#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

using namespace std;

class Reservation{
    private:
        int reservationID;
        int studentID;
        string studentName;
        string resourceID;
        string reservationDate;

    public:
        //Constructors
        Reservation();
        Reservation(int reservationID, int studentID, string studentName, string resourceID, string reservationDate);

        int getReservationID();
        void setReservationID(int);

        int getStudentID();
        void setStudentID(int);

        string getStudentName();
        void setStudentName(string);

        string getResourceID();
        void setResourceID(string);

        string getReservationDate();
        void setReservationDate(string);
};

#endif
