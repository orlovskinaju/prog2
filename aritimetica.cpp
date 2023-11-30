//A) Ao se utilizar um vetor como parâmetro para uma função, qual informação está
//sendo passada à função? Assinale a opção correta e explique.
//(a). Uma cópia de todos elementos do vetor
//Justificativa: Pois você está passando o vetor como um todo, sem especificar qual índice


// B) O valor de y será 4

//C)
//(F) Após a atribuição pa = &a[0], pa e a possuem valores idênticos, isto é, apontam para o mesmo endereço.
//(V) A atribuição pa = &a[0]; pode ser escrita como pa = a;.
//(V) Após a atribuição pa = &a[0], pa e a possuem valores idênticos, isto é, apontam

// D) Não existe conteúdo do ponteiro sem antes alocar nele um endereço de memória

//E) 9

//F) pc1= 1000, pc2=1001, pc3 = 1005, pc4= 1000

//G)
#include <iostream>
using namespace std;

void minMax(int* vetor, int tamanho, int* enderecoMin, int* enderecoMax);
int* juncao(const int* vetor1, int tamanho1, const int* vetor2, int tamanho2);
void separar(const int* vetor, int tamanho, int* pares, int& tamanhoPares, int* impares, int& tamanhoImpares);

int main() {
    // Função 1 
    int vetor1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int minimo, maximo;
    minMax(vetor1, sizeof(vetor1) / sizeof(vetor1[0]), &minimo, &maximo);
    cout << "Minimo: " << minimo << endl;
    cout << "Maximo: " << maximo << endl;

    // Função 2 
    int vetor2[] = {1, 2, 3};
    int tamanho1 = sizeof(vetor1) / sizeof(vetor1[0]);
    int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);
    int* resultado = juncao(vetor1, tamanho1, vetor2, tamanho2);
    cout << "Vetor resultante da juncao: ";
    for (int i = 0; i < tamanho1 + tamanho2; ++i) {
        cout << *(resultado + i) << " ";
    }
    cout << endl;
    delete[] resultado;

    // Função 3 
     int vetor3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho3 = sizeof(vetor3) / sizeof(vetor3[0]);
    int pares[tamanho3];
    int tamanhoPares = 0;
    int impares[tamanho3];
    int tamanhoImpares = 0;
    separar(vetor3, tamanho3, pares, tamanhoPares, impares, tamanhoImpares);
    cout << "Pares: ";
    for (int i = 0; i < tamanhoPares; ++i) {
        cout << pares[i] << " ";
    }
    cout << endl;
    cout << "Impares: ";
    for (int i = 0; i < tamanhoImpares; ++i) {
        cout << impares[i] << " ";
    }
    cout << endl;

    return 0;
}

// Função 1 - Mínimo e Máximo
void minMax(int* vetor, int tamanho, int* enderecoMin, int* enderecoMax) {
    if (tamanho <= 0) {
        cout << "O vetor esta vazio." << endl;
        return;
    }
    *enderecoMin = *vetor;
    *enderecoMax = *vetor;
    for (int i = 1; i < tamanho; ++i) {
        if (*(vetor + i) < *enderecoMin) {
            *enderecoMin = *(vetor + i);
        } else if (*(vetor + i) > *enderecoMax) {
            *enderecoMax = *(vetor + i);
        }
    }
}

// Função 2 - Junção de Vetores
int* juncao(const int* vetor1, int tamanho1, const int* vetor2, int tamanho2) {
    int* resultado = new int[tamanho1 + tamanho2];

    for (int i = 0; i < tamanho1; ++i) {
        *(resultado + i) = *(vetor1 + i);
    }

    for (int i = 0; i < tamanho2; ++i) {
        *(resultado + tamanho1 + i) = *(vetor2 + i);
    }

    return resultado;
}

// Função 3 - Separação de Vetor em Pares e Ímpares
void separar(const int* vetor, int tamanho, int* pares, int& tamanhoPares, int* impares, int& tamanhoImpares) {
    tamanhoPares = 0;
    tamanhoImpares = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (*(vetor + i) % 2 == 0) {
            *(pares + tamanhoPares) = *(vetor + i);
            ++tamanhoPares;
        } else {
            *(impares + tamanhoImpares) = *(vetor + i);
            ++tamanhoImpares;
        }
    }
}
