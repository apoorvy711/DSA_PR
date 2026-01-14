#include "Ticket.h"
#include "Event.h"
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

//./EventBookingSystem
vector<Ticket> tickets;
unordered_map<int, priority_queue<int>> prioritySeats;

void bookTicket(vector<Event>& events, int eventId, string username, bool priority) {
    for (auto& e : events) {
        if (e.id == eventId) {
            if (e.bookedSeats >= e.totalSeats) {
                cout << "Sorry! Event is fully booked.\n";
                return;
            }

            int ticketId = tickets.size() + 1;
            tickets.push_back(Ticket(ticketId, eventId, username, priority));
            e.bookedSeats++;

            if (priority)
                prioritySeats[eventId].push(ticketId);

            cout << "Ticket booked successfully! ID: " << ticketId << "\n";
            return;
        }
    }
    cout << "Event not found.\n";
}

void cancelTicket(int ticketId, vector<Event>& events) {
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->ticketId == ticketId) {
            for (auto& e : events) {
                if (e.id == it->eventId) {
                    e.bookedSeats--;
                    tickets.erase(it);
                    cout << "Ticket cancelled.\n";
                    return;
                }
            }
        }
    }
    cout << "Ticket ID not found.\n";
}
