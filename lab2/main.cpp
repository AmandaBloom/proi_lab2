#include <iostream>
#include "complexN.cpp"

using namespace std;


int main(){
    complexNumber temp1(6, 8);
    complexNumber temp2(3, 4);
    complexNumber temp3(10, 2);
    complexNumber temp4(9, 11);
    complexNumber temp5(21, 37);
    complexNumber temp6(temp5);

    temp1 -= temp2;
    cout << temp1;

    temp3 *= temp2;
    cout << temp3;

    temp4 /= 4;
    cout << temp4;

    cout << (temp2 > temp4) << "\n";

    cout << (temp5 == temp6) << "\n";

    cin >> temp2;
    cout << temp2;

    temp1^2;
    cout << temp1;

    system("Pause");
    return 0;
}