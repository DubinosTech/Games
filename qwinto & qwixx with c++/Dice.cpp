#include <ctime>

#include "Dice.h"

using namespace std;

uniform_int_distribution<int> RandomDice::die{1,6};
default_random_engine RandomDice::generator{ static_cast<unsigned int>(time(NULL)) };

//methode pour qui appelle roll dice
Dice::Dice(Color _color) : d_color(_color)
{
	roll();
}
//methode pour retourner le numero du dee
int Dice::roll()
{
	return d_face = RandomDice::die(RandomDice::generator);
}
//methode pour storer la couleur du de
ostream& operator<<(ostream& _out, const Dice& _dice)
{
	switch(_dice.d_color)
	{
		case Color::RED:
            _out << "red ";
            break;

		case Color::YELLOW:
            _out << "yellow ";
            break;

		case Color::BLUE:
            _out << "blue ";
            break;

        case Color::GREEN:
            _out << "green ";
            break;

        case Color::WHITE:
            _out << "white  ";

	}

	_out << _dice.d_face;
	return _out;
}
//methode pour roll dice
RollOfDice RollOfDice::roll()
{//boucle pour roll le dice
	for(auto &die : *this)
	{
		die.roll();
	}
	return *this;
}



RollOfDice RollOfDice::pair(const int _index1, const int _index2) const
{
	RollOfDice pairedRoll;
	pairedRoll.push_back((*this)[_index1]);
	pairedRoll.push_back((*this)[_index2]);

	return pairedRoll;
}
//methode qui retourne le total
RollOfDice::operator int() const
{
	int total = 0;
	for(auto die : *this)
		total += die.d_face;
	return total;
}


//methode qui sauvegarde  le total et le  retourne comme ostream
ostream& operator<<(ostream& _out, const RollOfDice& _roll)
{
	_out << "Roll---->: ";
	for(auto die : _roll)
		_out << die << ", ";

	_out << "Total--->: " << static_cast<int>(_roll) << endl;

	return _out;
}
