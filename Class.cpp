#include "Class.h"    // needed for class declaration
#include <iostream>   // needed for cout
#include <cstdlib>   //needed for EXIT function
using namespace std;


Rectangle::Rectangle(double w, double len)
{
    width = w;
    length = len;
}

void Rectangle::setWidth(double w)
{
    if( w >= 0)
        width = w;
    else
    {
       cout << "Invalid Width";
        exit(EXIT_FAILURE);
    }

}
void Rectangle::setLength(double len)
{
    if( len >= 0)
        length = len;
    else
    {
        cout << "Invalid Length";
        exit(EXIT_FAILURE);
    }

}
double Rectangle::getWidth() const
{
    return width;
}
double Rectangle::getLength() const
{
    return length;
}
double Rectangle::getArea() const
{
    return length * width;
}

