#include "QwixxScoreSheet.h"


using namespace std;
//destructeur de qwixx scoresheet
QwixxScoreSheet::~QwixxScoreSheet()
{
	for(auto& row : d_scoreSheetRows)
	{
		delete row;
	}
}
//methode retournant la validiter d une ligne de couleur du scoresheet
bool QwixxScoreSheet::validate(RollOfDice _dice, Color _color, int _pos)
{
	if (_color != Color::RED && _color != Color::YELLOW && _color != Color::GREEN && _color != Color::BLUE) {
		return false;
	}
	else {
		switch (_color)
		{
        case Color::BLUE:
			return d_scoreSheetRows[3]->validate(_pos, _dice);
		case Color::YELLOW:
			return d_scoreSheetRows[1]->validate(_pos, _dice);

		case Color::GREEN:
			return d_scoreSheetRows[2]->validate(_pos, _dice);

        case Color::RED:
			return d_scoreSheetRows[0]->validate(_pos, _dice);


		default:
			return false;
		}
	}
}
//methode calculant le socre total
int QwixxScoreSheet::calcTotal()
{
	int score = 0;
	score -= d_failedThrows * 5;
       int i = 0;
	while(i < 4){
		int cells = 0;
		int j = 0;
		while( j < 11){
			if((*d_scoreSheetRows[i])[j] > 0){
				++cells;
				++j;
			}

			++i;
		}

		switch(cells){
			case (1):	score += 1;
			case (2):	score += 3;
			case (3):	score += 6;
			case (4):	score += 10;
			case (5):	score += 15;
			case (6):	score += 21;
			case (7):	score += 28;
			case (8):	score += 36;
			case (9):	score += 45;
			case (10):	score += 55;
			case (11):	score += 66;
			case (12):	score += 78;
			default:	score += 0;
		}
	}
	return score;
}


bool QwixxScoreSheet::operator!()
{if (ScoreSheet::operator!())
		return true;

    return (d_lockedRows >= 2);
}


//methode retournant la ligne selectionner
Row& QwixxScoreSheet::operator[](Color _color)
{
	switch(_color)
	{

        case Color::GREEN :
			return *d_scoreSheetRows[2];

		case Color::YELLOW :
			return *d_scoreSheetRows[1];

        case Color::RED :
			return *d_scoreSheetRows[0];


		case Color::BLUE :
			return *d_scoreSheetRows[3];
		default:
			return *d_scoreSheetRows[0];
	}
}

//initialisation du constructeur
QwixxScoreSheet::QwixxScoreSheet(string _name) : ScoreSheet(_name)
{
	d_scoreSheetRows.reserve(4);

	d_scoreSheetRows.push_back( new QwixxRow<vector<int>, Color::RED>() );
	d_scoreSheetRows.push_back( new QwixxRow<vector<int>, Color::YELLOW>() );
	d_scoreSheetRows.push_back( new QwixxRow<list<int>, Color::GREEN>() );
	d_scoreSheetRows.push_back( new QwixxRow<list<int>, Color::BLUE>() );
}

