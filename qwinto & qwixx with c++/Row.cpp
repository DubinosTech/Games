#include "Row.h"


using namespace std;




ostream& operator<<(ostream& _out, const Row& _row)
{
    _row.print(_out);
    return _out;
}

void Row::printNumber(ostream& _out, int _value) const
{
    if (_value == 0)
        _out << "  ";
    else if (_value == -1)
        _out << "XX";
    else
        _out << setw(2) << _value;
}
