/* Inherits from Player.hpp but also implements:
    - tax
*/

#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup
{
    class Duke : public Player
    {
    public:
        Duke(Game game, string name);
        bool tax();
        bool block(Player player);
    };
}