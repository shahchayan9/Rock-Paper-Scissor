#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameEngine.h"

class GameController {
private:
    GameEngine *engine;

public:
    GameController(GameEngine *gameEngine);
    void playRound(Choice humanChoice);
};

#endif
