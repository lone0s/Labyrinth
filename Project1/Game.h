/**
* @file Game.h
* @brief Declares the Game class which is used to solve a maze.
*/

#pragma once
#include "Grid.h"
#include "Player.h"
#include "Tracer.h"
#include "Heuristic.h"

/**
* @class Game
* @brief The main class for solving a maze. 
* The Game class holds a grid, player, and tracer objects, and uses them to solve a maze. It can also display the maze and its progress in solving it.
*/
class Game
{
	Grid grid;
	size_t cpt;
public:
	/**
	* @brief Constructs a new Game object and initializes it with the maze from the specified file.
	* @param file The name of the file containing the maze.
	*/
	Game(const std::string& file);

	/**
	 * @brief Displays the current state of the maze and the progress of the player solving it.
	 */
	void display();

	/**
	 * @brief Plays the game using the specified heuristic to guide the player.
	 * @param heuristic The heuristic to use for guiding the player.
	 * @param displayed Whether to display the progress of the player solving the maze.
	 */
	void play(Heuristic& heuristic, bool displayed = false, bool notEpileptic = true);
};


