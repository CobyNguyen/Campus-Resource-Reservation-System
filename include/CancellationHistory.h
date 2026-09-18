#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H

#include <ostream>
#include <stack>
#include <string>

struct CancelledReservation {
    int reservationId;
    int studentId;
    std::string studentName;
    std::string resourceId;
    std::string reservationDate;
    std::string startTime;
    std::string endTime;
};

class CancellationHistory {
public:
    void record(const CancelledReservation& reservation);
    bool undo(CancelledReservation& reservation);
    void display(std::ostream& out) const;
    bool empty() const;

private:
    std::stack<CancelledReservation> cancelled_;
};

#endif
