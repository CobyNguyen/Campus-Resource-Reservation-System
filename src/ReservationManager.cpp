#include "../include/ReservationManager.h"
#include "../include/Reservation.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

//Constructors
ReservationManager::ReservationManager() {
    head = nullptr;
    tail = nullptr;
}

ReservationManager::ReservationManager(string, string) {
    head = nullptr;
    tail = nullptr;
}

ReservationManager::~ReservationManager() {
    while (head != nullptr) {
        ReservationNode* next = head->next;
        delete head;
        head = next;
    }
    tail = nullptr;
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

    //Goes through linked list to find the reservation with the given ID and removes it from the list
    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            if (previous == nullptr) { //
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

WaitingList* ReservationManager::findWaitingList(const string& resourceID) {
    for (WaitingList& list : waitingLists) {
        if (list.resourceId() == resourceID) {
            return &list;
        }
    }
    return nullptr;
}

int ReservationManager::nextReservationID() const {
    int largestID = 0;
    ReservationNode* current = head;
    while (current != nullptr) {
        if (current->reservation.getReservationID() > largestID) {
            largestID = current->reservation.getReservationID();
        }
        current = current->next;
    }
    return largestID + 1;
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

void ReservationManager::createReservation(vector<Resource>& resources) { // Creates a new reservation and updates the resource availability
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

    //Prompt user for reservation details with error handling
    cout << "Student ID: ";
    if (!(cin >> studentID)) {
        cin.clear();
        cin.ignore();
        cout << "Invalid student ID." << endl;
        return;
    }

    cout << "Student Name: ";
    cin.ignore();
    getline(cin, studentName);
    if (studentName.empty()) {
        cout << "Invalid student name." << endl;
        return;
    }

    cout << "Resource ID: ";
    getline(cin, resourceID);

    // Check if the resource ID exists in the resources vector
    Resource* selectedResource = nullptr;
    for (Resource& resource : resources) {
        if (resource.getResourceID() == resourceID) {
            cout << "Resource ID exists." << endl;
            selectedResource = &resource;
            break;
        }
    }

    if (selectedResource == nullptr) {
        cout << "Invalid resource ID" << endl;
        return;
    }

    cout << "Reservation Date: ";
    getline(cin, reservationDate);
    if (reservationDate.empty()) {
        cout << "Invalid reservation date." << endl;
        return;
    }

    // Check if the resource is available; if not then add the student to the waiting list
    if (selectedResource != nullptr && !selectedResource->getAvailability()) {
        WaitingList* waitingList = findWaitingList(resourceID);
        if (waitingList == nullptr) {
            waitingLists.emplace_back(resourceID);
            waitingList = &waitingLists.back();
        }

        WaitingStudent student{studentID, studentName, resourceID, reservationDate, "N/A", "N/A"};
        if (waitingList->add(student)) {
            cout << "Resource unavailable. Student added to waiting list." << endl;
        } else {
            cout << "Invalid waiting-list request." << endl;
        }
        return;
    }

    int reservationID = nextReservationID();
    addReservation(Reservation(reservationID, studentID, studentName, resourceID, reservationDate)); //adds reservation through method then updates the resource availability
    selectedResource->setAvailability(false); 
    cout << "Reservation created. Reservation ID: " << reservationID << endl; 
}

void ReservationManager::cancelReservation(vector<Resource>& resources) { // Cancels a reservation and updates the resource availability
    int reservationID;
    cout << "Reservation ID: ";
    if (!(cin >> reservationID)) {
        cin.clear();
        cin.ignore();
        cout << "Invalid reservation ID." << endl;
        return;
    }
    cin.ignore();
    ReservationNode* current = head;
    while (current != nullptr && current->reservation.getReservationID() != reservationID) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Reservation not found." << endl;
        return;
    }

    const Reservation cancelled = current->reservation; // Store the cancelled reservation details
    cancellationHistory.record({cancelled.getReservationID(), cancelled.getStudentID(), cancelled.getStudentName(), cancelled.getResourceID(), cancelled.getReservationDate(), "N/A", "N/A"});
    removeReservation(reservationID);

    for (Resource& resource : resources) { // Update the resource availability and check for waiting list
        if (resource.getResourceID() == cancelled.getResourceID()) {
            resource.setAvailability(true);
            WaitingList* waitingList = findWaitingList(cancelled.getResourceID()); // Check if there is a waiting list for the resource
            WaitingStudent next;
            if (waitingList != nullptr && waitingList->removeNext(next)) { // Assign the next waiting student to the resource
                addReservation(Reservation(nextReservationID(), next.studentId, next.studentName, next.resourceId, next.reservationDate));
                resource.setAvailability(false);
                cout << "Reservation cancelled; next waiting student assigned." << endl;
            } else {
                cout << "Reservation cancelled." << endl;
            }
            return;
        }
    }
}

void ReservationManager::displayWaitingLists() const {
    if (waitingLists.empty()) {
        cout << "Waiting lists are empty." << endl;
        return;
    }

    for (const WaitingList& list : waitingLists) {
        list.display(cout);
    }
}

void ReservationManager::undoCancellation(vector<Resource>& resources) { // Undoes the last cancellation and restores the reservation if possible
    CancelledReservation cancelled;
    if (!cancellationHistory.undo(cancelled)) {
        cout << "Cancellation history is empty." << endl;
        return;
    }

    for (Resource& resource : resources) { // Check if the resource is already reserved
        if (resource.getResourceID() == cancelled.resourceId &&
            !resource.getAvailability()) {
            cancellationHistory.record(cancelled);
            cout << "Cannot undo cancellation: resource is already reserved." << endl;
            return;
        }
    }

    // Restore the reservation and update the resource availability
    addReservation(Reservation(cancelled.reservationId, cancelled.studentId, cancelled.studentName, cancelled.resourceId, cancelled.reservationDate));
    for (Resource& resource : resources) {
        if (resource.getResourceID() == cancelled.resourceId) {
            resource.setAvailability(false);
            break;
        }
    }
    cout << "Cancellation undone." << endl;
}

bool ReservationManager::searchForReservation(int reservationID){
    ReservationNode* current = head;
    while (current != nullptr) { // Goes through linked list to find the reservation with the given ID and returns true if found or false if not
        if(current->reservation.getReservationID() == reservationID){
            return true;
        }
        current = current->next;
    }
    return false;
}