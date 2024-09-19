//
/*
Author: Rahat Hassan
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1b

Write a program 
Task A: Convert Time from 12-hour Notation to 24-hour Notation
    Step 2: Input time in 12-hour notation to a string variable
    Step 3a: Find the index of colon (:) separating hour and minute
    Step 3b: Extract hour and minute
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string inputTime;
    
    // Step 2: Read input using getline
    cout << "Enter time (hh:mm) in 12-hour notation (for example, 12:56 AM): ";
    getline(cin, inputTime);

    // Step 3: Extract the last two characters (AM or PM)
    string period = inputTime.substr(inputTime.length() - 2);
    inputTime = inputTime.substr(0, inputTime.length() - 2); // Remove AM/PM

    // Step 4: Find the index of colon
    size_t colonIndex = inputTime.find(':');
    if (colonIndex == string::npos) {
        cout << "invalid input" << endl;
        return -1;
    }

    // Extract hour and minute
    string hourStr = inputTime.substr(0, colonIndex);
    string minuteStr = inputTime.substr(colonIndex + 1);

    // Convert to integers
    int hour = stoi(hourStr);
    int minute = stoi(minuteStr);

    // Step 5: Validate hour and minute
    if (hour < 1 || hour > 12 || minute < 0 || minute > 59) {
        cout << "invalid input" << endl;
        return -1;
    }

    // Step 6: Convert to 24-hour format
    if (period == "AM") {
        if (hour == 12) {
            hour = 0; // 12 AM is 00:00
        }
    } else if (period == "PM") {
        if (hour != 12) {
            hour += 12; // PM hours (except 12) need 12 added
        }
    } else {
        cout << "invalid input" << endl; // Optional: check for AM/PM validity
        return -1;
    }

    // Print output in 24-hour format
    printf("12-hour notation %02d:%02d %s in 24-hour notation is %02d:%02d.\n", 
           hour, minute, period.c_str(), hour, minute);
    
    return 0;
}
