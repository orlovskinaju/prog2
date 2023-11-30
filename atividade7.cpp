#include <iostream>
using namespace std;

typedef struct{
    string nome;
    int idade;
    float nota;

}Aluno;

typedef struct{
    Aluno estudante;
    string gradua;
}Curso;

int main(){
    Aluno estudante;
    cout << "Digite o nome do aluno (ref 1): " << endl;
    cin >> estudante.nome;
    cout << "Digite a idade do aluno: "<< endl;
    cin >> estudante.idade;
    cout << "Digite a nota dele: "<< endl;
    cin >> estudante.nota;
    cout << "Aluno: " << estudante.nome << endl << "Idade: " << estudante.idade << endl << "Nota: " << estudante.nota;


    Aluno estudantes[2];
    cout <<endl << "Digite o nome do primeiro aluno: " << endl;
    cin >> estudantes[0].nome;
    cout << "Digite a idade do primeiro aluno: "<< endl;
    cin >> estudantes[0].idade;
    cout << "Digite a nota do primeiro aluno: "<< endl;
    cin >> estudantes[0].nota;
    cout << "Digite o nome do segundo aluno: " << endl;
    cin >> estudantes[1].nome;
    cout << "Digite a idade do segundo aluno: "<< endl;
    cin >> estudantes[1].idade;
    cout << "Digite a nota do segundo aluno: "<< endl;
    cin >> estudantes[1].nota;
    cout << "Digite o nome do terceiro aluno: " << endl;
    cin >> estudantes[2].nome;
    cout << "Digite a idade do terceiro aluno: "<< endl;
    cin >> estudantes[2].idade;
    cout << "Digite a nota do terceiro aluno: "<< endl;
    cin >> estudantes[2].nota;
    cout << "Aluno: " << estudantes[0].nome  << "  Idade: " << estudantes[0].idade << "  Nota: " << estudantes[0].nota<< endl;
    cout << "Aluno: " << estudantes[1].nome << "  Idade: " << estudantes[1].idade << "  Nota: " << estudantes[1].nota<< endl;
    cout << "Aluno: " << estudantes[2].nome << "  Idade: " << estudantes[2].idade << "  Nota: " << estudantes[2].nota<< endl;


    Aluno *pont;
    pont = &estudante;
    cout << "Digite outro nome do aluno (ref 1)" << endl;
    cin >> pont->nome;
    cout << pont << endl;


    Curso novoAluno;
    cout << "digite o curso do aluno: " << endl;
    cin >> novoAluno.gradua ;
    cout << "Digite o nome do aluno: " << endl;
    cin >> novoAluno.estudante.nome;
    cout << "Digite a idade do aluno: "<< endl;
    cin >> novoAluno.estudante.idade ;
    cout << "Digite a nota dele: "<< endl;
    cin >> novoAluno.estudante.nota ;
    cout << "Graduação: "<< novoAluno.gradua;
    cout <<  "  Nome: " << novoAluno.estudante.nome << "  Idade: " << novoAluno.estudante.idade << "  Nota: " << novoAluno.estudante.nota;


}
