#include<iostream>
using namespace std;

class Position {
protected:
    float x, y, z;
public:
    Position(float a=0, float b=0, float c=0) {
        x = a;
        y = b;
        z = c;
    }
    void setPosition(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
    void displayPosition() {
        cout << "Position: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};
class Health {
protected:
    int health;
public:
    Health(int h=100) {
        health = h;
    }
    void setHealth(int h) {
        health = h;
    }
    void displayHealth() {
        cout << "Health: " << health << endl;
    }
};
class Character : public Position, public Health {
    string name;
public:
    Character(string n, float a, float b, float c, int h) : Position(a,b,c), Health(h) {
        name = n;
    }
    void display() {
        cout << "Character: " << name << endl;
        displayPosition();
        displayHealth();
    }
};
int main() {
    Character hero("Warrior", 10.5, 20.0, 5.2, 85);
    hero.display();
    return 0;
}
