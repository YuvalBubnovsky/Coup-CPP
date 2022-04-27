#include "Contessa.hpp"
#include "Player.hpp"

namespace coup
{
    Contessa::Contessa(Game game, string name)
    {
        this->name = name;
        this->game = game;
        this->coins_num = 0;
    }
    bool Contessa::block(Player player) { return false; }
}