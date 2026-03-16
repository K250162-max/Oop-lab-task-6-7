#include<iostream>
using namespace std;

class Device{
protected:
    string brand;
    string model;
public:
    Device(string b,string m){
        brand=b;
        model=m;
    }
    void displayDevice(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
    }
};
class Smartphone: virtual public Device{
protected:
    int simSlots;
public:
    Smartphone(string b,string m,int s):Device(b,m){
        simSlots=s;
    }
    void displaySmartphone(){
        cout<<"SIM Slots: "<<simSlots<<endl;
    }
};
class Tablet: virtual public Device{
protected:
    bool stylusSupport;
public:
    Tablet(string b,string m,bool st):Device(b,m){
        stylusSupport=st;
    }
    void displayTablet(){
        cout<<"Stylus Support: "<<stylusSupport<<endl;
    }
};
class HybridDevice: public Smartphone, public Tablet{
public:
    HybridDevice(string b,string m,int s,bool st)
    :Device(b,m),Smartphone(b,m,s),Tablet(b,m,st){}
    void display(){
        displayDevice();
        displaySmartphone();
        displayTablet();
    }
};
int main(){
    HybridDevice h("TechBrand","X100",2,true);
    h.display();
}
