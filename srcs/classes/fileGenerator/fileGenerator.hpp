#pragma once

#include "../../structs/t_map.hpp"
#include <string>

class fileGenerator
{
  public:
    static void generateFile(const t_map &map, const std::string &folderPath);
};