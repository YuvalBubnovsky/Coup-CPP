#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;
using std::to_string;

#define A_COUP_COST 3

namespace coup{

    class Assassin: public Player{

        public:
            Assassin(Game& game, string name) : Player(&game, name, "Assassin"){};
            bool coup(Player& target);
    };
}
