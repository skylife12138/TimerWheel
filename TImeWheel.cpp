#include "TimeWheel.h"

void TM_SetDela(GTimerList *t1, int dt)
{
    t1->Delta = dt;
}

int  TM_GetDela(GTimerList *t1)
{
    return t1->Delta;
}

void TM_SetTimerFunc(GTimerList *t1, GTimerFunc func)
{
    t1->Func= func;
}

GTimerList *TM_GetTimer(void* udata)
{
    return (GTimerList *)udata - 1;
}

GlobalTimer::~GlobalTimer()
{

}

void GlobalTimer::*InitTimer(int dt, GTimerFunc func, int size, GDeleteFunc delFunc);