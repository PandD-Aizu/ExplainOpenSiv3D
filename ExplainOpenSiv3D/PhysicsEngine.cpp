#include"def.h"

Physics::Physics(const InitData& init) : IScene(init)
{
	ground = world.createLine(P2Static, Vec2{ 400, 300 }, Line{ -300, 0, 300, 0 });
}

void Physics::update()
{
	// 2D 物理演算のシミュレーションステップ（秒）
	constexpr double stepSec = (1.0 / 200.0);

	// 2D 物理演算のシミュレーション蓄積時間（秒）
	static double accumulatorSec = 0.0;

	for (accumulatorSec += Scene::DeltaTime(); stepSec <= accumulatorSec; accumulatorSec -= stepSec)
	{
		// 2D 物理演算のワールドを更新
		world.update(stepSec);
	}

	// 地面より下に落ちた物体は削除
	bodies.remove_if([](const P2Body& b) { return (500 < b.getPos().y); });

	// 左クリックしたら
	if (MouseL.down())
	{
		// クリックした場所に半径 10 cm のボールを作成
		bodies << world.createCircle(P2Dynamic, Cursor::PosF(), 10);
	}
	if (MouseR.down())
	{
		// クリックした場所に半径 10 cm のボールを作成
		bodies << world.createTriangle(P2Dynamic, Cursor::PosF(), Triangle(0, 0, 20, (Random(359) * Math::Pi / 180.0)));
	}

}

void Physics::draw() const
{

	Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

	// すべてのボディを描画
	for (const auto& body : bodies)
	{
		body.draw(HSV{ body.id() * 10.0 });
	}

	// 地面を描画
	ground.draw(Palette::Skyblue);
}
