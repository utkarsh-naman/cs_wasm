//
// Created by utnam on 12/24/2025.
//

#include "../include/map-.hpp"
#include "../include/map.hpp"
#include "../include/utils/p_serializer.hpp"
#include "../include/utils/serializer.hpp"
#include <algorithm>
#include <iostream>

#include <queue>

#include "../include/map.hpp"
#include "../include/map.hpp"


void print_p_state(const State_str& s)
{
    cout << "[ ";
    cout << s.data() << " ";
    cout << "]:\n";
}



void print_p_map(const PMap& map_0)
{
    for (const auto& [state, props] : map_0)
    {
        print_p_state(state);
        cout << "\t-> score: " << props.score << "\n";

        cout << "\tprevious states:\n";
        for (const State_str& next : props.previous_states)
        {
            cout << "\t";
            print_p_state(next);
            cout << "\n";
        }
        cout << "\n";
    }
}



PMap init_p_map()
{
    Map map_0 = load_map("map_0");
    PMap map_1;
    for (auto& [state, props] : map_0)
    {
        NState_Properties nprops;
        nprops.score = 0.0;
        nprops.previous_states = prev_states(state);
        map_1[state] = nprops;
    }

    return map_1;
}

void gen_p_map(const string& filename)
{
    Map map_0 = load_map("map_0");
    PMap map_1;
    for (auto& [state, props] : map_0)
    {
        NState_Properties nprops;
        nprops.score = 0.0;
        nprops.previous_states = prev_states(state);
        map_1[state] = nprops;
    }


    save_p_map(map_1,  filename);
}
