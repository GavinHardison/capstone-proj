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

#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int RESERVATION_START = 5001;

class Node
{
public:
	Node() : reservationNo(0), memberID(0), prev(nullptr),
		next(nullptr) {}
	Node(int member, const std::string& aHike, Node* newPrev,
		Node* newNext) : reservationNo(0), memberID(member),
		hikeName(aHike), prev(newPrev), next(newNext) {}
	int getReservation() const { return reservationNo; }
	int getMemberID() const { return memberID; }
	const std::string& getHikeName() const { return hikeName; }
	Node* getPrev() const { return prev; }
	Node* getNext() const { return next; }
	void setReservationNo(int reservation) { reservationNo =
		reservation; }
	void setMemberID(int member) { memberID = member; }
	void setHikeName(const std::string& aHike) { hikeName = aHike; }
	void setPrev(Node* newPrev) { prev = newPrev; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	int reservationNo;
	int memberID;
	std::string hikeName;
	Node* next;
	Node* prev;
};

class Reservations
{
public:
	Reservations() : first(nullptr), last(nullptr), count(0) {};
	Reservations(const Reservations& otherReservation);

	Reservations& operator=(const Reservations& otherReservation);

	int addReservation(int memberID, const std::string& hikeName);

	void cancelReservation(int reservation);
	
	void printReservation(int reservation, const HikeList& hikelist,
		const MemberList& memberList) const;
	
	void clearList();
	~Reservations();

private:
	Node* findReservation(int reservation) const;

	void copyCallingObjIsEmpty(const Reservations& otherReservation);
	void copyObjectsSameLength(const Reservations& otherReservation);
	void copyCallingObjLonger(const Reservations& otherReservation);
	void copyCallingObjShorter(const Reservations& otherReservation);

	Node* first;
	Node* last;
	int count;
};

#endif