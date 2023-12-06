#include <iostream>
using namespace std;

void pont();
void somarInt();
void subInt();
void subPont();
void comparar();
void Estatica();
void Registro();
void Array();
void CompararPont(int* ponteiro1, int* ponteiro2);



int main(){
    pont();
    cout << endl;
    somarInt();
    cout << endl;
    subInt();
    cout << endl;
    subPont();
    cout << endl;
    comparar();
       for (int i = 0; i < 5; ++i) {
        Estatica();
    }

    for (int i = 0; i < 5; ++i) {
        Registro();
    }

   // Array();

    int variavel1 = 42;
    int variavel2 = 73;
    int *ponteiro1, *ponteiro2;
    ponteiro1 = &variavel1;
    ponteiro2 = &variavel2;
    Comparar(ponteiro1, ponteiro2);

   // cout << "Novo valor da variavel global: " << global << endl;

}

void pont(){
    int num=50;
    int *ponteiro=&num;
    
    cout << "valor original: " << num << endl;
    (*ponteiro)++ ;
    cout << "o numero somado com 1 : "<< *ponteiro << endl;

    (*ponteiro)-- ;
    cout << "o numero subtraido 1: " << *ponteiro << endl;
}

void somarInt(){
    int n = 10;
    int *p = &n;
    const int constante = 2;

    cout << "valor original: " << n << endl;
    
    (*p)+=constante;

    cout << "valor somado com 2: " << *p << endl;
}

void subInt(){
    int n = 20;
    int *k = &n;
    const int constante = 2;

    cout << "valor original: " << n << endl;
    
    (*k)-= constante;

    cout << "valor subtraido com 2: " << *k << endl;
}

void subPont(){
    int a=10, b=15;
    int *p=&a, *k=&b;

    cout << "valores originais de 'a' e 'b': " << a << " " << b << endl;

    cout << " a operacao a-b = " << (*p) - (*k) << endl;

}

void comparar(){
    int a, b;
    cout << "digite dois valores inteiros: "<< endl;
    cin >> a >> b;
    int *p=&a, *k=&b;
    if ((*p)== (*k)){
        cout << "os ponteiros sao iguais" << endl;
    }
    else{
        if ((*p)>(*k)){
            cout << "o ponteiro p eh maior que o k" << endl;
        }
        else{
            cout << "o ponteiro k eh maior que o p" << endl;
        }
    }
}

void Estatica(){
    static int variavelEstatica = 0;

    variavelEstatica++;
    cout << "Valor da variavel estatica: " << variavelEstatica << endl;
}

void Registro() {
    register int variavelDeRegistro = 0;

    variavelDeRegistro++;
    cout << "Valor da variavel de registro: " << variavelDeRegistro << endl;
}
//9
//void Array() {
    //int array[5] = {10, 20, 30, 40, 50};
    //int tamanho;
    //int *ponteiro;
    //ponteiro = &array[0];

    //for (int i = 0; i < tamanho; ++i) {
       // cout << "Elemento " << i << ": " << *(ponteiro + i) << endl;
    //}
//}

void Comparar(int* ponteiro1, int* ponteiro2) {
    if (ponteiro1 > ponteiro2) {
        cout << "A variavel1 esta em um endereco de memoria mais alto." << endl;
    } else if (ponteiro2 > ponteiro1) {
        cout << "A variavel2 esta em um endereco de memoria mais alto." << endl;
    } else {
        cout << "Os enderecos de memoria sao iguais." << endl;
    }
}
