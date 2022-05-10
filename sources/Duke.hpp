#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup
{
    class Duke : public Player
    {

    public:
        Duke(Game& game, string name) : Player(&game, name, "Duke"){};
        bool tax();
        bool block(Player& player);
    };
}