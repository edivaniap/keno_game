#include "kenobet.h"

KenoBet::KenoBet() { m_wage = 0; }

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

bool KenoBet::set_rounds ( cash_type rounds_ )
{
	if( m_rounds <= 0) 
		return false;
	m_rounds = rounds_;
	return true;
}

void KenoBet::reset ( void ) { }

cash_type KenoBet::get_wage ( void ) const
{
	return m_wage;
}

cash_type KenoBet::get_rounds ( void ) const
{
	return m_rounds;
}

size_t KenoBet::size ( void ) const
{
	return m_spots.size();
}

set_of_numbers_type KenoBet::get_hits ( const set_of_numbers_type & hits_ ) const
{
	set_of_numbers_type hit;

	for( auto i = hits_.begin(); i != hits_.end(); i++ )
	{
		for( auto j = m_spots.begin(); j !=  m_spots.end(); j++ )
		{
			if( *i == *j )
				hit.push_back(*j);
		}
	}
	return hit;
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