#include <stdio.h>

#ifndef TRIE_H
#define TRIE_H


#define ALFABETO 26

typedef struct Trie{
  struct Trie *filhos[ALFABETO];
  int fim_da_palavra;
} Trie;

// Cria um novo nó
Trie *criar_no_trie();

// insere palavras na Trie (a partir do arquivo palavras.txt)
void inserir(Trie *raiz, const char *palavra);

// Busca palaras na Trie para verificar validade
// Verifica se uma sequência de caracteres (formada no tabuleiro) corresponde a uma palavra na Trie
int buscar(Trie *raiz, const char *palavra);

 
// Libera os ponteiros da Trie
void liberar_trie(Trie *raiz);

#endif