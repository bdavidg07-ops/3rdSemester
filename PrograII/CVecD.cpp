#include <iostream>

using namespace std;

class Vector{
private:
    int* vec, n;

public:
    Vector(int=1);
    Vector(const Vector&);
    ~Vector();

    int getN() const;
    void setN(int);

    void captura();
    void mostrar() const;

    Vector operator+(const Vector&) const;
    Vector operator*(int) const;
    friend Vector operator*(int, const Vector &);
    int operator*(const Vector &) const;
    Vector &operator=(const Vector &);
};

Vector::Vector(int tam){
    n=tam;
    vec=new int[tam];
    for(int i=0; i<tam ; i++){
        vec[i]=0;
    }
}

Vector::Vector(const Vector& v){
    n=v.n;
    vec=new int[n];
    for(int i=0; i<n ; i++){
        vec[i]=v.vec[i];
    }
}

Vector::~Vector(){
    delete []vec;
}

int Vector::getN() const{
    return n;
}

void Vector::setN(int n){
    this->n=n;
}

void Vector::captura(){
    for(int i=0 ; i<n ; i++){
        cout<<"Dame elemento en la posicion "<<i+1<<": ";
        cin>>vec[i];
        cout<<endl;
    }
}

void Vector::mostrar() const{
    for(int i=0 ; i<n ; i++){
        cout<<"["<<vec[i]<<"] ";
    }
    cout<<endl;
}

Vector Vector::operator+(const Vector &vect) const{
    if(n==vect.n){
        Vector obj(n);
        
        for(int i=0 ; i<n ; i++){
            obj.vec[i]=vec[i]+vect.vec[i];
        }
        return obj;
    }else{
        cout<<endl<<"El tamaño de vectores es diferente"<<endl;
        return 0;
    }
}

Vector Vector::operator*(int x) const{
    Vector obj(n);
    for(int i=0 ; i<n ; i++){
        obj.vec[i]=vec[i]*x;
    }
    return obj;
}

int Vector::operator*(const Vector &vect) const{
    if(n==vect.n){
        int x;
        for(int i=0 ; i<n ; i++){
            x=vec[i]*vect.vec[i];
        }
        return x;
    }
    cout<<endl<<"Error en los parametros, los vectores no son iguales";
    return 0;
}

Vector& Vector::operator=(const Vector &obj){
    Vector tmp;
    if( this != &obj){
        this->n=obj.n;
        delete [] vec;
        vec=new int [this->n];
        for(int i=0 ; i<obj.n ; i++)
        vec[i]=obj.vec[i];
    }
    return *this;
}

Vector operator*(int x, const Vector &obj){
    Vector tmp(obj.n);
    for(int i=0 ; i<obj.n ; i++)
        tmp.vec[i]=obj.vec[i]*x;
    return tmp;
}

int main(){
    Vector v, x(3), y(3),r,r1;
    int n=3,e;
    cout<<endl<<"Capturando 1er vector: ";
    v.captura();
    cout<<endl<<"Capturando 2do vector: ";
    x.captura();
    cout<<endl<<"Capturando 3er vector: ";
    y.captura();
    cout<<endl<<"Mostrando 1er vector: ";
    v.mostrar();
    cout<<endl<<"Mostrando 2do vector: ";
    x.mostrar();
    cout<<endl<<"Mostrando 3er vector: ";
    y.mostrar();
    cout<<endl<<"Multiplicando Vector por escalar...";
    r=x.operator*(n);
    cout<<endl<<"El resultado de la multiplicacion es: ";
    r.mostrar();
    cout<<endl<<"Multiplicando escalar por vector...";
    cout<<endl<<"Dame escalar: ";
    cin>>e;
    r1=operator*(n,y);
    cout<<endl<<"El resultado de la multiplicacion es: ";
    r1.mostrar();
    cout<<endl<<"Multiplicando 2 vectores..."
    <<endl<<"El resultado de la multiplicacion es: "<<x.operator*(y);
    Vector z(v);
    cout<<endl<<"Mostrando 4to vector que es copia del 1 ";
    z.mostrar();
    x.operator=(z);
    cout<<endl<<"Mostrando vector de copia en 2do vector con operador = del 4to operador";
    x.mostrar();
    cout<<endl<<"Mostrando n de 2do vector: ";
    cout<<endl<<x.getN();
    x.setN(n);
    cout<<endl<<"Mostrando 2do vector con n cambiada con set";
    x.mostrar();
    cout<<endl<<"Mostrando 3er vector: ";
    y.mostrar();
    cout<<endl<<"Mostrando 1er vector: ";
    v.mostrar();
    cout<<endl<<"Mostrando 2do vector: ";
    x.mostrar();
    cout<<endl<<"Mostrando 4to vector ";
    z.mostrar();
    cout<<endl<<"Multiplicando 2 vectores incompatibles..."
    <<endl<<"El resultado de la multiplicacion es: "<<y.operator*(v);
}

/*El operador de suma devuelve un vector debido a que estamos haciendo la operacion
entre 2 de estos y tienen datos dentro de ellos que deberian devolver una estructura similar

Devuelve un entero debido a que le pasamos un acumulador que hace su trabajo con cada operacion en 
estas estructuras

Que es la variable del objeto que se esta utilizando para hacer la funcion

Un vector por escalar lo podemos hacer dentro de la funcion ya que conoce los datos y lo mandamos
llamar desde dentro de la clase, por el contrario no podriamos sobrecargar la funcion con los mismos 
parametros en tipo y numero, por eso lo sacamos para la sobrecarga

La funcion miembro puede ver los parametros de la funcion y de la clase, la friend solo de la que
se tiene de amiga de las 2

El vector no sabria hasta donde parar

El operador de asignacion requiere de saber los parametros y los miembros de la clase y hacer 
los procesos de eliminacion y creacion, el de copia asigna directamente desde el inicio
*/ 