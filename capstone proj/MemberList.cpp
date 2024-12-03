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
	if (memberList->empty())
	{
		return -1;
	}

	return memberList->rbegin()->getID();
}

int MemberList::getPoints(int memberID) const
{
	auto it = find_if(memberList->begin(), memberList->end(), 
		[memberID](const Member& member) { return member.getID() 
		== memberID; });

	if (it != memberList->end())
	{
		return it->getPoints();
	}

	return -1;
}

void MemberList::printMember(int memberID, 
	const std::string& lastName) const
{
	auto it = find_if(memberList->begin(), memberList->end(), 
		[memberID](const Member& member) { return member.getID() 
		== memberID; });

	if (it != memberList->end() && it->getLastName() == lastName)
	{
		it->printMember();
		cout << "\tMembership # " << it->getID() << endl;
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