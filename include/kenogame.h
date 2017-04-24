#ifndef _KENOGAME_H_
#define _KENOGAME_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include "kenobet.h"

using set_of_numbers_type = std::vector<number_type>;

class KenoGame
{
private:
	set_of_numbers_type m_;
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