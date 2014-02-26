#include "uwl_game.h"
#include "uwlec/uwlec_entity.h"
#include "uwlec/uwlec_component.h"
#include "uwlec/uwlec_moveable.h"

// TODO: REMOVE ME !!!!!!!!!!!!!
#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif
// /TODO

using uwlec::Entity;
using uwlec::Moveable;

namespace uwl {

const char* WindowTitle = "The Unreal World";
const int WindowWidth = 640;
const int WindowHeight = 640;

Game::Game()
{
    _fileSystem = std::make_shared<uwlinf::FileSystem>();
    _windowManager = std::make_shared<oglwin::WindowManager>();
    _entityManager = std::make_shared<uwlman::EntityManager>();
    _assetManager = std::make_shared<oglres::AssetManager>(_fileSystem);
    _gameLogicSystem = std::make_shared<uwlsys::GameLogicSystem>(_entityManager);
    _gfxSystem = std::make_shared<uwlsys::GfxSystem>(_entityManager, _assetManager);
}

Game::~Game()
{
}

void Game::initialize()
{
    // Initialize window
    _windowManager->createWindow(WindowTitle, WindowWidth, WindowHeight);

    // Initialize systems
    _gfxSystem->initialize();
    _gameLogicSystem->initialize();

    // Initialize entities
    auto shipEntity = std::make_shared<Entity>();
    auto moveableComponent = std::make_shared<Moveable>();

    _entityManager->addComponent<Moveable>(shipEntity, std::make_shared<Moveable>());
    _entityManager->registerEntity(shipEntity);

    // Initialize state
    _time = 0.0;
}

void Game::finalize()
{
    _gameLogicSystem->finalize();
    _gfxSystem->finalize();
    _windowManager->closeWindow();
}

bool Game::isDone()
{
    return _windowManager->windowCanClose();
}

void Game::tick()
{
    // Get time delta (TODO: move time to utils)
    double t = 0.0, dt = 0.0;

    // Avoid microcosmically small time deltas
    //while (dt < 0.001) {
        t = glfwGetTime();
        dt = t - _time;
    //}

    // Process entity events
    _entityManager->processChanges();

    // Update game logic
    _gameLogicSystem->tick(t, dt);

    // Update GFX
    _gfxSystem->tick(t, dt);

    // Present to window
    _windowManager->redrawWindow();

    _time = t;
}

};
