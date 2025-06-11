#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Desafio: Nível Novato - Concluído (Luann - 11/06/2025)
// Lógica criada para representar um tabuleiro de Batalha Naval usando uma matriz 10x10
// Inclui verificação para posicionar navios, garantindo que fiquem dentro dos limites do tabuleiro e não se sobreponham
// A exibição do tabuleiro usa o número 0 para representar a água e o número 3 para representar os navios


int main() {
    // Variáveis para definir o tamanho do tabuleiro, o tamanho do navio e o número que representa a água
    // Os vetores 'navioHorizontal' e 'navioVertical' representam os navios com 3 partes (cada parte vale 3)
    int agua = 0;
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Matriz bidimensional para gerar o tabuleiro, usando laços for aninhados para preenchê-la com 0
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = agua;
        }
    }
    
    // Variáveis para definir a posição do navio que ficará na horizontal
    int linhaHorizontal = 6;
    int colunaHorizontal = 4;

    // Verifica se o navio posicionado horizontalmente cabe no tabuleiro
    if (colunaHorizontal + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro ao posicionar o navio horizontal\n");
        return 1;
    }

    // Variáveis para definir a posição do navio que ficará na vertical
    int linhaVertical = 3;
    int colunaVertical = 8;

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
            printf("Erro: um navio sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro ao posicionar o navio vertical\n");
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

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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