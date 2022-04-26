/* Methods To Implement:
    - turn
    - players
    - winner
*/

#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"

using std::string;
using std::vector;

namespace coup{

    class Game{

        private:
            vector<Player> player_list1;
            vector<string> player_list;
            bool active;

        public:
            bool start_game();
            string turn();
            string winner();
            vector<string> get_list();
    };
}