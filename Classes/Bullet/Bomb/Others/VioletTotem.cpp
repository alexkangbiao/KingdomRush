#include "VioletTotem.h"#include "GameManager.h"bool VioletTotem::init(){	if (! BombBulletBase::initWithTypeAndLevel(BULLET_TYPE_VIOLETTOTEM, 1)) {		return false;	}    //    this->setBulletType(BULLET_TYPE_VIOLETTOTEM);//    this->setBulletScope(50);//    //    this->addBulletSprite("TotemTower_VioletTotem_0001.png");	return true;}void VioletTotem::shoot(Point point){	this->setPosition(point);	_bulletSprite->runAction(Sequence::create(CallFuncN::create(CC_CALLBACK_0(VioletTotem::attackAreaMonster, this)),                                              Animate::create(AnimationCache::getInstance()->getAnimation("TotemTower_VioletTotem")),//                                              CallFuncN::create(CC_CALLBACK_0(VioletTotem::removeBullet,this)),                                              NULL));}void VioletTotem::handleHP(BaseMonster * monster) {    monster->runOnSlowSpeed(3.0f, 10);}//void VioletTotem::boom()//{//	auto bombPostion = this->getPosition() + this->getParent()->getPosition();////	auto monsterVector = GameManager::getInstance()->monsterVector;////	for (int i = 0; i < monsterVector.size(); i++) {//		auto monster = monsterVector.at(i);////		if ( monster != NULL//           && bombPostion.distance(monster->getMonsterPosition()) <= this->getBulletScope()//           && monster->getEnableAttackBySoldier()) {//			monster->runOnSlowSpeed(3.0f, 10);//		}		//	}	//}////void VioletTotem::removeBullet() {//	this->removeFromParent();//}