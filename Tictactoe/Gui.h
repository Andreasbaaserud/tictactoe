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
        void createSquareH();
        void createSquareV();
    protected:
    private:
        int gameType;
        char arr[999][999]; //få til å oppdatere arrayet til 8........
//        char square[999]; //sette antall avhengig av hvor stort brettet er
};


#endif // GUI_H
