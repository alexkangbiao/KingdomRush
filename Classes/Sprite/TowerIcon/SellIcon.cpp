#include "SellIcon.h"bool SellIcon::init(){	if (!Sprite::init()) {		return false;	}	_isSelected = false;	_isMoneyEnough = true;	_baseIcon = Sprite::createWithSpriteFrameName("ico_sell_0001.png");	this->addChild(_baseIcon);	_confirmIcon = Sprite::createWithSpriteFrameName("ico_sell_0002.png");	_confirmIcon->setPosition(Point(_baseIcon->getContentSize().width  / 2,                                    _baseIcon->getContentSize().height / 2));	_confirmIcon->setVisible(false);    _baseIcon->addChild(_confirmIcon);	return true;}