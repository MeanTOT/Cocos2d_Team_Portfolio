#pragma once
#include "cocos_framework.h"

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

	SpriteFrameCache* cache;

	Sprite* _monster;
	char* _monsterCode; //���� Ű��
	STATE _state; //���� ���°�

	bool _moveChange;

	int _atkMaxFrame; //���� ��� �ִ� ������ ��

	float _hpm, _hp; //���� �ִ� ü��, ���� ü��
	float _speed; //���� �̵��ӵ�
	float _delay; //���� ���ݼӵ�
	float _range; //���� ���ݹ���
	int _exp; //���� óġ �� ȹ�� ����ġ
	int _money; //���� óġ �� ȹ�� �Ӵ�

	bool _isAttack; //���� ����
	bool _isRemove; //���� ����

public:
	Monster(Scene* scene, Mob mob);
	
	void MonsterMove();
	void Hit(int atk); //�Ű� ������ ���ݷ� ����
	void Walk(); //���� �̵�
	void Attack(); //���� ����	
	void Dead(); //���� ����

	Sprite* getMonster() { return _monster; }
	float getHp() { return _hp; }
	float getRange() { return _range; }
	int getExp() { return _exp; }
	int getMoney() { return _money; }
	
	bool getIsAttack() { return _isAttack; }
	bool getIsRemove() { return _isRemove; }
};