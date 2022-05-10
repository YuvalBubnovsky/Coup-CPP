#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup{

    class Ambassador: public Player{

        public:
            Ambassador(Game& game, string name) : Player(&game, name, "Ambassador"){};
            bool transfer(Player& src, Player& dest);
            bool block(Player& player);
    };
}
