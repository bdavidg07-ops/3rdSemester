#include <iostream>

using namespace std;

class Product{
private:
    string name;
    float cost;
public:
    Product(string ,float );
    void updateCost(float);
    void updateCost(float,float);
    void mostrar();
};

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
    return (bM+bm)*h/2.0;
}

float promedio(int n, int n1){
    return (n+n1)/2.0;
}

float promedio(int n1, int n2, int n3){
    return (n1+n2+n3)/3.0;
}

float promedio(float vec[], int n){
    float a;
    for (int i=0 ; i<n ; i++){
        a=a+vec[i];
    }
    return a/n;
}

Product::Product(string name="", float c=0.0){
    this->name=name;
    cost=c;
}

void Product::updateCost(float c){
    cost=c;
}

void Product::updateCost(float c, float d){
    cost=c-c*(d/100);
}

void Product::mostrar(){
    cout<<endl<<"Product name: "<<name<<endl
    <<"Cost: "<<cost;
}

int main(){
    int dato1=2, l, n, d[3];
    double dato2= 800.0;
    char dato3='l';
    float bm, bM, h, b, a, vec[100], cost, discount;
    Product p("name"), p1("",29.99);

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

    cout<<endl<<"=== Calculo de Promedios ==="<<endl
    <<"Promedio entre 2 numeros enteros ";
    for (int i=0; i<2 ; i++){
        cout<<endl<<"Dame dato "<<i+1<<": ";
        cin>>d[i];
    } 
    cout<<endl<<"El promedio es: "<<promedio(d[0],d[1]);

    cout<<endl<<"Promedio entre 3 numeros decimales";
    for (int i=0; i<3 ; i++){
        cout<<endl<<"Dame dato "<<i+1<<": ";
        cin>>d[i];
    }
    cout<<endl<<"El promedio es: "<<promedio(d[0],d[1],d[2]);

    cout<<endl<<"Promedio entre los elementos de un vector";
    cout<<endl<<"Dame el numero de elementos del vector (Maximo 100): ";
    cin>>n;
    for (int i=0; i<n ; i++){
        cout<<endl<<"Dame dato "<<i+1<<": ";
        cin>>vec[i];
    }
    cout<<endl<<"El promedio es: "<<promedio(vec[100],n);
    cout<<endl<<"Producto 1: ";
    p.mostrar();
    cout<<endl<<"Producto 2: ";
    p1.mostrar();
    cout<<endl<<"Dame nuevo costo del producto 1: ";
    cin>>cost;
    p.updateCost(cost);
    cout<<endl<<"Dame nuevo costo del producto 2: ";
    cin>>cost;
    cout<<endl<<"Dame descuento del producto 2: ";
    cin>>discount;
    p1.updateCost(cost,discount);
    cout<<endl<<"Producto 1: ";
    p.mostrar();
    cout<<endl<<"Producto 2: ";
    p1.mostrar();


}