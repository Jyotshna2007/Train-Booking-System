#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ---------- Base Class (Inheritance) ---------- */
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

/* ---------- Derived Class ---------- */
class Passenger : public Person {
public:
    Passenger(string n, int a) : Person(n, a) {}
};

/* ---------- Train Class ---------- */
class Train {
private:
    int trainNo;
    string trainName;
    string source;
    string destination;
    int seatsAvailable;

public:
    Train(int no, string name, string src, string dest, int seats) {
        trainNo = no;
        trainName = name;
        source = src;
        destination = dest;
        seatsAvailable = seats;
    }

    int getTrainNo() {
        return trainNo;
    }

    string getTrainName() {
        return trainName;
    }

    string getRoute() {
        return source + " -> " + destination;
    }

    int getSeats() {
        return seatsAvailable;
    }

    void bookSeat() {
        seatsAvailable--;
    }

    void cancelSeat() {
        seatsAvailable++;
    }

    void displayTrain() {
        cout << trainNo << "\t" << trainName << "\t"
             << source << " -> " << destination
             << "\tSeats: " << seatsAvailable << endl;
    }
};

/* ---------- Ticket Class ---------- */
class Ticket {
private:
    int ticketId;
    Passenger passenger;
    Train *train;

public:
    Ticket(int id, Passenger p, Train *t)
        : passenger(p) {
        ticketId = id;
        train = t;
    }

    int getTicketId() {
        return ticketId;
    }

    Train* getTrain() {
        return train;
    }

    void displayTicket() {
        cout << "\nTicket ID: " << ticketId;
        cout << "\nPassenger Name: " << passenger.getName();
        cout << "\nAge: " << passenger.getAge();
        cout << "\nTrain: " << train->getTrainName();
        cout << "\nRoute: " << train->getRoute();
        cout << "\n-----------------------------\n";
    }
};

/* ---------- Main System Class ---------- */
class TrainBookingSystem {
private:
    vector<Train> trains;
    vector<Ticket> tickets;
    int ticketCounter;

public:
    TrainBookingSystem() {
        ticketCounter = 1;

        // Predefined trains
        trains.push_back(Train(101, "Express", "Hyderabad", "Delhi", 5));
        trains.push_back(Train(102, "Superfast", "Chennai", "Bangalore", 3));
        trains.push_back(Train(103, "Rajdhani", "Mumbai", "Kolkata", 4));
    }

    void showTrains() {
        cout << "\nAvailable Trains:\n";
        cout << "No\tName\tRoute\t\tSeats\n";
        for (auto &t : trains) {
            t.displayTrain();
        }
    }

    void bookTicket() {
        int trainNo, age;
        string name;

        showTrains();
        cout << "\nEnter Train Number: ";
        cin >> trainNo;

        for (auto &t : trains) {
            if (t.getTrainNo() == trainNo) {
                if (t.getSeats() <= 0) {
                    cout << "No seats available!\n";
                    return;
                }

                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Age: ";
                cin >> age;

                Passenger p(name, age);
                t.bookSeat();

                tickets.push_back(Ticket(ticketCounter++, p, &t));
                cout << "\nTicket Booked Successfully!\n";
                return;
            }
        }
        cout << "Invalid Train Number!\n";
    }

    void cancelTicket() {
        int id;
        cout << "\nEnter Ticket ID to Cancel: ";
        cin >> id;

        for (auto it = tickets.begin(); it != tickets.end(); it++) {
            if (it->getTicketId() == id) {
                it->getTrain()->cancelSeat();
                tickets.erase(it);
                cout << "Ticket Cancelled Successfully!\n";
                return;
            }
        }
        cout << "Ticket Not Found!\n";
    }

    void viewTickets() {
        if (tickets.empty()) {
            cout << "\nNo tickets booked yet.\n";
            return;
        }

        for (auto &t : tickets) {
            t.displayTicket();
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n====== Train Booking System ======\n";
            cout << "1. View Trains\n";
            cout << "2. Book Ticket\n";
            cout << "3. Cancel Ticket\n";
            cout << "4. View Booked Tickets\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: showTrains(); break;
                case 2: bookTicket(); break;
                case 3: cancelTicket(); break;
                case 4: viewTickets(); break;
                case 0: cout << "Thank you for using the system!\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 0);
    }
};

/* ---------- Main Function ---------- */
int main() {
    TrainBookingSystem system;
    system.menu();
    return 0;
}
