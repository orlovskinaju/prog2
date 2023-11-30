#include <iostream>
using namespace std;


int bigValor ( int vetor[], int tamanho){ //  Exercício C número 1
    int maior= vetor[0];
    for (int i=1; i<tamanho; i++){
        if (vetor[i]> maior){
            maior = vetor [i];
        }
    }
    return maior;
}

double calcularMedia(int vetor[], int tamanho) { // Exercício C número 2
    double soma = 0, media;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    media = soma/tamanho;

    return media;
}

int contarPositivos( int vetor[], int tamanho) { // Exercicío C número 3
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > 0) {
            contador++;
        }
    }
    return contador;
}

void lerVetor (int n){ // Exercício C número 4
    int array[n];
    cout << " digite os elementos do vetor" << endl;
    for (int i=0; i<n ;i++){
        cin >> array[i];
    }
    cout << "o vetor inserido foi: ";
    for (int i=0; i<n ;i++){
        cout << array[i] << " ";
    }
}

void encontrarMaiorEMenor(const int vetor[], int tamanho, int &maior, int &menor) { // Exercício C número 5
    maior = vetor[0];
    menor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }  
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
}

int main(){
    int taman, maiorValor, menorValor;
    int array[taman];
    cout << "digite o tamanho do vetor de inteiros "<< endl;
    cin >> taman;
    cout << " digite os elementos do vetor" << endl;
    for (int i=0; i<taman ;i++){
        cin >> array[i];
    }
    cout << "o maior valor eh " << bigValor(array, taman) << endl;
    cout << "a media dos valores do vetor eh " << calcularMedia(array, taman) << endl;
    cout << "a quantidade de positivos eh " << contarPositivos(array, taman) << endl;
    encontrarMaiorEMenor(array, taman, maiorValor, menorValor);
    cout << "Maior valor: " << maiorValor << endl;
    cout << "Menor valor: " << menorValor << endl;
    cout << "digite o tamanho do vetor de inteiros "<< endl;
    cin >> taman;
    lerVetor(taman);


}

//6. imprime *ss, que na função, é inicializado como 0 e soma i se x é divisível por i, até que i fique igual a c.
//7. a linha 19 decide se o número tem a característica ou não, tal que existe caso o quadrado da soma do resto da divisão deste por 100
//e o resultado dessa divisão seja igual ao numero;
//8. mostra quantos divisores o número tem.
