#include<iostream>
using namespace std;
int main(){
    
    float* fP;
    float numero1 = 7.3;
    fP = &numero1;

    cout << "Valor apontado por fP: " << *fP <<endl;

    float numero2 = *fP;

    cout << "Valor de numero2: " << numero2 <<endl;
    cout << "Endereco de numero1: " << &numero1 <<endl;
    cout << "Endereco armazenado em fP: " << fP <<endl;

    return 0;
}
    
//exercicios ponteiro
//A
//1) na linha 4:5 e na linha 5:6422296
//2) na linha 4:61ff1 e na linha 5:61ff18 e na linha 6:61ff17
//3) na linha 6:55 na  linha 7:0061FF14 e na  linha 8:55


//B
//1)e
//2)b
//3)c:retorna o endereço de uma variável


//C=5
