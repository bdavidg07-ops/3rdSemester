#include <iostream>

using namespace std;

struct date{
    int day, month, year;
};
class Producto{
private:
    int code, existence, nomv, *dinh, n;
    float cost;
    string name;
    date entryDate;
    class Supplier{
    private:
        string sname;
        int id;
        double callId;
    };
    Supplier supplier;
    static int nopr;
public:
    Producto();
    Producto(int,int,int,int*,int,int,string,date,Supplier);
    void setCode(int);
};