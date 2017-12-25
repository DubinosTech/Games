#ifndef QWINTO_SCORE_SHEET
#define QWINTO_SCORE_SHEET

#include "Dice.h"
#include "QwintoRow.h"
#include "ScoreSheet.h"

using namespace std;
class QwintoScoreSheet : public ScoreSheet
{

public:

    QwintoScoreSheet(string _name);
	~QwintoScoreSheet();
	virtual bool operator!();
	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1);
	virtual int calcTotal();
	virtual Row& operator[](Color _color);




};


#endif
