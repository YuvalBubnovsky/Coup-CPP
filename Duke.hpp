/* Inherits from Player.hpp but also implements:
    - tax
*/

#include <iostream>
#include "Player.hpp"

namespace coup{
    class Duke: public Player{
        public:
            Duke(Game game, std::string name);
            bool tax();
            bool block(Player player);
    };
}