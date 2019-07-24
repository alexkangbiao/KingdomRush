#ifndef _CircleBase_H_#define _CircleBase_H_#include "cocos2d.h"USING_NS_CC;class CircleBase : public Sprite {    public:    bool initWithScaleXFactorAndFileName(float scaleXFactor, std::string filename);        Size getCircleSize();private:    float _scaleXFactor;    Sprite* _circleLeftTop;    Sprite* _circleRightTop;    Sprite* _circleRightBottom;    Sprite* _circleLeftBottom;    protected:    void setScaleXFactor(float scaleXFactor);};#endif