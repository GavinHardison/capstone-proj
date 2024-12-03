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

#ifndef INTERFACE_H
#define INTERFACE_H

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>

void displayMenu();

void processReservation(const HikeList& hike, MemberList& member, 
	Reservations& reservation);

void chooseByLocation(const HikeList& hike, MemberList& member,
	Reservations& reservation);
void chooseByDuration(const HikeList& hike, MemberList& member,
	Reservations& reservation);
void chooseByDifficulty(const HikeList& hike, MemberList& member,
	Reservations& reservation);
void chooseByPrice(const HikeList& hike, MemberList& member,
	Reservations& reservation);

int askIfMember(MemberList& memberName);
int addNewMember(MemberList& newMember);

void makeReservation(const HikeList& hike, MemberList& member,
	Reservations& reservation);
void viewReservation(const HikeList& hike, MemberList& member,
	Reservations& reservation);
void cancelReservation(const HikeList& hike, MemberList& member,
	Reservations& reservation);
void askToReserve(const HikeList& hike, MemberList& member,
	Reservations& reservation);

#endif