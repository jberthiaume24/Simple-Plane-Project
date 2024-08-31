#include "plane.h"

int main() {
    Seat SEATCHART;
    int input = 0;

    SEATCHART.readChart();

    do {
        menu(input);

        switch (input) {
            case 1: SEATCHART.displayChart(); break;
            case 2: SEATCHART.reserveSeat(); break;
            case 3: SEATCHART.cancelSeat(); break;
            case 4: SEATCHART.saveChart(); break;
            case 5: SEATCHART.statistics(); break;
            case 6: explain(); break;
            case 7: cout << "Thank You!" << endl; break;
            default: cout << "Invalid selection. Please try again." << endl; break;
        }
    } while (input != 7);

    return 0;
}
