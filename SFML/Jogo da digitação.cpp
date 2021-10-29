#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "SFML-2.5.1/include/SFML/Window.hpp"
#include "SFML-2.5.1/include/SFML/Audio.hpp"
#include <iostream>
#include <vector>
#include <functional>

struct Pincel{
  sf::Font font;
  sf::Text text;
  sf::RenderWindow& window;

  Pincel (sf::RenderWindow& window) : window(window) {
    if(!font.loadFromFile("Roboto-Black.ttf"))
      std::cout << "erro na fonte\n";
    text.setFont(font);
  }

  void write(std::string str, int x,int y, int size, sf::Color color) {
    text.setString(str);
    text.setCharacterSize(size);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
  }

};

struct Bubble{
    static const int radius{ 10 };
    int x;
    int y;
    char letter;
    int speed;
    bool alive{true};

    Bubble(int x,int y, char letter, int speed) : x{x}, y{y}, letter{letter}, speed{speed} {
    }

    void update() {
      this->y += this->speed;
    }

    void draw(sf::RenderWindow& window) {
      const sf::Color color(rand() %255, rand() % 255, rand() % 255 );
      sf::CircleShape circle(Bubble::radius*2);
      circle.setPosition(x, y);
      circle.setFillColor(color);
      window.draw(circle);
      static Pincel pincel(window);

      pincel.write(std::string(1,letter),x+0.8 * Bubble::radius,y-2 ,Bubble::radius * 3.0,sf::Color::Black);
    }
};

struct board {
  sf::RenderWindow& window;
  std::vector<Bubble> bolhas;
  Pincel pencil;
  sf::Texture texture;

  int hits{0};
  int misses{0};

  board(sf::RenderWindow& window) : window(window), pencil(window) {
    //bolhas.push_back(Bubble(100,100,'a',1));
    //bolhas.push_back(Bubble(200,100,'a',2));
  }

 

  void update() {
    if (this->check_new_bubble())
      this->add_new_bubble();

    for (auto& bubble : bolhas) {
      bubble.update();
    }
    this->mark_outside_bubbles();
    this->remove_dead_bubbles();
  }

  void mark_outside_bubbles() {
    for (Bubble& bubble : bolhas) {
      if (bubble.y+2 * Bubble::radius > (int)this->window.getSize().y){
        if (bubble.alive) {
          bubble.alive = false;
          this->misses++;
        }
      }
    }
  }

  void mark_by_hit(char letter) {
    for (Bubble& bubble : bolhas) {
      if (bubble.letter == letter){
        bubble.alive = false;
        this->hits++;
        break;
      }
    }
  }

  void remove_dead_bubbles() {
    std::vector<Bubble> vivas;
      for (Bubble& bubble : bolhas) {
        if (bubble.alive) {
          vivas.push_back(bubble);
        }
      }
      this->bolhas = vivas;
  }

  bool check_new_bubble() {
    static const int new_bubble_timeout{ 30 };
    static int new_bubble_timer{0};

    new_bubble_timer--;
    if (new_bubble_timer < 0) {
      new_bubble_timer = new_bubble_timeout;
      return true;
    }
    return false;
  }


  void add_new_bubble() {
    int x = rand() % ((int) this->window.getSize().x - 4 * Bubble::radius);
    int y = -2*Bubble::radius;
    int speed = rand() % 3+1;
    char letter = rand() % 26+'A';
    bolhas.push_back(Bubble(x,y,letter,speed));
  }

  void draw() {
    pencil.write("hits: "+ std::to_string(this->hits) +  "\nmisses: " + std::to_string(this->misses),10 , 10, 20, sf::Color::Red);

    for (auto& bubble : bolhas) {
     bubble.draw(window);
    }
  }

  void restart() {
    for (auto& bubble : bolhas) {
      bubble.y = -100;
      bolhas.erase(bolhas.begin(), bolhas.end());
    }
  }

};



struct Game {
  sf::RenderWindow window;
  board board;
  std::function<void()> on_update;


  Game():window(sf::VideoMode(800,600),"Bubble"), board(window) {
    this->on_update=[&](){
      this->gameplay();
    };
    window.setFramerateLimit(60);
  }

  

  void process_events() {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed ) {
        window.close();
      } else if(event.type == sf::Event::TextEntered) {
          char code = static_cast<char>(event.text.unicode);
          code = toupper(code);
          board.mark_by_hit(code);
        }
      }
  }

  void gameplay() {

    sf::Keyboard::Key key;
    board.update();
    window.clear();
    board.draw();
    window.display();
    if(board.misses == 10) {
      this->on_update = [&]() {
        this->gameover();
      };
    }
    if (board.hits == 20) {
      this->on_update = [&] () {
        this->win();
      };
    }
  }

  void gameover() {
    static Pincel pencil(window);
    window.clear(sf::Color::White);
    pencil.write("Game Over",400,300,50,sf::Color::Red);
    pencil.write("Press PageUp to play again",380,400,25,sf::Color::Red);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)){
        board.restart();
        board.misses = 0;
        board.hits = 0;
        
        this->on_update = [&]() {
          this->gameplay();
        };
      }
    window.display();
  }

  void win() {
    static Pincel pencil(window);
    window.clear(sf::Color::White);
    pencil.write("Congratulations!!!",400,300,50,sf::Color::Red);
    pencil.write("Press PageUp to play again",380,400,25,sf::Color::Red);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)){
        board.restart();
        board.misses = 0;
        board.hits = 0;
        
        this->on_update = [&]() {
          this->gameplay();
        };
      }
    window.display();
  }

  void main_loop(){
    while (window.isOpen()) {
      process_events();
      on_update();
    }
  }
};

int main() {
  Game game;
  game.main_loop();

  return 0;
} 
