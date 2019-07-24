#ifndef _EARTHQUAKE_TOWER_H_#define _EARTHQUAKE_TOWER_H_#include "cocos2d.h"#include "BaseTower.h"#include "EarthquakeSmoke.h"#include "Lava.h"USING_NS_CC;class EarthquakeTower: public BaseTower{public:	virtual bool init();    CREATE_FUNC(EarthquakeTower);	private:        Sprite* _towerBase;    Sprite* _operation;    Sprite* _glow;    Sprite* _hitDecal;    Sprite* _light;    Lava*   _lava;    EarthquakeSmoke* _hitSmoke;        void initTower();    //	void showUpdateMenu();	void shoot(float dt);        int _attackCount;	void attackMonsters(int force);    	Point drill();//	void addTerrain();    //	void checkNearestMonster();        Animation* _operationDownAnimation;    Animation* _operationUpAnimation;    Animation* _glowAnimation;    Animation* _lightAnimation;    Animation* _drillingAnimation;        void prepareAnimation();};#endif