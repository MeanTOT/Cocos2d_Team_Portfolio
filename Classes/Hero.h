#pragma once
#include "cocos_framework.h"

enum INFO
{
	Waiting = 0,
	Walking,
	Attack,
};

enum Movement
{
	RightWay = 10,
	LeftWay,
};

class Hero
{
private:
	SpriteFrameCache* cache;

	Animation* _animation1; // ��� Action
	Animate* _animate1; // ��� Action

	Animation* _animation2; // Walk Action
	Animate* _animate2;	// Walk Action
	RepeatForever* _heroWaitingAction; // Walk Action
	RepeatForever* _heroWalkingAction; // Walk Action

	Animation* _animation3; // ���� Action
	Animate* _animate3; // ���� Action

	Sprite* _hero; // ����� ��������Ʈ
	ProgressTimer* _manaGauge; // ���� ������
	ProgressTimer* _meatGauge; // ��� ������

	ProgressTimer* _hpInfoGauge; // ����� ü�¹�(�߾ӻ��)
	ProgressTimer* _MonsterBaseHpGauge; // ���� ���̽� ü�¹�(�߾ӻ��)

	Movement _movement; // ���� �÷��̾ �����ִ� ����

	float _speed; // ���ǵ�
	float _lv; // ����
	float _hp; // ü��
	float _maxhp; // �ִ�ü��
	float _mana; // ���� ������
	float _maxmana; // �ִ븶��
	float _manaRegenSpeed; // ���� ���� ���ǵ�
	float _meat; // ���� ��ⷮ
	float _maxmeat; // �ִ� ��ⷮ
	float _meatRegenSpeed; // ��� ���� ���ǵ�
	float _gold; // ���
	float _exp; // ����ġ
	float _maxExp; // �ִ����ġ

	float _skillOneManaUse; // ��ų 1 ���� �Һ�
	float _skillTwoManaUse; // ��ų 2 ���� �Һ�
	float _skillThreeManaUse; // ��ų 3 ���� �Һ�

public:

	Hero(Scene* scene, Layer* layer);
	Movement getMoveWay() { return _movement; }
	void setMoveWay(Movement movement) { _movement = movement; }
	Sprite* getHero() { return _hero; }
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	float getHp() { return _hp; }
	void setHp(float hp) { _hp = hp; }
	float getMaxHp() { return _maxhp; }
	void setMaxHp(float maxhp) { _maxhp = maxhp; }
	float getMana() { return _mana; }
	void setMana(float mana) { _mana = mana; }
	float getMaxMana() { return _maxmana; }
	void setMaxMana(float maxmana) { _maxmana = maxmana; }
	float getGold() { return _gold; }
	void setGold(float gold) { _gold = gold; }
	float getExp() { return _exp; }
	void setExp(float exp) { _exp = exp; }
	float getMaxExp() { return _maxExp; }
	void setMaxExp(float maxexp) { _maxExp = maxexp; }
	float getManaRegenSpeed() { return _manaRegenSpeed; }
	void setManaRegenSpeed(float manaregenspeed) { _manaRegenSpeed = manaregenspeed; }
	float getMeat() { return _meat; }
	void setMeat(float meat) { _meat = meat; }
	float getMaxMeat() { return _maxmeat; }
	void setMaxMeat(float maxmeat) { _maxmeat = maxmeat; }
	float getMeatRegenSpeed() { return _meatRegenSpeed; }
	void setMeatRegenSpeed(float meatregenspeed) { _meatRegenSpeed = meatregenspeed; }
	float getSkillOneManaUse() { return _skillOneManaUse; }
	void setSkillOneManaUse(float skillonemanause) { _skillOneManaUse = skillonemanause; }
	float getSkillTwoManaUse() { return _skillTwoManaUse; }
	void setSkillTwoManaUse(float skilltwomanause) { _skillTwoManaUse = skilltwomanause; }
	float getSkillThreeManaUse() { return _skillThreeManaUse; }
	void setSkillThreeManaUse(float skillthreemanause) { _skillThreeManaUse = skillthreemanause; }
	float getLv() { return _lv; }
	void setLv(float lv) { _lv = lv; }
	ProgressTimer* getManaGauge() { return _manaGauge; }
	ProgressTimer* getMeatGauge() { return _meatGauge; }
	ProgressTimer* getHeroHpInfo() { return _hpInfoGauge; }
	ProgressTimer* getMonsterBaseInfo() { return _MonsterBaseHpGauge; }
	RepeatForever* getWaitingAction() { return _heroWaitingAction; }
	RepeatForever* getWalkingAction() { return _heroWalkingAction; }
	Animate* getAttackAction() { return _animate3; }
};