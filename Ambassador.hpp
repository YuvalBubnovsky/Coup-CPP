/* Inherits from Player.hpp but also implements:
    - ttransfer
*/

#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup
{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game game, string name);
        bool transfer(Player src, Player dest);
        bool block(Player player);
    };
}