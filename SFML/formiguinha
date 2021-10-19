#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

void setSize(sf::Sprite& sprite, int width, int height) {
    auto dim = sprite.getLocalBounds();
    sprite.setScale((float) width / dim.width, (float) height / dim.height);
}



struct Entity {
    int x {0}; //atributos
    int y {0};
    int step {0};
    sf::Sprite sprite;

    Entity(int x, int y, int step, sf::Texture& texture):
        x {x}, y {y}, step {step}, sprite(texture) {
    }

    void draw(sf::RenderWindow& window) { //métodos
        this->sprite.setPosition(x * step, y * step);
        setSize(this->sprite, step, step);
        window.draw(this->sprite);
    }
};

struct Board {
    int nc {0};
    int nl {0};
    int step {0};//atributos
    sf::Sprite sprite;
    sf::RectangleShape rect;
    //parametros
    Board(int nc, int nl, int step, sf::Texture& texture) {
        this->nc = nc;
        this->nl = nl;
        this->step = step;
        this->sprite.setTexture(texture);
        setSize(this->sprite, nc * step, nl * step);
        this->sprite.setPosition(0, -35);

        this->rect.setSize(sf::Vector2f(step, step));
        this->rect.setFillColor(sf::Color::Transparent);
        this->rect.setOutlineColor(sf::Color::Black);
        this->rect.setOutlineThickness(2);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(this->sprite);
        for (int i = 0; i < nc; i++) {
            for (int j = 0; j < nl; j++) {
                rect.setPosition(i * step, j * step);
                window.draw(rect);
            }
        }
    }
};

void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys) {
    if (key == move_keys[0])
        entity.x--;
    else if (key == move_keys[1])
        entity.y--;
    else if (key == move_keys[2])
        entity.x++;
    else if (key == move_keys[3])
        entity.y++;
}

sf::Texture loadTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        exit(1);
    }
    return texture;
}

int main() {

    sf::Texture player_text { loadTexture("ant.jpg") };
    sf::Texture leaf_text { loadTexture("folha.png") };
    sf::Texture field_text { loadTexture("table.png") };

    const int STEP {100};

    Entity player(1, 1, STEP, player_text);
    Entity leaf(4, 0, STEP, leaf_text);
    Entity leaf2(5, 1, STEP, leaf_text);
    Entity leaf3(1, 0, STEP, leaf_text);
    Entity leaf4(1, 3, STEP, leaf_text);
    Board board(7, 5, STEP, field_text);

    sf::RenderWindow window(sf::VideoMode(board.nc * STEP, board.nl * STEP), "SFML works!");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                moveEntity(event.key.code, player, {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
                //moveEntity(event.key.code, leaf, {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S});
            }

            if (player.y == leaf.y && leaf.x == player.x) {
              leaf.x = -player.x;
            }
            if (player.y == leaf2.y && leaf2.x == player.x) {
              leaf2.x = -player.x;
            }
            if (player.y == leaf3.y && leaf3.x == player.x) {
              leaf3.x = -player.x;
            }
            if (player.y == leaf4.y && leaf4.x == player.x) {
              leaf4.x = -player.x;
            }
            

        }

  
        window.clear();
        board.draw(window);
        player.draw(window);
        leaf.draw(window);
        leaf2.draw(window);
        leaf3.draw(window);
        leaf4.draw(window);

        window.display(); // display() must be called after all draw() calls
    }

    return 0;
}
