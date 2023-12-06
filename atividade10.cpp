#include <iostream>
#include <string>
using namespace std;

void inserirNumeros(int*& vetor, int n);
void apresentarVetor(const int* vetor, int n);
void liberarMemoria(int*& vetor);

struct Aluno {
    string nome;
    string serie;
    float nota;
};

void lerNotas(Aluno*& alunos, int numAlunos);
void imprimirMedia(const Aluno* alunos, int numAlunos);
void liberarMemoria(Aluno*& alunos);

int main() {
    int* vetor = nullptr; 
    int n;
    cout << "Digite a quantidade de numeros a serem inseridos: ";
    cin >> n;
    inserirNumeros(vetor, n); 
    apresentarVetor(vetor, n); 
    liberarMemoria(vetor); 

    Aluno* alunos = nullptr;
    int numAlunos;
    cout << "Digite a quantidade de alunos na turma: ";
    cin >> numAlunos;
    lerNotas(alunos, numAlunos); 
    imprimirMedia(alunos, numAlunos);
    liberarMemoria(alunos);

}
//A e B
void inserirNumeros(int*& vetor, int n) {
    vetor = new int[n]; 

    int* ptr = vetor; 

    for (int i = 0; i < n; ++i) {
        *ptr = i; 
        ++ptr;    
    }
}
void apresentarVetor(const int* vetor, int n) {
    const int* ptr = vetor; 

    for (int i = 0; i < n; ++i) {
        cout << *ptr << " "; 
        ++ptr; 
    }
    cout << endl;
}
void liberarMemoria(int*& vetor) {
    delete[] vetor; 
    vetor = nullptr; 
}
//C e D e E
void lerNotas(Aluno*& alunos, int numAlunos) {
    alunos = new Aluno[numAlunos]; 

    Aluno* ptr = alunos; 

    cout << "Digite as informacoes dos alunos:";
    for (int i = 0; i < numAlunos; ++i) {
        cout << "Nome do aluno " << i + 1 << ": ";
        cin >> ptr->nome;
        cout << "Serie do aluno " << i + 1 << ": ";
        cin >> ptr->serie;
        cout << "Nota do aluno " << i + 1 << ": ";
        cin >> ptr->nota;
        ++ptr;
    }
}
void imprimirMedia(const Aluno* alunos, int numAlunos) {
    const Aluno* ptr = alunos; 
    float soma = 0;

    for (int i = 0; i < numAlunos; ++i) {
        soma += ptr->nota; 
        ++ptr;             
    }

    if (numAlunos > 0) {
        float media = soma / numAlunos;
        cout << "A media aritmetica das notas da turma e: " << media << endl;
    } else {
        cout << "Nao ha alunos na turma." << endl;
    }
}
void liberarMemoria(Aluno*& alunos) {
    delete[] alunos; 
    alunos = nullptr; 
}
