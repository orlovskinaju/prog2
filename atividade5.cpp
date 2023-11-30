#include <iostream>
using namespace std;
const int tamanhoVetor = 5;

int multiplicacao(int a, int b);
int multipliReferencia(int (*a), int (*b));
int somaDez (int n);
int somaDezRef (int (*n));
int sub(int m);
int subRef (int (*m));
void inverterVetor(int* vetor, int tamanho);
void converterParaMaiusculas(string &palavra);


int main(){
    int x=5, y=6,z=4, mult, multref, soma, somaRef, subtracao, subtracaoRef;
    mult= multiplicacao(x,y);
    cout << mult << endl;
    multref= multipliReferencia(&x, &y);
    cout << multref << endl;
    soma = somaDez(x);
    cout << soma << endl;
    somaRef = somaDezRef(&x);
    cout << somaRef << endl;
    subtracao= sub (z);
    cout << subtracao << endl;
    subtracaoRef = subRef(&z);
    cout << subtracaoRef << endl;
    int vetor[tamanhoVetor] = {1, 2, 3, 4, 5};

        inverterVetor(vetor, tamanhoVetor);

        for (int i = 0; i < tamanhoVetor; i++) {
            cout << vetor[i] << " ";
         }
    cout << endl;
    string word;
    cout << "Digite uma string: "<<endl;
    cin >> word;
    converterParaMaiusculas(word);
    cout << word << endl;





}

int multiplicacao(int a, int b){
    int res;
    res = a*b;
    return res;
}

int multipliReferencia(int (*a), int (*b)){
    int res;
    res = (*a)*(*b);
    return res;
}

int somaDez(int n){
    int soma;
    soma = 10 + n;
    return soma;
}

int somaDezRef(int (*n)){
    int soma;
    soma = 10 +(*n);
    return soma;
}

int sub (int m){
    int resultado;
    resultado = m - 5;
    return resultado;
}

int subRef (int (*m)){
    int resultado;
    resultado = (*m) - 5;
    return resultado;
}

void inverterVetor(int* vetor, int tamanho) {
    int* inicio = vetor;
    int* fim = vetor + tamanho - 1;
    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

void converterParaMaiusculas(string &palavra) {
    for (char &c : palavra) {
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }
    }
}
