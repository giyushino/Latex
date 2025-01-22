#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;
// Main function to control inputs and outputs
int main() {
    string first_name, day; // Initialize the name of the customer and day of the week as strings
    int num_cups = 0; // Initialize the number of cups of coffee purchased as an integer
    double total_price = 0; // Initialize the final price as a double data type to support decimals
    char coffee[2], extra[2]; // Initialize the type of coffee and extra items as chars with length of 1 
    bool first_name_flag = false, day_flag = false, num_cups_flag = false, coffee_flag = false, extra_flag = false; // If these flags are fault, there was nothing wrong with the input. If true, we know there was something wrong with user input.
    cout << "Input:\nCustomer's first name: ";
    cin >> first_name;
    if (!isupper(first_name[0])) {
        first_name_flag = true;
    } 
    cout << "Number of cups: ";
    cin >> num_cups;
    if (num_cups < 0) {
        num_cups_flag = true;
    } else if (cin.fail()) {
        num_cups_flag = true;
        cin.clear();
    }     
    cin.ignore(10000,'\n');
    cout << "Type of coffee (r=regular,d=decaf): ";
    cin.getline(coffee, 2);
    if (coffee[0] != 'r') {
        if (coffee[0] != 'd'){
            coffee_flag = true;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000,'\n');
            }
        }
    }

    cout << "Any extra items? (y/n): ";
    cin.getline(extra, 2);
    if (extra[0] != 'y') {
        if (extra[0] != 'n'){
            extra_flag = true;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000,'\n');
            }
        }
    }

    cout << "Day of the week: ";
    cin >> day;
    if (day != "Monday") {
        if (day != "Tuesday") {
            if (day != "Wednesday") {
                if (day != "Thursday") {
                    if (day != "Friday") {
                        if (day != "Saturday") {
                            if (day != "Sunday") {
                                day_flag = true;
                                if (cin.fail()) {
                                    cin.clear();
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "\nOutput:\n---\n";
    //cout << "First name flag: " << first_name_flag << " Day flag: " << day_flag << " Cup flag: " << num_cups_flag << " coffee flag: " << coffee_flag << " extra_flag: " << extra_flag;
    if (first_name_flag == 1) {
        cout << "The first name must start with an uppercase letter."; 
        exit(0);
    }
    if (num_cups_flag == 1) {
        cout << "The number of cups must be positive";
        exit(0);
    }
    if (coffee_flag == 1) {
        cout << "You must enter r or d";
        exit(0);
    }
    if (extra_flag == 1) {
        cout << "You must enter y or n";
        exit(0);
    }
    if (day_flag == 1) {
        cout << "You must enter a valid day of the week";
        exit(0);
    }
    if (coffee[0] == 'r') {
        total_price = num_cups * 4.00;
    }
    if (coffee[0] == 'd') {
        total_price = num_cups * 4.50;
    }
    if (extra[0] == 'y') {
        total_price += 1.95;
    }
    if (day == "Wednesday") {
        total_price = total_price * 0.85;
    }

    cout << "The total charge for " <<  first_name << " is $" << fixed << setprecision(2) << total_price;
    
    return 0; 
}
