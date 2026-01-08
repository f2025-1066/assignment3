
#include "university.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Display Main Menu
void displayMenu() {
    cout << "\n=========== UNIVERSITY UTILITY PORTAL ===========" << endl;
    cout << "1. View Fee Status" << endl;
    cout << "2. View Attendance Status" << endl;
    cout << "3. View GPA Status" << endl;
    cout << "4. Exit" << endl;
    cout << "=================================================" << endl;
    cout << "Enter your choice: ";
}

// Function 1: Fee Status
void feeStatusFunction() {
    double totalFee, paidAmount, remainingBalance;

    cout << "\n--- FEE STATUS ---" << endl;
    
    // Input total fee
    cout << "Enter total semester fee: Rs ";
    cin >> totalFee;
    
    // Validation for total fee
    while (totalFee < 0) {
        cout << "Invalid amount! Fee cannot be negative. Enter again: Rs ";
        cin >> totalFee;
    }

    // Input paid amount
    cout << "Enter amount already paid: Rs ";
    cin >> paidAmount;
    
    // Validation for paid amount
    while (paidAmount < 0 || paidAmount > totalFee) {
        cout << "Invalid amount! Paid amount cannot be negative or exceed total fee." << endl;
        cout << "Enter again: Rs ";
        cin >> paidAmount;
    }

    // Calculate remaining balance
    remainingBalance = totalFee - paidAmount;

    // Display fee details
    cout << "\n--- Fee Details ---" << endl;
    cout << "Total Fee:         Rs " << fixed << setprecision(2) << totalFee << endl;
    cout << "Paid Amount:       Rs " << paidAmount << endl;
    cout << "Remaining Balance: Rs " << remainingBalance << endl;

    // Display status
    if (remainingBalance == 0) {
        cout << "\nStatus: Fee Cleared ✓" << endl;
    } else {
        cout << "\nStatus: Outstanding Balance - Rs " << remainingBalance << " due" << endl;
    }
}

// Function 2: Attendance Status
void attendanceStatusFunction() {
    int totalDays, daysAttended;
    double attendancePercentage;

    cout << "\n--- ATTENDANCE STATUS ---" << endl;
    
    // Input total working days
    cout << "Enter total number of working days: ";
    cin >> totalDays;
    
    // Validation for total days
    while (totalDays <= 0) {
        cout << "Invalid input! Total days must be positive. Enter again: ";
        cin >> totalDays;
    }

    // Input days attended
    cout << "Enter number of days attended: ";
    cin >> daysAttended;
    
    // Validation for days attended
    while (daysAttended < 0 || daysAttended > totalDays) {
        cout << "Invalid input! Days attended cannot be negative or exceed total days." << endl;
        cout << "Enter again: ";
        cin >> daysAttended;
    }

    // Calculate attendance percentage
    attendancePercentage = (static_cast<double>(daysAttended) / totalDays) * 100;

    // Display attendance details
    cout << "\n--- Attendance Details ---" << endl;
    cout << "Total Working Days: " << totalDays << endl;
    cout << "Days Attended:      " << daysAttended << endl;
    cout << "Attendance:         " << fixed << setprecision(2) << attendancePercentage << "%" << endl;

    // Display status based on percentage
    cout << "\nStatus: ";
    if (attendancePercentage >= 85) {
        cout << "Excellent ✓" << endl;
    } else if (attendancePercentage >= 70) {
        cout << "Satisfactory" << endl;
    } else {
        cout << "Short Attendance - Warning " << endl;
    }
}

// Function 3: GPA Status
void gpaStatusFunction() {
    const int NUM_SUBJECTS = 5;
    int marks[NUM_SUBJECTS];
    double grades[NUM_SUBJECTS];
    double cgpa = 0.0;

    cout << "\n--- GPA STATUS ---" << endl;
    
    // Input marks for 5 subjects
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Enter marks for Subject " << (i + 1) << " (0-100): ";
        cin >> marks[i];
        
        // Validation for marks
        while (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid marks! Must be between 0 and 100. Enter again: ";
            cin >> marks[i];
        }

        // Convert marks to GPA
        if (marks[i] >= 90) {
            grades[i] = 4.0;
        } else if (marks[i] >= 80) {
            grades[i] = 3.5;
        } else if (marks[i] >= 70) {
            grades[i] = 3.0;
        } else if (marks[i] >= 60) {
            grades[i] = 2.5;
        } else if (marks[i] >= 50) {
            grades[i] = 2.0;
        } else {
            grades[i] = 0.0;
        }

        // Add to CGPA calculation
        cgpa += grades[i];
    }

    // Calculate average CGPA
    cgpa = cgpa / NUM_SUBJECTS;

    // Display individual subject GPAs
    cout << "\n--- Individual Subject GPAs ---" << endl;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Subject " << (i + 1) << ": Marks = " << marks[i] 
             << " | GPA = " << fixed << setprecision(1) << grades[i] << endl;
    }

    // Display final CGPA
    cout << "\n--- Final CGPA ---" << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;

    // Display academic status
    cout << "\nStatus: ";
    if (cgpa < 2.0) {
        cout << "Academic Warning " << endl;
    } else {
        cout << "Good Academic Standing " << endl;
    }
}
