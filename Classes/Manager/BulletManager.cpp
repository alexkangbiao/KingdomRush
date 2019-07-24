//
//  BulletManager.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "BulletManager.hpp"


static BulletManager* _bulletManagerInstance = nullptr;

BulletManager* BulletManager::getInstance()
{
    if (!_bulletManagerInstance) {
        _bulletManagerInstance = new (std::nothrow) BulletManager();
        
        CCASSERT(_bulletManagerInstance, "FATAL: Not enough memory");
        
        _bulletManagerInstance->init();
//        _monsterManagerInstance->autorelease();
    }
    
    return _bulletManagerInstance;
}

void BulletManager::init() {
    this->readDataFromFile();
}

BulletParameter* BulletManager::getParameterByType(BulletType bulletType, int level) {
    for (BulletParameter* bulletParameter : _bulletParameterVector) {
        if (bulletParameter->getType() == bulletType
            && bulletParameter->getLevel() == level) {
            return bulletParameter;
        }
    }
    BulletParameter* tempBulletParameter = this->getParameterByType(BULLET_TYPE_ARROW, 1);
    log("error for BulletType: %d, level: %d", bulletType, level);
    return tempBulletParameter;
}

void BulletManager::readDataFromFile() {
    std::string fileName = "xml/bullet_config.plist";
    auto valueMap = FileUtils::getInstance()->getValueMapFromFile(fileName);
    
    //parse the soldiers data
    auto arrayBullets = valueMap.at("bullets").asValueVector();
    for (int i = 0; i< arrayBullets.size(); i++) {
        auto valueMap = (arrayBullets[i]).asValueMap();
        int type = atoi((valueMap["type"]).asString().c_str());
        int isarea = atoi((valueMap["isarea"]).asString().c_str()) > 0 ? true : false;
        int issoldier = atoi((valueMap["issoldier"]).asString().c_str()) > 0 ? true : false;
        int istower = atoi((valueMap["istower"]).asString().c_str()) > 0 ? true : false;
        auto bulletParameter = BulletParameter::createWithData(type,
                                                               atoi((valueMap["level"]).asString().c_str()),
                                                                 valueMap["imagename"].asString(),
                                                                 atoi((valueMap["force"]).asString().c_str()),
                                                                 atoi((valueMap["scope"]).asString().c_str()),
                                                                 atoi((valueMap["speed"]).asString().c_str()),
                                                                 isarea,
                                                                 issoldier,
                                                                 istower
                                                                 );
        _bulletParameterVector.pushBack(bulletParameter);

    }
}