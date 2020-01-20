#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroControl.h"
#include "HeroUnit.h"
#include "Monster.h"
#include "Dungeon.h"

enum ZORDER { //�̰� ���δ°� �����?
	������ = 10,
	���� = 50,
	���� = 55,
	������ = 90
};

class MindForest_Stage1 : public Scene
{
	Hero* _hero;
	HeroControl* _heroControl;
	HeroUnit* _heroUnit;
	vector<Monster*> _monster;
	Dungeon* _dungeon;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MindForest_Stage1);

	void tick(float delta);
	void HeroManaRegen(float delta);
	void HeroMeatRegen(float delta);

	void MonsterTick();
};
