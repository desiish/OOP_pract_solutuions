#include <iostream>
#include "BelotTournament.h"
int main()
{
	BelotTournament bt;
	bt.addTeam("Ivan", "Senior SE", 2500, "Petar", "Junior SE", 3600);
	bt.addTeam("Desi", "CEO", 1000000, "Kami", "CEO", 1000000);
	bt.addTeam("Moni", "Junior SE", 2000, "Toni", "Senior SE", 3500);
	bt.addTeam("Sisi", "Junior SE", 1000, "Hrisi", "Senior SE", 2000);
	bt.PlayTournament();
	return 0;
}