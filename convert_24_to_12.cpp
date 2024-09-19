
/* 
Author: Rahat Hassan
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1a

Write a program 
Task A: Convert Time from 24-hour Notation to 12-hour Notation
    Step 2: Input time in 24-hour notation to a string variable
    Step 3a: Find the index of colon (:) separating hour and minute
    Step 3b: Extract hour and minute

 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Step 2: Input time in 24-hour notation to a string variable
    cout << "Enter time (hh:mm) in 24-hour notation (for example, 12:56): ";
    string time24;
    getline(cin, time24); // Use getline to read the entire input line

    // Step 3a: Find the index of colon (:) separating hour and minute
    int colonIndex = time24.find(':');
    if (colonIndex == string::npos) {
        cout << "invalid format" << endl;
        return -1;
    }

    // Step 3b: Extract hour and minute
    string hourStr = time24.substr(0, colonIndex);
    string minuteStr = time24.substr(colonIndex + 1);

    // Step 3c: Convert strings to integers
    int hour = stoi(hourStr);
    int minute = stoi(minuteStr);

    // Step 4: Validate hour and minute
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        cout << "invalid format" << endl;
        return -1;
    }

    // Step 5: Prepare output for 12-hour notation
    string period = "AM";
    int hour12;

    if (hour == 0) {
        hour12 = 12; // Midnight case
    }
    else if (hour == 12) {
        hour12 = 12; // Noon case
        period = "PM";
    }
    else if (hour > 12) {
        hour12 = hour - 12; // Convert to 12-hour format for PM
        period = "PM";
    }
    else {
        hour12 = hour; // Keep as is for AM
    }

    // Step 6: Output the result
    cout << "24-hour notation " << time24 << " in 12-hour notation is "
        << hour12 << ":" << (minute < 10 ? "0" : "") << minute << period << endl;

    return 0;
}
