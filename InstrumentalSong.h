#ifndef INSTRUMENTALSONG_H_
#define INSTRUMENTALSONG_H_
#pragma once
#include "Song.h"
class InstrumentalSong : public Song
{
public:
	InstrumentalSong();
	
	std::string getBandName() const;
	void setBandName(std::string name);
	
	virtual void print() override;
private:

	std::string bandName;
};
#endif
