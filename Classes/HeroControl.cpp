#include "HeroControl.h"

HeroControl::HeroControl(Scene* scene, Hero* hero, Layer* layer)
{
	_hero = hero; // ����� �޸��ּ� �޾ƿ���
	_scene = scene; // Scene �޸��ּ� �޾ƿ���
	_layer = layer;

	cache = SpriteFrameCache::getInstance(); // ĳ������
	cache->addSpriteFramesWithFile("UI/ui_gameplay.plist"); // plist �߰�
	cache->addSpriteFramesWithFile("Player/UNIT_B~1/btn_unit-hd.plist"); // plist �߰�
	cache->addSpriteFramesWithFile("UI/game_info/ui_game_info.plist"); // plist �߰�

	// ������ ���
	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HeroControl::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HeroControl::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HeroControl::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, _scene);

	// ����� ���� ��������Ʈ
	_leftButton = Sprite::createWithSpriteFrameName("btn_left_up.png");
	_leftButton->setAnchorPoint({ 0,0 });
	_leftButton->setPosition({ 10,5 });
	_rightButton = Sprite::createWithSpriteFrameName("btn_right_up.png");
	_rightButton->setAnchorPoint({ 0,0 });
	_rightButton->setPosition({ 125,5 });

	// �뽬���� ��������Ʈ
	_mainDashbord = Sprite::createWithSpriteFrameName("ui_game_dashboard.png");
	_mainDashbord->setAnchorPoint({ 0,0 });
	_mainDashbord->setPosition({ 0,0 });
	_mainDashbordCase = Sprite::createWithSpriteFrameName("ui_macebtn_case.png");
	_mainDashbordCase->setAnchorPoint({ 0,0 });
	_mainDashbordCase->setPosition({ 237,2 });

	// ��ų 1,2,3 ��ư ��������Ʈ
	_skillOneButton = Sprite::createWithSpriteFrameName("btn_fist_up.png");
	_skillOneButton->setAnchorPoint({ 0,0 });
	_skillOneButton->setPosition({ 256,5 });
	_skillTwoButton = Sprite::createWithSpriteFrameName("btn_heal_up.png");
	_skillTwoButton->setAnchorPoint({ 0,0 });
	_skillTwoButton->setPosition({ 333,5 });
	_skillThreeButton = Sprite::createWithSpriteFrameName("btn_turnundead_up.png");
	_skillThreeButton->setAnchorPoint({ 0,0 });
	_skillThreeButton->setPosition({ 407,5 });

	// ���� ��ȯ ��ư
	_mouseSummonsButton = Sprite::createWithSpriteFrameName("btn_unit_00_disable.png");
	_mouseSummonsButton->setAnchorPoint({ 0,0 });
	_mouseSummonsButton->setPosition({ 10,55 });
	_mouseSummonsButton->setScale(0.5f);
	_mouseSummonsButton->setScaleY(0.48f);
	_scene->addChild(_mouseSummonsButton, 1);

	// �� ��ȯ ��ư
	_bearSummonsButton = Sprite::createWithSpriteFrameName("btn_unit_02_disable.png");
	_bearSummonsButton->setAnchorPoint({ 0,0 });
	_bearSummonsButton->setPosition({ 61,55 });
	_bearSummonsButton->setScale(0.5f);
	_bearSummonsButton->setScaleY(0.48f);
	_scene->addChild(_bearSummonsButton, 1);

	// Ļ�ŷ� ��ȯ ��ư
	_kangarooSummonsButton = Sprite::createWithSpriteFrameName("btn_unit_03_disable.png");
	_kangarooSummonsButton->setAnchorPoint({ 0,0 });
	_kangarooSummonsButton->setPosition({ 112,55 });
	_kangarooSummonsButton->setScale(0.5f);
	_kangarooSummonsButton->setScaleY(0.48f);
	_scene->addChild(_kangarooSummonsButton, 1);

	// ��ȯ ��ư ���
	_unitLock1 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock1->setAnchorPoint({ 0, 0 });
	_unitLock1->setPosition({ 163,55 });
	_unitLock1->setScale(0.5f);
	_unitLock1->setScaleY(0.48f);
	_scene->addChild(_unitLock1, 1);

	_unitLock2 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock2->setAnchorPoint({ 0, 0 });
	_unitLock2->setPosition({ 214,55 });
	_unitLock2->setScale(0.5f);
	_unitLock2->setScaleY(0.48f);
	_scene->addChild(_unitLock2, 1);

	_unitLock3 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock3->setAnchorPoint({ 0, 0 });
	_unitLock3->setPosition({ 265,55 });
	_unitLock3->setScale(0.5f);
	_unitLock3->setScaleY(0.48f);
	_scene->addChild(_unitLock3, 1);

	_unitLock4 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock4->setAnchorPoint({ 0, 0 });
	_unitLock4->setPosition({ 316,55 });
	_unitLock4->setScale(0.5f);
	_unitLock4->setScaleY(0.48f);
	_scene->addChild(_unitLock4, 1);

	_unitLock5 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock5->setAnchorPoint({ 0, 0 });
	_unitLock5->setPosition({ 367,55 });
	_unitLock5->setScale(0.5f);
	_unitLock5->setScaleY(0.48f);
	_scene->addChild(_unitLock5, 1);

	_unitLock6 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock6->setAnchorPoint({ 0, 0 });
	_unitLock6->setPosition({ 418,55 });
	_unitLock6->setScale(0.5f);
	_unitLock6->setScaleY(0.48f);
	_scene->addChild(_unitLock6, 1);
	

	//���,���� ������
	_meatIcon = Sprite::createWithSpriteFrameName("gauge_icon_food.png");
	_meatIcon->setAnchorPoint({ 0,0 });
	_meatIcon->setPosition({ 2,107 });
	_scene->addChild(_meatIcon, 1);
	_manaIcon = Sprite::createWithSpriteFrameName("gauge_icon_mana.png");
	_manaIcon->setAnchorPoint({ 0,0 });
	_manaIcon->setPosition({ 445,107 });
	_scene->addChild(_manaIcon, 1);
	_meatBackGround = Sprite::createWithSpriteFrameName("ui_gauge_back.png");
	_meatBackGround->setAnchorPoint({ 0,0 });
	_meatBackGround->setPosition(33, 105);
	_scene->addChild(_meatBackGround, -10);

	// ���� ��ⷮ ��Ʈ
	_currentMeat = Label::createWithTTF("", "fonts/arial.ttf", 14);
	_currentMeat->setPosition(73, 113);
	_currentMeat->setAnchorPoint({ 1, 0 });
	_currentMeat->enableBold();
	_scene->addChild(_currentMeat,100);

	// �ִ� ��ⷮ ��Ʈ
	_MaxMeat = Label::createWithTTF("", "fonts/arial.ttf", 14);
	_MaxMeat->setPosition(80, 113);
	_MaxMeat->setAnchorPoint({ 0, 0 });
	_MaxMeat->enableBold();
	_scene->addChild(_MaxMeat, 100);

	// ���� ������ ��Ʈ
	_currentMana = Label::createWithTTF("", "fonts/arial.ttf", 14);
	_currentMana->setPosition(400, 113);
	_currentMana->setAnchorPoint({ 1,0 });
	_currentMana->enableBold();
	_scene->addChild(_currentMana, 100);

	// �ִ� ���ķ� ��Ʈ
	_MaxMana = Label::createWithTTF("", "fonts/arial.ttf", 14);
	_MaxMana->setPosition(407, 113);
	_MaxMana->setAnchorPoint({ 0,0 });
	_MaxMana->enableBold();
	_scene->addChild(_MaxMana, 100);

	// ü�� ����(����߾�)
	_hpInfoLayout = Sprite::createWithSpriteFrameName("ui_hp_info_layout.png");
	_hpInfoLayout->setAnchorPoint({ 0.5, 1 });
	_hpInfoLayout->setPosition(240,320);
	_scene->addChild(_hpInfoLayout);
	_hpInfoBack = Sprite::createWithSpriteFrameName("ui_hp_info_back.png");
	_hpInfoBack->setAnchorPoint({ 0.5, 1 });
	_hpInfoBack->setPosition(240, 315);
	_scene->addChild(_hpInfoBack, -10);

	_expBar = Sprite::createWithSpriteFrameName("ui_exp.png");
	_expBar->setAnchorPoint({ 0,1 });
	_expBar->setPosition(0, 320);
	_scene->addChild(_expBar);

	_expBarBack = Sprite::createWithSpriteFrameName("ui_exp_back.png");
	_expBarBack->setAnchorPoint({ 0,1 });
	_expBarBack->setPosition(4, 308);
	_scene->addChild(_expBarBack, -10);
	
	// addchild
	_scene->addChild(_leftButton, 1);
	_scene->addChild(_rightButton, 1);
	_scene->addChild(_mainDashbord, 0);
	_scene->addChild(_mainDashbordCase, 2);
	_scene->addChild(_skillOneButton, 0);
	_scene->addChild(_skillTwoButton, 0);
	_scene->addChild(_skillThreeButton, 0);

	_right = false; // �������̵�
	_left = false; // �����̵�
	_skillOneClick = false; // ��ų1 ��ư
	_skillTwoClick = false; // ��ų2 ��ư
	_skillThreeClick = false; // ��ų3 ��ư

	_mouseSummonsClick = false; // ���� ��ȯ ��ư
	_bearSummonsClick = false; // �� ��ȯ ��ư
	_kangarooSummonsClick = false; // Ļ�ŷ� ��ȯ ��ư
}

