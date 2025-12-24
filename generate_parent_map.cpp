//
// Created by utnam on 12/24/2025.
//

#include <iostream>
#include "include/map-.hpp"
#include "include/utils/p_serializer.hpp"

int main()
{
    // string fname = "map_parent_0";
    // gen_p_map(fname);
    PMap map_p = load_p_map("map_parent_0");
    print_p_map(map_p);
}