//
//  MusicEffectButton.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef MenuMusicBackgroundButton_hpp
#define MenuMusicBackgroundButton_hpp

#include "PopMenuItemImage.hpp"
#include "cocos2d.h"

USING_NS_CC;

class MenuMusicBackgroundButton : public PopMenuItemImage {
public:
    virtual bool init() override;
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuMusicBackgroundButton);
    
private:
    SpriteFrame *onFrame;
    SpriteFrame *offFrame;
    
    void onButtonTouch(Ref* pSender);
    
};

#endif /* MenuMusicBackgroundButton_hpp */
