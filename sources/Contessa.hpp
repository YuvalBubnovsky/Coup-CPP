/* Inherits from Player.hpp but also implements:
    - block assassin
*/

#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup
{
    class Contessa : public Player
    {
    public:
        Contessa(Game game, string name);
        bool block(Player player);
    };
}