//
//  PopMenuItemImage.cpp
//  KingdomRush
//
//  Created by kangbiao on 15/11/5.
//
//

#include "PopMenuItemImage.hpp"
/** The item was selected (not activated), similar to "mouse-over". */
void PopMenuItemImage::selected() {
    MenuItemImage::selected();
    this->setScale(1.2);
}


/** The item was unselected. */
void PopMenuItemImage::unselected() {
    MenuItemImage::unselected();
    this->setScale(1);
}