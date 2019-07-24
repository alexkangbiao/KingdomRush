//
//  UserDefaultManager.hpp
//  MathOlympic
//
//  Created by kangbiao on 15/11/2.
//
//

#ifndef UserDefaultManager_hpp
#define UserDefaultManager_hpp

#include "cocos2d.h"

USING_NS_CC;

class UserDefaultManager : public Ref {
public:
    static UserDefaultManager * getInstance();
    
    //common function
    int getIntegerForKey(std::string keyString);
    void setIntegerForKey(std::string keyString, int value);
   
    //for Music Data Function
    bool checkBackgroundMusicState();
    void setBackgroundMusicState(bool isOpen);
    
    bool checkEffectState();
    void setEffectState(bool isOpen);
    
    //for slot save data
    
private:
    UserDefaultManager() {
        this->init();
    }
    void init();
    

};


#endif /* UserDefaultManager_hpp */
