#include <iostream>
#include <limits>  // For std::numeric_limits
using namespace std;

// Display menu and get user input
void menu(int &userInput) {
    while (true) {
        cout << "------------------------------------------------------" << endl;
        cout << "Menu" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "1. Display Seat Chart" << endl;
        cout << "2. Reserve Seat" << endl;
        cout << "3. Cancel Reservation" << endl;
        cout << "4. Save Seat Chart to File" << endl;
        cout << "5. Statistics" << endl;
        cout << "6. Help" << endl;
        cout << "7. Quit" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Your Selection: ";

        // Check if the input is an integer
        if (cin >> userInput) {
            // Check if the input is within the valid range
            if (userInput >= 1 && userInput <= 7) {
                break; // Valid input, exit the loop
            } else {
                cout << "Error: Please enter a number between 1 and 7." << endl;
            }
        } else {
            // If input is not an integer, clear the error flag and ignore invalid input
            cout << "Error: Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }
}
