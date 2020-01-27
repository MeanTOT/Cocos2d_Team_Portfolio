#pragma once

#include "cocos_framework.h"
#include "Dungeon.h"
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
	UnitSoul,
};

class HeroUnit
{
	SpriteFrameCache* cache;

	Layer* _layer;

	Dungeon* _dungeon;

	vector<HeroUnit*> _unitVec; // ����

	Sprite* _UnitSprite; // ���ֽ�������Ʈ
	Sprite* _UnitDeadAnimateBox; // ��ȥ �ִϸ��̼� ���� ��������Ʈ
	Sprite* _hitAnimationBox; // ��Ʈ �ִϸ��̼� ���� ��������Ʈ
	Sprite* _unitBuffOra;

	float _Hp; // ü��
	float _maxHP;
	float _Atk; // ���ݷ�
	float _Atk2;
	float _Speed; // ���ǵ�
	float _AtkSpeed; // ���� ���� ���ǵ�
	float _MaxAtkSpeed; // �ִ� ���� ���ǵ�
	float _Range; // ��Ÿ�
	bool _Dead; // ���翩��
	bool _FirstAtk;
	int _Zorder; // ��Ʈ����

	bool _buff;

	UnitKind _unitKind; // ��������
	UnitAction _unitAction; // �������־׼�
	HeroUnit* _heroUnit; // ���ְ�ü

	// Walk �׼�
	Animation* _animation1;
	Animate* _animate1;
	RepeatForever* _walkAction;

	// Attak(�����) �׼�
	Animation* _animation2;
	Animate* _animate2;

	// Attak(������) �׼�
	Animation* _animation2_1;
	Animate* _animate2_1;

	// Dead �׼�
	Animation* _animation3;
	Animate* _animate3;

	// ������ ��ȥ �ִϸ��̼�
	Animation* _animation4; 
	Animate* _animate4;

	Animation* _animation5;
	Animate* _animate5;
	RepeatForever* _unitBuffOraRepeat;

	// ��Ʈ�ִϸ��̼�
	Animation* _UnitHitAnimation1;
	Animate* _UnitHitAnimate1;

	Animation* _UnitHitAnimation2;
	Animate* _UnitHitAnimate2;

	//RepeatForever* AttackAct;
	Sequence* AttackAct;
	Sequence* DeadAct;

	ProgressTimer* _HeroUnitHpBar;
	Sprite* _HeroUnitHpBarBack;

	vector<Monster*> _monsterVec;

public:
	HeroUnit(Scene* scene, UnitKind herokind, Layer* layer, Dungeon* dungeon);
	vector<HeroUnit*> getUnitVec() { return _unitVec; }
	UnitKind getHeroKind() { return _unitKind; }
	UnitAction getUnitAction() { return _unitAction; }
	void setUnitAction(UnitAction unitaction) { _unitAction = unitaction; }
	RepeatForever* getWalkAction() { return _walkAction; }
	Animate* getAttackAction() { return _animate2; }
	Animate* getDeadAction() { return _animate3; }
	Sprite* getSprite() { return _UnitSprite; }
	Sprite* getUnitBuffOra() { return _unitBuffOra; }
	void setSprite(Sprite* pSprite) { _UnitSprite = pSprite; }
	float getHp() { return _Hp; }
	void setHp(float hp) { _Hp = hp; }
	float getAtk() { return _Atk; }
	void setAtk(float atk) { _Atk = atk; }
	float getAtk2() { return _Atk2; }
	void setAtk2(float atk2) { _Atk2 = atk2; }
	float getSpeed() { return _Speed; }
	void setSpeed(float speed) { _Speed = speed; }
	int getZorder() { return _Zorder; }
	void setZorder(int zorder) { _Zorder = zorder; }
	bool getDead() { return _Dead; }
	void setDead(bool dead) { _Dead = dead; }
	bool getBuff() { return _buff; }
	void setBuff(bool buff) { _buff = buff; }

	ProgressTimer* getUnitHpBar() { return _HeroUnitHpBar; }
	Sprite* getUnitHpBarBack() { return _HeroUnitHpBarBack; }

	void BringMonsterVec(vector<Monster*> monstervec);
	void UnitMove();
	void UnitCollisionCheck();
	void UnitAttack();
	void UnitHeavyAttack();
	void UnitDeadCheck();
	void ShowUnitHpBar();
	void ShowUnitDeadSoul();
	void Healing();

};