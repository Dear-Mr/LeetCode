# include <iostream>

using namespace std;

class Test{
public:
    Test():m_ptr(new int(3)){
        cout<<"gouzao"<<endl;
    }
    ~Test(){
        if(m_ptr != nullptr) {
            cout << "~Test()" << endl;
            delete m_ptr;
        }
    }
    Test(const Test& obj){
        m_ptr = new int(0);
        if(obj.m_ptr != nullptr)
            *m_ptr = *obj.m_ptr;
        cout<<"fuzhigouzaohanshu"<<endl;
    }
    Test(Test&& obj):m_ptr(obj.m_ptr){
        obj.m_ptr = nullptr;
        cout<<"yidonggouzaohanshu"<<endl;
    }

private:
    int * m_ptr;
};

Test f1(){
    return Test();
}
//void f2(Test obj){}

int main(){
   /* Test a1;//gouzao
    cout<<"1"<<endl;*/
   /* f2(a1);//kaobei
    cout<<"1"<<endl;*/

    Test a2 = f1();//yidong

 /*   cout<<"1"<<endl;
   Test a3(a1);*/
    return 0;
}

