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

class EmptyCase : public Transportation{
    public :
        Transportation* transfer() const override{
            return new EmptyCase();
        }
    public :
        void go() const override{
            cout << "선책하신 교통수단은 지원하지않습니다." << "\n";
        }

};

class TransportationTerminal{
    
    public:
      Transportation* transfortation(string tr){
        if(tr=="BUS") return (new Bus())->transfer();
        else if(tr=="CAR")return (new Car())->transfer();
        else return (new EmptyCase())->transfer();
      };
};

int main(){
    TransportationTerminal* terminal = new TransportationTerminal();
    Transportation* tr1 =  terminal->transfortation("BUS");
    tr1->go();
    Transportation* tr2 = terminal->transfortation("CAR");
    tr2->go();
}