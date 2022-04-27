/* Inherits from Player.hpp but also implements:
    - ttransfer
*/

#include <iostream>
#include "Player.hpp"

namespace coup{
    class Ambassador: public Player{
        public:
            Ambassador(Game game, std::string name);
            bool transfer(Player from_player, Player to_player);
            bool block(Player player);
    };
}