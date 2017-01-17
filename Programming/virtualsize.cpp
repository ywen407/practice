//가상함수 테이블..
//확실히 virtual 키워드가 들어가므로 인해 크기가 늘어난다. 여기선 8byte?이다.
//마찬가지로 상속되면 똑같이 포인터가 생기는듯 하다.
//vptr->vtable->func

#include <iostream>

using namespace std;

class A
{
    private:
        int a;
    public:
    virtual void foo();

};
class B :public A
{
    private:
        int b;
    public:
        void foo();
};
void B::foo()
{
    cout <<"B의 함수 foo입니다"<<endl;
}

void A::foo()
{
    cout<<"A의 가상함수 foo입니다"<<endl;
}
int main()
{
    cout <<"A클래스의 크기는: "<<sizeof(A)<<endl;
    cout <<"B클래스의 크기는: "<<sizeof(B)<<endl;
    return 0;
}
