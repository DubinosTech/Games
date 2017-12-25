#ifndef ROW
#define ROW

#include <iostream>
#include <iomanip>


#include "Dice.h"

using namespace std;


class Row
{

public:
    virtual void print(ostream& _out) const = 0;
    bool _locked;
    void printNumber(ostream& _out, int _value) const;
    virtual ~Row() = default;
    virtual int &operator[](int _index) = 0;
    virtual bool validate(int _index, RollOfDice roll) = 0;
    friend ostream& operator<<(ostream& _out, const Row& _row);
};


#endif
