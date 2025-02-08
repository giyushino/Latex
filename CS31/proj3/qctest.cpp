#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

bool not_in(char l) {
    char c[13] = { 'Q', 'p', 'd', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = 0; i < 13; i++) {
        if (l == c[i]) {
            return false;
        }
    }
    return true;
}

bool isValidQC(string results) {
    // If string is empty, return false immediately. 
    if (results.length() == 0) {
        return false;
    }
    // Declaring vectors to store the indicies of Q, p, and d
    vector<int> Qs, ps, ds, all_indicies;
    for (int i = 0; i < results.length(); i++) {
        // If we encounter a letter that is a a number or Q, p, d, then we return false 
        if (not_in(results[i]) == true) {
            return false;
        }
        if (results[i] == 'Q') {
            Qs.push_back(i);
            all_indicies.push_back(i);
        }
        else if (results[i] == 'p') {
            ps.push_back(i);
            all_indicies.push_back(i);
        }
        else if (results[i] == 'd') {
            ds.push_back(i);
            all_indicies.push_back(i);
        }
    }
    // If there's not the same of number of Q, p, and d, then return false
    if (Qs.size() != ps.size() || Qs.size() != ds.size() || ps.size() != ds.size()) {
        return false;
    }
    // If the last element in the vector corresponds with the last element in the input, then no digit was declared
    if (all_indicies.back() == results.length() - 1) {
        return false;
    }
    int Q_value = 0, Other_value = 0, otherCount = 0;
    // For each element in the vector with all the important indicies, check if there's at least once space in between them to hold a number
    for (int i = 0; i < all_indicies.size() ; i++) {
        if (all_indicies[i] + 1 == all_indicies[i + 1]) {
            return false;
        }
        // Get the number from the string as a sub string. Start index is the index we stored into the vector, the length we are searching is the next index - current index - 1
        string temp = results.substr(all_indicies[i] + 1, all_indicies[i + 1] - all_indicies[i] - 1);
        if (temp.length() > 1) {
            if (temp[0] == '0') {
                // cout << "starts with 0";
                return false;
            }
        }
        // Turn substring into int
        int num = stoi(temp);
        // For indicies corresponding with Q, if the number following is 0, return false
        if (i % 3 == 0) {
            if (num == 0) {
                return false;
            }
            Q_value = num;
        }
        // If not a Q, the value must correspond to p or d. Add it to total. 
        else {
            Other_value += num;
            otherCount++;
        }
        // Once we added the p and d together, if they don't add up to the total tests, return false
        if (otherCount == 2) {
            if (Q_value != Other_value) {
                //cout << "does not match";
                return false;
            }
            // Reset everything to 0
            otherCount = 0;
            Q_value = 0;
            Other_value = 0;
        }
    }
    return true;
}

int passQC(string results) {
    //  If string isn't valid, return -1 immediately  
    if (isValidQC(results) == false) {
        return -1;
    }
    int param = 0;
    vector<int> all_indicies;
    for (int i = 0; i < results.length(); i++) {
        if (not_in(results[i]) == true) {
            return -1;
        }
        // If ltter is Q, p, or d, add the index to the vector
        if (results[i] == 'Q' || results[i] == 'p' || results[i] == 'd') {
            all_indicies.push_back(i);
        }
    }
    // If the index corresponds to p, take the number following it and add it to param
    for (int i = 0; i < all_indicies.size(); i++) {
        if (results[all_indicies[i]] == 'p') {
            string temp = results.substr(all_indicies[i] + 1, all_indicies[i + 1] - all_indicies[i] - 1);
            int num = stoi(temp);
            param += num;
        }

    }
    return param;
}

int defectQC(string results) {
    // Same exact logic as passQC, except we search for d's 
    if (isValidQC(results) == false) {
        return -1;
    }
    int defect = 0;
    vector<int> all_indicies;
    for (int i = 0; i < results.length(); i++) {
        if (not_in(results[i]) == true) {
            return -1;
        }
        if (results[i] == 'Q' || results[i] == 'p' || results[i] == 'd') {
            all_indicies.push_back(i);
        }
    }
    for (int i = 0; i < all_indicies.size(); i++) {
        if (results[all_indicies[i]] == 'd') {
            string temp = results.substr(all_indicies[i] + 1, all_indicies[i + 1] - all_indicies[i] - 1);
            int num = stoi(temp);
            defect += num;
        }

    }
    return defect;
}

int totalQC(string results) {
    // Same logic as passQC, except we only search for Q's
    if (isValidQC(results) == false) {
        return -1;
    }
    int total = 0;
    vector<int> all_indicies;
    for (int i = 0; i < results.length(); i++) {
        if (not_in(results[i]) == true) {
            return -1;
        }
        if (results[i] == 'Q' || results[i] == 'p' || results[i] == 'd') {
            all_indicies.push_back(i);
        }
    }
    for (int i = 0; i < all_indicies.size(); i++) {
        if (results[all_indicies[i]] == 'Q') {
            string temp = results.substr(all_indicies[i] + 1, all_indicies[i + 1] - all_indicies[i] - 1);
            int num = stoi(temp);
            total += num;
        }

    }
    return total;
}

int batches(string results) {
    // Count the number of times we see Q to count the batches
    if (isValidQC(results) == false) {
        return -1;
    }
    int batches = 0;
    for (char c : results) {
        if (c == 'Q') {
            batches++;
        }
    }
    return batches;
}

int main() {
    cout << "finished!";
    return 0;
}
