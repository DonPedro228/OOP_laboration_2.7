#include "BitString.h"
#include "Set.h"
#include <string>
#include <bitset>
#include <intrin.h>
using namespace std;

Set::Set(const Set& other) {
    data = other.data;
}

void Set::Init(unsigned long value1, unsigned long value2)
{

    data.Init(value1, value2);
}

Set& Set::operator=(const BitString& other) {
    data = other; 
    return *this; 
}

Set operator+(const Set& set, int element) {
    Set result(set); 
    if (element >= 0 && element < 32)
        result.data = result.data | BitString(1UL << element, 0);
    else if (element >= 32 && element < 64)
        result.data = result.data | BitString(0, 1UL << (element - 32));
    else
        cout << "Element out of range" << endl;

    return result;
}

Set operator-(const Set& set, int element) {
    Set result(set); 
    if (element >= 0 && element < 32) {
        result.data.setField_1(result.data.getField_1() & ~(1UL << element));
    }
    else if (element >= 32 && element < 64) {
        result.data.setField_2(result.data.getField_2() & ~(1UL << (element - 32)));
    }
    else {
        cout << "Element out of range" << endl;
    }

    return result;
}

Set& Set::operator+=(const Set& other) {
    data = data | other.data;
    return *this;
}

Set operator/(const Set& set1, const Set& set2) {
    Set result;
    result.data = set1.data & set2.data;
    return result;
}

Set Set::operator()(const Set& other) const {
    Set result;

    result.data = data & (data != other.data);

    return result;
}

Set::operator string() const
{
    return string(data);
}

ostream& operator<<(ostream& out, const Set& set)
{
    out << "Field_1: " << bitset<64>(set.getField_1()) << endl;
    out << "Field_2: " << bitset<64>(set.getField_2()) << endl;
    return out;
}

istream& operator>>(istream& in, Set& set) {
    unsigned long number1, number2;

    cout << "Enter first number: ";
    in >> number1;

    cout << "Enter second number: ";
    in >> number2;

    if (number1 > 31) {
        set.setField_2(1UL << (number1 - 32));
        set.setField_1(0);
    }
    else {
        set.setField_1(1UL << number1);
        set.setField_2(0);
    }

    if (number2 > 31) {
        set.setField_2(set.getField_2() | 1UL << (number2 - 32));
    }
    else {
        set.setField_1(set.getField_1() | 1UL << number2);
    }

    return in;
}

int Set::operator[](int index) const {
    if (index == 0) 
        return __popcnt(data.getField_1()); 
    else if (index == 1)
        return __popcnt(data.getField_2()); 
    else
        return -1;
}

Set operator<(const Set& other, int bits) {
    unsigned long new_field_1, new_field_2;

    if (bits >= 64) {
        return Set();
    }
    else if (bits >= 32) {
        new_field_1 = other.data.getField_2() << (bits - 32);
        new_field_2 = 0;
    }
    else {
        new_field_1 = (other.data.getField_1() << bits) | (other.data.getField_2() >> (32 - bits));
        new_field_2 = other.data.getField_2() << bits;
    }

    return Set(new_field_1, new_field_2);
}

Set operator>(const Set& other, int bits) {
    unsigned long new_field_1, new_field_2;

    if (bits >= 64) {
        return Set();
    }
    else if (bits >= 32) {
        new_field_1 = 0;
        new_field_2 = other.data.getField_1() >> (bits - 32);
    }
    else {
        new_field_2 = (other.data.getField_2() >> bits) | (other.data.getField_1() << (32 - bits));
        new_field_1 = other.data.getField_1() >> bits;
    }

    return Set(new_field_1, new_field_2);
}