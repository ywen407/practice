//lamda expression
//캡처 인수목록 mutable->리턴타입{함수내용}(인수값전달);
//람다는 함수 객체이다.함수 객체란 operator()를 갖음
//람다식 끝에 인수값 전달 부분을 붙혀주면 실행이됨;.
//closure 객체의 특징을 가지고 있음(상태값을 갖고 있음 람다에서 캡처떄문에)
//무명 함수 객체.,,?

#include <iostream>

using namespace std;

int main()
{

    std::function<int(void)> func=[]()->int{return 3;};
    std::function<void(void)> func1=[]()->void{cout<<"none"<<endl;};
    auto lamda =[]()->void{cout<<"lamda"<<endl;};
    [](){cout<<"그냥 람다"<<endl;}();
    cout<<func()<<endl;
    cout<<"()안한 람다->"<<lamda<<endl;
    lamda();
    //operator void(*)()()const
    //operaotr ()()const
    auto lam2=[](int x)->int{return 3+x;};
    lam2(2);
    //operator int(*)(int)()const
    //operator ()(int x)const
    return 0;
}
