#include <iostream>
using namespace std;

string multiplo(int num){
    if (num % 4 == 0){
        return " e multiplo de 4";
    }
    else {
        return "nao e multiplo de 4";
    }
}

string parOuImpar (int n){
    if (n % 2 == 0){
        return "o numero e par";
    }
    else{
        return "o numero e impar";
    }
}

int somaDosN(int a, int b){
    int soma=0;
    for (int i=a ; i<=b ; i++){
        soma+=i;
    }
    return soma;
}
float volume (float raio){
    return (4*3.14*raio*raio*raio)/3;
    
}
int fatorial (int valor){
    int fat=1; 
    for (int i=1; i<=valor; i++){
        fat*= i;
    }
    return fat;
}

int potencia(int base, int expoente){
    int p=1;
    for (int i=0; i<expoente; i++){
        p *= base;
    }
   return p;
}

int main(){
    int num, n, a, b, valor, base, expoente;
    float raio;
    cout << "digite um numero para verificar se ele e multiplo de 4" << endl;
    cin >> num;
    cout << multiplo (num) << endl;
    cout << "digite um numero para saber se ele e par ou impar" << endl;
    cin >> n;
    cout << parOuImpar (n) << endl;
    cout << "digite 2 numeros para saber a soma dos n entre eles incluindo eles mesmos" << endl;
    cin >> a >> b;
    cout << "a soma e " << somaDosN (a,b) << endl;
    cout << "digite o valor do raio" << endl;
    cin >> raio;
    cout << "o volume eh " << volume (raio) << endl;
    cout << "digite um numero para saber o seu fatorial" << endl;
    cin >> valor;
    while (valor < 0){
        cout << "valor invalido" << endl;
        cin >> valor;
    }
    cout << "o fatorial eh " << fatorial(valor) << endl; 
    cout << "insira a base e o expoente (ambos inteiros e maiores ou iguais a 0)" << endl;
    cin >> base >> expoente;
    cout <<"o numero " << base << " elevado a " << expoente << " e igual a "<< potencia (base, expoente) << endl;
}




//exercicio C
//1. Funções = usada para modularizar o código e evitar repetições

//2. Argumentos/Parâmetros = informações que a gnt passa pra função pra que ela funcione, quando tem return

//3. Tipos de funções = as funções podem ser com parâmetros (com return) ou sem parâmetro (void)

//4. void = função sem parâmetro

//5. Tipos de passagem de parâmetro (qual o padrão do C/C++?)
//Por valor: uma cópia do valor é fornecida para a função, que não altera o conteúdo
//da variável de origem do valor. É a forma padrão (exceto para estruturas de
//armazenamento, como vetores e outras).
// Por referência: é fornecido o endereço da variável e a função chamada altera o
//conteúdo da variável de origem do valor

//6. Retorno de uma função (quais os tipos de retorno?):os retornos são do mesmo tipo da função, podendo ser int, float, double, char, string.
