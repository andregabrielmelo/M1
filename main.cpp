#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Struct produto 
struct Produto {
    string nome;
    float preco;
    int quantidade_disponivel;
};

// Struct node (prduto + próximo produto)
struct No {
    Produto produto;
    No *elo = nullptr;
};

// Struct lista encadeada
struct LUE {
    No *comeco = nullptr;
    No *fim = nullptr;
};

// Struct carrinho (lista + vendedor + valor total)?
struct Carrinho {
    string vendedor;
    int valor_total;
    LUE *lista = nullptr;
};

// pesquisar lista
bool pesquisar_lista(LUE *lista, Produto produto);
// verificar valores de itens na lista 
// reajustar preço de item na lista
// remover itens da lista (do estoque)
// controlar quantidade disponiveis e discontos de cada item na lista 
// salvar lista em um arquivo
// pegar lista de um arquivo

int main() {
    // Nova lista com os produtos a venda 

    // Nova lista do cliente (carrinho de compras)

    // Nova lista com os dados sobre vendas (valor, desconto, forma de pagamento, 
    // total de vendas, total de vendas por forma de pagameto, total de vendar por vendedor, etc)


    return 0;
}