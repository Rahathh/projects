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

// Converts hours and minutes to total minutes since midnight
int getMinutesFromMidnight(int hours, int minutes) {
    return hours * 60 + minutes;
}

int main() {
    int startHour, startMinute, endHour, endMinute;

    // Input start time in 24-hour format
    cout << "Enter start time (hours minutes): ";
    cin >> startHour >> startMinute;

    // Input end time in 24-hour format
    cout << "Enter end time (hours minutes): ";
    cin >> endHour >> endMinute;

    // Convert start and end times to total minutes since midnight
    int startTimeInMinutes = getMinutesFromMidnight(startHour, startMinute);
    int endTimeInMinutes = getMinutesFromMidnight(endHour, endMinute);

    // Check if start time is later than end time
    if (startTimeInMinutes > endTimeInMinutes) {
        cout << "invalid input" << endl;
        return -1;
    }

    // Calculate the duration in minutes
    int durationInMinutes = endTimeInMinutes - startTimeInMinutes;

    // Convert duration into hours and minutes
    int durationHours = durationInMinutes / 60;
    int durationMinutes = durationInMinutes % 60;

    // Output the result
    cout << "Duration: " << durationHours << " hours and " << durationMinutes << " minutes" << endl;

    return 0;
}



