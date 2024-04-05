#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "produto.cpp"

struct ListaDuplamenteEncadeada {
    Produto produto;
    ListaDuplamenteEncadeada *eloA = nullptr;
    ListaDuplamenteEncadeada *eloP = nullptr;
};

struct Lista {
    ListaDuplamenteEncadeada *comeco = nullptr;
    ListaDuplamenteEncadeada *fim = nullptr;
};

// Funções
bool inserir_final_lista(Lista *lista, Produto produto) {
    ListaDuplamenteEncadeada *novo_produto = new ListaDuplamenteEncadeada;
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

void mostrarLista(Lista *lista) {
    ListaDuplamenteEncadeada *temp = new ListaDuplamenteEncadeada; // nó temporário para atravessar a lista

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
