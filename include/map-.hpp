//
// Created by utnam on 12/24/2025.
//

#ifndef CS_CPP_MAP_MINUS_HPP
#define CS_CPP_MAP_MINUS_HPP

#include <map>
#include <string>
#include "utils/state_repr.hpp"

struct NState_Properties
{
    vector<State_str> previous_states;
};

using PMap = map<State_str, NState_Properties>;
PMap init_p_map();
void print_p_map(const PMap& map_0);
void gen_p_map(const string& filename);
#endif //CS_CPP_MAP_MINUS_HPP