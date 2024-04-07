#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "produto.cpp"

struct ItemDuplamenteEncadeada {
    Produto produto;
    ItemDuplamenteEncadeada *eloA = nullptr;
    ItemDuplamenteEncadeada *eloP = nullptr;
};

struct Lista {
    ItemDuplamenteEncadeada *comeco = nullptr;
    ItemDuplamenteEncadeada *fim = nullptr;
};

// Funções
bool inserir_final_lista(Lista *lista, Produto produto) {
    ItemDuplamenteEncadeada *novo_produto = new ItemDuplamenteEncadeada;
    if (novo_produto == nullptr) return false; // verificar alocação de memória
    novo_produto->produto = produto;

    if (lista->comeco == nullptr) { // caso lista vazia
        lista->comeco = novo_produto;
    } else {
        lista->fim->eloP = novo_produto;
        novo_produto->eloA = lista->fim;
    }

    lista->fim = novo_produto;

    return true;
}

bool inserir_final_lista(Lista *lista, Produto *produto) {
    ItemDuplamenteEncadeada *novo_produto = new ItemDuplamenteEncadeada;
    if (novo_produto == nullptr) return false; // verificar alocação de memória
    novo_produto->produto = *produto;

    if (lista->comeco == nullptr) { // caso lista vazia
        lista->comeco = novo_produto;
    } else {
        lista->fim->eloP = novo_produto;
        novo_produto->eloA = lista->fim;
    }

    lista->fim = novo_produto;

    return true;
}

void mostrarLista(Lista *lista) {
    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // nó temporário para atravessar a lista

    if (lista->comeco == nullptr) { // Se a lista estiver vazia
        cout << "\nLista vazia"; // TODO: Retirar isso e retornar algo ao inves disso?
    }

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto a lista não acabar
    while (temp != nullptr) {
        cout << "Nome: " << temp->produto.nome << "\n";
        cout << "Preço: " << temp->produto.preco << "\n";
        cout << "Desconto: " << temp->produto.desconto << "%\n";
        cout << "Quantidade disponivel: " << temp->produto.quantidade << "\n";

        cout << "\n";

        temp = temp->eloP; // próximo elemento
    }
}

// Sobrecarga de funções. Pode mudar para template depois
Produto pesquisarProduto(Lista *lista, string nome) {
    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // nó temporário para atravessar a lista

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto não encontrar o produto
    while (temp->produto.nome != nome) {
        temp = temp->eloP; // próximo elemento
    }

    // Retornar o produto encontrado
    return temp->produto;
}

Produto pesquisarProduto(Lista *lista, int preco) { // TODO: Retorna só um? Fazer retornar vários produtos 
    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // nó temporário para atravessar a lista

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto não encontrar o produto
    while (temp->produto.preco != preco) {
        temp = temp->eloP; // próximo elemento
    }

    // Retornar o produto encontrado
    return temp->produto;
}