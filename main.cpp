#include "settings.h"
#include "functions.h"
#include "bat.h"
#include "ball.h"

using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE
	);
	window.setFramerateLimit(FPS);
	Bat bat;
	batInit(bat);

	Ball ball;
	initBall(ball);

	int Score = 0;
	Font font;
	font.loadFromFile("Pitbull.ttf");
	Text ScoreText;
	initText(ScoreText, Score, font, charSize, textstartpos);

	while (window.isOpen()) {
		checkEvents(window,ball);
		updateGame(bat,ball);
		checkCollisions();
		drawGame(window, bat,ball);
	}
	
  return 0;
}

	


