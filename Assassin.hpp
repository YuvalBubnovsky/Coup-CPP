/* Inherits from Player.hpp but also implements:
    - coup with 3 coins
*/

#include <iostream>
#include "Player.hpp"

namespace coup{

    class Assassin: public Player{

        public:
            Assassin(Game game, string name);
            bool coup(Player player);
    };
}