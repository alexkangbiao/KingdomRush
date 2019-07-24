//
//  UserDefaultManager.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef BulletManager_hpp
#define BulletManager_hpp

#include "cocos2d.h"
#include "BulletParameter.h"
#include "Bullet.h"

USING_NS_CC;

class BulletManager : public Ref {
public:
    static BulletManager * getInstance();

    BulletParameter* getParameterByType(BulletType bulletType, int level);

private:
    Vector<BulletParameter *> _bulletParameterVector;
    
    void init();
    void readDataFromFile();
};


#endif /* UserDefaultManager_hpp */
