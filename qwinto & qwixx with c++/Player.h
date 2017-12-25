#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include <sstream>

#include "Dice.h"
#include "ScoreSheet.h"

using namespace std;

class Player
{
protected:
	bool d_active = false;
	ScoreSheet *d_ScoreSheet;
	vector<Color> get_color_index_vect(istream& _in);
	Color convert_to_color(string _str);
	virtual int convert_to_index(Color _color) = 0;

public:

	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll) = 0;
    bool operator!();
    Player(ScoreSheet *_ss);
	virtual ~Player() = default;
    virtual void inputAfterRoll(RollOfDice& _roll) = 0;
};

#endif
