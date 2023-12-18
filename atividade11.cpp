#include <iostream>
#include <vector>

using namespace std;

int buscaSequencial(const vector<int>& A, int v);

int main() {
    vector<int> A = { /* Seus valores aqui */ };
    int v;  // O número a ser procurado
    cout << "Digite o número a ser procurado: ";
    cin >> v;

    int resultado = buscaSequencial(A, v);

    if (resultado == -1) {
        cout << "O elemento não foi encontrado." << endl;
    } else {
        cout << "O elemento foi encontrado no índice: " << resultado << endl;
    }

    return 0;
}

int buscaSequencial(const vector<int>& A, int v) {
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == v) {
            return i;  // Elemento encontrado, retorna o índice
        }
    }
    return -1;  // Elemento não encontrado
}

//Melhor caso: O elemento v está na primeira posição do vetor A, resultando em uma complexidade de tempo constante O(1).

//Pior caso: O elemento v não está no vetor A ou está na última posição do vetor. Nesse caso, a busca terá que percorrer todo o vetor, resultando em uma complexidade de tempo linear O(n), onde n é o tamanho do vetor A.

//Portanto, a complexidade de tempo no melhor caso é O(1) e no pior caso é O(n) para a busca sequencial.
