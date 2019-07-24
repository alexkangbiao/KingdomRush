#include "BaseArtilleryTower.h"#include "GameManager.h"#include "Bomb.h"#include "TowerUpdateManager.h"bool BaseArtilleryTower::init() {    if (!BaseTower::init()) {        return false;    }    _isBulletReady = true;        this->addTerrainSprite("terrain_artillery_0004.png");        return true;}void BaseArtilleryTower::initArtilleryTower(int level){	this->setName(StringUtils::format("level%d_Artillery_",level).c_str());    	towerBase    = Sprite::createWithSpriteFrameName(                        StringUtils::format("tower_artillery_lvl%d_layer1_0001.png", level).c_str());	_leftShooter  = Sprite::createWithSpriteFrameName(                        StringUtils::format("tower_artillery_lvl%d_layer2_0001.png", level).c_str());	_rightShooter = Sprite::createWithSpriteFrameName(                        StringUtils::format("tower_artillery_lvl%d_layer3_0001.png", level).c_str());	_barrel       = Sprite::createWithSpriteFrameName(                        StringUtils::format("tower_artillery_lvl%d_layer4_0001.png", level).c_str());	_smoke        = Sprite::createWithSpriteFrameName(                        StringUtils::format("tower_artillery_lvl%d_layer5_0001.png", level).c_str());	_c4           = Sprite::createWithSpriteFrameName(                        StringUtils::format("tower_artillery_lvl%d_layer6_0001.png", level).c_str());	this->addChild(towerBase);	this->addChild(_leftShooter);	this->addChild(_rightShooter);	this->addChild(_barrel);	this->addChild(_smoke);	this->addChild(_c4);	this->addChild(Sprite::createWithSpriteFrameName(                        StringUtils::format("tower_artillery_lvl%d_layer7_0001.png", level).c_str()));        this->prepareAnimation();        _bulletInitPoint = Point(0, 30);}void BaseArtilleryTower::prepareAnimation() {    _leftShooterThrowAnimate = AnimationCache::getInstance()->getAnimation(getName() + "leftShooter_throw");    _leftShooterHoldAnimate  = AnimationCache::getInstance()->getAnimation(getName() + "leftShooter_hold");    _rightShooterAnimate     = AnimationCache::getInstance()->getAnimation(getName() + "rightShooter");        _c4Animate        = AnimationCache::getInstance()->getAnimation(getName() + "c4");    _towerBaseAnimate = AnimationCache::getInstance()->getAnimation(getName() + "towerBase");    _barrelAnimate    = AnimationCache::getInstance()->getAnimation(getName() + "barrel");    _smokeAnimate     = AnimationCache::getInstance()->getAnimation(getName() + "smoke");}#pragma mark - for animation functionvoid BaseArtilleryTower::playFilledAnimation() {	_leftShooter->runAction(Animate::create(_leftShooterThrowAnimate));	_c4->runAction(Animate::create(_c4Animate));	_isBulletReady = true;}void BaseArtilleryTower::playFireAnimation() {    _leftShooter->runAction(Animate::create(_leftShooterHoldAnimate));    towerBase->runAction(Animate::create(_towerBaseAnimate));    _barrel->runAction(Animate::create(_barrelAnimate));    _rightShooter->runAction(Animate::create(_rightShooterAnimate));    _smoke->runAction(Animate::create(_smokeAnimate));}#pragma mark - for others functionvoid BaseArtilleryTower::shoot(float dt) {//    this->checkNearestMonster();    _nearestMonster = this->getCanAttackMonster();        if(_isBulletReady && _nearestMonster != NULL && _nearestMonster->getCurrentHP() > 0) {        _isBulletReady = false;        auto firePosition = _nearestMonster->getMonsterPosition() - this->getParent()->getPosition();        this->runAction(Sequence::create(CallFuncN::create(CC_CALLBACK_0(BaseArtilleryTower::playFireAnimation, this)),                                         CallFuncN::create(CC_CALLBACK_0(BaseArtilleryTower::fire, this, firePosition)),                                         CallFuncN::create(CC_CALLBACK_0(BaseArtilleryTower::playFilledAnimation, this)),                                         NULL));    }}void BaseArtilleryTower::fire(Point firePosition) {	auto currentBullet = this->getArtilleryTowerBullet();	auto shootVector   = firePosition;        ccBezierConfig bezier;    bezier.controlPoint_1 = Point(currentBullet->getPosition().x,                                  currentBullet->getPosition().y + 200);	bezier.controlPoint_2 = Point(shootVector.x,                                  shootVector.y + 200);;	bezier.endPosition = shootVector;    	float endRotate;	if(shootVector.x > currentBullet->getPosition().x)		endRotate = 180.0f;	else		endRotate = -180.0f;    	auto action = Spawn::create(BezierTo::create(1.0f, bezier),                                RotateTo::create(1.0f, endRotate),                                NULL);    	currentBullet->setBulletAction(action);	currentBullet->shoot();	this->runAction(Sequence::create(DelayTime::create(1.0f),                                     CallFuncN::create(CC_CALLBACK_0(BaseArtilleryTower::playFireAnimation, this)),                                     NULL));	currentBullet = NULL;}Bullet* BaseArtilleryTower::getArtilleryTowerBullet() {//    log("Artillery bullet vector number is : %ld", _bulletVector.size());        //循环使用已经生成的子弹，否则就转到生成新子弹    for (int i = 0; i < _bulletVector.size(); i++) {        if (!_bulletVector.at(i)->getParent()) {            _bulletVector.at(i)->restoreBullet();            _bulletVector.at(i)->setPosition(_bulletInitPoint);            this->getParent()->addChild(_bulletVector.at(i));            return _bulletVector.at(i);        }    }        auto bullet = Bomb::createBombWithLevel(this->getLevel());	bullet->setPosition(_bulletInitPoint);//    bullet->refreshTypeAndLevel(bullet->getBulletType(), this->getLevel());	this->getParent()->addChild(bullet);    _bulletVector.pushBack(bullet);        return bullet;}void BaseArtilleryTower::refreshBulletVector() {    _bulletVector.clear();}void BaseArtilleryTower::addAdditionalParameterConfig() {    this->setUpdateMoney(this->getUpdateMoney() * (1 + TowerUpdateManager::getInstance()->getTowerUpgradeValue(UpgradeTowerTagArtillery02_ReduceBuildMoney)));    this->setAttackScope(this->getAttackScope() * (1 + TowerUpdateManager::getInstance()->getTowerUpgradeValue(UpgradeTowerTagArtillery03_AttackScope)));    this->setShootPeriod(this->getShootPeriod() * (1 + TowerUpdateManager::getInstance()->getTowerUpgradeValue(UpgradeTowerTagArtillery04_ShootPeriod)));}