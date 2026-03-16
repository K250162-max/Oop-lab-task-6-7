#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;
public:
    Currency(double a,string code,string symbol,double rate){
        amount=a;
        currencyCode=code;
        currencySymbol=symbol;
        exchangeRate=rate;
    }
    virtual double convertToBase(){
        return amount * exchangeRate;
    }
    double convertTo(Currency &target){
        double base = convertToBase();
        return base / target.exchangeRate;
    }
    virtual void displayCurrency(){
        cout<<currencySymbol<<amount<<" "<<currencyCode<<endl;
    }
};
class Dollar : public Currency{
public:
    Dollar(double a) : Currency(a,"USD","$",1.0){}
    double convertToBase(){
        return amount * exchangeRate;
    }
    void displayCurrency(){
        cout<<"Dollar: "<<currencySymbol<<amount<<" "<<currencyCode<<endl;
    }
};
class Euro : public Currency{
public:
    Euro(double a) : Currency(a,"EUR","€",1.1){}
    double convertToBase(){
        return amount * exchangeRate;
    }
    void displayCurrency(){
        cout<<"Euro: "<<currencySymbol<<amount<<" "<<currencyCode<<endl;
    }
};
class Rupee : public Currency{
public:
    Rupee(double a) : Currency(a,"PKR","Rs",0.0036){}
    double convertToBase(){
        return amount * exchangeRate;
    }
    void displayCurrency(){
        cout<<"Rupee: "<<currencySymbol<<amount<<" "<<currencyCode<<endl;
    }
};
int main(){
    Dollar d(100);
    Euro e(100);
    Rupee r(10000);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout<<"100 USD to EUR: "<<d.convertTo(e)<<endl;
    cout<<"100 EUR to PKR: "<<e.convertTo(r)<<endl;
    cout<<"10000 PKR to USD: "<<r.convertTo(d)<<endl;

    return 0;
}
