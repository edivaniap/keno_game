/**
 * @file kenobet.cpp
 * @version 1.0
 * @date 22/04/2017
 * @author Edivânia Pontes de Oliveira
 * @title KenoBet program
 * @brief Contains the implementation of KenoBet's functions.
 */

#include "kenobet.h"

KenoBet::KenoBet() 
{ 
	m_wage = 0; 
	m_rounds = 0;
	m_net_balance = 0;
}

KenoBet::~KenoBet() { /*delete [] m_spots;*/ }

bool KenoBet::add_number ( number_type spot_ )
{
	//
	if ( spot_ < 1 || spot_ > 80 ||  size() >= 15 )
		return false;

	for ( auto i = m_spots.begin(); i != m_spots.end(); i++ )
	{
		if( *i == spot_ )
			return false;
	}

	m_spots.push_back( spot_ );
	return true;
}

bool KenoBet::set_wage ( cash_type wage_ )
{
	if( wage_ <= 0) 
		return false;
	m_wage = wage_;
	return true;
}

void KenoBet::set_net_balance ( cash_type value_ )
{
	m_net_balance += value_;
}

bool KenoBet::set_rounds ( number_type rounds_ )
{
	if( rounds_ <= 0)
		return false;
	m_rounds = rounds_;
	return true;
}

void KenoBet::reset ( void ) 
{
	m_wage = 0;
	m_rounds = 0;
	m_spots.clear();
}

cash_type KenoBet::get_wage ( void ) const
{
	return m_wage;
}

cash_type KenoBet::get_net_balance ( void ) const
{
	return m_net_balance;
}

cash_type KenoBet::get_rounds ( void ) const
{
	return m_rounds;
}

size_t KenoBet::size ( void ) const
{
	return m_spots.size();
}

set_of_numbers_type KenoBet::get_spots ( void ) const
{
	return m_spots;
}

void KenoBet::print_spots ( void ) const
{
	std::cout << "[ ";
	for( auto i = m_spots.begin(); i != m_spots.end(); i++ )
		std::cout << *i << " "; 
	std::cout << "]";
}

void KenoBet::sort_spots ( void )
{
	std::sort(m_spots.begin(), m_spots.end() );
}