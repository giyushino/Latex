#include <iostream> 
#include <cctype>
#include <iomanip>
#include <string>

using namespace std;
// Main function to control inputs and outputs
int main() {
    // Declare variables for later use
    string first_name, day; 
    int num_cups = 0; 
    double total_price = 0; 
    char coffee[2], extra[2];

    // Method accept all inputs and still check for errors. If error in user input is found, flag will be set to true.
    bool first_name_flag = false, day_flag = false, num_cups_flag = false, coffee_flag = false, extra_flag = false; 

    // Ask user for first name
    cout << "Input:\nCustomer's first name: ";
    getline(cin, first_name);
    // Check if first letter is uppercase using isupper() function
    if (!isupper(first_name[0])) {
        first_name_flag = true;
    }
    // Ask user for number of cups
    cout << "Number of cups: ";
    cin >> num_cups;
    // If number of cups is less than 0, or if error occurs, set flag to true. Ignore error flag in buffer
    if (num_cups < 0) {
        num_cups_flag = true;
    } else if (cin.fail()) {
        num_cups_flag = true;
        cin.clear();
    }     
    cin.ignore(10000,'\n');
    // Ask user for type of coffee
    cout << "Type of coffee (r=regular,d=decaf): ";
    cin.getline(coffee, 2);
    // If coffee type is not r or d, set flag to true. Ignore error flag in buffer
    if (coffee[0] != 'r' && coffee[0] != 'd') {
        coffee_flag = true;
        if (cin.fail()) { 
            cin.clear();
            cin.ignore(10000,'\n');   
        }   
    }
    // Ask user if they want extra items
    cout << "Any extra items? (y/n): ";
    cin.getline(extra, 2);
    // If extra item is not y or n, set flag to true. Ignore error flag in buffer
    if (extra[0] != 'y' && extra[0] != 'n') {
        extra_flag = true;
       if (cin.fail()) { 
            cin.clear();
            cin.ignore(10000,'\n');   
        } 
    }
    
    // If day entered is not valid day with proper capitalization, set flag to true 
    cout << "Day of the week: ";
    cin >> day;
    if (day != "Monday" && day != "Tuesday" && day != "Wednesday" && day != "Thursday" && day != "Friday" && day != "Saturday" && day != "Sunday") {
        day_flag = true;
    }
    cout << "\nOutput:\n---\n";
    // Go through each flag. The first flag that is true will output the error message and exit the program
    if (first_name_flag == 1) {
        cout << "The first name must start with an uppercase letter."; 
        exit(0);
    }
    if (num_cups_flag == 1) {
        cout << "The number of cups must be positive.";
        exit(0);
    }
    if (coffee_flag == 1) {
        cout << "You must enter r or d";
        exit(0);
    }
    if (extra_flag == 1) {
        cout << "You must enter y or n.";
        exit(0);
    }
    if (day_flag == 1) {
        cout << "You must enter a valid day of the week.";
        exit(0);
    }
    // If none of the flags are true, calculate and output the total charge!
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
    // Output the total charge
    cout << "The total charge for " <<  first_name << " is $" << fixed << setprecision(2) << total_price;
    return 0;  
}
