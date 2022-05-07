#include"def.h"

Collision::Collision(const InitData& init) : IScene(init)
{
	mouseCircle = Circle(Vec2(-100, -100), 20);

	rects << Shape{ RectF(10,10,400,200),Palette::Red };
	rects << Shape{ RectF(30,400,300,70),Palette::Blue };
	rects << Shape{ RectF(300,350,100,70),Palette::Green };
	rects << Shape{ RectF(550,100,200,200),Palette::Yellow };
}

void Collision::update()
{
	mouseCircle.setPos(Cursor::Pos());
}

void Collision::draw() const
{

	Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

	for (Shape obj : rects) {
		if (mouseCircle.intersects(obj.body)) {
			obj.body.draw(obj.color);
		}
		else {
			obj.body.draw(Palette::Gray);
		}
	}
	mouseCircle.draw(Palette::Orange);
}
