#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

class Monster {
private:
	//Name of the monster
	string name;
	//Status: Dead 0 Alive 1
	bool status;
	//Elemental type: 0 Fire type 1 Water type 2 Grass type 3 Earth type 4 Dark type 5 Lightning type
	short type;
	//Base power of the monster
	short power;
	//Base defense of the monster
	short defense;
	//The agility determines who would get the first turn
	short agility;
	//List of available moves that can be used by the monster
	string moves[4];
	//The attack powers of the monster
	short attack[4];
public:
	Monster()
	{
		srand(time(0));
		name.erase();
		name += "Nebotus";
		status = 0;
		type = 4;
		//Total sum of the stats of a monster cannot exceed 270
		power = 80;
		agility = 60;
		defense = 130;
		moves[0].erase();
		moves[1].erase();
		moves[2].erase();
		moves[3].erase();
		moves[0] += "Awful Dreams";
		moves[1] += "Unpure";
		moves[2] += "Corruption";
		moves[3] += "Doom";
		attack[0] = 40 + rand() % 41;
		attack[1] = 58 + rand() % 41;
		attack[2] = 45 + rand() % 41;
		attack[3] = 73;
	}

	void setName(string a = "NEBOTUS")
	{
		name.erase();
		name += a;
	}
	void setStatus(bool a = false)
	{
		status = a;
	}
	void setType(short a = 0)
	{
		if (a <= 5 && a >= 0)
		{
			type = a;
		}
	}

	void setPower(short a = 60)
	{
		if ((a + defense + agility) <= 200)
		{
			power = a;
		}
	}

	void setDefense(short a = 60)
	{
		if ((power + a + agility) <= 200)
		{
			defense = a;
		}
	}

	void setAgility(short a = 60)
	{
		if ((power + defense + a) <= 200)
		{
			agility = a;
		}
	}

	void setMoves(string* a)
	{
		for (short loop = 0; loop < 4; loop++)
		{
			moves[loop].erase();
			moves[loop] += a[loop];
		}
	}
	void setAttack(short* a)
	{
		for (short loop = 0; loop < 4; loop++)
		{
			attack[loop] = a[loop];
		}
	}
	
	string getName()
	{
		return name;
	}
	bool getStatus()
	{
		return status;
	}
	short getType()
	{
		return type;
	}

	short getPower()
	{
		return power;
	}

	short getDefense()
	{
		return defense;
	}

	short getAgility()
	{
		return agility;
	}

	string* getMoves()
	{
		return moves;
	}
	short* getAttack()
	{
		return attack;
	}
};



//No setters are required as the data member are strictly for the class' own use
class MonsterGame {
private:
	Monster monsters[3];
	short CONTROL_VARIABLE;
	bool checker;
	static short player1;
	static short player2;
	static string name1;
	static string name2;
	static short HP1;
	static short HP2;
public:
	MonsterGame()
	{
		checker = false;
		CONTROL_VARIABLE = 6;
		srand(time(0));
		monsters[1].setName("Barbatos");
		monsters[1].setStatus(0);
		monsters[1].setType(0);
		//Total sum of the stats of a monster cannot exceed 270
		monsters[1].setPower(70);
		monsters[1].setAgility(70);
		monsters[1].setDefense(130);
		string moves[4];
		moves[0].erase();
		moves[1].erase();
		moves[2].erase();
		moves[3].erase();
		moves[0] += "Fire Trap";
		moves[1] += "Magma Carpet";
		moves[2] += "Super Nova";
		moves[3] += "Tornado of souls";
		monsters[1].setMoves(moves);
		short attack[4];
		attack[0] = 30 + rand() % 51;
		attack[1] = 70 + rand() % 21;
		attack[2] = 75;
		attack[3] = 56 + rand() % 31;
		monsters[1].setAttack(attack);

		monsters[2].setName("Terrasaur");
		monsters[2].setStatus(0);
		monsters[2].setType(3);
		//Total sum of the stats of a monster cannot exceed 270
		monsters[2].setPower(60);
		monsters[2].setAgility(50);
		monsters[2].setDefense(160);
		moves[0].erase();
		moves[1].erase();
		moves[2].erase();
		moves[3].erase();
		moves[0] += "Earth Power";
		moves[1] += "Stomp";
		moves[2] += "Earthquake";
		moves[3] += "Shatter";
		monsters[2].setMoves(moves);
		attack[0] = 10 + rand() % 91;
		attack[1] = 65 + rand() % 25;
		attack[2] = 50 + rand() % 31;
		attack[3] = 80;
		monsters[2].setAttack(attack);
	}

