#include "app.h"

App::App() {
    Game* game = new Game;
    game->run();
    game->cleanup();
}

int main() {
    App* app = new App;
    return 0;
}