#ifndef REACHEDELEM_H
#define REACHEDELEM_H

enum reac{
unreached,
reached

};


class ReachedElem
{
    public:
        ReachedElem(DangerBoard);
        virtual ~ReachedElem();
        void setSize(int);
        void afisare();
        disp getValue(int, int);
    protected:
    private:
};

class DisplayedValues
{
    public:
        DisplayedValues();
        DisplayedValues(DangerBoard);
        virtual ~DisplayedValues();

    protected:
    private:
        disp values[31][31];
        int size;

};

#endif // REACHEDELEM_H
