#include <iostream>
#include <cmath>
using namespace std;

class Point{
public:

    //get info
    double& getX() const {return (double&)x;};
    double& getY() const {return (double&)y;};

    //overloading operators
    int operator<(const Point &pt) const;
    int operator>(const Point &pt) const;
    int operator==(const Point &pt) const;
    int operator<=(const Point &pt) const;
    int operator>=(const Point &pt) const;

    friend istream& operator>>(istream &inStream, const Point &pt);
    friend ostream& operator<<(ostream &outStream, const Point &pt);

    double computeNorm() const{return sqrt(x*x+y*y);};

private:
    double x, y;
};

// I/O
istream& operator>>(istream &inStream, const Point &pt)
{
    inStream >> pt.getX() >> pt.getY();
    return inStream;
}

ostream& operator<<(ostream &outStream, const Point &pt)
{
    outStream << "(" << pt.getX() << ", " << pt.getY() << ")";
    return outStream;
}

// Overloading the < operator
int Point::operator<(const Point &pt) const
{
    double norm0 = this->computeNorm();
    double norm1 = pt.computeNorm();
    return norm0 < norm1;
}

// Overloading the > operator
int Point::operator>(const Point &pt) const
{
    return pt < (*this);
}

// Overloading the == operator
int Point::operator==(const Point &pt) const
{
    double xVal = (this->getX()-pt.getX())*(this->getX()-pt.getX());
    double yVal = (this->getY()-pt.getY())*(this->getY()-pt.getY());
    return fabs(xVal+yVal) < 1e-20;
}

// Overloading the <= operator
int Point::operator<=(const Point &pt) const
{
    return (*this < pt) || (*this == pt);
}

// Overloading the >= operator
int Point::operator>=(const Point &pt) const
{
    return pt <= (*this);
}

int main (int argc, char * const argv[]) {
    Point pt;
    cin >> pt;
    cout << pt << endl;
    return 0;
}
