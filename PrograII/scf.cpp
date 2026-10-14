#include <iostream>

using namespace std;

void mostrarDato(int dato){
    cout<<"Mostrando dato entero: "<<dato;
}

void mostrarDato(double dato){
    cout<<endl<<"Mostrando dato double: "<<dato;
}

void mostrarDato(char dato){
    cout<<endl<<"Mostrando dato char: "<<dato;
}

float calcularArea(int l){
    return l*l;
}

float calcularArea(float b, float h){
    return b*h;
}

float calcularArea(float bM, float bm, float h){
    return (bM+bm)*h/2;
}

float promedio(int n, int n1){

}

float promedio(int n1, int n2, int n3){
    
}

float promedio(int vec[], int n){
    
}

int main(){
    int dato1=2, l;
    double dato2= 800.0;
    char dato3='l';
    float bm, bM, h, b, a;

    mostrarDato(dato1);
    mostrarDato(dato2);
    mostrarDato(dato3);

    cout<<endl<<"La sobrecarga se logra debido a que los datos son diferentes en tipo."<<endl<<
    "Depende el tipo de dato que obtenga el compilador elige la opcion correcta";

    cout<<endl<<"Ahora Calcularemos Areas: ";
    cout<<endl<<"Lado del cuadrado: ";
    cin>>l;

    cout<<endl<<"Base del rectangulo: ";
    cin>>b;
    cout<<endl<<"Altura del rectangulo";
    cin>>h;

    cout<<endl<<"Base mayor del trapecio: ";
    cin>>bM;
    cout<<endl<<"Base menor del trapecio: ";
    cin>>bm;
    cout<<endl<<"Altura del trapecio: ";
    cin>>a;

    cout<<endl<<"El area del cuadrado es: "<<calcularArea(l);
    cout<<endl<<"El area del rectangulo es: "<<calcularArea(b,h);
    cout<<endl<<"El area del trapecio es: "<<calcularArea(bM,bm,a);

    cout<<endl<<"La sobrecarga se logra de dos formas: "<<endl<<
    "1. Debido a que en el cuadrado es un tipo de dato y en las demas otro"<<endl<<
    "2. Debido a que son distinto numero de datos por funcion."<<endl<<
    "El compilador elige la opcion que corresponde al numero de argumentos.";


}