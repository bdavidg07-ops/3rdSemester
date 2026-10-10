#include <iostream>

using namespace std;

struct Date{
    int day, month, year;
};

class Product;

void CompareExistence(Product, Product);

class InventoryAuditor{
private: 

public:
    InventoryAuditor();
    void ProductCheck(const Product&);
};

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

        string getSupplierName() const{
            return sname;
        }
        int getID() const{
            return id;
        }
        double getCallID() const{
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

    int getCode() const;
    int getExistence() const;
    int getNumberofMovements() const;
    int* getDynamicHistory() const;
    inline float getCost() const;
    inline string getName() const;
    Date getEntryDate() const;
    Supplier getSupplier() const{
        return supplier;
    }
    static int getNumberofProducts();

    int IncreaseExistence();
    int sell();
    void show() const;
    void showMovements() const;

    friend void CompareExistence(Product, Product);
    friend InventoryAuditor;

};

int Product::nopr=0;

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

InventoryAuditor::InventoryAuditor(){

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

int Product::getCode() const{
    return code;
}

float Product::getCost() const{
    return cost;
}

int Product::getExistence() const{
    return existence;
}

int Product::getNumberofMovements() const{
    return nomv;
}

string Product::getName() const{
    return name;
}

Date Product::getEntryDate() const{
    return entryDate;
}

int Product::getNumberofProducts(){
    return nopr;
}
int* Product::getDynamicHistory() const{
    return dinh;
}

int Product::IncreaseExistence(){
    int plus;
    cout<<endl<<"How many existence for increase in "<<name<<"? ";
    cin>>plus;
    existence=existence+plus;
    return existence;
}

int Product::sell(){
    int plus;
    cout<<endl<<"How many existence for sell in "<<name<<"? ";
    cin>>plus;
    existence=existence-plus;
    return existence;
}

void Product::show() const{
    cout<<endl<<"Product: "<<name<<endl<<"Product Code: "<<code<<endl
    <<"Existence: "<<existence<<endl<<"Cost: "<<cost<<endl
    <<"Entry Date: "<<entryDate.month<<"/"<<entryDate.day<<"/"<<entryDate.year
    <<endl<<"Number of Movements: "<<nomv;
}

void Product::showMovements() const{
    for(int i=0 ; i<nomv ; i++){
        cout<<endl<<"Dynamic Hystory: "<<"Movement "<<i+1<<": "<<dinh[i];
    }
}

void InventoryAuditor::ProductCheck(const Product& p){
    cout<<endl<<"====Auditor===="<<endl<< "Name of product: "<<p.name<<endl
    <<"Code of product: "<<p.code<<endl<<"Existence: "<<p.existence;
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
    cout << "=== MANDATORY TESTS ===" << endl;

    cout << endl << "1. Initial products count: " << Product::getNumberofProducts();

    Product penguins;

    penguins.setCode(1001);
    penguins.setName("Penguins");
    penguins.setExistence(50);
    penguins.setCost(18.5f);
    penguins.setEntryDate(15, 6, 2026);
    penguins.setSupplier("Bimbo", 501, 5551234.5);
    penguins.setNumberofMovements(2);
    int hist1[2] = {10, 40};
    penguins.setDynamicHistory(hist1, 2);

    int hist2[3] = {5, 15, 10};
    Product doritos(1002, 30, 3, hist2, 3, 25.0f, "Doritos", 20, 6, 2026, 5559876.1, 502, "Sabritas");

    penguins.IncreaseExistence(); 
    penguins.sell();              
    doritos.IncreaseExistence(); 

    cout << endl << "6. Showing data:";
    penguins.show();
    penguins.showMovements();
    doritos.show();
    doritos.showMovements();

    Product pCopia(penguins);
    pCopia.setName("Penguins Modified");
    pCopia.setExistence(999);
    cout << endl << "8. Original penguins: " << penguins.getExistence() << " | Copy: " << pCopia.getExistence();

    cout << endl << "9. Static counter: " << Product::getNumberofProducts();

    const Product pConst(1003, 100, 0, nullptr, 0, 10.0f, "Water", 1, 1, 2026, 5550000.0, 503, "Bonafont");
    cout << endl << "10. Const object name: " << pConst.getName();
    pConst.show();

    CompareExistence(penguins, doritos);

    InventoryAuditor auditor;
    auditor.ProductCheck(penguins);

    Product *chettos = new Product(1004, 75, 0, nullptr, 0, 45.0f, "Cheetos", 21, 6, 2026, 5551111.0, 504, "Sabritas");
    cout << endl << "14. Dynamic object chettos:";
    chettos->show();

    cout << endl << "15. Counter before delete: " << Product::getNumberofProducts();
    delete chettos;
    cout << endl << "17. Counter after delete: " << Product::getNumberofProducts();

    int cant;
    cout << endl << "18. Enter quantity for dynamic array: ";
    cin >> cant;

    Product *arrProd = new Product[cant];
    for(int i = 0; i < cant; i++){
        arrProd[i].setCode(3000 + i);
        arrProd[i].setName("Batch " + to_string(i + 1));
    }

    cout << endl << "21. Showing dynamic array catalog:";
    for(int i = 0; i < cant; i++){
        arrProd[i].show();
    }

    delete [] arrProd;
    cout << endl << "23. Final products counter: " << Product::getNumberofProducts() << endl;

    return 0;
}