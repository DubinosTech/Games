#include "ScoreSheet.h"



using namespace std;


//methode marquant le score du joueur
bool ScoreSheet::score(RollOfDice _dice, Color _color, int _pos)
{
    if(validate( _dice, _color, _pos ))
    {
    	Row& row = (*this)[_color];
    	row[_pos] = _dice;
    	setTotal();
    	return true;
    }

    return false;
}
//methode  initialisant le score sheet avec nom,essaie echouee,et les points
ScoreSheet::ScoreSheet(string _name) : d_name(_name), d_failedThrows(0), d_lockedRows(0), d_points(0)
{}

//methodes qui retourne les points
int ScoreSheet::setTotal(){
    d_points = calcTotal();
    return d_points;
}
//methodes retournant une lancee echouee

bool ScoreSheet::operator!()
{
	if(d_failedThrows >= 4)
		return true;
	return false;
}
//methodes qui ajoutes les lancees echouees
void ScoreSheet::addFailedThrow() {
    ++d_failedThrows;}


//methodes retourne le scoresheet sous forme de ostream
ostream& operator<<(ostream& _out, const ScoreSheet& _sS)
{
	_out << "\n Nom du joueur -->: " << _sS.d_name << "   Points-->:  " << _sS.d_points << std::endl;

	for(const auto& row : _sS.d_scoreSheetRows)
	{
		_out << "   ---------------------------------------------   " << std::endl;
		_out << *row;
	}

	_out << " ---------------------------------------------    \n" << std::endl;
	_out << "Lancees echouees: ";
	int i = 1;
	while( i <= _sS.d_failedThrows)
	{
		_out << i << ' ';
		 ++i;
	}
	_out << endl;

	return _out;
}

//methodes pour bloquer l entrer des valeurs dans les lignes
void ScoreSheet::addLockedRow() {
     ++d_lockedRows; }
