#include "Event.h"
#include "Ticket.h"
#include <iostream>
#include <vector>
using namespace std;

void displaySortedEvents(vector<Event> events, string key);
void bookTicket(vector<Event>& events, int eventId, string username, bool priority);
void cancelTicket(int ticketId, vector<Event>& events);

void createEvent(vector<Event>& events) {
    int id = events.size() + 1;
    string name, type, date;
    int seats;

    cout << "Enter Event Name: ";
    cin.ignore(); // clear input buffer
    getline(cin, name);
    cout << "Enter Event Type: ";
    getline(cin, type);
    cout << "Enter Event Date (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "Enter Total Seats: ";
    cin >> seats;

    events.push_back(Event(id, name, type, date, seats));
    cout << "Event created successfully with ID: " << id << "\n";
}

int main() {
    vector<Event> events;
    int choice;

    do {
        cout << "\n==== Event Ticket Booking ====\n";
        cout << "1. Create Event\n2. View Events\n3. Book Ticket\n4. Cancel Ticket\n5. Sort Events\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            createEvent(events);
        } else if (choice == 2) {
            displaySortedEvents(events, "date");
        } else if (choice == 3) {
            int id;
            string user;
            char prio;
            cout << "Enter Event ID: "; cin >> id;
            cout << "Enter Your Name: "; cin >> user;
            cout << "Priority Booking (y/n)? "; cin >> prio;
            bookTicket(events, id, user, prio == 'y');
        } else if (choice == 4) {
            int tid;
            cout << "Enter Ticket ID: "; cin >> tid;
            cancelTicket(tid, events);
        } else if (choice == 5) {
            string key;
            cout << "Sort by (type/date): "; cin >> key;
            displaySortedEvents(events, key);
        }
    } while (choice != 6);

    return 0;
}
