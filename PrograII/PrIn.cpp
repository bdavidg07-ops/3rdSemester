#include <iostream>

using namespace std;

struct Date{
    int day, month, year;
};

void CompareExistence(Product, Product);

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
        void setSupplierName(string name){
            sname=name;
        }
        void setID(int id){
            this->id=id;
        }
        void setCallID(double cid){
            callId=cid;
        }

        string getSupplierName(){
            return sname;
        }
        int getID(){
            return id;
        }
        double getCallID(){
            return callId;
        }
    };
    Supplier supplier;
    static int nopr;
public:
    Product();
    Product(int,int,int,int*,int,float,string,int,int,int,double,int,string);
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
    int* getDynamicHistory();
    inline float getCost();
    inline string getName();
    Date getEntryDate();
    Supplier getSupplier(){
        return supplier;
    }
    static int getNumberofProducts();

    int IncreaseExistence();
    int sell();
    void show();
    void showMovements();

    friend void CompareExistence(Product, Product);

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

Product::Product(int code,int ex,int nomv,int* dnh,int n,float cost ,string name,int dd, int mm, int yy,double cid,int id,string nam){
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
    supplier.setCallID(cid);
    supplier.setID(id);
    supplier.setSupplierName(nam);
    nopr++;
}

Product::Product(const Product& copy){
    this->code=copy.code;
    this->cost=copy.cost;
    this->n=copy.n;
    dinh=new int[n];
    for(int i = 0; i < n; i++) {
        dinh[i] = copy.dinh[i];
    }
    this->entryDate=copy.entryDate;
    this->existence=copy.existence;
    this->name=copy.name;
    this->supplier=copy.supplier;
    this->nomv=copy.nomv;
    nopr++;
}

Product::~Product(){
    delete []dinh;
    nopr--;
}

void Product::setCode(int code){
    this->code=code;
}

void Product::setCost(float c){
    cost=c;
}

void Product::setDynamicHistory(int* vec, int n){
    vec=dinh;
    this->n=n;
    dinh=new int[n];
}

void Product::setEntryDate(int dd, int mm, int yy){
    entryDate.day=dd;
    entryDate.month=mm;
    entryDate.year=yy;
}

void Product::setExistence(int ex){
    existence=ex;
}

void Product::setName(string n){
    name=n;
}

void Product::setNumberofMovements(int numm){
    nomv=numm;
}

void Product::setSupplier(string name, int id, double cid){
    supplier.setCallID(cid);
    supplier.setID(id);
    supplier.setSupplierName(name);
}

int Product::getCode(){
    return code;
}

float Product::getCost(){
    return cost;
}

int Product::getExistence(){
    return existence;
}

int Product::getNumberofMovements(){
    return nomv;
}

string Product::getName(){
    return name;
}

Date Product::getEntryDate(){
    return entryDate;
}

int Product::getNumberofProducts(){
    return nopr;
}
int* Product::getDynamicHistory(){
    return dinh;
}

int Product::IncreaseExistence(){
    int plus;
    cout<<endl<<"How many existence for increase? ";
    cin>>plus;
    existence=existence+plus;
    return existence;
}

int Product::sell(){
    int plus;
    cout<<endl<<"How many existence for sell? ";
    cin>>plus;
    existence=existence-plus;
    return existence;
}

void Product::show(){
    cout<<endl<<"Product: "<<name<<endl<<"Product Code: "<<code<<endl
    <<"Existence: "<<existence<<endl<<"Cost: "<<cost<<endl
    <<"Entry Date: "<<entryDate.month<<"/"<<entryDate.day<<"/"<<entryDate.year
    <<endl<<"Number of Movements: "<<nomv;
}

void Product::showMovements(){
    for(int i=0 ; i<nomv ; i++){
        cout<<endl<<"Dynamic Hystory: "<<"Movement "<<i<<": "<<dinh[i];
    }
}

void CompareExistence(Product p1, Product p2){
    if(p1.getExistence()>p2.getExistence()){
        cout<<endl<<"The existence in product 1 is mayor.";
    }else if (p1.getExistence()<p2.getExistence())
    {
        cout<<endl<<"The existence in product 2 is mayor.";
    }else{
        cout<<endl<<"The existence in the two products is the same";
    }
    
}

int main(){
    Product *chettos, penguins, doritos;
}