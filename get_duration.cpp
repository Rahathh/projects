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

// Converts hours and minutes to total minutes
int getMinutes(int hours, int minutes) {
    return hours * 60 + minutes;
}

// Approach 1: Convert to minutes and calculate the difference
void approach1(int startHour, int startMinute, int endHour, int endMinute) {
    // Convert start and end times to total minutes since midnight
    int startTimeInMinutes = getMinutes(startHour, startMinute);
    int endTimeInMinutes = getMinutes(endHour, endMinute);

    // Calculate duration in minutes
    int durationInMinutes = endTimeInMinutes - startTimeInMinutes;

    // Convert duration back to hours and minutes
    int durationHours = durationInMinutes / 60;
    int durationMinutes = durationInMinutes % 60;

    // Output the result
    cout << "Approach 1: Duration is " << durationHours << " hours and " << durationMinutes << " minutes.\n";
}


