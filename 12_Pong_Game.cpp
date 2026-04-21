#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Pong Game");

    RectangleShape paddle1(Vector2f(10, 100));
    paddle1.setPosition(50, 250);

    RectangleShape paddle2(Vector2f(dz10, 100));
    paddle2.setPosition(740, 250);

    CircleShape ball(10);
    ball.setPosition(400, 300);

    float ballSpeedX = 0.3f;
    float ballSpeedY = 0.3f;
 
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Controls
        if (Keyboard::isKeyPressed(Keyboard::W))    
            paddle1.move(0, -0.5f);
        if (Keyboard::isKeyPressed(Keyboard::S))
            paddle1.move(0, 0.5f);

        if (Keyboard::isKeyPressed(Keyboard::Up))
            paddle2.move(0, -0.5f);
        if (Keyboard::isKeyPressed(Keyboard::Down))
            paddle2.move(0, 0.5f);

        // Ball movement
        ball.move(ballSpeedX, ballSpeedY);

        // Collision top/bottom
        if (ball.getPosition().y <= 0 || ball.getPosition().y >= 580)
            ballSpeedY *= -1;

        // Paddle collision
        if (ball.getGlobalBounds().intersects(paddle1.getGlobalBounds()) ||
            ball.getGlobalBounds().intersects(paddle2.getGlobalBounds()))
            ballSpeedX *= -1;

        window.clear();00
        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(ball);
        window.display();
    }

    return 0;
}