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

int main()
{
    GlobalTimer * GTimer = new GlobalTimer(GetMinSecond(), MainAlloc, MainFree);
    int* udata=GTimer->InitTimer<int>(1000, NULL, NULL);
    while(true)
    {
        GTimer->Tick(GetMinSecond());
    }
    cout << "Learn TimeWheel end" << endl;
    return 0;
}