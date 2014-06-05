#include <iostream>

class String
{
    struct Srep;
    Srep *rep;

    String();
    String(const char*);
    String(const String&);
    String& operator=(const char*);
    String& operator=(const String&);

    void check(int i) const 
    {
        if (i < 0 || rep->sz <= i)
        {
            throw Range();
        }
    }

    char read(int i) const
    {
        return rep->s[i];
    }
    void write(int i, char c)
    {
        rep = rep->get_own_copy();
        rep->s[i] = c;
    }

    Cref operator[](int i)
    {
        check(i);
        return Cref(*this, i);
    }
    char operator[](int i) const
    {
        check(i);
        return rep->s[i];
    }

    int size() const 
    {
        return rep->sz;
    }
    ~String();
public:
    class Cref;
    class Range { };
};

struct String::Srep
{
    char* s;
    int sz;
    int n;

    Srep(int nsz, const char* p)
    {
        n = 1;
        sz = nsz;
        s = new char[sz+1];
        strcpy(s, p);
    }

    ~Srep() { delete[] s; }

    Srep* get_own_copy()
    {
        if (n == 1)
            return this;
        --n;
        return new Srep(sz, s);
    }

    void assign(int nsz, const char* p)
    {
        if (sz != nsz)
        {
            delete[] s;
            sz = nsz;
            s = new char[sz+1];
        }
        strcpy(s, p);
    }
private:
    Srep(const Srep&);
    Srep& operator=(const Srep&);
};

class String::Cref
{
    friend class String;
    String& s;
    int i;
    Cref(String& ss, int ii)
        : s(ss)
        , i(ii)
    {
    }
public:
    operator char() const
    {
        return s.read(i);
    }
    void operator=(char c)
    {
        s.write(i, c);
    }
};

String::String()
{
    rep = new Srep(0, "");
}

String::String(const String& x)
{
    x.rep->n++;
    rep = x.rep;
}

String::~String()
{
    if (--rep->n == 0)
    {
        delete rep;
    }
}

String& String::operator=(const String& x)
{
    x.rep->n++;
    if(--rep->n == 0)
    {
        delete rep;
    }
    rep = x.rep;
    return *this;
}

String::String(const char* s)
{
    rep = new Srep(strlen(s), s);
}

String& String::operator=(const char* s)
{
    if (rep->n == 1)
    {
        rep->assign(strlen(s), s);
    }
    else
    {
        --rep->n;
        rep = new Srep(strlen(s), s);
    }
    return *this;
}
