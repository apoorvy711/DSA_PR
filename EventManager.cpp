#include "Event.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void addSampleEvents(vector<Event>& events) {
    events.push_back(Event(1, "Music Fest", "Music", "2025-05-10", 100));
    events.push_back(Event(2, "Tech Conference", "Tech", "2025-05-15", 50));
    events.push_back(Event(3, "Cricket Match", "Sports", "2025-06-01", 200));
}

void displaySortedEvents(vector<Event> events, string key) {
    if (key == "type") {
        sort(events.begin(), events.end(), [](Event& a, Event& b) {
            return a.type < b.type;
        });
    } else {
        sort(events.begin(), events.end(), [](Event& a, Event& b) {
            return a.date < b.date;
        });
    }

    for (auto& e : events) {
        cout << e.id << ": " << e.name << " (" << e.type << ") on " << e.date
             << " [Seats: " << e.bookedSeats << "/" << e.totalSeats << "]\n";
    }
}
