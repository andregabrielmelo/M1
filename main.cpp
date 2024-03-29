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

// Struct node (prduto + pr�ximo produto)
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
    LUE *lista = nullptr; // ?
};

// operator == overloading com o tipo Produto
bool operator ==(const Produto &produto1, const Produto &produto2) {
    return (produto1.nome == produto2.nome && produto1.preco == produto2.preco && produto1.quantidade_disponivel == produto2.quantidade_disponivel);
}

// operator = overloading com o tipo Produto
Produto& Produto::operator=(const Produto& produto) {
    if (this != &produto) { // Verifica se n�o � a mesma inst�ncia
        // Atribui os membros individualmente
        this->nome = produto.nome;
        this->preco = produto.preco;
        this->quantidade_disponivel = produto.quantidade_disponivel;
    }
    return *this;
}

bool inserir_final_lista(LUE *lista, Produto produto);// Inserir item na lista 
// remover itens da lista (do estoque)


bool pesquisar_lista(LUE *lista, Produto produto); // pesquisar lista

int verificar_valor(LUE *lista, Produto produto); // verificar valores de itens na lista 
// reajustar pre�o de item na lista
// controlar quantidade disponiveis e discontos de cada item na lista 
// salvar lista em um arquivo
// pegar lista de um arquivo

int main() {
    // Nova lista com os produtos a venda 
    LUE *produtos_venda = new LUE;
    if (produtos_venda == nullptr) {
        printf("Aloca��o de mem�ria falhou");
        return 1;
    }

    // Nova lista do cliente (carrinho de compras)

    // Nova lista com os dados sobre vendas (valor, desconto, forma de pagamento, 
    // total de vendas, total de vendas por forma de pagameto, total de vendar por vendedor, etc)


    return 0;
}

bool pesquisar_lista(LUE *lista, Produto produto) { // Mudar para pesquisar o produto pelo nome/pre�o. Talvez deve retornar o produto?
    No *temp = lista->comeco; // no temporario para atravessar a lista

    // Enquanto o elemento da lista n�o for nulo
    while (temp != nullptr) {

        if (temp->produto == produto) { // Se o produto foi encontrado na lista
            return true;
        }

        temp = temp->elo; // Pr�ximo elemento na lista 
    }

    return false;
}

int verificar_valor(LUE *lista, Produto produto) {
    No *temp = lista->comeco; // n� temporario para atravessar a lista

    // Enquanto o elemento da lista n�o for nulo
    while (temp != nullptr) {

        if (temp->produto == produto) { // Se o produto foi encontrado na lista, retorna o pre�o
            return temp->produto.preco;
        }

        temp = temp->elo; // Pr�ximo produto na lista 
    }

    return 0;
}

bool inserir_final_lista(LUE *lista, Produto produto) { // Verificar novamente em uma revis�o final

    // Novo n�, para o novo produto
    No *novo_no = new No;
    novo_no->produto = produto;

    if (novo_no == nullptr) { // Verificar se a aloca��o de memoria deu certo 
        return false;
    }

    if (lista->comeco == nullptr) { // Caso a lista esteja vazia
        lista->comeco = novo_no;
        lista->fim = novo_no;
    } else {
        lista->fim->elo = novo_no; // Adiciona um pr�ximo n� para o ultimo da lista
    }

    lista->fim = novo_no; // muda o fim da lista

    return true;
}