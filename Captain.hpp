/* Inherits from Player.hpp but also implements:
    - steal
*/

#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game game, string name);
        bool block(Player player);
        bool steal(Player player);
    };
}