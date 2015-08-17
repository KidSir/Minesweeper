#ifndef DANGERBOARD_H
#define DANGERBOARD_H

enum dang{
mined = -1,
safe,
dangerous,
};

class DangerBoard
{
    public:
        DangerBoard(int);
        void reset();
        void addMines(int nrMines);
        void afisare();
        void addDangerZones();
        virtual ~DangerBoard();
    protected:
    private:
        dang zones[31][31];
        int size;
};

#endif // DANGERBOARD_H
