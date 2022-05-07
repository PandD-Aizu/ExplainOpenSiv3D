# include "def.h"

void Main()
{
	App manager;

	manager.add<Title>(TITLE);
	manager.add<Collision>(COLLISION);
	manager.add<Physics>(PHYSICS);

	while (System::Update())
	{
		// 現在のシーンを実行
		if (!manager.update())
		{
			break;
		}
	}
}
