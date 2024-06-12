#ifndef WKEXE_APP_H
#define WKEXE_APP_H

#include "cmdline.h"
#include "G:/mycode/miniblink57/wke/wkedefine.h"

typedef struct {
    CommandOptions options;
    WCHAR url[kMaxUrlLegth + 1];
} Application;


void runApplication(Application* app);

#endif//#ifndef WKEXE_APP_H