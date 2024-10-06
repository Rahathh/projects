//
/*
Author: Rahat Hassan
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1d

Write a program 
Task A: Convert Time from 12-hour Notation to 24-hour Notation
    Step 2: Input time in 12-hour notation to a string variable
    Step 3a: Find the index of colon (:) separating hour and minute
    Step 3b: Extract hour and minute


*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function declaration
void hours_minutes_in_24h(string str, int& hours, int& minutes);
int duration(string str);

#ifndef UNIT_TEST
int main() {
    // Step 1: Enter the file name
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;

    // Step 2: Enter the priority
    string searchPriority;
    cout << "Enter priority: ";
    cin >> searchPriority;

    // Step 3: Open the file
    ifstream fin(filename);
    if (!fin) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    // Step 4: Skip the first line (headers)
    string header;
    getline(fin, header);

    string time, activity, priority;
    int totalDuration = 0;

    // Step 5: Read data from the file
    while (getline(fin, time, ',')) {
        getline(fin, activity, ',');
        getline(fin, priority); // No comma at the end

        // Step 6: Process only if the priority matches
        if (priority == searchPriority) {
            int activityDuration = duration(time);
            totalDuration += activityDuration;

            int hours = activityDuration / 60;
            int minutes = activityDuration % 60;

            cout << time << "," << activity << "," << priority 
                 << " hours and " << hours << " minutes" << endl;
        }
    }

    // Step 7: Close the file
    fin.close();

    // Step 8: Print total duration
    cout << "Total duration: " << totalDuration / 60 << " hours and " 
         << totalDuration % 60 << " minutes" << endl;

    return 0;
}
#endif

// Purpose: Convert 12-hour time notation to 24-hour notation
void hours_minutes_in_24h(string str, int& hours, int& minutes) {
    size_t colonIndex = str.find(':');
    string period = str.substr(str.length() - 2);
    string hourStr = str.substr(0, colonIndex);
    string minuteStr = str.substr(colonIndex + 1, 2); // Assumes mm is always 2 digits

    hours = stoi(hourStr);
    minutes = stoi(minuteStr);

    if (period == "am") {
        if (hours == 12) {
            hours = 0; // 12 AM is 00:00
        }
    } else { // pm
        if (hours != 12) {
            hours += 12; // PM hours (except 12) need 12 added
        }
    }
}

// Let time be a string using dash symbol '-' to separate two times in 12-hour notation
int duration(string str) {
    size_t dashIndex = str.find('-');
    string startTimeStr = str.substr(0, dashIndex);
    string endTimeStr = str.substr(dashIndex + 1);

    int startHour, startMinute, endHour, endMinute;

    // Convert both times to 24-hour notation
    hours_minutes_in_24h(startTimeStr, startHour, startMinute);
    hours_minutes_in_24h(endTimeStr, endHour, endMinute);

    // Calculate the total minutes from midnight for both times
    int startTotalMinutes = startHour * 60 + startMinute;
    int endTotalMinutes = endHour * 60 + endMinute;

    return endTotalMinutes - startTotalMinutes; // Duration in minutes
}

