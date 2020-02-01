#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"
#include "Monster.h"
#include "Dungeon.h"
#include "MissileCollision.h"
#include "ShopScene.h"

class HeroControl : Scene
{
	SpriteFrameCache* cache; // ĳ��
	HeroUnit* _heroUnit; // ����� ���ְ�ü
	Dungeon* _dungeon; // ���� ����ü�� ������������ؼ�
	MissileCollision* _missileCollision;
	vector<HeroUnit*> _heroUnitVec; // ���� ����
	vector<MissileCollision*> _missileCollisionVec; // �̻��� ����

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
	Sprite* _goldIcon; // ��� ������
	Sprite* _pauseButton; // ������ư
	Sprite* _miniMapPointer; // �̴ϸ� ������

	Sprite* NextButton; // Ŭ����� �������� �ؽ�Ʈ ��ư

	Sprite* _levelUpBlackDot; // ������ ȿ��
	Sprite* _levelUpText; // ������ �ؽ�Ʈ
	Sprite* _levelUpWingL;
	Sprite* _levelUpWingR;

	Sprite* _pauseBack;
	Sprite* _pauseBord;
	Sprite* _pauseText;
	Sprite* _pauseQuitButton;
	Sprite* _pauseResumeButton;

	Animation* _miniMapPointerAnimation;
	Animate* _miniMapPointerAnimate;
	RepeatForever* _miniMapPointerRepeat;

	Label* _currentMeat;
	Label* _MaxMeat;
	Label* _currentMana;
	Label* _MaxMana;
	Label* _Level;
	Label* _Gold;
	Label* _SkillOneManaUse;
	Label* _SkillTwoManaUse;
	Label* _SkillThreeManaUse;

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

	bool _PauseClick;

	bool _UnitActiveSoundBool;
	bool _UnitActiveSoundBool2;
	bool _UnitActiveSoundBool3;

	// ����
	int _audioId1; // ����� �ȱ�
	int _audioUnitActive; // ���� ��ȯ��ư Ȱ��ȭ
	int _audioUnitSommons; // ���� ��ȯ��ư ����

public:
	HeroControl(Scene* scene, Layer* layer, Dungeon* dungeon);
	void HeroMove(Dungeon* dungeon);
	void HeroManaRegen();
	void HeroMeatRegen();
	void UnitVecErase();
	void CoolTime();
	void SkillEffectVisible();
	void MiniMap();
	void LevelUp();
	void SetLevelUpImage();
	void UnitBuff();
	void NextButtonVisible();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	vector<HeroUnit*> getHeroUnitVec() { return _heroUnitVec; }
	vector<MissileCollision*> getMissileCollisionVec() { return _missileCollisionVec; }
};