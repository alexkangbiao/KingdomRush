//
//  UserDefaultManager.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef TowerUpdateManager_hpp
#define TowerUpdateManager_hpp

#include "cocos2d.h"
#include "TowerUpdateParameter.h"

USING_NS_CC;

enum UpgradeTowerTag : int {
    UpgradeTowerTagArrow01_ImproveForce = 0,
    UpgradeTowerTagArrow02_ReduceBuildMoney,
    UpgradeTowerTagArrow03_IncreaseScope,
    UpgradeTowerTagArrow04_ShootPeriod,
    UpgradeTowerTagArrow05_Speed,
    UpgradeTowerTagSoldier01_Armor,
    UpgradeTowerTagSoldier02_RallyScope,
    UpgradeTowerTagSoldier03_Force,
    UpgradeTowerTagSoldier04_CurePercentage,
    UpgradeTowerTagSoldier05_AttackScope,
    UpgradeTowerTagMage01_Force,
    UpgradeTowerTagMage02_ReduceBuildMoney,
    UpgradeTowerTagMage03_AttackScope,
    UpgradeTowerTagMage04_ShootPeriod,
    UpgradeTowerTagMage05_Speed,
    UpgradeTowerTagArtillery01_Force,
    UpgradeTowerTagArtillery02_ReduceBuildMoney,
    UpgradeTowerTagArtillery03_AttackScope,
    UpgradeTowerTagArtillery04_ShootPeriod,
    UpgradeTowerTagArtillery05_AttackScope,
    UpgradeTowerTagFireball01_ReduceCountDownTime,
    UpgradeTowerTagFireball02_IncreaseNumber,
    UpgradeTowerTagFireball03,
    UpgradeTowerTagFireball04_Force,
    UpgradeTowerTagFireball05_Scope,
    UpgradeTowerTagReinforce01_ReduceCountDownTime,
    UpgradeTowerTagReinforce02_Armor,
    UpgradeTowerTagReinforce03_Force,
    UpgradeTowerTagReinforce04_CurePercentage,
    UpgradeTowerTagReinforce05_IncreaseNumber
};

class TowerUpdateManager : public Ref {
public:
    static TowerUpdateManager * getInstance();

    TowerUpdateParameter* getParameterByType(int updateID);
    float getTowerUpgradeValue(int updateID);
    bool  hasTowerUpgradeParameter(int updateID);

private:
    Map<int, TowerUpdateParameter *> _updateParameterMap;
    
    void init();
    void readDataFromFile();
};


#endif /* UserDefaultManager_hpp */
