#include "MindForest_Stage3.h"

Scene* MindForest_Stage3::createScene() {
	return MindForest_Stage3::create();
}

bool MindForest_Stage3::init() {
	if (!Scene::init()) {
		return false;
	}

	_soundBs = AudioEngine::play2d("Sound/start_battle.mp3", false, 1.f);

	_bgLayer = Layer::create();
	this->addChild(_bgLayer, -100);

	Hero::getInstance()->createHeroInfo(this, _bgLayer);
	_heroControl = new HeroControl(this, _bgLayer, _dungeon);
	_dungeon = new Dungeon(this, _bgLayer, 30000.0f); //3��° ���ڿ� ü�� ����
	_servecScene = new ServiceScene(this);

	this->schedule(schedule_selector(MindForest_Stage3::tick));
	this->schedule(schedule_selector(MindForest_Stage3::HeroManaRegen), Hero::getInstance()->getManaRegenSpeed());
	this->schedule(schedule_selector(MindForest_Stage3::HeroMeatRegen), Hero::getInstance()->getMeatRegenSpeed());

	// ����̹��� plist
	_cache = SpriteFrameCache::getInstance();
	_cache->addSpriteFramesWithFile("UI/Background/background_07.plist");

	// ����̹��� �����.
	_backGround1 = Sprite::createWithSpriteFrameName("background_07_a.png");
	_backGround1->setPosition({ 0,525 });
	_backGround1->setAnchorPoint({ 0,1 });

	// �̹����� ª�Ƽ� ������ ����
	_backGround2 = Sprite::createWithSpriteFrameName("background_07_b.png");
	_backGround2->setPosition({ 0,525 });
	_backGround2->setAnchorPoint({ 0,1 });
	_backGround2_1 = Sprite::createWithSpriteFrameName("background_07_b.png");
	_backGround2_1->setPosition({ 752,525 });
	_backGround2_1->setAnchorPoint({ 0,1 });

	_backGround3 = Sprite::createWithSpriteFrameName("background_07_c.png");
	_backGround3->setPosition({ 0,525 });
	_backGround3->setAnchorPoint({ 0,1 });

	// �̹����� ª�Ƽ� ������ ����
	_backGround3_1 = Sprite::createWithSpriteFrameName("background_07_c.png");
	_backGround3_1->setPosition({ 480,525 });
	_backGround3_1->setAnchorPoint({ 0,1 });
	_backGround3_2 = Sprite::createWithSpriteFrameName("background_07_c.png");
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
	_bgLayer->runAction(Follow::create(Hero::getInstance()->getHero(), Rect(0, 0, 1024, 512)));

	//����ŷ ���°�
	_zomking = 0;

	// �� ���� ȭ��
	_servecScene->GetReady();

	// ����

	BgSoundClear = false;

	Hero::getInstance()->setStageKind(Stage3);

	return true;
}

void MindForest_Stage3::tick(float delta)
{
	if (AudioEngine::getState(_soundBs) != AudioEngine::AudioState::PLAYING && AudioEngine::getState(_soundBg1) != AudioEngine::AudioState::PLAYING && !BgSoundClear)
	{
		_soundBg1 = AudioEngine::play2d("Sound/bg_stage.mp3", true, 0.6);
		BgSoundClear = true;
	}

	if (Hero::getInstance()->getStageStart())
		MonsterTick();

	for (int i = 0; i < _heroControl->getHeroUnitVec().size(); i++)
	{
		_heroControl->getHeroUnitVec()[i]->BringMonsterVec(_monster);

		// �� ��ų ���� �۵�
		if (Hero::getInstance()->getIsHealing())
			_heroControl->getHeroUnitVec()[i]->Healing();
	}

	// ��� ��ü�� ���� ������ �� ��ų ��Ȱ��ȭ ���·� ������
	Hero::getInstance()->setIsHealing(false);

	// ��ų 1 �̻��� �� ���� ���� �浹 ó��
	for (int i = 0; i < _heroControl->getMissileCollisionVec().size(); i++)
	{
		_heroControl->getMissileCollisionVec()[i]->BringMonsterVec(_monster, _dungeon);
	}

	_heroControl->HeroMove(_dungeon); // ����� ���� ����
	_heroControl->UnitVecErase(); // ���ֹ��� ����
	_heroControl->CoolTime(); // ��Ÿ�� ���

	// �������� Ŭ���� ȭ��
	_servecScene->StageClear();

	for (int i = 0; i < _monster.size(); i++)
	{
		if (_monster[i]->getMonsterCode() == "b01" && _monster[i]->getHp() <= 0 && !Hero::getInstance()->getStageClear())
		{
			AudioEngine::stop(_soundBg1);
			AudioEngine::play2d("Sound/stage_clear.mp3", false, 1.0f);
			Hero::getInstance()->setStageClear(true);
		}
	}

	// �� ��ȯ
	if (Hero::getInstance()->getSceneChange())
	{
		AudioEngine::stopAll();
		AudioEngine::uncacheAll();
		Hero::getInstance()->setSceneChange(false);
		//auto scene = MindForest_Stage2::create();
		//Director::getInstance()->replaceScene(scene);
	}
}

