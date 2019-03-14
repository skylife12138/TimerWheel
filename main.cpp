#include<iostream>
#include <time.h>
#include "TimeWheel.h"
using namespace std;

int GetMinSecond()
{
    int NowSecond = (int)time(NULL);
    return NowSecond;
}

static void* MainAlloc(int size)
{
    return malloc(size);
}

static void MainFree(void* p,int size)
{
    free(p);
}

static void TestPrint(GlobalTimer* gtimer,GTimerList* t1,void* udata,int size)
{
    cout << "testprint right!!!" << endl;
}

int main()
{
    cout << "TimeWheel Begin" << endl;
    GlobalTimer * GTimer = new GlobalTimer(GetMinSecond(), MainAlloc, MainFree);
    int* udata=GTimer->InitTimer<int>(10, TestPrint, NULL);
    while(GTimer->Size()>0)
    {
        GTimer->Tick(GetMinSecond());
    }
    cout << "Learn TimeWheel end" << endl;
    return 0;
}