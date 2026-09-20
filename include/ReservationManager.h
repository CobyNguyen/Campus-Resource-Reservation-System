#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <string>

#include "Reservation.h"

using namespace std;

struct ReservationNode {
    Reservation reservation;
    ReservationNode* next;
};

class ReservationManager {
    private:
        ReservationNode* head;
        ReservationNode* tail;
        string studentName;
        string reservationDate;

        void addReservation(Reservation reservation);
        void removeReservation(int reservationID);

    public:
        ReservationManager();
        ReservationManager(string studentName, string reservationDate);

        void cancelReservation();
        void createReservation();
        void displayReservations();
};

#endif