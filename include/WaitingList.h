#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include <ostream>
#include <queue>
#include <string>

struct WaitingStudent {
    int studentId;
    std::string studentName;
    std::string resourceId;
    std::string reservationDate;
    std::string startTime;
    std::string endTime;
};

class WaitingList {
public:
    explicit WaitingList(const std::string& resourceId);
    bool add(const WaitingStudent& student);
    bool removeNext(WaitingStudent& student);
    void display(std::ostream& out) const;
    bool empty() const;

private:
    std::string resourceId_;
    std::queue<WaitingStudent> students_;
};

#endif
