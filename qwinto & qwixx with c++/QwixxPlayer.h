#ifndef QWIXXPLAYER
#define QWIXXPLAYER

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "Dice.h"
#include "QwixxScoreSheet.h"
#include "Player.h"

using namespace std;
class QwixxPlayer : public Player
{
public:
	virtual int convert_to_index(Color _color);
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll);
	QwixxPlayer(string _name);
	virtual ~QwixxPlayer();
	virtual void inputAfterRoll(RollOfDice& _roll);
};


#endif
