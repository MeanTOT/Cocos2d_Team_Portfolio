#include "MindForest_Stage1.h"

Scene* MindForest_Stage1::createScene() {
	return MindForest_Stage1::create();
}

bool MindForest_Stage1::init() {
	if (!Scene::init()) {
		return false;
	}

	_bgLayer = Layer::create();
	this->addChild(_bgLayer, -100);

	_hero = new Hero(this, _bgLayer);
	_heroControl = new HeroControl(this, _hero, _bgLayer);
	_dungeon = new Dungeon(this, _bgLayer, 1000.0f); //3��° ���ڿ� ü�� ����

	this->schedule(schedule_selector(MindForest_Stage1::tick));
	this->schedule(schedule_selector(MindForest_Stage1::HeroManaRegen), _hero->getManaRegenSpeed());
	this->schedule(schedule_selector(MindForest_Stage1::HeroMeatRegen), _hero->getMeatRegenSpeed());
	
	// ����̹��� plist
	_cache = SpriteFrameCache::getInstance();
	_cache->addSpriteFramesWithFile("UI/Background/background_00.plist");

	// ����̹��� �����.
	_backGround1 = Sprite::createWithSpriteFrameName("background_00_a.png");
	_backGround1->setPosition({ 0,525 });
	_backGround1->setAnchorPoint({ 0,1 });

	// �̹����� ª�Ƽ� ������ ����
	_backGround2 = Sprite::createWithSpriteFrameName("background_00_b.png");
	_backGround2->setPosition({ 0,525 });
	_backGround2->setAnchorPoint({ 0,1 });
	_backGround2_1 = Sprite::createWithSpriteFrameName("background_00_b.png");
	_backGround2_1->setPosition({ 752,525 });
	_backGround2_1->setAnchorPoint({ 0,1 });

	_backGround3 = Sprite::createWithSpriteFrameName("background_00_c.png");
	_backGround3->setPosition({ 0,525 });
	_backGround3->setAnchorPoint({ 0,1 });

	// �̹����� ª�Ƽ� ������ ����
	_backGround3_1 = Sprite::createWithSpriteFrameName("background_00_c.png");
	_backGround3_1->setPosition({ 480,525 });
	_backGround3_1->setAnchorPoint({ 0,1 });
	_backGround3_2 = Sprite::createWithSpriteFrameName("background_00_c.png");
	_backGround3_2->setPosition({ 960,525 });
	_backGround3_2->setAnchorPoint({ 0,1 });

	// �̹����� ������ �����ڸ��� �������� ����� ������ ����
	_backGround1->getTexture()->setAliasTexParameters();
	_backGround2->getTexture()->setAliasTexParameters();
	_backGround2_1->getTexture()->setAliasTexParameters();
	_backGround3->getTexture()->setAliasTexParameters();
	_backGround3_1->getTexture()->setAliasTexParameters();
	_backGround3_2->getTexture()->setAliasTexParameters();

	// ��淹�̾ �߰�
	_bgLayer->addChild(_backGround1, -1000);
	_bgLayer->addChild(_backGround2, -1010);
	_bgLayer->addChild(_backGround2_1, -1010);
	_bgLayer->addChild(_backGround3, -1020);
	_bgLayer->addChild(_backGround3_1, -1020);
	_bgLayer->addChild(_backGround3_2, -1020);
	
	// Follow �׼����� ȭ���̵�����
	_bgLayer->runAction(Follow::create(_hero->getHero(), Rect(0, 0, 1024, 512)));

	return true;
}

void MindForest_Stage1::tick(float delta)
{
	MonsterTick();

	for (int i = 0; i < _heroControl->getHeroUnitVec().size(); i++)
	{
		_heroControl->getHeroUnitVec()[i]->BringMonsterVec(_monster);
	}

	_heroControl->HeroMove(_dungeon); // ����� ���� ����
	_heroControl->UnitVecErase();
	_heroControl->CoolTime();

}

void MindForest_Stage1::HeroManaRegen(float delta)
{
	_heroControl->HeroManaRegen(); // ��������
}

void MindForest_Stage1::HeroMeatRegen(float delta)
{
	_heroControl->HeroMeatRegen(); // ��⸮��
}

void MindForest_Stage1::MonsterTick()
{
	if (rand() % 300 == 0) {
		_monster.push_back(new Monster(this, _bgLayer, _hero, _heroControl->getHeroUnitVec(), Mob::�Ϲ�����));
	}
	if (rand() % 1500 == 0) {
		_monster.push_back(new Monster(this, _bgLayer, _hero, _heroControl->getHeroUnitVec(), Mob::��ȭ����));
	}
	for (int i = 0; i < _monster.size(); i++) {
		if (_monster[i]->getUnitAttack() != -1 && 
			_monster[i]->getUnitAttack() < _heroControl->getHeroUnitVec().size()) {
			_heroControl->getHeroUnitVec()[_monster[i]->getUnitAttack()]->setHp(_heroControl->getHeroUnitVec()[_monster[i]->getUnitAttack()]->getHp() - _monster[i]->getAtk());
			_monster[i]->setUnitAttack();
		}
		if (_dungeon->getIsCrash()) {
			_monster[i]->Hit(999999);
		}
		if (_heroControl->getHeroUnitVec().size() != _monster[i]->getUnitSize()) {
			_monster[i]->setUnit(_heroControl->getHeroUnitVec());
		}
		_monster[i]->MonsterMove();
		if (_monster[i]->getIsRemove()) {
			_bgLayer->removeChild(_monster[i]->getMonster());
			_monster.erase(_monster.begin() + i);
		}
	}
}