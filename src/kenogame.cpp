/**
 * @file kenogame.cpp
 * @version 1.0
 * @date 26/04/2017
 * @author Edivânia Pontes de Oliveira
 * @title KenoGame program
 * @brief Contains the implementation of KenoGame's functions.
 */

#include "kenogame.h"

void KenoGame::initialize_game( std::string filename )
{
    //read file and initialize m_kenobet with player's bet
    m_can_read = read_file( filename );
    
    if ( not m_can_read )
        goto end_initialize_game;

    m_kenobet.sort_spots();

    m_wage_bet = m_kenobet.get_wage() / m_kenobet.get_rounds();
    m_curr_round = 0;
    m_player_won = 0;
    m_curr_cameout = 0;
    m_selecteds.clear();
    m_curr_hits.clear();

    end_initialize_game: ;
}

void KenoGame::initial_render( void ) const
{
    std::cout << "\tYou are going to wage a total of $" << m_kenobet.get_wage() <<" dollars.\n";
    std::cout << "\tGoing for a total of "<< m_kenobet.get_rounds() <<" rounds, waging $" << m_wage_bet <<" per round.\n\n";

    std::cout << "\tYour bet has " << m_kenobet.size() << " numbers. They are: ";
    m_kenobet.print_spots();
    std::cout << std::endl;

    print_payout_table();
}

void KenoGame::render( void ) const
{
    std::cout << "\t\t--------------------------------------------------\n";
    std::cout << "\t\tThis is round #" << m_curr_round << " of " << m_kenobet.get_rounds();
    std::cout << ", and your wage is $" << m_wage_bet << ". Good luck!\n";
    std::cout << "\t\tThe selecteds numbers are: ";
    print_selecteds();
    std::cout << std::endl;
    std::cout << "\t\tYour bet spots are: ";
    m_kenobet.print_spots();
    std::cout << std::endl << std::endl;

    std::cout << "\t\tYou hit the following number(s) ";
    print_curr_hits();
    std::cout << ", a total of " << m_curr_hits.size() << " hits out of " << m_kenobet.size() << std::endl;
    std::cout << "\t\tPayout rate is " << m_curr_payout << ", thus you came out with: $" << m_curr_cameout << std::endl;
    std::cout << "\t\tYour net balance so far is: $" << m_kenobet.get_net_balance() << " dollars.\n";
}

void KenoGame::render_log( void ) const
{
	std::cout << "\n\n\t===== SUMMARY =====\n";
	std::cout << "\t>>> You spent in this game a total of $" << m_kenobet.get_wage() << " dollars.\n";
	std::cout << "\t>>> Hooray, you won $" << m_player_won << " dollars. See you next time! ;-)\n";
	std::cout << "\t>>> You are leaving the Keno table with $" << m_kenobet.get_net_balance() << " dollars.\n";
}

void KenoGame::process_round( void ) 
{
    m_curr_hits.clear();
    m_selecteds.clear();

    /*   generate randoms and fill the vector   */
    while ( m_selecteds.size() < 20 )
    {
        //gerar random
        number_type new_elem = generate_random();

        //check if the new element is unique and put in m_selecteds
        if ( is_unique ( new_elem ) )
            m_selecteds.push_back( new_elem );
    }

    //sort vector
    std::sort(m_selecteds.begin(), m_selecteds.end() );

    /*  calculate the player's hits   */
    set_curr_hits();
}

void KenoGame::update( void )
{
    m_curr_round++;

    m_curr_payout = m_payouts[m_kenobet.size()][m_curr_hits.size()];

    m_curr_cameout = m_wage_bet * m_curr_payout;
    
    m_player_won += m_curr_cameout - m_wage_bet;

    m_kenobet.set_net_balance( m_curr_cameout - m_wage_bet );
}

bool KenoGame::game_over( void ) const
{
    bool over = false;

    if( not m_can_read )
        over = true;

    if( m_curr_round == m_kenobet.get_rounds() ) {
        over = true;
        std::cout << "\n\t>>> End of rounds!\n";
        std::cout << "\t--------------------------------------------------\n";
    }

    return over;
}

void KenoGame::set_curr_hits( void )
{
    set_of_numbers_type player_spots = m_kenobet.get_spots();

    for( auto i = m_selecteds.begin(); i != m_selecteds.end(); i++ )
    {
        for( auto j = player_spots.begin(); j !=  player_spots.end(); j++ )
        {
            if( *i == *j )
                m_curr_hits.push_back(*j);
        }
    }
}

void KenoGame::print_selecteds( void ) const
{
    std::cout << "[ ";
    for( auto i = m_selecteds.begin(); i != m_selecteds.end(); i++ )
        std::cout << *i << " "; 
    std::cout << "]";
}

void KenoGame::print_curr_hits( void ) const
{
    std::cout << "[ ";
    for( auto i = m_curr_hits.begin(); i != m_curr_hits.end(); i++ )
        std::cout << *i << " "; 
    std::cout << "]";
}

void KenoGame::print_payout_table( void ) const
{
    const std::vector<std::string> fields_ = { "Hits", "Payout" };

    std::cout << "\t\t\t";
    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir primeira linha
        std::cout << "+" << std::setw(fields_[i].size()+3) << std::setfill('-');   
    }
    std::cout << "+" << std::endl;

    std::cout << "\t\t\t";
    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir fields
        std::cout << "| " << fields_[i] << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "\t\t\t";
    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir segunda linha
        std::cout << "+" << std::setw(fields_[i].size()+3) << std::setfill('-');   
    }
    std::cout << "+" << std::endl;

    for (auto i = 0u; i < m_kenobet.size() + 1; ++i) { //imprimir elementos
            std::cout << std::setfill(' ');
            std::cout << "\t\t\t| " << std::setw(fields_[0].size()) << i << " ";
            std::cout << "| " << std::setw(fields_[1].size()) << m_payouts[m_kenobet.size()-1][i] << " ";
        std::cout << "|" << std::endl;
    }

    std::cout << "\t\t\t";
    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir ultima linha
        std::cout << "+" << std::setw(fields_[i].size()+3) << std::setfill('-');   
    }
    std::cout << "+" << std::endl;
}

bool KenoGame::read_file( std::string filename )
{
    std::ifstream ifs;
    
    system("clear");

    std::cout << "\t>>> Preparing to read bet file [" << filename << "], please wait...\n";
    std::cout << "\t--------------------------------------------------\n";

    ifs.open( filename.c_str() ); //tentar abrir aquivo

    if( ifs.fail() ) { //verificando erro
        std::cout << "\t>>> read_file(): Erro. Cannot open the file [" << filename << "], try again.\n";
        return false;
    }

    std::cout << "\t>>> Bet successfully read!\n\n";

    int line = 0;
    while( true ) { //preenchendo keno
        float elem;
        if ( !(ifs >> elem) ) break;
        if ( line == 0 ) {
            m_kenobet.set_wage( elem );
            m_kenobet.set_net_balance( elem );
        }
        else if ( line == 1 )
            m_kenobet.set_rounds( (int) elem );
        else
            m_kenobet.add_number( (int) elem );
        line++;
    }

    ifs.close(); //fechar arquivo
    return true;
}

number_type KenoGame::generate_random() const
{
    int max = 80;
    int min = 1;
    int random = rand()%(max-min+1) + min;

    return random;
}

bool KenoGame::is_unique( number_type elem_ ) const
{
    for( auto i = m_selecteds.begin(); i != m_selecteds.end(); i++)
    {
        if( *i == elem_ )
            return false;
    }

    return true;
}