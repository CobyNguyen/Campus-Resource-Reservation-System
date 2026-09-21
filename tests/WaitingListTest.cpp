#include "WaitingList.h"

#include <cassert>
#include <iostream>
#include <sstream>

int main() {
    WaitingList list("R101");
    WaitingList otherResource("R102");
    WaitingStudent next{};

    assert(list.empty());
    assert(!list.removeNext(next));
    assert(!list.add({0, "Invalid", "R101", "09/15/2026", "10:00", "11:00"}));
    assert(!list.add({1003, "", "R101", "09/15/2026", "10:00", "11:00"}));
    assert(!list.add({1003, "Eve", "R102", "09/15/2026", "10:00", "11:00"}));

    assert(list.add({1001, "Alice", "R101", "09/15/2026", "10:00", "11:00"}));
    assert(list.add({1002, "Bob", "R101", "09/15/2026", "10:00", "11:00"}));
    assert(otherResource.add({1003, "Eve", "R102", "09/15/2026", "10:00", "11:00"}));

    std::ostringstream output;
    list.display(output);
    assert(output.str() ==
           "1001 | Alice | R101 | 09/15/2026 | 10:00 - 11:00\n"
           "1002 | Bob | R101 | 09/15/2026 | 10:00 - 11:00\n");

    assert(list.removeNext(next) && next.studentId == 1001);
    assert(list.removeNext(next) && next.studentId == 1002);
    assert(list.empty());
    assert(otherResource.removeNext(next) && next.studentId == 1003);

    std::ostringstream emptyOutput;
    list.display(emptyOutput);
    assert(emptyOutput.str() == "Waiting list is empty.\n");

    std::cout << "Waiting-list tests passed.\n";
}
