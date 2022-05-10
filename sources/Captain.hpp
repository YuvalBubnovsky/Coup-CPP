#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup{

    class Captain: public Player{

        public:
            Captain(Game& game, string name) : Player(&game, name, "Captain"){};
            bool block(Player& player);
            bool steal(Player& player);
    };
}
