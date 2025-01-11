#include "../include/trie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria um novo nó
Trie *criar_no_trie() {
    Trie *no = (Trie *)malloc(sizeof(Trie));
    no->fim_da_palavra = false;

    for (int i = 0; i < ALFABETO; i++) {
        no->filhos[i] = NULL;
    }

    return no;
}

// insere palavras na Trie (a partir do arquivo palavras.txt)
void inserir(Trie *raiz, const char *palavra) {
    Trie *no_atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (no_atual->filhos[indice] == NULL) {
            no_atual->filhos[indice] = criar_no_trie();
        }

        no_atual = no_atual->filhos[indice];
    }

    no_atual->fim_da_palavra = true;

    // printf("%s inserida na Trie\n", palavra);
}

// Busca palaras na Trie para verificar validade
// Verifica se uma sequência de caracteres (formada no tabuleiro) corresponde a uma palavra na Trie
bool buscar(Trie *raiz, const char *palavra) {
    Trie *no_atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (no_atual->filhos[indice] == NULL) {
            return false;
        }

        no_atual = no_atual->filhos[indice];
    }

    return no_atual->fim_da_palavra;
}

void percorrer_trie(Trie *raiz, char *buffer, int depth) {
    if (raiz != NULL) {
        if (raiz->fim_da_palavra) {
            buffer[depth] = '\0';
            printf("%s\n", buffer);
        }

        for (int i = 0; i < ALFABETO; i++) {
            if (raiz->filhos[i] != NULL) {
                buffer[depth] = 'a' + i;
                percorrer_trie(raiz->filhos[i], buffer, depth + 1);
            }
        }
    } else {
        printf("Raíz nula\n");
    }

    return;
}

// Libera os ponteiros da Trie
void liberar_trie(Trie *raiz) {
    if (raiz == NULL)
        return;

    for (int i = 0; i < ALFABETO; i++) {
        liberar_trie(raiz->filhos[i]);
    }

    free(raiz);
}
