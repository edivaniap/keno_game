#include "kenogame.h"

bool KenoGame::read_file(std::string filename, KenoBet & kenobet_ )
{
	std::ifstream ifs;

	std::cout << ">>> Preparing to read bet file [" << filename << "], please wait...\n";
	std::cout << "--------------------------------------------------\n";

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
			kenobet_.set_wage( elem );
		else if ( line == 1 )
			kenobet_.set_rounds( elem );
		else
			kenobet_.add_number( elem );
		line++;
	}

	ifs.close(); //fechar arquivo
	return true;
}