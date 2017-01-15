/* Overriding Upcasting.....*/
//Upcasting-> 부모 타입의 참조변수가 자식 객체를 가리키는것.
//정리
//업케스팅 사용시 virutal 함수 사용없이 사용한다면 정적바인딩이 됨. 즉 부모클래스와 자식클래스에 똑같은 함수가 정의가 되어있는데
//업케스팅 된 타입은 부모클래스의 타입이므로 부모클래스의 함수가 호출됨.
//그러나 virtual 함수를 부모클래스 함수에 선언시 동적바인딩이 되서 자식클래스의 함수가 호출됨.자식클래스의 함수에는 virtual 붙혀도 되고 안붙혀도 됨
//이미 부모 클래스의 함수가 가상함수가 되었기 떄문에 자동적으로 가상함수가 됨.
//이때 업케스팅시 주의할점은 부모 클래스의 타입이기떄문에 부모클래스의 소멸자만 호출되기 때문에 virtual를 선언해서 자식 클래스의 소멸자를 호출시켜줘야 한다.

#include <iostream>

using namespace std;

class A
{
    public:
        A(){};
        void func();
};

class B :public A
{
    public:
        B(){};

        void func();
};

class C
{
    public:
        C(){};
        virtual ~C(){};
        virtual void foo();
};

class D :public C
{
    public:
        D(){};
        void foo();
};
int main()
{
    A a;
    a.func(); //그대로 a의 함수 호출

    B b;
    b.func(); //그대로 b의 함수 호출

    A* p=new B(); //업케스팅 부모의 자식으로부터 재정의 되어질 함수는 virtual이 아님.
    p->func();

    C c;
    c.foo(); //그대로 c의 함수 호출

    D d;    
    d.foo(); //그대로 d의 함수 호출

    C* q=new D(); //업케스팅,virtual이 있을경우
    q->foo();

    delete p;
    delete q;

    return 0;
}

void A::func()
{
    cout<<"A class"<<endl;
}

void B::func()
{
    cout<<"B class"<<endl;
}
void C::foo()
{
    cout<<"C class"<<endl;
}
void D::foo()
{
    cout<<"D class"<<endl;
}
