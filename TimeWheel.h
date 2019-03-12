#ifndef _TIME_WHEEL_H
#define _TIME_WHEEL_H

#include "List.h"
#include<stddef.h>
#include<assert.h>

struct GTimerList;
class GlobalTimer;

typedef void (*GTimerFunc)(GlobalTimer *gtimer, GTimerList *t1, void *udata, int size);
typedef void (*GDeleteFunc)(void *udata, int size);

struct GTimerList
{
    struct list_head lst;
    int Expire;
    int Delta;
    GTimerFunc Func;
    int size;
    void *udata;
    GDeleteFunc delFunc;
};

class GlobalTimer
{
    GlobalTimer(const GlobalTimer &);
    GlobalTimer &operator=(const GlobalTimer &);
  public:
    ~GlobalTimer();
    explicit GlobalTimer(int gtick,void*(*alloc)(int),void (*dealloc)(void*,int));
    template<class T> inline T* InitTimer(int dt,GTimerFunc func, GDeleteFunc delFunc)
    {
        void *udata = InitTimer(dt, func, sizeof(T), delFunc);
        return (T *)udata;
    }
    void *InitTimer(int dt, GTimerFunc func, int size, GDeleteFunc delFunc);
    void AddTimer(GTimerList *t1);
    void Tick(int gtick);
    int Size() { return mSize; }
    void DelTimer(GTimerList *t1);
    void SetTimer(GTimerList *t1, int expire);
    int GetExpire(GTimerList *t1);

  private:
    void DestoryTimer(GTimerList *t1);
    void OneTick();
    bool Cascade(int base, int index);
    void AddTimerImpl(GTimerList *t1);

    struct list_head mRotary[256 * 4];
    int mGTick;
    int mSize;
    struct list_head mErase;
    void *(*mAlloc)(int);
    void (*mDealloc)(void *, int);
};

void TM_SetDela(GTimerList *t1, int dt);
int  TM_GetDela(GTimerList *t1);
void TM_SetTimerFunc(GTimerList *t1, GTimerFunc func);
GTimerList *TM_GetTimer(void* udata);

template<class T>
inline T* GT_UserData(void* udata,int size)
{
    assert(size>=sizeof(T));
    if(size>=sizeof(T))
        return (T *)udata;
    return 0;
}



#endif