//
// Created by utnam on 12/27/2025.
//


#include "serializer.hpp"

class UncEngine
{
public:
    Map game_map;
    UncEngine()
    {
        game_map = load_map("map_final");
    };
    State_str play(State_str state)
    {
        State_str move;
        vector<State_str> move_options = game_map[state].next_states;
        if (!move_options.empty())
        {

        }
        return move;
    };
private:

};
