#include "../include/ReservationManager.h"
#include "../include/Reservation.h"
#include <iostream>

using namespace std;

//Constructors
ReservationManager::ReservationManager() {
    head = nullptr;
    tail = nullptr;
    studentName = "";
    reservationDate = "";
}

ReservationManager::ReservationManager(string studentName, string reservationDate) {
    head = nullptr;
    tail = nullptr;
    this->studentName = studentName;
    this->reservationDate = reservationDate;
}

//Methods

void ReservationManager::addReservation(Reservation reservation) {
    ReservationNode* newNode = new ReservationNode();
    newNode->reservation = reservation;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void ReservationManager::removeReservation(int reservationID) {
    ReservationNode* current = head;
    ReservationNode* previous = nullptr;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void ReservationManager::displayReservations() {
    ReservationNode* current = head;
    while (current != nullptr) {
        cout << "Reservation ID: " << current->reservation.getReservationID() << endl;
        cout << "Student ID: " << current->reservation.getStudentID() << endl;
        cout << "Student Name: " << current->reservation.getStudentName() << endl;
        cout << "Resource ID: " << current->reservation.getResourceID() << endl;
        cout << "Reservation Date: " << current->reservation.getReservationDate() << endl;
        cout << "------------------------" << endl;
        current = current->next;
    }
}

void ReservationManager::createReservation() {
    string input;
    int reservationID;
    int studentID;
    string studentName;
    int resourceID;
    string reservationDate;

    cout << "Reservation ID: ";
    getline(cin, input);

    cout << "Student ID: ";
    getline(cin, input);

    cout << "Student Name: ";
    getline(cin, studentName);

    cout << "Resource ID: ";
    getline(cin, input);

    cout << "Reservation Date: ";
    getline(cin, reservationDate);

    addReservation(Reservation(reservationID, studentID, studentName, resourceID, reservationDate));
    cout << "Reservation created." << endl;
}

void ReservationManager::cancelReservation() {
    string input;
    cout << "Reservation ID: ";
    getline(cin, input);
    removeReservation(stoi(input));
    cout << "Reservation cancelled." << endl;
}