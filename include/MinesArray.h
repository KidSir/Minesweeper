#ifndef MINESARRAY_H
#define MINESARRAY_H


class MinesArray
{
    public:
        MinesArray(int);
        void reset();
        void addMines(int nrMines);
        void afisare();
        virtual ~MinesArray();
    protected:
    private:
        int mines[31][31];
        int size;
};

#endif // MINESARRAY_H
