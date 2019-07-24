#include "UpgradeIcon.h"USING_NS_CC;UpgradeIcon* UpgradeIcon::createNewIcons(std::string onPictureName,                                         std::string offPictureName,                                         std::string iconName,                                         std::string iconIntroduction,                                         int starNumber,                                         UpgradeIconsStatus iconStatus,                                         int row,                                         int column){    auto pRet = new UpgradeIcon();        if (pRet && pRet->initNewIcons(onPictureName,                                   offPictureName,                                   iconName,                                   iconIntroduction,                                   starNumber,                                   iconStatus,                                   row,                                   column))    {        pRet->autorelease();        return pRet;    }    CC_SAFE_DELETE(pRet);    return NULL;}bool UpgradeIcon::initNewIcons(std::string onPictureName,                               std::string offPictureName,                               std::string iconName,                               std::string iconIntroduction,                               int starNumber,                               UpgradeIconsStatus iconStatus,                               int row,                               int column) {    if ( !Sprite::init() ) {        return false;    }        _onPictureName  = onPictureName;    _offPictureName = offPictureName;    switch (iconStatus)    {        case UpgradeIconsStatusDisable:            _icon = Sprite::createWithSpriteFrameName(offPictureName);            break;                    case UpgradeIconsStatusEnable:            _icon = Sprite::createWithSpriteFrameName(onPictureName);            break;                    default:            _icon = Sprite::createWithSpriteFrameName(onPictureName);            break;    }    //初始化三种类型的状态        _buyIcon     = Sprite::createWithSpriteFrameName("upgrades_icons_0032.png");    _selectIcon  = Sprite::createWithSpriteFrameName("upgrades_icons_0031.png");        this->addChild(_icon, UpgradeIconsDrawingOrderIcon);    this->addChild(_selectIcon, UpgradeIconsDrawingOrderSelectIcon);    this->addChild(_buyIcon, UpgradeSceneDrawingOrderBuyIcon);        _selectIcon->setVisible(false);    _buyIcon->setVisible(false);    //    _starIcon = Sprite::createWithSpriteFrameName("");//    this->addChild(_starIcon, UpgradeSceneDrawingOrderStarIcon);            _starNumberLabel = Label::createWithBMFont("fonts/bmfont.fnt", StringUtils::format("%d", starNumber).c_str());//    _starNumberLabel->setPosition(Point(_buyIcon->getContentSize().width * 0.85,//                                        _buyIcon->getContentSize().height * 0.63));    this->addChild(_starNumberLabel, UpgradeSceneDrawingOrderStarIcon);    this->_iconName         = iconName;    this->_iconIntroduction = iconIntroduction;    this->_iconStatus  = iconStatus;    this->_starNumber  = starNumber;    this->_iconRow     = row;    this->_iconColumn  = column;    return true;}SpriteFrame* UpgradeIcon::getIconSpriteFrame() {    return this->_icon->getSpriteFrame();}Size UpgradeIcon::getIconContentSize() {    return this->_icon->getContentSize();}void UpgradeIcon::setIconSelected(bool select){    _selectIcon->setVisible(select);}void UpgradeIcon::setIconStatus(UpgradeIconsStatus iconStatus){    switch (iconStatus)    {        case UpgradeIconsStatusDisable:            _icon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(_offPictureName));            this->_buyIcon->setVisible(false);            break;        case UpgradeIconsStatusEnable:            _icon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(_onPictureName));            this->_buyIcon->setVisible(false);            break;        case UpgradeIconsStatusBuy:            _icon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(_onPictureName));            this->_buyIcon->setVisible(true);            break;        default:            _icon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(_onPictureName));            break;    }    this->_iconStatus = iconStatus;}UpgradeIconsStatus UpgradeIcon::getIconStatus(){    return this->_iconStatus;}