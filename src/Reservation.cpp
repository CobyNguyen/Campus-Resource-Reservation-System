#include "../include/Reservation.h"

using namespace std;

//Constructors
Reservation::Reservation() {
    reservationID = 0;
    studentID = 0;
    studentName = "";
    resourceID = "";
    reservationDate = "";
}

Reservation::Reservation(int reservationID, int studentID, string studentName, string resourceID, string reservationDate) {
    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resourceID = resourceID;
    this->reservationDate = reservationDate;
}

//Getters and Setters
int Reservation::getReservationID() const {
    return reservationID;
  }

void Reservation::setReservationID(int reservationID) {
    this->reservationID = reservationID;
}

int Reservation::getStudentID() const {
    return studentID;
}

void Reservation::setStudentID(int studentID) {
    this->studentID = studentID;
}

string Reservation::getStudentName() const {
    return studentName;
}

void Reservation::setStudentName(string studentName) {
    this->studentName = studentName;
}

string Reservation::getResourceID() const {
    return resourceID;
}

void Reservation::setResourceID(string resourceID) {
    this->resourceID = resourceID;
}

string Reservation::getReservationDate() const {
    return reservationDate;
}

void Reservation::setReservationDate(string reservationDate) {
    this->reservationDate = reservationDate;
}

