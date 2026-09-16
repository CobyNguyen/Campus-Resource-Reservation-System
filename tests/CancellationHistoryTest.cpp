#include "CancellationHistory.h"

#include <cassert>
#include <iostream>
#include <sstream>

int main() {
    CancellationHistory history;
    CancelledReservation restored{};

    assert(history.empty());
    assert(!history.undo(restored));

    std::ostringstream emptyOutput;
    history.display(emptyOutput);
    assert(emptyOutput.str() == "Cancellation history is empty.\n");

    history.record({301, 1001, "Alice", "R101", "09/15/2026"});
    history.record({302, 1002, "Bob", "R102", "09/16/2026"});

    std::ostringstream output;
    history.display(output);
    assert(output.str() ==
           "302 | 1002 | Bob | R102 | 09/16/2026\n"
           "301 | 1001 | Alice | R101 | 09/15/2026\n");

    assert(history.undo(restored) && restored.reservationId == 302);
    assert(history.undo(restored) && restored.reservationId == 301);
    assert(history.empty());
    assert(!history.undo(restored));

    std::cout << "Cancellation-history tests passed.\n";
}
