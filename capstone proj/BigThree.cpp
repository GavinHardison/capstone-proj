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

#include "MemberList.h"
#include "Reservations.h"

#include <iostream>

using namespace std;


MemberList::MemberList(const MemberList& otherMemberList)
{
    memberList = new std::set<Member>(otherMemberList.memberList->begin(),
        otherMemberList.memberList->end());
}

MemberList& MemberList::operator=(const MemberList& otherMemberList)
{
    if (this == &otherMemberList)
    {
        cerr << "Attempted assignment to itself." << endl;
        return *this;
    }

    memberList = new std::set<Member>(otherMemberList.memberList->begin(),
        otherMemberList.memberList->end());
    return *this;
}

Reservations::Reservations(const Reservations& otherReservation) 
    :first(nullptr), last(nullptr), count(0) 
{
    Node* current = otherReservation.first;

    if (current  != nullptr)
    {
        while (current != nullptr)
        {
            addReservation(current->getMemberID(), 
                current->getHikeName());
            current = current->getNext();
        }

    }
}

Reservations& Reservations::operator=(const Reservations& 
    otherReservation)
{
    if (this == &otherReservation) 
    {
        cerr << "Attempted assignment to itself." << std::endl;
        return *this;
    }
    else if (otherReservation.first == nullptr) 
    {
        clearList();
    }
    else if (first == nullptr) 
    {
        copyCallingObjIsEmpty(otherReservation);
    }
    else if (count == otherReservation.count) 
    {
        copyObjectsSameLength(otherReservation);
    }
    else if (count > otherReservation.count) 
    {
        copyCallingObjLonger(otherReservation);
    }
    else 
    {
        copyCallingObjShorter(otherReservation);
    }

    return *this;
}


void Reservations::copyCallingObjIsEmpty(const Reservations& 
    otherReservation)
{
    Node* current = otherReservation.first;

    while (current != nullptr) 
    {
        addReservation(current->getMemberID(), current->getHikeName());
        current = current->getNext();
    }
}

void Reservations::copyObjectsSameLength(const Reservations& 
    otherReservation)
{
    Node* currentThis = first;
    Node* currentOther = otherReservation.first;

    while (currentThis != nullptr && currentOther != nullptr) 
    {
        currentThis->setReservationNo(currentOther->getReservation());
        currentThis->setMemberID(currentOther->getMemberID());
        currentThis->setHikeName(currentOther->getHikeName());

        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }
}

void Reservations::copyCallingObjLonger(const Reservations& 
    otherReservation)
{
    Node* currentThis = first;
    Node* currentOther = otherReservation.first;

    while (currentOther != nullptr) 
    {
        currentThis->setReservationNo(currentOther->getReservation());
        currentThis->setMemberID(currentOther->getMemberID());
        currentThis->setHikeName(currentOther->getHikeName());

        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }

    Node* toDelete = currentThis;

    while (toDelete != nullptr) {
        Node* temp = toDelete->getNext();
        delete toDelete;
        toDelete = temp;

        --count;
    }

    last = currentThis ? currentThis->getPrev() : nullptr;
    if (last) last->setNext(nullptr);
}

void Reservations::copyCallingObjShorter(const Reservations& 
    otherReservation)
{
    Node* currentThis = first;
    Node* currentOther = otherReservation.first;

    while (currentThis != nullptr) {
        currentThis->setReservationNo(currentOther->getReservation());
        currentThis->setMemberID(currentOther->getMemberID());
        currentThis->setHikeName(currentOther->getHikeName());

        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }

    while (currentOther != nullptr) {
        addReservation(currentOther->getMemberID(), 
            currentOther->getHikeName());
        currentOther = currentOther->getNext();
    }
}