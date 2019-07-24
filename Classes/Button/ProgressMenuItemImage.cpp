//
//  PopMenuItemImage.cpp
//  KingdomRush
//
//  Created by kangbiao on 15/11/5.
//
//

#include "ProgressMenuItemImage.hpp"
/** The item was selected (not activated), similar to "mouse-over". */
void ProgressMenuItemImage::selected() {
    MenuItemImage::selected();
    this->setScale(1.2);
}


/** The item was unselected. */
void ProgressMenuItemImage::unselected() {
    MenuItemImage::unselected();
    this->setScale(1);
}