#pragma once

#include "cocos_framework.h"
class Monster;


enum UnitKind
{
	���� = 100,
	��,
	Ļ�ŷ�,
};

enum UnitAction
{
	UnitWalk = 50,
	UnitAttack1,
	UnitAttack2,
	UnitDead,
	UnitCollision,
};

class HeroUnit
{
	SpriteFrameCache* cache;

	vector<HeroUnit*> _unitVec; // ����

	Sprite* _UnitSprite; // ���ֽ�������Ʈ

	float _Hp; // ü��
	float _Atk; // ���ݷ�
	float _Speed; // ���ǵ�
	UnitKind _unitKind; // ��������
	UnitAction _unitAction;
	HeroUnit* _heroUnit; // ���ְ�ü

	// Walk �׼�
	Animation* _animation1;
	Animate* _animate1;
	RepeatForever* _walkAction;

	// Attak �׼�
	Animation* _animation2;
	Animate* _animate2;

	// Dead �׼�
	Animation* _animation3;
	Animate* _animate3;

	vector<Monster*> _monsterVec;

public:
	HeroUnit(Scene* scene, UnitKind herokind, Layer* layer);

	vector<HeroUnit*> getUnitVec() { return _unitVec; }
	UnitKind getHeroKind() { return _unitKind; }
	UnitAction getUnitAction() { return _unitAction; }
	void setUnitAction(UnitAction unitaction) { _unitAction = unitaction; }
	RepeatForever* getWalkAction() { return _walkAction; }
	Animate* getAttackAction() { return _animate2; }
	Animate* getDeadAction() { return _animate3; }
	Sprite* getSprite() { return _UnitSprite; }
	void setSprite(Sprite* pSprite) { _UnitSprite = pSprite; }
	float getHp() { return _Hp; }
	void setHp(float hp) { _Hp = hp; }
	float getAtk() { return _Atk; }
	void setAtk(float atk) { _Atk = atk; }
	float getSpeed() { return _Speed; }
	void setSpeed(float speed) { _Speed = speed; }

	void BringMonsterVec(vector<Monster*> monstervec);
	void UnitMove();
	void HeroUnit_VS_MonsterUnit();

};