//
// Created by utnam on 12/25/2025.
//

#include "unc_engine.hpp"

#include <algorithm>
#include <iostream>

#include "../../include/utils/state_repr.hpp"
#include "../../include/utils/serializer.hpp"

// State_str best_move(State_str state)
// {
//     State_str best_state;
//     Map botmap = load_map("map_f_set");
//
//     return best_state;
// }

class UncEngine
{
    Map solution_map;

    public:
    UncEngine()
    {
        solution_map = load_map("map_f_set");
    }

    State_str best_move(const State_str& state)
    {
        State_str best_move;

        vector<State_str> options;
        auto best_id = std::max_element(
            options.begin(),
            options.end(),
            [&](const State_str& a, const State_str& b) {
                return solution_map.at(a).score < solution_map.at(b).score;
            }
        );
        best_move = *best_id;
        return best_move;
    }
};