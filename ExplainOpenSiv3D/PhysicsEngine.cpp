#include"def.h"

Physics::Physics(const InitData& init) : IScene(init)
{
	
}

void Physics::update()
{
	if (SimpleGUI::Button(U"Physics", Vec2(120, 40))) {
		changeScene(TITLE);
	}
	if (SimpleGUI::Button(U"Collision", Vec2(120, 80))) {
		changeScene(COLLISION);
	}
	if (SimpleGUI::Button(U"Physics", Vec2(120, 80))) {
		changeScene(PHYSICS);
	}
}

void Physics::draw() const
{

	Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

	font(U"My Game").drawAt(400, 100);
}
