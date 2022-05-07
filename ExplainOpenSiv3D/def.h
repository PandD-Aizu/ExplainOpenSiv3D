#pragma once
# include <Siv3D.hpp>

enum Scenes
{
	TITLE,
	COLLISION,
	PHYSICS,
};

using App = SceneManager<Scenes>;

class Title : public App::Scene
{
public:
	// コンストラクタ（必ず実装）
	Title(const InitData& init);

	// 更新関数
	void update() override;

	// 描画関数 (const 修飾)
	void draw() const override;

private:
	const Font font=Font(50);
};

struct Shape {
	RectF body;
	Color color;
};

class Collision : public App::Scene
{
public:

	Circle mouseCircle;
	Array<Shape> rects;
	// コンストラクタ（必ず実装）
	Collision(const InitData& init);

	// 更新関数
	void update() override;

	// 描画関数 (const 修飾)
	void draw() const override;

private:
	const Font font = Font(50);
};

class Physics : public App::Scene
{
public:
	Physics(const InitData& init);

	// 更新関数
	void update() override;

	// 描画関数 (const 修飾)
	void draw() const override;

private:
	const Font font = Font(50);
};
