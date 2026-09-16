#include "CancellationHistory.h"

void CancellationHistory::record(const CancelledReservation& reservation) {
    cancelled_.push(reservation);
}

bool CancellationHistory::undo(CancelledReservation& reservation) {
    if (cancelled_.empty()) {
        return false;
    }

    reservation = cancelled_.top();
    cancelled_.pop();
    return true;
}

void CancellationHistory::display(std::ostream& out) const {
    if (cancelled_.empty()) {
        out << "Cancellation history is empty.\n";
        return;
    }

    std::stack<CancelledReservation> copy = cancelled_;
    while (!copy.empty()) {
        const CancelledReservation& reservation = copy.top();
        out << reservation.reservationId << " | "
            << reservation.studentId << " | "
            << reservation.studentName << " | "
            << reservation.resourceId << " | "
            << reservation.reservationDate << '\n';
        copy.pop();
    }
}

bool CancellationHistory::empty() const {
    return cancelled_.empty();
}
