#ifndef DANGERBOARD_H
#define DANGERBOARD_H
#include "dispEnum.h"
#include "dangEnum.h"


class DangerBoard
{
    public:
        DangerBoard(int);
        void reset();
        void addMines(int nrMines);
        void afisare();
        void addDangerZones();
        int getSize();
        disp getNearbyMines(int, int);
        dang getValue(int, int);
        virtual ~DangerBoard();
    protected:
    private:
        dang zones[31][31];
        int size;
};

#endif // DANGERBOARD_H
