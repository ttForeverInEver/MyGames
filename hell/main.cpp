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
    int main()
    {
        srand(time(NULL));
        int d = 4;
        int b = 4;
        Clock timer;
        Player sudo("rsudo.png", 250, 250, 70.0, 97.0);
        RenderWindow window(sf::VideoMode(1980, 1080), "SFML works!");
        Player p("hh.png", 250, 250, 60.0, 80.0);
        p.sprite.setPosition(100, 100);
        Texture dop;
        dop.loadFromFile("image/hh.png");
        Texture dop1;
        dop1.loadFromFile("image/hh1.png");
        window.setFramerateLimit(240);
        Enemy boss1(2, "boss1.png");
        Image ibull;
        Texture tbull;
        Sprite bull;
        tbull.loadFromFile("image/bullet.png");
        bull.setTexture(tbull);
        boss1.sprite.setPosition(500, 500);
        Image ibullet;
        Texture tbullet;
        Sprite bullet;
        tbullet.loadFromFile("image/ebullet.png");
        bullet.setTexture(tbullet);
        Image ishapka;
        Texture tshapka;
        Sprite shapka;
        tshapka.loadFromFile("image/shapka.png");
        shapka.setTexture(tshapka);
        Texture tlsudo;
        Texture trsudo;
        tlsudo.loadFromFile("image/lsudo.png");
        trsudo.loadFromFile("image/rsudo.png");
        Texture twlsudo;
        Texture twrsudo;
        twlsudo.loadFromFile("image/lwsudo.png");
        twrsudo.loadFromFile("image/rwsudo.png");
        Texture tGameOver;
        Sprite gameOver;
        tGameOver.loadFromFile("image/gameOver.png");
        gameOver.setTexture(tGameOver);
        bool shot = false;
        bool side = true;
        bool eb = false;
        double hp = 10;
        int enemyBulletx = 0;
        int enemyBullety = 0;
        bullet.setPosition(800, 500);
        int person = 1;
        bool lyeShapka = false;
        bool go = false;
        while (window.isOpen()) {                      
            Event event;
            while (window.pollEvent(event)) 
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    window.clear();
                    window.display();
                }
            if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)) && go == false)) {
                p.sprite.move(-5, 0);
                p.sprite.setTexture(dop1);
                side = false;
            }
            if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)) && go == false)) {
                p.sprite.setTexture(dop);
                p.sprite.move(5, 0);
                side = true;
            }
            if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)) && go == false)) {
                p.sprite.move(0, 5);
            }
            if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)) && go == false)) {
                p.sprite.move(0, -5);
            }
            if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)) && go == false)) {
                sudo.sprite.move(-5, 0); 
                sudo.sprite.setTexture(tlsudo);
                if (lyeShapka == true) {
                    sudo.sprite.setTexture(twlsudo);
                }
            }
            if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)) && go == false)) {
                sudo.sprite.move(5, 0);              
                sudo.sprite.setTexture(trsudo);
                if (lyeShapka == true) {
                    sudo.sprite.setTexture(twrsudo);
                }
            }
            if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)) && go == false)) {
                sudo.sprite.move(0, 5);
                sudo.sprite.setTexture(trsudo);
                if (lyeShapka == true) {
                    sudo.sprite.setTexture(twlsudo);
                }
            }
            if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)) && go == false)) {
                sudo.sprite.move(0, -5);
                sudo.sprite.setTexture(trsudo);
                if (lyeShapka == true) {
                    sudo.sprite.setTexture(twlsudo);
                }
            }
            if ((Keyboard::isKeyPressed(Keyboard::Space)) && person == 1 && go == false) {
                shot = true;
                bull.setPosition(p.sprite.getPosition().x, p.sprite.getPosition().y);
            }
            if ((Keyboard::isKeyPressed(Keyboard::Space)) && person == 2 && go == false) {
                lyeShapka = true;
                shapka.setPosition(sudo.sprite.getPosition().x, sudo.sprite.getPosition().y);
            }
            if ((Keyboard::isKeyPressed(Keyboard::LShift)) && go == false) {
                person = 2;
                sudo.sprite.setPosition(p.sprite.getPosition().x, p.sprite.getPosition().y);
            }
            if (hp > 0 && go == false) {
                boss1.sprite.move(d, b);
            }
            if (bull.getPosition().x > 1900 || bull.getPosition().x < 0 && go == false) {
                shot = false;
                bull.setPosition(2000, 2000);
            }
            if (shot == true && go == false) {
                if (side == true) {
                    bull.move(15, 0);
                }
                else {
                    bull.move(-15, 0);
                }
            }
            if (boss1.sprite.getPosition().x > 1800 && go == false) {
                d = randomInt(-5, 0);
                eb = true;
                enemyBulletx = -7;
                bullet.setPosition(boss1.sprite.getPosition().x, boss1.sprite.getPosition().y);
            }
            if (boss1.sprite.getPosition().x < 0 && go == false) {
                d = randomInt(0, 5);
                eb = true;
                enemyBulletx = 7;
                bullet.setPosition(boss1.sprite.getPosition().x + 100, boss1.sprite.getPosition().y + 100);
            }
            if (boss1.sprite.getPosition().y > 800 && go == false) {
                b = randomInt(-5, 0);
                eb = true;
                enemyBullety = -7;
                bullet.setPosition(boss1.sprite.getPosition().x  , boss1.sprite.getPosition().y);
            }
            if (boss1.sprite.getPosition().y < 0 && go == false) {
                b = randomInt(0, 5);
                eb = true;
                enemyBullety = 7;
                bullet.setPosition(boss1.sprite.getPosition().x + 100, boss1.sprite.getPosition(). y + 100);
            }
            if (go == true) {
                if (Keyboard::isKeyPressed(Keyboard::O)) {
                    boss1.sprite.setPosition(1000, 500);
                    hp = 10;
                    go = false;
                    person = 1;
                    p.sprite.setPosition(0, 0);
                    
                } 
            }
            if (p.sprite.getPosition().x >= 1900 && go == false) {
                p.sprite.move(-5, 0);
            }
            if (p.sprite.getPosition().x <= 0 && go == false) {
                p.sprite.move(5, 0); 
            }
            if (p.sprite.getPosition().y >= 1000 && go == false) {
                p.sprite.move(0, -5);
            }
            if (p.sprite.getPosition().y <= 0 && go == false) {
                p.sprite.move(0, 5);
            }
            if (sudo.sprite.getPosition().x >= 1900 && go == false) {
                sudo.sprite.move(-5, 0);
            }
            if (sudo.sprite.getPosition().x <= 0 && go == false) {
                sudo.sprite.move(5, 0);
            }
            if (sudo.sprite.getPosition().y >= 1000 && go == false) {
                sudo.sprite.move(0, -5);
            }
            if (sudo.sprite.getPosition().y <= 0 && go == false) {
                sudo.sprite.move(0, 5);
            }
            if (bullet.getPosition().x >= 1900 && go == false) {
                eb = false;
                enemyBullety = 0;
                enemyBulletx = 0;
            }
            if (bullet.getPosition().x <= 0 && go == false) {
                eb = false;
                enemyBullety = 0;
                enemyBulletx = 0;
            }
            if (bullet.getPosition().y >= 1000 && go == false) {
                eb = false;
                enemyBullety = 0;
                enemyBulletx = 0;
            }
            if (bullet.getPosition().y <= 0 && go == false) {
                eb = false;
                enemyBullety = 0;
                enemyBulletx = 0;
            }
            if (eb == false) {
                enemyBullety = 0;
                enemyBulletx = 0;
            }
            if (bull.getGlobalBounds().intersects(boss1.sprite.getGlobalBounds()) && go == false) {
                hp--;
                shot = false;
                bull.setPosition(2000, 2000);
            }
            if (sudo.sprite.getGlobalBounds().intersects(boss1.sprite.getGlobalBounds()) && hp > 0 && go == false) {
                go = true;
            }
            if (sudo.sprite.getGlobalBounds().intersects(bullet.getGlobalBounds()) && hp > 0 && go == false) {
                go = true;
            }
            if (shapka.getGlobalBounds().intersects(boss1.sprite.getGlobalBounds()) && person == 2 && hp > 0 && lyeShapka == true && go == false) {
                lyeShapka = false;
                hp -= 5;               
                bull.setPosition(2000, 2000);
            }
            if (bullet.getGlobalBounds().intersects(p.sprite.getGlobalBounds()) && person == 1 && go == false) {
                go = true;
            }
            if (boss1.sprite.getGlobalBounds().intersects(p.sprite.getGlobalBounds()) && person == 1 && go == false) {
                go = true;
            }
            if (eb = true && go == false) {
                bullet.move(enemyBulletx, enemyBullety);
            }
                
            
            window.clear();
            if (person == 1 && go == false) {
                window.draw(p.sprite);
            }
            if (person == 2 && go == false) {
                window.draw(sudo.sprite);
            }
            if (shot == true && go == false) {
                window.draw(bull);
            }         
            if(hp > 0 && go == false){
                window.draw(boss1.sprite);
            }         
            if (eb == true && hp > 0 && go == false) {
                window.draw(bullet);
           }
            if (lyeShapka == true && go == false) {
                window.draw(shapka);
            }
            if (go == true) {
                window.draw(gameOver);
            }
            window.display();
        }
    }
