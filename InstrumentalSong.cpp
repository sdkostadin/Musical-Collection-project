#include "InstrumentalSong.h"

InstrumentalSong::InstrumentalSong()
	: bandName("")
{
}

std::string InstrumentalSong::getBandName() const
{
	return bandName;
}

void InstrumentalSong::setBandName(std::string name)
{
	bandName = name;
}

void InstrumentalSong::print()
{
	Song::print();
	std::cout << "BandName: " << bandName;
}
