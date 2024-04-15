//read visual studio prompts on the functions for more details
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main() {
	RenderWindow window(VideoMode(640, 400), "SFML Works!", Style::Default);
	window.setFramerateLimit(50); //frame rates can be modified but be mindful of system capacity
	Vector2f vec1(50.f, 100.f);//makes 2 floats go together (x & y coords) (Vector2i does the same with ints)
	CircleShape shape (50.f); //circle takes rad in constructor
	RectangleShape rect(vec1);
	shape.setPosition(Vector2f(0.f, 0.f));
	rect.setPosition(Vector2f(400.f, 200.f));
	rect.setFillColor(Color::Yellow);
	rect.setOutlineThickness(10.f); 
	rect.setOutlineColor(Color::Black);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)window.close();
		}
		//update
		shape.move(0.1f, 0.f); //Parameters (x coord,y coord)
		rect.move(0.f, 0.2f);
		rect.rotate(5.f);
		//draw
		window.clear(Color::Red);
		//draw everything
		window.draw(shape);window.draw(rect);
		window.display();
	}
	




