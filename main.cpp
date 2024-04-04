#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <locale.h>

using namespace std;

// Struct produto 
struct Produto {
    string nome;
    float preco;
    float desconto;
    int quantidade_disponivel;

    // operator = overloading com o tipo Produto
    Produto& operator=(const Produto& produto) {
        if (this != &produto) { // Verifica se não é a mesma instância
            // Atribui os membros individualmente
            this->nome = produto.nome;
            this->preco = produto.preco;
            this->desconto = produto.desconto;
            this->quantidade_disponivel = produto.quantidade_disponivel;
        }
        return *this;
    }
};


// Struct node (produto + próximo produto)
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

// operator << overloading 
std::ostream& operator<<(std::ostream &os, const Produto &produto) {
    os << "Nome: " << produto.nome << "\n";
    os << "Preço: " << produto.preco << "\n";
    os << "Desconto: " << produto.desconto << "%\n";
    os << "Quantidade disponivel: " << produto.quantidade_disponivel << "\n";

    return os;
}

// operator == overloading com o tipo Produto
bool operator ==(const Produto &produto1, const Produto &produto2) {
    return (produto1.nome == produto2.nome && produto1.preco == produto2.preco && produto1.quantidade_disponivel == produto2.quantidade_disponivel);
}

// operator != overloading com o tipo Produto
bool operator !=(const Produto &produto1, const Produto &produto2) {
    return !(produto1.nome == produto2.nome && produto1.preco == produto2.preco && produto1.quantidade_disponivel == produto2.quantidade_disponivel);
}

int verificar_valor(LUE *lista, Produto produto); // verificar valores de itens na lista 
bool imprimir_lista(LUE *lista); // mostrar lista
bool inserir_final_lista(LUE *lista, Produto produto);// Inserir item na lista 
bool remover_lista(LUE *lista, Produto produto); // remover itens da lista (do estoque)
bool pesquisar_lista(LUE *lista, Produto produto); // pesquisar lista
bool reajustar_preco(LUE *lista, int posicao, float preco); // reajustar preço de item na lista
bool reajustar_quantidade(LUE *lista, int posicao, int quantidade); // controlar quantidade disponiveis 
bool reajustar_desconto(LUE *lista, int posicao, float desconto); // controlar descontos 
// salvar lista em um arquivo
// pegar lista de um arquivo

bool mostrar_item_lista(LUE *lista, string nome_produto); // pesquisar e, se encontrar, mostrar o item

void decoracao(int numero);

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    // Nova lista com os produtos a venda 
    LUE *produtos_venda = new LUE;
    if (produtos_venda == nullptr) {
        cout << "Alocação de memória falhou";
        return 1;
    }

    // Novo produto para vender
    Produto blusa;
    blusa.nome = "blusa";
    blusa.preco = 30;
    blusa.desconto = 0;
    blusa.quantidade_disponivel = 1;

    inserir_final_lista(produtos_venda, blusa);

    cout << "\nProdutos a venda:\n";
    imprimir_lista(produtos_venda);

    // Nova lista do cliente (carrinho de compras)
    LUE *carrinho = new LUE;
    if (carrinho == nullptr) {
        cout << "Alocação de memória falhou";
        return 1;
    }

    // Nova lista com os dados sobre vendas (valor, desconto, forma de pagamento, 
    // total de vendas, total de vendas por forma de pagameto, total de vendar por vendedor, etc)

    while(true) {

        // Mostrar menu
        cout << "\n"; 
        decoracao(100);
        cout << "\n";

        cout << "\nEscolha uma das opções:";
        cout << "\n1.Cliente Comprando";
        cout << "\n2.Pesquisar";
        cout << "\n3.Verificar Valor";
        cout << "\n4.Reajustar Preço";
        cout << "\n5.Remover Produto";
        cout << "\n6.Inserir Produto";
        cout << "\n7.Modificar Produto";
        cout << "\n8.Exit";
        
        cout << "\n"; 
        decoracao(100);
        cout << "\n";

        char choice;
        while(true) { // O usuário deve escolher o que fazer na aplicação 
            cout << "\nRealizar a opção: ";
            cin >> choice;

            if (choice >= '1' && choice <= '8') { // Verifica a entrada do usuário
                break;
            } else {
                cout << "\nEntrada inválida. Escolha uma número de 1 a 6.";
            }
        } 

        string nome_produto;
        switch (choice) {
            case 1: // Cliente comprando
                break;
            case '2': // Pesquisar um produto pelo nome 

                // Qual item ele procura, o nome
                cout << "\nQual o item que você procura?";
                cout << "\nNome: ";
                cin >> nome_produto;

                // Procura e mostra o item
                mostrar_item_lista(produtos_venda, nome_produto);

                // Limpar buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Tem que pausar aqui
                do {
                cout << '\n' << "Press a key to continue...";
                } while (cin.get() != '\n');

                break;
            case 3: // Verificar valor de um produto
                break;
            case 4: // Reajustar preço de um produto 
                break;
            case 5: // Remover produto
                break;
            case 6: // Inserir produto
                break;
            case 7: // Modificar produto
                break;
            case 8: // Sair do programa
                cout << "\nSaindo do programa...";
                break;
                // exclue os ponteiros? verificar se eles estão excluidos?
                break;
            default:
                break;
        }

    }

    return 0;
}

