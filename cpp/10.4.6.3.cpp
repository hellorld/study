#include <iostream>

using namespace std;

class A
{
private:
    //const int m_a;
    int m_a;
public:
    A(int a = 10)
        :m_a(a)
    {
    }
    void print()
    {
        cout << m_a << endl;
    }
};

int main()
{
    A a1;
    a1.print();
    A a2;
    a2.print();
    a2 = a1;
    return 0;
}
