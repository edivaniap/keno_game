#ifndef _KENOBET_H_
#define _KENOBET_H_

#include <iostream>
#include <vector>

using cash_type           = float; //<! Defines the wage type in this application.
using number_type         = unsigned short int; //<! data type for a keno hit.
using set_of_numbers_type = std::vector<number_type>;

class KenoBet
{
private:
	cash_type m_wage; //<! The player's wage.
	number_type m_rounds; //<! The number of rounds the player wants
	set_of_numbers_type m_spots; //<! The player's bet.
public:
	//! Creats an empty Keno bet.
	KenoBet();

	//! Destroy Keno bet.
	~KenoBet();

	/*! Adds a number to the spots only if the number is not already there.
		@param spot_ The number we wish to include in the bet.
		@return T if number chosen is successfully inserted; F otherwise. */
	bool add_number ( number_type spot_ );

	/*! Sets the amount of money the player is betting.
		@param wage_ The wage.
		@return True if we have a wage above zero; false otherwise. */
	bool set_wage ( cash_type wage_ );

	/*! Sets number of rounds.
		@param rounds_ The number of rounds.
		@return True if we have a number above zero; false otherwise. */
	bool set_rounds ( cash_type rounds_ );

	// ! Resets a bet to an empty state.
	void reset ( void );
	
	/*! Retrieves the player’s wage on this bet.
		@return The wage value. */
	cash_type get_wage ( void ) const;

	/*! Retrieves the number of rounds on this bet.
		@return The number of rounds. */
	cash_type get_rounds ( void ) const;

	/*! Returns to the current number of spots in the player ’s bet .
		@return Number of spots present in the bet . */
	size_t size ( void ) const;

	/*! Determine how many spots match the hits passed as argument.
		@param hits_ List of hits randomly chosen by the computer.
		@return An vector with the list of hits. */
	set_of_numbers_type get_hits ( const set_of_numbers_type & hits_ ) const;

	/*! Return a vector < spot_type > with the spots the player has picked so far.
		@return The vector < spot_type > with the player ’s spots picked so far. */
	set_of_numbers_type get_spots ( void ) const;

	// ! Print the plyaer spots.
	void print_spots ( void ) const;

};

#endif