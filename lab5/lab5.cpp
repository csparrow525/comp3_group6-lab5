/* 

Reflector - Alex
Manager - Charlie
Scribe - Hector
Recorder - Khang

GROUP 6:
    CHARLIE SPARROW - Wrote the driver in main and created repository

    ALEX LY - Wrote the Overloaded + - * / functions.

    KHANG VU - Wrote Constructors, Mutators, Accessors, and overloaded extraction operator

    HECTOR VAZQUEZ -  Wrote overloaded ! function.
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

    //Hector Vazquez - Overloaded ! operator
    friend ComplexNumber operator!(const  ComplexNumber& c1);

private:
    double real;
    double imaginary;
};

int main() {
    //Complex number objects created with default constructor as well as constructor that take two ints
    //the first for the real number and second for imaginary
    ComplexNumber c1;
    ComplexNumber c2(1,2);
    ComplexNumber c3(3,4);

    //outputs
    cout << "Value of c1 (default constructor): " << endl;
    cout << "c1.Re() == " << c1.Re() << ", c1.Im() == " << c1.Im() << endl;
    cout << "Value of c2 (value constructor): " << endl;
    cout << "c2.Re() == " << c2.Re() << ", c2.Im() == " << c2.Im() << endl;

    cout << "\nc2 + c3 (" << c2 << " + " << c3 << ") == " << c2 + c3 <<  endl;
    cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << c2 - c3 <<  endl;
    cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << c2 * c3 <<  endl;
    cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << c2 / c3 <<  endl;
    cout << "(c2/c3) + (c2*c3) == " <<  (c2/c3) + (c2*c3) <<  endl;
    //need hector to write the overload the ! operator before i can add this part
    cout << "c2 is currently " << c2 << "; !c2 (complex conjugate of c2) == " << !c2 << endl;

    //outputs vector of ComplexNumbers using for loop
    vector<ComplexNumber> v;
    cout << "\nVector output using indexed for-loop:" << endl;
    for (int i = 0; i < 10; i++) {
        ComplexNumber c(i, i*2);
        v.push_back(c);
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    //outputs vector of complex numbers using iterator inside a for loop
    cout << "\nVector output using an iterator in for loop:" << endl;
    vector<ComplexNumber>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }


    return 0;
}

// FUNCTION DEFINITIONS
// KV - Overloaded <<
ostream& operator<<(ostream& outstream, const ComplexNumber& obj) {
    outstream << obj.real;
    if (obj.imaginary >= 0) outstream << "+";
    outstream << obj.imaginary << "i";
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

//Hector Vazquez - Logic for overloaded ! operator
ComplexNumber operator!(const ComplexNumber& c1) {
    return ComplexNumber(c1.real, -(c1.imaginary));
}