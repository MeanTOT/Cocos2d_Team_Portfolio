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

enum HAMMERINFO
{
	HammerWaiting = 20,
	HammerWalking,
	HammerAttack,
	HammerSkillEffect1,
	HammerSkillEffect2,
	HammerSkillEffect3,
};

enum HAMMERKIND
{
	����ġ = 1582,
	ȸ����ġ,
	�ķ���ġ,
};

class Hero
{
private:
	SpriteFrameCache* cache;

	Animation* _animation1; // ����� ��� �׼�
	Animate* _animate1; // ����� ��� �׼�
	RepeatForever* _heroWaitingAction; // ����� ��� �׼�

	Animation* _animation2; // ����� �ȱ� �׼�
	Animate* _animate2;	// ����� �ȱ� �׼�
	RepeatForever* _heroWalkingAction; // ����� �ȱ� �׼�

	Animation* _animation3; // ����� ���� �׼�
	Animate* _animate3; // ����� ���� �׼�

	Animation* _animation4; // ����ġ ��� �׼�
	Animate* _animate4; // ����ġ ��� �׼�
	RepeatForever* _hammerWaitingAction1; // ����ġ ��� �׼�

	Animation* _animation5; // ����ġ �ȱ� �׼�
	Animate* _animate5; // ����ġ �ȱ� �׼�
	RepeatForever* _hammerWalkingAction1; // ����ġ �ȱ� �׼�

	Animation* _animation6; // ����ġ ���� �׼�
	Animate* _animate6; // ����ġ ���� �׼�

	Animation* _hammerSkillEffectAnimation_A1; // ����ġ ��ų ����ƮA
	Animate* _hammerSkillEffectAnimate_A1; // ����ġ ��ų ����ƮA

	Animation* _animation7; // ȸ����ġ ��� �׼�
	Animate* _animate7; // ȸ����ġ ��� �׼�
	RepeatForever* _hammerWaitingAction2; // ȸ����ġ ��� �׼�

	Animation* _animation8; // ȸ����ġ �ȱ� �׼�
	Animate* _animate8; // ȸ����ġ �ȱ� �׼�
	RepeatForever* _hammerWalkingAction2; // ȸ����ġ �ȱ� �׼�

	Animation* _animation9; // ȸ����ġ ���� �׼�
	Animate* _animate9; // ȸ����ġ ���� �׼�

	Animation* _hammerSkillEffectAnimation_A2; // ȸ����ġ ��ų ����ƮA
	Animate* _hammerSkillEffectAnimate_A2; // ȸ����ġ ��ų ����ƮA

	Animation* _hammerSkillEffectAnimation_B2; // ȸ����ġ ��ų ����ƮB
	Animate* _hammerSkillEffectAnimate_B2; // ȸ����ġ ��ų ����ƮB

	Animation* _hammerSkillEffectAnimation_C2; // ȸ����ġ ��ų ����ƮC
	Animate* _hammerSkillEffectAnimate_C2; // ȸ����ġ ��ų ����ƮC

	Animation* _animation10; // �ķ���ġ ��� �׼�
	Animate* _animate10; // �ķ���ġ ��� �׼�
	RepeatForever* _hammerWaitingAction3; // �ķ���ġ ��� �׼�

	Animation* _animation11; // �ķ���ġ �ȱ� �׼�
	Animate* _animate11; // �ķ���ġ �ȱ� �׼�
	RepeatForever* _hammerWalkingAction3; // �ķ���ġ �ȱ� �׼�

	Animation* _animation12; // �ķ���ġ ���� �׼�
	Animate* _animate12; // �ķ���ġ ���� �׼�

	Animation* _hammerSkillEffectAnimation_A3; // �ķ���ġ ��ų ����ƮA
	Animate* _hammerSkillEffectAnimate_A3; // �ķ���ġ ��ų ����ƮA

	Sprite* _hero; // ����� ��������Ʈ
	Sprite* _heroWeapon1; // ����ġ
	Sprite* _skillEffectBox1; // ��ųA ����Ʈ�� ������ �ڽ�
	Sprite* _skillEffectBox2; // ��ųB ����Ʈ�� ������ �ڽ�
	Sprite* _skillEffectBox3; // ��ųC ����Ʈ�� ������ �ڽ�

	ProgressTimer* _manaGauge; // ���� ������
	ProgressTimer* _meatGauge; // ��� ������
	ProgressTimer* _hpInfoGauge; // ����� ü�¹�(�߾ӻ��)
	ProgressTimer* _MonsterBaseHpGauge; // ���� ���̽� ü�¹�(�߾ӻ��)

	Movement _movement; // ���� �÷��̾ �����ִ� ����
	HAMMERKIND _HammerKind;

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
	Sprite* getWeapon1() { return _heroWeapon1; }
	Sprite* getSkillEffectBox1() { return _skillEffectBox1; }
	Sprite* getSkillEffectBox2() { return _skillEffectBox2; }
	Sprite* getSkillEffectBox3() { return _skillEffectBox3; }
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
	
	HAMMERKIND getHammerKind() { return _HammerKind; }
	void setHammerKind(HAMMERKIND hammerkind) { _HammerKind = hammerkind; }

	RepeatForever* HammerWaitingAction(HAMMERKIND hammerkind);
	RepeatForever* HammerWalkingAction(HAMMERKIND hammerkind);
	Animate* HammerAttackAction(HAMMERKIND hammerkind);
	Animate* HammerAttackEffectA(HAMMERKIND hammerkind);
	Animate* HammerAttackEffectB(HAMMERKIND hammerkind);
	Animate* HammerAttackEffectC(HAMMERKIND hammerkind);
};