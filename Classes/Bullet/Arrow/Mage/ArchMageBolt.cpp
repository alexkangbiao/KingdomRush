#include "ArchMageBolt.h"bool ArchMageBolt::init() {	if (! ArrowBulletBase::initWithTypeAndLevel(BULLET_TYPE_ARCHMAGEBOLT, 1)) {		return false;	}	this->round();    	return true;}void ArchMageBolt::shoot() {	this->runAction(Sequence::create(_bulletAction,                               CallFuncN::create(CC_CALLBACK_0(ArchMageBolt::attackPointMonster, this)),                               NULL));}void ArchMageBolt::round() {	_bulletSprite->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("proy_archbolt"))));}void ArchMageBolt::processMonsterDeath(BaseMonster * monster) {    monster->death();}