//
//  MusicEffectButton.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef MenuMusicEffectButton_hpp
#define MenuMusicEffectButton_hpp

#include "PopMenuItemImage.hpp"

#include "cocos2d.h"

USING_NS_CC;

class MenuMusicEffectButton : public PopMenuItemImage {
public:
    virtual bool init() override;
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuMusicEffectButton);
    
private:
    SpriteFrame *onFrame;
    SpriteFrame *offFrame;
    void onButtonTouch(Ref* pSender);
    
};

#endif /* MenuMusicEffectButton_hpp */
