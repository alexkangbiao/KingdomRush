#include "UpdatePanleLayerWithFlag.h"#include "GameManager.h"#include "BaseBuildIcon.h"#include "TouchLayer.h"#include "BaseMap.h"USING_NS_CC;bool UpdatePanleLayerWithFlag::init(){    if ( !UpdatePanelLayer::init() )    {        return false;    }	return true;}void UpdatePanleLayerWithFlag::addOthersIcons(){    _flag = Sprite::createWithSpriteFrameName("sub_icons_0001.png");    _flag->setPosition(Point(_ringBackgroundSprite->getContentSize().width / 4 + _flag->getContentSize().width / 2 ,                             - _ringBackgroundSprite->getContentSize().height / 3.2));    _flag->setVisible(false);    this->addChild(_flag, PanelLayerDrawingOrderIcon);        _flag->setVisible(true);        auto flagListener = EventListenerTouchOneByOne::create();    flagListener->onTouchBegan = CC_CALLBACK_2(UpdatePanleLayerWithFlag::onFlagTouchBegan, this);    flagListener->onTouchEnded = CC_CALLBACK_2(UpdatePanleLayerWithFlag::onFlagTouchEnded, this);    flagListener->setSwallowTouches(true);    _eventDispatcher->addEventListenerWithSceneGraphPriority(flagListener, _flag);}bool UpdatePanleLayerWithFlag::onFlagTouchBegan(Touch *touch, Event *event){    auto target = static_cast<Sprite*>(event->getCurrentTarget());        Point locationInNode = target->convertTouchToNodeSpace(touch);        Size size = target->getContentSize();    Rect rect = Rect(0, 0, size.width, size.height);    if (rect.containsPoint(locationInNode))    {        return true;    }    return false;}void UpdatePanleLayerWithFlag::onFlagTouchEnded(Touch* touch, Event* event){    static_cast<TouchLayer*>(this->getParent())->setTower(this->getTower());    static_cast<TouchLayer*>(this->getParent())->setRallyFlagTouchShield();    tower->_isUpdateMenuShown = false;    this->removeFromParent();}