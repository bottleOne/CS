#include <stdio.h>
#include <stdc++.h>

using namespace std;

class Transportation{
   public:
   virtual Transportation* transfer() const = 0;
   virtual void go() const = 0;
};

class Car : public Transportation{
    public :
        Transportation* transfer() const override{
            return new Car();
        }
    public :
        void go() const override{
            cout << "차타고 가는중" << "\n";
        }
};

class Bus : public Transportation{
    public :
        Transportation* transfer() const override{
            return new Bus();
        }
    public :
        void go() const override{
            cout << "버스타고 가는중" << "\n";
        }

};

int main(){
    Transportation* bus = new Bus();
    bus->go();
    Transportation* car = new Car();
    car->go();
}