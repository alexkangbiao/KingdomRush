//
//  UpdateManager.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "TowerUpdateManager.h"

static TowerUpdateManager* _updateManagerInstance = nullptr;

TowerUpdateManager* TowerUpdateManager::getInstance()
{
    if (!_updateManagerInstance) {
        _updateManagerInstance = new (std::nothrow) TowerUpdateManager();
        CCASSERT(_updateManagerInstance, "FATAL: Not enough memory");
        _updateManagerInstance->init();
        //        _UpdateManagerInstance->autorelease();
    }
    
    return _updateManagerInstance;
}

void TowerUpdateManager::init() {
    this->readDataFromFile();
}

TowerUpdateParameter* TowerUpdateManager::getParameterByType(int updateID) {
    if (!_updateParameterMap.at(updateID)) {
        log("error for Tower Upgrade Type : %d", updateID);;
        return _updateParameterMap.at(0);
    }
    return _updateParameterMap.at(updateID);
}

float TowerUpdateManager::getTowerUpgradeValue(int updateID) {
    if (this->hasTowerUpgradeParameter(updateID)) {
        auto parameter = this->getParameterByType(updateID);
        return parameter->getValue();
    }
    
    return 0.0f;
}

bool  TowerUpdateManager::hasTowerUpgradeParameter(int updateID) {
    auto parameter = this->getParameterByType(updateID);
    if (UserDefault::getInstance()->getIntegerForKey(StringUtils::format("upgrades_icon_%d_%d",
                                                                         parameter->getType(),
                                                                         parameter->getLevel()).c_str()) == 1) {
        return true;
    }
    return false;
}

void TowerUpdateManager::readDataFromFile() {
    std::string fileName = "xml/update_detail.plist";
    auto valueMap = FileUtils::getInstance()->getValueMapFromFile(fileName);
    
    //parse the terrains data
    auto arrayUpdates = valueMap.at("updates").asValueVector();
    for (int i = 0; i< arrayUpdates.size(); i++) {
        auto valueMap = (arrayUpdates[i]).asValueMap();
        int updateid = atoi((valueMap["id"]).asString().c_str());
        auto updateParameter = TowerUpdateParameter::createWithData(updateid,
                                                               atoi((valueMap["type"]).asString().c_str()),
                                                               atoi((valueMap["level"]).asString().c_str()),
                                                               atof((valueMap["value"]).asString().c_str()),
                                                               valueMap["imageon"].asString(),
                                                               valueMap["imageoff"].asString(),
                                                               valueMap["title"].asString(),
                                                               valueMap["explain"].asString()
                                                               );
        _updateParameterMap.insert(updateid, updateParameter);
    }
}