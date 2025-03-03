/* 

Reflector     Manager     Scribe       Recorder

GROUP 6:
    CHARLIE SPARROW - 

    ALEX LY - Wrote the Overloaded + - * / functions.

    KHANG VU - Wrote Constructors, Mutators, Accessors, and overloaded extraction operator

    HECTOR VAZQUEZ - 
*/
#include <iostream>
#include <vector>
using namespace std;

class ComplexNumber {
public:
    //need constructors, accessors and mutators, and overloaded operators below

    // Khang Vu - Constructors
    ComplexNumber() : real(0), imaginary(0) {}; // Default constructor
    ComplexNumber(double newReal, double newI) : real(newReal), imaginary(newI) {}; // Value constructor

    // Khang Vu - Mutators + Accessors
    double Re(void) { return real; }
    double Im(void) { return imaginary; }

    void setRe(double newR) { real = newR; }
    void setIm(double newIm) { imaginary = newIm; }

    // Khang Vu - Overloaded << - Friend non-Member
    friend ostream& operator<<(ostream& outstream, const ComplexNumber& obj);

    // Alex Ly - Overloaded Math Functions Below - Friend non-Members
    friend ComplexNumber operator+(const  ComplexNumber &c1, const  ComplexNumber &c2);
    friend ComplexNumber operator-(const  ComplexNumber &c1, const  ComplexNumber &c2);
    friend ComplexNumber operator*(const  ComplexNumber &c1, const  ComplexNumber &c2);
    friend ComplexNumber operator/(const  ComplexNumber &c1, const  ComplexNumber &c2);


private:
    double real;
    double imaginary;
};

int main() {
    //writing the driver here - Charlie Sparrow
    cout << "Hello, world!" << endl;
    return 0;
}

// FUNCTION DEFINITIONS
// KV - Overloaded <<
ostream& operator<<(ostream& outstream, const ComplexNumber& obj) {
    outstream << obj.real << "+" << obj.imaginary << "i";
    return outstream;
}

// Alex Ly - Logic for mathematical functions for imaginary numbers -> source: https://en.wikipedia.org/wiki/Complex_number#Addition_and_subtraction

// Addition Operator
ComplexNumber operator+(const  ComplexNumber &c1, const  ComplexNumber &c2) {
    return ComplexNumber(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

// Subtraction Operator
ComplexNumber operator-(const  ComplexNumber &c1, const  ComplexNumber &c2) {

    return ComplexNumber(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

// Multiplication Operator
// (a + bi) * (c+di) = ac - bd + (ad + bc)i
ComplexNumber operator*(const  ComplexNumber &c1, const  ComplexNumber &c2) {
    //                     real portion below                                   imaginary portion below (because it is multiplied by i)
    //                        a         c            b               d              a          d              b              c
    return ComplexNumber((c1.real * c2.real) - (c1.imaginary * c2.imaginary), ((c1.real * c2.imaginary) + (c1.imaginary * c2.real)));
}

// Division Operator
// ((ux + vy) / (x*x + y*y))    +    ((vx - uy) / (x*x + y*y))i  denominator rationalization
ComplexNumber operator/(const  ComplexNumber &c1, const  ComplexNumber &c2) {

    //((ux + vy) / (x * x + y * y)
    return ComplexNumber(

//      real portion
//      u           x           v               y               x          x           y                y                                                                          
    (((c1.real * c2.real) + (c1.imaginary * c2.imaginary)) / ((c2.real * c2.real) + (c2.imaginary * c2.imaginary))),    

//      imaginary portion
//              v           x           u           y               x       x           y                   y
    (((c1.imaginary * c2.real) - (c1.real * c2.imaginary)) / ((c2.real * c2.real) + (c2.imaginary * c2.imaginary)))
    
    );
}