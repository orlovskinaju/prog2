#include <iostream>
using namespace std;

void multiplo(){
    int num;
    cout << "digite um numero para saber se ele e multiplo de 4" << endl;
    cin >> num;
    if (num % 4 == 0){
        cout << "e multiplo" << endl;
    }
    else {
        cout << "nao e multiplo" << endl;
    }
}

void parOuImpar (){
    int n;
    cout << "digite um numero para saber se ele e par ou impar" << endl;
    cin >> n;
    if (n % 2 == 0){
        cout << "o numero e par" << endl;
    }
    else{
        cout << "o numero e impar" << endl;
    }
}

void somaDosN(){
    int a, b, soma=0;
    cout << "digite 2 numeros para saber a soma dos n entre eles incluindo eles mesmos" << endl;
    cin >> a >> b;
    for (int i=a ; i<=b ; i++){
        soma+=i;
    }
    cout << "a soma e " << soma << endl;
}
void volume (){
    float vol, raio;
    cout << "digite o valor do raio" << endl;
    cin >> raio;
    vol = (4*3.14*raio*raio*raio)/3;
    cout << "o volume e " << vol << endl;
}
void fatorial (){
    int valor, fat=1;
    cout << "digite um numero para saber o seu fatorial" << endl;
    cin >> valor;
    while (valor < 0){
        cout << "valor invalido" << endl;
        cin >> valor;
    }
    for (int i=1; i<=valor; i++){
        fat*= i;
    }
    cout << "o fatorial de " << valor << " e igual a " << fat << endl;
}

void potencia(){
    int base, expoente, p=1;
    cout << "insira a base e o expoente (ambos inteiros e maiores ou iguais a 0)" << endl;
    cin >> base >> expoente;
    for (int i=0; i<expoente; i++){
        p *= base;
    }
    cout <<"o numero " << base << " elevado a " << expoente << " e igual a "<< p << endl;
}

int main (){
    multiplo();
    cout << endl;
    parOuImpar();
    cout << endl;
    somaDosN();
    cout << endl;
    volume ();
    cout << endl;
    fatorial ();
    cout << endl;
    potencia ();

}
