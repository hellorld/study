#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        a = 10;
        cout << "A()" << endl;
    }
    void print()
    {
        cout << "print()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    int a;
};

class B: public A
{
public:
    B()
    {
        cout << "B()" << endl;
    }
    ~B()
    {
        cout << "~B()" << endl;
    }
};

int main()
{
    A *pa = new B;
    delete pa;

    return 0;
}
