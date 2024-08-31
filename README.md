# **Plane Reservation System**

## **Project Overview**

The Plane Reservation System is a simple C++ application designed to manage and display seating arrangements for a plane. It allows users to reserve and cancel seats, view seating charts, save seat charts to a file, and view statistics about seat availability.

## **Features**

- **Display Seat Chart**: Shows the current seating arrangement.
- **Reserve Seat**: Allows users to reserve a specific seat.
- **Cancel Reservation**: Allows users to cancel a seat reservation.
- **Save Seat Chart to File**: Saves the current seat chart to a file.
- **View Statistics**: Displays statistics on available and reserved seats, including lists of available aisle and window seats.

## **Project Structure**

- **src/ main.cpp :** Entry point of the application. 
- **menu.cpp :** Contains the menu display logic. 
- **explain.cpp :** Contains the explanation or help information. 
- **plane.cpp :** Contains methods for handling the plane seat chart. 
- **seat.cpp :** Contains methods for seat operations (reserve, cancel, etc.). 
- **include/ plane.h :** Contains class declarations and function prototypes. 
- **data/ chartIn.txt :** The initial seat chart data file. 
- **Makefile** The file used for building the project.
## **Compilation and Execution**

### **Using the Makefile**

The project includes a `Makefile` for compiling and building the application. To compile and run the project, follow these steps:

1. **Open Terminal**: Navigate to the root directory of the project where the `Makefile` is located.

2. **Compile the Project**: Run the following command to compile the project:

```sh
make
```

This will compile the source code files and produce an executable named plane_reservation.

Run the Program: Execute the program with the following command:

```sh
./plane_reservation
```

This will start the application and display the menu options for interacting with the plane reservation system.
### Notes
Ensure the chartIn.txt file in the data directory is correctly formatted as described in the data/ directory structure for proper reading and processing. Modify the Makefile as necessary if your directory structure changes or if additional build requirements arise.
