#include "Captain.hpp"
#include "Player.hpp"

namespace coup
{
    Captain::Captain(Game game, string name)
    {
        this->name = name;
        this->game = game;
        this->coins_num = 0;
    }
    bool Captain::block(Player player) { return false; }
    bool Captain::steal(Player player) { return false; }
}