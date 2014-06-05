#include <iostream>

class Rint
{
    int m_i;
public:
    Rint(int i = 0)
    {
        m_i = i;
    }

    Rint& operator=(int i)
    {
        m_i = i;
        return *this;
    }

    int getValue()
    {
        return m_i;
    }

    Rint& operator+()
    {
        return *this;
    }

    Rint operator+(int i)
    {
        return m_i + i;
    }

    Rint operator+(const Rint& r)
    {
        return m_i + r.m_i;
    }

    Rint& operator-()
    {
        m_i = -m_i;
        return *this;
    }

    Rint operator-(int i)
    {
        return m_i - i;
    }

    Rint operator*(int i)
    {
        return m_i * i;
    }

    Rint operator/(int i)
    {
        return m_i / i;
    }
};

Rint operator+(int i, Rint r)
{
    return r+i;
}
Rint operator*(int i, Rint r)
{
    return r*i;
}

int main()
{
    Rint a = 3;
    Rint b = 5;
    Rint c = 5 + b;
    std::cout << c.getValue() << std::endl;
}
