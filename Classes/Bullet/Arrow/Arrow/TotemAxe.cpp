#include "TotemAxe.h"#include "GameManager.h"bool TotemAxe::init() {	if (! ArrowBulletBase::initWithTypeAndLevel(BULLET_TYPE_TOTEMAXE, 1)) {		return false;	}	return true;}void TotemAxe::shoot(){	this->runAction(Sequence::create(_bulletAction,                                     CallFuncN::create(CC_CALLBACK_0(TotemAxe::attackPointMonster, this)),                                     NULL));}void TotemAxe::processMonsterDeath(BaseMonster * monster) {    monster->death();}void TotemAxe::handleMissBullet() {    _bulletSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("decal_axe.png"));    _bulletSprite->runAction(Sequence::create(FadeOut::create(2.0f),                                              CallFuncN::create(CC_CALLBACK_0(TotemAxe::handleFinishBullet, this)),                                              FadeIn::create(0.0f),                                              NULL));}