#include <iostream>
#include <thread>

using namespace std;

//01.
//이와 같은 싱글톤 구현은 멀티쓰레드 환경에서 문제가 될 수 있다.
class singletone_01{
    public :
        static singletone_01& instance_01(string a){
            string b;
            b = a;
            if(instance_ == NULL){
                instance_ = new singletone_01();
                cout << a  << " : " << b << "\n";
            }
            return *instance_;
        }

private :
 singletone_01(){};

static singletone_01* instance_;
};

//02.
//위에서의 멀티 쓰레드의 환경에서의 문제점과 전역으로 선언함으로써 문제점을 보완하고자
//지연 초기화와 정적지역변수로 선언함으로써 문제해결
class singletone_02{

    public :
        static singletone_02& instance(string &a){
            string b;
            b = a;
            static singletone_02* instance_02 = new singletone_02();
            cout << a  << " : " << b << "\n";
            //만약 관리가 까다롭다면
            //static singletone* instance_
            //return instance_ 로 구현하면 힙이 아닌 데이터 세그먼트에 올라가기때문에 관리가 더 쉬울것이다.
            return *instance_02;
        }

    private :
    singletone_02(){};
};

singletone_01* singletone_01::instance_ = nullptr;

int main(){
 
    string me = "난",you = "너";
    
    thread t1(&singletone_01::instance_01,ref(me));
    thread t2(&singletone_01::instance_01,ref(you));
    thread t3(&singletone_01::instance_01,ref(me));
    thread t4(&singletone_01::instance_01,ref(you));

    thread t5(&singletone_01::instance_01,ref(me));
    thread t6(&singletone_01::instance_01,ref(me));
    thread t7(&singletone_01::instance_01,ref(you));
    thread t9(&singletone_01::instance_01,ref(me));

}