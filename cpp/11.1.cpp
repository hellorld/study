#include <iostream>

using namespace std;

struct X
{
    int i;
    X(int a)
    {
        i = a;
        cout << "X(int a) called" << endl;
    }
    X operator+(int a)
    {
        i += a;
        return X(i);
    }
};

struct Y
{
    int i;

    Y(X x)
    {
        i = x.i;
        cout << "Y(X x) called" << endl;
    }
    Y operator+(X x)
    {
        i += x.i;
        return Y(X(i));
    }
    friend ostream& operator<<(ostream& out, const Y& y)
    {
        out << y.i << endl;
        return out;
    }

    operator int()
    {
        return i;
    }
};

X operator*(X x, Y y)
{
    return x.i * y.i;
}

int f(X x)
{
    return x.i;
}

X x = 1;
Y y = x;
int i = 2;

int main()
{
    cout << "i + 10 = " << i+10 << endl;
    /*
    cout << "y + 10 = " << y+10 << endl;
    cout << "y + 10 * y = " << y+10*y << endl;
    cout << "x + y + i = " << x+y+i << endl;
    cout << "x * x +i = " << x*x+i << endl;
    cout << "f(7) = " << f(7) << endl;
    cout << "f(y) = " << f(y) << endl;
    cout << "y + y = " << y+y << endl;
    */
    cout << "106 +y = " << 106+y << endl;

    return 0;
}
