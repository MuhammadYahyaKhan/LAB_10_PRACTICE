#include <stdio.h>
#include <stdlib.h>

struct Flights {
    int flightNumber; 
    char departureCity[100];
    char arrivalCity[100];
    int departureTime;
    int arrivalTime;  
    int availableSeats;
};

int main() {
    struct Flights s1[3]; 
    int flightCount = 3;  

    // Input details
    for (int i = 0; i < flightCount; i++) {
        printf("---------------------------- Entry %d ----------------------------\n", i + 1);
        printf("Enter flight number: "); scanf("%d", &s1[i].flightNumber);
        printf("Departure city: "); scanf(" %s", s1[i].departureCity);
        printf("Arrival city: "); scanf(" %s", s1[i].arrivalCity); 
        printf("Departure Time (24-hour format): "); scanf("%d", &s1[i].departureTime); 
        printf("Arrival Time (24-hour format): "); scanf("%d", &s1[i].arrivalTime); 
        printf("Enter the number of available seats: "); scanf("%d", &s1[i].availableSeats);
    }

    system("cls"); 

    // Main Logic
    int terminate = 1;
    printf("Enter 0 to break: "); scanf("%d", &terminate);

    while (terminate != 0) {
        // Print available Flights
        printf("------------------------------- Available Flights -------------------------------\n");
        printf("Flight Number\tDeparture City\tDeparture Time\tArrival City\tArrival Time\tNo. Seats\n");
        
        for (int i = 0; i < flightCount; i++) {
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n",
                   s1[i].flightNumber,
                   s1[i].departureCity,
                   s1[i].departureTime,
                   s1[i].arrivalCity,
                   s1[i].arrivalTime,
                   s1[i].availableSeats);
        }

        int FN;
        printf("Enter the Flight Number to book a seat: ");
        scanf("%d", &FN);

        // Check if the flight number is valid and seats are available
        int found = 0;
        for (int i = 0; i < flightCount; i++) {
            if (s1[i].flightNumber == FN) {
                found = 1;
                if (s1[i].availableSeats > 0) {
                    s1[i].availableSeats--;
                    printf("Seat booked successfully on flight %d. Available seats now: %d\n", FN, s1[i].availableSeats);
                } else {
                    printf("No available seats on flight %d.\n", FN);
                }
                break;
            }
        }
        
        if (!found) {
            printf("Flight number %d not found.\n", FN);
        }

        printf("Enter 0 to break: "); scanf("%d", &terminate);
    }

    return 0;
}