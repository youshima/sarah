/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
-----------------------------------------------------------------------------

This source file is part of the
  _________                       .__   PROJECT 
 /   _____/_____  _______ _____   |  |__  
 \_____  \ \__  \ \_  __ \\__  \  |  |  \ 
 /        \ / __ \_|  | \/ / __ \_|   Y  \
/_______  /(____  /|__|   (____  /|___|  /
        \/      \/             \/      \/                           
-----------------------------------------------------------------------------
*/
#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"

#define _ATL_APARTMENT_THREADED

//#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override something,
//but do not change the name of _Module
//extern CComModule _Module;
//#include <atlcom.h>

#include "SAPI.h"

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);

protected:
    virtual void createScene(void);
};

#endif // #ifndef __TutorialApplication_h_
