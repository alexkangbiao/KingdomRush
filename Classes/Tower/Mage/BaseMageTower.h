#ifndef _BASE_MAGE_TOWER_H_#define _BASE_MAGE_TOWER_H_#include "cocos2d.h"#include "BaseTower.h"#include "Bullet.h"USING_NS_CC;class BaseMageTower:public BaseTower{public:    virtual bool init();    protected:	Sprite* _shooter;	Bullet* _currentBullet;	void initMageTower(const int level);        Point _bulletInitPoint;    Vector<Bullet *> _bulletVector;    void refreshBulletVector();	virtual Bullet* getMageTowerBullet();    	virtual void shoot(float dt);    virtual void playShootVoice();    virtual void playAdditionalAnimate();        Animation* _shootUpAnimation;    Animation* _shootDownAnimation;    private:    Animation* _shiningAnimation;    void prepareAnimation();            virtual void addAdditionalParameterConfig();};#endif