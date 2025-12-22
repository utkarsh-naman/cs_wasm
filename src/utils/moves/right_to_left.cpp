//
// Created by utnam on 12/22/2025.
//

#include "../../../include/utils/moves/right_to_left.hpp"
#include "../../../include/rules.hpp"
#include "../../../include/utils/state_repr.hpp"
#include "../../../include/utils/moves/arrange_attacker_victim.hpp"

State_str rl(const State_tuple& state)
{
    State_str rl_next_state_str = {0};
    Player attacker;
    Player victim;
    Attacker_index a_index = get<2>(state);
    if (a_index == 0)
    {
        attacker = get<0>(state);
        victim = get<1>(state);
    }
    else
    {
        attacker = get<1>(state);
        victim = get<0>(state);
    }

    // if victim is already lost
    if (get<1>(victim) == 0) return rl_next_state_str;
    // if attacking hand or victim hand is 0
    if (get<1>(attacker) == 0 || get<0>(victim) == 0) return rl_next_state_str;
    get<0>(victim) = static_cast<short>((get<0>(victim)+get<1>(attacker))%MAX_FINGER);
    const short temp_0 = min(get<0>(victim), get<1>(victim));
    const short temp_1 = max(get<0>(victim), get<1>(victim));
    get<0>(victim) = temp_0;
    get<1>(victim) = temp_1;
    return arrange_state(state, victim);
}