#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "HealthBar.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 450), "Juego Básico");
    Clock dre;

    Player player(Vector2f(400.0f, 225.0f));
    Enemy enemy(Vector2f(100.0f, 100.0f));
    HealthBar healthBar(Vector2f(10.0f, 10.0f), Vector2f(200.0f, 20.0f));

    Vector2f mvel(0.0f, 0.0f);
    float vel = 100.0f;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
            mvel.x = -vel;
        else if (Keyboard::isKeyPressed(Keyboard::D))
            mvel.x = vel;
        else if (Keyboard::isKeyPressed(Keyboard::Space))
            mvel.y = -vel;
        else {
            mvel.x = 0;
            mvel.y = 0;
        }

        float tiempo = dre.restart().asSeconds();
        
        player.move(mvel, tiempo);
        enemy.chase(player, tiempo);

        window.clear();
        player.draw(window);
        enemy.draw(window);

        healthBar.update(player.getHealth());
        healthBar.draw(window);

        window.display();
    }
    return 0;
}
