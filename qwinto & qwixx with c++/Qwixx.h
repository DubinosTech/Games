#ifndef QWIXX
#define QWIXX

#include <iostream>
#include <string>

#include "QwixxScoreSheet.h"
#include "Player.h"


using namespace std;
class QwixxPlayer : public Player
{

public:
    bool stage;

	QwixxPlayer() : stage(0) {}
	QwixxScoreSheet d_sS;
	~QwixxPlayer();
};

#endif
