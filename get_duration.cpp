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

    // Calculate the total minutes from midnight for both times
    int startTimeInMinutes = getMinutes(startHour, startMinute);
    int endTimeInMinutes = getMinutes(endHour, endMinute);

    // Calculate the duration in minutes
    int durationInMinutes = endTimeInMinutes - startTimeInMinutes;

    // Extract hours and minutes from the duration
    int durationHours = durationInMinutes / 60;
    int durationMinutes = durationInMinutes % 60;

    // Output the duration
    cout << "Duration: " << durationHours << " hours and " << durationMinutes << " minutes" << endl;

    return 0;
}


