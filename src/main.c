#include <stdio.h>
#include <stdlib.h>

#include "../include/jogo.h"
#include "../include/trie.h"

int main() {
    printf(
        "+----------------------------+\n"
        "|        CAÇA PALAVRAS       |\n"
        "+----------------------------+\n");

    int option = -1;

    Trie* trie = criar_no_trie();
    char** tabuleiro = NULL;

    while (option != 0) {
        printf("\nMenu:\n");
        printf("[1] Carregar informações\n");
        printf("[2] Buscar palavras\n");
        printf("[3] Imprimir resultados\n");
        printf("[4] Ajuda\n");
        printf("[0] Sair\n");

        printf("\n> ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
        case 1:
            // ler_palavras(trie);
            ler_tabuleiro(&tabuleiro);
            break;
        case 2:
            printf("Buscand palavras\n");
            break;
        case 3:
            imprimir_resultados(trie);
            break;
        case 4:
            printf(
                "O objetivo deste programa é encontrar palavras em um jogo de caça-palavra. O tabuleiro do jogo precisa estar presente em um arquivo chamado tabuleiro.txt. As possíveis palavras que devem ser procuradas no tabuleiro precisam estar no arquivo palavras.txt.\n\n"
                "As principais operações que o programa permite que usuário execute é: \n"
                "   * Carregar informações: carrega para o programa as informações presentes no arquivo palavras.txt e tabuleiro.txt.\n"
                "   * Buscar palavras: faz com que o programa busque as palavras da arquivo palavras.txt no tabuleiro.\n"
                "   * Imprimir resultados: após ser feita a busca pelas palavras, esta opção exibe as palavras encontradas no tabuleiro.\n");
            break;
        case 0:
            liberar_trie(trie);
            free(trie);

            printf("Limpando\n");
            if (tabuleiro != NULL) {
                for (int i = 0; i < 10; i++) {
                    printf("%s\n", tabuleiro[i]);
                }
            } else {
                printf("Tabuleiro nulo");
            }

            free(tabuleiro);

            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}