//
//  MonsterManager.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "MonsterManager.hpp"


static MonsterManager* _monsterManagerInstance = nullptr;

MonsterManager* MonsterManager::getInstance()
{
    if (!_monsterManagerInstance) {
        _monsterManagerInstance = new (std::nothrow) MonsterManager();
        CCASSERT(_monsterManagerInstance, "FATAL: Not enough memory");
        _monsterManagerInstance->init();
//        _monsterManagerInstance->autorelease();
    }
    
    return _monsterManagerInstance;
}

void MonsterManager::init() {
    this->readDataFromFile();
}

MonsterParameter* MonsterManager::getParameterByType(int monsterType) {
    if (_monsterParameterMap.at(monsterType)) {
        return _monsterParameterMap.at(monsterType);
    } else {
        return _monsterParameterMap.at(0);
        log("load monster has error type : %d", monsterType);
    }
}

void MonsterManager::readDataFromFile() {
    std::string fileName = "xml/monster_detail.plist";
    auto valueMap = FileUtils::getInstance()->getValueMapFromFile(fileName);
    
    //parse the terrains data
    auto arrayMonsters = valueMap.at("monsters").asValueVector();
    for (int i = 0; i< arrayMonsters.size(); i++) {
        auto valueMap = (arrayMonsters[i]).asValueMap();
        int type = atoi((valueMap["type"]).asString().c_str());
        bool attackbysoldier = (valueMap["attackbysoldier"]).asString() == "TRUE" ? true : false;
        bool attackbytower = (valueMap["attackbytower"]).asString() == "TRUE" ? true : false;
        bool haveChildren  = (valueMap["havechildren"]).asString() == "1" ? true : false;
        bool isfly         = (valueMap["isfly"]).asString() == "1" ? true : false;

        auto monsterParameter = MonsterParameter::createWithData(type,
                                                                 valueMap["name"].asString(),
                                                                 valueMap["baseimage"].asString(),
                                                                 valueMap["bloodcolor"].asString(),
                                                                 atoi((valueMap["maxhp"]).asString().c_str()),
                                                                 atoi((valueMap["money"]).asString().c_str()),
                                                                 atoi((valueMap["force"]).asString().c_str()),
                                                                 atoi((valueMap["armor"]).asString().c_str()),
                                                                 atoi((valueMap["speed"]).asString().c_str()),
                                                                 attackbysoldier,
                                                                 attackbytower,
                                                                 haveChildren,
                                                                 atoi(valueMap["childrentype"].asString().c_str()),
                                                                 isfly,
                                                                 valueMap["portraitsimagename"].asString(),
                                                                 valueMap["portraitsname"].asString()
                                                                 );
        _monsterParameterMap.insert(type, monsterParameter);
//        log("%d, %s, %s, %s, %d, %d, %d, %d, %d",
//            type,
//            monsterParameter->getName().c_str(),
//            monsterParameter->getBaseImageName().c_str(),
//            monsterParameter->getBloodColor().c_str(),
//            monsterParameter->getMaxHP(),
//            monsterParameter->getMoney(),
//            monsterParameter->getForce(),
//            monsterParameter->getArmor(),
//            monsterParameter->getSpeed()
//            );
    }
}