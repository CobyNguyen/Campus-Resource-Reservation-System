#include "../include/Reservation.h"

using namespace std;

//Constructors
Reservation::Reservation() {
    reservationID = 0;
    studentID = 0;
    studentName = "";
    resourceID = 0;
    reservationDate = "";
}

Reservation::Reservation(int reservationID, int studentID, string studentName, int resourceID, string reservationDate) {
    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resourceID = resourceID;
    this->reservationDate = reservationDate;
}

//Getters and Setters
  int Reservation::getReservationID() {
    return reservationID;
  }

void Reservation::setReservationID(int reservationID) {
    this->reservationID = reservationID;
}

int Reservation::getStudentID() {
    return studentID;
}

void Reservation::setStudentID(int studentID) {
    this->studentID = studentID;
}

string Reservation::getStudentName() {
    return studentName;
}

void Reservation::setStudentName(string studentName) {
    this->studentName = studentName;
}

int Reservation::getResourceID() {
    return resourceID;
}

void Reservation::setResourceID(int resourceID) {
    this->resourceID = resourceID;
}

string Reservation::getReservationDate() {
    return reservationDate;
}

void Reservation::setReservationDate(string reservationDate) {
    this->reservationDate = reservationDate;
}

