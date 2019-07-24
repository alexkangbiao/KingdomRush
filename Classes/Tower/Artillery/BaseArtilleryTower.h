#ifndef _BASE_BASEARTILLERY_TOWER_H_#define _BASE_BASEARTILLERY_TOWER_H_#include "cocos2d.h"#include "BaseTower.h"#include "Bullet.h"USING_NS_CC;class BaseArtilleryTower: public BaseTower{public:    virtual bool init();    protected:	void initArtilleryTower(int level);    //	void addTerrain();	Sprite* _leftShooter; //左边炮手	Sprite* _rightShooter;//右边炮手	Sprite* _c4;          //炸弹	Sprite* _barrel;      //炮筒	Sprite* _smoke;       //烟    	bool _isBulletReady;//炮弹是否填充完毕（上一发炮是否打完）	void playFilledAnimation();//填充炮弹动画	void playFireAnimation();//发射炮弹动画	void fire(Point firePosition);//发射炮弹        Point _bulletInitPoint = Point(0, 30);    Vector<Bullet *> _bulletVector;    void refreshBulletVector();    virtual Bullet* getArtilleryTowerBullet();//创建炮弹    void shoot(float dt);//攻击         virtual void addAdditionalParameterConfig();    private:    Animation* _leftShooterThrowAnimate;    Animation* _c4Animate;    Animation* _leftShooterHoldAnimate;    Animation* _rightShooterAnimate;    Animation* _towerBaseAnimate;    Animation* _barrelAnimate;    Animation* _smokeAnimate;    void prepareAnimation();};#endif