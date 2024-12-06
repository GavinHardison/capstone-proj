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

#include <iostream>
#include <algorithm>

using namespace std;

void MemberList::addMember(const std::string& firstName,
	const std::string& lastName)
{
	int nextID = MEMBER_ID + static_cast<int>(memberList->size());

	Member newMember(firstName, lastName);
	newMember.setID(nextID);

	memberList->insert(newMember);

}

void MemberList::addMember(const std::string& firstName,
	const std::string& lastName, int points)
{
	int nextID = MEMBER_ID + static_cast<int>(memberList->size());

	Member newMember(firstName, lastName);
	newMember.setID(nextID);
	newMember.addPoints(points);

	memberList->insert(newMember);
}

int MemberList::getLastID() const
{
	return memberList->rbegin()->getID();
}

int MemberList::getPoints(int memberID) const
{
	auto getPointsIter = find_if(memberList->begin(), memberList->end(),
		[memberID](const Member& member)
		{ return member.getID() == memberID; });

	return getPointsIter->getPoints();
}

void MemberList::printMember(int memberID,
	const std::string& lastName) const
{
	auto printMemberIter = find_if(memberList->begin(), memberList->end(),
		[memberID](const Member& member) { return member.getID()
		== memberID; });

	if (printMemberIter != memberList->end() &&
		printMemberIter->getLastName() == lastName)
	{
		printMemberIter->printMember();

		cout << "\tMembership # " << printMemberIter->getID() << endl;
	}
}

void MemberList::clearList()
{
	memberList->clear();
}

MemberList::~MemberList()
{
	delete memberList;
	memberList = nullptr;
}