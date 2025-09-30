#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <array>

const sf::Keyboard::Key controls[4] = {
	sf::Keyboard::A,   // Player1 UP
	sf::Keyboard::Z,   // Player1 Down
	sf::Keyboard::Up,  // Player2 UP
	sf::Keyboard::Down // Player2 Down
};

//Parameters
const sf::Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;
const float paddleOffsetWall = 10.f;
const float time_step = 0.017f; //60 fps

//Objects of the game
sf::CircleShape ball;
sf::RectangleShape paddles[2];
std::array<int, 2> scores;

sf::Vector2f ball_velocity;
bool is_player_serving = true;
const float initial_velocity_x = 100.f; //horizontal velocity
const float initial_velocity_y = 60.f; //vertical velocity
const float velocity_multiplier = 1.1f; //how much the ball will speed up everytime it hits a paddle. Here, 10% every time.

sf::Font font;
sf::Text text;

void setEntityPositions() {
	// reset paddle position
	paddles[0].setPosition(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f);
	paddles[1].setPosition(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f);
	// reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	ball_velocity = { (is_player_serving ? initial_velocity_x : -initial_velocity_x), initial_velocity_y };
}

void init() {
	// Set size and origin of paddles
	for (sf::RectangleShape& p : paddles) {
		p.setSize(paddleSize);
		p.setOrigin(paddleSize / 2.f);
	}
	// Set size and origin of ball
	ball.setRadius(ballRadius);
	ball.setOrigin(ball.getRadius(), ball.getRadius()); //Should be half the ball width and height

	setEntityPositions();

	// Load font-face from res dir
	font.loadFromFile("resources/fonts/RobotoMono-Medium.ttf");
	// Set text element to use font
	text.setFont(font);
	// set the character size to 24 pixels
	text.setCharacterSize(24);

	scores[0] = 0;
	scores[1] = 0;
	text.setString((char)scores[0] + " | " + (char)scores[1]);
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void reset() {
	setEntityPositions();

	// Update Score Text
	text.setString((char)scores[0] + " | " + (char)scores[1]);
	// Keep Score Text Centered
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void update(float dt) {
	// handle paddle movement
	float direction = 0.0f;
	int paddleToMove = 0;
	if (sf::Keyboard::isKeyPressed(controls[0]) && paddles[0].getPosition().y > 0) {
		direction--;
		paddleToMove = 0;
	}
	if (sf::Keyboard::isKeyPressed(controls[1]) && paddles[0].getPosition().y < gameHeight) {
		direction++;
		paddleToMove = 0;
	}
	if (sf::Keyboard::isKeyPressed(controls[2]) && paddles[1].getPosition().y > 0) {
		direction--;
		paddleToMove = 1;
	}
	if (sf::Keyboard::isKeyPressed(controls[3]) && paddles[1].getPosition().y < gameHeight) {
		direction++;
		paddleToMove = 1;
	}

	paddles[paddleToMove].move(sf::Vector2f(0.f, direction * paddleSpeed * dt));

	ball.move(ball_velocity * dt);

	// check ball collision
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;

	if (by > gameHeight || by < 0) { //bottom wall and top wall
		ball_velocity.x *= velocity_multiplier;
		ball_velocity.y *= -velocity_multiplier;

		if (by > gameHeight) // Bottom Wall
		{
			ball.move(sf::Vector2f(0.f, -10.f));
		}
		else { // Top Wall
			ball.move(sf::Vector2f(0.f, 10.f));
		}
	}
	else if (bx > gameWidth) {
		// right wall
		is_player_serving = false;
		scores[0] += 1;
		reset();
	}
	else if (bx < 0)
	{
		// left wall
		is_player_serving = true;
		scores[1] += 1;
		reset();
	}
	else if (
		//ball is inline or behind paddle AND
		bx < paddleSize.x + paddleOffsetWall &&
		//ball is below top edge of paddle AND
		by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
		//ball is above bottom edge of paddle
		by < paddles[0].getPosition().y + (paddleSize.y * 0.5)) {
				ball_velocity.x *= -1;
			}
	else if (
		bx > gameWidth - paddleSize.x - paddleOffsetWall &&
		by > paddles[1].getPosition().y - (paddleSize.y * 0.5f) &&
		by < paddles[1].getPosition().y + (paddleSize.y * 0.5f)) {
		ball_velocity.x *= -1;
	}
}

void render(sf::RenderWindow& window) {
	// Draw Everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
	window.draw(text);
	window.display();
}

void clean() {
	//free up the memory if necessary.
}

int main() {
	//create the window
	sf::RenderWindow window(sf::VideoMode({ gameWidth, gameHeight }), "PONG");
	window.setVerticalSyncEnabled(true);

	//initialise and load
	init();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		static sf::Clock clock;
		const float dt = clock.restart().asSeconds();

		window.clear();
		update(dt);
		render(window);
		//wait for the time_step to finish before displaying the next frame.
		sf::sleep(sf::seconds(time_step));
		window.display();
	}
	//Unload and shutdown
	clean();
}
