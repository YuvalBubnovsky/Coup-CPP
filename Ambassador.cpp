#include "Ambassador.hpp"
#include "Player.hpp"

namespace coup
{
    Ambassador::Ambassador(Game game, string name)
    {
        this->name = name;
        this->game = game;
        this->coins_num = 0;
    }
    
    bool Ambassador::transfer(Player src, Player dest) { return false; }
    bool Ambassador::block(Player player) { return false; }
}