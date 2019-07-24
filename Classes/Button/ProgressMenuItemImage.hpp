//
//  PopMenuItemImage.hpp
//  KingdomRush
//
//  Created by kangbiao on 15/11/5.
//
//

#ifndef ProgressMenuItemImage_hpp
#define ProgressMenuItemImage_hpp

#include "cocos2d.h"

USING_NS_CC;

class ProgressMenuItemImage : public cocos2d::MenuItemImage {
    virtual void selected() override;
    virtual void unselected() override;
};

#endif /* ProgressMenuItemImage_hpp */
