#ifndef REVEALEDELEM_H
#define REVEALEDELEM_H

enum rev
{
    revealed,
    hidden
};
class RevealedElem
{
    public:
        RevealedElem(int _size);
        rev getState(int, int);
        void setState(int, int, rev state);
        void init_board();

        virtual ~RevealedElem();
    protected:
    private:
        int size;
        rev board[31][31];
};

#endif // REVEALEDELEM_H
