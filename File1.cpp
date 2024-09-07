//SINETHEMBA MABASO 
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int random_r();
string decimal_to_binary(int Decimal_Value);
int binary_to_decimal(int binary);
string decimal_to_hexadecimal(int Decimal_Value);
int hexadecimal_to_decimal(string Hexadecimal_Value);
//THIS GIVES A RANDOM NUMBER
int random_r() {
    srand(time(NULL));
    return (rand() % (99 - 1 + 1)) + 1;
}
//THIS CONVERT A DECIMAL TO BINARY
string decimal_to_binary(int Decimal_Value) {
    string binarycode;
    while (Decimal_Value > 0) {
        binarycode = to_string(Decimal_Value % 2) + binarycode;
        Decimal_Value = Decimal_Value / 2;
    }
    return binarycode;
}
//THIS CONVERT A BINARY TO DECIMAL
int binary_to_decimal(int binary) {
    int tot = 0, i = 0, remainder;
    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        tot += remainder * pow(2, i);
        ++i;
    }
    return tot;
}
//THIS CONVERT A DECIMAL TO HEXADECIMAL
string decimal_to_hexadecimal(int Decimal_Value) {
    string hexcode;
    while (Decimal_Value > 0) {
        int remainder = Decimal_Value % 16;
        if (remainder < 10)
            hexcode = to_string(remainder) + hexcode;
        else
            hexcode = char(remainder - 10 + 'A') + hexcode;
        Decimal_Value = Decimal_Value / 16;
    }
    return hexcode;
}
//THIS CONVERT HEXADECIMAL TO DECIMAL
int hexadecimal_to_decimal(string Hexadecimal_Value) {
    int totA = 0, size = 0;
    int length = Hexadecimal_Value.size() - 1;
    while (length >= 0) {
        int remainder = Hexadecimal_Value[length];
        if (remainder >= '0' && remainder <= '9') {
            remainder = remainder - '0';
        } else if (remainder >= 'A' && remainder <= 'F') {
            remainder = remainder - 'A' + 10;
        }
        totA = totA + remainder * pow(16, size);
        length--;
        size++;
    }
    return totA;
}

int main() {
    int menuselection = 0;
    cout << "PROGRAM MENU:" << endl;
    printf("1.\tConvert DECIMAL to BINARY \n");
    printf("2.\tConvert BINARY to DECIMAL \n");
    printf("3.\tConvert HEXADECIMAL to DECIMAL \n");
    printf("4.\tConvert DECIMAL to HEXADECIMAL \n");
    printf("5.\tDEMO (Generate and convert random integers to binary) \n");
    printf("6.\tExit\n");

    while (menuselection < 7) {
        cout << "Enter your selection (1-6): ";
        cin >> menuselection;
        if (menuselection == 1) {
            int DV;
            cout << "Give a decimal number: ";
            cin >> DV;
            cout << "Binary representation: " << decimal_to_binary(DV) << endl;
        } else if (menuselection == 2) {
            int BN;
            cout << "Give a binary number: ";
            cin >> BN;
            cout << "Decimal representation: " << binary_to_decimal(BN) << endl;
        } else if (menuselection == 3) {
            string Hexadecimal_Value;
            cout << "Give a hexadecimal number: ";
            cin >> Hexadecimal_Value;
            cout << "Decimal representation: " << hexadecimal_to_decimal(Hexadecimal_Value) << endl;
        } else if (menuselection == 4) {
            int Decimal_Value;
            cout << "Give a decimal number: ";
            cin >> Decimal_Value;
            cout << "Hexadecimal representation: " << decimal_to_hexadecimal(Decimal_Value) << endl;
        } else if (menuselection == 5) {
            int Rnumber = random_r();
            cout << "Generated random integer: " << Rnumber << endl;
            cout << "Binary representation: " << decimal_to_binary(Rnumber) << endl;
        } else if (menuselection == 6) {
            cout << "Exiting the program." << endl;
            exit(0);
        }
    }
    return 0;
}
