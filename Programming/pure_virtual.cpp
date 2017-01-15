//순수 가상함수
//추상클래스의 객체는 생성하지는 못하나 포인터 타입으로써 자식클래스를 가리키는 업케스팅이 가능함
//이때 업케스팅시 자원해제를 위해 추상클래스의 가상소멸자 필요.동적할당시
//그리고 정적할당이면 범위를 벗어나면 자동적으로 소멸자가 호출됨 자식부터 호출.(순수가상함수시)

#include <iostream>

using namespace std;

static int count=0;
class A
{
    public:
        A(){};
        virtual ~A(){cout<<"업케스팅시 부모의 가상소멸자 필수 자식의 소멸자 먼저 호출하기 위해"<<endl;};
        virtual void must()=0;
};

class B : public A
{
    int count=0;
    public:
        B(){};
        ~B(){cout<<"자식 소멸자 호출"<<count++<<endl;};
        void must()
        {
            cout<<"순수가상함수 구현완료(자식)"<<endl;
        }
};
int main()
{
    B b;
    b.must();

    A* p=new B();
    p->must();
    return 0;
}
