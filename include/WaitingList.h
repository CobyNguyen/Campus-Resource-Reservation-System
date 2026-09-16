#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include <ostream>
#include <queue>
#include <string>

struct WaitingStudent {
    int studentId;
    std::string studentName;
};

class WaitingList {
public:
    bool add(const WaitingStudent& student);
    bool removeNext(WaitingStudent& student);
    void display(std::ostream& out) const;
    bool empty() const;

private:
    std::queue<WaitingStudent> students_;
};

#endif
