#include "WaveAnimation.h"USING_NS_CC;WaveAnimation::WaveAnimation(){};WaveAnimation::~WaveAnimation(){};bool WaveAnimation::init(Sprite* baseSprite, ValueMap animationMap) {    if ( ! Node::init() ) {        return false;    }    _baseSprite = baseSprite;    _waveNumber = atoi((animationMap["wavenumber"]).asString().c_str());    int from = atoi((animationMap["from"]).asString().c_str());    int to   = atoi((animationMap["to"]).asString().c_str());    _delay   = atof((animationMap["delay"]).asString().c_str());        Vector<SpriteFrame*> animationVector;    SpriteFrame* frame = nullptr;    for (int i = from; i <= to; i++) {        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(                        StringUtils::format((animationMap["animationimagename"]).asString().c_str(), i).c_str());        if (frame != nullptr) _animationVector.pushBack(frame);    }    	return true;}WaveAnimation* WaveAnimation::create(Sprite* baseSprite, ValueMap animationMap){      auto waveAnimation = new WaveAnimation();	if (waveAnimation && waveAnimation->init(baseSprite, animationMap)) {		waveAnimation->autorelease();		return waveAnimation;	}	CC_SAFE_DELETE(waveAnimation);    return NULL;}void WaveAnimation::playAnimation() {    this->_baseSprite->runAction(Animate::create(Animation::createWithSpriteFrames(_animationVector, _delay)));}