bool imprimir_lista(LUE *lista) {
    No *temp = new No; // nó temporário para atravessar a lista 

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto a lista não acabar
    while (temp != nullptr) {
        cout << "Nome: " << temp->produto.nome << "\n";
        cout << "Preço: " << temp->produto.preco << "\n";
        cout << "Desconto: " << temp->produto.desconto << "%\n";
        cout << "Quantidade disponivel: " << temp->produto.quantidade_disponivel << "\n";

        temp = temp->elo; // próximo elemento
    }

    return true;
}

bool pesquisar_lista(LUE *lista, Produto produto) { // Mudar para pesquisar o produto pelo nome/preço. Talvez deve retornar o produto?
    No *temp = lista->comeco; // no temporario para atravessar a lista

    // Enquanto o elemento da lista não for nulo
    while (temp != nullptr) {

        if (temp->produto == produto) { // Se o produto foi encontrado na lista
            return true;
        }

        temp = temp->elo; // Próximo elemento na lista 
    }

    return false;
}

int verificar_valor(LUE *lista, Produto produto) {
    No *temp = lista->comeco; // nó temporario para atravessar a lista

    // Enquanto o elemento da lista não for nulo
    while (temp != nullptr) {

        if (temp->produto == produto) { // Se o produto foi encontrado na lista, retorna o preço
            return temp->produto.preco;
        }

        temp = temp->elo; // Próximo produto na lista 
    }

    return 0;
}

bool inserir_final_lista(LUE *lista, Produto produto) { // Verificar novamente em uma revisão final

    // Novo nó, para o novo produto
    No *novo_no = new No;
    novo_no->produto = produto;
    novo_no->elo = nullptr;

    if (novo_no == nullptr) { // Verificar se a alocação de memoria deu certo 
        return false;
    }

    if (lista->comeco == nullptr) { // Caso a lista esteja vazia
        lista->comeco = novo_no;
        lista->fim = novo_no; // muda o fim da lista
    } else {
        lista->fim->elo = novo_no; // Adiciona um próximo nó para o ultimo da lista
    }

    return true;
}

bool remover_lista(LUE *lista, Produto produto) {
    No *temp = lista->comeco; // nó temporario para atravessar a lista
    No *temp_anterior = nullptr; // guarda o nó anterior do temp

    // Enquanto o elemento da lista não for nulo
    while (temp != nullptr && temp->produto != produto) {
        temp_anterior = temp;
        temp = temp->elo; // Próximo produto na lista 
    }

    if (temp == lista->comeco && temp == lista->fim) { // a lista contém um unico elemento
        lista->comeco = nullptr;
        lista->fim = nullptr;
        delete temp;
        return true;
    }

    if (temp == lista->comeco) { // se o elemento a ser excluido é o primeiro da lista
        lista->comeco = temp->elo;
        delete temp;
        return true;
    }

    if (temp == lista->fim) { // se o elemento a ser excluido é o último da lista
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
    if (lista == nullptr || lista->comeco == nullptr) { // verfica se a lista é valida
        return false;
    }

    No *temp = lista->comeco; // nó temporario para atravessar a lista
    int i = 0;

    // Percorra a lista até a posição desejada
    while (i != posicao) {
        i++;
        temp = temp->elo; // Próximo produto na lista 
    }

    if (temp == nullptr) { // Verifica se a posição é valida
        return false;
    }

    temp->produto.preco = preco; // ajustando o preco

    return true;
}

bool reajustar_quantidade(LUE *lista, int posicao, int quantidade) {
    if (lista == nullptr || lista->comeco == nullptr) { // verfica se a lista é valida
        return false;
    }

    No *temp = lista->comeco; // nó temporario para atravessar a lista
    int i = 0;

    // Percorra a lista até a posição desejada
    while (i != posicao) {
        i++;
        temp = temp->elo; // Próximo produto na lista 
    }

    if (temp == nullptr) { // Verifica se a posição é valida
        return false;
    }

    temp->produto.quantidade_disponivel = quantidade; // ajustando a quantidade 

    return true;
}

bool reajustar_desconto(LUE *lista, int posicao, float desconto) { 
    if (lista == nullptr || lista->comeco == nullptr) { // verfica se a lista é valida
        return false;
    }

    No *temp = lista->comeco; // nó temporario para atravessar a lista
    int i = 0;

    // Percorra a lista até a posição desejada
    while (i != posicao) {
        i++;
        temp = temp->elo; // Próximo produto na lista 
    }

    if (temp == nullptr) { // Verifica se a posição é valida
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

bool mostrar_item_lista(LUE *lista, string nome_produto) {
    No *temp = lista->comeco; // no temporario para atravessar a lista

    // Enquanto o elemento da lista não for nulo
    bool tem = false;
    while (temp != nullptr) {

        if (temp->produto.nome == nome_produto) { // Se o produto foi encontrado na lista
            cout << temp->produto; 
            tem = true;
        }

        temp = temp->elo; // Próximo elemento na lista 
    }

    return tem;
}