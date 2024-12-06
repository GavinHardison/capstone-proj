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

#include "HikeList.h"
#include "HikeReader.h"

#include "MemberList.h"
#include "MemberReader.h"

#include "ReservationReader.h"

#include "Interface.h"

#include <iostream>


using namespace std;

int main()
{
	MemberList memberList1;
	HikeList hikeList1;
	Reservations reservations1;

	getMemberData(memberList1);
	getHikeData(hikeList1);
	getReservationsData(reservations1);

	displayMenu();

	processReservation(hikeList1, memberList1, reservations1);
	
	return 0;
}