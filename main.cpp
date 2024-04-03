#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Hello world

using namespace std;

// Struct produto 
struct Produto {
    string nome;
    float preco;
    float desconto;
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
    LUE *lista = nullptr; // mudar?
};

// operator == overloading com o tipo Produto
bool operator ==(const Produto &produto1, const Produto &produto2) {
    return (produto1.nome == produto2.nome && produto1.preco == produto2.preco && produto1.quantidade_disponivel == produto2.quantidade_disponivel);
}

// operator != overloading com o tipo Produto
bool operator !=(const Produto &produto1, const Produto &produto2) {
    return !(produto1.nome == produto2.nome && produto1.preco == produto2.preco && produto1.quantidade_disponivel == produto2.quantidade_disponivel);
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

int verificar_valor(LUE *lista, Produto produto); // verificar valores de itens na lista 
bool imprimir_lista(LUE *lista); // mostrar lista
bool inserir_final_lista(LUE *lista, Produto produto);// Inserir item na lista 
bool remover_lista(LUE *lista, Produto produto); // remover itens da lista (do estoque)
bool pesquisar_lista(LUE *lista, Produto produto); // pesquisar lista
bool reajustar_preco(LUE *lista, int posicao, float preco); // reajustar pre�o de item na lista
bool reajustar_quantidade(LUE *lista, int posicao, int quantidade); // controlar quantidade disponiveis 
bool reajustar_desconto(LUE *lista, int posicao, float desconto); // controlar descontos 
// salvar lista em um arquivo
// pegar lista de um arquivo

void decoracao(int numero);

int main() {
    // Nova lista com os produtos a venda 
    LUE *produtos_venda = new LUE;
    if (produtos_venda == nullptr) {
        cout << "Aloca��o de mem�ria falhou";
        return 1;
    }

    // Novo produto para vender
    Produto blusa;
    blusa.nome = "blusa";
    blusa.preco = 30;
    blusa.desconto = 0;
    blusa.quantidade_disponivel = 1;

    inserir_final_lista(produtos_venda, blusa);
    imprimir_lista(produtos_venda);

    // Nova lista do cliente (carrinho de compras)
    LUE *carrinho = new LUE;
    if (carrinho == nullptr) {
        cout << "Aloca��o de mem�ria falhou";
        return 1;
    }

    // Nova lista com os dados sobre vendas (valor, desconto, forma de pagamento, 
    // total de vendas, total de vendas por forma de pagameto, total de vendar por vendedor, etc)

    while(true) {

        // Mostrar menu
        cout << "\n" << decoracao << "\n";
        cout << "\nEscolha uma das op��es:";
        cout << "\n1.Cliente Comprando";
        cout << "\n2.Pesquisar";
        cout << "\n3.Verificar Valor";
        cout << "\n4.Reajustar Pre�o";
        cout << "\n5.Remover Produto";
        cout << "\n6.Inserir Produto";
        cout << "\n7.Modificar Produto";
        cout << "\n8.Exit";
        cout << "\n" << decoracao << "\n";

        char choice;
        while(true) { // O usu�rio deve escolher o que fazer na aplica��o 
            cout << "\nRealizar a op��o: ";
            cin >> choice;

            if (choice >= '1' && choice <= '8') { // Verifica a entrada do usu�rio
                break;
            } else {
                cout << "\nEntrada inv�lida. Escolha uma n�mero de 1 a 6.";
            }
        } 

        switch (choice) {
            case 1: // Cliente comprando
                break;
            case 2: // Pesquisar um produto 
                break;
            case 3: // Verificar valor de um produto
                break;
            case 4: // Reajustar pre�o de um produto 
                break;
            case 5: // Remover produto
                break;
            case 6: // Inserir produto
                break;
            case 7: // Modificar produto
                break;
            case 8: // Sair do programa
                cout << "\nSaindo do programa...";
                // exclue os ponteiros? verificar se eles est�o excluidos?
                break;
            default:
                break;
        }

    }

    return 0;
}

bool imprimir_lista(LUE *lista) {
    No *temp = new No; // n� tempor�rio para atravessar a lista 

    // Equanto a lista n�o acabar
    while (temp != nullptr) {
        cout << temp->produto.nome << "," << temp->produto.preco << "," << temp->produto.desconto << "," << temp->produto.quantidade_disponivel << "\n";
    }

    return true;
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

bool remover_lista(LUE *lista, Produto produto) {
    No *temp = lista->comeco; // n� temporario para atravessar a lista
    No *temp_anterior = nullptr; // guarda o n� anterior do temp

    // Enquanto o elemento da lista n�o for nulo
    while (temp != nullptr && temp->produto != produto) {
        temp_anterior = temp;
        temp = temp->elo; // Pr�ximo produto na lista 
    }

    if (temp == lista->comeco && temp == lista->fim) { // a lista cont�m um unico elemento
        lista->comeco = nullptr;
        lista->fim = nullptr;
        delete temp;
        return true;
    }

    if (temp == lista->comeco) { // se o elemento a ser excluido � o primeiro da lista
        lista->comeco = temp->elo;
        delete temp;
        return true;
    }

    if (temp == lista->fim) { // se o elemento a ser excluido � o �ltimo da lista
        temp_anterior->elo =  nullptr;
        lista->fim = temp_anterior;
        delete temp;
        return true;
    }

    temp_anterior->elo = temp->elo; // caso o elemento a ser excluido esteja no meio da lista
    delete temp;
    return true;
}

bool reajustar_preco(LUE *lista, int posicao, float preco) {
    if (lista == nullptr || lista->comeco == nullptr) { // verfica se a lista � valida
        return false;
    }

    No *temp = lista->comeco; // n� temporario para atravessar a lista
    int i = 0;

    // Percorra a lista at� a posi��o desejada
    while (i != posicao) {
        i++;
        temp = temp->elo; // Pr�ximo produto na lista 
    }

    if (temp == nullptr) { // Verifica se a posi��o � valida
        return false;
    }

    temp->produto.preco = preco; // ajustando o preco

    return true;
}

bool reajustar_quantidade(LUE *lista, int posicao, int quantidade) {
    if (lista == nullptr || lista->comeco == nullptr) { // verfica se a lista � valida
        return false;
    }

    No *temp = lista->comeco; // n� temporario para atravessar a lista
    int i = 0;

    // Percorra a lista at� a posi��o desejada
    while (i != posicao) {
        i++;
        temp = temp->elo; // Pr�ximo produto na lista 
    }

    if (temp == nullptr) { // Verifica se a posi��o � valida
        return false;
    }

    temp->produto.quantidade_disponivel = quantidade; // ajustando a quantidade 

    return true;
}

bool reajustar_desconto(LUE *lista, int posicao, float desconto) { 
    if (lista == nullptr || lista->comeco == nullptr) { // verfica se a lista � valida
        return false;
    }

    No *temp = lista->comeco; // n� temporario para atravessar a lista
    int i = 0;

    // Percorra a lista at� a posi��o desejada
    while (i != posicao) {
        i++;
        temp = temp->elo; // Pr�ximo produto na lista 
    }

    if (temp == nullptr) { // Verifica se a posi��o � valida
        return false;
    }

    temp->produto.desconto = desconto; // ajustando o desconto

    return true;
} 

void decoracao(int numero) {
    for (int i = 0; i < numero; i++) { // = * numero
        cout << "=";
    }
}