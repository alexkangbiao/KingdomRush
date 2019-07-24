//
//  UserDefaultManager.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef SoldierManager_hpp
#define SoldierManager_hpp

#include "cocos2d.h"
#include "SoldierParameter.h"
#include "BaseSoldier.h"

USING_NS_CC;

class SoldierManager : public Ref {
public:
    static SoldierManager * getInstance();

    SoldierParameter* getParameterByType(SoldierType soldierType, int level);

private:
    Vector<SoldierParameter *> _soldierParameterVector;
    
    void init();
    void readDataFromFile();
};


#endif /* UserDefaultManager_hpp */
