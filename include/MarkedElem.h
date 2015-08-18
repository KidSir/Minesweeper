#ifndef MARKEDELEM_H
#define MARKEDELEM_H

enum mark{
unmarked,
marked
};

class MarkedElem
{
    public:
        MarkedElem(int _size);
        virtual ~MarkedElem();
        mark getValue(int i, int j);
        void setValue(int i, int j, mark val);
        void afisare();
    protected:
    private:
        mark values[31][31];
        int size;
};



#endif // MARKEDELEM_H
