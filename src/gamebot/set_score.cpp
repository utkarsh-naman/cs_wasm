//
// Created by utnam on 12/26/2025.
//

#include "../../include/utils/state_repr.hpp"
#include "../../include/utils/serializer.hpp"
#include "../../include/utils/p_serializer.hpp"
#include <algorithm>

vector<State_str> u_wins_vec(const Map& map_0)
{
    vector<State_str> u_wins_vector;
    for (auto [key, value] : map_0)
    {
        if (get<1>(get<0>(str_to_tuple(key))) == 0) u_wins_vector.push_back(key);
    }

    return u_wins_vector;
}

vector<State_str> r_wins_vec(const Map& map_0)
{
    vector<State_str> r_wins_vector;
    for (auto [key, value] : map_0)
    {
        if (get<1>(get<1>(str_to_tuple(key))) == 0) r_wins_vector.push_back(key);
    }

    return r_wins_vector;
}

Map map_f = load_map("map_0");
PMap map_p_f = load_p_map("map_parent_0");
vector<State_str> u_wins_vector  = u_wins_vec(map_f);
vector<State_str> r_lose_vector;
vector<State_str> worked_history;

void u_wins(short depth);
void r_loses(short depth);

void u_wins(short depth)
{
    if (u_wins_vector.empty()) return;
    r_lose_vector.clear(); //empty the r_lose_vector to make it contain r_lose state of single level.
    for (State_str uw_key: u_wins_vector)
    {
        // cases where u defeats r : next chance is of r, i.e. 0
        if (uw_key[4] == '0')
        {
            map_f[uw_key].score = Infinity;
            map_f[uw_key].windepth = static_cast<float>(depth);
            for (State_str parent_uw_key: map_p_f[uw_key].previous_states)
            {
                // parent not in worked history
                auto it = find(worked_history.begin(), worked_history.end(), parent_uw_key);
                if (it == worked_history.end())
                {
                    map_f[parent_uw_key].score = NegInfinity;
                    map_f[parent_uw_key].losedepth = static_cast<float>(depth+1);
                    r_lose_vector.push_back(parent_uw_key);
                    worked_history.push_back(uw_key);
                }
            }
        }

        // cases where r loses due to suicide: : next chance is of r, i.e. 0
        else
        {
            map_f[uw_key].score = NegInfinity;
            map_f[uw_key].losedepth = static_cast<float>(depth);
            r_lose_vector.push_back(uw_key);
        }




    }
    r_loses(depth+1);
    return;
}

void r_loses(short depth)
{
    if (r_lose_vector.empty()) return;
    u_wins_vector.clear();

    for (State_str rl_key: r_lose_vector)
    {
        for (State_str parent_rl_key: map_p_f[rl_key].previous_states)
        {
            auto it = find(worked_history.begin(), worked_history.end(), parent_rl_key);
            if (it == worked_history.end())
            {
                vector<State_str> children = map_f[parent_rl_key].next_states;
                bool isall_ninf = all_of(
                    children.begin(), children.end(),
                    [](const State_str& x) {
                        return map_f[x].score == NegInfinity;
                    }
                );
                if (isall_ninf) u_wins_vector.push_back(parent_rl_key);
            }
        }
    }

    u_wins(depth);
    return;
}




int main()
{
    u_wins(0);
    return 0;
}