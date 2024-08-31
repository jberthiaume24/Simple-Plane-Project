#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes
void explain();
void menu(int &);

// Class Declarations
class Plane {
public:
    string seatChart[15][5];  // 2D array to store seat chart data
    void readChart();         // Method to read the seat chart from a file

protected:
    ifstream inFile;          // Input file stream to read from files
};

class Seat : public Plane {
public:
    void displayChart();     // Method to display the seat chart
    void reserveSeat();      // Method to reserve a seat
    void cancelSeat();       // Method to cancel a reservation
    void saveChart();        // Method to save the seat chart to a file
    void statistics();       // Method to display seat statistics
};
