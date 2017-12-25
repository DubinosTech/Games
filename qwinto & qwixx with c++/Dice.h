#ifndef DICE
#define DICE

#include <iostream>
#include <vector>
#include <random>
#include <list>


using namespace std;
enum Color {INVALID, RED, YELLOW, GREEN, BLUE, WHITE};

struct RandomDice
{
	static uniform_int_distribution<int> die;
	static default_random_engine generator;
};

struct Dice
{
	Dice(Color _color);
	const Color d_color;

	friend ostream& operator<<(ostream& _out, const Dice& _dice);

	int d_face;
	int roll();
};

struct RollOfDice : public vector<Dice>
{
	operator int() const;
	RollOfDice pair(const int _index1, const int _index2) const;
	friend ostream& operator<<(ostream& _out, const RollOfDice& _roll);
	RollOfDice roll();
};

#endif
