//Each reservation must contain:

//Reservation ID
//Student ID
//Student Name
//Resource ID
//Reservation Date

#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

class Reservation{
    private:
        int reservationID;
        int studentID;
        string studentName;
        int resourceID;
        string reservationDate;

    public:
        //Constructors
        Reservation();
        Reservation(int reservationID, int studentID, string studentName, int resourceID, string reservationDate);

        int getReservationID();
        void setReservationID(int);

        int getStudentID();
        void setStudentID(int);

        string getStudentName();
        void setStudentName(string);

        int getResourceID();
        void setResrouceID(int);

        string getReservationDate();
        void setReservationDate(string);
};

#endif
