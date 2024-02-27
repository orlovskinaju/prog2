#include <iostream> 
#include <cmath>
using namespace std;
const double PI = 3.14159;

//  EXERCICIO 1 
// antes da técnica
void operacoes (){
    int a=5, b=10;
    cout << "soma: " << a+b << endl;
    cout << "multiplicacao: " << a*b << endl;
}
// depois da técnica
int soma1(){
    int a=5, b=10;
    return a+b;
}

int mult1(){
    int a=5, b=10;
    return a*b;
}
// EXERCICIO 2
void ex2 (){
    double principal, taxa, tempo; 
    principal = 1000.0;
    taxa = 0.05;
    tempo = 2.0;
    
    double montante = principal * pow(1 + taxa, tempo);
    
    cout << "montante : " << montante << endl;
    
}

//EXERCICIO 3
double calcularPrecoComDesconto(double preco, double desconto) {
    return preco * (1 - desconto / 100);
}

double calcularPrecoFinal(double preco, double taxa_adicional) {
    return preco * (1 + taxa_adicional / 100);
}

// EXERCICIO 4 
void area(){
 double raio;
    cout << "Digite o raio: ";
    cin >> raio;

    double area = PI * raio * raio;
    cout << "A area do círculo eh: " << area << endl;

}

//EXERCICIO 5
void checandoTemp(int temperature) {
    if (temperature > 100) {
        cout << "Muito quente!";
    } else if (temperature > 70) {
        cout << "Clima agradavel.";
    } else if (temperature > 50) {
        cout << "Fresco.";
    } else {
        cout << "Muito frio!";
    }
}


int main (){
    cout << "exercicio 1: " << endl;
    operacoes();
    cout << "soma: " << soma1() << endl << "multiplicacao: " << mult1() << endl;
    cout << endl << "exercicio 2: " << endl;
    ex2();
    // EXERCICIO 3
    cout << endl << "exercicio 3: "<< endl;
    double preco;
    double desconto;
    double taxa_adicional;

    cout << "Digite o preco: ";
    cin >> preco;

    cout << "Digite o desconto (%): ";
    cin >> desconto;

    cout << "Digite a taxa adicional (%): ";
    cin >> taxa_adicional;

    double preco_com_desconto = preco * (1 - desconto / 100);
    double preco_final = preco_com_desconto * (1 + taxa_adicional / 100);
    cout << "O preco final com desconto e taxas adicionais eh: " << preco_final << endl;


    double precoComDesconto = calcularPrecoComDesconto(preco, desconto);
    double precoFinal = calcularPrecoFinal(preco_com_desconto, taxa_adicional);

    cout << "O preco final com desconto e taxas adicionais eh: " << preco_final << endl;
    cout << endl << "exercicio 4: " << endl;
    area();

    cout << endl << "exercicio 5: " << endl;
    int temperatura;
    cout << "Digite a temperatura: ";
    cin >> temperatura;

    checandoTemp(temperatura);

}
