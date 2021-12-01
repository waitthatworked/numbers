#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string intToString(int number);
void printIntStrings(int start, int end, int interval);

//function prototypes
string ones(int onesDigit);
string teens(int onesDigit);
string tens(int onesDigit, int tensDigit);
string hundreds(int onesDigit, int tensDigit, int hundredsDigit);
string thousands(int onesDigit, int tensDigit, int hundredsDigit, int thousandsDigit, int ttDigit);

int main(int argc, char** argv) {
    
    int start = 0;
    int end = 0;
    int interval = 0;
    
    cout << "input a starting value: ";
    cin >> start;
    cout << "input an end: ";
    cin >> end;
    cout << "interval: ";    
    cin >> interval;
    
    printIntStrings(start, end, interval);
    
    return 0; 
}

void printIntStrings(int start, int end, int interval){
    for (int i = start; i <= end; i+=interval){
        cout << i << ": " << intToString(i) << endl;
    }
}

//intToString() will pass digits to other functions
string intToString(int num){ 
    string stringNum = "BLANK";
    
    // digit[] array with 5 elements
    int digit[5] = {0,0,0,0,0};
    
    //enclosed in if statement to avoid abort trap errors
    if (0<=num && num <= 99999){
        
    //used an array for digit assignment, in the end just converted to five variables
        
        int digitAssign = num;
        int i = 0;  
        
        while (digitAssign>0){
            digit[i] = digitAssign%10;
            digitAssign = digitAssign/10;
            i++;
        }
    }
    
    int onesDigit = digit[0];
    int tensDigit = digit[1];
    int hundredsDigit = digit[2];
    int thousandsDigit = digit[3];
    int ttDigit = digit[4];
    
    //TEMPORARY   
    cout << "1s\t10s\t100s\t1000s\t10,000s\t" << endl;
    cout << onesDigit << "\t" << tensDigit << "\t" << hundredsDigit << "\t" << thousandsDigit << "\t" << ttDigit << endl;
    
    if (num == 0){
        stringNum = "zero";
    }
    else if (0<num && num<=9){
        stringNum = ones(onesDigit);
    }
    else if (10<=num && num<=99){
        stringNum = tens(onesDigit, tensDigit);
    }
    else if (100<=num && num<=999){
        stringNum = hundreds(onesDigit, tensDigit, hundredsDigit);     
    }
    else if (1000<=num && num<=99999)
        stringNum = thousands(onesDigit, tensDigit, hundredsDigit, thousandsDigit, ttDigit);
    else {
        stringNum = "error";
    }
    return stringNum;
}

string ones(int onesDigit){
    string oneString;
    
    switch(onesDigit){
        case 0:
            oneString = "";
            break;
        case 1:
            oneString = "one";
            break;
        case 2:
            oneString = "two";
            break;
        case 3:
            oneString = "three";
            break;
        case 4:
            oneString = "four";
            break;
        case 5:
            oneString = "five";
            break;
        case 6:
            oneString = "six";
            break;
        case 7:
            oneString = "seven";
            break;
        case 8:
            oneString = "eight";
            break;
        case 9:
            oneString = "nine";
            break;
        default:
            oneString = "onesError";
            break;
    }  
    return oneString;
}

string teens(int onesDigit){
    string teenString;
    
    switch(onesDigit){
        case 0:
            teenString = "ten";
            break;
        case 1:
            teenString = "eleven";
            break;
        case 2:
            teenString = "twelve";
            break;
        case 3:
            teenString = "thirteen";
            break;
        case 4:
            teenString = "fourteen";
            break;
        case 5:
            teenString = "fifteen";
            break;
        case 6:
            teenString = "sixteen";
            break;
        case 7:
            teenString = "seventeen";
            break;
        case 8:
            teenString = "eighteen";
            break;
        case 9:
            teenString = "nineteen";
            break;
        default:
            teenString = "teensError";
            break;
    }  
    return teenString;
}

string tens(int onesDigit, int tensDigit){
    string tenString;
    
    if (tensDigit == 1){
        tenString = teens(onesDigit);
    }
    else{
        switch(tensDigit){
            case 0:
                tenString = "";
                break;
            case 1:
                tenString = "ten";
                break;
            case 2:
                tenString = "twenty";
                break;
            case 3:
                tenString = "thirty";
                break;
            case 4:
                tenString = "forty";
                break;
            case 5:
                tenString = "fifty";
                break;
            case 6:
                tenString = "sixty";
                break;
            case 7:
                tenString = "seventy";
                break;
            case 8:
                tenString = "eighty";
                break;
            case 9:
                tenString = "ninety";
                break;
            default:
                tenString = "tensError";
                break;     
        }
        //no ones digit, prints out just the 'n'-ty
        if (onesDigit == 0){
            tenString = tenString;  
        }
        //if the tens digit is 0, only calls ones function
        else if (tensDigit == 0){
            tenString = ones(onesDigit);
        }
        //if both are > 0, it will print a dash "-" in between
        else {
            tenString = tenString + "-" + ones(onesDigit);
        }
    }
    return tenString;
}

string hundreds(int onesDigit, int tensDigit, int hundredsDigit){
    string hundredString;
    
    if (hundredsDigit != 0){
        hundredString = ones(hundredsDigit) + " hundred";
    }
    //will only print an "and" if a value follows the hundreds place
    if (onesDigit != 0 || tensDigit != 0){
        hundredString = hundredString + " and " + tens(onesDigit, tensDigit);
    }  
    return hundredString;
}

string thousands(int onesDigit, int tensDigit, int hundredsDigit, int thousandsDigit, int ttDigit){
    string thousandString;
    
    thousandString = tens(thousandsDigit, ttDigit) + " thousand" ;
    
    if (onesDigit != 0 || tensDigit != 0 || hundredsDigit != 0) {
        
        //this is to avoid printing two spaces after a comma
        
        if (hundredsDigit == 0){
            thousandString = thousandString + "," + hundreds(onesDigit, tensDigit, hundredsDigit);
        }
        else{
            thousandString = thousandString + ", " + hundreds(onesDigit, tensDigit, hundredsDigit);
        }
    }
    return thousandString;
}