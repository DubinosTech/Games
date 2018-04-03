# Games

1
CSI 2772
Prélude au Projet
Automne 2017
(Date d'échéance pour tout le projet 6 Déc., 2017)
Jouer aux dés
Le projet de cette année consiste en la programmation d’un jeu console basé
sur un simple jeu de lancer de dés. Les points pour un lancé de dés sont
enregistrés sur une feuille de score (scoresheet). Le but du jeu est d’obtenir le
score total le plus élevé.
Les joueurs, à chacun leur tour, lancent jusqu’à trois dés et tous les joueurs
peuvent enregistrés les points pour tous les lancés. Le joueur qui lance les dés
peut décider d’en lancer un, deux ou trois. Les dés ont le code de couleur
rouge, jaune et bleu. La feuille de score est organisée en une matrice avec 3
rangées et 5 colonnes superposées. Les rangées ont également le code couleur
rouge, jaune et bleu. Les joueurs peuvent entrer les points dans une rangée
seulement si le dés de la même couleur ont été utilisé, mais les points enregistrés
sont ceux de tous les dés lancés.
exemple : si les dés jaune et bleu ont été lancés, les points des dés jaune et bleu
peuvent être entrés dans la rangée jaune ou la rangée bleu.
Toutefois, les nombres dans chaque rangée doivent strictement augmenter et
dans chaque colonne superposée, aucun nombre ne peut être répété. Si un
joueur ne peut enregistrer son propre lancé de dés, cela compte comme un
lancé échoué. Chaque lancé échoué comptera comme moins 5 points dans le
score final du joueur. Après quatre lancés échoués, le jeu se termine. Le jeu
s’arrêtera également si l’un des joueurs a rempli toutes les rangées. Le compte
de points est un mélange entre le nombre de scores entrés dans chaque
rangée plus un bonus spécial pour une colonne superposée remplie. Les
rangées complétement remplies sont comptées différemment. Au lieu de
compter le nombre d’entrées dans la rangée, on comptera le score de l’entrée
la plus à droite.
Ce prélude a pour but de vous aider à vous familiariser avec le jeu et
d’implémenter une classe représentant une feuille de score (scoresheet). La
feuille de score nécessite 4 rangées dans notre adaptation : une rangée pour
chaque couleur de dés : rouge, jaune et bleu, ainsi qu’une quatrième rangée
pour les lancés échoués. On a besoin au maximum de 14 colonnes. Les champs
bonus sont marqués avec des signes % de part et d’autre alors que les champs
invalides sont marqués avec XX. Noter que puisque les scores peuvent variés
entre 1 – 18 on a besoin d’un espace de deux caractères.
Une feuille de score vide devrait être comme ci-dessous :
2
Player name:
 -------------------------------
Red | % % |XX| % % | | | |
 ----------------------------------
Yellow | | | | | |XX| % % | |
 ----------------------------------
Blue | | % % |XX| | | | % %
 -------------------------------
Failed throws:
A la fin du jeu une feuille de score pourrait être telle que suit :
Player name: Jane Doe Points: 28
 -------------------------------
Red | 2% 3% 6|XX| 9%11%12|13|15|16|
 ----------------------------------
Yellow | 1| 3| 4| 5| |XX|12%13% | |
 ----------------------------------
Blue | 1| 3% % 6|XX| 7| | |10% %
 -------------------------------
Failed throws: 1 2 3
Jane Doe a obtenu un score de 28 points. La rangée rouge est complète et
donc le score le plus à droite est utilisé (16 points). La rangée jaune a 6 entrées
et la rangée bleu en a 5. Deux colonnes bonus sont complétées pour un extra
de 3 + 13 = 16 points ( les scores dans les champs correspondants marqués par
des %) et trois lancés échoués sont enregistrés à 3 * -5 = -15 points.
Ce jeu est une adaptation du jeu Qwinto par Bernhard Lach et Uwe Rapp qui a
été publié par Gigamic, Nürnberger-Spielkarten-Verlag et White Goblin Games.
Vous pouvez trouver une revue en anglais du jeu à
https://www.boardgamegeek.com/boardgame/183006/qwinto.
Conception de la classe
La classe scoresheet devrait contenir le score pour les 3 couleurs, le nom du
joueur, le nombre de lancés échoués et le score total. Doter la classe
scoresheet d’une fonction print qui accepte en argument un std::ostream et
insert le scoresheet formaté comme dans l’exemple ci-dessus dans le stream.
Vous devez implémenter et utiliser la fonction print dans la structure Dice.
Ajouter un constructeur qui accepte le nom du joueur en argument de type
std::string. Un score devrait être entré par la fonction score qui accepte un 
3
vector de structures Dice et la couleur sélectionnée du joueur et sa position
comptée à partir de la gauche. Colour devrait être une énumération avec les
valeurs RED, YELLOW, et BLUE. La classe sera étendue plus tard dans le projet.
Pour ce prélude, vous devriez vous concentrez sur l’impression à l’écran de la
feuille de score et la création d’un simple driver de test pour votre classe. La
classe devra être définie dans le fichier entête scoresheet.h et les méthodes
dans le fichier source scoresheet.cpp . Implémenter le driver de test comme
une fonction main avec la classe scoresheet mais avec un switch de
compilation TEST_SCORESHEET.
