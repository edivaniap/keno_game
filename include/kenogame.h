/**
 * @file kenogame.h
 * @version 1.0
 * @date 26/04/2017
 * @author Edivânia Pontes de Oliveira
 * @title Class Keno game
 * @brief Class for Keno game configuration
 */

#ifndef _KENOGAME_H_
#define _KENOGAME_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>     //rand
#include <algorithm> //std::sort
#include "kenobet.h"

using set_of_numbers_type = std::vector<number_type>;
using cash_type           = float; //<! Defines the wage type in this application.
using number_type         = unsigned short int; //<! data type for a keno hit.
using set_of_numbers_type = std::vector<number_type>; 
using set_of_cash_type    = std::vector<std::vector<cash_type> >; //<! matrix for payout table

class KenoGame
{
private:
	set_of_numbers_type  m_selecteds;   //<! The 20 numbers randomly picked
	set_of_numbers_type  m_curr_hits;   //<! Determine how many bet spots match the selecteds numbers.
	number_type          m_curr_round;  //<! Current round in the game
	KenoBet              m_kenobet;     //<! The player's bet data
	bool                 m_can_read;    //<! Informs if it was possible to read file
	cash_type            m_wage_bet;    //<! Value of the bet on each round
	cash_type            m_curr_payout; //<!
	cash_type            m_curr_cameout;//<!
	cash_type            m_player_won;    //<! Total of cash that player won
	set_of_cash_type     m_payouts = {  //<! Keep all the payouts factors
			{ 0.0, 3.0 },
			{ 0.0, 1.0, 9.0 },
			{ 0.0, 1.0, 2.0, 16.0 },
			{ 0.0, 0.5, 2.0,  6.0, 12.0 },
			{ 0.0, 0.5, 1.0,  3.0, 15.0, 50.0 },
			{ 0.0, 0.5, 1.0,  2.0,  3.0, 30.0, 75.0 },
			{ 0.0, 0.5, 0.5,  1.0,  6.0, 12.0, 36.0, 100.0 },
			{ 0.0, 0.5, 0.5,  1.0,  3.0,  6.0, 19.0,  90.0, 720.0 },
			{ 0.0, 0.5, 0.5,  1.0,  2.0,  4.0,  8.0,  20.0,  80.0, 1200.0 },
			{ 0.0, 0.0, 0.5,  1.0,  2.0,  3.0,  5.0,  10.0,  30.0,  600.0, 1800.0 },
			{ 0.0, 0.0, 0.5,  1.0,  1.0,  2.0,  6.0,  15.0,  25.0,  180.0, 1000.0, 3000.0 },
			{ 0.0, 0.0, 0.0,  0.5,  1.0,  2.0,  4.0,  24.0,  72.0,  250.0,  500.0, 2000.0, 4000.0 },
			{ 0.0, 0.0, 0.0,  0.5,  0.5,  3.0,  4.0,   5.0,  20.0,   80.0,  240.0,  500.0, 3000.0, 6000.0 },
			{ 0.0, 0.0, 0.0,  0.5,  0.5,  2.0,  3.0,   5.0,  12.0,   50.0,  150.0,  500.0, 1000.0, 2000.0, 7500.0 },
			{ 0.0, 0.0, 0.0,  0.5,  0.5,  1.0,  2.0,   5.0,  15.0,   50.0,  150.0,  300.0,  600.0, 1200.0, 2500.0, 10000.0 }
		};
	
public:
    /*KenoGame()
	~KenoGame();*/

	/*! Initialize the game data if it could possible reads player'r file. 
		@param filename Bet file name. */
	void initialize_game(std::string filename);

	/*! Process the rounds, generating 20 new numbers for raffle and calculating player's hits. */
	void process_round( void );

	/*! Updates the game data after process a round. */
	void update( void );

	/*! Displays game's initial informations on the screen after after read the player's file. */
	void initial_render( void ) const;

	/*! Displays game's informations on the screen after after each round update. */
	void render( void ) const;

	/*! Displays game's final information on the screen after the game is over. */
	void render_log( void ) const;

	/*! Prints the payout table according to the number of spots and hits of the player. */
	void print_payout_table( void ) const;

	/*! Prints the randoms numbers of the raffle. */
	void print_selecteds( void ) const;

	/*! Prints player's hits in current round. */
	void print_curr_hits( void ) const;

	/*! Sets number of player's hits in current round. */
	void set_curr_hits( void );

	/*! Check if the game is over 
	    @return True if the game's over, false otherwise. */
	bool game_over( void ) const;

	/*! Generate a random number for the raffle.
	    @return Random number between 1 and 80.  */
	number_type generate_random() const;

	/*! Check if the random number is already in vector of numbers selecteds.
		@param elem_ Number randomly generated.
	    @return True if elem_ isn't on vector, false otherwise. */
	bool is_unique( number_type elem_ ) const;

	/*! Reads the player's bet file.
		@param filename Bet file name.
		@param kenobet_ KenoBet with player bet data.
		@return True if the file was successfully read. */
	bool read_file(std::string filename);
		
};

#endif
