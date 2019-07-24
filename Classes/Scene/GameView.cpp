#include "GameView.h"#include "TransitionGame.h"#include "WelcomeScene.h"#include "MapFlag.h"#include "Road.h"#include "GameViewMenu.h"#include "GameManager.h"#include "RespirationSprite.h"#include "SoundManager.h"#include "SpriteCacheManager.h"USING_NS_CC;Scene* GameView::createScene() {    auto scene = Scene::create();        auto layer = GameView::create();	auto menuLayer = GameViewMenu::create();    scene->addChild(layer, GameViewDrawingOrderBackground);	scene->addChild(menuLayer, GameViewDrawingOrderMenu);    return scene;}bool GameView::init(){    if ( !Layer::init() )    {        return false;    }	_gameManagerInstance = GameManager::getInstance();        SpriteCacheManager::getInstance()->loadGameViewSceneSpriteFile();    SpriteCacheManager::getInstance()->loadCommonSceneSpriteFile();	//下行测试用//	UserDefault::getInstance()->setIntegerForKey(_gameManagerInstance->LEVELX_DOWNCOUNT, 0);    this->addBackgroundImage();    this->readMapFlagPointFromFile();	//添加道路	this->addRoad();	//添加旗帜	this->addMapFlags();    this->locateScreenPoint();    this->addKeyboardListener();	SoundManager::playGameTheme1();        return true;}void GameView::onEnterTransitionDidFinish(){    int newReady = UserDefault::getInstance()->getIntegerForKey(_gameManagerInstance->LEVEL_SLOTX_NEW_OPEN, 0);    if (newReady <= 12) {//最多13关        if (UserDefault::getInstance()->getIntegerForKey(_gameManagerInstance->SLOT_X_COMPLETE_COUNT, 0) !=  newReady){            UserDefault::getInstance()->setIntegerForKey(_gameManagerInstance->SLOT_X_COMPLETE_COUNT, newReady);            _mapFlagVector.at(newReady - 1)->setFlagType(0);            auto sequence = Sequence::create(CallFuncN::create(CC_CALLBACK_0(MapFlag::playSuccessAnimation, _mapFlagVector.at(newReady - 1))),                                             CallFuncN::create(CC_CALLBACK_0(Road::buildRoadAnimation, _road, newReady - 1)),                                             DelayTime::create(1.5f),                                             CallFuncN::create(CC_CALLBACK_0(GameView::addNewMapFlag,this , newReady)),                                             NULL);            runAction(sequence);        }    }}#pragma mark -- for private functionvoid GameView::locateScreenPoint() {    int newReady = UserDefault::getInstance()->getIntegerForKey(_gameManagerInstance->LEVEL_SLOTX_NEW_OPEN, 0);        Point location = Point();    location.x = _winSize.width / 2  - _mapFlagPointVector.at(newReady).x;    location.y = _winSize.height / 2 - _mapFlagPointVector.at(newReady).y;    auto backgroundCurrentSize = _backgroundSprite->getBoundingBox().size;    location.x = MIN(location.x, 0);    location.x = MAX(location.x, - backgroundCurrentSize.width + _winSize.width);    location.y = MIN(location.y, 0);    location.y = MAX(location.y, - backgroundCurrentSize.height + _winSize.height);    this->setPosition(location);}void GameView::readMapFlagPointFromFile() {    std::string fileName = "xml/map_flag_point.plist";    auto valueMap = FileUtils::getInstance()->getValueMapFromFile(fileName);    auto arrayPoints = valueMap.at("points").asValueVector();    for (int i = 0; i< arrayPoints.size(); i++) {        auto pointValueMap = (arrayPoints[i]).asValueMap();       _mapFlagPointVector.push_back(Point(atoi(pointValueMap["x"].asString().c_str()),                                           atoi(pointValueMap["y"].asString().c_str())));    }}#pragma mark -- for add functionvoid GameView::addBackgroundImage() {    _winSize = Director::getInstance()->getWinSize();    _backgroundSprite = Sprite::createWithSpriteFrameName("MapBackground.png");    _backgroundSprite->setAnchorPoint(Vec2::ZERO);    _backgroundSprite->setPosition(Vec2::ZERO);        this->addChild(_backgroundSprite, GameViewDrawingOrderBackground);    auto listener = EventListenerTouchAllAtOnce::create();    listener->onTouchesBegan = CC_CALLBACK_2(GameView::onTouchesBegan, this);// 触摸开始时触发    listener->onTouchesMoved = CC_CALLBACK_2(GameView::onTouchesMoved, this);// 触摸移动时触发    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, _backgroundSprite);}void GameView::addNewMapFlag(int number){	auto mapFlag = MapFlag::createWithLevel(number);	mapFlag->setPosition(_mapFlagPointVector.at(number));	this->addChild(mapFlag, GameViewDrawingOrderFlag);	_mapFlagVector.pushBack(mapFlag);	mapFlag->playDropdownAnimation();}void GameView::addRoad() {	_road = Road::create();	_road->setPosition(Point(_backgroundSprite->getContentSize().width / 2,                             _backgroundSprite->getContentSize().height / 2));	this->addChild(_road, GameViewDrawingOrderFlag);}void GameView::addMapFlags() {    int count = UserDefault::getInstance()->getIntegerForKey(_gameManagerInstance->LEVEL_SLOTX_NEW_OPEN, 0);//    count = 13;    for(int i = 0; i <= count; i++) {        auto mapFlag = MapFlag::createWithLevel(i);        mapFlag->setPosition(_mapFlagPointVector.at(i));        _mapFlagVector.pushBack(mapFlag);        if(i == count) {            mapFlag->setStarInvisiable();        }        this->addChild(mapFlag, GameViewDrawingOrderFlag);    }        //add tip    if(UserDefault::getInstance()->getIntegerForKey(_gameManagerInstance->LEVEL_SLOTX_NEW_OPEN, 0) == 0){        auto respirationSprite = RespirationSprite::createRespirationSprite("mapBalloon_starthere.png");        respirationSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);        respirationSprite->setPosition(_mapFlagPointVector.at(0));        this->addChild(respirationSprite, GameViewDrawingOrderFlag);    }}#pragma mark - for listener callback functionvoid GameView::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event){	if (touches.size() == 1)        // 单点进行移动    {        // 单点时，touches中只有一个Touch对象，所以通过touches[0]就可以得到触摸对象        auto touch = touches[0];        // 计算滑动过程中的滑动增量        auto diff = touch->getDelta();               // 得到当前bgSprite的位置        auto currentPos = this->getPosition();        // 得到滑动后bgSprite应该所在的位置        auto pos = currentPos + diff;        // 得到此刻bgSprite的尺寸        auto bgSpriteCurrSize = _backgroundSprite->getBoundingBox().size;         //边界控制，约束pos的位置        pos.x = MIN(pos.x, bgSpriteCurrSize.width * _backgroundSprite->getAnchorPoint().x);        pos.x = MAX(pos.x, -bgSpriteCurrSize.width + _winSize.width + bgSpriteCurrSize.width * _backgroundSprite->getAnchorPoint().x);        pos.y = MIN(pos.y, bgSpriteCurrSize.height * _backgroundSprite->getAnchorPoint().y);        pos.y = MAX(pos.y, -bgSpriteCurrSize.height + _winSize.height + bgSpriteCurrSize.height * _backgroundSprite->getAnchorPoint().y);        this->setPosition(pos);	    }}void GameView::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event){}#pragma mark - for key boardvoid GameView::addKeyboardListener() {    auto listenerkeyPad = EventListenerKeyboard::create();    listenerkeyPad->onKeyReleased = CC_CALLBACK_2(GameView::onKeyReleased, this);    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);}void GameView::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event){	if(keycode==EventKeyboard::KeyCode::KEY_BACK)	{		auto scene = WelcomeScene::createScene();		Director::getInstance()->replaceScene(TransitionGame::create(2.0f,scene));	}}