#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

// Criando struct produto
struct Produto {
    string nome;
    int preco;
    float desconto;
    int quantidade;
};

// Overloading
ostream& operator<<(ostream &os, const Produto &produto) {
    os << "Nome: " << produto.nome << "\n";
    os << "Preço: " << produto.preco << "\n";
    os << "Desconto: " << produto.desconto << "%\n";
    os << "Quantidade: " << produto.quantidade << "\n";

    return os;
}

// Funções
// Criar produto
Produto criarProduto() {
    Produto novo_produto; // cria a váriavel do novo produto 

    // Valores do novo produto
    std::cout << "Nome: ";
    std::cin >> novo_produto.nome;
    
    std::cout << "Preço: ";
    std::cin >> novo_produto.preco;
    
    std::cout << "Desconto: ";
    std::cin >> novo_produto.desconto;
    
    std::cout << "Quantidade: ";
    std::cin >> novo_produto.quantidade;

    return novo_produto; // retorno o novo produto 
}

// Funcao para reajustar produto //
void reajustar(Produto *produto){

    // Valores do reajuste
    std::cout << "Novo nome: ";
    std::cin >> produto->nome;

    std::cout << "Novo preço: ";
    std::cin >> produto->preco;

    std::cout << "Novo desconto: ";
    std::cin >> produto->desconto;

    std::cout << "Nova quantidade: ";
    std::cin >> produto->quantidade;

    return;
}