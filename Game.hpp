/* Methods To Implement:
    - turn
    - players
    - winner
*/

#include <iostream>
#include <vector>
#include <string>
#pragma once

using std::string;
using std::vector;

namespace coup
{
    class Game
    {
    private:
        vector<string> players_list;
        vector<string> last_action;

    public:
        string turn();
        vector<string> players();
        string winner();
    };
}