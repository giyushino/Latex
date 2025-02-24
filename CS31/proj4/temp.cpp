#include <iostream>
#include <string>
using namespace std; 


int locateMaximum(const string array[], int n) {
    // Returns the index of largest item found in the passed array of -1 if n <= 0
    if (n <= 0) return -1;
    int currentLargest;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            currentLargest = i;
        }
        else {
            if (array[i] > array[currentLargest]) {
                currentLargest = i;
            }
        }
    }
    cout << array[currentLargest] << " " << currentLargest;
    return currentLargest;
}


int countFloatingPointValues(const string array[], int n) {
    // Returns the number of numerical floating points values found in the passed array or -1 if n <= 0.
    if (n <= 0) return -1;
    int numFloat = 0;
    for (int i = 0; i < n; i++) {  // Fix loop to not go out of bounds (i < n)
        int tempCount = -1;
        bool validFloat = true;
        for (char c : array[i]) {
            tempCount += 1;
            // Check if the character is a digit (between 0 and 9) or a decimal point ('.')
            if (c < '0' || c > '9') {
                if (c == '.') {  // It's a decimal point
                    if (tempCount != array[i].length() - 1) {
                        validFloat = false;
                    }
                } else {
                    // If it's not a digit or a decimal point, then it's not a valid float
                    validFloat = false;
                    break;  // No need to check further for this string
                }
            }
        }
        if (validFloat) {
            cout << array[i] << " is valid" << endl;
            numFloat += 1;  // Increment count if it's a valid float
        }
        else {
            cout << array[i] << " is not valid" << endl;
        }
    }
    //cout << numFloat;  // Debug print
    return numFloat;  // Return the number of valid floating-point values
}


bool hasNoCapitals(const string array[], int n) {
    // If all the elements in the passed array include not a single CAPITAL letter (that is, the letters A-Z), return true otherwise false. If n <= 0, return true since indeed there are no elements with a single CAPITAL letter.
    if (n <= 0) return -1;
    bool capitals = false;
    for (int i = 0; i < n; i++) {  // Fix loop to not go out of bounds (i < n)
        cout << array[i] << endl;
        for (char c : array[i]) {
            if (c >= 'A' && c <= 'Z') {
                //cout << "has capital";
                capitals = true;
            }
        }
        if (capitals == true) break;
    }
    //cout << capitals;
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
    for (int i = 0; i < 5; i++) {
        cout << array[i] << endl;
    }
    return move;
}




int main() {
    //string test[7] = {"98.484", "1", "2", "00001", "012000.", "1.1", "222"};
    //countFloatingPointValues(test, 7);
    //string data[5] = { "mamabBcca", "mamabbcca", "tyrion" };
    //hasNoCapitals(data, 5);
    string test[8] = {"one", "two", "three", "four", "five", "six", "seven", "eight"};
    string name[5]={"Andrew","Bethany","Christie","Danny","Edward"};
    shiftLeft(name, 3, 2, "foo");
    return 0;
}
