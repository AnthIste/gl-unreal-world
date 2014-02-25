////////////////////////////////////////////////////////////////
// Program Boostrapper
//
// This file is just for starting up the program and
// interacting with the system environment. The rest of the
// execution should be deferred to subsystems.
////////////////////////////////////////////////////////////////

#include "uwl/uwl_game.h"

#include <memory>

using uwl::Game;

int main()
{
    auto game = std::make_shared<Game>();

    // Initialize game engine
    game->initialize();

    // Enter main window loop
    while (!game->isDone())
    {
        // Update game engine
        game->tick();
    }

    // Cleanup engine
    game->finalize();

    return 0;
}
