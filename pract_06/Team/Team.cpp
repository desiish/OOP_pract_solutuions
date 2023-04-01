#include "Team.h"
Team::Team(const char* name1, const char* pos1, size_t sal1, const char* name2, const char* pos2, size_t sal2): _participant1(name1, pos1, sal1),
																												_participant2(name2, pos2, sal2){}
void Team::setParticipant1(const char* name, const char* pos, size_t sal)
{
	_participant1.setName(name);
	_participant1.setPosition(pos);
	_participant1.setSalary(sal);
}
void Team::setParticipant2(const char* name, const char* pos, size_t sal)
{
	_participant2.setName(name);
	_participant2.setPosition(pos);
	_participant2.setSalary(sal);
}
const SoftwareEngineer& Team::getParticipant(int ind) const
{
	if (ind == 1)
		return _participant1;
	else if (ind == 2)
		return _participant2;
}
void Team::addPoints(size_t points)
{
	_points += points;
}
void Team::setPoints(size_t points)
{
	_points = points;
}
void Team::changeSalary(size_t newSalary, int ind)
{
	if (ind == 1)
		_participant1.setSalary(newSalary);
	else if (ind == 2)
		_participant2.setSalary(newSalary);
	else
		return;
}
size_t Team::getPoints() const
{
	return _points;
}
bool Team::getStatus() const
{
	return hasPlayedInRound;
}
void Team::changeStatus(bool status)
{
	hasPlayedInRound = status;
}