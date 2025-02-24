#include <iostream>
#include <string>

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


int main() {
    cout << locateMaximum(string test[5] = {"", "", "", "", ""}, 5);
}
