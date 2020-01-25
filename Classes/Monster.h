#pragma once
#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"

enum Mob {
	�Ϲݹ̶�,
	��������,
	�Ϲ�����,
	��ũ�̶�,
	��ȭ����,
	����ŷ
};

class Monster : Scene
{
	enum STATE {
		WALK, //�̵�
		ATTACK, //����
		DEAD //����
	};

	Scene* _scene;
	Layer* _layer;
	Hero* _hero;
	vector<HeroUnit*> _unit;

	SpriteFrameCache* cache;

	Sprite* _monster;
	Sprite* _summon;

	ProgressTimer* _monsterHpBar;
	Sprite* _monsterHpBarBack;

	char* _monsterCode; //���� Ű��
	STATE _state; //���� ���°�

	bool _moveChange;

	int _atkMaxFrame; //���� ��� �ִ� ������ ��

	float _hpm, _hp; //���� �ִ� ü��, ���� ü��
	float _atk; //���� ���ݷ�
	float _speed; //���� �̵��ӵ�
	float _delay; //���� ���ݼӵ�
	float _range; //���� ���ݹ���
	int _time;
	int _exp; //���� óġ �� ȹ�� ����ġ
	int _money; //���� óġ �� ȹ�� �Ӵ�

	int _isAttackDelay;//���ݵ����� üũ
	bool _isRemove; //���� ����
	float _isSummonX; //���� ��ȯ��ǥ
	int _unitAttack; //������ ���� ��ȣ

public:
	Monster(Scene* scene, Layer* layer, Hero* hero, vector<HeroUnit*> unit, Mob mob);

	void MonsterMove();
	void Hit(float atk); //�Ű� ������ ���ݷ� ����
	void setSummunPositionX(float x);
	void setUnit(vector<HeroUnit*> unit) { _unit = unit; }
	void setUnitAttack() { _unitAttack = -1; }
	int getUnitAttack() { return _unitAttack; }

	Sprite* getMonster() { return _monster; }
	int getUnitSize() { return _unit.size(); }
	float getHp() { return _hp; }
	float getAtk() { return _atk; }
	float getRange() { return _range; }
	int getExp() { return _exp; }
	int getMoney() { return _money; }

	bool getIsRemove() { return _isRemove; }
	float getIsSummon() { return _isSummonX; }

private:
	void Walk(); //���� �̵�
	void Attack(); //���� ����
	void ZomkingSummon(); //����ŷ ��ȯ��
	void ZomkingSummonRemove(); //����ŷ ��ȯ�� ����
	void Dead(); //���� ����
};