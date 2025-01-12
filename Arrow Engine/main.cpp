//THIS MAIN FILE, AND ANYTHING ELSE NOT IN THE "ARROW ENGINE" FILTER, IS FOR 
//DEMO PURPOSES ONLY.

#include <iostream>
#include <Arrow Engine/Buttons/Rect_Button.h>
#include <Arrow Engine/Drawable_calculations.h>
#include <Arrow Engine/Incrementors/Incrementor.h>
#include <SFML/Graphics.hpp>

#include "States.h"
#include "Project Config.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(AE::initial_win_size.x, AE::initial_win_size.y), "BogoSearch!");
    //window.setFramerateLimit(60);

    std::vector<sf::Font> main_fonts; //these fonts has to be accessed everywhere, as we dont need/want multiple duplicates of the same font as that would be wasteful
    sf::Font* fnt_buffer = new sf::Font;

    AE::drawable_calculations::load_n_check_fnt(*fnt_buffer, "Assets/Fonts/prstartk.ttf");
    main_fonts.push_back(*fnt_buffer);

    delete fnt_buffer;

    sf::View main_view(sf::FloatRect(0, 0, AE::initial_win_size.x / 1.15, AE::initial_win_size.y / 1.15));

    sf::RenderTexture main_RenderTexture;
    if (!main_RenderTexture.create(AE::initial_win_size.x / 1.15, AE::initial_win_size.y / 1.15)) // Set this to your desired resolution
        return -1;
    sf::View render_view(sf::FloatRect(0, 0, AE::initial_win_size.x / 1.15, AE::initial_win_size.y / 1.15));
    main_RenderTexture.setSmooth(false); // Disable smoothing for the render texture

    States st;
    window.setView(main_view);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                if (event.size.width < AE::initial_win_size.x)
                {
                    window.setSize(sf::Vector2u(AE::initial_win_size.x, window.getSize().y));
                }
                if (event.size.height < AE::initial_win_size.y)
                {
                    window.setSize(sf::Vector2u(window.getSize().x, AE::initial_win_size.y));
                }
                main_view = sf::View(sf::FloatRect(0, 0, event.size.width / 1.15, event.size.height / 1.15));
                render_view = sf::View(sf::FloatRect(0, 0, event.size.width / 1.15, event.size.height / 1.15));
                main_RenderTexture.create(event.size.width / 1.15, event.size.height / 1.15);

                window.setView(main_view);
            }
            //st.state_manager_event(renderTexture, window, main_view, event);
        }

        main_RenderTexture.clear(st.get_current_bg_colour());
        st.state_manager_rt(window, main_RenderTexture, main_view);
        main_RenderTexture.display(); //Display the render texture

        sf::Sprite renderSprite(main_RenderTexture.getTexture());

        window.clear();
        window.draw(renderSprite);
        window.display();
    }

    return 0;
}