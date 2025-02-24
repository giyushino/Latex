#include <iostream>
#include <string>
using namespace std;

// function #1: find the index of the largest string in the first n strings
int locateMaximum(const string array[], int n) {
    
    // return error if n is 0 or negative
    if(n <= 0) {
        return -1;
    }
    
    // initialize the index of the 'largest' string by setting it to the first index
    int max = 0;

    // iterate for the rest of the array
    for (int i = 1; i < n; i++) {
        
        // if the string at the index is greater than the current max, make that the current max
        if(array[i] > array[max]) {
            max = i;
        }
    }

    return max;
}

// function #2: find the number of valid float strings in the first n strings
int countFloatingPointValues(const string array[], int n) {
    
    // return error if n is 0 or negative
    if(n <= 0) {
        return -1;
    }
    
    // initialize variable to count how many valid floats are found
    int floats = 0;

    // iterate for the each string in the array
    for (int i = 0; i < n; i++) {
        string s = array[i];
        
        // only run if the string isn't empty
        if(s != "") {
            
            // initializing variables for the amount of decimal points, digits, and whether the string is a valid float
            int decimals = 0;
            int digits = 0;
            bool isfloat = true; // flag to indicate if current string is a valid float
            
            // iterate for each character in the string
            for (int j = 0; j < s.length(); j++) {
                char ch = s[j];
                
                // if the character is a digit
                if(ch >= '0' && ch <= '9') {
                    digits++;
                
                // if the character is a decimal
                } else if(ch == '.') {
                    decimals++;
                    
                    // if more than one decimal point is found
                    if(decimals > 1) {
                        isfloat = false;
                        break;
                    }
                
                // if the character is literally anything else
                } else {
                    isfloat = false;
                    break;
                }
            }
            
            // if the string passes all prior tests, mark it as a valid float
            if(isfloat && digits > 0) {
                floats++;
            }
        }
        
        
    }
    
    return floats;
}


// function #3: check if any of the strings in the array has a capital letter
bool hasNoCapitals(const string array[], int n) {
    
    // return true if n is 0 or negative
    if(n <= 0) {
        return true;
    }
    
    // iterate through each string in the array
    for (int i = 0; i < n; i++) {
        string s = array[i];
        
        // iterate through each character in the string
        for (int j = 0; j < s.length(); j++) {
            char letter = s[j];
            
            // if character is uppercase, return false
            if(letter >= 'A' && letter <= 'Z') {
                return false;
            }
        }
    }
    
    // if no characters are uppcase, return true
    return true;
}


// function #4: shifts the first n elements to the left by a specified amount, filling all empty spaces with placeholders
int shiftLeft (string array[], int n, int amount, string placeholder) {
    
    // return error if n is 0 or negative
    if(n <= 0 || amount < 0) {
        return -1;
    }
    
    // if the amount shifted is greater than or equal to the size of the array, sets all strings to placeholder
    if(amount >= n) {
        for (int i = 0; i < n; i++) {
            array[i] = placeholder;
        }
        return n;
    } else {
        
        // copy and paste elements to the left
        for (int i = 0; i < n - amount; i++) {
            array[i] = array[i + amount];
        }
        
        // set the remaining strings to the placeholder
        for (int i = n - amount; i < n; i++) {
            array[i] = placeholder;
        }
    }
    
    return amount;
}
 
 
int main() {
    cout << "locateMaximum tests:" << endl;
    string array_set_1[4][6] = {
        {"i", "like", "computer", "science", "a", "lot"},
        {"science", "i", "like", "computer", "science", "a"},
        {"i", "like", "computer", "science", "a", "lot"},
        {"i", "like", "computer", "science", "a", "lot"}
    };
    int n_set_1[4] = {6, 6, 3, 0};
    int expected_1[4] = {3, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
        int result = locateMaximum(array_set_1[i], n_set_1[i]);
        cout << "test #" << i+1 << ": expected " << expected_1[i] << ", got " << result << endl;
    }
    cout << endl;
    
    cout << "countFloatingPointValues tests:" << endl;
    string array_set_2[4][6] = {
        {"1", "2.3", "4.56", "abacadaba", "7.89", "10.11"},
        {"yipeee", "001", "1.1.1", "+1.", ".1", "skadoosh"},
        {"1", "2", "3", "4", "", ""},
        {".", "/", "", "*", "(", ")"}
    };
    int n_set_2[4] = {6, 6, 6, 6};
    int expected_2[4] = {5, 2, 4, 0};
    for (int i = 0; i < 4; ++i) {
        int result = countFloatingPointValues(array_set_2[i], n_set_2[i]);
        cout << "test #" << i+1 << ": expected " << expected_2[i] << ", got " << result << endl;
    }
    cout << endl;
    
    cout << "hasNoCapitals tests:" << endl;
    string array_set_3[4][6] = {
        {"i", "lik", "co", "ding", "very", "much"},
        {"I", "LIK", "CO", "ding", "very", "much"},
        {"i", "lik", "co", "", "", ""},
        {"", "", "", "", "", ""}
    };
    int n_set_3[4] = {6, 6, 6, 6};
    bool expected_3[4] = {true, false, true, true};
    for (int i = 0; i < 4; ++i) {
        bool result = hasNoCapitals(array_set_3[i], n_set_3[i]);
        cout << "test #" << i+1 << ": expected " << (expected_3[i] ? "true" : "false")
             << ", got " << (result ? "true" : "false") << endl;
    }
    cout << endl;
    
    cout << "shiftLeft tests:" << endl;
    string array_set_4[4][6] = {
        {"please", "give", "me", "an", "A", "+"},
        {"please", "give", "me", "an", "A", "+"},
        {"please", "give", "me", "an", "A", "+"},
        {"please", "give", "me", "an", "A", "+"}
    };
    string expected_array[4] = {"me an A + yipeeee yipeeee","an A yipeeee yipeeee yipeeee","give me yipeeee",""};
    int n_set_4[4] = {6, 5, 3, 6};
    int shift_amount[4] = {2, 3, 1, -1};
    string placeholder = "yipeeee";
    int expected_4[4] = {2, 3, 1, -1};
    for (int i = 0; i < 4; ++i) {
        int result = shiftLeft(array_set_4[i], n_set_4[i], shift_amount[i], placeholder);
        cout << "test #" << i+1 << ": expected " << expected_4[i] << ", got " << result << endl;
        if(result >= 0) {
            cout << "expected array: " << expected_array[i] << endl;
            cout << "resulting array: ";
            int count = n_set_4[i];
            for (int j = 0; j < count; j++) {
                cout << array_set_4[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
