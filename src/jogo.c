#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_tabuleiro(char** tabuleiro) {
    printf("Carregando palavras...\n");

    FILE* arquivo = fopen("./tabuleiro.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[512];
    char* letra;

    int n_linhas = 0;
    int n_colunas = 0;

    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        return;
    } else {
        sscanf(linha, "%d %d", &n_colunas, &n_linhas);
        tabuleiro = (char**)malloc(n_linhas * sizeof(char*));
    }

    for (int y = 0; y < n_linhas; y++) {
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            break;
        }

        tabuleiro[y] = (char*)malloc(n_colunas * sizeof(char*));

        // Remove o '\n'
        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
        }

        
        letra = strtok(linha, " ");

        // Separar/obter cada letra da linha do tableiro;

        for (int x = 0; x < n_colunas; x++) {
            if (linha == NULL) {
                break;
            }

            tabuleiro[y][x] = *letra;

            letra = strtok(NULL, " ");
        }

        printf("%s\n", tabuleiro[y]);
    }

    /*
        while (1) {
            if (fgets(linha, sizeof(linha), arquivo) == NULL) {
                break;
            }

            // Remove o '\n'
            size_t len = strlen(linha);
            if (len > 0 && linha[len - 1] == '\n') {
                linha[len - 1] = '\0';
            }

            printf("%s\n", linha);
        }

        fclose(arquivo);
        printf("Carregamento concluído!\n");
    */
}

// ler o arquivo palavras.txt contendo as possíveis palavras e armazená-las na Trie
void ler_palavras(Trie* trie) {
    printf("Carregando palavras...\n");

    FILE* arquivo = fopen("./palavras.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[512];

    while (1) {
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            break;
        }

        // Remove o '\n'
        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
        }

        inserir(trie, linha);
    }

    fclose(arquivo);
    printf("Carregamento concluído!\n");
}

// Buscar automaticamente as palavras na tabuleiro, verificando em todas as direções e em ordem direta e inversa. Caso validadda, inseri-la na AVL
void bucar_palavras() {
    printf("Em construção...");
}

// Exibir as palavras encontradas, armazenadas na AVL
void imprimir_resultados(Trie* trie) {
    char buffer[100];
    percorrer_trie(trie, buffer, 0);
}
