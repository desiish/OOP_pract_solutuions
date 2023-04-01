#pragma once
#include "Team.h"
const size_t WINNING_POINTS = 151;
class BelotTournament
{
	Team* _teams;
	size_t _maxCountOfTeams = 8;
	size_t _currentCountOfTeams = 0;
	double _donations = 0;
	double _reward = 0;

	void copyFrom(const BelotTournament& other);
	void free();
	void resize(size_t newCapacity);

	void deleteTeam(int indexOfT);
	void validateData();
	size_t chooseValidOpponent() const;
	void manageLoserTeamMoney(int indexOfTeam);
	void playRound(int team1, int team2, bool& team1HasWon);
	void duel(int indexOfT1, int indexOfT2);
public:
	BelotTournament();
	BelotTournament(const BelotTournament& other);
	BelotTournament& operator=(const BelotTournament& other);
	~BelotTournament();

	void addTeam(const char* name1, const char* pos1, size_t sal1, const char* name2, const char* pos2, size_t sal2);
	void PlayTournament();
	double getDonations() const;
};

