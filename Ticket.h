#ifndef TICKET_H
#define TICKET_H

#include <string>
using namespace std;

struct Ticket {
    int ticketId;
    int eventId;
    string username;
    bool isPriority;

    Ticket(int tid, int eid, string user, bool priority)
        : ticketId(tid), eventId(eid), username(user), isPriority(priority) {}
};

#endif
