#include <stdio.h>

#ifndef JOGO_H
#define JOGO_H

// Ler o tabuleiro do arquivo tabuleiro.txt
void ler_tabuleiro(); 

// ler o arquivo palavras.txt contendo as possíveis palavras e armazená-las na Trie
void ler_palavras();

// Buscar automaticamente as palavras na tabuleiro, verificando em todas as direções e em ordem direta e inversa. Caso validadda, inseri-la na AVL
void bucar_palavras();

// Exibir as palavras encontradas, armazenadas na AVL
void imprimir_resultados();

#endif