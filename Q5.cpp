#include <iostream>
#include <string>
using namespace std;

class Vehicle{
protected:
    string make;
    string model;
    int year;
public:
    Vehicle(string mk, string md, int yr) : make(mk), model(md), year(yr) {}
    void displayVehicle(){
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};
class Car : public Vehicle{
protected:
    int doors;
    double fuelEfficiency;
public:
    Car(string mk, string md, int yr, int d, double fe)
        : Vehicle(mk, md, yr), doors(d), fuelEfficiency(fe) {}
    void displayCar(){
        displayVehicle();
        cout << "Doors: " << doors << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << " km/l" << endl;
    }
};
class ElectricCar : public Car{
private:
    int batteryLife;
public:
    ElectricCar(string mk, string md, int yr, int d, double fe, int bl)
        : Car(mk, md, yr, d, fe), batteryLife(bl) {}
    void displayElectricCar(){
        displayCar();
        cout << "Battery Life: " << batteryLife << " km" << endl;
    }
};
int main(){
    ElectricCar e("Tesla", "Model 3", 2023, 4, 0, 450);
    e.displayElectricCar();
    return 0;
}
