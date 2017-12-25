#ifndef SCORESHEET
#define SCORESHEET

#include <iostream>
#include <string>
#include <vector>

#include "Dice.h"
#include "Row.h"

using namespace std;

class ScoreSheet
{
public:
	string d_name;
	int d_failedThrows;
    int d_lockedRows;
	int d_points;

	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1) = 0;
	virtual int calcTotal() = 0;
	virtual Row& operator[](Color _color) = 0;

	vector<Row*> d_scoreSheetRows;

	ScoreSheet(string _name);
	virtual ~ScoreSheet() = default;
	bool score(RollOfDice _dice, Color _color, int _pos = -1);
	int setTotal();
	virtual bool operator!();
	void addFailedThrow();
    void addLockedRow();

	friend ostream& operator<<(ostream& _out, const ScoreSheet& _sS);
};


#endif
