#include "IntroScene.h"
#include "MapMindForest.h"

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
  auto touchPoint = touch->getLocation();

  bool touchPlay = _introUI->GetTitleBtnNewgameUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchPaladog = _introUI->GetHeroPaladogUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchCampaign = _introUI->GetBtnCampaignUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchExit = _introUI->GetBtnExitUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchDataSlot = _introUI->GetDataSlot()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchStart = _introUI->GetBtnSlotStartUp()->
    getBoundingBox().containsPoint(touchPoint);

  // Play ��ư Ŭ��
  if (touchPlay && !_isPlay) {
    _introUI->GetModeSelectBox()->setVisible(true);
    _introUI->GetTxtHeroSelect()->setVisible(true);
    _introUI->GetHeroPaladogUp()->setVisible(true);
    _introUI->GetHeroDarkdogUp()->setVisible(true);

    _isPlay = true;
  }

  // �ȶ� ��ư Ŭ��
  else if (_isPlay && touchPaladog && !_isPaladog) {
    _introUI->GetHeroDarkdogUp()->setVisible(false);
    _introUI->GetBtnCampaignUp()->setVisible(true);
    _introUI->GetBtnCampaignUp()->
      runAction(RotateBy::create(1, Vec3(0, 180, 0)));
    _introUI->GetBtnSurvivalUp()->setVisible(true);
    _introUI->GetBtnSurvivalUp()->
      runAction(RotateBy::create(1, Vec3(0, 180, 0)));

    _isPaladog = true;
  }

  // Play ��ư Ŭ�� �� ��� Ŭ��
  if (_isPlay && !_isPaladog && !touchCampaign && !touchPaladog &&
      !_isCampaign) {
    _introUI->GetModeSelectBox()->setVisible(false);
    _introUI->GetTxtHeroSelect()->setVisible(false);
    _introUI->GetHeroPaladogUp()->setVisible(false);
    _introUI->GetHeroDarkdogUp()->setVisible(false);
    _introUI->GetBtnCampaignUp()->setVisible(false);
    _introUI->GetBtnSurvivalUp()->setVisible(false);
    _introUI->GetTitleBtnNewgameUp()->setVisible(true);
    _introUI->GetTitleBtnInfoUp()->setVisible(true);

    _isPlay = false;
    _isPaladog = false;

  } else if (_isPaladog && (!touchCampaign && !touchPaladog && !_isCampaign)) {
    _introUI->GetHeroDarkdogUp()->setVisible(true);
    _introUI->GetBtnCampaignUp()->setVisible(false);
    _introUI->GetBtnSurvivalUp()->setVisible(false);

    _isPlay = true;
    _isPaladog = false;
  }

  // ķ���� ��ư Ŭ��
  if (_isPaladog && touchCampaign && !_isCampaign) {
    _introUI->GetModeSelectBox()->setVisible(false);
    _introUI->GetTxtHeroSelect()->setVisible(false);
    _introUI->GetHeroPaladogUp()->setVisible(false);
    _introUI->GetHeroDarkdogUp()->setVisible(false);
    _introUI->GetTitleLogo()->setVisible(false);
    _introUI->GetTitleBtnNewgameUp()->setVisible(false);
    _introUI->GetTitleBtnInfoUp()->setVisible(false);
    _introUI->GetBtnCampaignUp()->setVisible(false);
    _introUI->GetBtnSurvivalUp()->setVisible(false);    
    // ����
    _introUI->GetMsgSelectSlot()->setVisible(true);
    _introUI->GetDataSlot()->setVisible(true);
    _introUI->GetSlotInfoEmpty()->setVisible(true);
    _introUI->GetBtnExitUp()->setVisible(true);

    _isCampaign = true;
  }

  // X ��ư Ŭ��
  if (_isCampaign && touchExit && !_isExit) {
    _introUI->GetMsgSelectSlot()->setVisible(false);
    _introUI->GetDataSlot()->setVisible(false);
    _introUI->GetSlotInfoEmpty()->setVisible(false);
    _introUI->GetBtnExitUp()->setVisible(false);
    // �ʱ�ȭ��
    _introUI->GetTitleLogo()->setVisible(true);
    _introUI->GetTitleBtnNewgameUp()->setVisible(true);
    _introUI->GetTitleBtnInfoUp()->setVisible(true);

    _isCampaign = false;
    _isExit = false;
    _isPaladog = false;
    _isPlay = false;
  }

  // ���� ����
  if (_isCampaign && touchDataSlot && !_isDataSlot) {
    _introUI->GetDataSlot()->runAction(MoveBy::create(1, Vec2(-20, 0)));
    _introUI->GetBtnSlotStartUp()->setVisible(true);
    _introUI->GetBtnSlotDeleteUp()->setVisible(true);

    _isDataSlot = true;
  }

  // Start Ŭ��
  if (_isDataSlot && touchStart && _isStart) {    
    _isStart = true;

    // �� ��ȯ
    auto pScene = MapMindForest::createScene();
    Director::getInstance()->replaceScene(pScene);
  }

  return true;
}

