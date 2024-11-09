#include "../include/Game.hpp"

int main()
{
    try
    {
        Game    game;

        while (game.getWindow().isOpen())
        {
            game.updateWindow();
            game.renderWindow();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0); 
}
