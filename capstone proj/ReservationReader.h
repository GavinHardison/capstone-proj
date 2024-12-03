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

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservations(ifstream& infile, Reservations& reservations)
{
	int memberID = 0;
	string hikeName;

	while (!infile.eof())
	{
		infile >> memberID >> hikeName;
		reservations.addReservation(memberID, hikeName);
	}
}

void getReservationsData(Reservations& reservations) 
{
	ifstream infile;
	
	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservations(infile, reservations);

	infile.close();
}