//
//  MenuMusicEffectButton.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "MenuMusicEffectButton.hpp"
#include "UserDefaultManager.hpp"
#include "SoundManager.h"

bool MenuMusicEffectButton::init()
{
    if ( ! MenuItemImage::init() )
    {
        return false;
    }
    this->onFrame  = SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0003.png");
    this->offFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0004.png");
    
    if (UserDefaultManager::getInstance()->checkEffectState()) {
        this->setNormalSpriteFrame(onFrame);
    } else {
        this->setNormalSpriteFrame(offFrame);
    }
    this->setCallback(CC_CALLBACK_1(MenuMusicEffectButton::onButtonTouch, this));
    
    return true;
}

#pragma mark for touch function

void MenuMusicEffectButton::onButtonTouch(Ref* pSender) {
    //实现自己的逻辑代码
    SoundManager::playClickEffect();
    if (UserDefaultManager::getInstance()->checkEffectState()) {
        UserDefaultManager::getInstance()->setEffectState(false);
        this->setNormalSpriteFrame(offFrame);
    } else {
        UserDefaultManager::getInstance()->setEffectState(true);
        this->setNormalSpriteFrame(onFrame);
    }
}

