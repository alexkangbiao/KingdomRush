#include "BarrackSoldier.h"#include "GameManager.h"BarrackSoldier* BarrackSoldier::createSoldier(Point point, int level){    auto barrackSoldier = new BarrackSoldier();    if (barrackSoldier && barrackSoldier->initSoldier(level))    {        barrackSoldier->setLocation(point);        barrackSoldier->runToLocation(point);        barrackSoldier->autorelease();        return barrackSoldier;    }    CC_SAFE_DELETE(barrackSoldier);    return NULL;}bool BarrackSoldier::initSoldier(int level){    if (!BaseSoldier::initWithSoldierType(SOLDIER_TYPE_BARRACK, 1)) {        return false;    }    return true;}#pragma mark - for some private functionvoid BarrackSoldier::setAnimationAndOthers() {    _animationDeath  = AnimationCache::getInstance()->getAnimation(StringUtils::format("level%d_barracksSoilder_dead", _level).c_str());    _animationAttack = AnimationCache::getInstance()->getAnimation(StringUtils::format("level%d_barracksSoilder_attack", _level).c_str());    _animationRun    = AnimationCache::getInstance()->getAnimation(StringUtils::format("level%d_barracksSoilder_run", _level).c_str());    _soldierWaitingSpriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("soldier_lvl%d_0001.png", _level).c_str());}void BarrackSoldier::updateSoldier(int level){    this->setSoldierParameter(SOLDIER_TYPE_BARRACK, level);    this->setAnimationAndOthers();    baseSprite->stopActionByTag(_lastState);        this->setHpPercentage(100);    this->getHpBar()->setPercentage(100);    baseSprite->setSpriteFrame(_soldierWaitingSpriteFrame);    _lastState = SoldierStateNone;}//void BarrackSoldier::setSoldierAttackState(float & monsterCurrentHP) {//    this->setState(SoldierStateAttack);//    monsterCurrentHP =  monsterCurrentHP - this->getForce() + nearestMonster->getArmor();//}//void BarrackSoldier::attackMonster(float dt)//{//    if (nearestMonster != NULL && nearestMonster->getCurrentHP() > 0) {//        if ( ! this->checkDirectionForMonster()) {//            nearestMonster->setMonsterState(MonsterStateAttackLeft);//        } else {//            nearestMonster->setMonsterState(MonsterStateAttackRight);//        }//        this->setState(SoldierStateAttack);//        auto monsterCurrentHP = nearestMonster->getCurrentHP();//        auto soldierCurrentHP = this->getCurrentHP();//        //        monsterCurrentHP =  monsterCurrentHP - this->getForce() + nearestMonster->getArmor();//        if (nearestMonster->getMonsterState() != MonsterStateFrozen)//            soldierCurrentHP =  soldierCurrentHP - nearestMonster->getForce() + this->getArmor();//        //        if (monsterCurrentHP <= 0) monsterCurrentHP = 0;//        if (soldierCurrentHP <= 0)  soldierCurrentHP = 0;//        //        nearestMonster->setCurrentHP( monsterCurrentHP );//        this->setCurrentHP(soldierCurrentHP);//        //        nearestMonster->getHpBar()->setPercentage((monsterCurrentHP / nearestMonster->getMaxHp()) * 100);//        this->getHpBar()->setPercentage((soldierCurrentHP / this->getMaxHp()) * 100);//        //        if (monsterCurrentHP == 0) {//            this->unschedule(schedule_selector(BarrackSoldier::attackMonster));//            //GameManager::getInstance()->monsterVector.eraseObject(nearestMonster);//            nearestMonster->death();//            if ( this->getCurrentHP() > 0 ) this->runToLocation(_location);//        }//        if (soldierCurrentHP == 0) {//            _lastState = SoldierStateDeath;//            this->setState(SoldierStateDeath);//            this->unscheduleAllCallbacks();//            this->stopAllActions();//            this->baseSprite->stopAllActions();//            _hpBackgroungSprite->setVisible(false);//            //            if (nearestMonster != NULL && nearestMonster->getCurrentHP() > 0) {//                nearestMonster->restartWalking();//                nearestMonster->setIsAttacking(false);//            }//            baseSprite->runAction(Sequence::create(Animate::create(_animationDeath),//                                                   FadeOut::create(1.0f),//                                                   NULL));//        }//    } else {//        this->unschedule(schedule_selector(BarrackSoldier::attackMonster));//        if (this->getCurrentHP() > 0) this->runToLocation(_location);//    }//}