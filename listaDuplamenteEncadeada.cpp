#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "produto.cpp"

using namespace std;

struct ItemDuplamenteEncadeada { // TODO: trocar para template ao invés de fixar em produto
    Produto produto;
    ItemDuplamenteEncadeada *eloA = nullptr;
    ItemDuplamenteEncadeada *eloP = nullptr;
};

struct Lista { // TODO: trocar para template ao invés de fixar
    ItemDuplamenteEncadeada *comeco = nullptr;
    ItemDuplamenteEncadeada *fim = nullptr;
};

// Funções
bool inserir_final_lista(Lista *lista, Produto produto) {
    ItemDuplamenteEncadeada *novo_produto = new ItemDuplamenteEncadeada;
    if (novo_produto == nullptr) return false; // verificar alocação de memória

    // Inserindo os valores do novo produto
    novo_produto->produto = produto;

    if (lista->comeco == nullptr) { // caso lista vazia
        lista->comeco = novo_produto; 
        lista->fim = novo_produto; // o novo produto é o ultimo elemento da lista
        return true;
    } else { // caso não vazia
        novo_produto->eloA = lista->fim; // Inicialize o ponteiro anterior do novo produto
        lista->fim->eloP = novo_produto; // O próximo produto do ultimo produto vai ser o novo produto
        lista->fim = novo_produto; // o novo produto é o ultimo elemento da lista
        return true;
    }

    return false;
}

bool inserir_final_lista(Lista *lista, Produto *produto) {
    ItemDuplamenteEncadeada *novo_produto = new ItemDuplamenteEncadeada;
    if (novo_produto == nullptr) return false; // verificar alocação de memória

    // Inserindo os valores do novo produto
    novo_produto->produto = *produto;

    if (lista->comeco == nullptr) { // caso lista vazia
        lista->comeco = novo_produto; 
        lista->fim = novo_produto; // o novo produto é o ultimo elemento da lista
        return true;
    } else { // caso não vazia
        novo_produto->eloA = lista->fim; // Inicialize o ponteiro anterior do novo produto
        lista->fim->eloP = novo_produto; // O próximo produto do ultimo produto vai ser o novo produto
        lista->fim = novo_produto; // o novo produto é o ultimo elemento da lista
        return true;
    }

    return false;
}

void mostrarLista(Lista *lista) {
    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // nó temporário para atravessar a lista

    if (lista->comeco == nullptr) { // Se a lista estiver vazia
        cout << "\nLista vazia"; // TODO: Retirar isso e retornar algo ao inves disso?
    }

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto a lista não acabar
    while (temp != nullptr) {
        cout << "\n";
        cout << "Nome: " << temp->produto.nome << "\n";
        cout << "Preço: " << temp->produto.preco << "\n";
        cout << "Desconto: " << temp->produto.desconto << "%\n";
        cout << "Quantidade disponivel: " << temp->produto.quantidade << "\n";

        cout << "\n";

        temp = temp->eloP; // próximo elemento
    }
}

bool liberarItemLista(Lista *lista, string nome) {
    if (lista->comeco == nullptr) { // Verifica se a lista está vazia
        return false;
    }

    ItemDuplamenteEncadeada *temp = lista->comeco; // Inicializa o temp com o começo da lista

    // Percorre a lista até encontrar o produto com o nome especificado
    while (temp != nullptr && temp->produto.nome != nome) {
        temp = temp->eloP; // Próximo elemento
    }

    // Se chegar ao fim da lista e não encontrar o produto
    if (temp == nullptr) {
        return false;
    }

    // Retirar o produto
    if (lista->comeco == lista->fim) { // Se tiver um único produto na lista
        lista->comeco = nullptr;
        lista->fim = nullptr;
        
    } else if (lista->comeco == temp) { // Se ele for o primeiro da lista
        lista->comeco = temp->eloP; // A lista vai começar no próximo produto
        temp->eloP->eloA = nullptr; // O próximo produto não vai ter mais um produto anterior
    } else if (lista->fim == temp) { // Se ele for o último da lista
        lista->fim = temp->eloA; // Muda o final da lista
        temp->eloA->eloP = nullptr; // O último produto da lista não tem um próximo produto
    } else { // Ele está no meio da lista
        temp->eloA->eloP = temp->eloP; // Pula o produto que vai ser liberado na lista
        temp->eloP->eloA = temp->eloA; // O produto seguinte agora aponta para o anterior
    }

    delete temp; // Libera a memória do único produto

    return true;
}


// Sobrecarga de funções. Pode mudar para template depois
Produto pesquisarProduto(Lista *lista, string nome) {
    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // nó temporário para atravessar a lista

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto não encontrar o produto ou não chegar ao fim da lista
    while (temp != nullptr && temp->produto.nome != nome) {
        temp = temp->eloP; // próximo elemento
    }

    // Se chegar ao fim da lista e não encontrar o produto
    if (temp == nullptr) {
        Produto produto;
        produto.nome = "";
        return produto; // Retorna nullptr indicando que o produto não foi encontrado
    }

    // Retornar o produto encontrado
    return (temp->produto);
}

Produto pesquisarProduto(Lista *lista, int preco) { // TODO: Retorna só um? Fazer retornar vários produtos 
    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // nó temporário para atravessar a lista

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto não encontrar o produto ou não chegar ao fim da lista
    while (temp != nullptr || temp->produto.preco != preco) {
        temp = temp->eloP; // próximo elemento
    }

    // Se chegar ao fim da lista e não encontrar o produto
    if (temp == nullptr) {
        Produto produto;
        produto.nome = "";
        return produto; // Retorna nullptr indicando que o produto não foi encontrado
    }

    // Retornar o produto encontrado
    return temp->produto;
}

Produto* pegarEndereco(Lista *lista, string nome) {
    ItemDuplamenteEncadeada *temp = lista->comeco; // Inicializa o temp com o come�o da lista

    // Percorre a lista at� encontrar o produto com o nome especificado
    while (temp != nullptr && temp->produto.nome != nome) {
        temp = temp->eloP; // Pr�ximo elemento
    }

    // Se o produto for encontrado, retorna o endere�o do produto
    if (temp != nullptr) {
        return &(temp->produto);
    } else {
        return nullptr; // Retorna nullptr se o produto n�o for encontrado
    }
}