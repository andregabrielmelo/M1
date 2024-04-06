#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <locale.h>

// Incluindo bibliotecas
// #include "produto.cpp"
#include "listaDuplamenteEncadeada.cpp"

void pause();
void limpar_buffer();
void decoracao();

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    // // Novo produto
    // Produto blusa = criar_produto();

    // // Novo produto
    // Produto carro = criar_produto();

    // // Nova lista
    // Lista *produtos_venda = new Lista;
    // if (produtos_venda == nullptr) {
    //     cout << "\nAlocaÃ§Ã£o de memÃ³ria falhou";
    //     return 1;
    // }
    // produtos_venda->comeco == nullptr;
    // produtos_venda->fim == nullptr;

    // inserir_final_lista(produtos_venda, blusa);
    // inserir_final_lista(produtos_venda, carro);

    // cout << "\nLista:\n";
    // mostrarLista(produtos_venda);

    Lista *catalogo = new Lista;

    while(true) {

        // Mostrar menu
        decoracao();
        cout << "\n1.Inserir produto no catalogo";
        cout << "\n2.Mostrar catalogo";
        cout << "\n3.Sair";
        cout << "\n";
        decoracao();

        // Escolher opÃ§Ã£o
        int choice;
        while(true) {
            cout << "\nEscolher opÃ§Ã£o: ";   
            cin >> choice;

            if (1 <= choice && choice <= 3) {
                break;
            } else {
                cout << "\nEntrada invalida. Escolha um nÃºmero entre 1 e 3.";
            }
        }

        // Ir para opÃ§Ã£o
        switch (choice) {
        case 1:  // Inseri um produto no catalogo
            Produto *novo_produto = new Produto; // Criar um ponteiro para o novo produto

            // Nome do produto
            cout << "\nNome do produto: ";
            cin >> novo_produto->nome;

            // Preço do produto
            cout << "\nPreço do produto: ";
            cin >> novo_produto->preco;

            // Desconto do produto
            cout << "\nDesconto do produto: ";
            cin >> novo_produto->desconto;         

            // Quantidade do produto
            cout << "\nQuantidade do produto: ";
            cin >> novo_produto->quantidade;

            if(inserir_final_lista(catalogo, novo_produto)) { // Inseri na lista, retonando se teve sucesso ou não
                cout << "\nItem inserido com sucesso\n";
            } else {
                cout << "\nFalha na inserção do item\n";
            }
            
            pause();

            break;

        case 2: // Mostra os produtos no catalogo
            mostrarLista(catalogo);
            break;

        case 3: // Sai do programa
            cout << "\nObrigado por usar nosso programa\n";
            return 0;
        
        default:
            break;
        }
    } 
}

void limpar_buffer() { // Limpa o buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause() {
    do { // Pausa o programa, até o usuário clicar alguma tecla
        cout << '\n' << "Pressione uma tecla para continuar...";
    } while (cin.get() != '\n');

    return;
}

void decorcao() { 
    for (int i = 0; i < numeric_limits<streamsize>::max(); i++) { // Printa uma linha inteira de '='
        cout << "=";
    }

    return;
}