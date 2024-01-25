//pg 5

// 1) 
// solução interativa: 
//      1- f= 5
//      2- f= 5 * 4 = 20
//      3- f= 20* 3 = 60
//      4- f= 60 * 2 = 120
//      5- f= 120* 1 = 120
// 
//  solução recursiva:
//      1- fat(5) = 120
//      2- 5 * fat (4)
//          5*24
//      3- fat (4)= 24
//      4- 4 * fat(3)
//          4*6
//      5- fat(3)=6
//      6- 3 * fat(2)
//          3 * 2 
//      7- fat (2)=2
//      8- 2 * fat(1)
//      9- fat (1)
//      10- 1

// solução interativa: 
//      1- f= 3
//      2- f= 3 * 2 = 6
//      3- f= 6 * 1 = 6
// 
//  solução recursiva:
//      1- fat(3) = 6
//      2- 3 * fat (2)
//          3*2
//      3- fat (2)= 2
//      4- 2 * fat(1)
//          1*1
//      5- fat (1)
//      6- 1

// solução interativa: 
//      1- f= 0 
//      2- 1
// 
//  solução recursiva:
//      1- fat(0)
//      2- 1


// 2) 13

// Pg 6

// 1)
//  1- x= max(v,4)
//      14
//  2- x = max (v,3)
//      14
//  3- x = max (v,2)
//      12
//  4- x = max (v,1)
//      7
//  5-7
// pg 8) 12 vezes
// 2)

#include <iostream>
using namespace std;

int somaVetor (int *v, int n);
int somaInt (int a);// exercicio A
int pot(int a, int b);// Exercicio B
int mult(int m, int n);// exercicio 4


int main (){
    int a[4] = {1,2,3,4};
    cout << somaVetor(a,4)<< endl;
    cout << somaInt(5)<< endl;
    cout << pot (4,2)<< endl;
    cout << mult (5,4)<< endl;
}

int somaVetor (int *v, int n){
    if (n==1){
        return v[0];
    }
    else{
        int s =somaVetor(v, n-1);
        if (s >= v[0]){
            return s+v[n-1];
        }
        else{
           return v[n-1];
        }
    }
}
int somaInt(int a){
    if(a==1){
        return a;
    }
    else{
        return a+somaInt(a-1);
    }
}

int pot (int a, int b){
    if (b == 0){
        return 1;
    }
    else{
        if (b == 1){
            return a;
        }
        else{
            return a* pot(a, b-1);
        }
    }
}

// c) é linear, ele soma os números alocados no vetor que são maiores que 10
//d) ele soma os valores de resto da divisão por 10 que resulta na soma dos próprios algarismos dos números, resposta 14
//e) o ídice 3
int mult(int m, int n){
    if(n==1){
        return m;
    }
    else{
        return m+ mult(m,n-1);
    }
}
//1) ele calcula a soma dos numeros decrementando 1. Ex: 5+4+3+2+1
// for(int i=n, i>0,i--){
//   soma+=i;
//}
