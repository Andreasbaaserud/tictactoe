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
        void reprintBoard();
//        void createSquareH();
//        void createSquareV();
        int randomPlayer(int,int);
        int randomChoice1();
        int randomChoice2();
    protected:
    private:
        int gameType;
        int choiceX,choiceY;
        char arr[999][999]; //rett måte?
};


#endif // GUI_H
