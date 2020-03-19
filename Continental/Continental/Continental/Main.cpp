#include <stdio.h>
#include <iostream>
#include <string>
/*
drawing[10] = {
							 "    -----+",
							 "    |    |",
							 "    O    |",
							"   \/|\\    |",
							 "    |    |",
							 "  \/ \\    |",
							 "         |",
							 "         |",
							 "  _______|",
							 " |       |"
					   };*/
std::string zero = "    -----+";
std::string one = "    |    |";
std::string two = "    O    |";
std::string threeA = "    |    |";
std::string threeB = "   \/|    |";
std::string threeC = "   \/|\\   |";
std::string four = "    |    |";
std::string fiveA = "   \/     |";
std::string fiveB = "   \/ \\   |";
std::string end = "|\\\/O|\/| |\\";
std::string initialHang[10]= {
							 "    -----+",
							 "         |",
							 "         |",
							 "         |",
							 "         |",
							 "         |",
							 "         |",
							 "         |",
							 "  _______|",
							 " |       |"
							 };
std::string drawing[10];
int incercari;
std::string word = "";
std::string ongoing="";

void initialize()
{
	for (int i = 0; i < 10; i++)
		drawing[i] = initialHang[i];
}


void paint()
{
	for (int i = 0; i < 10; i++)
		std::cout << drawing[i] << std::endl;
}




void meniu()
{
	std::cout << "Hello!\n";
	std::cout << "1.Start game!\n";
	std::cout << "0.Exit!\n";
	std::cout << "Choose an option:";
}


void stage(int cont)
{
	switch (cont)
	{
	case 0:
		initialize();
		paint();
		break;
	case 1:
		drawing[1] = one;
		paint();
		break;
	case 2:
		drawing[2] = two;
		paint();
		break;
	case 3: 
		drawing[3] = threeA;
		paint();
		break;
	case 4:
		drawing[3] = threeB;
		paint();
		break;
	case 5:
		drawing[3] = threeC;
		paint();
		break;
	case 6:
		drawing[4] = four;
		paint();
		break;
	case 7:
		drawing[5] = fiveA;
		paint();
		break;
	case 8: 
		drawing[5] = fiveB;
		paint();
		break;
	case 9:
		initialize();
		drawing[7] = end;
		paint();
		break;
	default: paint();
		break;
	}
}

void singlePlayer(std::string word)
{
	paint();
	ongoing = "";
	incercari = 8;
	int cont = 0;
	int i = 0;
	int j = 0;
	char guess;
	std::string alreadyTried="";
	for (j = 0; j < word.length(); j++)
	{
		ongoing.append("_");
	}
	while (incercari >= 0)
	{
		std::cout << "Tries:" << incercari << std::endl;
		std::cout << "Guessed:" << ongoing << std::endl;
		bool ch = false;
		std::cout << "Insert character for guess:";
		std::cin >> guess;
		//if()
		if (alreadyTried.find_first_of(guess) != std::string::npos)
		{
			std::cout << "You have already tried '" << guess << "'\n";
		}
		else
		{
			for (i = 0; i < word.length(); i++)
			{
				if (word[i] == guess)
				{
					ongoing[i] = guess;
					ch = true;
				}
				if (i == word.length() - 1 && ch != true)
				{
					incercari--;
					cont++;
				}
			}
		}
		stage(cont);
		alreadyTried.append(&guess);
		
		if (ongoing==word)
		{
			std::cout << "You won. Congratulations!!\n";
			break;
		}
		if (incercari == 0)
		{
			std::cout << "You lost!\n";
			break;
		}
	}
}

int main()
{
	int opt;
	do
	{
		meniu();
		std::cin >> opt;
		switch (opt)
		{
		case 1:
			initialize();
			
			std::cout << "Insert word to start game:";
			std::cin >> word;
			system("cls");
			singlePlayer(word);
			break;
		default:
			break;
		}
	} while (opt != 0);

	return 0;
}