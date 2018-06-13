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
  int direction;
};

void update(vector<Snakes> &snakes, Clock &clock)
{
  // Delay timer
  while(clock.getElapsedTime().asMilliseconds() < 100 )
  {}

  clock.restart();
  // Moves the "head" of the snake in the direction of the key pressed or continues
  // in the same direction

  if(snakes[0].direction == 0) snakes[0].ypos += -20;

  else if(snakes[0].direction == 1) snakes[0].xpos += 20;

  else if(snakes[0].direction == 2) snakes[0].ypos += 20;

  else if(snakes[0].direction == 3) snakes[0].xpos += -20;



  // Moves all of the other pieces in the direction of the piece of snake in front of them.
  for(int i = snakes.size()-1; i >= 1; --i)
  {
    cout << "snake direction before: " << snakes[i].direction << endl;
    if(snakes[i].direction == 0)
    {
      snakes[i].ypos += -20;
      snakes[i].direction = snakes[i-1].direction;
    }

    else if(snakes[i].direction == 1)
    {
      snakes[i].xpos += 20;
      snakes[i].direction = snakes[i-1].direction;
    }

    else if(snakes[i].direction == 2)
    {
      snakes[i].ypos += 20;
      snakes[i].direction = snakes[i-1].direction;
    }

    else if(snakes[i].direction == 3)
    {
      snakes[i].xpos += -20;
      snakes[i].direction = snakes[i-1].direction;
    }
    cout << "snake direction after: " << snakes[i].direction << endl;
  }
}

bool lose(Snakes head)
{
  //cout << "xpos: " << head.xpos << " ypos: " << head.ypos <<  endl;
  if(head.xpos >= 600 || head.xpos < 0) return true;

  if(head.ypos >= 600 || head.ypos < 0) return true;

  return false;
}

void add_snake(vector<Snakes> &snakes)
{


}
int main()
{
    int dir = 1;
    vector<Snakes> snakes;
    /*
    cout << "Press any arrow key to start the game"<< endl;
    bool start = false;
    while(start == false)
    {
      if(Keyboard::isKeyPressed(Keyboard::Up)){dir = 0; start = true;}
      if(Keyboard::isKeyPressed(Keyboard::W)) { dir = 0; start = true;}

      if(Keyboard::isKeyPressed(Keyboard::Right)) {dir = 1; start = true;}
      if(Keyboard::isKeyPressed(Keyboard::D)) {dir = 1; start = true;}

      if(Keyboard::isKeyPressed(Keyboard::Left)) {dir = 3; start = true;}
      if(Keyboard::isKeyPressed(Keyboard::A)) {dir = 3; start = true;}

      if(Keyboard::isKeyPressed(Keyboard::Down)) {dir = 2; start = true;}
      if(Keyboard::isKeyPressed(Keyboard::S)) {dir = 2; start = true;}

    }
    */
    Snakes first = {100, 100, dir};
    snakes.push_back(first);
    cout << "Snake starting size: " << snakes.size() << endl;
    RenderWindow window(sf::VideoMode(600, 600), "Snake!");
    Clock clock;



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
    //cout << "Xpos: " << fruit.xpos << " yPos: " << fruit.ypos << endl;
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


        if(Keyboard::isKeyPressed(Keyboard::Up)) dir = 0;
        if(Keyboard::isKeyPressed(Keyboard::W)) dir = 0;

        if(Keyboard::isKeyPressed(Keyboard::Right)) dir = 1;
        if(Keyboard::isKeyPressed(Keyboard::D)) dir = 1;

        if(Keyboard::isKeyPressed(Keyboard::Left)) dir = 3;
        if(Keyboard::isKeyPressed(Keyboard::A)) dir = 3;

        if(Keyboard::isKeyPressed(Keyboard::Down)) dir = 2;
        if(Keyboard::isKeyPressed(Keyboard::S)) dir = 2;

        snakes[0].direction = dir;

        //cout << "Value of direction: " << snakes[0].direction << endl;



        //update(snakes, clock);
        /*
        if(lose(snakes[0]))
        {
          cout << "close window" << endl;
           window.close();
        }
        */
        window.clear();
        back.setPosition(0,0);  window.draw(back);
        apple.setPosition(fruit.xpos, fruit.ypos); window.draw(apple);


        for(int i = 0; i < snakes.size(); ++i)
        {
          snek.setPosition(snakes[i].xpos, snakes[i].ypos);
          window.draw(snek);
          cout << "count: " << i << endl;
          cout << "position: " << snakes[i].xpos << " " << snakes[i].ypos << endl;
          cout << "direction: " << snakes[i].direction << endl;
        }

        if(snek.getGlobalBounds().intersects(apple.getGlobalBounds()))
        {
          fruit.xpos = ((rand() % 30) + 1) * 20;
          fruit.ypos = ((rand() % 30) + 1) * 20;
          Snakes temp = snakes[snakes.size() -1];
          update(snakes, clock);
          snakes.push_back(temp);
        }
        else
        {
          update(snakes, clock);
        }

        window.display();
    }

    return 0;
}
