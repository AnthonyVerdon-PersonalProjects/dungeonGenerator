#include "classes/DungeonGenerator/DungeonGenerator.hpp"
#include "classes/SDL/SDL.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
int main(void)
{
    try
    {
        t_map mapGenerated = DungeonGenerator::generate(20, 20, "assets/dungeon/rules.json");
        std::cout << std::endl << "mapGenerated: " << std::endl << mapGenerated << std::endl;
        std::cout << "start render " << std::endl;
        SDL instance;

        instance.updateLoop(mapGenerated);

        return (EXIT_SUCCESS);
    }
    catch (const std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return (EXIT_FAILURE);
    }
}