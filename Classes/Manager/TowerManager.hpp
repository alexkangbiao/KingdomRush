//
//  UserDefaultManager.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef TowerManager_hpp
#define TowerManager_hpp

#include "cocos2d.h"
#include "TowerParameter.h"
#include "BaseTower.h"

USING_NS_CC;

class TowerManager : public Ref {
public:
    static TowerManager * getInstance();

    TowerParameter* getParameterByType(int towerType);

private:
    Map<int, TowerParameter *> _towerParameterMap;
    
    void init();
    void readDataFromFile();
};


#endif /* UserDefaultManager_hpp */
