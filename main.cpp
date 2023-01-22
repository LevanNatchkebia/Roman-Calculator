#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

//############################################################################
//maping roman numerals to integer 
map<char, int> romanMap;                                   

void symbolMap() {
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
}


//############################################################################
//convert romanian symbols to integer
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


//############################################################################
//convert integers to romanian symbols
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
    
    
    string input, num1, operatorSymbol, number;
    int  result;
    
    
    
    cout<<"Welcome, I am Roman Numeral Calculator"<<endl;
    cout<< endl;
    cout<<"Please Enter Roman Numeral: ";
    cin>>input;
    
    
    
    result = romanToInt(input);
    
    number = to_string(result);
    
    
    
//############################################################################
// create vectors for romanian symbols and for numbers, for printing result and complete arithmetical actions  
    vector <string> symb;
    vector <string> nums;
    
    
    
    
    symb.push_back(input);
    nums.push_back(number);
    
    
    
    
    while (true) {
  //############################################################################
  // checks if 'exit' is entered in number entering level and remove word 'exit' and arithmetical symbol from vector and adds it '=' and result.
        if (num1=="exit") {
            symb.pop_back();
            symb.pop_back();
            symb.push_back("=");
            symb.push_back(intToRoman(result));
            for (int i=0; i< symb.size(); i++){
                cout<< symb[i];
             
            } 
            
            cout<< endl;
            
            
            nums.pop_back();
            nums.pop_back();
            nums.push_back("=");
            nums.push_back(to_string(result));
            for (int i=0; i< nums.size(); i++){
                cout<< nums[i];
             
            }
            
            break;
        }
        
        
        
   //############################################################################
  // checks if 'exit' is entered in arithmetical symbol entering level and remove word 'exit' from vector and adds it '=' and result.     
        
        if (operatorSymbol=="exit") {
            symb.pop_back();
            symb.push_back("=");
            symb.push_back(intToRoman(result));
            for (int i=0; i< symb.size(); i++){
                cout<< symb[i];
             
            }
            
            cout<< endl;
            nums.pop_back();
            nums.push_back("=");
            nums.push_back(to_string(result));
            for (int i=0; i< nums.size(); i++){
                cout<< nums[i];
              
            }
            break;
        }
        
 //########################################################################################
 //checks for how long loop must be used and what operations must be done
        if (num1!= "exit") {
            cout<<"Select from following operators: +, -, *, /"<<endl;
            cout<<"Please Enter operator: ";
            cin>>operatorSymbol;
            symb.push_back(operatorSymbol);
            nums.push_back(operatorSymbol);
        }
        
        
        
        if (operatorSymbol != "exit") {
            cout<<"Enter next Roman Numeral: ";
            cin>>num1;
            symb.push_back(num1);
            nums.push_back(to_string(romanToInt(num1)));
            
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
        
    
        
        
    }
    return 0;
}