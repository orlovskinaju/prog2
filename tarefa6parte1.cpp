#include <iostream>
using namespace std;


void ordenar(int& a, int& b){ // Exercicio 1 da letra A
    int aux;
    if (a > b){
        aux = a;
        a = b;
        b = aux;
    }
}

void decomporDouble(double x, int* int_part, double* frac_part) {// Exercício 2 da letra A
    *int_part = static_cast<int>(x);
    *frac_part = x - static_cast<double>(*int_part);
}


int main(){
    double numero, parte_fracionaria;
    int parte_inteira, num1, num2;
    cout << "digite um numero: " << endl;
    cin >> numero;
    decomporDouble(numero, &parte_inteira, &parte_fracionaria);
    cout << "Parte inteira: " << parte_inteira << endl;
    cout << "Parte fracionaria: " << parte_fracionaria << endl;
    cout << "Digite 2 numeros inteiros "<< endl;
    cin >> num1 >> num2;
    ordenar (num1 ,num2);
    cout << "Os valores em ordem: " << num1 << " " << num2;

}

//bool has_zero(int a[], int n) {
//    int i;
//    for (i = 0; i < n; i++){
//      if (a[i] == 0){             Exercício B: o erro é que ele não percorria todo o vetor para retornar false
//            return true;
//       }
//    }
//    return false;
//}
