#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

struct Event {
    int id;
    string name;
    string type;
    string date;
    int totalSeats;
    int bookedSeats;

    Event(int i, string n, string t, string d, int ts)
        : id(i), name(n), type(t), date(d), totalSeats(ts), bookedSeats(0) {}
};

#endif
