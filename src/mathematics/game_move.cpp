//
// Created by utnam on 12/20/2025.
//

#include <iostream>

#include "../../include/utils/state_repr.hpp"
#include <vector>
#include <array>
using namespace std;
int main()
{
    vector<State_str> all_moves;
    vector<State_tuple> all_moves_tuple;
    for (short l = 0; l<5; l++)
    {
        for (short r = l; r<5; r++)
        {
            for (short l2 = 0; l2<5; l2++)
            {
                for (short r2 = l2; r2<5; r2++)
                {
                    // State_str state1 = static_cast<char>('0'+l)+static_cast<char>('0'+r)+static_cast<char>('0'+l2)+static_cast<char>('0'+r2)+'0'+'\0';
                    // State_str state2 = static_cast<char>('0'+l)+static_cast<char>('0'+r)+static_cast<char>('0'+l2)+static_cast<char>('0'+r2)+'1'+'\0';
                    State_str state1;
                    state1[0] = static_cast<char>('0'+l);
                    state1[1] = static_cast<char>('0'+r);
                    state1[2] = static_cast<char>('0'+l2);
                    state1[3] = static_cast<char>('0'+r2);
                    state1[4] = '0';
                    state1[5] = '\0';

                    State_str state2;
                    state2[0] = static_cast<char>('0'+l);
                    state2[1] = static_cast<char>('0'+r);
                    state2[2] = static_cast<char>('0'+l2);
                    state2[3] = static_cast<char>('0'+r2);
                    state2[4] = '1';
                    state2[5] = '\0';

                    // cout << state1 <<endl;
                    // cout << state2 <<endl;

                    all_moves.push_back(state1);
                    all_moves.push_back(state2);
                    // all_moves_tuple.push_back(str_to_tuple(state1));
                    // all_moves_tuple.push_back(str_to_tuple(state2));
                }
            }
        }
    }
    // cout << static_cast<string>(all_moves) << endl;
    for (auto & all_move : all_moves)
    {
        cout << all_move.data() << endl;
        // cout << get<0>(get<0>(all_moves_tuple[i])) << get<1>(get<0>(all_moves_tuple[i])) << get<0>(get<1>(all_moves_tuple[i])) << get<1>(get<1>(all_moves_tuple[i])) << get<2>(all_moves_tuple[i]) << endl;
    }
    return 0;
}