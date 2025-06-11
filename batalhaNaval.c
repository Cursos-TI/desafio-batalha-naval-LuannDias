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


int main() {
    // Variáveis para definir o tamanho do tabuleiro, o tamanho do navio e o número que representa a água
    int agua = 0;
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    // Variáveis para definir a posição do navio que será colocado na HORIZONTAL
    int linhaHorizontal = 4;
    int colunaHorizontal = 1;

    // Variáveis para definir a posição do navio que será colocado na VERTICAL
    int linhaVertical = 6;
    int colunaVertical = 6;

    // Variáveis para definir a posição do navio que será colocado na DIAGONAL 1
    int linhaDiagonalNavio1 = 1;
    int colunaDiagonalNavio1 = 5;

    // Variáveis para definir a posição do navio que será colocado na DIAGONAL 2
    int linhaDiagonalNavio2 = 6;
    int colunaDiagonalNavio2 = 2;

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
    if (linhaDiagonalNavio2 + tamanhoNavio <= tamanhoTabuleiro && colunaDiagonalNavio2 + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiagonalNavio2 + i][colunaDiagonalNavio2 + i] != agua) {
                sobrepoe = 1;
                break;
            }
        }

        if (!sobrepoe) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaDiagonalNavio2 + i][colunaDiagonalNavio2 + i] = navioDiagonal2[i];
            }
        } else {
            printf("Erro: navio diagonal 2 sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro ao posicionar navio diagonal 2\n");
        return 1;
    }

    // Exibição do tabuleiro usando laços for aninhados
    printf("Tabuleiro:\n");
    printf("* 0 == Água, 3 == Navio *\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0