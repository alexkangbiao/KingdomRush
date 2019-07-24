//
//  UserDefaultManager.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "UserDefaultManager.hpp"
#include "CommonDefine.h"
#include "Utility.h"

static UserDefaultManager* _userDefalutInstance = nullptr;

UserDefaultManager* UserDefaultManager::getInstance()
{
    if (!_userDefalutInstance)
    {
        _userDefalutInstance = new (std::nothrow) UserDefaultManager();
        CCASSERT(_userDefalutInstance, "FATAL: Not enough memory");
        _userDefalutInstance->init();
//        _userDefalutInstance->autorelease();
    }
    
    return _userDefalutInstance;
}

void UserDefaultManager::init() {
    
}

#pragma mark for common function
int UserDefaultManager::getIntegerForKey(std::string keyString) {
    return UserDefault::getInstance()->getIntegerForKey(keyString.c_str(), 1);
}

void UserDefaultManager::setIntegerForKey(std::string keyString, int value) {
    UserDefault::getInstance()->setIntegerForKey(keyString.c_str(), value);
}

#pragma mark for MUSIC  function
bool UserDefaultManager::checkBackgroundMusicState() {
    return UserDefault::getInstance()->getBoolForKey(USERDEFAULT_KEY_BACKGROUNDMUSIC, true);;
}

void UserDefaultManager::setBackgroundMusicState(bool isOpen) {
    UserDefault::getInstance()->setBoolForKey(USERDEFAULT_KEY_BACKGROUNDMUSIC, isOpen);
}


bool UserDefaultManager::checkEffectState() {
    return UserDefault::getInstance()->getBoolForKey(USERDEFAULT_KEY_MUSICEFFECT, true);
}

void UserDefaultManager::setEffectState(bool isOpen) {
    UserDefault::getInstance()->setBoolForKey(USERDEFAULT_KEY_MUSICEFFECT, isOpen);
}

