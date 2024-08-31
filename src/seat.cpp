#include "plane.h"
#include <iostream>
#include <fstream>
#include <cctype>  // For toupper

using namespace std;

// Display the seat chart
void Seat::displayChart() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            cout << seatChart[i][j] << " ";  // Print each seat label
        }
        cout << endl;
    }
}

// Reserve a seat
void Seat::reserveSeat() {
    int row;
    char letter;
    int locLetter = -1;  // Default to -1 to handle invalid cases

    cout << "Please enter the seat you want to reserve (e.g., 1A): ";
    cin >> row >> letter;
    letter = toupper(letter);

    // Map seat letters to their indices
    switch (letter) {
        case 'A': locLetter = 1; break; // Seat A is in the second position
        case 'B': locLetter = 2; break; // Seat B is in the third position
        case 'C': locLetter = 3; break; // Seat C is in the fourth position
        case 'D': locLetter = 4; break; // Seat D is in the fifth position
        default:
            cout << "Invalid seat letter" << endl;
            return;
    }

    // Ensure row number is within valid range
    if (row < 1 || row > 15 || locLetter < 1 || locLetter > 4) {
        cout << "Invalid seat number or letter" << endl;
        return;
    }

    // Check if the seat is available
    if (seatChart[row - 1][locLetter] != "X") {
        seatChart[row - 1][locLetter] = "X"; // Reserve the seat
        cout << "Seat " << row << letter << " reserved successfully." << endl;
    } else {
        cout << "Sorry, this seat has already been reserved" << endl;
    }
}


// Cancel a reservation
void Seat::cancelSeat() {
    int row;
    char letter;
    int locLetter = -1;  // Default to -1 to handle invalid cases

    cout << "Please enter the seat you want to cancel (e.g., 1A): ";
    cin >> row >> letter;
    letter = toupper(letter);

    // Map seat letters to their indices
    switch (letter) {
        case 'A': locLetter = 1; break; // Seat A is in the second position
        case 'B': locLetter = 2; break; // Seat B is in the third position
        case 'C': locLetter = 3; break; // Seat C is in the fourth position
        case 'D': locLetter = 4; break; // Seat D is in the fifth position
        default:
            cout << "Invalid seat letter" << endl;
            return;
    }

    // Ensure row number is within valid range and locLetter is valid
    if (row < 1 || row > 15 || locLetter < 1 || locLetter > 4) {
        cout << "Invalid seat number or letter" << endl;
        return;
    }

    // Check if the seat is reserved
    if (seatChart[row - 1][locLetter] == "X") {
        // Restore the seat to its original letter
        seatChart[row - 1][locLetter] = string(1, letter);
        cout << "The reservation has been cancelled successfully." << endl;
    } else {
        cout << "This seat is already free." << endl;
    }
}

// Save the seat chart to a file
void Seat::saveChart() {
    string userInput2;
    ofstream outFile;

    cout << "Please enter the name of the file (include the extension): ";
    cin >> userInput2;
    outFile.open(userInput2);

    if (outFile.fail()) {
        cerr << "The output file failed to open" << endl;
        return;
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            outFile << seatChart[i][j] << " ";
        }
        outFile << endl;
    }
}

// Display seat statistics
void Seat::statistics() {
    int availableSeats = 0;
    int totalSeats = 15 * 4;  // Total number of seats, since there are 15 rows and 4 seats per row

    // Count available seats
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j < 5; j++) {  // Start from 1 to skip the row number
            if (seatChart[i][j] == "A" || seatChart[i][j] == "B" || seatChart[i][j] == "C" || seatChart[i][j] == "D") {
                availableSeats++;
            }
        }
    }

    int reservedSeats = totalSeats - availableSeats;

    cout << "Number of Available Seats: " << availableSeats << endl;
    cout << "Percentage of Reserved Seats: " << (reservedSeats * 100.0 / totalSeats) << "%" << endl;

    // List available aisle seats
    cout << "List of Available Aisle Seats: ";
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j < 5; j++) {  // Start from 1 to skip the row number
            if (seatChart[i][j] == "B" || seatChart[i][j] == "C") {
                cout << i + 1 << seatChart[i][j] << " ";
            }
        }
    }
    cout << endl;

    // List available window seats
    cout << "List of Available Window Seats: ";
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j < 5; j++) {  // Start from 1 to skip the row number
            if (seatChart[i][j] == "A" || seatChart[i][j] == "D") {
                cout << i + 1 << seatChart[i][j] << " ";
            }
        }
    }
    cout << endl;
}
