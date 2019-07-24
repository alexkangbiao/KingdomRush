//
//  PopMenuItemImage.hpp
//  KingdomRush
//
//  Created by kangbiao on 15/11/5.
//
//

#ifndef PopMenuItemImage_hpp
#define PopMenuItemImage_hpp

#include "cocos2d.h"

USING_NS_CC;

class PopMenuItemImage : public cocos2d::MenuItemImage {
    virtual void selected() override;
    virtual void unselected() override;
};

#endif /* PopMenuItemImage_hpp */
