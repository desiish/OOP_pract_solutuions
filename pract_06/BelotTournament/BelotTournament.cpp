#include "BelotTournament.h"
#include <iostream>
void BelotTournament::copyFrom(const BelotTournament& other)
{
	_maxCountOfTeams = other._maxCountOfTeams;
	_currentCountOfTeams = other._currentCountOfTeams;
	_teams = new Team[_maxCountOfTeams];
	for (int i = 0; i < _currentCountOfTeams; i++)
		_teams[i] = other._teams[i];
}
void BelotTournament::free()
{
	delete[] _teams;
	_teams = nullptr;
	_maxCountOfTeams = 0;
	_currentCountOfTeams = 0;
}
void BelotTournament::resize(size_t newCapacity)
{
	Team* newTeam = new Team[newCapacity];
	for (int i = 0; i < _currentCountOfTeams; i++)
		newTeam[i] = _teams[i];
	delete[] _teams;
	_teams = newTeam;
	_maxCountOfTeams = newCapacity;
}
void BelotTournament::validateData()
{
	if (_currentCountOfTeams < 2)
	{
		return;
	}
	if(_currentCountOfTeams%2 == 1)
		deleteTeam(_currentCountOfTeams - 1);
	for (int i = 0; i < _currentCountOfTeams; i++)
	{
		_teams[i].changeStatus(false);
		_teams[i].setPoints(0);
	}
}
BelotTournament::BelotTournament()
{
	_maxCountOfTeams = 8;
	_currentCountOfTeams = 0;
	_teams = new Team[_maxCountOfTeams];
}
BelotTournament::BelotTournament(const BelotTournament& other)
{
	copyFrom(other);
}
BelotTournament& BelotTournament::operator=(const BelotTournament& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
BelotTournament::~BelotTournament()
{
	free();
}
void BelotTournament::addTeam(const char* name1, const char* pos1, size_t sal1, const char* name2, const char* pos2, size_t sal2)
{
	if (_currentCountOfTeams == _maxCountOfTeams)
		resize(2 * _maxCountOfTeams);
	Team team(name1, pos1, sal1, name2, pos2, sal2);
	_teams[_currentCountOfTeams++] = team;
}
void BelotTournament::playRound(int team1, int team2, bool& team1HasWon)
{
	_teams[team1].setPoints(0);
	_teams[team2].setPoints(0);
	size_t points_t1, points_t2;
	while (1)
	{
		std::cout << "Team " << _teams[team1].getParticipant(1).getName()<<" and "<<_teams[team1].getParticipant(2).getName() << " points: ";
		std::cin >> points_t1;
		std::cout << "Team " << _teams[team2].getParticipant(1).getName() << " and " << _teams[team2].getParticipant(2).getName() << " points: ";
		std::cin >> points_t2;
		_teams[team1].addPoints(points_t1);
		_teams[team2].addPoints(points_t2);
		if (_teams[team1].getPoints() >= WINNING_POINTS)
		{
			team1HasWon = true;
			std::cout << "Team " << _teams[team1].getParticipant(1).getName() << " and " << _teams[team1].getParticipant(2).getName() << " has won this round! " << std::endl;
			break;
		}
		if 	(_teams[team2].getPoints() >= WINNING_POINTS)
		{
			team1HasWon = false;
			std::cout << "Team " << _teams[team2].getParticipant(1).getName() << " and " << _teams[team2].getParticipant(2).getName() << " has won this round! " << std::endl;
			break;
		}
	}
}
void BelotTournament::duel(int indexOfT1, int indexOfT2)
{
	if (indexOfT1 >= _currentCountOfTeams || indexOfT2 >= _currentCountOfTeams || indexOfT1 == indexOfT2)//indexes strart from 0
		return;
	unsigned team1_wins, team2_wins;
	team1_wins = team2_wins = 0;
	bool team1HasWon = false;
	for (int i = 0; i < 3; i++)
	{
		playRound(indexOfT1, indexOfT2, team1HasWon);
		if (team1HasWon)
			team1_wins++;
		else
			team2_wins++;
		if (team1_wins == 2)
		{
			team1HasWon = true;
			break;
		}
		if (team2_wins == 2)
		{
			team1HasWon = false;
			break;
		}
	}
	if (team1HasWon)
	{
		manageLoserTeamMoney(indexOfT2);
		deleteTeam(indexOfT2);
	}
	else
	{
		manageLoserTeamMoney(indexOfT2);
		deleteTeam(indexOfT1);
	}
}
void BelotTournament::manageLoserTeamMoney(int indexOfTeam)
{
	(_donations += (double)(_teams[indexOfTeam].getParticipant(1).getSalary() / 50)) += (double)(_teams[indexOfTeam].getParticipant(2).getSalary() / 50);
	(_reward += (double)(_teams[indexOfTeam].getParticipant(1).getSalary() / 100)) += (double)(_teams[indexOfTeam].getParticipant(2).getSalary() / 100);
	_teams[indexOfTeam].changeSalary((_teams[indexOfTeam].getParticipant(1).getSalary() * 97) / 100, 1);
	_teams[indexOfTeam].changeSalary((_teams[indexOfTeam].getParticipant(2).getSalary() * 97) / 100, 2);
}
void BelotTournament::deleteTeam(int indexOfT)
{
	if (indexOfT >= _currentCountOfTeams || _currentCountOfTeams == 1)
		return;
	for (int i = indexOfT; i < _currentCountOfTeams - 1; i++)
		std::swap(_teams[i], _teams[i+1]);
	_currentCountOfTeams--;
	if (_currentCountOfTeams == _maxCountOfTeams / 4)
		resize(_maxCountOfTeams / 2);
}
double BelotTournament::getDonations() const
{
	return _donations;
}
size_t BelotTournament::chooseValidOpponent() const
{
	while (1)
	{
		int ind = rand() % _currentCountOfTeams;
		if (!_teams[ind].getStatus())
		{
			_teams[ind].changeStatus(true);
			return ind;
		}
	}
}
namespace
{
	unsigned myLog2(unsigned n)
	{
		if(n != 0)
		{
			unsigned count = 0;
			while (n)
			{
				n >>= 1;
				count++;
			}
			return count - 1;
		}
	}
}
void BelotTournament::PlayTournament()
{
	validateData();
	if (_currentCountOfTeams < 2)
	{
		std::cout << "Not enough teams!" << std::endl;
		return;
	}
	int countOfStages = myLog2(_currentCountOfTeams);
	for (int i = 0; i < countOfStages; i++)
	{
		int countOfMatches = _currentCountOfTeams / 2;
		for (int i = 0; i < countOfMatches; i++)
		{
			int team1 = chooseValidOpponent();
			int team2 = chooseValidOpponent();
			duel(team1, team2);
		}
		validateData();
	}
	_teams[0].changeSalary((_teams[0].getParticipant(1).getSalary() + _reward / 2.0), 1);
	_teams[0].changeSalary((_teams[0].getParticipant(2).getSalary() + _reward / 2.0), 2);
	std::cout << "Total Donated Money: " << _donations;
}
