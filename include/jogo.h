#include <stdio.h>

#ifndef JOGO_H
#define JOGO_H
#include "./trie.h"
#include "./avl.h"

// Ler o tabuleiro do arquivo tabuleiro.txt
char** ler_tabuleiro(int *n_linhas, int *n_colunas); 

// ler o arquivo palavras.txt contendo as possíveis palavras e armazená-las na Trie
void ler_palavras(Trie* trie);

// Buscar automaticamente as palavras na tabuleiro, verificando em todas as direções e em ordem direta e inversa. Caso validadda, inseri-la na AVL
void buscar_palavras(Trie* trie, Avl* avl);

// Exibir as palavras encontradas, armazenadas na AVL
void imprimir_resultados(Trie *trie);

// Mostrar as dados do jogo (palavras que serão procuradas e o tabuleiro)
void mostrarJogo(char** tabuleiro, int n_linhas, int n_colunas, Trie* trie);

#endif