//
// Created by utnam on 12/25/2025.
//

#include <iostream>
#include "../include/utils/serializer.hpp"


void print_state(const State_str& s)
{
     cout << "[ ";
     cout << s.data() << " ";
     cout << "]:\n";
}



void print_map(const Map& map_0)
{
     for (const auto& [state, props] : map_0)
     {
          print_state(state);
          cout << "\t-> score: " << props.score << "\n";

          cout << "\tnext states:\n";
          for (const State_str& next : props.next_states)
          {
               cout << "\t";
               print_state(next);
               cout << "\n";
          }
          cout << "\n";
     }
}


int main()
{
     Map botmap = load_map("map_f_set");
     cout << botmap.size() << endl;
     print_map(botmap);
}