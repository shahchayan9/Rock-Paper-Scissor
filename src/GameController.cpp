#include "GameController.h"

GameController::GameController(GameEngine *gameEngine) {
    engine = gameEngine;
}

void GameController::playRound(Choice humanChoice) {
    engine->playRound(humanChoice);
    engine->displayResults();
}