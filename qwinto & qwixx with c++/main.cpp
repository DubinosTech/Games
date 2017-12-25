#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Dice.h"

#include "QwintoPlayer.h"
#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"

#include "QwixxPlayer.h"
#include "QwixxRow.h"
#include "QwixxScoreSheet.h"

using namespace std;

int main(int argc, char const *argv[])
{
	vector<Player*> players;
	RollOfDice rd;

	cout << "---------Bienvenue au jeu de  Qwinto/Qwixx-------------------------" << endl;

	cout << "Entrer la version de votre jeu " << endl;
	cout << "---Qwinto [1]---------ou--------- Qwixx[2]------" << endl;

	int gameVers = 0;
	cin >> gameVers;
	cin.ignore(256, '\n');

	int playerNum = 0;
	cout << "Veuillez entrer le nombre de joueur: " << endl;
	cin >> playerNum;
	cin.ignore(256, '\n');

	vector<std::string> playerNames;
	string name;


	for (int i = 0; i < playerNum; i++) {
		std::cout << "Joueur  " << i + 1 << "---> Nom : " << std::flush;
		std::cin >> name;
		std::cin.ignore(256, '\n');
		playerNames.push_back(name);
	}


	players.reserve(playerNum);


	if (gameVers == 1)
	{
		for (auto name : playerNames) {
			players.push_back(new QwintoPlayer(name));
		}
		rd.push_back(Dice(Color::RED));
		rd.push_back(Dice(Color::YELLOW));
		rd.push_back(Dice(Color::BLUE));
	}


	 else if (gameVers == 2)
	 {
	 	for (auto name : playerNames) {
	 		players.push_back(new QwixxPlayer(name));
	 	}
	 	rd.push_back(Dice(Color::RED));
	 	rd.push_back(Dice(Color::YELLOW));
	 	rd.push_back(Dice(Color::GREEN));
	 	rd.push_back(Dice(Color::BLUE));
	 	rd.push_back(Dice(Color::WHITE));
	 	rd.push_back(Dice(Color::WHITE));
	 }
    bool endCond = false;
	while (!endCond) {

		for(auto active_player : players)
		{
			RollOfDice current_roll = active_player->inputBeforeRoll(rd);
			for(auto player : players)
			{
				player->inputAfterRoll(current_roll);
			}
		}

        for(auto player : players){
            endCond = endCond || !*player;
        }

	}


	for(auto player : players)
		delete player;

	return 0;
}
