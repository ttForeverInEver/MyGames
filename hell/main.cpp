#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream> 
#include <string>
using namespace sf;
using namespace std;
int randomInt(int start, int end) {
    int n = rand() % (end - start + 1) + start;
    return n;
}
class Enemy {
public:
    string file;
    float speed;
    Image image;
    Texture texture;
    Sprite sprite;
    Enemy(float s, string F) {
        speed = s;
        file = F;
        image.loadFromFile("image/" + file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    }
    void M(float speed) {
        sprite.setPosition(500, 500);
        sprite.move(speed, 0);
        if (sprite.getPosition().x > 1979 || sprite.getPosition().x < 0) {
            speed = -speed;
        }
    }
};
class Player
{
public:
    float x, y, w, h, dx, dy, speed = 0;
    int dir;
    String file;
    Image image;
    Texture texture;
    Sprite sprite;
    Player(String F, float X, float Y, float W, float H) {
        dx = 0; dy = 0; speed = 0; dir = 0;
        file = F;
        w = W; h = H;
        image.loadFromFile("image/" + file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }
    };
class Bullet {
public:
    bool draw;
    float speed;
    string file;
    Texture texture;
    Sprite sprite;
    Bullet(bool d, string F){
        F = file;       
        texture.loadFromFile("image/" + file);
        sprite.setTexture(texture);
    }
    
    void shot(){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sprite.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
        }
    }
};
    int main()
    {
        srand(time(NULL));
        int d = 4;
        int b = 4;
        RenderWindow window(sf::VideoMode(1980, 1080), "SFML works!");
        Player p("hh.png", 250, 250, 60.0, 80.0);
        p.sprite.setPosition(100, 100);
        Texture dop;
        dop.loadFromFile("image/hh.png");
        Texture dop1;
        dop1.loadFromFile("image/hh1.png");
        window.setFramerateLimit(180);
        Enemy boss1(2, "boss1.png");        
        boss1.sprite.setPosition(500, 500);
        while (window.isOpen()) {                      
            Event event;
            while (window.pollEvent(event)) 
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    window.clear();
                    window.display();
                }
            if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
                p.sprite.move(-5, 0);
                p.sprite.setTexture(dop1);
            }
            if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
                p.sprite.setTexture(dop);
                p.sprite.move(5, 0);
            }
            if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
                p.sprite.move(0, 5);
            }
            if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
                p.sprite.move(0, -5);
            }
            boss1.sprite.move(d, b);
            if (boss1.sprite.getPosition().x > 1900 || boss1.sprite.getPosition().x < 0 || boss1.sprite.getPosition().y < 100 || boss1.sprite.getPosition().x > 1080) {
                d = randomInt(-5, 5);
                b = randomInt(-5, 5);
            }
            window.clear();
            window.draw(p.sprite);
            window.draw(boss1.sprite);
            window.display();
        }
    }
