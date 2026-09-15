//Users shall be able to:
//Create a reservation.
//Cancel a reservation.
//View current reservations.
//Search for reservations.

//Each reservation must contain:
//Reservation ID
//Student ID
//Student Name
//Resource ID
//Reservation Date

#ifndef RESERVATIONMANAGERH 
#define RESERVATIONMANAGERH

#include <string>
#include "Reservation.h"

class ReservationManager{
    private:
        //Constructor
        ReservationManager();
        ReservationManager(string studentName, string reservationDate);

        void createReservation(Reservation reservation);
        void cancelReservation(Reservation reservation);
        void viewReservations();
        void searchReservations();

    public:
        string studentName;
        string reservationDate;
        //Linked list here? Vector?

};


#endif