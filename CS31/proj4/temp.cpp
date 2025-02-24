#include <iostream>
#include <string>
#include <cassert>
using namespace std; 


int locateMaximum(const string array[], int n) {
    // Returns the index of largest item found in the passed array of -1 if n <= 0
    if (n <= 0) return -1;
    int currentLargest = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] > array[currentLargest]) {
            currentLargest = i;
        }
    }
    return currentLargest;
}


int countFloatingPointValues(const string array[], int n) {
    if (n <= 0) return -1;
    int numFloat = 0; 
    for (int i = 0; i < n; i++) {  // Fix loop to not go out of bounds (i < n)
        bool validFloat = true;
        int numDecimals = 0;
        if (array[i].length() == 0) {
            validFloat = false;
            break;
        }
        for (char c: array[i]) {
            if ((c >= '0' && c <= '9')  || c == '.') {
                if (c == '.' && array[i].length() == 1) {
                    validFloat = false;
                    break;
                }
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
            cout << array[i] << "valid float \n";
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
    for (int i = 0; i < n; i++) {  // Fix loop to not go out of bounds (i < n)
        for (char c : array[i]) {
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
    if (n - amount > 0) index = n - amount;
    for (int i = 0; i < index; i++) {
        array[i] = array[i+amount];
    }
    for (int i = index; i < n; i++) {
        array[i] = placeholder;
        move++;
    }
    /*
    assert(locateMaximum(nums, 6) == 4);            // "45" is max
    for (int i = 0; i < 5; i++) {
        cout << array[i] << endl;
    } 
    */
    return move;
}










int main2() {
    // Test arrays from assignment
    string folks[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon"};
    string data[5] = {"mamaBbcca", "mamaBbcca", "12.", "98.76", "tyrion"};

    // New test arrays
    string nums[6] = {"1.23", "45", "6.7", "abc", "8.9", "10.0"};
    string mixed[4] = {"Zebra", "apple", "Banana", "cat"};
    string sorted[5] = {"ant", "bee", "cat", "dog", "elk"};
    string empty[3] = {"", "", ""};
    string single[1] = {"hello"};
    string duplicates[5] = {"zoo", "zoo", "cat", "zoo", "dog"};

    // 50 test cases with asserts
    // locateMaximum tests (12 cases)
    assert(locateMaximum(folks, 8) == 4);           // "tyrion" is max
    assert(locateMaximum(data, 5) == 4);            // "tyrion" is max
    assert(locateMaximum(nums, 6) == 3);            // "45" is max
    assert(locateMaximum(mixed, 4) == 3);           // "Zebra" is max (uppercase first)
    assert(locateMaximum(sorted, 5) == 4);          // "elk" is max
    assert(locateMaximum(empty, 3) == 0);           // "" is max (all same)
    assert(locateMaximum(single, 1) == 0);          // "hello" is max
    assert(locateMaximum(duplicates, 5) == 0);      // "zoo" at 0 (first occurrence)
    assert(locateMaximum(folks, 3) == 0);           // "samwell" in first 3
    assert(locateMaximum(nums, 0) == -1);           // empty case
    assert(locateMaximum(mixed, 2) == 1);           // "Zebra" in first 2
    assert(locateMaximum(sorted, 1) == 0);          // "ant" in first 1


    // hasNoCapitals tests (12 cases)
    assert(hasNoCapitals(folks, 8) == true);              // all lowercase
    assert(hasNoCapitals(data, 5) == false);              // "mamaBbcca" has B
    assert(hasNoCapitals(nums, 6) == true);               // all lowercase
    assert(hasNoCapitals(mixed, 4) == false);             // "Zebra" has Z
    assert(hasNoCapitals(sorted, 5) == true);             // all lowercase
    assert(hasNoCapitals(empty, 3) == true);              // no capitals
    assert(hasNoCapitals(single, 1) == true);             // "hello" no caps
    assert(hasNoCapitals(folks, 0) == true);              // empty case
    assert(hasNoCapitals(mixed, 1) == false);             // "Zebra" has Z
    assert(hasNoCapitals(sorted, 2) == true);             // "ant", "bee" no caps
    string caps[2] = {"ABC", "def"};
    assert(hasNoCapitals(caps, 2) == false);              // "ABC" has caps
    string lowercase[3] = {"xyz", "abc", "pqr"};
    assert(hasNoCapitals(lowercase, 3) == true);          // all lowercase

    // shiftLeft tests (13 cases)
    string temp1[5] = {"a", "b", "c", "d", "e"};
    assert(shiftLeft(temp1, 5, 2, "x") == 2 && temp1[0] == "c" && temp1[4] == "x");
    string temp2[4] = {"1", "2", "3", "4"};
    assert(shiftLeft(temp2, 4, 4, "z") == 4 && temp2[0] == "z" && temp2[3] == "z");
    string dataCopy[5] = {"mamaBbcca", "mamaBbcca", "12.", "98.76", "tyrion"};
    assert(shiftLeft(dataCopy, 5, 2, "foo") == 2 && dataCopy[2] == "tyrion" && dataCopy[4] == "foo");
    string folksCopy[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon"};
    assert(shiftLeft(folksCopy, 8, 10, "bar") == 8 && folksCopy[0] == "bar" && folksCopy[7] == "bar");
    string numsCopy[6] = {"1.23", "45", "6.7", "abc", "8.9", "10.0"};
    assert(shiftLeft(numsCopy, 6, 0, "none") == 0 && numsCopy[0] == "1.23");
    assert(shiftLeft(temp1, 0, 3, "y") == -1);           // n <= 0
    assert(shiftLeft(temp2, 4, -1, "w") == -1);          // amount < 0
    string temp3[3] = {"cat", "dog", "bird"};
    assert(shiftLeft(temp3, 3, 1, "fish") == 1 && temp3[0] == "dog" && temp3[2] == "fish");
    string temp4[2] = {"yes", "no"};
    assert(shiftLeft(temp4, 2, 2, "maybe") == 2 && temp4[0] == "maybe");
    string temp5[6] = {"p", "q", "r", "s", "t", "u"};
    assert(shiftLeft(temp5, 6, 3, "x") == 3 && temp5[0] == "s" && temp5[5] == "x");
    string temp6[1] = {"solo"};
    assert(shiftLeft(temp6, 1, 1, "done") == 1 && temp6[0] == "done");
    string temp7[4] = {"w", "x", "y", "z"};
    assert(shiftLeft(temp7, 4, 3, "a") == 3 && temp7[0] == "z" && temp7[3] == "a");
    string temp8[5] = {"m", "n", "o", "p", "q"};
    assert(shiftLeft(temp8, 5, 4, "b") == 4 && temp8[0] == "q" && temp8[4] == "b");
    
    return 0;
}
