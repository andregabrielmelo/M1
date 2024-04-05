#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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
Produto criar_produto() {
    Produto novo_produto; // cria a váriavel do novo produto 

    // Valores do novo produto
    cout << "Nome: ";
    cin >> novo_produto.nome;
    
    cout << "Preço: ";
    cin >> novo_produto.preco;
    
    cout << "Desconto: ";
    cin >> novo_produto.desconto;
    
    cout << "Quantidade: ";
    cin >> novo_produto.quantidade;

    return novo_produto; // retorno o novo produto 
}

