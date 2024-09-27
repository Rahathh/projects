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
#include <string>

using namespace std;

// Converts hours and minutes to total minutes since midnight
int getMinutesFromMidnight(int hours, int minutes) {
    return hours * 60 + minutes;
}

int main() {
    string startTime, endTime;
    int startHour, startMinute, endHour, endMinute;

    // Input start time in 24-hour format
    cout << "Enter start time (hh:mm): ";
    cin >> startTime;
    
    // Input end time in 24-hour format
    cout << "Enter end time (hh:mm): ";
    cin >> endTime;

    // Extract hours and minutes from start time
    startHour = stoi(startTime.substr(0, startTime.find(':')));
    startMinute = stoi(startTime.substr(startTime.find(':') + 1));

    // Extract hours and minutes from end time
    endHour = stoi(endTime.substr(0, endTime.find(':')));
    endMinute = stoi(endTime.substr(endTime.find(':') + 1));

    // Validate the time inputs
    if (startHour < 0 || startHour > 23 || startMinute < 0 || startMinute > 59 ||
        endHour < 0 || endHour > 23 || endMinute < 0 || endMinute > 59) {
        cout << "invalid input" << endl;
        return -1;
    }

    // Convert start and end times to total minutes since midnight
    int startTimeInMinutes = getMinutesFromMidnight(startHour, startMinute);
    int endTimeInMinutes = getMinutesFromMidnight(endHour, endMinute);

    // Handle cases where the end time is on the next day
    if (endTimeInMinutes < startTimeInMinutes) {
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






