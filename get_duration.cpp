//

/*

Author: Rahat Hassan

Course: CSCI-135

Instructor: Tong Yi

Assignment: Project 1c


Write a program 

Task A: Convert Time from 12-hour Notation to 24-hour Notation

    Step 2: Input time in 12-hour notation to a string variable

    Step 3a: Find the index of colon (:) separating hour and minute

    Step 3b: Extract hour and minute

*/
#include <iostream>
using namespace std;

int getMinutes(int hours, int minutes) {
    return hours * 60 + minutes;  // Converts hours and minutes into total minutes
}

int main() {
    int startHour, startMinute, endHour, endMinute;

    // Input start time
    cout << "Enter start time (hours minutes): ";
    cin >> startHour >> startMinute;

    // Input end time
    cout << "Enter end time (hours minutes): ";
    cin >> endHour >> endMinute;

    // Check if start time is strictly later than end time
    if (startHour > endHour || (startHour == endHour && startMinute > endMinute)) {
        cout << "invalid input" << endl;
        return -1;
    }

    // Borrow an hour if start minutes are larger than end minutes
    if (endMinute < startMinute) {
        endMinute += 60;
        endHour -= 1;  // Borrow an hour from end time
    }

    // Calculate the total duration
    int durationHours = endHour - startHour;
    int durationMinutes = endMinute - startMinute;

    // Output the duration
    cout << "Duration: " << durationHours << " hours and " << durationMinutes << " minutes" << endl;

    return 0;
}


