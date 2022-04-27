#include <iostream>
#include <string>
#include "Game.hpp"
#pragma once

using std::string;

namespace coup
{
    class Player
    {
    protected:
        Game game;
        string name;
        int coins_num;

    public:
        bool income();
        bool foreign_aid();
        bool coup(Player);
        int coins();
    };
}