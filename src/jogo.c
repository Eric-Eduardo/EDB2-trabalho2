#include "jogo.h"

#include <stdio.h>
#include <string.h>

void ler_tabuleiro() {
    printf("Em construção...");
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
