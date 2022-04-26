/* Inherits from Player.hpp but also implements:
    - block assassin
*/

#include <iostream>
#include "Player.hpp"

namespace coup{

    class Contessa: public Player{

        public:
            Contessa(Game game, string name);
            bool block(Player player);
    };
}