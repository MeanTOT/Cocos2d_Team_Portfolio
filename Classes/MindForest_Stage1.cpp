#include "MindForest_Stage1.h"


Scene* MindForest_Stage1::createScene() {
	return MindForest_Stage1::create();
}

bool MindForest_Stage1::init() {
	if (!Scene::init()) {
		return false;
	}

	_hero = new Hero(this);
	_heroControl = new HeroControl(this, _hero);
	_dungeon = new Dungeon(this, 1000); //2��° ���ڿ� ü�� ����

	this->schedule(schedule_selector(MindForest_Stage1::tick));
	this->schedule(schedule_selector(MindForest_Stage1::HeroManaRegen), _hero->getManaRegenSpeed());
	this->schedule(schedule_selector(MindForest_Stage1::HeroMeatRegen), _hero->getMeatRegenSpeed());

	_monster.push_back(new Monster(this, _hero, _heroControl->getHeroUnitVec(), Mob::����ŷ)); //���� ����

	_hero->getHero()->setZOrder(50); //��ġ������ ���� �ӽ� �����Դϴ�

	return true;
}

void MindForest_Stage1::tick(float delta)
{
	_heroControl->HeroMove();
	_heroControl->UnitMove();

	MonsterTick();
}

void MindForest_Stage1::HeroManaRegen(float delta)
{
	_heroControl->HeroManaRegen();
}

void MindForest_Stage1::HeroMeatRegen(float delta)
{
	_heroControl->HeroMeatRegen();
}

void MindForest_Stage1::MonsterTick()
{
	if (rand() % 150 == 0) {
		_monster.push_back(new Monster(this, _hero, _heroControl->getHeroUnitVec(), Mob::��ȫ�̶�));
	}
	for (int i = 0; i < _monster.size(); i++) {
		if (_heroControl->getHeroUnitVec().size() != _monster[i]->getUnitSize()) {
			_monster[i]->setUnit(_heroControl->getHeroUnitVec());
		}
		if (_monster[i]->getIsSummon()) { //����ŷ ��ȯ��
			_monster.push_back(new Monster(this, _hero, _heroControl->getHeroUnitVec(), Mob::�ȴ�����));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
			_monster.push_back(new Monster(this, _hero, _heroControl->getHeroUnitVec(), Mob::�ȴ�����));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
		}
		_monster[i]->MonsterMove();
		if (_monster[i]->getIsRemove()) {
			this->removeChild(_monster[i]->getMonster());
			_monster.erase(_monster.begin() + i);
		}
	}
}