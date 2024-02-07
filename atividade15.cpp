#include <iostream>
#include <vector>
using namespace std;

int buscaSequencial(const vector<int>& v, int x);
int buscaBinariaModificada(const vector<int>& v, int x);
int buscaSequencialRecursiva(const vector<int>& v, int x, int index = 0);
void duasSomas(const vector<int>& v, int target, int& indice1, int& indice2);
int buscaBinariaModificada1(const vector<int>& v, int x);

int main() {
    vector<int> vetor = {1, 2, 3, 5, 7, 9, 12, 14, 15};
    int x = 8;
    
    cout << "Busca Sequencial: " << buscaSequencial(vetor, x) << endl;
    cout << "Busca Binária Modificada: " << buscaBinariaModificada(vetor, x) << endl;
    cout << "Busca Sequencial Recursiva: " << buscaSequencialRecursiva(vetor, x) << endl;

    int indice1, indice2;
    duasSomas(vetor, x, indice1, indice2);

    if (indice1 != -1) {
        cout << "Índices para a soma " << x << ": " << indice1 << " e " << indice2 << endl;
    } else {
        cout << "Não foram encontrados índices para a soma " << x << endl;
    }

    int indice = buscaBinariaModificada1(vetor, x);

    if (indice != -1) {
        cout << "Menor índice onde v[j] >= " << x << ": " << indice << endl;
    } else {
        cout << "Não foi encontrado índice para " << x << endl;
    }

    return 0;
}

// Função para Busca Sequencial
int buscaSequencial(const vector<int>& v, int x) {
    for (int j = 0; j < v.size(); ++j) {
        if (v[j] < x && (j == v.size() - 1 || v[j + 1] >= x)) {
            return j;
        }
    }
    return -1;  
}

// Função para Busca Binária modificada
int buscaBinariaModificada(const vector<int>& v, int x) {
    int left = 0, right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (v[mid] >= x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

// Função para Busca Sequencial Recursiva
int buscaSequencialRecursiva(const vector<int>& v, int x, int index = 0) {
    if (index == v.size() || v[index] >= x) {
        return index;
    }

    return buscaSequencialRecursiva(v, x, index + 1);
}

void duasSomas(const vector<int>& v, int target, int& indice1, int& indice2) {
    int left = 0, right = v.size() - 1;

    while (left < right) {
        int currentSum = v[left] + v[right];

        if (currentSum == target) {
            indice1 = left;
            indice2 = right;
            return;
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }

    indice1 = -1;
    indice2 = -1;
}

int buscaBinariaModificada1(const vector<int>& v, int x) {
    int left = 0, right = v.size() - 1;
    int resultado = -1;  // Inicializa com um valor que indica que não foi encontrado

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (v[mid] >= x) {
            resultado = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return resultado;
}
