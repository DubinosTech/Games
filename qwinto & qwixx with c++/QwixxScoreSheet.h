#ifndef QWIXX_SCORE_SHEET
#define QWIXX_SCORE_SHEET

#include "QwixxRow.h"
#include "ScoreSheet.h"
#include "Dice.h"


using namespace std;

class QwixxScoreSheet : public ScoreSheet
{

public:

	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1);
	virtual int calcTotal();
	QwixxScoreSheet(string _name);
	~QwixxScoreSheet();
	virtual bool operator!();
	virtual Row& operator[](Color _color);



};

#endif
