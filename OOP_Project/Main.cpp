#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Event.cpp"
#include "Venue.cpp"
#include "Ticket.cpp"
#include "Ticket_Manager.cpp"

int Ticket::tickets_bought = 0;

//make it so it saves all the info in a file at the end. read the file at the start. the file contains: how many events there are, and the info data

int main() {
    int EventCount=0;
    int CurrentEvent=0;

    Ticket_Manager* ticketM=nullptr; //every Eveniment will be stored here
    Ticket_Manager* copyTix=nullptr; //surprise tool for later

    //!!!!!!!!!!!!!!!! Uncomment for testing.

    int seats[2] = {10, 10};
    Ticket_Manager tix((char*)"Backyard", 100, 2, seats, "Concert", "18:30", "19:30", "2023-11-16");
    Ticket_Manager tix2((char*)"Cinema", 100, 2, seats, "Movie", "12:45", "14:10", "2024-01-12");

    ticketM = new Ticket_Manager[2];

    
    ticketM[0] = tix;
    EventCount++;

    ticketM[1] = tix2;
    EventCount++;

    ticketM[0].generateTickets(0, 2);
    ticketM[0].generateTickets(1, 3);

    int stop;
    cout << endl << "If you wish to read data from a text file, type 0. Else, if you wish to use the menu right away, press 1: ";
    cin >> stop;
    cout << endl << endl;

    if (stop == 0) {

        if (EventCount==0) {
            ifstream data("data.txt");

            if (!data.is_open()) {
                cout << endl << "!!!!!!!!!!!!! The file did not open !!!!!!!!!!!!!";
            }
            else {
                EventCount++;
                ticketM = new Ticket_Manager[1];
                ticketM[0].readFromFile(data);
                cout << ticketM[0];
            }
        }
        else
        {
            ifstream data("data.txt");

            if (!data.is_open()) {
                cout << endl << "!!!!!!!!!!!!! The file did not open !!!!!!!!!!!!!";
            }
            else {
                EventCount++;
                CurrentEvent = EventCount - 1;

                if (copyTix != nullptr)
                    delete[] copyTix;
                copyTix = new Ticket_Manager[EventCount - 1];

                for (int i = 0; i < EventCount - 1; i++)
                    copyTix[i] = ticketM[i];
                delete[] ticketM;

                ticketM = new Ticket_Manager[EventCount];

                for (int i = 0; i < EventCount - 1; i++)
                    ticketM[i] = copyTix[i];
                delete[] copyTix;

                ticketM[CurrentEvent].readFromFile(data);
                cout << ticketM[CurrentEvent];
            }
        }
    }
    stop = 1;
    while (stop != 0) {
        cout << endl << "Input 0 to exit the program";
        cout << endl << "Input 1 to display data for the current event selected";
        cout << endl << "Input 2 to buy tickets for the current event selected";
        cout << endl << "Input 3 to add a new event";
        cout << endl << "Input 4 to show all events";
        cout << endl << "Input 5 to switch to another event";
        cout << endl << "Input 6 to remove an event";
        cout << endl << endl << "Input command : ";
        cin >> stop;
        switch (stop) {
        case (1):
            if (EventCount != 0)
                cout << ticketM[CurrentEvent];
            else
                cout << endl << "There are currently no events" << endl;
            break;
        case(2):
            if (EventCount != 0) {
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
            }
            else
                cout << endl << "There are currently no events" << endl;

            break;
        case(3):

            EventCount++;
            CurrentEvent = EventCount - 1;
            if (ticketM != nullptr) {

                copyTix = new Ticket_Manager[EventCount - 1];

                for (int i = 0; i < EventCount - 1; i++)
                    copyTix[i] = ticketM[i];
                delete[] ticketM;

                ticketM = new Ticket_Manager[EventCount];

                for (int i = 0; i < EventCount - 1; i++)
                    ticketM[i] = copyTix[i];
                delete[] copyTix;
            }
            else
                ticketM = new Ticket_Manager[1];

            cin >> ticketM[CurrentEvent];
            break;
        case(4):
            if (EventCount != 0) {
                cout << endl << "The events currently availible are: ";
                for (int i = 0; i < EventCount; i++)
                    cout << ticketM[i].get_eventname() << " ";
                cout << endl;
            }
            else
                cout << endl << "There are currently no events" << endl;
            break;
        case(5):
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
                cout << endl << "No events currently exist" << endl;
            break;
        case(6):
            int del;
            cout << endl << "Current events availible to pick out of are: ";
            if (EventCount != 0) {
                for (int i = 0; i < EventCount; i++)
                    cout << i << " ";
                cout << endl << "Choose an event to remove: ";
                cin >> del;
                while (del >= EventCount) {
                    cout << "You cannot pick that value. Try again: ";
                    cin >> del;
                }

                for (int i = del; i < EventCount - 1; i++)
                    ticketM[i] = ticketM[i + 1];

                copyTix = new Ticket_Manager[EventCount - 1];

                for (int i = 0; i < EventCount - 1; i++)
                    copyTix[i] = ticketM[i];
                delete[] ticketM;

                ticketM = new Ticket_Manager[EventCount-1];

                for (int i = 0; i < EventCount - 1; i++)
                    ticketM[i] = copyTix[i];
                delete[] copyTix;

                EventCount--;
                CurrentEvent = 0;
            }
            else
                cout << endl << "No events currently exist" << endl;
            break;
        default:
            break;
        }
    }
    
    delete[] ticketM;
}