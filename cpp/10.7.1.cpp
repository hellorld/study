#include <iostream>

using namespace std;

class A
{
    string m_buf;
public:
    A(const char* p)
    {
        m_buf = p;
        cout << "A(const char* p)" << endl;
    }
    A(const A& a)
    {
        m_buf = a.m_buf;
        cout << "A(const A& a)" << endl;
    }
    void print()
    {
        cout << m_buf << endl;
    }
};

void f(A& a)
{

}
int main()
{
    A a("123");
    //A test(A("123"));

    f(a);

    return 0;
}
