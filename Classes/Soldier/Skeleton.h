#ifndef _SKELETON_H_#define _SKELETON_H_#include "BaseSoldier.h"class Skeleton : public BaseSoldier{public:	virtual bool init();//	CREATE_FUNC(Skeleton);	static Skeleton* createSkeleton(Point point);//	void update(float dt);//	void attackMonster(float dt);//	void runToMonster();//	bool checkDirectionForMonster();//	void checkNearestMonster();//	void createAndSetHpBar();    private:    void birth(Point point);    virtual void setAnimationAndOthers();};#endif