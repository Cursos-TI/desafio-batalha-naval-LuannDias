#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Desafio: Nível Novato - Concluído (Luann - 11/06/2025)
// Lógica criada para representar um tabuleiro de Batalha Naval usando uma matriz 10x10
// Inclui verificação para posicionar navios, garantindo que fiquem dentro dos limites do tabuleiro e não se sobreponham
// A exibição do tabuleiro usa o número 0 para representar a água e o número 3 para representar os navios

// Desafio: Nível Aventureiro - Concluído (Luann - 11/06/2025)
// Adicionado o posicionamento de 2 novos navios, ambos posicionados na diagonal
// Reorganizadas algumas variáveis no código para facilitar futuras alterações nas posições dos navios

// Desafio: Nível Mestre – Concluído (Luann – 11/06/2025)
// Adicionadas as habilidades Cone, Octaedro e Cruz
// Criadas lógicas para preencher as matrizes com os formatos das habilidades
// Criadas as lógicas para aplicar as habilidades no tabuleiro


int main() {
    // Variáveis para definir o tamanho do tabuleiro, o tamanho do navio e o número que representa a água
    int agua = 0;
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    // Variáveis para definir a posição do navio que será colocado na HORIZONTAL
    int linhaHorizontal = 0;
    int colunaHorizontal = 0;

    // Variáveis para definir a posição do navio que será colocado na VERTICAL
    int linhaVertical = 3;
    int colunaVertical = 9;

    // Variáveis para definir a posição do navio que será colocado na DIAGONAL 1
    int linhaDiagonalNavio1 = 5;
    int colunaDiagonalNavio1 = 0;

    // Variáveis para definir a posição do navio que será colocado na DIAGONAL 2
    int linhaDiagonalNavio2 = 7;
    int colunaDiagonalNavio2 = 5;

    // Matriz bidimensional para gerar o tabuleiro, usando laços for aninhados para preenchê-la com 0
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = agua;
        }
    }
    
    // NAVIO HORIZONTAL
    // O vetor 'navioHorizontal' representa um navio com 3 partes (cada parte vale 3)
    int navioHorizontal[3] = {3, 3, 3};

    // Verifica se o navio posicionado horizontalmente cabe no tabuleiro
    if (colunaHorizontal + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }

    } else {
        printf("Erro ao posicionar o navio horizontal\n");
        return 1;
    }

    // NAVIO VERTICAL
    // O vetor 'navioVertical' representa um navio com 3 partes (cada parte vale 3)
    int navioVertical[3] = {3, 3, 3};

    // Verifica se o navio posicionado verticalmente cabe no tabuleiro e não sobrepõe outro navio
    int sobrepoe = 0;
    if (linhaVertical + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != agua) {
                sobrepoe = 1;
                break;
            }
        }

        if (!sobrepoe) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }   
        } else {
            printf("Erro: navio vertical sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro ao posicionar o navio vertical\n");
        return 1;
    }

    // NAVIO DIAGONAL 1
    // O vetor 'navioDiagonal1' representa um navio com 3 partes (cada parte vale 3)
    int navioDiagonal1[3] = {3, 3, 3};

    // Verifica se o navio posicionado na diagonal cabe no tabuleiro e não sobrepõe outros navios
    sobrepoe = 0;
    if (linhaDiagonalNavio1 + tamanhoNavio <= tamanhoTabuleiro && colunaDiagonalNavio1 + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiagonalNavio1 + i][colunaDiagonalNavio1 + i] != agua) {
                sobrepoe = 1;
                break;
            }
        }

        if (!sobrepoe) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaDiagonalNavio1 + i][colunaDiagonalNavio1 + i] = navioDiagonal1[i];
            }
        } else {
            printf("Erro: navio diagonal 1 sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro ao posicionar navio diagonal 1\n");
        return 1;
    }

    // NAVIO DIAGONAL 2
    // O vetor 'navioDiagonal2' representa um navio com 3 partes (cada parte vale 3)
    int navioDiagonal2[3] = {3, 3, 3};

    // Verifica se o navio posicionado na diagonal cabe no tabuleiro e não sobrepõe outros navios
    sobrepoe = 0;
    if (linhaDiagonalNavio2 + tamanhoNavio <= tamanhoTabuleiro && colunaDiagonalNavio2 - tamanhoNavio + 1 >= 0) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiagonalNavio2 + i][colunaDiagonalNavio2 - i] != agua) {
                sobrepoe = 1;
                break;
            }
        }

        if (!sobrepoe) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaDiagonalNavio2 + i][colunaDiagonalNavio2 - i] = navioDiagonal2[i];
            }
        } else {
            printf("Erro: navio diagonal 2 sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro ao posicionar navio diagonal 2\n");
        return 1;
    }

    // Habilidades do Desafio Mestre

    // Primeira habilidade: CONE
    // Matriz da Habilidade
    int habilidadeCone[3][5];

    // Lógica para preencher a matriz com o formato da habilidade CONE
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2)) {
                habilidadeCone[i][j] = 1;
            } else {
                habilidadeCone[i][j] = 0;
            }
        }
    }

    // Segunda habilidade: OCTAEDRO
    // Matriz da Habilidade
    int habilidadeOctaedro[3][5];

    // Lógica para preencher a matriz com o formato do Octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 1 && j >= 1 && j <= 3) || ((i == 0 || i == 2) && j == 2)) {
                habilidadeOctaedro[i][j] = 1;
            } else {
                habilidadeOctaedro[i][j] = 0;
            }
        }
    }

    // Terceira habilidade: Cruz
    // Matriz da Habilidade
    int habilidadeCruz[3][5];

    // Lógica para preencher a matriz com o formato da cruz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 1 || ((i == 0 || i == 2) && j ==2)) {
                habilidadeCruz[i][j] = 1;
            } else {
                habilidadeCruz[i][j] = 0;
            }
        }
    }

    // Sessão para aplicar as habilidades no tabuleiro
    // Aplicando a habilidade Cone
    // Variáveis para definir o início da habilidade
    int linhaBaseCone = 1;
    int colunaBaseCone = 4;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeCone[i][j] == 1) {
                tabuleiro[linhaBaseCone + i][colunaBaseCone + j] = 5;
            }
        }
    }

    // Aplicando a habilidade Octaedro
    // Variáveis para definir o início da habilidade
    int linhaBaseOctaedro = 7;
    int colunaBaseOctaedro = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeOctaedro[i][j] == 1) {
                tabuleiro[linhaBaseOctaedro + i][colunaBaseOctaedro + j] = 5;
            }
        }
    }

    // Aplicando a habilidade Cruz
    // Variáveis para definir o início da habilidade
    int linhaBaseCruz = 2;
    int colunaBaseCruz = 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeCruz[i][j] == 1) {
                tabuleiro[linhaBaseCruz + i][colunaBaseCruz + j] = 5;
            }
        }
    }

    // Exibição do tabuleiro usando laços for aninhados
    printf("Tabuleiro:\n");
    printf("* 0 == Água, 3 == Navio, 5 == Habilidade *\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
