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

#include "Reservations.h"
#include "HikeList.h"
#include "MemberList.h"

#include <iomanip>

using namespace std;

Node* Reservations::findReservation(int reservation) const
{
	Node* finderPtr = first;

	while (finderPtr->getReservation() != reservation)
	{
		finderPtr = finderPtr->getNext();
	}

	return finderPtr;
}


int Reservations::addReservation(int memberID,const std::string& hikeName)
{
	if (first == nullptr)
	{
		first = new Node(memberID, hikeName, nullptr, nullptr);
		first->setReservationNo(RESERVATION_START);
		last = first;
	}
	else
	{
		last->setNext(new Node(memberID, hikeName, last, nullptr));
		last = last->getNext();
		last->setReservationNo(last->getPrev()->getReservation() + 1);
	}

	++count;

	return last->getReservation();
}

void Reservations::cancelReservation(int reservation)
{
	Node* cancelPtr;

	if (count == 1)
	{
		cancelPtr = first;
	}
	else
	{
		cancelPtr = findReservation(reservation);
		if (cancelPtr == first)
		{
			cancelPtr = first;
			first = first->getNext();
		}
		else if (cancelPtr == last)
		{
			cancelPtr = last;
			last = last->getPrev();
		}
		else
		{
			cancelPtr->getPrev()->setNext(cancelPtr->getNext());
			cancelPtr->getNext()->setPrev(cancelPtr->getPrev());
		}
	}

	--count;

	delete cancelPtr;
	cancelPtr = nullptr;
}

void Reservations::printReservation(int reservation, const HikeList& hikeList, const MemberList& memberList) const
{
	Node* printPtr = findReservation(reservation);
	string resHikeName = printPtr->getHikeName();
	int memberID = printPtr->getMemberID();

	double reservationPrice = hikeList.getPrice(resHikeName);
	double discountPrice = reservationPrice -
		(memberList.getPoints(memberID) / 100);

	hikeList.printByHikeName(resHikeName);
	
	if (reservationPrice != discountPrice)
	{
		cout << "\n\tDiscounted price using points: $" << fixed
			<< setprecision(2) << discountPrice << "\n";
	}
}

void Reservations::clearList()
{
	while (first) {
		Node* temp = first;
		first = first->getNext();
		delete temp;
	}

	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	clearList();
}

