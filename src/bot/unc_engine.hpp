//
// Created by utnam on 12/25/2025.
//

#ifndef CS_CPP_UNC_ENGINE_HPP
#define CS_CPP_UNC_ENGINE_HPP
#include "../../include/utils/state_repr.hpp"


class UncEngine
{
public:
    UncEngine();
    State_str best_move(const State_str& state);
};
#endif //CS_CPP_UNC_ENGINE_HPP