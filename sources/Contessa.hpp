#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;
using std::stoi;

namespace coup
{
    class Contessa : public Player
    {

    public:
        Contessa(Game& game, string name) : Player(&game, name, "Contessa"){};
        bool block(Player& player);
    };
}