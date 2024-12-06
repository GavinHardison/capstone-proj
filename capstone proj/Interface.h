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

void displayMenu();
void processReservation(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
void chooseByLocation(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
void chooseByDuration(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
void chooseByDifficulty(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
void chooseByPrice(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
int askIfMember(MemberList& memberList);
int addNewMember(MemberList& memberList);
void makeReservation(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
void viewReservation(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
void cancelReservation(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);
void askToReserve(const HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

#endif