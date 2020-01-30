#pragma once
#include "cocos_framework.h"

class Monster;

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
	HammerMissile,
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
	static Hero* Instance;
	Hero();
	~Hero() {}

	SpriteFrameCache* cache;

	vector<Sprite*> HeroInventoryVec; // ����� �κ��丮

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

	Animation* _animation13; // �ķ���ġ ��� �׼�
	Animate* _animate13; // �ķ���ġ ��� �׼�
	RepeatForever* _heroBuffOraRepeat; // �ķ���ġ ��� �׼�

	Sprite* _hero; // ����� ��������Ʈ
	Sprite* _heroWeapon1; // ����ġ
	Sprite* _skillEffectBox1; // ��ųA ����Ʈ�� ������ �ڽ�
	Sprite* _skillEffectBox2; // ��ųB ����Ʈ�� ������ �ڽ�
	Sprite* _skillEffectBox3; // ��ųC ����Ʈ�� ������ �ڽ�
	Sprite* _heroBuffOra;

	ProgressTimer* _manaGauge; // ���� ������
	ProgressTimer* _meatGauge; // ��� ������
	ProgressTimer* _hpInfoGauge; // ����� ü�¹�(�߾ӻ��)
	ProgressTimer* _MonsterBaseHpGauge; // ���� ���̽� ü�¹�(�߾ӻ��)
	ProgressTimer* _expGauge; // ���� ���̽� ü�¹�(�߾ӻ��)

	Movement _movement; // ���� �÷��̾ �����ִ� ����
	HAMMERKIND _HammerKind;

	// ����� ����
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

	bool IsHealing;

	bool _skillOneUnlock;
	bool _skillTwoUnlock;
	bool _skillThreeUnlock;

	bool _unitOneUnlock;
	bool _unitTwoUnlock;
	bool _unitThreeUnlock;

	bool _stageStart;


	// ��������
	float _mouseHp; // ü��
	float _mouseMaxHP; // �ִ�ü��
	float _mouseAtk; // �Ϲݰ��ݷ�
	float _mouseAtk2; // �����ݷ�
	float _mouseSpeed; // ���ǵ�

	float _bearHp; // ü��
	float _bearMaxHP; // �ִ�ü��
	float _bearAtk; // �Ϲݰ��ݷ�
	float _bearAtk2; // �����ݷ�
	float _bearSpeed; // ���ǵ�

	float _kangarooHp; // ü��
	float _kangarooMaxHP; // �ִ�ü��
	float _kangarooAtk; // �Ϲݰ��ݷ�
	float _kangarooAtk2; // �����ݷ�
	float _kangarooSpeed; // ���ǵ�


public:
	static Hero* getInstance();
	static void releaseInstance();
	void createHeroInfo(Scene* scene, Layer* layer);

	vector<Sprite*> getHeroInventoryVec() { return HeroInventoryVec; } // ����� �κ��丮 ���Լ�

	Movement getMoveWay() { return _movement; }
	void setMoveWay(Movement movement) { _movement = movement; }
	Sprite* getHero() { return _hero; }
	Sprite* getWeapon1() { return _heroWeapon1; }
	Sprite* getSkillEffectBox1() { return _skillEffectBox1; }
	Sprite* getSkillEffectBox2() { return _skillEffectBox2; }
	Sprite* getSkillEffectBox3() { return _skillEffectBox3; }
	Sprite* getHeroBuffOra() { return _heroBuffOra; }
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
	bool getIsHealing() { return IsHealing; }
	void setIsHealing(bool ishealing) { IsHealing = ishealing; }
	bool getSkillOneUnlock() { return _skillOneUnlock; }
	void setSkillOneUnlock(bool skilloneunlock) { _skillOneUnlock = skilloneunlock; }
	bool getSkillTwoUnlock() { return _skillTwoUnlock; }
	void setSkillTwoUnlock(bool skilltwounlock) { _skillTwoUnlock = skilltwounlock; }
	bool getSkillThreeUnlock() { return _skillThreeUnlock; }
	void setSkillThreeUnlock(bool skillthreeunlock) { _skillThreeUnlock = skillthreeunlock; }
	bool getUnitOneUnlock() { return _unitOneUnlock; }
	void setUnitOneUnlock(bool unitoneunlock) { _unitOneUnlock = unitoneunlock; }
	bool getUnitTwoUnlock() { return _unitTwoUnlock; }
	void setUnitTwoUnlock(bool unittwounlock) { _unitTwoUnlock = unittwounlock; }
	bool getUnitThreeUnlock() { return _unitThreeUnlock; }
	void setUnitThreeUnlock(bool unitthreeunlock) { _unitThreeUnlock = unitthreeunlock; }
	bool getStageStart() { return _stageStart; }
	void setStageStart(bool stagestart) { _stageStart = stagestart; }
	ProgressTimer* getManaGauge() { return _manaGauge; }
	ProgressTimer* getMeatGauge() { return _meatGauge; }
	ProgressTimer* getHeroHpInfo() { return _hpInfoGauge; }
	ProgressTimer* getMonsterBaseInfo() { return _MonsterBaseHpGauge; }
	ProgressTimer* getExpGauge() { return _expGauge; }
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

	//���� ���� getset �Լ�
	float getMouseHp() { return _mouseHp; }
	void setMouseHp(float hp) { _mouseHp = hp; }
	float getMouseMaxHp() { return _mouseMaxHP; }
	void setMouseMaxHp(float maxhp) { _mouseMaxHP = maxhp; }
	float getMouseAtk() { return _mouseAtk; }
	void setMouseAtk(float atk) { _mouseAtk = atk; }
	float getMouseAtk2() { return _mouseAtk2; }
	void setMouseAtk2(float atk2) { _mouseAtk2 = atk2; }
	float getMouseSpeed() { return _mouseSpeed; }
	void setMouseSpeed(float speed) { _mouseSpeed = speed; }


	float getBearHp() { return _bearHp; }
	void setBearHp(float hp) { _bearHp = hp; }
	float getBearMaxHp() { return _bearMaxHP; }
	void setBearMaxHp(float maxhp) { _bearMaxHP = maxhp; }
	float getBearAtk() { return _bearAtk; }
	void setBearAtk(float atk) { _bearAtk = atk; }
	float getBearAtk2() { return _bearAtk2; }
	void setBearAtk2(float atk2) { _bearAtk2 = atk2; }
	float getBearSpeed() { return _bearSpeed; }
	void setBearSpeed(float speed) { _bearSpeed = speed; }


	float getKangarooHp() { return _kangarooHp; }
	void setKangarooHp(float hp) { _kangarooHp = hp; }
	float getKangarooMaxHp() { return _kangarooMaxHP; }
	void setKangarooMaxHp(float maxhp) { _kangarooMaxHP = maxhp; }
	float getKangarooAtk() { return _kangarooAtk; }
	void setKangarooAtk(float atk) { _kangarooAtk = atk; }
	float getKangarooAtk2() { return _kangarooAtk2; }
	void setKangarooAtk2(float atk2) { _kangarooAtk2 = atk2; }
	float getKangarooSpeed() { return _kangarooSpeed; }
	void setKangarooSpeed(float speed) { _kangarooSpeed = speed; }
};