#include "BitString.h"
#include <sstream>
#include <string>
#include <bitset>
using namespace std;

BitString::BitString(const BitString& other) : field_1(other.field_1), field_2(other.field_2) {}

void BitString::Init(unsigned long value1, unsigned long value2)
{
    setField_1(value1);
    setField_2(value2);
}

BitString& BitString::operator=(const BitString& other) 
{
    if (this != &other) {
        field_1 = other.field_1;
        field_2 = other.field_2;
    }
    return *this;
}

BitString::operator string() const 
{
    return bitset<64>(field_1).to_string() + "\n " + bitset<64>(field_2).to_string();
}

ostream& operator<<(ostream& out, const BitString& bitString)
{
    out << "Field_1: " << bitset<64>(bitString.field_1) << endl;
    out << "Field_2: " << bitset<64>(bitString.field_2) << endl;
    return out;
}

istream& operator>>(istream& in, BitString& bitString) {
    unsigned long number1, number2;

    cout << "Enter first number: ";
    in >> number1;

    cout << "Enter second number: ";
    in >> number2;

    if (number1 > 31) {
        bitString.field_2 = 1UL << (number1 - 32);
        bitString.field_1 = 0;
    }
    else {
        bitString.field_1 = 1UL << number1;
        bitString.field_2 = 0;
    }

    if (number2 > 31) {
        bitString.field_2 |= 1UL << (number2 - 32);
    }
    else {
        bitString.field_1 |= 1UL << number2;
    }

    return in;
}

BitString operator!=(const BitString& lhs, const BitString& rhs) {
    BitString result;
    result.field_1 = lhs.field_1 != rhs.field_1 ? 1 : 0;
    result.field_2 = lhs.field_2 != rhs.field_2 ? 1 : 0;
    return result;
}

BitString& BitString::operator++() {
    ++field_1;
    ++field_2;
    return *this;
}

BitString& BitString::operator--() {
    --field_1;
    --field_2;
    return *this;
}

BitString BitString::operator&(const BitString& other) const{
    BitString result;
    result.field_1 = field_1 & other.field_1;
    result.field_2 = field_2 & other.field_2;
    return result;
}

BitString BitString::operator|(const BitString& other) const {
    BitString result;
    result.field_1 = field_1 | other.field_1;
    result.field_2 = field_2 | other.field_2;
    return result;
}

BitString BitString::operator^(const BitString& other) {
    BitString result;
    result.field_1 = field_1 ^ other.field_1;
    result.field_2 = field_2 ^ other.field_2;
    return result;
}

BitString operator<(const BitString& other, int bits) {
    unsigned long new_field_1, new_field_2;

    if (bits >= 64) {
        return BitString();
    }
    else if (bits >= 32) {
        new_field_1 = other.field_2 << (bits - 32);
        new_field_2 = 0;
    }
    else {
        new_field_1 = (other.field_1 << bits) | (other.field_2 >> (32 - bits));
        new_field_2 = other.field_2 << bits;
    }

    return BitString(new_field_1, new_field_2);
}

BitString operator>(const BitString& other, int bits) {
    unsigned long new_field_1, new_field_2;

    if (bits >= 64) {
        return BitString();
    }
    else if (bits >= 32) {
        new_field_1 = 0;
        new_field_2 = other.field_1 >> (bits - 32);
    }
    else {
        new_field_2 = (other.field_2 >> bits) | (other.field_1 << (32 - bits));
        new_field_1 = other.field_1 >> bits;
    }

    return BitString(new_field_1, new_field_2);
}

