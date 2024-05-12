/* Amy Saad
* Program: main.cpp, uses:
 * constructors, overloaded operators ( >>, <<, +, =, +=)
* Purpose: Program to manipulate octal numbers as easily as decimals
* Input  : No input per se, converts octal values to decimal
* Output : Depends on the test program/user input. Returns sum of 2 octal numbers
and decimal value
*/

#include <iostream>
using namespace std;
class octal {
    int octalValue;
public:
    octal();
//default constructor
    octal(octal&);
    constructor, reference to object octal (parameter)
    int toDecimal() const;
//method() to turn octal decimal
    friend istream& operator >> (istream&, octal&);
    input and output overloading operators
    friend ostream& operator << (ostream&, octal&);
    friend octal operator + (const octal&other, const octal& other2);
//overloading operator+
    octal& operator = (const int &);
//overloading operator=
    friend void operator += (octal&, octal&);
//overloading operator+=
};
octal::octal() {
//default constructor, member of octal class
    octalValue = 0;
    variable to 0
}
octal::octal(octal& other) {
    constructor for class octal
            octalValue = other.octalValue;
//initializes new object
}
istream &operator>>(istream& input, octal& o) {
//overload input operator >> (input and octal as parameters)
    int num;
//assigns int to num
    input >> num;
    o.octalValue = num;
//copy
//
//sets
//copy
//assigns num to octalValue
    return input;
//returns input, istream object
}
ostream &operator<<(ostream &output, octal &octal) {
//overload input operator >> (output and octal as parameters)
    output << octal.octalValue << endl;
//outputs octal value to output stream
    return output;
//returns output, ostream object
}
octal operator+(const octal &other, const octal &other2) {
//overload operator + (octal, other, other2 as parameters)
    octal temp;
//creates temp as octal object
    temp = other.octalValue + other2.octalValue;
    octal values and assigns to temp
    return temp;
//returns temp, octal object
}
octal &octal::operator=(const int & right) {
//overload operator = (right as parameter)
    octalValue = right;
//assigns right to octalValue
    return *this;
//returns this, reference to octal object
}
int octal::toDecimal() const {
//converting octal to decimal
    int dec_val = 0;
//initializes dec_val to 0
    int num =1;
//initializes num to 1
    for (int temp = octalValue; temp > 0; temp /= 10){
//iterates through octalValue
        int dec = temp % 10;
        dec_val += dec * num;
        conversion to dec_val
        num *= 8;
        track of value
    }
    return dec_val;
//returns dec_val (int)
}
void operator+=(octal &left, octal &right) {
//overload operation += (left and right as parameters)
    left.octalValue += right.octalValue;
}
int main() {
    octal oOne, oTwo, oThree;
    int iNum;
//adds
//adds
//keeps
//main

    cout << " Type in two octal numbers to add: " << endl;
    cin >> oOne >> oTwo;
    oOne = oOne + oTwo;
    cout << " Sum is: " << oOne;
    iNum = 23;
    oThree = iNum;
    cout << " Octal is: " << oThree;
    cout << " Its decimal value is: " << oThree.toDecimal();
    return 0;
}