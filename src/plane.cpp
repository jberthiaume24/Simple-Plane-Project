#include "plane.h"

// Read chart from file
void Plane::readChart() {
    inFile.open("data/chartIn.txt");
    if (inFile.fail()) {
        cerr << "Error Opening File" << endl;
        return;
    }

    int rowNumber;
    string seat;

    for (int i = 0; i < 15; i++) {
        inFile >> rowNumber;       // Read row number
        seatChart[i][0] = to_string(rowNumber); // Store row number in the first column
        
        for (int j = 1; j < 5; j++) {  // Read the four seat labels
            inFile >> seat;
            seatChart[i][j] = seat;    // Store seat label in subsequent columns
        }
    }

    inFile.close();
}
