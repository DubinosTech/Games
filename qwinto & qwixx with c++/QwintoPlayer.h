#ifndef QWINTOPLAYER
#define QWINTOPLAYER

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "Dice.h"
#include "Player.h"
#include "QwintoScoreSheet.h"

using namespace std;

class QwintoPlayer : public Player
{
protected:
	virtual int convert_to_index(Color _color);

public:
	QwintoPlayer(string _name);
	virtual ~QwintoPlayer();
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll);
	virtual void inputAfterRoll(RollOfDice& _roll);
};

#endif
