#include "QwixxPlayer.h"


using namespace std;

//initialise le constructeur par le user name
QwixxPlayer::QwixxPlayer(std::string _name) : Player( new QwixxScoreSheet(_name) ) {}


//methode interagissant avec l user apres le roll

RollOfDice QwixxPlayer::inputBeforeRoll(RollOfDice& _roll)
{
    d_active = true;

  cout << "\n Quel de voulez vous jouer ?" << std::endl;
   cout << "(separes les donnes entrees par les espaces (ex red blue yellow green)): \n" <<std::endl;

	vector<Color> dice_colors = get_color_index_vect(std::cin);

    RollOfDice rd;
    rd.push_back(_roll[4]);
    rd.push_back(_roll[5]);
    for(auto color : dice_colors)
        rd.push_back(_roll[convert_to_index(color)]);

    return rd;
}

//methode interagissant avec l user apres le roll
void QwixxPlayer::inputAfterRoll(RollOfDice& _roll)
{
    std::cout << _roll;
    std::cout << *d_ScoreSheet;

    if(!d_active)
    {
        char answer;
        std::cout << "\nVoulez vous store ce score \n? [y/n] ";
        std::cin >> answer;
		std::cin.ignore(256, '\n');
        if(answer == 'n')
            return;
    }

    for (int i = 0; i < 2; ++i)
    {
        Color color;
        int index;

        std::cout << "Dans quelle ligne voulez vous sauvegarder le score? (enter color (red blue ...)) \n";

		color = get_color_index_vect(std::cin)[0];

        std::cout << "\n Dans quel columne (index) desiriez vous ?" << std::endl;
        std::cout << "(en tenant compte du debut de la ligne) \n";
        std::cin >> index;
		std::cin.ignore(256, '\n');

        if(d_ScoreSheet->score(_roll, color, index-1))
            return;

        else
        {
            std::cout << "\nCette location est invalide ,veuillez ressayer\n" << std::endl;
            if(d_active)
                std::cout << "(Dernier essai avant qu on ne marque comme echec lancee)" << std::endl;
        }
    }

    if(d_active)
        d_ScoreSheet->addFailedThrow();
    d_active = false;

}

//methode convertisant les couleurs en index
int QwixxPlayer::convert_to_index(Color _color)
{

	if(_color == Color::RED)
		return 0;
    else if(_color == Color::WHITE)
		return 4;


	else if(_color == Color::GREEN)
		return 2;
    else if(_color == Color::YELLOW)
		return 1;


	else if(_color == Color::BLUE)
		return 3;



    else
        return 0;
}

//destructeur du qwixx player
QwixxPlayer::~QwixxPlayer() {
     delete d_ScoreSheet; }
