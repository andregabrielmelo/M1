#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <locale.h>

// Incluindo bibliotecas
// #include "produto.cpp"
#include "listaDuplamenteEncadeada.cpp"

void pause();
void limpar_tela();
void limpar_buffer();
void decoracao(int quantidade);

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    // // Novo produto
    // Produto blusa = criar_produto();

    // // Novo produto
    // Produto carro = criar_produto();

    // // Nova lista
    // Lista *produtos_venda = new Lista;
    // if (produtos_venda == nullptr) {
    //     cout << "\nAlocação de memÃ³ria falhou";
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
        limpar_tela(); // Sempre limpar tela antes de carregar o menu

        // Mostrar menu
        cout << "\n";
        decoracao(150);
        cout << "\n1.Inserir produto no catalogo";
        cout << "\n2.Mostrar catalogo";
        cout << "\n3.Pesquisar produto";
        cout << "\n4.Sair";
        cout << "\n";
        decoracao(150);

        // Escolher opção
        int escolha;
        while(true) {
            cout << "\nEscolher opção: ";   
            cin >> escolha;

            if (1 <= escolha && escolha <= 4) {
                break;
            } else {
                cout << "\nEntrada invalida. Escolha um nÃºmero entre 1 e 3.";
            }
        }

        // Ir para opção
        switch (escolha) {
        case 1:  // Inseri um produto no catalogo
        {
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
        }
        case 2: // Mostra os produtos no catalogo
        {
            mostrarLista(catalogo);

            limpar_buffer();
            pause();

            break;
        }
        case 3: // Pesquisar produto
        {
        
        if (catalogo->comeco == nullptr) { // Verificar se a lista está vazia
            cout << "\nCatalogo vazio!";
            break;
        }

        // Pesquisar por nome ou preço
        int *choice = new int;
        cout << "\nPesquisar por:";
        cout << "\n1.Nome";
        cout << "\n2.Preço";

        while(true) {
            cout << "\nEscolher opção: ";   
            cin >> *choice;

            if (1 <= *choice && *choice <= 2) {
                break;
            } else {
                cout << "\nEntrada invalida. Escolha um nÃºmero entre 1 e 2.";
            }
        }

        if (*choice == 1) {
            string *nome = new string; // cria váriael para guardar nome do produto
            
            // Pega o nome do produto procurado
            cout << "\nNome do produto: "; 
            cin >> *nome; // TODO: validar input 

            // Mostra o produto encontrado
            cout << pesquisarProduto(catalogo, *nome);

            delete nome; // libera o ponteiro 
        } else {
            float *preco = new float; // cria variável para guardar o preco do produto

            // Pega o preco do produto procurado
            cout << "\nPreço do produto: ";
            cin >> *preco; // TODO: validar input 

            // Mostra o produto encontrado
            cout << pesquisarProduto(catalogo, *preco);

            delete preco; // libera o ponteiro
        }
        
        delete choice; // libera o ponteiro

        pause();

        break;
        }
        case 4: // Sai do programa
        {
            cout << "\nObrigado por usar nosso programa\n";

            // Colocar a lista emn outro arquivo
            // Liberar lista 

            return 0;
        }
        default:
            break;
        }
    } 
}

void limpar_tela() {
    cout << "\033[2J\033[1;1H";
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

void decoracao(int quantidade) { 
    for (int i = 0; i < quantidade; i++) { // Printa '=' * quantidade 
        cout << "=";
    }

    return;
}

// TODO: Fazer função para validar o input do usuário 