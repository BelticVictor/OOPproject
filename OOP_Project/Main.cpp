#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Event.cpp"
#include "Venue.cpp"
#include "Ticket.cpp"
#include "Ticket_Manager.cpp"

int Ticket::tickets_bought = 0;

int main() {
    int EventCount=0;
    int CurrentEvent=0;

    int seats[2] = {10, 10};
    Ticket_Manager tix((char*)"Backyard", 100, 2, seats, "Concert", "18:30", "19:30", "2023-11-16");
    Ticket_Manager* ticketM; //every Eveniment will be stored here
    Ticket_Manager* copyTix=nullptr; //surprise tool for later

    ticketM = new Ticket_Manager[1];

    ticketM[0] = tix;

    ticketM[0].generateTickets(0, 2);
    ticketM[0].generateTickets(1, 3);
    EventCount++;
    int stop;
    cout << endl << "If you wish to read data from a text file, type 0. Else, if you wish to use the menu, press 1: ";
    cin >> stop;
    stop = 1;
    cout << endl << endl;

    if (stop == 0) {

        ifstream data("data.txt", ios::ate);

        if (!data.is_open()) {
            cout << endl << "!!!!!!!!!!!!! The file did not open !!!!!!!!!!!!!";
        }
        else {
            Ticket_Manager ticket;
            int type;
            int num;
            data >> ticket;
            data >> type;
            data >> num;
            ticket.generateTickets(type, num);
            cout << ticket;
        }
    }
    else {
        while (stop != 0) {
            cout << endl << "Input 0 to exit the program";
            cout << endl << "Input 1 to display data for the current event selected";
            cout << endl << "Input 2 to buy tickets for the current event selected";
            cout << endl << "Input 3 to add a new event"; 
            cout << endl << "Input 4 to show all events"; 
            cout << endl << "Input 5 to switch to another event";
            cout << endl << "Input 6 to remove an event";
            //cout << endl << "Input 6 to show availible seats for the current event"; //to implement
            cout << endl << "Input command : ";
            cin >> stop;
            switch (stop) {
            case (1):
                if (EventCount != 0)
                    cout << ticketM[CurrentEvent];
                else
                    cout << endl << "There are currently no events";
                break;
            case(2):
                cout << endl << "Input how many tickets do you wish to buy: ";
                int quan;
                cin >> quan;
                cout << endl << "Input what kind of ticket you wish to buy (0 for Normal, 1 for VIP): ";
                int type;
                cin >> type;
                while (type >= 2) {
                    cout << endl << "Error: Input not 0 or 1. Retry again:";
                    cin >> type;
                }
                ticketM[CurrentEvent].generateTickets(type, quan);
                
                break;
            case(3):

                EventCount++;
                CurrentEvent = EventCount - 1;

                if (copyTix != nullptr)
                    delete[] copyTix;
                copyTix = new Ticket_Manager[EventCount - 1];

                for (int i = 0; i < EventCount-1; i++)
                    copyTix[i] = ticketM[i];
                delete[] ticketM;

                ticketM = new Ticket_Manager[EventCount];

                for (int i = 0; i < EventCount-1; i++)
                    ticketM[i] = copyTix[i];
                delete[] copyTix;

                cin >> ticketM[CurrentEvent];
                break;
            case(4):
                for (int i = 0; i < EventCount; i++)
                    cout << endl << ticketM[i].get_eventname()<<endl;
                break;
            case(5):
                int pick;
                cout << endl << "Current events availible to pick out of are: ";
                if (EventCount != 0) {
                    for (int i = 0; i < EventCount; i++)
                        cout << " " << i;
                    cout << endl << "Choose an event: ";
                    cin >> CurrentEvent;
                    while (CurrentEvent >= EventCount) {
                        cout << "You cannot pick that value. Try again: ";
                        cin >> CurrentEvent;
                    }
                }
                else
                    cout << "No events currently exist";
                break;
            default:
                break;
            }
        }
    }
    delete[] ticketM;
}