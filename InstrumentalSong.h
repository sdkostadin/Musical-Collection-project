#pragma once
#include "Song.h"
class InstrumentalSong : public Song
{
public:
	InstrumentalSong();
	
	virtual std::string getBandName() const;
	virtual void setBandName(std::string name);
	
	virtual void print() override;
private:

	std::string bandName;
};

