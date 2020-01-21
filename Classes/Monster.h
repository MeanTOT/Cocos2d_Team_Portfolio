#pragma once
#include "cocos_framework.h"
#include "Hero.h"

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
	Monster(Scene* scene, Hero* hero, Mob mob);

	void MonsterMove();
	void Hit(float atk); //�Ű� ������ ���ݷ� ����
	void setSummunPositionX(float x);

	Sprite* getMonster() { return _monster; }
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