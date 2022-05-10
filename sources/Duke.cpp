
#include "Duke.hpp"
#include "Player.hpp"

namespace coup
{
    Duke::Duke(Game game, string name)
    {
        this->name = name;
        this->game = game;
        this->coins_num = 0;
    }
    bool Duke::tax() { return false; }
    bool Duke::block(Player player) { return false; }
}