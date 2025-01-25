#include <iostream>
#include <string>

using namespace std;

int main() {
    int x;
    int sum = 0;
    cin >> x;
    while(x>0) {
        cout << (x%10) << "\n";
        sum += x%10;
        x = x%10;
    }
    cout << "Sum is " << sum;
    return 0;
}
