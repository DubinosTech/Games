#include "QwixxRow.h"

using namespace std;

//methode initialisant la ligne du scoresheet de blue
template <>
void QwixxRow<list<int>, Color::BLUE>::print(ostream& _out) const
{
	_out << "Blue    ";
	int i=0;
	while(i<11)

    {
        _out << '|';
        printNumber(_out, (*this)[i]);
        ++i;
    }
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' << endl;
}

//methode initialisant la ligne du scoresheet de red
template <>
void QwixxRow<vector<int>, Color::RED>::print(ostream& _out) const
{
	_out << "Red     ";
	int i=0;
	while(i<11)

    {	_out << '|';
		printNumber(_out, (*this)[i]);++i;
	}
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' << endl;
}

//methode initialisant la ligne du scoresheet de yellow
template <>
void QwixxRow<vector<int>, Color::YELLOW>::print(ostream& _out) const
{
	_out << "Yellow  ";
    int i=0;
	while(i<11)

    {
        _out << '|';
        printNumber(_out, (*this)[i]);++i;
    }
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' <<endl;
}


//methode initialisant la ligne du scoresheet de green
template <>
void QwixxRow<list<int>, Color::GREEN>::print(ostream& _out) const
{
	_out << "Green   ";
   int i=0;
	while(i<11){  _out << '|';
        printNumber(_out, (*this)[i]);++i;
    }
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' << endl;
}




