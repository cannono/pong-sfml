//sfml test
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace std;
using namespace sf;

struct Fruit
{
  int xpos;
  int ypos;
};

struct Snakes
{
  int xpos;
  int ypos;
  int dir;
}; test


int main()
{
    int dir;
    test.xpos = 0;
    test.ypos = 0;
    RenderWindow window(sf::VideoMode(600, 600), "Snake!");


    Texture t1, t2, t3;
    t1.loadFromFile("textures/background.png");
    t2.loadFromFile("textures/snake.png");
    t3.loadFromFile("textures/apple.png");

    Sprite back(t1);
    Sprite snek(t2);
    Sprite apple(t3);

    Fruit fruit;
    fruit.xpos = ((rand() % 30 ) + 1) * 20;
    fruit.ypos = ((rand() % 30) + 1) * 20;
    cout << "Xpos: " << fruit.xpos << " yPos: " << fruit.ypos << endl;
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if(Keyboard::isKeyPressed(Keyboard::Up))  //dir = 0;
            if(Keyboard::isKeyPressed(Keyboard::W)) //dir = 0;

            if(Keyboard::isKeyPressed(Keyboard::Right)) //dir = 1;
            if(Keyboard::isKeyPressed(Keyboard::D)) //dir = 1;

            if(Keyboard::isKeyPressed(Keyboard::Left)) //dir = 2;
            if(Keyboard::isKeyPressed(Keyboard::A)) //dir = 2;

            if(Keyboard::isKeyPressed(Keyboard::Down)) //dir = 3;
            if(Keyboard::isKeyPressed(Keyboard::S)) //dir = 3;

        }
        if(snek.Intersects(apple))
        {
          fruit.xpos((rand() % 30) + 1) * 20;
          fruit.ypos((rand() % 30) + 1) * 20;
        }



        window.clear();
        back.setPosition(0,0);  window.draw(back);
        apple.setPosition(fruit.xpos, fruit.ypos); window.draw(apple);
        snek.draw(snakes.xpos, snakes.ypos)
        window.display();
    }

    return 0;
}
