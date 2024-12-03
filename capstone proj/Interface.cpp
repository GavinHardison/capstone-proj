/*
    NHLD
    Nguyen, Tai (Team Leader)
    Hardison, Gavin
    Lewandowski, Joe
    Davis, Joey

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
    cout << string(50, '*') << "\n"
        << "\t\tHIKING IN THE US\n"
        << string(50, '*') << "\n\n";

    cout << "\t1. Browse by location\n"
        << "\t2. Browse by duration\n"
        << "\t3. Browse by difficulty\n"
        << "\t4. Browse by price\n"
        << "\t5. Make a reservation\n"
        << "\t6. View Reservation\n"
        << "\t7. Cancel Reservation\n"
        << "\t8. Exit\n\n";
}

void processReservation(const HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Please make a selection: ";
    int selection = 0;

    while (cin >> selection)
    {
        cout << "\n";

        if (selection == 1) chooseByLocation(hike, member, reservation);
        else if (selection == 2) chooseByDuration(hike, member, 
            reservation);
        else if (selection == 3) chooseByDifficulty(hike, member, 
            reservation);
        else if (selection == 4) chooseByPrice(hike, member, 
            reservation);
        else if (selection == 5) makeReservation(hike, member, 
            reservation);
        else if (selection == 6) viewReservation(hike, member, 
            reservation);
        else if (selection == 7) cancelReservation(hike, member, 
            reservation);
        else if (selection == 8) {
            cout << "Thank you for visiting! " << endl;
            break;
        }

        system("Pause");
        cout << "\n";
        displayMenu();

        cout << "Please make a selection: ";
    }
}

void chooseByLocation(const HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    hike.printAllLocations();

    cout << "Choose a location: ";

    string location;
    cin >> location;
    cout << endl;

    hike.printByLocation(location);

    askToReserve(hike, member, reservation);
}

void chooseByDuration(const HikeList& hike,MemberList& member,
    Reservations& reservation)
{
    cout << "\t(days)\n";

    hike.printByDuration();

    cout << "How many days are you considering? ";

    int days;
    cin >> days;
    cout << endl;

    hike.printByDuration(days);

    askToReserve(hike, member, reservation);
}

void chooseByDifficulty(const HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Choose difficulty level:\n" << endl;
    cout << "\te. easy\n";
    cout << "\tm. moderate\n";
    cout << "\ts. strenuous\n\n";
    cout << "Your choice: ";

    char choice = 'n';
    cin >> choice;
    cout << endl;

    cout << "\t(difficulty level)\n";
    hike.printByDifficulty(choice);
    cout << "\n";

    askToReserve(hike, member, reservation);
}

void chooseByPrice(const HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    hike.printByPrice();

    askToReserve(hike, member, reservation);
}

int askIfMember(MemberList& member)
{
    cout << "Are you a member? (y/n) ";
    char isMember;

    cin >> isMember;
    cout << endl;

    if (isMember == 'y')
    {
        cout << "What is your member ID number? ";

        int idNumber;
        cin >> idNumber;
        cout << endl;

        cout << "What is your last name? ";

        string lastName;
        cin >> lastName;
        cout << endl;

        member.printMember(idNumber, lastName);
        cout << "\n";

        return idNumber;
    }
    else
    {
        return addNewMember(member);
    }
}

int addNewMember(MemberList& member)
{
    cout << "\tLet's add you to the member list!";
    cout << "\n\t\tWhat is your first name? ";

    string firstName;
    cin >> firstName;

    cout << "\t\tWhat is your last name? ";

    string lastName;
    cin >> lastName;

    member.addMember(firstName, lastName);

    int lastID = member.getLastID();

    cout << "\n\tWelcome to the club!\n";
    cout << "\t\tYour member ID number is: ";
    cout << lastID << "\n\n";

    return lastID;
}

void makeReservation(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    int memberID = askIfMember(memberList);

    cout << "Which hike would you like to reserve (hike name)? ";

    string hikeName;
    cin >> hikeName;

    cout << "\n";
    hikeList.printByHikeName(hikeName);
    cout << "\n";

    double reservationPrice = hikeList.getPrice(hikeName);
    double discountPrice = reservationPrice -
        (memberList.getPoints(memberID) / 100.0);

    if (memberList.getPoints(memberID))
    {
        cout << "\tDiscounted price using points: $" << fixed
            << setprecision(2) << discountPrice << "\n\n";
    }

    int reservationNo = reservation.addReservation(memberID, hikeName);

    cout << "\tBefore proceeding, please make a note of your reservation" 
        << " number.\n";
    cout << "\t  Reservation #: " << reservationNo << "\n\n";

    cout << "( *** Will continue to scheduling and payment. *** )" 
        << "\n\n";
}

void viewReservation(const HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Enter reservation #: ";

    int reservationNumber;
    cin >> reservationNumber;
    cout << "\n";

    reservation.printReservation(reservationNumber, hike, member);
    cout << "\n";
}

void cancelReservation(const HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Enter reservation #: ";

    int reservationNumber;
    cin >> reservationNumber;

    cout << "\n";

    reservation.printReservation(reservationNumber, hike, member);

    cout << "\nAre you sure you want to cancel this reservation? (y/n) ";

    char answer;
    cin >> answer;

    cout << "\n";

    if (answer == 'y')
    {
        reservation.cancelReservation(reservationNumber);

        cout << "Reservation #" << reservationNumber 
            << " has been canceled.\n" << endl;
    }
}

void askToReserve(const HikeList& hike, MemberList& member,
    Reservations& reservation)
{
    cout << "Would you like to make a reservation? (y/n) ";

    char response;
    cin >> response;

    cout << "\n";

    if (response == 'y' )
    {
        makeReservation(hike, member, reservation);
    }
}