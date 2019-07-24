//
//  TowerManager.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "TowerManager.hpp"


static TowerManager* _towerManagerInstance = nullptr;

TowerManager* TowerManager::getInstance()
{
    if (!_towerManagerInstance) {
        _towerManagerInstance = new (std::nothrow) TowerManager();
        CCASSERT(_towerManagerInstance, "FATAL: Not enough memory");
        _towerManagerInstance->init();
        //        _towerManagerInstance->autorelease();
    }
    
    return _towerManagerInstance;
}

void TowerManager::init() {
    this->readDataFromFile();
}

TowerParameter* TowerManager::getParameterByType(int towerType) {
    if (!_towerParameterMap.at(towerType)) {
        log("error for Tower Type : %d", towerType);;
        return _towerParameterMap.at(TOWER_TYPE_ARCHER_1);
    }
    return _towerParameterMap.at(towerType);
}

void TowerManager::readDataFromFile() {
    std::string fileName = "xml/tower_config.plist";
    auto valueMap = FileUtils::getInstance()->getValueMapFromFile(fileName);
    
    //parse the terrains data
    auto arrayTowers = valueMap.at("towers").asValueVector();
    for (int i = 0; i< arrayTowers.size(); i++) {
        auto valueMap = (arrayTowers[i]).asValueMap();
        int type = atoi((valueMap["id"]).asString().c_str());
        auto towerParameter = TowerParameter::createWithFileData(type,
                                                               valueMap["TowerName"].asString(),
                                                               atoi((valueMap["level"]).asString().c_str()),
                                                               atof((valueMap["scope"]).asString().c_str()),
                                                               atof((valueMap["nextScope"]).asString().c_str()),
//                                                               atof((valueMap["force"]).asString().c_str()),
                                                               atof((valueMap["buildMoney"]).asString().c_str()),
                                                               atof((valueMap["updateMoney"]).asString().c_str()),
                                                               atof((valueMap["period"]).asString().c_str()),
                                                               valueMap["portraitsimagename"].asString(),
                                                               atoi((valueMap["update1startlevel"]).asString().c_str()),
                                                               atoi((valueMap["update2startlevel"]).asString().c_str())
                                                               );
        _towerParameterMap.insert(type, towerParameter);
    }
}