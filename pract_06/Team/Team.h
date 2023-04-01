#pragma once
#include "SoftwareEngineer.h"
class Team
{
	SoftwareEngineer _participant1;
	SoftwareEngineer _participant2;
	size_t _sizeOfTeam = 2;
	size_t _points = 0;
	bool hasPlayedInRound = false;

public:
	Team() = default;
	Team(const char* name1, const char* pos1, size_t sal1, const char* name2, const char* pos2, size_t sal2);
	void setParticipant1(const char* name, const char* pos, size_t sal);
	void setParticipant2(const char* name, const char* pos, size_t sal);
	void addPoints(size_t points);
	void setPoints(size_t points);
	size_t getPoints() const;
	const SoftwareEngineer& getParticipant(int ind) const;
	void changeSalary(size_t newSalary, int ind);
	bool getStatus() const;
	void changeStatus(bool status);
};

