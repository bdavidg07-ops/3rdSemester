#include <iostream>

using namespace std;

struct Date{
    int day, month, year;
};

void CompareExistence();

class Product{
private:
    int code, existence, nomv, *dinh, n;
    float cost;
    string name;
    Date entryDate;
    class Supplier{
    private:
        string sname;
        int id;
        double callId;
    public:
        void setSupplierName(string);
        void setID(int);
        void setCallID(double);

        string getSupplierName();
        int getID();
        double getCallID();
    };
    Supplier supplier;
    static int nopr;
public:
    Product();
    Product(int,int,int,int*,int,float,string,int,int,int,Supplier);
    Product(const Product&);
    ~Product();

    void setCode(int);
    void setExistence(int);
    void setNumberofMovements(int);
    void setDynamicHistory(int*,int);
    void setCost(float);
    void setName(string);
    void setEntryDate(int,int,int);
    void setSupplier(string,int,double);

    int getCode();
    int getExistence();
    int getNumberofMovements();
    int getDynamicHistory();
    float getCost();
    string getName();
    Date getEntryDate();
    Supplier getSupplier();

    void IncreaseExistence(int);
    void sell();
    void show();
    void showMovements();

    friend void CompareExistence();

};

Product::Product(){
    n=100;
    dinh=new int[n];
    for(int i=0 ; i<n ; i++){
        dinh[i]=0;
    }
    code=0;
    existence=0;
    nomv=0;
    cost=0;
    name="";
    entryDate.day=01;
    entryDate.month=01;
    entryDate.year=2000;
    supplier.getCallID();
    supplier.getID();
    supplier.getSupplierName();
    nopr++;
}

Product::Product(int code,int ex,int nomv,int* dnh,int n,float cost ,string name,int dd, int mm, int yy,Supplier s){
    this->n=n;
    dinh=new int[n];
    for(int i=0 ; i<n ; i++){
        dinh[i]=0;
    }
    this->code=code;
    existence=ex;
    this->nomv=nomv;
    this->cost=cost;
    this->name=name;
    entryDate.day=dd;
    entryDate.month=mm;
    entryDate.year=yy;
}