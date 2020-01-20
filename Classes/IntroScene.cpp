#include "IntroScene.h"

Scene* IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }
  
  _introBg = new (std::nothrow) IntroBg;
  _introBg->Set15Age(this);
  
  this->scheduleOnce(schedule_selector(IntroScene::changeBg15AgeToVolcano), 3);

  return true;
}

void IntroScene::onEnter() {
  Scene::onEnter();

  _listener = EventListenerTouchOneByOne::create();
  _listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
  _listener->onTouchEnded = CC_CALLBACK_2(IntroScene::onTouchEnded, this);
  _listener->setSwallowTouches(true);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void IntroScene::onExit() {
  _eventDispatcher->removeEventListener(_listener);
  
  Scene::onExit();
}

bool IntroScene::onTouchBegan(Touch * touch, Event * event) {
  return false;
}

void IntroScene::onTouchEnded(Touch * touch, Event * event) {
}

void IntroScene::changeBg15AgeToVolcano(float time) {
  this->removeChild(_introBg->Get15Age());

  _introBg->SetTitleVolcano(this);
  _introBg->SetTitleSky(this);
  _introBg->SetTitleVolcanoCloud(this);

  _introBg->SetTitleDarkCloud(this);
  _introBg->GetTitleDarkCloud()->
    runAction(_introBg->GetTitleDarkCloudAction());

  _introBg->SetTitleDarkCloud2(this);
  _introBg->GetTitleDarkCloud2()->
    runAction(_introBg->GetTitleDarkCloud2Action());

  _introBg->SetTitleMountain(this);
  _introBg->SetTitleMountain2(this);

  _introBg->SetTitleWood(this);

  _introUI = new (std::nothrow) IntroUI(this); // UI ��ü �߰�
  _introUI->SetTitleLogo(this); // �ȶ� �ΰ�
  _introUI->SetTitleBtnNewgameUp(this); // PLAY ��ư
  _introUI->SetTitleBtnInfoUp(this); // ���� ��ư
}