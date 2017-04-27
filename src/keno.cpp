/*!
 * Main program, which should contain the main game loop.
 *
 * \author Edivânia Pontes de Oliveira
 * \date 26/04/2017
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

    // The Game Loop
/*    while( not kenogame.game_over() )
    {
        //kenogame.process_events();
        //kenogame.update();
        //kenogame.render();
    }*/

    //kenogame.render_log();

    return EXIT_SUCCESS;
}
