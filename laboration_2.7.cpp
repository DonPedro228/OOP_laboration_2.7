#include <iostream>
#include "Set.h"
#include "BitString.h"
using namespace std;

int main() {
    Set set1, set2;
    cout << "Input set_1" << endl;
    cin >> set1;
    cout << "Set1: " << endl;
    cout << set1 << endl;
    cout << endl;

    cout << "Input set_2" << endl;
    cin >> set2;
    cout << "Set2: " << endl;
    cout << set2 << endl;
    cout << endl;

    int elem_1;
    cout << "Add Elem for set_1: "; cin >> elem_1;

    set1 = set1 + elem_1;
    cout << "Set 1 after add: " << endl;
    cout << set1 << endl;

    int elem_2;
    cout << "Add Elem for set_2: "; cin >> elem_2;

    set2 = set2 + elem_2;
    cout << "Set 2 after add: " << endl;
    cout << set2 << endl;


    int elem_3;
    cout << "Remove Elem for set_1: "; cin >> elem_3;

    set1 = set1 - elem_3;
    cout << "Set 1 after removing: " << endl;
    cout << set1 << endl;

    int elem_4;
    cout << "Remove Elem for set_2: "; cin >> elem_4;

    set2 = set2 - elem_4;
    cout << "Set 2 after removing: " << endl;
    cout << set2 << endl;

    int count;
    count = set1[0] + set1[1];
    cout << "Count elem in set1: " << count << endl;

    int count_2;
    count_2 = set2[0] + set2[1];
    cout << "Count elem in set2: " << count_2 << endl;

    Set set3 = set1 += set2;
    cout << "Union set: " << endl;
    cout << set3 << endl;
         
    Set set4 = set1 / set2;
    cout << "Interest: " << endl;
    cout << set4 << endl;

    Set set5 = set1(set2);
    cout << "Difference set: " << endl;
    cout << set5 << endl;

    set1 = set1 < 5;
    cout << "Set1 after moving" << endl; 
    cout << set1 << endl;

    set2 = set2 > 5;
    cout << "Set1 after moving" << endl; 
    cout << set2 << endl;

    return 0;
}
