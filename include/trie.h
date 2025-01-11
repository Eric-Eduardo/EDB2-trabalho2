#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdbool.h>

#define ALFABETO 26

typedef struct Trie{
  struct Trie *filhos[ALFABETO];
  bool fim_da_palavra;
} Trie;

// Cria um novo nó
Trie *criar_no_trie();

// insere palavras na Trie (a partir do arquivo palavras.txt)
void inserir(Trie *raiz, const char *palavra);

// Busca palaras na Trie para verificar validade
// Verifica se uma sequência de caracteres (formada no tabuleiro) corresponde a uma palavra na Trie
bool buscar(Trie *raiz, const char *palavra);

 
// Libera os ponteiros da Trie
void liberar_trie(Trie *raiz);

void percorrer_trie(Trie *raiz, char *buffer, int depth);

#endif