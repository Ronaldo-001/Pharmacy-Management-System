#include <iostream>
#include<string.h>
using namespace std;
class Product{
    public:
    string name;
    int quantity;
    int threshold;
    
    Product(string n,int temp,int t){
        string name= n;
        int quantity = temp;
        int threshold = t;
    }
    void restock(int q){
        int quantity = quantity + q;
    }
    bool needsRestock(){
        return (quantity < threshold);
    }
};
class Customer{
    public:
    string name;
    string address;
    string prescription;
    
    Customer(string n,string a,string p){
        name=n;
        address=a;
        prescription=p;
    }
};
class Prescription{
    public:
    string drugname;
    string dosage;
    int quantity;
    int refillrequests;
    
    Prescription(string n, string d,int q,int r){
        drugname=n;
        dosage=d;
        quantity=q;
        refillrequests=r;
    }
    void refill(int q){
        quantity+=q;
        refillrequests--;
    }
    bool needsrefill(){
        return refillrequests>0;
    }
};
class Sale{
    public:
    string productname;
    int quantity;
    float price;
    string paymentmethod;
    
    Sale(string n,int q,float p,string m){
        productname=n;
        quantity=q;
        price =p;
        paymentmethod=m;
    }
    float gettotal(){
        return quantity*price;
    }
};
int main(){
    string prodn;
    int pt;
    int ptt;
    cout<<"Enter the product name : ";
    cin>>prodn;
    cout<<"Enter the quantity of the product : ";
    cin>>pt;
    cout<<"Enter the threshold value : ";
    cin>>ptt;
    Product product(prodn,pt,ptt);
    if (product.needsRestock()){
        cout <<"product"<<product.name<<"needs restocking."<<endl;
    }
    product.restock(10);
    cout<<"\n"<<endl;
    string cname,cadd,cpres;
    cout<<"Enter the customer name : ";
    cin>>cname;
    cout<<"Enter the customer address : ";
    cin>>cadd;
    cout<<"Enter the customer prescription : ";
    cin>>cpres;
    Customer customer(cname,cadd,cpres);
    cout<<"customer name: "<<customer.name<<endl;
    cout<<"customer address: "<<customer.address<<endl;
    cout<<"customer prescription: "<<customer.prescription<<endl;
    cout<<"\n"<<endl;
    string dname,dosage;
    int quan,rr;
    cout<<"Enter the drug name : ";
    cin>>dname;
    cout<<"Enter the dosage needed (mg): ";
    cin>>dosage;
    cout<<"Enter the quantity of the drug (number) : ";
    cin>>quan;
    cout<<"Enter the refillrequest (number): ";
    cin>>rr;
    Prescription prescription(dname,dosage,quan,rr);
    if (prescription.needsrefill()){
        cout<< "Prescription for" << prescription.drugname<< " needs a refill." <<endl;
    }
    prescription.refill(30);
    cout<<"\n"<<endl;
    string pname,paymethod;
    int salequna;
    float saleprice;
    cout<<"Enter the sale product name : ";
    cin>>pname;
    cout<<"Enter the quantity (number) : ";
    cin>>salequna;
    cout<<"Enter the sale price (float) : ";
    cin>>saleprice;
    cout<<"Enter the payment method (Credit Card , UPI etc) : ";
    cin>>paymethod;
    Sale sale(pname,salequna,saleprice,paymethod);
    cout<< "Product Name: " << sale.productname << endl;
    cout<< "Quantity: " << sale.quantity << endl;
    cout<< "Price: " << sale.price << endl;
    cout<< "Payment Method: " << sale.paymentmethod <<endl;
    return 0;
}
