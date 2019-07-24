#ifndef _SLOT_MENU_H_#define _SLOT_MENU_H_#include "cocos2d.h"USING_NS_CC;enum SlotMenuTag : unsigned int {    SlotMenuTagBackground = 101,    SlotMenuTagNewGame,    SlotMenuTagConfirmInterfaceNode};enum SlotMenuDrawingOrder : unsigned int {    SlotMenuDrawingOrderBackgound = 0,    SlotMenuDrawingOrder};class SlotMenu : public Sprite{public:	SlotMenu();	~SlotMenu();        static SlotMenu* createMenu(int num);        CREATE_FUNC(SlotMenu);        Size getSlotMenuSize();        CC_SYNTHESIZE(int, _number, Number);    private:	Label* _hintLabel;	Sprite* _background;    MenuItemSprite* _deleteButton;    virtual bool initWithNumber(int number);    void deleteRecord();        void createBackground();    void createNewGameInterface();    void createSaveSlotInterface();    void createConfirmInterface();        //for callback function    bool onTouchBackgroundBegan(Touch *touch, Event *event);    void onTouchBackgroundEnded(Touch *touch, Event *event);        void onTouchDeleteButtonCallback(Ref* pSender);    void onTouchConfirmDeleteCallback(Ref* pSender);    void onTouchCancelDeleteCallback(Ref* pSender);};#endif