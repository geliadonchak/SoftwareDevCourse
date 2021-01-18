#include "utils/config.h"
#include "game.h"

int main() {
    Config::init("config.json");
    graphics::init();

    game main_game;
    main_game.start();
    return 0;
}
