#ifndef _ArrowBase_H_#define _ArrowBase_H_#include "SoundManager.h"#include "cocos2d.h"#include "GameManager.h"#include "BaseMonster.h"#include "ArrowBulletBase.h"USING_NS_CC;class ArrowBase : public ArrowBulletBase{protected:        //设置子弹的个性化参数配置    virtual void addAdditionalParameterConfig();};#endif