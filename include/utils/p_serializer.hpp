//
// Created by utnam on 12/24/2025.
//

#ifndef CS_CPP_P_SERIALIZER_HPP
#define CS_CPP_P_SERIALIZER_HPP


#include "../map-.hpp"
#include <string>

// Saves the map to a binary file
void save_p_map(const PMap& map_1, const std::string& filename);

// Loads the map from a binary file
PMap load_p_map(const std::string& filename);
#endif //CS_CPP_P_SERIALIZER_HPP