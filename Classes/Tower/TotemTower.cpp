#include "TotemTower.h"#include "GameManager.h"#include "TotemAxe.h"#include "RedTotem.h"#include "VioletTotem.h"#include "BaseMap.h"bool TotemTower::init() {    if (! BaseArrowTower::init()) {        return false;    }    this->setTowerType(TOWER_TYPE_TOTEMTOWER);        this->initTotemTowerBase();    this->playEyesDownAnimation();        _isShootAdditionalWeapon = true;    this->schedule(schedule_selector(TotemTower::shoot), this->getShootPeriod());    this->schedule(schedule_selector(TotemTower::openShootAdditionalWeapon), 5.0f);        SoundManager::playTotemReady();    return true;}void TotemTower::initTotemTowerBase() {    towerBase = Sprite::createWithSpriteFrameName("TotemTower.png");        shooter_1 = Sprite::createWithSpriteFrameName("TotemTower_Shooter_0001.png");    shooter_2 = Sprite::createWithSpriteFrameName("TotemTower_Shooter_0001.png");        shooter_1->setPosition(Point(towerBase->getContentSize().width  / 2 - shooter_1->getContentSize().width / 2,                                 towerBase->getContentSize().height / 2 + shooter_1->getContentSize().height / 2));    shooter_2->setPosition(Point(towerBase->getContentSize().width  / 2 + shooter_2->getContentSize().width / 2,                                 towerBase->getContentSize().height / 2 + shooter_2->getContentSize().height / 2));        towerBase->addChild(shooter_1);    towerBase->addChild(shooter_2);        this->addChild(towerBase, BaseTowerDrawingOrderTowerBase);}void TotemTower::playEyesDownAnimation() {    _eyesDown = Sprite::createWithSpriteFrameName("TotemTower_EyesDown_0001.png");    _eyesDown->setPosition(Point(0, -25));    this->addChild(_eyesDown, BaseTowerDrawingOrderAdditional);    _eyesDown->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("TotemTower_EyesDown"))));}//void TotemTower::showUpdateMenu()//{//    auto simplePanleLayer = SimplePanleLayer::create();//    simplePanleLayer->setTag(_terrain->getTag() + 100);//    simplePanleLayer->setTower(this);//    simplePanleLayer->setPosition(this->getParent()->getPosition());//    static_cast<BaseMap*>(this->getParent()->getParent())->mTouchLayer->addChild(simplePanleLayer);//    simplePanleLayer->playShowAnimation();//    _isUpdateMenuShown = true;//}void TotemTower::openShootAdditionalWeapon(float dt) {    _isShootAdditionalWeapon = true;}Bullet* TotemTower::getArrowTowerBullet(){//    log("arrow vector number is : %ld", _bulletVector.size());        //循环使用已经生成的子弹，否则就转到生成新子弹    for (int i = 0; i < _bulletVector.size(); i++) {        if (!_bulletVector.at(i)->getParent()) {            _bulletVector.at(i)->restoreBullet();            this->getParent()->addChild(_bulletVector.at(i));            return _bulletVector.at(i);        }    }        auto bullet = TotemAxe::create();    bullet->setRotation(90.0f);    this->getParent()->addChild(bullet);    _bulletVector.pushBack(bullet);        return bullet;}void TotemTower::prepareAnimation() {    _shooterDownAnimation = AnimationCache::getInstance()->getAnimation("TotemTower_Shooter_down");    _shooterUpAnimation   = AnimationCache::getInstance()->getAnimation("TotemTower_Shooter_up");}//void TotemTower::shoot(float dt)//{////    this->checkNearestMonster();//    _nearestMonster = this->getCanAttackMonster();//    //    if (_nearestMonster != NULL && _nearestMonster->getCurrentHP() > 0 )//    {//        auto currentBullet = this->getArrowTowerBullet();//        //        Point shootVector = _nearestMonster->getMonsterPosition() - this->getTowerPosition();//        // //        //        if (shootVector.x - currentBullet->getPosition().x <= 0)//向左攻击//        {//            if (_shooterTag == ArrowShooterTag_1) //轮到1号弓箭手//            {//                currentBullet->setPosition(Point(0, 30));//子弹设置在弓箭手所在位置//                shooter_1->setFlippedX(true);//                if (shootVector.y - currentBullet->getPosition().y <= 0)//                {//                    //攻击动画//                    shooter_1->runAction(Animate::create(_shooterDownAnimation));//                } else {//                    shooter_1->runAction(Animate::create(_shooterUpAnimation));//                }//                _shooterTag = ArrowShooterTag_2;//            } else {//                //轮到2号弓箭手//                currentBullet->setPosition(Point(10, 30));//                shooter_2->setFlippedX(true);//                if (shootVector.y - currentBullet->getPosition().y <= 0) {//                    shooter_2->runAction(Animate::create(_shooterDownAnimation));//                } else {//                    shooter_2->runAction(Animate::create(_shooterUpAnimation));//                }//                _shooterTag = ArrowShooterTag_1;//            }//        } else {//            if (_shooterTag == ArrowShooterTag_1) {//                currentBullet->setPosition(Point(0, 30));//                shooter_1->setFlippedX(false);//                if (shootVector.y - currentBullet->getPosition().y <= 0) {//                    shooter_1->runAction(Animate::create(_shooterDownAnimation));//                } else {//                    shooter_1->runAction(Animate::create(_shooterUpAnimation));//                }//                _shooterTag = ArrowShooterTag_2;//            } else {//                currentBullet->setPosition(Point(10, 30));//                shooter_2->setFlippedX(false);//                if (shootVector.y - currentBullet->getPosition().y <= 0) {//                    shooter_2->runAction(Animate::create(_shooterDownAnimation));//                } else {//                    shooter_2->runAction(Animate::create(_shooterUpAnimation));//                }//                _shooterTag = ArrowShooterTag_1;//            }//        }//        //        //弧线s//        //        ////        //攻击属性给弓箭//        currentBullet->setBulletAction(action);//        currentBullet->shoot();//        currentBullet = NULL;//    }//}void TotemTower::playShootVoice() {    SoundManager::playTotemShot();}void TotemTower::shootAdditionalWeapon()  {    Point shootVector = _nearestMonster->getMonsterPosition() - this->getTowerPosition();    if (_isShootAdditionalWeapon) {        SoundManager::playTotemSpirits();        auto redTotem = RedTotem::create();        this->getParent()->addChild(redTotem);        redTotem->shoot(shootVector + Point(20, 20));                auto violetTotem = VioletTotem::create();        this->getParent()->addChild(violetTotem);        violetTotem->shoot(shootVector - Point(20, 20));        _isShootAdditionalWeapon = false;    }}Spawn* TotemTower::getBulletAction()  {    Point shootVector = _nearestMonster->getMonsterPosition() - this->getTowerPosition();    float duringTime  = this->caculateSpendTime(_nearestMonster->getMonsterPosition(),                                                _currentBullet->getBulletSpeed());        auto action = Spawn::create(MoveTo::create(duringTime, shootVector),                                RotateTo::create(duringTime, 1080.0f),                                NULL);    return action;}