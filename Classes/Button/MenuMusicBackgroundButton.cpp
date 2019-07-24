//
//  MenuMusicBackgroundButton.cpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#include "MenuMusicBackgroundButton.hpp"
#include "UserDefaultManager.hpp"
#include "SoundManager.h"

bool MenuMusicBackgroundButton::init()
{
    if ( ! MenuItemImage::init() )
    {
        return false;
    }

    this->onFrame  = SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0001.png");
    this->offFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0002.png");
    
    if (UserDefaultManager::getInstance()->checkBackgroundMusicState()) {
        this->setNormalSpriteFrame(onFrame);
    } else {
        this->setNormalSpriteFrame(offFrame);
    }
    this->setCallback(CC_CALLBACK_1(MenuMusicBackgroundButton::onButtonTouch, this));
    
    return true;
}

#pragma mark for touch function

void MenuMusicBackgroundButton::onButtonTouch(Ref* pSender) {
    //实现自己的逻辑代码
    SoundManager::playClickEffect();
    if (UserDefaultManager::getInstance()->checkBackgroundMusicState()) {
        UserDefaultManager::getInstance()->setBackgroundMusicState(false);
        this->setNormalSpriteFrame(this->offFrame);
    } else {
        UserDefaultManager::getInstance()->setBackgroundMusicState(true);
        this->setNormalSpriteFrame(this->onFrame);
    }
}

