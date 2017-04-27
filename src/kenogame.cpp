#include "kenogame.h"

void KenoGame::initialize_game( std::string filename )
{
    //read file and initialize m_kenobet with player's bet
    m_can_read = read_file( filename );
    
    if ( not m_can_read )
        goto end_initialize_game;

    m_wage_bet = m_kenobet.get_wage() / m_kenobet.get_rounds();
    m_curr_round = 0;
    m_selection.clear();

    end_initialize_game: ;
}

void KenoGame::initial_render() const
{
    std::cout << "You are going to wage a total of $" << m_kenobet.get_wage() <<" dollars.\n";
    std::cout << "Going for a total of "<< m_kenobet.get_rounds() <<" rounds, waging $" << m_wage_bet <<" per round.\n\n";

    std::cout << "Your bet has " << m_kenobet.size() << " numbers. They are: ";
    m_kenobet.print_spots();
    std::cout << std::endl;

    print_payout_table();
    std::cout << "--------------------------------------------------\n";
}

bool KenoGame::game_over() const
{
    bool over = false;

    if( not m_can_read )
        over = true;

    if( m_curr_round > m_kenobet.get_rounds() )
        over = true;

    return over;
}

void KenoGame::print_payout_table() const
{
    const std::vector<std::string> fields_ = { "Hits", "Payout" };

    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir primeira linha
        std::cout << "+" << std::setw(fields_[i].size()+3) << std::setfill('-');   
    }
    std::cout << "+" << std::endl;

    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir fields
        std::cout << "| " << fields_[i] << " ";
    }
    std::cout << "|" << std::endl;

    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir segunda linha
        std::cout << "+" << std::setw(fields_[i].size()+3) << std::setfill('-');   
    }
    std::cout << "+" << std::endl;

    for (auto i = 0u; i < m_kenobet.size() + 1; ++i) { //imprimir elementos
            std::cout << std::setfill(' ');
            std::cout << "| " << std::setw(fields_[0].size()) << i << " ";
            std::cout << "| " << std::setw(fields_[1].size()) << m_payouts[m_kenobet.size()-1][i] << " ";
        std::cout << "|" << std::endl;
    }

    for (auto i = 0u; i < fields_.size(); ++i) { //imprimir ultima linha
        std::cout << "+" << std::setw(fields_[i].size()+3) << std::setfill('-');   
    }
    std::cout << "+" << std::endl;
}

bool KenoGame::read_file( std::string filename )
{
    std::ifstream ifs;

    std::cout << ">>> Preparing to read bet file [" << filename << "], please wait...\n";
    std::cout << "--------------------------------------------------\n\n";

    ifs.open( filename.c_str() ); //tentar abrir aquivo

    if( ifs.fail() ) { //verificando erro
        std::cout << ">> read_file(): Erro. Cannot open the file [" << filename << "], try again.\n";
        return false;
    }

    std::cout << ">>> Bet successfully read!\n";

    int line = 0;
    while( true ) { //preenchendo keno
        float elem;
        if ( !(ifs >> elem) ) break;
        if ( line == 0 )
            m_kenobet.set_wage( elem );
        else if ( line == 1 )
            m_kenobet.set_rounds( (int) elem );
        else
            m_kenobet.add_number( (int) elem );
        line++;
    }

    ifs.close(); //fechar arquivo
    return true;
}
