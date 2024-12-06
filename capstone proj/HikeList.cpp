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

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void HikeList::addHike(const Hike& hike, double price)
{
	hikeList.insert(make_pair(hike, price));
}

void HikeList::addHike(const string& location, const string& hikeName,
	int duration, char difficulty, double price)
{
	hikeList.insert(make_pair(Hike::Hike(location, hikeName, duration,
		difficulty), price));
}

double HikeList::getPrice(const string& hikeName) const
{
	auto priceIter = find_if(hikeList.begin(), hikeList.end(),
		[hikeName](const pair<Hike, double>& getPricePair)
		{ return getPricePair.first.getHikeName() == hikeName; });

	return priceIter->second;
}

void HikeList::printAllLocations() const
{
	auto iter = hikeList.begin();

	while (iter != hikeList.end())
	{
		cout << "\t" << iter->first.getLocation() << "\n";
		iter = hikeList.upper_bound(iter->first);
	}

	cout << "\n";
}

void HikeList::printByLocation(const string& location) const
{
	for (auto iter = hikeList.begin(); iter != hikeList.end(); ++iter)
	{
		auto locationIter = find_if(iter, hikeList.end(),
			[&location](const pair <Hike, double>& printByLocationPair)
			{ return printByLocationPair.first.getLocation()
			== location; });

		if (iter->first.getLocation() == location)
		{
			cout << locationIter->first << "\t  Price (per person): $ " << fixed
				<< setprecision(2) << locationIter->second << "\n\n";
		}
	}
}

void HikeList::printByDuration() const
{
	multimap<int, string> durationMap;

	for (const auto& durationPair : hikeList)
	{
		durationMap.insert(make_pair(durationPair.first.getDuration(),
			durationPair.first.getHikeName() + ", " +
			durationPair.first.getLocation()));
	}

	for (const auto& durationMapPair : durationMap)
	{
		cout << "\t(" << durationMapPair.first << ") "
			<< durationMapPair.second << "\n";
	}

	cout << "\n";
}

void HikeList::printByDuration(int days) const
{
	for (const auto& durationPair : hikeList)
	{
		if (durationPair.first.getDuration() == days)
		{
			cout << durationPair.first << "\n";
		}
	}
}

void HikeList::printByDifficulty(char difficulty) const
{
	for (const auto& durationPair : hikeList)
	{
		if (durationPair.first.getDifficulty() == difficulty)
		{
			cout << "\t(" << difficulty << ") "
				<< durationPair.first.getHikeName() << ", "
				<< durationPair.first.getLocation() << "\n";
		}
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> priceMap;

	for (const auto& pricePair : hikeList)
	{
		priceMap.emplace(pricePair.second,
			make_pair(pricePair.first.getLocation(),
				pricePair.first.getHikeName()));
	}

	for (const auto& durationMapPair : priceMap)
	{
		cout << "\t$" << fixed << setw(8) << setprecision(2)
			<< right << durationMapPair.first << " - "
			<< durationMapPair.second.first
			<< " (" << durationMapPair.second.second << ")\n";
	}

	cout << "\n";
}

void HikeList::printByHikeName(const std::string& hikeName) const
{
	auto hikeNameIter = find_if(hikeList.begin(), hikeList.end(),
		[hikeName](const pair<Hike, double>& getPricePair)
		{ return getPricePair.first.getHikeName() == hikeName; });

	cout << "\t" << hikeName << " (" << hikeNameIter->first.getLocation()
		<< ")" 
		<< "\n\t  Difficulty: ";

	switch (hikeNameIter->first.getDifficulty())
	{
		case 'e':
			cout << "easy";
			break;
		case 'm':
			cout << "moderate";
			break;
		case 's':
			cout << "strenuous";
			break;
	}

	cout << "\n\t  Duration: " << hikeNameIter->first.getDuration()
		<< " day(s)"
		<< "\n\t  $" << fixed << setprecision(2) << hikeNameIter->second
		<< "\n";
}

void HikeList::clearList()
{
	hikeList.clear();
}