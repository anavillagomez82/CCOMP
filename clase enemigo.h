#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;

class Enemy {
public:
    Enemy(Vector2f position) {
        enemyShape.setRadius(15.0f);
        enemyShape.setPointCount(360);
        enemyShape.setFillColor(Color::Red);
        enemyShape.setOrigin(enemyShape.getRadius() / 2, enemyShape.getRadius() / 2);
        enemyShape.setPosition(position);
    }

    void chase(Player& player, float deltaTime) {
        Vector2f playerPos = player.getShape().getPosition();
        Vector2f enemyPos = enemyShape.getPosition();
        Vector2f direction = playerPos - enemyPos;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= length;  // Normalize direction
        enemyShape.move(direction * speed * deltaTime);
    }

    void draw(RenderWindow& window) {
        window.draw(enemyShape);
    }

private:
    CircleShape enemyShape;
    float speed = 50.0f;
};
