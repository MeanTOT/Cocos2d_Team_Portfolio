#pragma once
#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"

enum Mob {
	�ȴ�����,
	��ȫ�̶�,
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
	Hero* _hero;
	vector<HeroUnit*> _unit;

	SpriteFrameCache* cache;

	Sprite* _monster;
	Sprite* _summon;

	char* _monsterCode; //���� Ű��
	STATE _state; //���� ���°�

	bool _moveChange;

	int _atkMaxFrame; //���� ��� �ִ� ������ ��

	float _hpm, _hp; //���� �ִ� ü��, ���� ü��
	float _atk; //���� ���ݷ�
	float _speed; //���� �̵��ӵ�
	float _delay; //���� ���ݼӵ�
	float _range; //���� ���ݹ���
	int _exp; //���� óġ �� ȹ�� ����ġ
	int _money; //���� óġ �� ȹ�� �Ӵ�

	bool _isRemove; //���� ����
	float _isSummonX; //���� ��ȯ��ǥ

public:
	Monster(Scene* scene, Hero* hero, vector<HeroUnit*> unit, Mob mob);

	void MonsterMove();
	void Hit(float atk); //�Ű� ������ ���ݷ� ����
	void setSummunPositionX(float x);
	void setUnit(vector<HeroUnit*> unit) { _unit = unit; }

	Sprite* getMonster() { return _monster; }
	int getUnitSize() { return _unit.size(); }
	float getHp() { return _hp; }
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