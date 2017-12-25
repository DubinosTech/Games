#include "Player.h"

using namespace std;

Player::Player(ScoreSheet *_ss) : d_ScoreSheet(_ss) {}

bool Player::operator!()
{
	return !*d_ScoreSheet;
}



Color Player::convert_to_color(string _str)
{
		if(_str == "red")
			return Color::RED;

		else if(_str == "yellow")
			return Color::YELLOW;

		else if(_str == "green")
			return Color::GREEN;

		else if(_str == "blue")
			return Color::BLUE;

		else if(_str == "white")
			return Color::WHITE;
		else
			return Color::INVALID;
}

vector<Color> Player::get_color_index_vect(istream& _in)
{
	vector<Color> colors;
	while(colors.size() < 1)
	{
//les methodes pour obtenir les inputs
		string ligne;
		getline(_in, ligne);

//convertir les lignes obtenus du user
		istringstream ss(ligne);
		string tmp;
		while(ss >> tmp)
		{
			Color c = convert_to_color(tmp);
			if(c != Color::INVALID)
				colors.push_back(c);
		}

		if(colors.size() < 1)
			cout << "Donnees invalides ,veuillez ressayer: ";
	}
	return colors;
}
