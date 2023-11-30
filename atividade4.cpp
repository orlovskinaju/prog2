#include <iostream>
using namespace std;

void trocaValores();
void vetor();
int dobrarValor(int valor);
void vogal();
void IverterString(char* vetor);


int main(){
    int valor;
    trocaValores();
    vetor();

    cout<<"valor"<<endl;
    cin>>valor;
    cout<<dobrarValor(valor)<<endl;

    vogal();
    char string[] = "professorgiovane";

    inverterString(string);

    cout<<string << endl;
}

void trocaValores(){
    int a=2,b=3;
    int *p=&a;
    int *q=&b;
    int temp = *p;
    *p = *q;
    *q = temp;
    cout<<a<<endl;
    cout<<b<<endl;

}

void vetor(){
    int v[3];
    int *p=v;
    v[0]=0, v[1]=1, v[2]=2;
    
    for(int i=0; i<3; i++){
        *p=v[i];
        cout<<*p<<endl;
    }

}

int dobrarValor(int valor){
    int *p=&valor;
    (*p)*=2;

    return *p;
}

void vogal(){
    string palavra;
    int cont=0;
    int *p=&cont;
    cout<<"digite uma palavra"<<endl;
    cin >> palavra;
    for (char c : palavra){
        if (tolower(c)=='a'|| tolower(c)=='e'|| tolower(c)=='i'|| tolower(c)=='o'|| tolower(c)=='u'){
            cont+=1;
        }
    }
    cout<<*p<<endl;
}

void inverterString(char* vetor) {
    int tamanho = 0;
    while (vetor[tamanho] != 0) {
        tamanho++;
    }

    char* inicio = vetor;
    char* fim = vetor + tamanho - 1;

    while (inicio < fim) {
        
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}
