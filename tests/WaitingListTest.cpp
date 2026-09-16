#include "WaitingList.h"

#include <cassert>
#include <iostream>
#include <sstream>

int main() {
    WaitingList list;
    WaitingStudent next{0, ""};

    assert(list.empty());
    assert(!list.removeNext(next));
    assert(!list.add({0, "Invalid"}));
    assert(!list.add({1003, ""}));

    assert(list.add({1001, "Alice"}));
    assert(list.add({1002, "Bob"}));

    std::ostringstream output;
    list.display(output);
    assert(output.str() == "1001 | Alice\n1002 | Bob\n");

    assert(list.removeNext(next) && next.studentId == 1001);
    assert(list.removeNext(next) && next.studentId == 1002);
    assert(list.empty());

    std::ostringstream emptyOutput;
    list.display(emptyOutput);
    assert(emptyOutput.str() == "Waiting list is empty.\n");

    std::cout << "Waiting-list tests passed.\n";
}
