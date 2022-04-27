/* Inherits from Player.hpp but also implements:
    - coup with 3 coins
*/

#include <iostream>
#include <string>
#include "Player.hpp"

using std::string;

namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game game, string name);
        bool coup(Player player);
    };
}