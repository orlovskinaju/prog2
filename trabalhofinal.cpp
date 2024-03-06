#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cassert>

using namespace std;

enum CodigoProduto {
    CAMISETA_MASCULINA = 1,
    CAMISETA_FEMININA,
    TOP,
    LEGGIN,
    SHORTS_FEMININO,
    SHORTS_MASCULINO
};

enum Tamanho {
    P = 1,
    M,
    G,
    GG
};

enum Cor {
    ROSA = 1,
    AZUL,
    PRETO,
    VERDE_MUSGO,
    ROXO,
    CINZA
};

struct Produto {
    CodigoProduto codigo;
    vector<Tamanho> tamanhos;
    vector<Cor> cores;
    vector<int> quantidades;
    double preco;
};

struct Venda {
    int codigoProduto;
    Tamanho tamanho;
    Cor cor;
    int quantidade;
    double preco;
};

struct Compra {
    vector<Venda> produtos;
    double valorTotal;
};

void mostrarmenuPrincipalEstoque();
void mostrarMenuProdutosEstoque();
void mostrarMenuTamanhosEstoque();
void mostrarMenuCoresEstoque();
void adicionarProdutoEstoque(Produto* estoque, CodigoProduto codigoProduto);
void adicionarTamanhoCorEstoque(Produto& produto);
void buscatProdutoEstoque(Produto* estoque, CodigoProduto codigoProduto);
void buscarProdutoRecursivo(Produto* estoque, CodigoProduto codigoProduto, int indice = 0);
void exibirEstoque(Produto* estoque);
void exibirTamanhosCoresEstoque(const Produto& produto);
void verificarEstoque(Produto* estoque);
void menuPrincipalEstoque(Produto* estoque);
bool validarEscolha(int escolha, int min, int max);

struct Cliente {
    string nome;
    string cpf;
    string telefone;
    string dataCadastro;
};

void menuPrincipal();
void menuClientes();
void cadastrarCliente(vector<Cliente>& listaClientes);
void exibirListaClientes(const vector<Cliente>& listaClientes);
void procurarClientePorCPF(const vector<Cliente>& listaClientes);
void venderProduto(Produto* estoque, vector<Cliente>& listaClientes);

bool compararProdutos(const Produto& produto1, const Produto& produto2);
void ordenarEstoque(Produto* estoque);

