/*템플릿*/
//일반화 프로그래밍하기 위한 템플릿.
//예외적인 상황 같은 경우 템플릿 오버로딩과 특수화를 사용한다.

#include <iostream>

using namespace std;

template <typename T>

void A(T a, T b, int c)
{
    cout <<"인자 1->"<<a<<" 인자2->"<<b<<" 인자3->"<<c<<endl;
}
template <typename T>
void A(T a,T b)
{
    cout <<"인자 1->"<<a<<" 인자2->"<<b <<endl;
}
/* 특수화
template[<>] 반환타입 함수명[<[타입]>](타입 인자,타입 인자,....);
추천
template<> 반환타입 함수명<타입>(타입 인자,타입 인자,....)
특수화는 특정 하나 타입에 다른 방법으로 쓰일때
오버로딩은 특정타입에 대한것이 아님
*/
//오버로딩 할떄 반환타입이 void 이면 void로 특수화 해야하는듯.
//T일경우 특정타입으로 가능한듯
template<> void A<char>(char a ,char b)
{
    cout<<"문자 인자1->"<<a<<" 문자 인자2->"<<b<<endl;
}
    
int main()
{
    cout<<"템플릿 함수"<<endl;
    A(1,5);
    cout<<"암시적 변환"<<endl;
    A<double>(1.5,5);//이렇게 타입이 여러개로 인식할 경우 명시적으로 구체화 해줘야됨.(일반적 구체화 안됨)
    cout<<"템플릿 함수 오버로딩 가능"<<endl;
    A(1,5,3);
    cout<<"char에 대한 특수화"<<endl;
    A('a','b');
    return 0;
}
