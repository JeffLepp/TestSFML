#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(750, 500), "SFML works!");
    sf::CircleShape shape(250.f);
    shape.setFillColor(sf::Color::Cyan);

    // song file
    sf::SoundBuffer songFile;
    songFile.loadFromFile("assetts/song.wav");

    // background song
    sf::Sound song;
    song.setBuffer(songFile);
    song.setVolume(55);
    song.setLoop(true);
    song.play();
    //song.stop();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}