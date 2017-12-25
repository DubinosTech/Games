#ifndef QWIXX_ROW
#define QWIXX_ROW

#include <iomanip>

#include "Dice.h"
#include "Row.h"

using namespace std;



template <class rowType, const Color d_c>
class QwixxRow : public Row
{

public:
    rowType d_row;

	QwixxRow();
	bool validate(int _index, RollOfDice roll);
	 virtual int & operator[](const int _index);
	 virtual void print(ostream& _out) const;

	const virtual int & operator[](const int _index) const;

};



template <typename rowType, const Color d_c>
bool QwixxRow<rowType, d_c>::validate(int _index, RollOfDice _roll)
{

	if (_index < 0 || _index > 10)
		return false;

	if ((*this)[_index] != 0)
		return false;


	bool found = false;
	for (auto die : _roll)
	{
		if (die.d_color == d_c)
			found = true;
	}
	if (!found)
		return false;


	int playedBoxCount = 0;
	for (int i = 0; i < d_row.size(); i++) {
		if ((*this)[i] == 1) {
			playedBoxCount++;
			if (i > _index)
				return false;
		}
	}

	if (playedBoxCount > 5)
        this->_locked = true;
        return false;

	return true;
}


template<class rowType, const Color d_c>
QwixxRow<rowType, d_c>::QwixxRow()
{
    _locked = false;
	if ((d_c == Color::RED) || (d_c == Color::YELLOW))
       {

        int i = 2;
        while( i < 13) {
            d_row.push_back(i);
                 i++;
		}}
	if ((d_c == Color::GREEN) || (d_c == Color::BLUE))
		{int i = 12;
		while( i > 1 ) {
            d_row.push_back(i);
              i--;
		}}
}

template<typename rowType, Color d_c>
int & QwixxRow<rowType, d_c>::operator[](int _index)
{
    auto iter = d_row.begin();
   advance(iter, _index);
    return *iter;
}

template<typename rowType, Color d_c>
const int & QwixxRow<rowType, d_c>::operator[](int _index) const
{
    auto iter = d_row.begin();
    advance(iter, _index);
    return *iter;
}




#endif
