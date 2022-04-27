#include "Assassin.hpp"
#include "Player.hpp"

namespace coup
{
    Assassin::Assassin(Game game, string name)
    {
        this->name = name;
        this->game = game;
        this->coins_num = 0;
    }
    bool Assassin::coup(Player player) { return false; }
}