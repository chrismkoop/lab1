#include <SFML/Graphics.hpp>
#include "rand.h"
#include "Config.h"

void render(sf::RenderWindow & window, const std::vector<sf::CircleShape> & shapes) {
  // always clear!
  window.clear();

  // drawing happens here (off-screen)
  for (const auto & shape : shapes) {
    window.draw(shape);
  }

  // swap the display buffer (double-buffering)
  window.display();
}

void processEvents(sf::RenderWindow & window, std::vector<sf::CircleShape> & shapes) {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void update(sf::Time dt, std::vector<sf::CircleShape> & shapes) {
  float s = dt.asSeconds();
  Config* config = Config::getInstance();
  for (auto & shape : shapes) {
    shape.move(20.0f * s, 20.0f * s);
    if (shape.getPosition().x > config->getWindowWidth())
    {
      shape.setPosition(0, shape.getPosition().y);
    }
    else if ( shape.getPosition().x < 0)
    {
      shape.setPosition(config->getWindowWidth(), shape.getPosition().y);
    }


    if (shape.getPosition().y > config->getWindowHeight())
    {
      shape.setPosition(shape.getPosition().x, 0);
    }
    else if (shape.getPosition().y < 0)
    {
      shape.setPosition(shape.getPosition().x, config->getWindowHeight());
    }
  }
}

int main(int argc, char *argv[]) {
  // get config values
  Config* config = Config::getInstance(argc, argv);

  sf::RenderWindow window{sf::VideoMode{config->getWindowWidth(), config->getWindowHeight()}, "Lab1"};

  std::vector<sf::CircleShape> shapes{};

  for (int i{}; i < config->getCircleNum(); ++i) {
    sf::CircleShape shape{config->getCircleSize(), 100};
    shape.setFillColor(sf::Color::Blue);
    shape.setOutlineColor(sf::Color::White);
    shape.setPosition(rand(22.0f, config->getWindowWidth() - 22.0f), rand(22.0f, config->getWindowHeight() - 22.0f));
    shapes.push_back(shape);
  }

  // for info on game loops:
  //   https://subscription.packtpub.com/book/game+development/9781849696845/1/ch01lvl1sec11/game-loops-and-frames
  sf::Clock clock;

  sf::Time t{sf::Time::Zero}; // time
  sf::Time dt{sf::seconds(1.0f / 60.0f)}; // delta time (fixed to 60fps)

  while (window.isOpen()) {
    processEvents(window, shapes);
    t += clock.restart();

    while (t > dt) {
      t -= dt;
      processEvents(window, shapes);
      update(dt, shapes);
    }

    render(window, shapes);
  }
}
