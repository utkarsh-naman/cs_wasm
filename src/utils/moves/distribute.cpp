//
// Created by utnam on 12/22/2025.
//

#include "../../../include/utils/moves/distribute.hpp"

#include "../../../include/rules.hpp"
#include "../../../include/utils/state_repr.hpp"

Next_State_str_vector distribute(State_tuple state)
{
    Next_State_str_vector distribution_list;
    Player attacker;
    Player victim;
    short attacker_index = get<2>(state);

    if (attacker_index == 0)
    {
        attacker = get<0>(state);
        victim = get<1>(state);
    }
    else
    {
        attacker = get<1>(state);
        victim = get<0>(state);
    }

    // in distribution, attacker is the one who gets changed.
    // call _distribution_pair, do some operation and return

    return distribution_list;
}

static vector<tuple<short, short>> distribution_pairs(tuple<short, short> fingers)
{
    vector<tuple<short, short>> distribution_pairs_list;
    //some code here
    auto sum = static_cast<short>(get<0>(fingers)+get<1>(fingers));
    for (short i = 0; i < MAX_FINGER; i++)
    {
        tuple<short, short> sol_i;
        get<0>(sol_i) = min(i, sum-get);

    }
    return distribution_pairs_list;
}
