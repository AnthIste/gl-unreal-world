////////////////////////////////////////////////////////////////
// Program Boostrapper
//
// This file is just for starting up the program and
// interacting with the system environment. The rest of the
// execution should be deferred to subsystems.
////////////////////////////////////////////////////////////////

#include "uwl/uwl_game.h"

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>

#include <memory>

using uwl::Game;

using namespace log4cxx;
LoggerPtr logger(Logger::getRootLogger());

int main()
{
    BasicConfigurator::configure();

    auto game = std::make_shared<Game>();

    // Initialize game engine
    LOG4CXX_DEBUG(logger, "Initializing game engine");
    game->initialize();

    // Enter main window loop
    LOG4CXX_DEBUG(logger, "Entering main game loop");
    while (!game->isDone())
    {
        // Update game engine
        game->tick();
    }

    // Cleanup engine
    LOG4CXX_DEBUG(logger, "Cleaning up game engine resources");
    game->finalize();

    return 0;
}