void HeroControl::HeroMove()
{
	// ����� ���ۺ�
	if (_left)
	{
		_hero->setMoveWay(LeftWay); // ������ ���»���

		_hero->getHero()->setPosition(_hero->getHero()->getPosition() + Vec2(_hero->getSpeed() * -1, 0));

		if (!_hero->getHero()->getNumberOfRunningActionsByTag(Walking))
		{
			_hero->getHero()->runAction(_hero->getWalkingAction());
		}
	}
	if (_right)
	{
		_hero->setMoveWay(RightWay); // �������� ���»��� 

		_hero->getHero()->setPosition(_hero->getHero()->getPosition() + Vec2(_hero->getSpeed(), 0));

		if (!_hero->getHero()->getNumberOfRunningActionsByTag(Walking))
		{
			_hero->getHero()->runAction(_hero->getWalkingAction());
		}
	}
	if (!_hero->getHero()->getNumberOfRunningActions())
	{
		if (!_hero->getHero()->getNumberOfRunningActionsByTag(Waiting))
		{
			_hero->getHero()->runAction(_hero->getWaitingAction());

		}
	}

	// ��ų��ư 1
	if (_hero->getMana() < _hero->getSkillOneManaUse())
	{
		_skillOneButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (_hero->getMana() >= _hero->getSkillOneManaUse() && !_skillOneClick)
	{
		_skillOneButton->setSpriteFrame("btn_fist_up.png");
	}
	else if (_skillOneClick)
	{
		_skillOneButton->setSpriteFrame("btn_fist_down.png");
	}
	// ��ų��ư 2
	if (_hero->getMana() < _hero->getSkillTwoManaUse())
	{
		_skillTwoButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (_hero->getMana() >= _hero->getSkillTwoManaUse() && !_skillTwoClick)
	{
		_skillTwoButton->setSpriteFrame("btn_heal_up.png");
	}
	else if (_skillTwoClick)
	{
		_skillTwoButton->setSpriteFrame("btn_heal_down.png");
	}

	// ��ų��ư 3
	if (_hero->getMana() < _hero->getSkillThreeManaUse())
	{
		_skillThreeButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (_hero->getMana() >= _hero->getSkillThreeManaUse() && !_skillThreeClick)
	{
		_skillThreeButton->setSpriteFrame("btn_turnundead_up.png");
	}
	else if (_skillThreeClick)
	{
		_skillThreeButton->setSpriteFrame("btn_turnundead_down.png");
	}

	// ���� ��ȯ ��ư
	if (_hero->getMeat() < 10)
	{
		_mouseSummonsButton->setSpriteFrame("btn_unit_00_disable.png");
	}
	else if (_hero->getMeat() >= 10 && !_mouseSummonsClick)
	{
		_mouseSummonsButton->setSpriteFrame("btn_unit_00_up.png");
	}
	else if (_mouseSummonsClick)
	{
		_mouseSummonsButton->setSpriteFrame("btn_unit_00_down.png");
	}

	// �� ��ȯ ��ư
	if (_hero->getMeat() < 30)
	{
		_bearSummonsButton->setSpriteFrame("btn_unit_02_disable.png");
	}
	else if (_hero->getMeat() >= 30 && !_bearSummonsClick)
	{
		_bearSummonsButton->setSpriteFrame("btn_unit_02_up.png");
	}
	else if (_bearSummonsClick)
	{
		_bearSummonsButton->setSpriteFrame("btn_unit_02_down.png");
	}

	// Ļ�ŷ� ��ȯ��ư
	if (_hero->getMeat() < 40)
	{
		_kangarooSummonsButton->setSpriteFrame("btn_unit_03_disable.png");
	}
	else if (_hero->getMeat() >= 40 && !_kangarooSummonsClick)
	{
		_kangarooSummonsButton->setSpriteFrame("btn_unit_03_up.png");
	}
	else if (_kangarooSummonsClick)
	{
		_kangarooSummonsButton->setSpriteFrame("btn_unit_03_down.png");
	}

	_hero->getManaGauge()->setPercentage((_hero->getMana() / _hero->getMaxMana()) * 100); // ������������ Bar �� �����ش�
	_hero->getMeatGauge()->setPercentage((_hero->getMeat() / _hero->getMaxMeat()) * 100); // ���������� Bar �� �����ش�
	_hero->getHeroHpInfo()->setPercentage((_hero->getHp() / _hero->getMaxHp()) * 100); // �÷��̾��� ü���� ������
	_hero->getMonsterBaseInfo()->setPercentage(100);


	// ����,��� �������� ���ڷ� �����ش�
	_currentMeat->setString(String::createWithFormat("%d", (int)_hero->getMeat())->_string.c_str());
	_MaxMeat->setString(String::createWithFormat("%d", (int)_hero->getMaxMeat())->_string.c_str());
	_currentMana->setString(String::createWithFormat("%d", (int)_hero->getMana())->_string.c_str());
	_MaxMana->setString(String::createWithFormat("%d", (int)_hero->getMaxMana())->_string.c_str());
	
}

void HeroControl::UnitMove()
{
	// ���� �̵�
	for (int i = 0; i < _heroUnitVec.size(); ++i)
	{
		// ������ �̵�
		if (_heroUnitVec[i]->getUnitAction() == UnitWalk)
		{
			_heroUnitVec[i]->getSprite()->setPosition(_heroUnitVec[i]->getSprite()->getPosition() +
				Vec2(_heroUnitVec[i]->getSpeed(), 0));
		}

		// Walk �׼�(�ִϸ��̼�)
		if (_heroUnitVec[i]->getUnitAction() != UnitCollision && !_heroUnitVec[i]->getSprite()->getNumberOfRunningActions())
		{
			_heroUnitVec[i]->setUnitAction(UnitWalk);
			_heroUnitVec[i]->getSprite()->runAction(_heroUnitVec[i]->getWalkAction());
		}
	}	
}

void HeroControl::HeroManaRegen()
{
	// ���� ����
	if (_hero->getMana() < _hero->getMaxMana())
	{
		_hero->setMana(_hero->getMana() + 1);
	}
}

void HeroControl::HeroMeatRegen()
{
	// ��� ����
	if (_hero->getMeat() < _hero->getMaxMeat())
	{
		_hero->setMeat(_hero->getMeat() + 1);
	}
}

bool HeroControl::onTouchBegan(Touch * touch, Event * event)
{

	// �¿� �̵�
	if (_leftButton->getBoundingBox().containsPoint(touch->getLocation()))
	{

		_hero->getHero()->setFlippedX(true);
		_left = true;
		_leftButton->setSpriteFrame("btn_left_down.png");

	}
	else if (_rightButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_hero->getHero()->setFlippedX(false);
		_right = true;
		_rightButton->setSpriteFrame("btn_right_down.png");
	}

	if (_hero->getHero()->getNumberOfRunningActionsByTag(Waiting))
	{
		_hero->getHero()->stopActionByTag(Waiting);
	}

	// ��ų 1 Ŭ���� �ൿ
	if (_skillOneButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_skillOneClick = true;

		if (_hero->getMana() >= _hero->getSkillOneManaUse())
		{
			_hero->setMana(_hero->getMana() - _hero->getSkillOneManaUse());
			_hero->getHero()->runAction(_hero->getAttackAction()->clone()); // ���� ��� ����
		}
	}

	// ��ų 2 Ŭ���� �ൿ
	if (_skillTwoButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_skillTwoClick = true;


		if (_hero->getMana() >= _hero->getSkillTwoManaUse())
		{
			_hero->setMana(_hero->getMana() - _hero->getSkillTwoManaUse());
			_hero->getHero()->runAction(_hero->getAttackAction()->clone()); // ���� ��� ����
		}

	}

	// ��ų 3 Ŭ���� �ൿ
	if (_skillThreeButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_skillThreeClick = true;


		if (_hero->getMana() >= _hero->getSkillThreeManaUse())
		{
			_hero->setMana(_hero->getMana() - _hero->getSkillThreeManaUse());
			_hero->getHero()->runAction(_hero->getAttackAction()->clone()); // ���� ��� ����
		}

	}

	// ���� ��ȯ ��ư
	if (_mouseSummonsButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (_hero->getMeat() >= 10)
		{
			_mouseSummonsClick = true;

			_heroUnit = new HeroUnit(_scene, ����, _layer);
			_heroUnitVec.push_back(_heroUnit);

			_hero->setMeat(_hero->getMeat() - 10);
		}
	}

	// �� ��ȯ ��ư
	if (_bearSummonsButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (_hero->getMeat() >= 30)
		{
			_bearSummonsClick = true;

			_heroUnit = new HeroUnit(_scene, ��, _layer);
			_heroUnitVec.push_back(_heroUnit);

			_hero->setMeat(_hero->getMeat() - 30);
		}
	}

	// Ļ�ŷ� ��ȯ ��ư
	if (_kangarooSummonsButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (_hero->getMeat() >= 40)
		{
			_kangarooSummonsClick = true;

			_heroUnit = new HeroUnit(_scene, Ļ�ŷ�, _layer);
			_heroUnitVec.push_back(_heroUnit);

			_hero->setMeat(_hero->getMeat() - 40);
		}

	}

	return true;
}

void HeroControl::onTouchMoved(Touch * touch, Event * event)
{
}

void HeroControl::onTouchEnded(Touch * touch, Event * event)
{
	_left = false;
	_right = false;
	_skillOneClick = false;
	_skillTwoClick = false;
	_skillThreeClick = false;
	_mouseSummonsClick = false;
	_bearSummonsClick = false;
	_kangarooSummonsClick = false;

	_leftButton->setSpriteFrame("btn_left_up.png");
	_rightButton->setSpriteFrame("btn_right_up.png");

	if (_hero->getHero()->getNumberOfRunningActionsByTag(Walking))
	{
		_hero->getHero()->stopActionByTag(Walking);
	}

}
