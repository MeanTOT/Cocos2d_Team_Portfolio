#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"
#include "Monster.h"

class HeroControl : Scene
{
	SpriteFrameCache* cache; // ĳ��
	Hero* _hero; // ����� ��ü
	HeroUnit* _heroUnit; // ����� ���ְ�ü
	vector<HeroUnit*> _heroUnitVec; // ����

	EventListenerTouchOneByOne* listener;

	Layer* _layer; // �����,����,���� ���̾�

	Scene* _scene;
	Sprite* _leftButton; // ����Move��ư
	Sprite* _rightButton; // ������Move��ư
	Sprite* _mainDashbord; // �뽬����
	Sprite* _mainDashbordCase; // �뽬���� ���̽�
	Sprite* _skillOneButton; // ��ų 1 ��ư
	Sprite* _skillTwoButton; // ��ų 2 ��ư
	Sprite* _skillThreeButton; // ��ų 3 ��ư
	Sprite* _mouseSummonsButton; // ���� ��ȯ ��ư
	Sprite* _mouseSummonsButtonDisable; // ���� ��ȯ ��ư(Ÿ�̸�)
	Sprite* _bearSummonsButton; // �� ��ȯ ��ư
	Sprite* _bearSummonsButtonDisable; // �� ��ȯ ��ư(Ÿ�̸�)
	Sprite* _kangarooSummonsButton; // Ļ�ŷ� ��ȯ ��ư
	Sprite* _kangarooSummonsButtonDisable; // Ļ�ŷ� ��ȯ ��ư(Ÿ�̸�)
	Sprite* _unitLock1; // ��� ���� ��ư
	Sprite* _unitLock2; // ��� ���� ��ư
	Sprite* _unitLock3; // ��� ���� ��ư
	Sprite* _unitLock4; // ��� ���� ��ư
	Sprite* _unitLock5; // ��� ���� ��ư
	Sprite* _unitLock6; // ��� ���� ��ư
	Sprite* _meatIcon; // ��������
	Sprite* _manaIcon; // ����������
	Sprite* _meatBackGround; // ���,���� ������ ���(����)
	Sprite* _hpInfoLayout; // ü������(����߾�)
	Sprite* _hpInfoBack; // ü���������(����)
	Sprite* _expBar; // ����ġ��
	Sprite* _expBarBack; // ����ġ�ٹ��(����)

	Label* _currentMeat;
	Label* _MaxMeat;
	Label* _currentMana;
	Label* _MaxMana;

	ProgressTimer* _mouseSummonsTimer;
	ProgressTimer* _bearSummonsTimer;
	ProgressTimer* _kangarooSummonsTimer;

	float _mouseSummonsCollTime;
	float _mouseSummonsMaxCollTime;
	float _bearSummonsCollTime;
	float _bearSummonsMaxCollTime;
	float _kangarooSummonsCollTime;
	float _kangarooSummonsMaxCollTime;

	bool _right;
	bool _left;

	bool _skillOneClick;
	bool _skillTwoClick;
	bool _skillThreeClick;

	bool _mouseSummonsClick;
	bool _bearSummonsClick;
	bool _kangarooSummonsClick;

	bool _mouseSummonsButtonActivation;
	bool _bearSummonsButtonActivation;
	bool _kangarooSummonsButtonActivation;

public:
	HeroControl(Scene* scene, Hero* hero, Layer* layer);
	//void UnitMove();
	void HeroMove();
	void HeroManaRegen();
	void HeroMeatRegen();
	void UnitVecErase();
	void UnitZorder();
	void CoolTime();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	vector<HeroUnit*> getHeroUnitVec() { return _heroUnitVec; }
};