//            Trabalho M1 - Estrurura de dados           // 
// Nomes: Thomas Norfleet Crews & Andre Gabriel De Melo //

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <locale.h>
#include <string>
#include <fstream>

// Incluindo bibliotecas
// #include "produto.cpp"
#include "listaDuplamenteEncadeada.cpp"

using namespace std;

const int TAMANHO_MAXIMO = 100; // Tamanho máximo do array

struct Carrinho {
    string vendedor;
    Lista *lista_compras = new Lista;
};

struct Venda {
    float valorTotal;
    float desconto;
    string formaPagamento;
    string vendedor;
    Venda *proxima_venda = nullptr;
};

struct ListaVenda {
    Venda *comeco = nullptr;
    Venda *fim = nullptr;
};

// TODO: Fazer função para validar o input do usuário 

void pause();
void limpar_tela();
void limpar_buffer();
void decoracao(int quantidade);

bool lerArquivo(Lista *lista, string arquivo_nome);
bool salvarDados(Lista *lista, string arquivo_nome);

void mostrarCarrinho(Carrinho carrinho);
bool inserirVenda(ListaVenda *lista, Venda venda);
Venda registrarVenda(Carrinho carrinho, string formaPagamento);
void mostrarVenda(ListaVenda *lista);

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    Lista *catalogo = new Lista;
    lerArquivo(catalogo, "catalogo.csv");

    ListaVenda *vendas = new ListaVenda;
    
    while(true) {
        limpar_tela(); // Sempre limpar tela antes de carregar o menu

        // Mostrar menu
        decoracao(150);
        cout << "\n1.Inserir produto no catalogo";
        cout << "\n2.Remover produto do catalago";
        cout << "\n3.Reajustar produto do catalago";
        cout << "\n4.Mostrar catalogo";
        cout << "\n5.Pesquisar produto";
        cout << "\n6.Comprar";
        cout << "\n7.Total Vendas";
        cout << "\n8.Sair";
        cout << "\n";
        decoracao(150);

        // Escolher opção
        int escolha;
        while(true) {
            cout << "\nEscolher opção: ";   
            cin >> escolha;

            if (1 <= escolha && escolha <= 8) {
                break;
            } else {
                cout << "\nEntrada invalida. Escolha um número entre 1 e 7.";
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
            cout << "Preço do produto: ";
            cin >> novo_produto->preco;

            // Desconto do produto
            cout << "Desconto do produto: ";
            cin >> novo_produto->desconto;         

            // Quantidade do produto
            cout << "Quantidade do produto: ";
            cin >> novo_produto->quantidade;

            if(inserir_final_lista(catalogo, novo_produto)) { // Inseri na lista, retonando se teve sucesso ou não
                cout << "\nItem inserido com sucesso\n";
            } else {
                cout << "\nFalha na inserção do item\n";
            }
            
            pause();

            break;
        }
        case 2: // Remove produto do catalogo
        {
            cout << "\nRemovendo produto do catalogo\n";

            // Pega o nome do produto para remover
            string *produto_nome = new string; 
            cout << "Nome do produto: ";
            cin >> *produto_nome;

            // Libera o produto 
            if(liberarItemLista(catalogo, *produto_nome)) {
                cout << "\nItem removido com sucesso!\n";
            } else {
                cout << "\nFalha na remoção do item\n";
            }

            pause();

            break;
        }
        case 3: // Reajusta produto do catalogo
        {
            string nome;
            cout << "\nEscolha algum produto do catalogo: ";
            cin >> nome;

            Produto *temp = new Produto;
            temp = pegarEndereco(catalogo, nome);
            
            if (temp == nullptr) {
                cout << "\nProduto não encontrado\n";
                pause();
                break;
            }
    
            reajustar(temp);
            break;
        }
        case 4: // Mostra os produtos no catalogo
        {
            limpar_tela();

            cout << "\nCatalogo:\n";

            mostrarLista(catalogo);

            pause();

            break;
        }
        case 5: // Pesquisar produto
        {
        
            if (catalogo->comeco == nullptr) { // Verificar se a lista está vazia
                cout << "\nCatalogo vazio!";
                pause();
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
                    cout << "\nEntrada invalida. Escolha um número entre 1 e 2.";
                }
            }

            if (*choice == 1) {
                string *nome = new string; // cria váriael para guardar nome do produto
                
                // Pega o nome do produto procurado
                cout << "\nNome do produto: ";
                limpar_buffer(); 
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
        case 6:
        {
            
            // criar carrinho
            Carrinho carrinho;
            carrinho.lista_compras = new Lista;

            bool comprando = true;

            limpar_tela();
            
            // Pega o vendedor
            cout << "\nNome do vendedor: ";
            cin >> carrinho.vendedor;

            while (comprando) {
                limpar_tela();

                cout << "\nComprando\n";

                // Opções
                cout << "\n1.Adicionar ao carrinho";
                cout << "\n2.Retirar do carrinho";
                cout << "\n3.Mostrar carrinho";
                cout << "\n4.Ir ao caixa";

                // Escolher opção
                int escolhaComprando;
                while(true) {
                    cout << "\n\nEscolher opção: ";   
                    cin >> escolhaComprando;

                    if (1 <= escolhaComprando && escolhaComprando <= 4) {
                        break;
                    } else {
                        cout << "\nEntrada invalida. escolha um número entre 1 e 4.";
                    }
                }

                switch(escolhaComprando){
                    case 1: // Adicionando produto no carrinho
                    {
                        limpar_tela();

                        cout << "\nAdicionando ao carrinho...\n";

                        // Escolhendo produto
                        string nome_produto;
                        cout << "\nNome do produto: ";
                        cin >> nome_produto;

                        // Pesquisando o produto
                        Produto produto = pesquisarProduto(catalogo, nome_produto);

                        // Verificar que o produto foi retornado 
                        if (produto.nome == "") {
                            cout << "\nProduto não encontrado!\n";
                            
                            pause();
                            break;
                        }

                        // Inserindo o produto
                        inserir_final_lista(carrinho.lista_compras, produto);

                        pause();
                        break;
                    }
                    case 2:
                    {
                        limpar_tela();

                        cout << "\nRemovendo do carrinho...\n";

                        // Escolhendo produto
                        string nome_produto;
                        cout << "\nNome do produto: ";
                        cin >> nome_produto;

                        // Pesquisando o produto
                        Produto produto = pesquisarProduto(catalogo, nome_produto);

                        // Verificar que o produto foi retornado 
                        if (produto.nome == "") {
                            cout << "\nProduto não encontrado!\n";
                            
                            pause();
                            break;
                        }

                        // Remover produto
                        liberarItemLista(carrinho.lista_compras, produto.nome);

                        pause();
                        break;

                    }
                    case 3:
                    {
                        limpar_tela();

                        mostrarCarrinho(carrinho);

                        pause();
                        break;
                    }
                    case 4:
                    {
                        limpar_tela();

                        cout << "\nFinalizando compra...\n";

                        // Mostra o carrinho
                        mostrarCarrinho(carrinho);

                        // Pegar valor total
                        
                        // Pegar forma de pagamento
                        string formaPagamento;

                        cout << "\nPix";
                        cout << "\nDinheiro";
                        cout << "\nCartão";

                        cout << "\n\nForma de pagamento: ";
                        cin >> formaPagamento;

                        // Registra venda 
                        inserirVenda(vendas, registrarVenda(carrinho, formaPagamento));

                        // Volta para o menu principal
                        comprando = false;
                        
                        pause();
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            break;
        }
        case 7: // Total Vendas Dia
        {
            mostrarVenda(vendas);
        }
         case 8: // Sai do programa
        {
            cout << "\nObrigado por usar nosso programa\n";

            // Colocar a lista emn outro arquivo
            salvarDados(catalogo, "catalogo.csv");

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
    limpar_buffer();
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


bool lerArquivo(Lista *lista, string arquivo_nome) {
    ifstream arquivo;
    arquivo.open(arquivo_nome); // abre arquivo 
    string line;
    string produto[4];
    Produto *novo_produto = new Produto; // Removido a alocação aqui

    // Le as linhas e insere na lista
    if(arquivo.is_open()) { // verifica se o arquivo está aberto 
        while (getline(arquivo, line)) {
            // Zera o vetor
            produto[0] = "";
            produto[1] = "";
            produto[2] = "";
            produto[3] = "";

            int index = 0; // Reinicializa o índice para zero a cada iteração
            // Pega o produto
            for (int i = 0; i < line.size(); i++) { // Usa line.size() para obter o comprimento real da string
                if (line[i] == ',') {
                    index++;
                } else {
                    produto[index] += line[i];
                }
            }

            // Cria um novo produto a cada iteração
            novo_produto = new Produto; // Move a alocação aqui
            novo_produto->nome = produto[0];
            novo_produto->preco = stoi(produto[1]);
            novo_produto->desconto = stof(produto[2]);
            novo_produto->quantidade = stoi(produto[3]);

            // Insere na lista 
            inserir_final_lista(lista, novo_produto);
        }

        arquivo.close(); // Fecha arquivo
    } else {
        cout << "\nNão foi possível ler o arquivo\n";
        return false;
    }

    return true;
}

// Função para salvar os dados em um arquivo
bool salvarDados(Lista *lista, string arquivo_nome) {
    
    ofstream arquivo(arquivo_nome); // Abre o arquivo para escrita
    
    if (arquivo.is_open()) { // Verifica se o arquivo foi aberto com sucesso
        ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // Para iterar sobre a lista

        temp = lista->comeco; // tem aponta para o começo da lista

        // Enquanto não chegar ao fim da lista
        while (temp != nullptr) {
            // Copia produto para o arquivo
            arquivo << temp->produto.nome << "," << temp->produto.preco << "," << temp->produto.desconto << "," << temp->produto.quantidade << "\n";

            temp = temp->eloP;
        }

        arquivo.close(); // Fecha o arquivo após escrever todos os dados

        return true;
    } else {
        cout << "Erro ao abrir o arquivo para salvar.\n"; // Exibe uma mensagem de erro se não for possível abrir o arquivo
        return false;
    }
}

// Função para carregar os dados do arquivo 
void carregaraDados(int* array, int& tamanho, const string& arquivo_nome) {
    ifstream arquivo(arquivo_nome); // Abre o arquivo para leitura
    if (arquivo.is_open()) { // Verifica se o arquivo foi aberto com sucesso
        int valor;
        tamanho = 0; // Inicializa o tamanho como zero
        while (arquivo >> valor && tamanho < TAMANHO_MAXIMO) { // Lê os dados do arquivo enquanto houver dados disponíveis e o tamanho do array não ultrapassar o limite
            array[tamanho++] = valor; // Armazena cada valor lido no array e incrementa o tamanho
        }
        arquivo.close(); // Fecha o arquivo após ler todos os dados
    } else {
        cout << "Erro ao abrir o arquivo para carregar.\n"; // Exibe uma mensagem de erro se não for possível abrir o arquivo
    }
}

void mostrarCarrinho(Carrinho carrinho) {
    if (carrinho.lista_compras == nullptr) { // verificar se o carrinho está vazio
        cout << "\nCarrinho vazio!\n";
        return;
    }

    // Mostrar vendedor
    cout << "\nVendedor: " << carrinho.vendedor;

    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada; // Novo item para atravessar a lista do carrinho

    temp = carrinho.lista_compras->comeco; // temp aponta para o inicio da lista

    // Mostrar compras
    cout << "\nCompras:\n";

    while (temp != nullptr) {
        // Mostra o item
        cout << temp->produto.nome;
        cout << "\nPreço sem desconto: " << temp->produto.preco;
        cout << "\nPreço com desconto: " << (temp->produto.preco * (1 - temp->produto.desconto)) << "(" << temp->produto.desconto << "%)";
        cout << "\nQuantidade disponivel: " << temp->produto.quantidade;

        temp = temp->eloP; // temp vai para o próximo item
    }

    cout << "Total: ";

}

bool inserirVenda(ListaVenda *lista, Venda venda){
    // Criar um novo nó para armazenar a nova venda
    Venda *nova_venda = new Venda;
    *nova_venda = venda; // Copiar os dados da venda para a nova venda

    // Se a lista estiver vazia
    if (lista->comeco == nullptr) {
        lista->comeco = nova_venda;
        lista->fim = nova_venda;
        return true;
    }

    // Adicionar venda no final
    lista->fim->proxima_venda = nova_venda;
    lista->fim = nova_venda;

    return true;
}

Venda registrarVenda(Carrinho carrinho, string formaPagamento) {
    // Criar variavel para atravessar lista
    ItemDuplamenteEncadeada *temp = new ItemDuplamenteEncadeada;

    // Aponta para o começo da lista
    temp = carrinho.lista_compras->comeco;
    
    // Pegar valor total
    float valorTotal = 0;
    float descontoTotal = 0;
    while (temp != nullptr) {
        valorTotal += (temp->produto.preco * (1 - temp->produto.desconto));
        descontoTotal += (temp->produto.preco * temp->produto.desconto);

        temp = temp->eloP; // Vai para o próximo elemento
    }

    // Cria um novo objeto Venda
    Venda nova_venda;
    nova_venda.valorTotal = valorTotal;
    nova_venda.desconto = descontoTotal;
    nova_venda.formaPagamento = formaPagamento;
    nova_venda.vendedor = carrinho.vendedor;

    // Insere a venda na lista de vendas
    return nova_venda;
}

void mostrarVenda(ListaVenda *lista) {
    Venda *temp = new Venda; // nó temporário para atravessar a lista

    if (lista->comeco == nullptr) { // Se a lista estiver vazia
        cout << "\nLista vazia"; // TODO: Retirar isso e retornar algo ao inves disso?
    }

    temp = lista->comeco; // Aponta para o começo da lista

    // Equanto a lista não acabar
    while (temp != nullptr) {
        cout << "\n";
        cout << temp->valorTotal;
        cout << temp->desconto;
        cout << temp->formaPagamento;
        cout << temp->vendedor;

        cout << "\n";

        temp = temp->proxima_venda; // próximo elemento
    }
}