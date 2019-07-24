//
//  UserDefaultManager.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef MonsterManager_hpp
#define MonsterManager_hpp

#include "cocos2d.h"
#include "MonsterParameter.h"
#include "BaseMonster.h"

USING_NS_CC;

class MonsterManager : public Ref {
public:
    static MonsterManager * getInstance();

    MonsterParameter* getParameterByType(int monsterType);

private:
    Map<int, MonsterParameter *> _monsterParameterMap;
    
    void init();
    void readDataFromFile();
};


#endif /* UserDefaultManager_hpp */
