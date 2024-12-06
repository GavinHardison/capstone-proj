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

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& theHike)
{
    out << "\t" << theHike.hikeName << " (" << theHike.location << ")"
        << "\n\t  " << "Difficulty: ";

    switch (theHike.difficulty)
    {
        case 'e':
            out << "easy";
            break;
        case 'm':
            out << "moderate";
            break;
        case 's':
            out << "strenuous";
            break;
    }

    out << "\n\t  Duration: " << theHike.duration << " day(s)\n";

    return out;
}

string Hike::getLocation() const
{
    return location;
}

int Hike::getDuration() const
{
    return duration;
}

char Hike::getDifficulty() const
{
    return difficulty;
}

string Hike::getHikeName() const
{
    return hikeName;
}

bool Hike::operator<(const Hike& otherHike) const
{
    return (location < otherHike.location);
}