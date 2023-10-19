#include <iostream>
#include <cmath>
using namespace std;

int soma (int a);
bool anoBi (int ano);
void binario ();
bool validarSenha (const string senha);
double jurosCompostos (float valor, float taxa, int anos );
void ordenar ();

int main (){
    int a, ano, b, v[9], anos, array[9];
    float valor, taxa;
    string senha;
    cout <<  "digite um numero para saber a soma de todos os inteiros positivos menores ou iguais a ele." << endl;
    cin >> a;
    cout << soma (a) << endl;
    cout << "digite um ano para saber se ele eh bissexto (true), ou nao (false)" << endl;
    cin >> ano;
    if (anoBi (ano)){
        cout << "o eh bissexto" << endl;
    }
    else{
        cout << "o ano nao eh bissexto" << endl;
    }
    cout << "digite um numero menor que 1024 pra saber a sua representacao em binario" << endl;
    binario();
    cout << endl;
    do{
        cout << "Digite a senha: ";
        cin >> senha;

        if (validarSenha(senha)) {
            cout << "A senha eh valida." << endl;
        } else {
            cout << "A senha nao eh valida." << endl;
        }
    }while((validarSenha(senha)==false));
    cout << endl << "digite o valor inicial" << endl;
    cin >> valor;
    cout << endl << "digite a taxa de juros anual" << endl;
    cin >> taxa;
    cout << endl << "digite o numero de anos" << endl;
    cin >> anos;
    cout << endl << jurosCompostos (valor,taxa,anos )<< endl;
    cout << endl << "insira 10 valores" << endl;
    ordenar();


}

int soma (int a){
    int soma=0;
    for (int i=0; i<=a; i++){
    soma+=i;
    }
    return soma;
}

bool anoBi (int ano){
    if ((ano % 4 == 0)&& (ano % 100 == 0) && (ano % 400 == 0)){
        return true;
    }
    else if ((ano % 4 == 0) && (ano % 100 != 0)){
        return true;
    }
    else{
        return false;
    }
}

void binario (){
    int v[9],b,i=0;
    cin >> b;
    while (b != 0){
        v[i]= b%2;
        b/=2;
        i++;
    }
    while (i--){
        cout << v[i];
    }
}

bool validarSenha(const string senha) {
    if (senha.length() < 8) {
        return false;     
    }
    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temNumero = false;

    for (int i = 0; i < senha.length(); i++) {
        if (senha[i] >= 'A' && senha[i] <= 'Z') {
            temMaiuscula = true;
        } else if (senha[i] >= 'a' && senha[i] <= 'z') {
            temMinuscula = true;
        } else if (senha[i] >= '0' && senha[i] <= '9') {
            temNumero = true;
        }
    }
    return temMaiuscula && temMinuscula && temNumero;
}

double jurosCompostos (float valor, float taxa, int anos ){
    float total;
    int meses;
    meses = anos * 12;
    taxa = taxa/12;
    taxa = taxa/100;
    total = valor* pow (1 + taxa, meses);
    return total;

}

void ordenar (){
    int aux, array [10], i, j;
    for (i=0; i<=9; i++){
        cin >> array[i];
    }
    for (i=0 ; i<10; i++){
        for(j=i; j<10; j++){
            if (array[i] > array[j]){
                aux = array[i];
                array[i]=array[j];
                array[j]=aux;
            }
        }
    }
    for(i=0; i<10; i++){
        cout << array[i] << " ";
    }
}
