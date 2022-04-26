/* Methods To Implement:
    - income
    - foreign_aid
    - coup
    - role
    - coins
    - role specific block
*/

#include <iostream>
#include "Game.hpp"
#pragma once

using std::string;

namespace coup{
    
    class Player{

        protected:
            Game game;
            string name;
            int coins;
            string role;

        public:
            bool income();
            bool foreign_aid();
            bool coup(Player);
            int get_coins();
            string get_role();
    };
}