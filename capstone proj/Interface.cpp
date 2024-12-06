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
#include <string>

using namespace std;

void displayMenu()
{
    cout << string(50, '*')
        << "\n\t\tHIKING IN THE US\n"
        << string(50, '*')
        << "\n\n\t1. Browse by location"
        << "\n\t2. Browse by duration"
        << "\n\t3. Browse by difficulty"
        << "\n\t4. Browse by price"
        << "\n\t5. Make a reservation"
        << "\n\t6. View Reservation"
        << "\n\t7. Cancel Reservation"
        << "\n\t8. Exit\n\n";
}

void processReservation(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    cout << "Please make a selection: ";
    int selection = 0;

    while (cin >> selection)
    {
        cout << "\n";

        if (selection == 1) chooseByLocation(hikeList, memberList,
            reservation);
        else if (selection == 2) chooseByDuration(hikeList, memberList,
            reservation);
        else if (selection == 3) chooseByDifficulty(hikeList, memberList,
            reservation);
        else if (selection == 4) chooseByPrice(hikeList, memberList,
            reservation);
        else if (selection == 5) makeReservation(hikeList, memberList,
            reservation);
        else if (selection == 6) viewReservation(hikeList, memberList,
            reservation);
        else if (selection == 7) cancelReservation(hikeList, memberList,
            reservation);
        else if (selection == 8) {
            cout << "Thank you for visiting!\n";
            break;
        }

        system("Pause");
        cout << "\n";
        displayMenu();

        cout << "Please make a selection: ";
    }
}

void chooseByLocation(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    hikeList.printAllLocations();

    cout << "Choose a location: ";

    string location;
    cin >> location;
    cout << "\n";

    hikeList.printByLocation(location);

    askToReserve(hikeList, memberList, reservation);
}

void chooseByDuration(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    cout << "\t(days)\n";

    hikeList.printByDuration();

    cout << "How many days are you considering? ";

    int days = 0;
    cin >> days;
    cout << "\n";

    hikeList.printByDuration(days);

    askToReserve(hikeList, memberList, reservation);
}

void chooseByDifficulty(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    cout << "Choose difficulty level:"
        << "\n\n\te. easy"
        << "\n\tm. moderate"
        << "\n\ts. strenuous"
        << "\n\nYour choice: ";

    char choice = 'n';
    cin >> choice;
    cout << "\n\t(difficulty level)\n";

    hikeList.printByDifficulty(choice);
    cout << "\n";

    askToReserve(hikeList, memberList, reservation);
}

void chooseByPrice(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    hikeList.printByPrice();

    askToReserve(hikeList, memberList, reservation);
}

int askIfMember(MemberList& memberList)
{
    cout << "Are you a member? (y/n) ";
    
    char isMember = 'n';
    cin >> isMember;
    cout << "\n";

    if (isMember == 'y')
    {
        cout << "What is your member ID number? ";

        int idNumber = 0;
        cin >> idNumber;

        cout << "\nWhat is your last name? ";

        string lastName;
        cin >> lastName;
        cout << "\n";

        memberList.printMember(idNumber, lastName);
        cout << "\n";

        return idNumber;
    }
    else
    {
        return addNewMember(memberList);
    }
}

int addNewMember(MemberList& memberList)
{
    cout << "\tLet's add you to the member list!"
        << "\n\t\tWhat is your first name? ";

    string firstName;
    cin >> firstName;

    cout << "\t\tWhat is your last name? ";

    string lastName;
    cin >> lastName;

    memberList.addMember(firstName, lastName);

    int lastID = memberList.getLastID();

    cout << "\n\tWelcome to the club!"
        << "\n\t\tYour member ID number is: " << lastID << "\n\n";

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
        << " number."
        << "\n\t  Reservation #: " << reservationNo
        << "\n\n( *** Will continue to scheduling and payment. *** )\n\n";
}

void viewReservation(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    cout << "Enter reservation #: ";

    int reservationNumber = 0;
    cin >> reservationNumber;
    cout << "\n";

    reservation.printReservation(reservationNumber, hikeList, memberList);
    cout << "\n";
}

void cancelReservation(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    cout << "Enter reservation #: ";

    int reservationNumber = 0;
    cin >> reservationNumber;
    cout << "\n";

    reservation.printReservation(reservationNumber, hikeList, memberList);

    cout << "\nAre you sure you want to cancel this reservation? (y/n) ";

    char answer = 'n';
    cin >> answer;
    cout << "\n";

    if (answer == 'y')
    {
        reservation.cancelReservation(reservationNumber);

        cout << "Reservation #" << reservationNumber
            << " has been canceled.\n\n";
    }
}

void askToReserve(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservation)
{
    cout << "Would you like to make a reservation? (y/n) ";

    char response = 'n';
    cin >> response;
    cout << "\n";

    if (response == 'y')
    {
        makeReservation(hikeList, memberList, reservation);
    }
}