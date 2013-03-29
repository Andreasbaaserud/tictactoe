#ifndef GUI_H
#define GUI_H

class Gui
{
    public:
        Gui();
        void start();
        void rdy();
        void build();
        virtual ~Gui();
        int checkwinner();
        void clearWindow();
        void createBoard();
    protected:
    private:
        char square[10]; //sette antall avhengig av hvor stort brettet er
};


#endif // GUI_H
