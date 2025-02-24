#include <iostream>
#include <string>
#include <cassert>
using namespace std; 


int locateMaximum(const string array[], int n) {
    // Returns the index of largest item found in the passed array of -1 if n <= 0
    if (n <= 0) return -1;
    // Initialize value to store largest array index
    int currentLargest = 0;
    for (int i = 1; i < n; i++) {
        // if current array is larger previous largest, update int
        if (array[i] > array[currentLargest]) {
            currentLargest = i;
        }
    }
    return currentLargest;
}


int countFloatingPointValues(const string array[], int n) {
    if (n <= 0) return -1;
    int numFloat = 0;
    // We iterate through the value specified in the arg 
    for (int i = 0; i < n; i++) {  // Fix loop to not go out of bounds (i < n)
        bool validFloat = true;
        int numDecimals = 0;
        // If empty string, return false 
        if (array[i].length() == 0) {
            validFloat = false;
            break;
        }
        // Otherwise, iterate through each character
        for (char c: array[i]) {
            // if character is not a number or decimal, then number cannot be a float
            if ((c >= '0' && c <= '9')  || c == '.') {
                if (c == '.' && array[i].length() == 1) {
                    validFloat = false;
                    break;
                }
                // if number has 2 decimals, then not valid float
                if (c == '.') { numDecimals ++; }
                if (numDecimals > 1) {
                    validFloat = false; 
                    break;
                }
            }
            else {
                validFloat = false; 
                break;
            }
        }
        if (validFloat == true) {
            numFloat += 1;
        }
        validFloat = true; 
        numDecimals = 0;
    }
    return numFloat;
}



bool hasNoCapitals(const string array[], int n) {
    // If all the elements in the passed array include not a single CAPITAL letter (that is, the letters A-Z), return true otherwise false. If n <= 0, return true since indeed there are no elements with a single CAPITAL letter.
    if (n <= 0) return true;
    bool capitals = true;
    // Iterate through each word
    for (int i = 0; i < n; i++) {  // Fix loop to not go out of bounds (i < n)
        // Iterate through each char
        for (char c : array[i]) {
            // If letter is in between A and Z (inclusive), then it's uppercase, not valid for has no capitals anymore
            if (c >= 'A' && c <= 'Z') {
                //cout << "has capital";
                return false;
            }
        }
    }
    return capitals;
}


int shiftLeft( string array[ ], int n, int amount, string placeholder ) {
    // For the passed array, shift all of its elements left by amount, filling in the right-most values with the placeholder value and return the number of times the placeholder value was used or return -1 if n <= 0 or amount < 0.   
    if (n <= 0 || amount < 0) return -1;
    int move = 0, index = 0;
    
    // if n - amount is not less than 0, then that's our starting point
    if (n - amount > 0) index = n - amount;
    for (int i = 0; i < index; i++) {
        array[i] = array[i+amount];
    }
    // for each time we replace an old word with place holder, add to move
    for (int i = index; i < n; i++) {
        array[i] = placeholder;
        move++;
    }
    return move;
}


int main() {
    string test1[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon"};
    string test2[5] = {"mamaBbcca", "mamaBbcca", "12.", "98.76", "tyrion"};
    string test3[6] = {"1.23", "45", "6.7", "abc", "8.9", "10.0"};
    string test4[4] = {"Zebra", "apple", "Banana", "cat"};
    string test5[5] = {"ant", "bee", "cat", "dog", "elk"};
    string test6[3] = {"", "", ""};
    string test7[1] = {"hello"};
    string test8[5] = {"zoo", "zoo", "cat", "zoo", "dog"};
    
    // test 1
    assert(locateMaximum(test1, 8) == 4);
    assert(countFloatingPointValues(test1, 6) == 0);
    assert(hasNoCapitals(test1, 8) == true);
    assert(shiftLeft(test1, 5, 2, "foo") == 2);

    // test 2
    assert(locateMaximum(test2, 0) == -1);
    assert(countFloatingPointValues(test2, 0) == -1);
    assert(hasNoCapitals(test2, 0) == true);
    assert(shiftLeft(test2, 0, 4, "foo") == -1);
    
    // test 3
    assert(locateMaximum(test3, 3) == 2);
    assert(countFloatingPointValues(test3, 6) == 5);
    assert(hasNoCapitals(test3, 6) == true);
    assert(shiftLeft(test3, 1, 3, "foo") == 1);
    
    // test 4
    assert(locateMaximum(test4, 4) == 3);
    assert(countFloatingPointValues(test4, 4) == 0);
    assert(hasNoCapitals(test4, 4) == false);
    assert(shiftLeft(test4, 4, 1, "foo") == 1);
    
    //test 5
    assert(locateMaximum(test5, 5) == 4);
    assert(countFloatingPointValues(test5, 5) == 0);
    assert(hasNoCapitals(test5, 5) == true);
    assert(shiftLeft(test5, 5, 3, "bar") == 3);

    //test 6
    assert(locateMaximum(test6, 3) == 0);
    assert(countFloatingPointValues(test6, 3) == 0);
    assert(hasNoCapitals(test6, 3) == true);
    assert(shiftLeft(test6, 3, 2, "xyz") == 2);

    //test 7 
    assert(locateMaximum(test7, 1) == 0);
    assert(countFloatingPointValues(test7, 1) == 0);
    assert(hasNoCapitals(test7, 1) == true);
    assert(shiftLeft(test7, 1, 0, "foo") == 0);

    //test 8
    assert(locateMaximum(test8, 5) == 0);
    assert(countFloatingPointValues(test8, 5) == 0);
    assert(hasNoCapitals(test8, 5) == true);
    assert(shiftLeft(test8, 5, 5, "baz") == 5);

    cout << "Finished";
    return 0;
}