void MindForest_Stage3::HeroManaRegen(float delta)
{
	if (Hero::getInstance()->getStageStart() && !Hero::getInstance()->getStageClear())
		_heroControl->HeroManaRegen(); // ��������
}

void MindForest_Stage3::HeroMeatRegen(float delta)
{
	if (Hero::getInstance()->getStageStart() && !Hero::getInstance()->getStageClear())
		_heroControl->HeroMeatRegen(); // ��⸮��
}

void MindForest_Stage3::MonsterTick()
{
	if (_dungeon->getIsCrash()) {
		switch (_zomking) {
		case 0:
			_monster.push_back(new Monster(this, _bgLayer, _heroControl->getHeroUnitVec(), Mob::����ŷ));
			_zomking = 1;
			break;
		case 1:
			if (rand() % 1500 == 0) {
				_monster.push_back(new Monster(this, _bgLayer, _heroControl->getHeroUnitVec(), Mob::��ũ�̶�));
			}
			break;
		}
	}
	else {
		if (rand() % 400 == 0) {
			_monster.push_back(new Monster(this, _bgLayer, _heroControl->getHeroUnitVec(), Mob::��������));
		}
		if (rand() % 1000 == 0) {
			_monster.push_back(new Monster(this, _bgLayer, _heroControl->getHeroUnitVec(), Mob::�Ϲݹ̶�));
		}
		if (rand() % 2000 == 0) {
			_monster.push_back(new Monster(this, _bgLayer, _heroControl->getHeroUnitVec(), Mob::��ũ�̶�));
		}
	}
	for (int i = 0; i < _monster.size(); i++) {
		if (_monster[i]->getIsBossDead()) {
			_zomking = 2;
		}
		if (_zomking == 2) {
			_monster[i]->Hit(999999);
		}
		if (_monster[i]->getUnitAttack() != -1 &&
			_monster[i]->getUnitAttack() < _heroControl->getHeroUnitVec().size()) {
			_heroControl->getHeroUnitVec()[_monster[i]->getUnitAttack()]->setHp(_heroControl->getHeroUnitVec()[_monster[i]->getUnitAttack()]->getHp() - _monster[i]->getAtk());
			_monster[i]->setUnitAttack();
		}
		if (_heroControl->getHeroUnitVec().size() != _monster[i]->getUnitSize()) {
			_monster[i]->setUnit(_heroControl->getHeroUnitVec());
		}
		if (_monster[i]->getIsSummon()) { //����ŷ ��ȯ��
			_monster.push_back(new Monster(this, _bgLayer, _heroControl->getHeroUnitVec(), Mob::�Ϲ�����));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
			_monster.push_back(new Monster(this, _bgLayer, _heroControl->getHeroUnitVec(), Mob::�Ϲ�����));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
		}
		_monster[i]->MonsterMove();
		if (_monster[i]->getIsRemove()) {
			_bgLayer->removeChild(_monster[i]->getMonster());
			_monster.erase(_monster.begin() + i);
		}
	}
}