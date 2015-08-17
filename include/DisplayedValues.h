#ifndef DISPLAYEDVALUES_H
#define DISPLAYEDVALUES_H
#include "dispEnum.h"

class DangerBoard;

class DisplayedValues
{
    public:
        DisplayedValues();
        DisplayedValues(DangerBoard);
        virtual ~DisplayedValues();
        void setSize(int);
        void afisare();
    protected:
    private:
        disp values[31][31];
        int size;

};

#endif // DISPLAYEDVALUES_H
