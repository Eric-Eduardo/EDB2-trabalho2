#include "avl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criar um novo nó da AVL.
Avl* criar_no_avl(int dado[4], char* chave) {
    Avl* no = (Avl*)malloc(sizeof(Avl));
    no->chave = chave;

    if (dado != NULL) {
        no->dado[0] = dado[0];
        no->dado[1] = dado[1];
        no->dado[2] = dado[2];
        no->dado[3] = dado[3];
    } else {
        dado = NULL;
    }
    no->esquerdo = NULL;
    no->direito = NULL;
    no->altura = 0;

    return no;
}

// Inserir uma palavra encontrada no tabuleiro (validade na Trie) na AVL.
Avl* inserir_no(Avl* no, char* chave, int dado[4]) {
    if (no == NULL)
        return criar_no_avl(dado, chave);

    if (strcmp(chave, no->chave) < 0)
        no->esquerdo = inserir_no(no->esquerdo, chave, dado);
    else if (strcmp(chave, no->chave) > 0)
        no->direito = inserir_no(no->direito, chave, dado);
    else
        return no;

    if (obter_altura(no->esquerdo) > obter_altura(no->direito))
        no->altura = 1 + obter_altura(no->esquerdo);
    else
        no->altura = 1 + obter_altura(no->direito);

    int balanceamento = calcular_fator_de_balanceamento(no);

    /* Caso 1: Desbalanceamento à esquerda (Rotação à direita). */
    if (balanceamento > 1 && strcmp(chave, no->esquerdo->chave) < 0) {
        // printf("Rotação direita");
        return rotacao_direita(no);
    }

    /* Caso 2: Desbalanceamento à direita (Rotação à esquerda). */
    if (balanceamento < -1 && strcmp(chave, no->direito->chave) > 0) {
        // printf("Rotação esquerda");
        return rotacao_esquerda(no);
    }
    /* Caso 3: Desbalanceamento esquerda-direita (Rotação dupla esquerda-direita). */
    if (balanceamento > 1 && strcmp(chave, no->esquerdo->chave) > 0) {
        // printf("Rotação direita");
        no->esquerdo = rotacao_esquerda(no->esquerdo);
        return rotacao_direita(no);
    }

    /* Caso 4: Desbalanceamento direita-esquerda (Rotação dupla direita-esquerda). */
    if (balanceamento < -1 && strcmp(chave, no->direito->chave) < 0) {
        no->direito = rotacao_direita(no->direito);
        return rotacao_esquerda(no);
    }

    return no;
}

// Balancear a árvore após inserções ou remoções, realizando rotações (simples e duplas).
Avl* rotacao_direita(Avl* raiz) {
    Avl* pivo = raiz->esquerdo;

    raiz->esquerdo = pivo->direito;
    pivo->direito = raiz;

    int altura_no_esquerdo_raiz = obter_altura(raiz->esquerdo);
    int altura_no_direito_raiz = obter_altura(raiz->direito);
    int altura_no_esquerdo_pivo = obter_altura(pivo->esquerdo);
    int altura_no_direito_pivo = obter_altura(pivo->direito);

    if (altura_no_esquerdo_raiz > altura_no_direito_raiz)
        raiz->altura = 1 + altura_no_esquerdo_raiz;
    else
        raiz->altura = 1 + altura_no_direito_raiz;

    if (altura_no_esquerdo_pivo > altura_no_direito_pivo)
        pivo->altura = 1 + altura_no_esquerdo_pivo;
    else
        pivo->altura = 1 + altura_no_direito_pivo;

    return pivo;
}

Avl* rotacao_esquerda(Avl* raiz) {
    Avl* pivo = raiz->direito;

    raiz->direito = pivo->esquerdo;
    pivo->esquerdo = raiz;

    int altura_no_esquerdo_raiz = obter_altura(raiz->esquerdo);
    int altura_no_direito_raiz = obter_altura(raiz->direito);
    int altura_no_esquerdo_pivo = obter_altura(pivo->esquerdo);
    int altura_no_direito_pivo = obter_altura(pivo->direito);

    if (altura_no_esquerdo_raiz > altura_no_direito_raiz)
        raiz->altura = 1 + altura_no_esquerdo_raiz;
    else
        raiz->altura = 1 + altura_no_direito_raiz;

    if (altura_no_esquerdo_pivo > altura_no_direito_pivo)
        pivo->altura = 1 + altura_no_esquerdo_pivo;
    else
        pivo->altura = 1 + altura_no_direito_pivo;

    return pivo;
}

int obter_altura(Avl* no) {
    if (no == NULL)
        return -1;
    else
        return no->altura;
    return 0;
}

int calcular_fator_de_balanceamento(Avl* no) {
    if (no == NULL)
        return 0;
    else
        return obter_altura(no->esquerdo) - obter_altura(no->direito);
    return 0;
}

Avl* menor_valorNo(Avl* no) {
    Avl* atual = no;

    while (atual->esquerdo != NULL)
        atual = atual->esquerdo;

    return atual;
}

// Remover uma palavra na AVL pelo usuário.
Avl* remover_no(Avl* raiz, int dado) {
    printf("Em construção...");
    return NULL;
}

// Imprimir as palavras armazenadas em ordem alfabética.
void imprimir_em_ordem(Avl* raiz) {
    if (raiz != NULL) {
        imprimir_em_ordem(raiz->esquerdo);
        printf("%s\n", raiz->chave);
        imprimir_em_ordem(raiz->direito);
    }
}

void liberar_avl(Avl* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberar_avl(raiz->esquerdo);
    liberar_avl(raiz->direito);

    free(raiz);
}
