#ifndef _KENOGAME_H_
#define _KENOGAME_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include "kenobet.h"

using set_of_numbers_type = std::vector<number_type>;
using cash_type           = float; //<! Defines the wage type in this application.
using number_type         = unsigned short int; //<! data type for a keno hit.
using set_of_numbers_type = std::vector<number_type>; 
using set_of_cash_type    = std::vector<std::vector<cash_type> >; //<! matrix for payout table

class KenoGame
{
private:
	set_of_numbers_type  m_selection;   //<! The 20 numbers randomly picked
	number_type          m_curr_round;  //<! Current round in the game
	KenoBet              m_kenobet;     //<! The player's bet data
	bool                 m_can_read;    //<! Informs if it was possible to read file
	cash_type            m_wage_bet;        //<! Value of the bet on each round
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
/*	KenoGame(){
				
	}
	~KenoGame();*/

	void initialize_game(std::string filename);

	void update();

	void initial_render() const;

	void render() const;

	void print_payout_table() const;

	bool game_over() const;

	/*! Reads the player's bet file.
		@param filename Bet file name.
		@param kenobet_ KenoBet
		@return True if the file was successfully read */
	bool read_file(std::string filename);
		
};

#endif
