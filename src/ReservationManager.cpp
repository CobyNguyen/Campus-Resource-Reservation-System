using namespace std;

#include "ReservationManager.h"
#include "Reservation.h"

//Constructors
ReservationManager::ReservationManager() {
    studentName = "";
    reservationDate = "";
}

ReservationManager::ReservationManager(string studentName, string reservationDate) {
    this->studentName = studentName;
    this->reservationDate = reservationDate;
}

//Methods

void ReservationManager::createReservation(Reservation reservation) {
    //Implementation for creating a reservation
}

void ReservationManager::cancelReservation(Reservation reservation) {
    //Implementation for canceling a reservation
}

void ReservationManager::viewReservations() {
    //Implementation for viewing current reservations
}

void ReservationManager::searchReservations() {
    //Implementation for searching for reservations
}
