#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lê o tabuleiro do arquivo e aloca dinamicamente
char **ler_tabuleiro(int *n_linhas, int *n_colunas) {
    printf("Carregando tabuleiro...\n");

    FILE *arquivo = fopen("./tabuleiro.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    char linha[512];
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        return NULL;
    }

    sscanf(linha, "%d %d", n_colunas, n_linhas);

    char **tabuleiro = (char **)malloc(*n_linhas * sizeof(char *));
    for (int y = 0; y < *n_linhas; y++) {
        tabuleiro[y] = (char *)malloc(*n_colunas * sizeof(char));
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            break;
        }

        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
        }

        char *letra = strtok(linha, " ");
        for (int x = 0; x < *n_colunas; x++) {
            if (letra == NULL) {
                break;
            }
            tabuleiro[y][x] = *letra;
            letra = strtok(NULL, " ");
        }
    }

    fclose(arquivo);
    printf("Tabuleiro carregado com sucesso!\n");
    return tabuleiro;
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
