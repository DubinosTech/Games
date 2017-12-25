#include "QwintoPlayer.h"

using namespace std;


//methodes qui retourne 0 ,1,2 si les couleurs sont rouge,jaune,bleue
int QwintoPlayer::convert_to_index(Color _color)
{
	if(_color == Color::RED)
		return 0;

	else if(_color == Color::YELLOW)
		return 1;

	else if(_color == Color::BLUE)
		return 2;

    else
        return 0;

}

//methode initialisant le nom du joueur sur le scoresheet
QwintoPlayer::QwintoPlayer(string _name) : Player(new QwintoScoreSheet(_name)) {}
//methode  pour interagir avec interagir avec l utilisateur en lui demandant les couleurs des  dices de leur choix et renvoit ca
//
RollOfDice QwintoPlayer::inputBeforeRoll(RollOfDice& _roll)
{
	d_active = true;

	cout << "\nQuelle dice voulez vous jouer:  ?" << endl;
	cout << "(Tape les noms des  separes d espaces  comme : red blue yellow): " <<endl;

	vector<Color> dice_colors = get_color_index_vect(cin);

	RollOfDice rol;
	for(auto color : dice_colors)
		rol.push_back(_roll[convert_to_index(color)]);

	return rol;
}

//methode pour demander aux joueurs les donnes et ou les enregistrer
void QwintoPlayer::inputAfterRoll(RollOfDice& _roll)
{
	cout << _roll;
	cout << *d_ScoreSheet;

	if(!d_active)
	{
		char answer;
		cout << "Veux tu enregistrer cet roll? [y/n] ";
		cin >> answer;
		cin.ignore(256, '\n');
		if(answer == 'n')
			return;
	}

	for (int i = 0; i < 2; ++i)
	{
		Color color;
		int index;

		cout << "\nDans quelle ligne veux-tu storer cet roll en? (entree la couleur) ";

		color = get_color_index_vect(cin)[0];

		cout << "\nSur quelle coloumne veux tu storer ton score ?" << endl;
		cout << "(Commencer a penser a partir du debut de la ligne) \n";
		cin >> index;
		cin.ignore(256, '\n');

		if(d_ScoreSheet->score(_roll, color, index-1))
			return;

		else
		{
			cout << "Cette location est invalide veuiller ressayer " << endl;
			if(d_active)
				cout << "(derniere essaie avant qu on le marche comme echec )" << endl;
		}
	}

	if(d_active)
		d_ScoreSheet->addFailedThrow();
	d_active = false;

}

//methode pour supprimer le joueur de qwinto
QwintoPlayer::~QwintoPlayer() {
delete d_ScoreSheet;
}
