#ifndef _BASE_ARROW_TOWER_H_#define _BASE_ARROW_TOWER_H_#include "cocos2d.h"#include "BaseTower.h"#include "Bullet.h"USING_NS_CC;enum ArrowShooterTag : unsigned int {    ArrowShooterTag_1 = 0,    ArrowShooterTag_2};class BaseArrowTower: public BaseTower{public:    virtual bool init();    protected:    //射手	Sprite* shooter_1;	Sprite* shooter_2;	ArrowShooterTag _shooterTag;    	void initArrowTowerBase(int level);        Vector<Bullet *> _bulletVector;    void refreshBulletVector();    virtual Bullet* getArrowTowerBullet();	        Animation* _shooterDownAnimation;    Animation* _shooterUpAnimation;    void prepareAnimation();        Bullet* _currentBullet;    virtual void shoot(float dt);    virtual void playShootVoice();    virtual void shootAdditionalWeapon() {};    virtual Spawn* getBulletAction();        virtual void addAdditionalParameterConfig();};#endif