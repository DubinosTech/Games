#include "QwintoRow.h"

using namespace std;


//methode pour initialiser la ligne yellow
template <>
void QwintoRow<Color::YELLOW>::print(ostream& _out) const
{
	_out << "Yellow ----> ";
	int i=0;
	while (i < 10)
	{//la ligne suivante decide quel separateur a placer
		_out << (((i == 7) || (i == 8)) ? '%' : '|');
		QwintoRow<Color::YELLOW>::printNumber(_out, d_row[i]);
		++i;
	}
	_out << '|' << std::endl;
}


//methode pour initialiser la ligne red
template <>
void QwintoRow<Color::RED>::print(ostream& _out) const
{
	_out << "Red -------> ";
	int i=0;
	while (i < 10)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|');
		QwintoRow<Color::RED>::printNumber(_out, d_row[i]);
		++i;
	}
	_out << '|' << endl;
}




//methode pour initialiser la ligne blue
template <>
void QwintoRow<Color::BLUE>::print(ostream& _out) const
{
	_out << "Blue------>";
	int i=0;
	while (i < 10)
	{
		_out << (((i == 2) || (i == 3) || (i == 9)) ? '%' : '|');
		QwintoRow<Color::BLUE>::printNumber(_out, d_row[i]);
		++i;
	}
	_out << '%' << endl;
}
