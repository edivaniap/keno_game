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
using set_of_cash_type    = std::vector<cash_type>;

class KenoGame
{
private:
	set_of_numbers_type m_selection; //<! The 20 numbers randomly picked
	set_of_cash_type payout_table; //<! Keep all the payouts factors
	number_type m_current_round; //<! Current round in the game
	KenoBet * m_kenobet //<! The player's bet data
public:
/*	KenoGame(){
				
	}
	~KenoGame();*/

	/*! Reads the player's bet file.
		@param filename Bet file name.
		@param kenobet_ KenoBet
		@return True if the file was successfully read */
	bool read_file(std::string filename, KenoBet & kenobet_ );
		
};

#endif