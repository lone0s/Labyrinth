#include <iostream>
#include <string>
#include <filesystem>
#include "Game.h"

int mainCLI()
{
	std::string testFilesPath = "../TestFiles/";
	std::string fileName;
	
	bool fileLoaded = false;
	Game* game = nullptr;

	//Factory pattern peut être ?
	std::vector<std::string> heuristicNames{
	"onlyRight",
	"onlyLeft",
	"embranchementUser",
	"escalier",
	"userInput"
	};
	size_t heuristicIndex = 0;
	bool heuristicChosen = false;
	std::string heuristicName;

	bool forcedDisplay = false;
	bool display = false;

	Heuristic* h = nullptr;


	

	//Header CLI
	std::cout << "  __  __                                               \n"
		" |  \\/  |                                  _       _   \n"
		" | \\  / |   __ _   ____   ___            _| |_   _| |_ \n"
		" | |\\/| |  / _` | |_  /  / _ \\          |_   _| |_   _|\n"
		" | |  | | | (_| |  / /  |  __/            |_|     |_|  \n"
		" |_|  |_|  \\__,_| /___|  \\___|                         \n"
		"                                ______                 \n"
		"                               |______|                \n";

	std::cout << "    --------------------------------------    \n\n";
	std::cout << "Welcome to the Labyrinth Solver !\n\n";
	//Choix du labyrinte
	std::cout << "Please enter the name of the file you want to solve: ";
	
	while (!fileLoaded)
	{
		try {
			std::cin >> fileName;
			//Penser a le delete
			game = new Game(testFilesPath + fileName);
			fileLoaded = true;

		}
		catch (std::exception& e) {
			std::cout << "Couldn't open the file, are you sure you've imported in the TestFiles folder?\n\n";
			std::cout << "Current files in the TestFiles folder:\n";
			for (const auto& entry : std::filesystem::directory_iterator("../TestFiles/"))
				std::cout << "    - " << entry.path() << std::endl;
		}
	}


	//Choix de l'héuristique
	std::cout << "Veuillez entrer le nom de l'heuristique voulue :\n";
	for (std::string name : heuristicNames)
		std::cout << "    - " << name << std::endl;
	while (true) {
		try
		{
			std::cin >> heuristicName;
			heuristicIndex = std::find(heuristicNames.begin(), heuristicNames.end(), heuristicName) != heuristicNames.end();
			std::cout << heuristicIndex << std::endl;

			heuristicIndex != 0 ? heuristicChosen = true : throw std::exception();
			break;
		}
		catch (const std::exception&)
		{
			std::cout << "Heuristique non reconnue, veuillez réessayer (sensible à la casse)\n";
		}
	}


	//Init de l'heuristique et du 
	switch (heuristicIndex) {
	case 1:
		h = new onlyRight();
		break;
	case 2:
		h = new onlyLeft();
		break;
	case 3:
		//h = new embranchementUser();
		break;
	case 4:
		//h = new escalier();
		break;
	case 5:
		//h = new userInput();
		break;
	default:
		//h = new userInput();
		break;
	}

	//Gestion de l'affichage
	if (!h)
		throw std::invalid_argument("Heuristique null, je dois mettre un terme a mon execution :((\n");
	
	if(!forcedDisplay) {
		while (true) {
			std::cout << "Voulez vous afficher l'execution de l'heuristique ? (y/n)\n";
			try {
				char c;
				std::cin >> c;
				c == 'y' ? display = true : c == 'n' ? display = false : throw std::exception();
				break;
			}
			catch (const std::exception& e)
			{
				std::cout << "Valeur non reconnue, veuillez réessayer (sensible à la casse)\n";
			}
		}
	}
	forcedDisplay ? display = forcedDisplay : display;

	try {
		game->play(*h, display);
	}
	catch (std::exception& e)
	{
		std::cerr << "Game broke :// \nshutting down.\n";
	}
	
	
	//Deleters 
	delete game;
	delete h;

	return 0;
}


int main() {
	/*Game game("../testfiles/lab3.txt");

	Heuristic* h = new chooseAll();
	game.play(*h, true);*/
	mainCLI();
}