void IntroScene::onTouchEnded(Touch * touch, Event * event) {
}

void IntroScene::changeBg15AgeToVolcano(float time) {
  this->removeChild(_introBg->Get15Age()); // ���� ȭ�� ����

  // ���
  _introBg->SetTitleVolcano(this); // ȭ��
  _introBg->SetTitleSky(this); // ���� ���� ����
  _introBg->SetTitleVolcanoCloud(this); // �ؿ� ���� 
  _introBg->SetTitleDarkCloud(this);
  _introBg->GetTitleDarkCloud()->
    runAction(_introBg->GetTitleDarkCloudAction());
  _introBg->SetTitleDarkCloud2(this);
  _introBg->GetTitleDarkCloud2()->
    runAction(_introBg->GetTitleDarkCloud2Action());
  _introBg->SetTitleMountain(this);
  _introBg->SetTitleMountain2(this);
  _introBg->SetTitleWood(this);

  // UI
  _introUI = new (std::nothrow) IntroUI(this); // UI ��ü �߰�
  _introUI->SetTitleLogo(this); // �ȶ� �ΰ�
  _introUI->SetTitleBtnNewgameUp(this); // PLAY ��ư
  _introUI->SetTitleBtnInfoUp(this); // ���� ��ư

  // ���� ����
  _introUI->SetModeSelectBox(this);
  _introUI->GetModeSelectBox()->setVisible(false);
  _introUI->SetHeroPaladogUp(this);
  _introUI->GetHeroPaladogUp()->setVisible(false);
  _introUI->SetHeroDarkdogUp(this);
  _introUI->GetHeroDarkdogUp()->setVisible(false);
  _introUI->SetBtnCampaignUp(this); // ķ���� ��ư
  _introUI->GetBtnCampaignUp()->setVisible(false);
  _introUI->SetBtnSurvivalUp(this);
  _introUI->GetBtnSurvivalUp()->setVisible(false);
  _introUI->SetTxtHeroSelect(this);
  _introUI->GetTxtHeroSelect()->setVisible(false);

  // ���� ����
  _introUI->SetMsgSelectSlot(this);
  _introUI->GetMsgSelectSlot()->setVisible(false);
  _introUI->SetDataSlot(this);
  _introUI->GetDataSlot()->setVisible(false);
  _introUI->SetSlotInfoEmpty(this);
  _introUI->GetSlotInfoEmpty()->setVisible(false);
  _introUI->SetBtnExitUp(this);
  _introUI->GetBtnExitUp()->setVisible(false);
  _introUI->SetBtnSlotStartUp(this);
  _introUI->GetBtnSlotStartUp()->setVisible(false);
  _introUI->SetBtnSlotDeleteUp(this);
  _introUI->GetBtnSlotDeleteUp()->setVisible(false);

  _isPlay = false;
  _isPaladog = false;
  _isCampaign = false;
  _isExit = false;
  _isDataSlot = false;
  _isStart = false;
}
