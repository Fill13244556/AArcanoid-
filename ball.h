#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "bat.h"

struct Ball {
	sf::CircleShape shape;
	float speedX, speedY;
}; 

void initBall(Ball& ball)
{
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	ball.speedX = arr_speed[index];
	index = rand() % 10;
	ball.speedY = arr_speed[index];
}

void moveBall(Ball& ball) {
	ball.shape.move(ball.speedX, ball.speedY);
	

	if (ball.shape.getPosition().x <= 0)
	{
		
		ball.speedX = -ball.speedX;
	}
	if (ball.shape.getPosition().x >=
		WINDOW_WIDTH - 2 * BALL_RADIUS)
	{
	
		ball.speedX = -ball.speedX;
	}

	if (ball.shape.getPosition().y <= 0 ||
		ball.shape.getPosition().y >=
		(WINDOW_HEIGHT - 2 * BALL_RADIUS)
		)
		ball.speedY = -ball.speedY;

}
void ballControl(Ball& ball, Bat& shape)
{
	if ((shape.shape.getPosition().x <= ball.shape.getPosition().x + BALL_RADIUS && ball.shape.getPosition().x + BALL_RADIUS <= shape.shape.getPosition().x + BAT_WIDTH) && (shape.shape.getPosition().y <= ball.shape.getPosition().y + BALL_RADIUS * 2 && ball.shape.getPosition().y + BALL_RADIUS * 2 <= shape.shape.getPosition().y + BAT_HEIGHT))
	{
		ball.speedY = -ball.speedY;
	}
	/*if ((shape.shape.getPosition().x <= ball.ball.getPosition().x && ball.ball.getPosition().x <= shape.shape.getPosition().x + BAT_WIDTH) && (shape.shape.getPosition().y <= ball.ball.getPosition().y + BALL_RADIUS && ball.ball.getPosition().y + BALL_RADIUS <= shape.shape.getPosition().y + BAT_HEIGHT))
	{
	 ball.ballspeedX = -ball.ballspeedX;
	}

	if ((shape.shape.getPosition().x <= ball.ball.getPosition().x + BALL_RADIUS * 2 && ball.ball.getPosition().x + BALL_RADIUS * 2 <= shape.shape.getPosition().x + BAT_WIDTH) && (shape.shape.getPosition().y <= ball.ball.getPosition().x + BALL_RADIUS * 2 && ball.ball.getPosition().x + BALL_RADIUS * 2 <= shape.shape.getPosition().y + BAT_HEIGHT))
	{
	 ball.ballspeedX = -ball.ballspeedX;
	}*/
}

void ballDraw(sf::RenderWindow& window, Ball& ball) {
	window.draw(ball.shape);
}
