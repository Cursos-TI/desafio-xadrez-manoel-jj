#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// Funções recursivas para o Nível Mestre
void bispoRecursivo(int passos, int direcao) {
    if (passos == 0) return;
    printf("Diagonal %d\n", direcao);
    bispoRecursivo(passos - 1, direcao + 1);
}

void torreRecursiva(int passos) {
    if (passos == 0) return;
    printf("Direita %d\n", passos);
    torreRecursiva(passos - 1);
}

void rainhaRecursiva(int passos) {
    if (passos == 0) return;
    printf("Esquerda %d\n", passos);
    rainhaRecursiva(passos - 1);
}

void cavaloRecursivo(int movimentos, int tipo) {
    if (movimentos == 0) return;
    printf("Movimento L - Tipo %d\n", tipo);
    cavaloRecursivo(movimentos - 1, tipo + 1);
}

int main() {
    // Nível Novato - Movimentação das Peças
    // Declaração de variáveis constantes para representar o número de casas que cada peça pode se mover.
    
    const int BISPO_CASAS = 5;
    const int TORRE_CASAS = 5;
    const int RAINHA_CASAS = 8;
    const int CAVALO_MOVIMENTOS = 8;

    printf("===== NÍVEL NOVATO =====\n\n");

    // Implementação de Movimentação do Bispo
    // Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
    printf("Movimentação do Bispo (Diagonal):\n");
    for (int i = 1; i <= BISPO_CASAS; i++) {
        printf("Bispo se move para a diagonal: posição (%d, %d)\n", i, i);
    }
    printf("\n");

    // Implementação de Movimentação da Torre
    // Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
    printf("Movimentação da Torre (Para a direita):\n");
    for (int i = 1; i <= TORRE_CASAS; i++) {
        printf("Torre se move para a direita: posição (%d, 0)\n", i);
    }
    printf("\n");

    // Implementação de Movimentação da Rainha
    // Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
    printf("Movimentação da Rainha (Para a esquerda):\n");
    for (int i = 1; i <= RAINHA_CASAS; i++) {
        printf("Rainha se move para a esquerda: posição (-%d, 0)\n", i);
    }
    printf("\n");

    printf("===== NÍVEL AVENTUREIRO =====\n\n");

    // Nível Aventureiro - Movimentação do Cavalo
    // Utilize loops aninjados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.
    printf("Movimentação do Cavalo (Em L):\n");
    int movimentos_cavalo[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (int i = 0; i < CAVALO_MOVIMENTOS; i++) {
        printf("Cavalo se move: (%d, %d)\n", movimentos_cavalo[i][0], movimentos_cavalo[i][1]);
    }
    printf("\n");

    // Loops aninhados para demonstrar os 8 possíveis movimentos do cavalo
    printf("Visualização dos 8 movimentos do Cavalo:\n");
    for (int horizontal = -2; horizontal <= 2; horizontal++) {
        for (int vertical = -2; vertical <= 2; vertical++) {
            // Verifica se é um movimento válido de cavalo (L)
            int distancia_h = (horizontal < 0) ? -horizontal : horizontal;
            int distancia_v = (vertical < 0) ? -vertical : vertical;

            if ((distancia_h == 2 && distancia_v == 1) || (distancia_h == 1 && distancia_v == 2)) {
                printf("Posição válida: (%d, %d)\n", horizontal, vertical);
            }
        }
    }
    printf("\n");

    printf("===== NÍVEL MESTRE =====\n\n");

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Substitua as movimentações das peças por funções recursivas.

    printf("Movimentação do Bispo (Recursiva):\n");
    bispoRecursivo(BISPO_CASAS, 1);
    printf("\n");

    printf("Movimentação da Torre (Recursiva):\n");
    torreRecursiva(TORRE_CASAS);
    printf("\n");

    printf("Movimentação da Rainha (Recursiva):\n");
    rainhaRecursiva(RAINHA_CASAS);
    printf("\n");

    printf("Movimentação do Cavalo (Recursiva):\n");
    cavaloRecursivo(CAVALO_MOVIMENTOS, 1);
    printf("\n");

    // Implementação da movimentação do Cavalo com loops avançados, continue e break
    printf("Movimentação Avançada do Cavalo (Com continue e break):\n");
    int contador = 0;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // Pula movimentos pares
        }
        printf("Movimento %d do Cavalo\n", i);
        contador++;
        if (contador == 5) {
            break; // Para após 5 movimentos válidos
        }
    }
    printf("\n");

    return 0;
}
