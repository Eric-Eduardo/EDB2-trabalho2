#include <stdio.h>

#ifndef AVL_H
#define AVL_H

typedef struct Avl{
    int dado;
    struct Avl* esquerdo;
    struct Avl* direito;
    int altura;
} Avl;


// Criar um novo nó da AVL.
Avl* criar_no_avl(int dado);

// Inserir uma palavra encontrada no tabuleiro (validade na Trie) na AVL.
Avl* inserir_no(Avl* no, int dado);

// Balancear a árvore após inserções ou remoções, realizando rotações (simples e duplas).
Avl* rotacao_direita(Avl* y);
Avl* rotacao_esquerda(Avl* x);
int obter_altura(Avl* no);
int calcular_fator_de_balanceamento(Avl* no);
Avl* menor_valorNo(Avl* no);

// Remover uma palavra na AVL pelo usuário.
Avl* remover_no(Avl* raiz, int dado);

// Imprimir as palavras armazenadas em ordem alfabética.
void imprimir_em_ordem(Avl* raiz);

#endif