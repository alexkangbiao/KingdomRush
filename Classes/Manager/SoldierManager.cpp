//
//  SoldierManager.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "SoldierManager.hpp"


static SoldierManager* _soldierManagerInstance = nullptr;

SoldierManager* SoldierManager::getInstance()
{
    if (!_soldierManagerInstance) {
        _soldierManagerInstance = new (std::nothrow) SoldierManager();
        
        CCASSERT(_soldierManagerInstance, "FATAL: Not enough memory");
        
        _soldierManagerInstance->init();
//        _monsterManagerInstance->autorelease();
    }
    
    return _soldierManagerInstance;
}

void SoldierManager::init() {
    this->readDataFromFile();
}

SoldierParameter* SoldierManager::getParameterByType(SoldierType soldierType, int level) {
    for (SoldierParameter* soldierParameter : _soldierParameterVector) {
        if (soldierParameter->getType() == soldierType
            && soldierParameter->getLevel() == level) {
            return soldierParameter;
        }
    }
    
    SoldierParameter* soldierParameter = this->getParameterByType(SOLDIER_TYPE_ASSASSIN, 1);
    log("error for Soldier Type: %d, level: %d", soldierType, level);
    
    return soldierParameter;
}

void SoldierManager::readDataFromFile() {
    std::string fileName = "xml/soldier_config.plist";
    auto valueMap = FileUtils::getInstance()->getValueMapFromFile(fileName);
    
    //parse the soldiers data
    auto arraySoldiers = valueMap.at("soldiers").asValueVector();
    for (int i = 0; i< arraySoldiers.size(); i++) {
        auto valueMap = (arraySoldiers[i]).asValueMap();
        int type = atoi((valueMap["type"]).asString().c_str());
        auto soldierParameter = SoldierParameter::createWithData(type,
                                                                 valueMap["name"].asString(),
                                                                 valueMap["baseimage"].asString(),
                                                                 atoi((valueMap["level"]).asString().c_str()),
                                                                 atoi((valueMap["maxhp"]).asString().c_str()),
                                                                 atoi((valueMap["force"]).asString().c_str()),
                                                                 atoi((valueMap["armor"]).asString().c_str()),
                                                                 atoi((valueMap["speed"]).asString().c_str()),
                                                                 atoi((valueMap["scope"]).asString().c_str()),
                                                                 atof((valueMap["attackperiod"]).asString().c_str()),
                                                                 atof((valueMap["cureperiod"]).asString().c_str()),
                                                                 atof((valueMap["curepercentage"]).asString().c_str())
                                                                 );
        _soldierParameterVector.pushBack(soldierParameter);
        
//        log("%d, %s, %s, %s, %d, %d, %d, %d, %d",
//            type,
//            soldierParameter->getName().c_str(),
//            soldierParameter->getBaseImageName().c_str(),
//            soldierParameter->getBloodColor().c_str(),
//            soldierParameter->getMaxHP(),
//            soldierParameter->getMoney(),
//            soldierParameter->getForce(),
//            soldierParameter->getArmor(),
//            soldierParameter->getSpeed()
//            );
    }
}