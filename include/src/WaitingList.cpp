#include "WaitingList.h"

bool WaitingList::add(const WaitingStudent& student) {
    if (student.studentId <= 0 || student.studentName.empty()) {
        return false;
    }

    students_.push(student);
    return true;
}

bool WaitingList::removeNext(WaitingStudent& student) {
    if (students_.empty()) {
        return false;
    }

    student = students_.front();
    students_.pop();
    return true;
}

void WaitingList::display(std::ostream& out) const {
    if (students_.empty()) {
        out << "Waiting list is empty.\n";
        return;
    }

    std::queue<WaitingStudent> copy = students_;
    while (!copy.empty()) {
        const WaitingStudent& student = copy.front();
        out << student.studentId << " | " << student.studentName << '\n';
        copy.pop();
    }
}

bool WaitingList::empty() const {
    return students_.empty();
}
