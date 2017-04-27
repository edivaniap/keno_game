/**
 * @file keno.cpp
 * @version 1.0
 * @date 26/04/2017
 * @author Edivânia Pontes de Oliveira
 * @title Main program
 * @brief The Main program contain the main game loop.
 */

#include "../include/kenogame.h"

int main(int argc, char const *argv[])
{
    // If player doesn't pass file name by argument, stop program
    if ( argc < 2)
        return EXIT_FAILURE;

    KenoGame kenogame;

    kenogame.initialize_game( argv[1] );

    if( not kenogame.game_over() )
        kenogame.initial_render();

    srand((unsigned)time(0)); //for rand

    // The Game Loop
    while( not kenogame.game_over() )
    {
        kenogame.process_round();
        kenogame.update();
        kenogame.render();
    }

    kenogame.render_log();

    return EXIT_SUCCESS;
}