	//Checks if the game has ended or not. Made this condition logic through truth table and k-map
	bool operator!()
	{
		if ((!(monsters[0].getStatus()) && !(monsters[1].getStatus())) || (!(monsters[1].getStatus()) && !(monsters[2].getStatus())) || (!(monsters[0].getStatus()) && !(monsters[2].getStatus())))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

	void playInterface()
	{
		
		if (CONTROL_VARIABLE == 0) //Music 1
		{
			PlaySound(TEXT("8 bit oop.wav"), NULL, SND_LOOP | SND_ASYNC);
			
		}
		else if (CONTROL_VARIABLE == 1) //Music 2
		{
			PlaySound(TEXT("Arabic oop.wav"), NULL, SND_LOOP | SND_ASYNC);
			
		}
		else if (CONTROL_VARIABLE == 2) //Music 3
		{
			PlaySound(TEXT("Blade runner resonance oop.wav"), NULL, SND_LOOP | SND_ASYNC);
			
		}
		else if (CONTROL_VARIABLE == 3) //Music 4
		{
			PlaySound(TEXT("L Equipe Du Son oop.wav"), NULL, SND_LOOP | SND_ASYNC);
			
		}
		else if (CONTROL_VARIABLE == 4) //Music 5
		{
			PlaySound(TEXT("Whistle oop.wav"), NULL, SND_LOOP | SND_ASYNC);
			
		}
		else if (CONTROL_VARIABLE == 5) //Music 6
		{
			PlaySound(TEXT("Ching chang hanji oop.wav"), NULL, SND_LOOP | SND_ASYNC);
			
		}
		
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		short enter = '1';
		short arrowKey = '1';
		short enter1 = 192;
		short enter2 = 7;
		short enter3 = 7;
		short enter4 = 7;
		short enter5 = 7;

		string coutArray[5];
		coutArray[0].erase();
		coutArray[0] += "\n\n\t\t\tStart Game";
		coutArray[1].erase();
		coutArray[1] += "\n\n\t\t\tLoad Game";
		coutArray[2].erase();
		coutArray[2] += "\n\n\t\t\tDefault Music";
		coutArray[3].erase();
		coutArray[3] += "\n\n\t\t\tHelp";
		coutArray[4].erase();
		coutArray[4] += "\n\n\t\t\tExit";
		short coutArrayIndex = 0;
		system("CLS");

		cout << "\n\n\n\t\t\t";
		SetConsoleTextAttribute(h, enter1);
		cout << coutArray[0];
		SetConsoleTextAttribute(h, enter2);
		cout << coutArray[1];
		SetConsoleTextAttribute(h, enter3);
		cout << coutArray[2];
		SetConsoleTextAttribute(h, enter4);
		cout << coutArray[3];
		SetConsoleTextAttribute(h, enter5);
		cout << coutArray[4];
		SetConsoleTextAttribute(h, 7);
		cout << endl;

		while (enter != 13)
		{
			enter = _getch();
			if (enter == 13)
			{
				break;
			}
			//Enter = 13 and \n = 10
			if (enter == 224)
			{
				arrowKey = _getch();
				if (arrowKey == 72) //up
				{
					if (coutArrayIndex == 0)
					{
						coutArrayIndex = 4;
					}
					else
					{
						coutArrayIndex--;
					}
				}
				else if (arrowKey == 80) //down
				{
					if (coutArrayIndex == 4)
					{
						coutArrayIndex = 0;
					}
					else
					{
						coutArrayIndex++;
					}
				}
				else if (arrowKey == 77) //right
				{

				}
				else if (arrowKey == 75) //left
				{

				}
				if (coutArrayIndex == 0)
				{
					enter1 = 192;
					enter2 = 7;
					enter3 = 7;
					enter4 = 7;
					enter5 = 7;
				}
				else if (coutArrayIndex == 1)
				{
					enter1 = 7;
					enter2 = 192;
					enter3 = 7;
					enter4 = 7;
					enter5 = 7;
				}
				else if (coutArrayIndex == 2)
				{
					enter1 = 7;
					enter2 = 7;
					enter3 = 192;
					enter4 = 7;
					enter5 = 7;
				}
				else if (coutArrayIndex == 3)
				{
					enter1 = 7;
					enter2 = 7;
					enter3 = 7;
					enter4 = 192;
					enter5 = 7;
				}
				else if (coutArrayIndex == 4)
				{
					enter1 = 7;
					enter2 = 7;
					enter3 = 7;
					enter4 = 7;
					enter5 = 192;
				}
				system("CLS");
				cout << "\n\n\n\t\t\t";
				SetConsoleTextAttribute(h, enter1);
				cout << coutArray[0];
				SetConsoleTextAttribute(h, enter2);
				cout << coutArray[1];
				SetConsoleTextAttribute(h, enter3);
				cout << coutArray[2];
				SetConsoleTextAttribute(h, enter4);
				cout << coutArray[3];
				SetConsoleTextAttribute(h, enter5);
				cout << coutArray[4];
				SetConsoleTextAttribute(h, 7);
				cout << endl;

			}
			else
			{
				continue;
			}
		}
		if (coutArrayIndex == 0) //Start Game
		{
			play();
			return;
		}
		else if (coutArrayIndex == 1) //Load Game
		{
			name1.erase();
			name2.erase();
			ifstream fin("Save.txt", ios::in);
			if (!fin)
			{
				system("CLS");
				cout << "\n\n\n\t\t\t";
				SetConsoleTextAttribute(h, 64);
				cout << "No state to load from. Resetting...";
				SetConsoleTextAttribute(h, 7);
				Sleep(3000);
				playInterface();
				return;
			}
				string name11;
				string name12;
				string name13;
				bool status1;
				short type1;
				short power1;
				short defense1;
				short agility1;
				
				short attack1[4];
				short player11;
				short player22;
				short HP11;
				short HP22;
				short index = 0;
				while (index < 3)
				{
					fin >> name11 >> status1 >> type1 >> power1 >> defense1 >> agility1 >> attack1[0] >> attack1[1] >>
						attack1[2] >> attack1[3] >> player11 >> player22 >> HP11 >> HP22 >> name12 >> name13;
					monsters[index].setName(name11);
					monsters[index].setStatus(status1);
					monsters[index].setType(type1);
					//Total sum of the stats of a monster cannot exceed 270
					monsters[index].setPower(power1);
					monsters[index].setAgility(agility1);
					monsters[index].setDefense(defense1);
					monsters[index].setAttack(attack1);
					index++;
					
					name1.erase();
					name2.erase();
					name1 += name12;
					name2 += name13;
					name11.erase();
					name12.erase();
					name13.erase();
				}
				HP1 = HP11;
				HP2 = HP22;
				player1 = player11;
				player2 = player22;
				fin.close();

			checker = true;
			play();
			return;
		}
		else if (coutArrayIndex == 2) //Default Music
		{
			system("CLS");
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			short enter = '1';
			short arrowKey = '1';
			short enter1 = 192;
			short enter2 = 7;
			short enter3 = 7;
			short enter4 = 7;
			short enter5 = 7;
			short enter6 = 7;
			string coutArray[6];
			coutArray[0].erase();
			coutArray[0] += "\n\n\t\t\tMusic 1";
			coutArray[1].erase();
			coutArray[1] += "\n\n\t\t\tMusic 2";
			coutArray[2].erase();
			coutArray[2] += "\n\n\t\t\tMusic 3";
			coutArray[3].erase();
			coutArray[3] += "\n\n\t\t\tMusic 4";
			coutArray[4].erase();
			coutArray[4] += "\n\n\t\t\tMusic 5";
			coutArray[5].erase();
			coutArray[5] += "\n\n\t\t\tMusic 6";
			short coutArrayIndex = 0;
			system("CLS");
			cout << "\n\n\n\t\t\t";
			SetConsoleTextAttribute(h, enter1);
			cout << coutArray[0];
			SetConsoleTextAttribute(h, enter2);
			cout << coutArray[1];
			SetConsoleTextAttribute(h, enter3);
			cout << coutArray[2];
			SetConsoleTextAttribute(h, enter4);
			cout << coutArray[3];
			SetConsoleTextAttribute(h, enter5);
			cout << coutArray[4];
			SetConsoleTextAttribute(h, enter6);
			cout << coutArray[5];
			SetConsoleTextAttribute(h, 7);
			cout << endl;
			while (enter != 13)
			{
				enter = _getch();
				if (enter == 13)
				{
					break;
				}
				else if (enter == 27)
				{
					playInterface();
					return;
				}
				
				//Enter = 13 and \n = 10
				if (enter == 224)
				{
					arrowKey = _getch();
					if (arrowKey == 72) //up
					{
						if (coutArrayIndex == 0)
						{
							coutArrayIndex = 5;
						}
						else
						{
							coutArrayIndex--;
						}
					}
					else if (arrowKey == 80) //down
					{
						if (coutArrayIndex == 5)
						{
							coutArrayIndex = 0;
						}
						else
						{
							coutArrayIndex++;
						}
					}
					else if (arrowKey == 77) //right
					{

					}
					else if (arrowKey == 75) //left
					{

					}
					if (coutArrayIndex == 0)
					{
						enter1 = 192;
						enter2 = 7;
						enter3 = 7;
						enter4 = 7;
						enter5 = 7;
						enter6 = 7;
					}
					else if (coutArrayIndex == 1)
					{
						enter1 = 7;
						enter2 = 192;
						enter3 = 7;
						enter4 = 7;
						enter5 = 7;
						enter6 = 7;
					}
					else if (coutArrayIndex == 2)
					{
						enter1 = 7;
						enter2 = 7;
						enter3 = 192;
						enter4 = 7;
						enter5 = 7;
						enter6 = 7;
					}
					else if (coutArrayIndex == 3)
					{
						enter1 = 7;
						enter2 = 7;
						enter3 = 7;
						enter4 = 192;
						enter5 = 7;
						enter6 = 7;
					}
					else if (coutArrayIndex == 4)
					{
						enter1 = 7;
						enter2 = 7;
						enter3 = 7;
						enter4 = 7;
						enter5 = 192;
						enter6 = 7;
					}
					else if (coutArrayIndex == 5)
					{
						enter1 = 7;
						enter2 = 7;
						enter3 = 7;
						enter4 = 7;
						enter5 = 7;
						enter6 = 192;
					}
					system("CLS");
					cout << "\n\n\n\t\t\t";
					SetConsoleTextAttribute(h, enter1);
					cout << coutArray[0];
					SetConsoleTextAttribute(h, enter2);
					cout << coutArray[1];
					SetConsoleTextAttribute(h, enter3);
					cout << coutArray[2];
					SetConsoleTextAttribute(h, enter4);
					cout << coutArray[3];
					SetConsoleTextAttribute(h, enter5);
					cout << coutArray[4];
					SetConsoleTextAttribute(h, enter6);
					cout << coutArray[5];
					SetConsoleTextAttribute(h, 7);
					cout << endl;

				}
				else
				{
					continue;
				}
			}
			if (coutArrayIndex == 0) //Music 1
			{
				PlaySound(TEXT("8 bit oop.wav"), NULL, SND_LOOP | SND_ASYNC);
				CONTROL_VARIABLE = 0;
				playInterface();
				return;
			}
			else if (coutArrayIndex == 1) //Music 2
			{
				PlaySound(TEXT("Arabic oop.wav"), NULL, SND_LOOP | SND_ASYNC);
				CONTROL_VARIABLE = 1;
				playInterface();
				return;
			}
			else if (coutArrayIndex == 2) //Music 3
			{
				PlaySound(TEXT("Blade runner resonance oop.wav"), NULL, SND_LOOP | SND_ASYNC);
				CONTROL_VARIABLE = 2;
				playInterface();
				return;
			}
			else if (coutArrayIndex == 3) //Music 4
			{
				PlaySound(TEXT("L Equipe Du Son oop.wav"), NULL, SND_LOOP | SND_ASYNC);
				CONTROL_VARIABLE = 3;
				playInterface();
				return;
			}
			else if (coutArrayIndex == 4) //Music 5
			{
				PlaySound(TEXT("Whistle oop.wav"), NULL, SND_LOOP | SND_ASYNC);
				CONTROL_VARIABLE = 4;
				playInterface();
				return;
			}
			else if (coutArrayIndex == 5) //Music 6
			{
				PlaySound(TEXT("Ching chang hanji oop.wav"), NULL, SND_LOOP | SND_ASYNC);
				CONTROL_VARIABLE = 5;
				playInterface();
				return;
			}

		}
		else if (coutArrayIndex == 3) //Help
		{
			system("CLS");
			SetConsoleTextAttribute(h, 96);
			cout << "\n\n\n\t\t\tHELP MENU" << endl << endl << endl;
			SetConsoleTextAttribute(h, 7);
			cout << "\n\n\n\tIn this game you must first choose your monster. Each monster has a set elemental type. As there are only 3 monsters\n"
				<< "\tcurrently in the game so only 3 elemental types are in play. Dark type for Nebotus, Fire type for Barbatos and Earth type\n"
				<< "\tfor Terrasaur. Other elemental types will be associated with Monsters added in the future. When each player has chosen his/her\n"
				<< "\tMonster they will be locked in a battle. During each turn the respective player must choose an attack with each\n"
				<< "\tattack having different power. The power of attacks is randomly determined at the time a monster is chosen. The base powers of\n"
				<< "\teach kind of attack is displayed before the battle is commenced and the randomized increase in those attacks is kept secret\n"
				<< "\tfrom the player. The player must choose each time an attack whose power will be subtracted from the opponent's defense and the\n"
				<< "\tremaining from the opponent's health. Whichever player's Monster's HP is reduced to zero first loses the battle. Escape \n"
				<< "\toption will be available everytime a player has to choose an attack and game will be saved which can be loaded later on.\n";
			_getch();
			playInterface();
			return;
		}
		else if (coutArrayIndex == 4) //Exit
		{
			cout << "\n\n\n\n\n\n\n";
			exit(0);
		}
		playInterface();
		return;
	}

	void playAnim0()
	{
		cout << "                                           .\"\"--.._" << "                                                       " << "                            ,-.\n"
			<< "                                           []      `'--.._" << "                                                " << "       ___,---.__          /'|`\\          __,---,___\n"
			<< "                                           ||__           `'-," << "                                            " << "    ,-'    \\`    `-.____,-'  |  `-.____,-'    //    `-.\n"
			<< "                                         `)||_ ```'--..       \\" << "                                           " << "  ,'        |           ~'\\     /`~           |        `.\n"
			<< "                     _                    /|//}        ``--._  |" << "                                          " << " /      ___//              `. ,'          ,  , \\___      \\\n"
			<< "                  .'` `'.                /////}              `\\/" << "                                          " << "|    ,-'   `-.__   _         |        ,    __,-'   `-.    |\n"
			<< "                 /  .\"\"\".\\              //{///    " << "                                                        " << "|   /          /\\_  `   .    |    ,      _/\\          \\   |\n"
			<< "                /  /_  _`\\\\            // `||" << "                                                             " << "\\  |           \\ \\`-.___ \\   |   / ___,-'/ /           |  /\n"
			<< "                | |(_)(_)||          _//   ||" << "                                                             " << " \\  \\           | `._   `\\\\  |  //'   _,' |           /  /\n"
			<< "                | |  /\\  )|        _///\\   ||" << "                                                             " << "  `-.\\         /'  _ `---'' , . ``---' _  `\\         /,-'\n"
			<< "                | |L====J |       / |/ |   ||" << "                                                             " << "     ``       /     \\    ,='/ \\`=.    /     \\       ''\n"
			<< "               /  /'-..-' /    .'`  \\  |   ||" << "                                                             " << "             |__   /|\\_,--.,-.--,--._/|\\   __|\n"
			<< "              /   |  :: | |_.-`      |  \\  ||" << "                                                             " << "             /  `./  \\\\`\\ |  |  | /,//' \\,'  \\\n"
			<< "             /|   `\\-::.| |          \\   | ||" << "                                                             " << "            /   /     ||--+--|--+-/-|     \\   \\\n"
			<< "           /` `|   /    | |          |   / ||" << "                                                             " << "           |   |     /'\\_\\_\\ | /_/_/`\\     |   |\n"
			<< "         |`    \\   |    / /          \\  |  ||" << "                                                             " << "            \\   \\__, \\_     `~'     _/ .__/   /\n"
			<< "        |       `\\_|    |/      ,.__. \\ |  ||" << "                                                             " << "             `-._,-'   `-._______,-'   `-._,-'\n"
			<< "        /                     /`    `\\ ||  ||" << "                                                             \n"
			<< "       |           .         /        \\||  ||" << "                                                             \n";
	}

	void playAnim1()
	{
		cout << "                                           .\"\"--.._" << "                                                       " << "\n"
			<< "                                           []      `'--.._" << "                                                " << "\n"
			<< "                                           ||__           `'-," << "                                            " << "\n"
			<< "                                         `)||_ ```'--..       \\" << "                                           " << "\n"
			<< "                     _                    /|//}        ``--._  |" << "                                          " << "                       _. - ~ ~ ~ - .\n"
			<< "                  .'` `'.                /////}              `\\/" << "                                          " << "   ..__.    . - ~~- .\n"
			<< "                 /  .\"\"\".\\              //{///    " << "                                                        " << "   ((\\ / `}.~`.\n"
			<< "                /  /_  _`\\\\            // `||" << "                                                             " << "    \\\\\\   {     } / \\   \\\n"
			<< "                | |(_)(_)||          _//   ||" << "                                                             " << "(\\   \\\\~~^ } | }   \\\n"
			<< "                | |  /\\  )|        _///\\   ||" << "                                                             " << " \\`. - ~- @~ }, -. | )    \\\n"
			<< "                | |L====J |       / |/ |   ||" << "                                                             " << " (___     ) _}   (    :        |    / /      `.\n"
			<< "               /  /'-..-' /    .'`  \\  |   ||" << "                                                             " << "  `----._-~.     _\\ \\ |_       \\   / /- _      `.\n"
			<< "              /   |  :: | |_.-`      |  \\  ||" << "                                                             " << "         ~~----~~  \\ \\| ~~--~~~(  + /     ~-.     ~- _\n"
			<< "             /|   `\\-::.| |          \\   | ||" << "                                                             " << "                   /  /         \\  \\          ~- . _ _~_-_.\n"
			<< "           /` `|   /    | |          |   / ||" << "                                                             " << "                __/  /          _\\  )\n"
			<< "         |`    \\   |    / /          \\  |  ||" << "                                                             " << "              .<___.'         .<___/\n"
			<< "        |       `\\_|    |/      ,.__. \\ |  ||" << "                                                             " << "\n"
			<< "        /                     /`    `\\ ||  ||" << "                                                             \n"
			<< "       |           .         /        \\||  ||" << "                                                             \n";
	}
	void playAnim2()
	{
		cout << "                            ,-." << "\n"
			<< "       ___,---.__          /'|`\\          __,---,___" << "" << "\n"
			<< "    ,-'    \\`    `-.____,-'  |  `-.____,-'    //    `-." << "" << "\n"
			<< "  ,'        |           ~'\\     /`~           |        `." << "                                                  " << "                       _. - ~ ~ ~ - .\n"
			<< " /      ___//              `. ,'          ,  , \\___      \\" << "                                                 " << "   ..__.    . - ~~- .\n"
			<< "|    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << "                                                " << "   ((\\ / `}.~`.\n"
			<< "|   /          /\\_  `   .    |    ,      _/\\          \\   |" << "                                                " << "    \\\\\\   {     } / \\   \\\n"
			<< "\\  |           \\ \\`-.___ \\   |   / ___,-'/ /           |  /" << "                                                " << "(\\   \\\\~~^ } | }   \\\n"
			<< " \\  \\           | `._   `\\\\  |  //'   _,' |           /  /" << "                                                 " << " \\`. - ~- @~ }, -. | )    \\\n"
			<< "  `-.\\         /'  _ `---'' , . ``---' _  `\\         /,-'" << "                                                  " << " (___     ) _}   (    :        |    / /      `.\n"
			<< "     ``       /     \\    ,='/ \\`=.    /     \\       ''" << "                                                     " << "  `----._-~.     _\\ \\ |_       \\   / /- _      `.\n"
			<< "             |__   /|\\_,--.,-.--,--._/|\\   __|" << "                                                             " << "         ~~----~~  \\ \\| ~~--~~~(  + /     ~-.     ~- _\n"
			<< "             /  `./  \\\\`\\ |  |  | /,//' \\,'  \\" << "                                                             " << "                   /  /         \\  \\          ~- . _ _~_-_.\n"
			<< "            /   /     ||--+--|--+-/-|     \\   \\" << "                                                            " << "                __/  /          _\\  )\n"
			<< "           |   |     /'\\_\\_\\ | /_/_/`\\     |   |" << "                                                           " << "              .<___.'         .<___/\n"
			<< "            \\   \\__, \\_     `~'     _/ .__/   /" << "\n"
			<< "             `-._,-'   `-._______,-'   `-._,-'\n";
	}
	void playAnim3()
	{
		cout << "                                           .\"\"--.._ " << "                                                                                     .\"\"--.._ \n"
			<< "                                           []      `'--.._ " << "                                                                              []      `'--.._ \n"
			<< "                                           ||__           `'-, " << "                                                                          ||__           `'-, \n"
			<< "                                         `)||_ ```'--..       \\ " << "                                                                       `)||_ ```'--..       \\ \n"
			<< "                     _                    /|//}        ``--._  | " << "                                                  _                    /|//}        ``--._  | \n"
			<< "                  .'` `'.                /////}              `\\/ " << "                                               .'` `'.                /////}              `\\/ \n"
			<< "                 /  .\"\"\".\\              //{///     " << "                                                            /  .\"\"\".\\              //{///     \n"
			<< "                /  /_  _`\\\\            // `|| " << "                                                                /  /_  _`\\\\            // `|| \n"
			<< "                | |(_)(_)||          _//   || " << "                                                                | |(_)(_)||          _//   || \n"
			<< "                | |  /\\  )|        _///\\   || " << "                                                                | |  /\\  )|        _///\\   || \n"
			<< "                | |L====J |       / |/ |   || " << "                                                                | |L====J |       / |/ |   || \n"
			<< "               /  /'-..-' /    .'`  \\  |   || " << "                                                               /  /'-..-' /    .'`  \\  |   || \n"
			<< "              /   |  :: | |_.-`      |  \\  || " << "                                                              /   |  :: | |_.-`      |  \\  || \n"
			<< "             /|   `\\-::.| |          \\   | || " << "                                                             /|   `\\-::.| |          \\   | || \n"
			<< "           /` `|   /    | |          |   / || " << "                                                           /` `|   /    | |          |   / || \n"
			<< "         |`    \\   |    / /          \\  |  || " << "                                                         |`    \\   |    / /          \\  |  || \n"
			<< "        |       `\\_|    |/      ,.__. \\ |  || " << "                                                        |       `\\_|    |/      ,.__. \\ |  || \n"
			<< "        /                     /`    `\\ ||  || " << "                                                        /                     /`    `\\ ||  || \n"
			<< "       |           .         /        \\||  || " << "                                                       |           .         /        \\||  || \n";
	}
	void playAnim4()
	{
		cout << "                            ,-.                            " << "                                               " << "                            ,-.\n"
			<< "       ___,---.__          /'|`\\          __,---,___       " << "                                               " << "       ___,---.__          /'|`\\          __,---,___\n"
			<< "    ,-'    \\`    `-.____,-'  |  `-.____,-'    //    `-.    " << "                                               " << "    ,-'    \\`    `-.____,-'  |  `-.____,-'    //    `-.\n"
			<< "  ,'        |           ~'\\     /`~           |        `." << "                                                 " << "  ,'        |           ~'\\     /`~           |        `.\n"
			<< " /      ___//              `. ,'          ,  , \\___      \\" << "                                                " << " /      ___//              `. ,'          ,  , \\___      \\\n"
			<< "|    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << "                                               " << "|    ,-'   `-.__   _         |        ,    __,-'   `-.    |\n"
			<< "|   /          /\\_  `   .    |    ,      _/\\          \\   |" << "                                               " << "|   /          /\\_  `   .    |    ,      _/\\          \\   |\n"
			<< "\\  |           \\ \\`-.___ \\   |   / ___,-'/ /           |  /" << "                                               " << "\\  |           \\ \\`-.___ \\   |   / ___,-'/ /           |  /\n"
			<< " \\  \\           | `._   `\\\\  |  //'   _,' |           /  /" << "                                                " << " \\  \\           | `._   `\\\\  |  //'   _,' |           /  /\n"
			<< "  `-.\\         /'  _ `---'' , . ``---' _  `\\         /,-'" << "                                                 " << "  `-.\\         /'  _ `---'' , . ``---' _  `\\         /,-'\n"
			<< "     ``       /     \\    ,='/ \\`=.    /     \\       ''" << "                                                    " << "     ``       /     \\    ,='/ \\`=.    /     \\       ''\n"
			<< "             |__   /|\\_,--.,-.--,--._/|\\   __|" << "                                                            " << "             |__   /|\\_,--.,-.--,--._/|\\   __|\n"
			<< "             /  `./  \\\\`\\ |  |  | /,//' \\,'  \\" << "                                                            " << "             /  `./  \\\\`\\ |  |  | /,//' \\,'  \\\n"
			<< "            /   /     ||--+--|--+-/-|     \\   \\" << "                                                           " << "            /   /     ||--+--|--+-/-|     \\   \\\n"
			<< "           |   |     /'\\_\\_\\ | /_/_/`\\     |   |" << "                                                          " << "           |   |     /'\\_\\_\\ | /_/_/`\\     |   |\n"
			<< "            \\   \\__, \\_     `~'     _/ .__/   /            " << "                                               " << "            \\   \\__, \\_     `~'     _/ .__/   /\n"
			<< "             `-._,-'   `-._______,-'   `-._,-'             " << "                                               " << "             `-._,-'   `-._______,-'   `-._,-'\n";
	}
	void playAnim5()
	{
		cout << "                       _. - ~ ~ ~ - .                      " << "                                " << "                       _. - ~ ~ ~ - .\n"
			<< "   ..__.    . - ~~- .                                      " << "                                " << "   ..__.    . - ~~- .\n"
			<< "   ((\\ / `}.~`.                                            " << "                                " << "   ((\\ / `}.~`.\n"
			<< "    \\\\\\   {     } / \\   \\                                  " << "                                " << "    \\\\\\   {     } / \\   \\\n"
			<< "(\\   \\\\~~^ } | }   \\                                       " << "                                " << "(\\   \\\\~~^ } | }   \\\n"
			<< " \\`. - ~- @~ }, -. | )    \\                                " << "                                " << " \\`. - ~- @~ }, -. | )    \\\n"
			<< " (___     ) _}   (    :        |    / /      `.            " << "                                " << " (___     ) _}   (    :        |    / /      `.\n"
			<< "  `----._-~.     _\\ \\ |_       \\   / /- _      `.          " << "                                " << "  `----._-~.     _\\ \\ |_       \\   / /- _      `.\n"
			<< "         ~~----~~  \\ \\| ~~--~~~(  + /     ~-.     ~- _     " << "                                " << "         ~~----~~  \\ \\| ~~--~~~(  + /     ~-.     ~- _\n"
			<< "                   /  /         \\  \\          ~- . _ _~_-_." << "                                " << "                   /  /         \\  \\          ~- . _ _~_-_.\n"
			<< "                __/  /          _\\  )                      " << "                                " << "                __/  /          _\\  )\n"
			<< "              .<___.'         .<___/                       " << "                                " << "              .<___.'         .<___/\n";
	}

	void play()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		short enter = '1';
		short arrowKey = '1';
		short enter1 = 192;
		short enter2 = 7;
		short enter3 = 7;
		string name11;
		string name22;
		string coutArray[3];
		short coutArrayIndex = 0;
		if (!checker)
		{
			HP1 = 100;
			HP2 = 100;
			system("CLS");
			cout << "\n\n\n\t\t\tEnter the first Player's name: ";
			cin >> name11;
			name1.erase();
			name1 += name11;
			system("CLS");
			cout << "\n\n\n\t\t\tWhich monster do you want to choose?\n";

			coutArray[0].erase();
			coutArray[0] += "\n\n\t\t\tNebotus";
			coutArray[1].erase();
			coutArray[1] += "\n\n\t\t\tBarbatos";
			coutArray[2].erase();
			coutArray[2] += "\n\n\t\t\tTerrasaur";
			SetConsoleTextAttribute(h, enter1);
			cout << coutArray[0];
			SetConsoleTextAttribute(h, enter2);
			cout << coutArray[1];
			SetConsoleTextAttribute(h, enter3);
			cout << coutArray[2];
			SetConsoleTextAttribute(h, 7);
			cout << endl;

			while (enter != 13)
			{
				enter = _getch();
				if (enter == 13)
				{
					break;
				}
				
				
				//Enter = 13 and \n = 10
				if (enter == 224)
				{
					arrowKey = _getch();
					if (arrowKey == 72) //up
					{
						if (coutArrayIndex == 0)
						{
							coutArrayIndex = 2;
						}
						else
						{
							coutArrayIndex--;
						}
					}
					else if (arrowKey == 80) //down
					{
						if (coutArrayIndex == 2)
						{
							coutArrayIndex = 0;
						}
						else
						{
							coutArrayIndex++;
						}
					}
					else if (arrowKey == 77) //right
					{

					}
					else if (arrowKey == 75) //left
					{

					}
					if (coutArrayIndex == 0)
					{
						enter1 = 192;
						enter2 = 7;
						enter3 = 7;
					}
					else if (coutArrayIndex == 1)
					{
						enter1 = 7;
						enter2 = 192;
						enter3 = 7;
					}
					else if (coutArrayIndex == 2)
					{
						enter1 = 7;
						enter2 = 7;
						enter3 = 192;
					}
					system("CLS");
					cout << "\n\n\n\t\t\tWhich monster do you want to choose?\n";
					SetConsoleTextAttribute(h, enter1);
					cout << coutArray[0];
					SetConsoleTextAttribute(h, enter2);
					cout << coutArray[1];
					SetConsoleTextAttribute(h, enter3);
					cout << coutArray[2];
					SetConsoleTextAttribute(h, 7);

				}
				else
				{
					continue;
				}
			}
			player1 = coutArrayIndex;

			enter = '1';
			arrowKey = '1';
			enter1 = 192;
			enter2 = 7;
			enter3 = 7;

			system("CLS");
			cout << "\n\n\n\t\t\tEnter the second Player's name: ";
			cin >> name22;
			name2.erase();
			name2 += name22;
			system("CLS");
			cout << "\n\n\n\t\t\tWhich monster do you want to choose?\n";

			coutArray[0].erase();
			coutArray[0] += "\n\n\t\t\tNebotus";
			coutArray[1].erase();
			coutArray[1] += "\n\n\t\t\tBarbatos";
			coutArray[2].erase();
			coutArray[2] += "\n\n\t\t\tTerrasaur";
			coutArrayIndex = 0;
			SetConsoleTextAttribute(h, enter1);
			cout << coutArray[0];
			SetConsoleTextAttribute(h, enter2);
			cout << coutArray[1];
			SetConsoleTextAttribute(h, enter3);
			cout << coutArray[2];
			SetConsoleTextAttribute(h, 7);
			cout << endl;

			while (enter != 13)
			{
				enter = _getch();
				if (enter == 13)
				{
					break;
				}
				
				//Enter = 13 and \n = 10
				if (enter == 224)
				{
					arrowKey = _getch();
					if (arrowKey == 72) //up
					{
						if (coutArrayIndex == 0)
						{
							coutArrayIndex = 2;
						}
						else
						{
							coutArrayIndex--;
						}
					}
					else if (arrowKey == 80) //down
					{
						if (coutArrayIndex == 2)
						{
							coutArrayIndex = 0;
						}
						else
						{
							coutArrayIndex++;
						}
					}
					else if (arrowKey == 77) //right
					{

					}
					else if (arrowKey == 75) //left
					{

					}
					if (coutArrayIndex == 0)
					{
						enter1 = 192;
						enter2 = 7;
						enter3 = 7;
					}
					else if (coutArrayIndex == 1)
					{
						enter1 = 7;
						enter2 = 192;
						enter3 = 7;
					}
					else if (coutArrayIndex == 2)
					{
						enter1 = 7;
						enter2 = 7;
						enter3 = 192;
					}
					system("CLS");
					cout << "\n\n\n\t\t\tWhich monster do you want to choose?\n";
					SetConsoleTextAttribute(h, enter1);
					cout << coutArray[0];
					SetConsoleTextAttribute(h, enter2);
					cout << coutArray[1];
					SetConsoleTextAttribute(h, enter3);
					cout << coutArray[2];
					SetConsoleTextAttribute(h, 7);
					cout << endl;

				}
				else
				{
					continue;
				}
			}
			player2 = coutArrayIndex;
		}
		
		if ((player1 == 1 && player2 == 0) || (player1 == 2 && player2 == 0) || (player1 == 2 && player2 == 1))
		{
			short temp = 0;
			string tempName;
			temp = player1;
			player1 = player2;
			player2 = temp;
			tempName.erase();
			tempName += name1;
			name1.erase();
			name1 += name2;
			name2.erase();
			name2 += tempName;
		}

		string* moves1 = monsters[player1].getMoves();
		short* attacks1 = monsters[player1].getAttack();
		string* moves2 = monsters[player2].getMoves();
		short* attacks2 = monsters[player2].getAttack();

		system("CLS");
		cout << "\n\n\nNebotus' Base Attack Stats: \t\t\t" << "Barbatos' Base Attack Stats: \t\t\t\t" << "Terrasaur's Base Attack Stats: \n\n";

		cout << "Awful Dreams: " << 40 << " + " << "Random Bonus" << "\t\t\tFire Trap: " << 30 << " + " << "Random Bonus" << "\t\t\t\tEarth Power: " << 10 << " + " << "Random Bonus\n";
		cout << "Unpure: " << 58 << " + " << "Random Bonus" << "\t\t\tMagma Carpet: " << 70 << " + " << "Random Bonus" << "\t\t\t\tStomp: " << 65 << " + " << "Random Bonus\n";
		cout << "Corruption: " << 45 << " + " << "Random Bonus" << "\t\t\tSuper Nova: " << 75 << "\t\t\t\t\t\tEarthquake: " << 50 << " + " << "Random Bonus\n";
		cout << "Doom: " << 73 << "\t\t\t\t\tTornado of souls: " << 56 << " + " << "Random Bonus" << "\t\t\tShatter: " << 80 << endl;

		SetConsoleTextAttribute(h, 208);
		cout << "\n\n\n\t" << name1 << "'s Available Moves: ";
		SetConsoleTextAttribute(h, 7);
		cout << "\n\t" << moves1[0] << "\n\t" << moves1[1] << "\n\t" << moves1[2] <<
			"\n\t" << moves1[3];
		SetConsoleTextAttribute(h, 208);
		cout << "\n\n\t" << name2 << "'s Available Moves: ";
		SetConsoleTextAttribute(h, 7);
		cout << "\n\t" << moves2[0] << "\n\t" << moves2[1] << "\n\t" << moves2[2] <<
			"\n\t" << moves2[3] << endl << endl << "Press any key to continue...";
		_getch();


		char attacks2D1[4][16];
		char attacks2D2[4][16];

		for (short row = 0; row < 4; row++)
		{
			for (short col = 0; col < 16; col++)
			{
				attacks2D1[row][col] = ' ';
				attacks2D2[row][col] = ' ';
			}
		}

		for (short row = 0; row < 4; row++)
		{
			for (short attackName = 0; attackName < moves1[row].length(); attackName++)
			{
				attacks2D1[row][attackName] = moves1[row][attackName];
			}
		}

		for (short row = 0; row < 4; row++)
		{
			for (short attackName = 0; attackName < moves2[row].length(); attackName++)
			{
				attacks2D2[row][attackName] = moves2[row][attackName];
			}
		}


		while (HP1 > 0 && HP2 > 0)
		{
			short enterArray[4];
			enterArray[0] = 192;
			enterArray[1] = 7;
			enterArray[2] = 7;
			enterArray[3] = 7;
			if (!checker)
			{
				enter = '1';
				arrowKey = '1';
				coutArrayIndex = 0;
				while (enter != 13)
				{
					system("CLS");
					
					cout << "\n\n\t\t" << name1 << "'s " << monsters[player1].getName() << "\t\t\t\t\t\t\t\t\t\t\t\t" << name2 << "'s " << monsters[player2].getName() << endl;
					//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					if (player1 == 0 && player2 == 1)
					{
						playAnim0();
					}
					else if (player1 == 0 && player2 == 2)
					{
						playAnim1();
					}
					else if (player1 == 1 && player2 == 2)
					{
						playAnim2();
					}
					else if (player1 == 0 && player2 == 0)
					{
						playAnim3();
					}
					else if (player1 == 1 && player2 == 1)
					{
						playAnim4();
					}
					else if (player1 == 2 && player2 == 2)
					{
						playAnim5();
					}
					else
					{
						cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					}
					cout << "\n\t\tHP  ";

					for (short loop = 0; loop < HP1; loop += 10)
					{
						cout << "*";
					}

					cout << " " << HP1 << "\t\t\t\t\t\t\t\t\t\t\t\tHP  ";

					for (short loop = 0; loop < HP2; loop += 10)
					{
						cout << "*";
					}

					cout << " " << HP2 << endl << endl;

					for (short row = 0; row < 4; row++)
					{
						cout << "\t\t";
						SetConsoleTextAttribute(h, enterArray[row]);
						for (short attackName = 0; attackName < 16; attackName++)
						{
							cout << attacks2D1[row][attackName];

						}
						SetConsoleTextAttribute(h, 7);

						cout << "\t\t\t\t\t\t\t\t\t\t\t";

						for (short attackName = 0; attackName < 16; attackName++)
						{
							cout << attacks2D2[row][attackName];

						}
						cout << endl;
					}

					enter = _getch();
					if (enter == 13)
					{
						break;
					}
					
					//Enter = 13 and \n = 10
					if (enter == 224)
					{
						arrowKey = _getch();
						if (arrowKey == 72) //up
						{
							if (coutArrayIndex == 0)
							{
								coutArrayIndex = 3;
							}
							else
							{
								coutArrayIndex--;
							}
						}
						else if (arrowKey == 80) //down
						{
							if (coutArrayIndex == 3)
							{
								coutArrayIndex = 0;
							}
							else
							{
								coutArrayIndex++;
							}
						}
						else if (arrowKey == 77) //right
						{

						}
						else if (arrowKey == 75) //left
						{

						}
						if (coutArrayIndex == 0)
						{
							enterArray[0] = 192;
							enterArray[1] = 7;
							enterArray[2] = 7;
							enterArray[3] = 7;
						}
						else if (coutArrayIndex == 1)
						{
							enterArray[0] = 7;
							enterArray[1] = 192;
							enterArray[2] = 7;
							enterArray[3] = 7;
						}
						else if (coutArrayIndex == 2)
						{
							enterArray[0] = 7;
							enterArray[1] = 7;
							enterArray[2] = 192;
							enterArray[3] = 7;
						}
						else if (coutArrayIndex == 3)
						{
							enterArray[0] = 7;
							enterArray[1] = 7;
							enterArray[2] = 7;
							enterArray[3] = 192;
						}

					}
					else
					{
						continue;
					}

				}

				if (coutArrayIndex == 0) //Attack 1
				{
					HP2 += ((monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[0])) > 0 ? 0 : (monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[0])));
				}
				else if (coutArrayIndex == 1) //Attack 2
				{
					HP2 += ((monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[1])) > 0 ? 0 : (monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[1])));
				}
				else if (coutArrayIndex == 2) //Attack 2
				{
					HP2 += ((monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[2])) > 0 ? 0 : (monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[2])));
				}
				else if (coutArrayIndex == 3) //Attack 2
				{
					HP2 += ((monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[3])) > 0 ? 0 : (monsters[player2].getDefense() - (monsters[player1].getPower() + attacks1[3])));
				}

				if (!(HP1 > 0 && HP2 > 0))
				{
					break;
				}
			}
			else
			{
				checker = false;
			}
			
			
			enter = '1';
			arrowKey = '1';
			coutArrayIndex = 0;
			enterArray[0] = 192;
			enterArray[1] = 7;
			enterArray[2] = 7;
			enterArray[3] = 7;

			while (enter != 13)
			{
				system("CLS");
				cout << "\n\n\t\t" << name1 << "'s " << monsters[player1].getName() << "\t\t\t\t\t\t\t\t\t\t\t\t" << name2 << "'s " << monsters[player2].getName() << endl;
				//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				if (player1 == 0 && player2 == 1)
				{
					playAnim0();
				}
				else if (player1 == 0 && player2 == 2)
				{
					playAnim1();
				}
				else if (player1 == 1 && player2 == 2)
				{
					playAnim2();
				}
				else if (player1 == 0 && player2 == 0)
				{
					playAnim3();
				}
				else if (player1 == 1 && player2 == 1)
				{
					playAnim4();
				}
				else if (player1 == 2 && player2 == 2)
				{
					playAnim5();
				}
				else
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				}
				cout << "\n\t\tHP  ";

				for (short loop = 0; loop < HP1; loop += 10)
				{
					cout << "*";
				}

				cout << " " << HP1 << "\t\t\t\t\t\t\t\t\t\t\t\tHP  ";

				for (short loop = 0; loop < HP2; loop += 10)
				{
					cout << "*";
				}

				cout << " " << HP2 << endl << endl;

				for (short row = 0; row < 4; row++)
				{
					cout << "\t\t";
					
					for (short attackName = 0; attackName < 16; attackName++)
					{
						cout << attacks2D1[row][attackName];

					}
					

					cout << "\t\t\t\t\t\t\t\t\t\t\t";

					SetConsoleTextAttribute(h, enterArray[row]);
					for (short attackName = 0; attackName < 16; attackName++)
					{
						cout << attacks2D2[row][attackName];

					}
					SetConsoleTextAttribute(h, 7);
					cout << endl;
				}

				enter = _getch();
				if (enter == 13)
				{
					break;
				}
				else if (enter == 27)
				{
					char choice = '1';
					system("CLS");
					
					cout << "\n\n\n\t\t\t";
					SetConsoleTextAttribute(h, 64);
					cout << "Are you sure you want to save and exit ? Enter 'y' for yes and 'n' for no : ";
					SetConsoleTextAttribute(h, 7);
					choice = _getch();
					if (choice == 'y' || choice == 'Y')
					{
						ofstream fout("Save.txt", ios::out);
						if (!fout)
						{
							cout << "\nCould not open file for saving. Cannot save game. Game will resume in a few seconds." << endl;
							Sleep(5000);
							system("CLS");
							cout << "\n\n\t\t" << name1 << "'s " << monsters[player1].getName() << "\t\t\t\t\t\t\t\t\t\t\t\t" << name2 << "'s " << monsters[player2].getName() << endl;
							//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
							if (player1 == 0 && player2 == 1)
							{
								playAnim0();
							}
							else if (player1 == 0 && player2 == 2)
							{
								playAnim1();
							}
							else if (player1 == 1 && player2 == 2)
							{
								playAnim2();
							}
							else if (player1 == 0 && player2 == 0)
							{
								playAnim3();
							}
							else if (player1 == 1 && player2 == 1)
							{
								playAnim4();
							}
							else if (player1 == 2 && player2 == 2)
							{
								playAnim5();
							}
							else
							{
								cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
							}
							cout << "\n\t\tHP  ";

							for (short loop = 0; loop < HP1; loop += 10)
							{
								cout << "*";
							}

							cout << " " << HP1 << "\t\t\t\t\t\t\t\t\t\t\t\tHP  ";

							for (short loop = 0; loop < HP2; loop += 10)
							{
								cout << "*";
							}

							cout << " " << HP2 << endl << endl;

							for (short row = 0; row < 4; row++)
							{
								cout << "\t\t";

								for (short attackName = 0; attackName < 16; attackName++)
								{
									cout << attacks2D1[row][attackName];

								}


								cout << "\t\t\t\t\t\t\t\t\t\t\t";

								SetConsoleTextAttribute(h, enterArray[row]);
								for (short attackName = 0; attackName < 16; attackName++)
								{
									cout << attacks2D2[row][attackName];

								}
								SetConsoleTextAttribute(h, 7);
								cout << endl;
							}
						}
						else
						{
							for (short loop = 0; loop < 3; loop++)
							{
								fout << monsters[loop].getName() << " " << monsters[loop].getStatus() << " " << monsters[loop].getType()
									<< " " << monsters[loop].getPower() << " " << monsters[loop].getDefense() << " "
									<< monsters[loop].getAgility() << " " << (monsters[loop].getAttack())[0] << " " <<
									(monsters[loop].getAttack())[1] << " "
									<< (monsters[loop].getAttack())[2] << " " << (monsters[loop].getAttack())[3] << " " << player1 << " "
									<< player2 << " " << HP1 << " " << HP2 << " " << name1 << " " << name2 << " ";
							}
							fout.close();
							playInterface();
							return;
						}
					}
					else
					{
						continue;
					}

				}
				/*if (enter != 27)
				{
					arrowKey = _getch();
				}*/
				//Enter = 13 and \n = 10
				if (enter == 224)
				{
					arrowKey = _getch();
					if (arrowKey == 72) //up
					{
						if (coutArrayIndex == 0)
						{
							coutArrayIndex = 3;
						}
						else
						{
							coutArrayIndex--;
						}
					}
					else if (arrowKey == 80) //down
					{
						if (coutArrayIndex == 3)
						{
							coutArrayIndex = 0;
						}
						else
						{
							coutArrayIndex++;
						}
					}
					else if (arrowKey == 77) //right
					{

					}
					else if (arrowKey == 75) //left
					{

					}
					if (coutArrayIndex == 0)
					{
						enterArray[0] = 192;
						enterArray[1] = 7;
						enterArray[2] = 7;
						enterArray[3] = 7;
					}
					else if (coutArrayIndex == 1)
					{
						enterArray[0] = 7;
						enterArray[1] = 192;
						enterArray[2] = 7;
						enterArray[3] = 7;
					}
					else if (coutArrayIndex == 2)
					{
						enterArray[0] = 7;
						enterArray[1] = 7;
						enterArray[2] = 192;
						enterArray[3] = 7;
					}
					else if (coutArrayIndex == 3)
					{
						enterArray[0] = 7;
						enterArray[1] = 7;
						enterArray[2] = 7;
						enterArray[3] = 192;
					}

				}
				else
				{
					continue;
				}

			}

			if (coutArrayIndex == 0) //Attack 1
			{
				HP1 += ((monsters[player1].getDefense() - (monsters[player2].getPower() + attacks2[0])) > 0 ? 0 : (monsters[player1].getDefense() - (monsters[player2].getPower() + attacks2[0])));
			}
			else if (coutArrayIndex == 1) //Attack 2
			{
				HP1 += ((monsters[player1].getDefense() - (monsters[player2].getPower() + attacks1[1])) > 0 ? 0 : (monsters[player1].getDefense() - (monsters[player2].getPower() + attacks2[1])));
			}
			else if (coutArrayIndex == 2) //Attack 2
			{
				HP1 += ((monsters[player1].getDefense() - (monsters[player2].getPower() + attacks2[2])) > 0 ? 0 : (monsters[player1].getDefense() - (monsters[player2].getPower() + attacks2[2])));
			}
			else if (coutArrayIndex == 3) //Attack 2
			{
				HP1 += ((monsters[player1].getDefense() - (monsters[player2].getPower() + attacks2[3])) > 0 ? 0 : (monsters[player1].getDefense() - (monsters[player2].getPower() + attacks2[3])));
			}

			if (!(HP1 > 0 && HP2 > 0))
			{
				break;
			}
		}

		PlaySound(TEXT("Death effect oop.wav"), NULL, SND_SYNC);
		if (CONTROL_VARIABLE == 0) //Music 1
		{
			PlaySound(TEXT("8 bit oop.wav"), NULL, SND_LOOP | SND_ASYNC);

		}
		else if (CONTROL_VARIABLE == 1) //Music 2
		{
			PlaySound(TEXT("Arabic oop.wav"), NULL, SND_LOOP | SND_ASYNC);

		}
		else if (CONTROL_VARIABLE == 2) //Music 3
		{
			PlaySound(TEXT("Blade runner resonance oop.wav"), NULL, SND_LOOP | SND_ASYNC);

		}
		else if (CONTROL_VARIABLE == 3) //Music 4
		{
			PlaySound(TEXT("L Equipe Du Son oop.wav"), NULL, SND_LOOP | SND_ASYNC);

		}
		else if (CONTROL_VARIABLE == 4) //Music 5
		{
			PlaySound(TEXT("Whistle oop.wav"), NULL, SND_LOOP | SND_ASYNC);

		}
		else if (CONTROL_VARIABLE == 5) //Music 6
		{
			PlaySound(TEXT("Ching chang hanji oop.wav"), NULL, SND_LOOP | SND_ASYNC);

		}
		if (HP1 <= 0)
		{
			system("CLS");
			cout << "\n\n\n\t\t\t" << name2 << " Won!\n\n\t\t\tPress any key to continue...";
			HP1 = 0;
			HP2 = 0;
			_getch();
			playInterface();
			return;
		}
		else
		{
			system("CLS");
			cout << "\n\n\n\t\t\t" << name1 << " Won!\n\n\t\t\tPress any key to continue...";
			HP1 = 0;
			HP2 = 0;
			_getch();
			playInterface();
			return;
		}

		playInterface();
		return;
	}

	Monster* getMonsters()
	{
		return monsters;
	}
};

short MonsterGame::HP1 = 0;
short MonsterGame::HP2 = 0;
short MonsterGame::player1 = 0;
short MonsterGame::player2 = 0;
string MonsterGame::name1 = "sadddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
string MonsterGame::name2 = "sddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";

int main()
{
	MonsterGame a;
	a.playInterface();
	_getch();
	return 0;
}
