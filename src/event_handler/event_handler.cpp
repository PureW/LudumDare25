

#include "event_handler.h"







EventHandler::EventHandler( sf::RenderWindow *_App )
{
	App = _App;
}


const UserEvents  EventHandler::processEvents()
{
	const sf::Input& Input = App->GetInput();

	events.pressingUp = Input.IsKeyDown(sf::Key::Comma) | Input.IsKeyDown(sf::Key::W);
	events.pressingDown = Input.IsKeyDown(sf::Key::Comma) | Input.IsKeyDown(sf::Key::S);
	events.pressingLeft = Input.IsKeyDown(sf::Key::A);
	events.pressingRight = Input.IsKeyDown(sf::Key::D) | Input.IsKeyDown(sf::Key::E);
	events.pressingSpace = Input.IsKeyDown(sf::Key::Space);

	events.mouse_x = Input.GetMouseX();
	events.mouse_y = Input.GetMouseY();

	events.pressingF9 = Input.IsKeyDown(sf::Key::F9);


	// Process events
	sf::Event Event;
	while (App->GetEvent(Event))
	{
		switch( Event.Type )
		{
		case sf::Event::Closed: // Close window : exit
			App->Close();
			break;
		case sf::Event::KeyPressed:
		case sf::Event::KeyReleased:
			//processKeyEvent( Event );
			break;

		default:
			break;
		}

	}

	return events;
}

