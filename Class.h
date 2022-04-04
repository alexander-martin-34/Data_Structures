#ifndef CHAPTER13_CLASSES_CLASS_H
#define CHAPTER13_CLASSES_CLASS_H
/* 13.5 FOCUS ON SOFTWARE ENGINEERING: SEPARATING CLASS SPECFICATION FROM IMPLEMENTATION
 *  In programs we've looked at so far, the class declaration, member function definitions,
 *  and application program are all stored in one file.
 *  A more conventional way of designing C++ programs is to store class declarations and member function definitions
 *  in their own separate files.
 *  Class declarations are stored in their own header files.
 *  A header file that contains a class declaration is call a class specification file
 *  The name of the specification file is usually the same as the name of the class, with a .h extension.
 */
class Rectangle
{
private:
    double width;
    double length;
public:

    //CONSTRUCTORS
    //Without arguments
    //Rectangle();
    //With arguments
    Rectangle(double, double);
    /*
     * The constructor Rectangle() can have arguments such as (double w, double len) - see main.cpp for 13.7
     * this would allow box object to be initialized instantly
     * Rectangle box(10.0, 20.0);
     */

    void setWidth(double);
    void setLength(double);

    double getWidth() const;
    double getLength() const;
    double getArea() const;
};


#endif //CHAPTER13_CLASSES_CLASS_H
//#endif & #ifndefd are called include guard, preventing class declaration from being included more than once