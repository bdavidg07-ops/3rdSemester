/*
Situación
Se desea desarrollar un simulador sencillo para administrar pacientes de un área de urgencias.
Cada paciente tendrá:

-número de registro;
-nombre;
-edad;
-nivel de urgencia;
-turno de llegada.

Los niveles serán:
5 Crítico
4 Muy urgente
3 Urgente
2 Poco urgente
1 No urgente

8.2. Reglas de prioridad
El sistema deberá seleccionar primero al paciente con:
1. mayor nivel de urgencia;
2. si dos pacientes tienen la misma urgencia, deberá atenderse primero al que llegó antes.

Por ejemplo:
Paciente Urgencia Llegada
Ana     3       1
Luis    5       2
Pedro   3       3
María   5       4

El orden esperado sería:
Luis -> Maria -> Ana -> Pedro

Menu:

====================================
SISTEMA DE URGENCIAS
====================================
1. Registrar paciente
2. Consultar siguiente paciente
3. Atender siguiente paciente
4. Mostrar pacientes pendientes
5. Mostrar cantidad de pacientes
6. Salir
Seleccione una opcion:

*/
#include <iostream>
#include<vector>
#include<queue>

using namespace std;

struct Paciente
{
    int registro;
    string nombre;
    int edad;
    int urgencia;
    int llegada;
};



struct CompararUrgencia
{
    bool operator()(const Paciente& a,
                    const Paciente& b) const{
        return a.urgencia < b.urgencia; 
    }

};

struct CompararLlegada
{
    bool operator()(const Paciente& a,
                    const Paciente& b) const{
        return a.llegada < b.llegada; 
    }

};


int main(){
    priority_queue<
        Paciente,
        vector<Paciente>,
        CompararUrgencia
    > pacientes;
    priority_queue<
        Paciente,
        vector<Paciente>,
        CompararUrgencia
    > pacientesc;

    int o,edad,urgencia,llegada,registro, mayor=0;
    string nombre;
    Paciente actual1;

    do{
        cout<<endl<<"0. Salir"<<
        "\n1. Registrar paciente"<<
        "\n2. Consultar siguiente paciente"<<
        "\n3. Atender siguiente paciente"<<
        "\n4. Mostrar pacientes pendientes"<<
        "\n5. Mostrar cantidad de pacientes"<<
        "\n6. Salir"<<
        "\nSeleccione una opcion: ";
        cin>>o;
        switch(o){
                case 0: 
                    cout<<endl<<"Hasta luego...";
                    break;
                case 1:
                    cout<<endl<<"Dame nombre del paciente: ";
                    cin>>nombre;
                    cout<<endl<<"Dame registro: ";
                    cin>>registro;
                    cout<<endl<<"Dame edad: ";
                    cin>>edad;
                    cout<<endl<<"Dame urgencia: ";
                    cin>>urgencia;
                    cout<<endl<<"Dame orden de llegada: ";
                    cin>>llegada;
                    pacientes.push({registro,nombre,edad,urgencia,llegada});
                    break;
                case 2: 
                        actual1 = pacientes.top();

                    cout << "Registro: " << actual1.registro
                    << "\nNombre: " << actual1.nombre
                    << "\nEdad: " << actual1.edad
                    << "\nUrgencia: " << actual1.urgencia
                    << "\nLlegada: " << actual1.llegada
                    << endl;
                    break;
                case 3: 
                    actual1 = pacientes.top();

                    cout << "Registro: " << actual1.registro
                    << "\nNombre: " << actual1.nombre
                    << "\nEdad: " << actual1.edad
                    << "\nUrgencia: " << actual1.urgencia
                    << "\nLlegada: " << actual1.llegada
                    << endl;
                    pacientes.pop();
                    break;
                case 4:
                    pacientesc=pacientes;
                    while (!pacientesc.empty())
                    {
                        Paciente actual;
                        actual=pacientesc.top();
                        cout << "Registro: " << actual.registro
                        << "\nNombre: " << actual.nombre
                        << "\nEdad: " << actual.edad
                        << "\nUrgencia: " << actual.urgencia
                        << "\nLlegada: " << actual.llegada
                        << endl;
                        pacientesc.pop();
                    }
                    break;
                case 5: 
                    pacientesc=pacientes;
                    while(!pacientesc.empty()){
                        mayor++;
                        pacientesc.pop();
                    }
                    cout<<endl<<"El numero de pacientes pendientes es: "<<mayor;
                    break;

        }
    }while(o!=0); 
    return 0;
}