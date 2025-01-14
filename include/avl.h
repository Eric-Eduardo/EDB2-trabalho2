#include <stdio.h>

#ifndef AVL_H
#define AVL_H

typedef struct Avl{
    char* chave;
    int dado[4]; // [x_inicio, y_inicio, x_final, y_final]
    struct Avl* esquerdo;
    struct Avl* direito;
    int altura;
} Avl;


// Criar um novo nó da AVL.
Avl* criar_no_avl(int dado[4], char* chave);

// Inserir uma palavra encontrada no tabuleiro (validade na Trie) na AVL.
Avl* inserir_no(Avl* no, char* chave, int dado[4]);

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

void liberar_avl(Avl* raiz);

#endif