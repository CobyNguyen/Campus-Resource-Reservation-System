#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <string>
#include <vector>

#include "CancellationHistory.h"
#include "Reservation.h"
#include "Resource.h"
#include "WaitingList.h"

using namespace std;

struct ReservationNode {
    Reservation reservation;
    ReservationNode* next;
};

class ReservationManager {
    private:
        ReservationNode* head;
        ReservationNode* tail;
        CancellationHistory cancellationHistory;
        vector<WaitingList> waitingLists;

        void addReservation(Reservation reservation);
        void removeReservation(int reservationID);
        WaitingList* findWaitingList(const string& resourceID);
        int nextReservationID() const;

    public:
        ReservationManager();
        ReservationManager(string studentName, string reservationDate);
        ~ReservationManager();

        void cancelReservation(vector<Resource>& resources);
        void createReservation(vector<Resource>& resources);
        void displayReservations();
        void displayWaitingLists() const;
        void undoCancellation(vector<Resource>& resources);
        bool searchForReservation(int);
};

#endif