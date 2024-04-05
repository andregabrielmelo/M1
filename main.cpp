#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <locale.h>

// Incluindo bibliotecas
// #include "produto.cpp"
#include "listaDuplamenteEncadeada.cpp"

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    // // Novo produto
    // Produto blusa = criar_produto();

    // // Novo produto
    // Produto carro = criar_produto();

    // // Nova lista
    // Lista *produtos_venda = new Lista;
    // if (produtos_venda == nullptr) {
    //     cout << "\nAlocação de memória falhou";
    //     return 1;
    // }
    // produtos_venda->comeco == nullptr;
    // produtos_venda->fim == nullptr;

    // inserir_final_lista(produtos_venda, blusa);
    // inserir_final_lista(produtos_venda, carro);

    // cout << "\nLista:\n";
    // mostrarLista(produtos_venda);

    while(true) {

        // Mostrar menu
        cout << "\n1.Inserir Produto";
        cout << "\n2.Mostrar catalogo";

        // Escolher opção
        int choice;
        while(true) {
            cout << "\nEscolher opção: ";   
            cin >> choice;

            if (1 <= choice &&) {
                
            }
        }
    } 

    return 0;
}