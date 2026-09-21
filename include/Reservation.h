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

        int getReservationID() const;
        void setReservationID(int);

        int getStudentID() const;
        void setStudentID(int);

        string getStudentName() const;
        void setStudentName(string);

        string getResourceID() const;
        void setResourceID(string);

        string getReservationDate() const;
        void setReservationDate(string);
};

#endif
