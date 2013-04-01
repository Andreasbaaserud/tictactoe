//Navn: Andreas Baaserud
//Studnr: s169982
//År: 2013

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
        void settings();
        void reprintBoard();
        int randomPlayer(int,int);
        int randomChoiceX();
        int randomChoiceY();
        void qPlayAgain();
    protected:
    private:
        int gameType;
        int choiceX,choiceY;
        char arr[999][999]; //rett måte?
};


#endif // GUI_H