int main(){
    vector<Cliente> listaClientes;
    int escolha;
    int escolhaprincipal;

    const int TAMANHO_ESTOQUE = 100;
    Produto* estoque = new Produto[TAMANHO_ESTOQUE];
    estoque[0].preco = 109.90;  // CAMISETA_MASCULINA
    estoque[1].preco = 109.90;  // CAMISETA_FEMININA
    estoque[2].preco = 59.90;   // TOP
    estoque[3].preco = 129.90;  // LEGGIN
    estoque[4].preco = 119.90;  // SHORTS_FEMININO
    estoque[5].preco = 99.90;   // SHORTS_MASCULINO

    for (int i = 0; i < TAMANHO_ESTOQUE; ++i) {
        estoque[i].codigo = static_cast<CodigoProduto>(i % 6 + 1);  // Cicla pelos 6 produtos
    }

    do{
        menuPrincipal();
        cin>> escolhaprincipal;
        system ("cls");
        switch (escolhaprincipal) {
            case 1:
                menuPrincipalEstoque(estoque);
                system ("cls");
                break;
            case 2:
                do {
                    menuClientes();
                    cin >> escolha;
                    system("cls");
                    if(escolha == 1){
                        cadastrarCliente(listaClientes);  
                    }
                    else if(escolha == 2){
                        exibirListaClientes(listaClientes);    
                    }
                    else if(escolha == 3){
                        procurarClientePorCPF(listaClientes);    
                    }
                    else{
                        cout << "Voltando ao menu principal" << endl;
                    }
                } while (escolha != 4);
                break;
            case 3:
                venderProduto(estoque, listaClientes);
                break;
            case 4:
                cout << "Obrigada por usar o programa" << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }while(escolhaprincipal!=4);
}

void menuPrincipal(){
    cout<< "Bem vindo" << endl;
    cout<< "escolha uma das opcoes para iniciarmos: "<< endl;
    cout << "1. Controle de estoque "<< endl;
    cout << "2. Clientes "<< endl;
    cout << "3. Venda "<< endl;
    cout << "4. Sair "<< endl;
    cout << "Escolha uma opcao: "<< endl;
}

// funcao menu clientes
void menuClientes(){
    cout << "Menu: " << endl;
    cout << "1. Cadastrar Cliente "<< endl;
    cout << "2. Exibir Lista de Clientes "<< endl;
    cout << "3. Procurar Cliente por CPF "<< endl;
    cout << "4. Sair "<< endl;
    cout << "Escolha uma opcao: "<< endl;
}

// Função para cadastrar um cliente
void cadastrarCliente(vector<Cliente>& listaClientes){
    Cliente novoCliente;
    cout << "Nome do cliente: ";
    cin.ignore();  // Limpar o buffer de entrada
    getline(cin, novoCliente.nome);
    cout << "CPF do cliente: ";
    cin >> novoCliente.cpf;
    cout << "Telefone do cliente: ";
    cin >> novoCliente.telefone;
    cout << "Data do cadastro do cliente: ";
    cin >> novoCliente.dataCadastro;

    listaClientes.push_back(novoCliente);
    cout << "Cliente cadastrado com sucesso!\n";
}
void ordenarEstoque(Produto* estoque) {
    sort(estoque, estoque + 100, compararProdutos);
    cout << "Estoque ordenado por codigo.\n";
    exibirEstoque(estoque);  // Mostra o estoque ordenado
}

bool compararProdutos(const Produto& produto1, const Produto& produto2) {
    return static_cast<int>(produto1.codigo) < static_cast<int>(produto2.codigo);
}

// Função para exibir a lista de clientes
void exibirListaClientes(const vector<Cliente>& listaClientes){
    if (listaClientes.empty()) {
        cout << "Nenhum cliente cadastrado.\n";
    } 
    else {
        cout << "Lista de clientes:\n";
        for (const auto& cliente : listaClientes) {
            cout << "Nome: " << cliente.nome << "\tCPF: " << cliente.cpf
                << "\tTelefone: " << cliente.telefone << "\tData de Cadastro: " << cliente.dataCadastro << "\n";
        }
    }
}

// Função para procurar cliente pelo CPF
void procurarClientePorCPF(const vector<Cliente>& listaClientes) {
    system ("cls");
    string cpfProcurado;
    cout << "Digite o CPF do cliente que deseja procurar: ";
    cin >> cpfProcurado;

    for (const auto& cliente : listaClientes) {
        if (cliente.cpf == cpfProcurado) {
            cout << "Cliente encontrado:\n";
            cout << "Nome: " << cliente.nome << "\tCPF: " << cliente.cpf
                << "\tTelefone: " << cliente.telefone << "\tData de Cadastro: " << cliente.dataCadastro << "\n";
            return;
        }
    }

    cout << "Cliente com CPF " << cpfProcurado << " nao encontrado.\n";

}

void mostrarmenuPrincipalEstoque() {
    cout << "\n======= Menu Principal =======\n";
    cout << "1. Adicionar Produto\n";
    cout << "2. Exibir Estoque\n";
    cout << "3. Buscar Produto\n";
    cout << "4. Verificar Estoque\n";
    cout << "5. Ordenar Estoque\n";
    cout << "6. Sair\n";
}

void mostrarMenuProdutosEstoque() {
    system ("cls");
    cout << "\n======= Menu Produtos =======\n";
    cout << "1. Camiseta Masculina\n";
    cout << "2. Camiseta Feminina\n";
    cout << "3. Top\n";
    cout << "4. Leggin\n";
    cout << "5. Shorts Feminino\n";
    cout << "6. Shorts Masculino\n";
}

void mostrarMenuTamanhosEstoque() {
    system ("cls");
    cout << "\n======= Menu Tamanhos =======\n";
    cout << "1. P\n";
    cout << "2. M\n";
    cout << "3. G\n";
    cout << "4. GG\n";
}

void mostrarMenuCoresEstoque() {
    system ("cls");
    cout << "\n======= Menu Cores =======\n";
    cout << "1. Rosa\n";
    cout << "2. Azul\n";
    cout << "3. Preto\n";
    cout << "4. Verde Musgo\n";
    cout << "5. Roxo\n";
    cout << "6. Cinza\n";
}

void adicionarProdutoEstoque(Produto* estoque, CodigoProduto codigoProduto) {
    int quantidade;

    int indice = 0;
    while (estoque[indice].codigo != codigoProduto) {
        ++indice;

        if (indice == 100) {
            cout << "\nErro: Nao ha espaco suficiente no estoque para adicionar o produto.\n";
            return;
        }
    }

    adicionarTamanhoCorEstoque(estoque[indice]);

    cout << "Digite a quantidade a ser adicionada: ";
    cin >> quantidade;

    estoque[indice].quantidades.push_back(quantidade);

    cout << "\nProduto adicionado/atualizado com sucesso!\n";
    exibirEstoque(estoque);  // Exibe o estoque atualizado
}


void adicionarTamanhoCorEstoque(Produto& produto) {
    int escolhaTamanho, escolhaCor;

    do {
        mostrarMenuTamanhosEstoque();
        cout << "Escolha um tamanho (0 para sair): ";
        if (!(cin >> escolhaTamanho) || !validarEscolha(escolhaTamanho, 1, 4)) {
           
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        mostrarMenuCoresEstoque();
        cout << "Escolha uma cor: ";
        if (!(cin >> escolhaCor) || !validarEscolha(escolhaCor, 1, 6)) {
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        produto.tamanhos.push_back(static_cast<Tamanho>(escolhaTamanho));
        produto.cores.push_back(static_cast<Cor>(escolhaCor));

        cout << "Digite a quantidade a ser adicionada (0 para encerrar): ";
        if (!(cin >> escolhaTamanho) || escolhaTamanho < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (escolhaTamanho != 0) {
            produto.quantidades.push_back(escolhaTamanho);
        }

    } while (escolhaTamanho != 0);
}

bool validarEscolha(int escolha, int min, int max) {
    return escolha >= min && escolha <= max;
}

void buscatProdutoEstoque(Produto* estoque, CodigoProduto codigoProduto) {
    buscarProdutoRecursivo(estoque, codigoProduto);
}
void buscarProdutoRecursivo(Produto* estoque, CodigoProduto codigoProduto, int indice ){
    if (indice >= 100) {
        cout << "Produto não encontrado no estoque.\n";
        return;
    }

    if (estoque[indice].codigo == codigoProduto) {
        cout << "Produto encontrado:\n";
        exibirTamanhosCoresEstoque(estoque[indice]);
        return;
    }

    buscarProdutoRecursivo(estoque, codigoProduto, indice + 1);
}


void exibirTamanhosCoresEstoque(const Produto& produto) {
    cout << right << setw(5) << "Tamanho"<<setw(10) <<"Cor" << setw(15) << "Quantidade" << "\n";

    for (size_t i = 0; i < produto.tamanhos.size(); ++i) {
        cout << static_cast<int>(produto.tamanhos[i])<<setw(15) << static_cast<int>(produto.cores[i]) << setw(15)
             << produto.quantidades[i] << "\n";
    }
}

void verificarEstoque(Produto* estoque) {
    system ("cls");
    int totalProdutos = 0;
    int produtosEmFalta = 0;

    cout << "\n======= Estoque =======\n";
    cout << left << setw(10) << "Codigo" << setw(15) << "Tamanho"<< setw(15)<<"Cor" << setw(15) << "Quantidade" << "\n";

    for (int i = 0; i < 100; ++i) {
        for (size_t j = 0; j < estoque[i].tamanhos.size(); ++j) {
            cout << setw(10) << estoque[i].codigo << setw(15) << static_cast<int>(estoque[i].tamanhos[j])<<setw(15)
                 << static_cast<int>(estoque[i].cores[j]) << setw(15) << estoque[i].quantidades[j] << "\n";

            totalProdutos += estoque[i].quantidades[j];
            cout<<" "
            <<"\n"<<endl;

            if (estoque[i].quantidades[j] < 5) {
                ++produtosEmFalta;
                cout << "Alerta: O produto " << i + 1 << " (" << estoque[i].quantidades[j] << " unidades) esta quase no fim!\n";
            }
        }
    }

    cout << "\nTotal de produtos no estoque: " << totalProdutos << "\n";
    cout << "Produtos em falta: " << produtosEmFalta << "\n";
}

void exibirEstoque(Produto* estoque) {
    system ("cls");
    cout << "\n======= Estoque =======\n";
    cout << left << setw(10) << "Codigo" << setw(15) << "Tamanho"<<setw(15)<<"Cor" << setw(15) << "Quantidade" << "\n";

    for (int i = 0; i < 100; ++i) {
        for (size_t j = 0; j < estoque[i].tamanhos.size(); ++j) {
            cout << setw(10) << estoque[i].codigo << setw(15) << static_cast<int>(estoque[i].tamanhos[j]) <<setw(15)
                 << static_cast<int>(estoque[i].cores[j]) << setw(15) << estoque[i].quantidades[j] << "\n";
        }
    }
}

void menuPrincipalEstoque(Produto* estoque) {

    int escolha;
    do {
        
        mostrarmenuPrincipalEstoque();
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        if (escolha == 1) {
            mostrarMenuProdutosEstoque();
            cout << "Escolha um produto: ";
            cin >> escolha;

            if (escolha >= 1 && escolha <= 6) {
                adicionarProdutoEstoque(estoque, static_cast<CodigoProduto>(escolha));
            } else {
                cout << "Opcao invalida.\n";
            }
        } else if (escolha == 2) {
            exibirEstoque(estoque);
        } else if (escolha == 3) {
            mostrarMenuProdutosEstoque();
            cout << "Escolha um produto: ";
            cin >> escolha;

            if (escolha >= 1 && escolha <= 6) {
                buscatProdutoEstoque(estoque, static_cast<CodigoProduto>(escolha));
            } else {
                cout << "Opcao invalida.\n";
            }
        } else if (escolha == 4) {
            verificarEstoque(estoque);
        } else if (escolha == 5) {
            ordenarEstoque(estoque);
        } else {
            cout << "Opcao invalida. Tente novamente.\n";
        }
    }while (escolha != 6);
}

void venderProduto(Produto* estoque, vector<Cliente>& listaClientes){
    string cpf;
    double totalValue = 0.0;
    vector<Venda> vendas;

    cout << "Digite o CPF do cliente: ";
    cin >> cpf;

    auto clienteIter = find_if(listaClientes.begin(), listaClientes.end(), [&cpf](const Cliente& c) {
        return c.cpf == cpf;
    });

    if (clienteIter == listaClientes.end()) {
        cadastrarCliente(listaClientes);
    }

    int codigoProduto;
    do {
        system("cls");

        mostrarMenuProdutosEstoque();
        cout << "Escolha o codigo do produto: (0 para sair)";
        cin >> codigoProduto;

        if (codigoProduto >= 1 && codigoProduto <= 6) {
            system("cls");

            mostrarMenuTamanhosEstoque();
            cout << "Escolha o tamanho do produto: ";
            int tamanho;
            cin >> tamanho;

            mostrarMenuCoresEstoque();
            cout << "Escolha a cor do produto: ";
            int cor;
            cin >> cor;

            assert(tamanho >= 1 && tamanho <= 4);  // Verifica se o tamanho está dentro da faixa válida
            assert(cor >= 1 && cor <= 6);          // Verifica se a cor está dentro da faixa válida

            for (int i = 0; i < 100; ++i) {
                for (size_t j = 0; j < estoque[i].tamanhos.size(); ++j) {
                    if (estoque[i].codigo == codigoProduto &&
                        estoque[i].tamanhos[j] == static_cast<Tamanho>(tamanho) &&
                        estoque[i].cores[j] == static_cast<Cor>(cor)) {

                        if (estoque[i].quantidades[j] < 1) {
                            cout << "Nao ha este produto em estoque.\n";
                            break;
                        }

                        vendas.push_back({codigoProduto, static_cast<Tamanho>(tamanho), static_cast<Cor>(cor), 1, estoque[i].preco});
                        estoque[i].quantidades[j]--;

                        // Instrução assert para depuração/teste
                        assert(estoque[i].quantidades[j] >= 0);  // Verifica se a quantidade é não negativa

                        cout << "\nProduto vendido com sucesso!\n";
                        break;
                    }
                }
            }

            system("pause");
        }
    } while (codigoProduto != 0);

    for (const auto& v : vendas) {
        totalValue += v.quantidade * v.preco;
    }

    cout << "Total da venda: R$" << totalValue << "\n";

    int pagamento;
    cout << "Escolha a forma de pagamento:\n";
    cout << "1. Cartao\n";
    cout << "2. Dinheiro\n";
    cin >> pagamento;
    
    if (pagamento ==1){
        cout << "Compra feita com sucesso!" <<endl;
    }
    else if (pagamento == 2){
        double pago;
        cout << "Digite o valor pago: R$";
        cin >> pago;
         if (pago < totalValue) {
            cout << "Valor insuficiente.\n";
        } 
        else {
            double troco = pago - totalValue;
            cout << "Troco: R$" << troco << "\n";
            cout << "Notas sugeridas:\n";
            vector<int> notas = {100, 50, 20, 10, 5, 1};
            for (int nota : notas) {
                if (nota <= troco) {
                    int numNotas = troco / nota;
                    troco -= numNotas * nota;
                    cout << numNotas << " nota(s) de R$" << nota << "\n";
                }
            }
        }
    }
}
