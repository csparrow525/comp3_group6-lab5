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
    friend ComplexNumber operator+(const  ComplexNumber c1, const  ComplexNumber c2);
    friend ComplexNumber operator-(const  ComplexNumber c1, const  ComplexNumber c2);
    friend ComplexNumber operator*(const  ComplexNumber c1, const  ComplexNumber c2);
    friend ComplexNumber operator/(const  ComplexNumber c1, const  ComplexNumber c2);


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
ComplexNumber operator+(const  ComplexNumber c1, const  ComplexNumber c2) {
    
    //add the real parts

    //add the imaginary parts

    //put them together into a new complex number
    ComplexNumber newComplex = c1 + c2;

    return newComplex;
}
ComplexNumber operator-(const  ComplexNumber c1, const  ComplexNumber c2) {

    return c1;
}
ComplexNumber operator*(const  ComplexNumber c1, const  ComplexNumber c2) {

    return c1;
}
ComplexNumber operator/(const  ComplexNumber c1, const  ComplexNumber c2) {

    return c1;
}