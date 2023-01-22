#include <iostream>
#include <map>
using namespace std;

map<char, int> romanMap;                                    

void symbolMap() {
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;
}

int romanToInt(string roman) {
    int result = 0;
    for (int i = 0; i < roman.length(); i++) {
        if (i > 0 && romanMap[roman[i]] > romanMap[roman[i - 1]]) {
            result += romanMap[roman[i]] - 2 * romanMap[roman[i - 1]];
        } else {
            result += romanMap[roman[i]];
        }
    }
    return result;
}

string intToRoman(int num) {
    string roman[] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result = "";
    for (int i = 0; i < 9; i++) {
        while (num >= values[i]) {
            result += roman[i];
            num -= values[i];
        }
    }
    return result;
}

int main() {
    symbolMap();
    string input, num1, operatorSymbol;
    int  result;
    cout<<"Welcome, I am Roman Numeral Calculator"<<endl;
    cout<< endl;
    cout<<"Please Enter Roman Numeral: ";
    cin>>input;
    
    result = romanToInt(input);
    
    while (true) {
        cout<<"Select from following operators: +, -, *, /"<<endl;
        cout<<"Please Enter operator: ";
        cin>>operatorSymbol;
        
        if (operatorSymbol != "exit") {
            cout<<"Enter next Roman Numeral: ";
            cin>>num1;
        }
        if (operatorSymbol == "+") {
            result = result + romanToInt(num1);
        }
        else if (operatorSymbol == "-") {
            result = result - romanToInt(num1);
        }
        else if (operatorSymbol == "*") {
            result = result * romanToInt(num1);
        }
        else if (operatorSymbol == "/") {
            result = result / romanToInt (num1);
        }
        else if (operatorSymbol=="exit" || num1 == "exit") {
            cout<< intToRoman(result)<<endl;
            break;
        }
        
    }
    
    
    return 0;
}




