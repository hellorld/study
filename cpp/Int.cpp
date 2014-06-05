#include <iostream>

class Int
{
    int m_i;
public:
    Int(int i = 0)
    {
        m_i = i;
    }

    Int& operator=(int i)
    {
        m_i = i;
        return *this;
    }

    Int& operator+=(int i)
    {
        m_i += i;
        return *this;
    }

    operator int()
    {
        return m_i;
    }

    int getValue()
    {
        return m_i;
    }
};

int main()
{
    Int a(3);
    Int b;
    b = a;
    b = 5;
    b += a;
    const char* p = "hello, world";
    std::cout << "b.m_i = " << b.getValue() << std::endl;
    std::cout << "p[b] = " << p[b] << std::endl;
}
