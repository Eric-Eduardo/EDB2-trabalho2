#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
            // Converte para minúsculas ao carregar
            tabuleiro[y][x] = tolower(*letra);
            letra = strtok(NULL, " ");
        }
    }

    fclose(arquivo);
    printf("Tabuleiro carregado com sucesso!\n");
    return tabuleiro;
}

// ler o arquivo palavras.txt contendo as possíveis palavras e armazená-las na Trie
void ler_palavras(Trie *trie) {
    printf("Carregando palavras...\n");

    FILE *arquivo = fopen("./palavras.txt", "r");

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
    printf("Carregamento das palavras concluído!\n");
}

// Buscar automaticamente as palavras na tabuleiro, verificando em todas as direções e em ordem direta e inversa. Caso validadda, inseri-la na AVL
void buscar_palavras(Trie* trie, char** tabuleiro, int n_linhas, int n_colunas, Avl** avl) {
    printf("Buscando palavras...\n");
    char palavra[1000];

    // Percorrer cada célula do tabuleiro como ponto inicial
    for (int y = 0; y < n_linhas; y++) {
        for (int x = 0; x < n_colunas; x++) {
            // Explorando as palavras em todas as direções
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy == 0 && dx == 0)
                        continue;

                    int len = 0, ny = y, nx = x;

                    while (ny >= 0 && ny < n_linhas && nx >= 0 && nx < n_colunas) {
                        // Converte cada letra para minúsculas ao formar a palavra
                        palavra[len++] = tolower(tabuleiro[ny][nx]);
                        palavra[len] = '\0';

                        if (buscar(trie, palavra)) {
                            // Insere a palavra encontrada na AVL
                            printf("Palavra encontrada: %s\n", palavra);
                            *avl = inserir_no(*avl, palavra);
                        }

                        ny += dy;
                        nx += dx;
                    }
                }
            }
        }
    }

    printf("Busca concluída!\n");
}


// 23, 87, 5, 46, 92, 14, 68, 39, 74, 31 47
    // char* p1 = "23";
    // char* p2 = "87";
    // char* p3 = "05";
    // char* p4 = "46";
    // char* p5 = "92";
    // char* p6 = "14";
    // char* p7 = "68";
    // char* p8 = "39";
    // char* p9 = "74";
    // char* p10 = "31";
    // char* p11 = "47";

    // avl = inserir_no(avl, p1, NULL);
    // avl = inserir_no(avl, p2, NULL);
    // avl = inserir_no(avl, p3, NULL);
    // avl = inserir_no(avl, p4, NULL);
    // avl = inserir_no(avl, p5, NULL);
    // avl = inserir_no(avl, p6, NULL);
    // avl = inserir_no(avl, p7, NULL);
    // avl = inserir_no(avl, p8, NULL);
    // avl = inserir_no(avl, p9, NULL);
    // avl = inserir_no(avl, p10, NULL);

    // imprimir_em_ordem(avl);
}

// Exibir as palavras encontradas, armazenadas na AVL
void imprimir_em_ordem(Avl* raiz) {
    if (raiz != NULL) {
        imprimir_em_ordem(raiz->esquerdo);
        printf("%s\n", raiz->chave);
        imprimir_em_ordem(raiz->direito);
    }
}

// Atualização no case 3 para usar AVL
void imprimir_resultados(Avl* avl) {
    if (avl == NULL) {
        printf("Nenhuma palavra encontrada.\n");
    } else {
        printf("Palavras encontradas:\n");
        imprimir_em_ordem(avl);
    }
}

void mostrarJogo(char **tabuleiro, int n_linhas, int n_colunas, Trie *trie) {
    char buffer[100];
    percorrer_trie(trie, buffer, 0);

    if (tabuleiro == NULL) {
        printf("Tabuleiro vazio");
        return;
    }

    printf("\n");

    for (int y = 0; y < n_linhas; y++) {
        for (int x = 0; x < n_colunas; x++) {
            if (x < n_colunas - 1) {
                printf("%c ", tabuleiro[y][x]);
            } else {
                printf("%c\n", tabuleiro[y][x]);
            }
        }
    }
}
