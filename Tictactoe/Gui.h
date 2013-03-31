#ifndef GUI_H
#define GUI_H

class Gui
{
    public:
        Gui();
        void start();
        void rdy(); //Metode som spør om du vil starte eller ikke
        void build();//Metode for å legge inn 'X' eller 'O'
        virtual ~Gui();
        int checkwinner();//Algoritme for sjekk av vinner/uavgjort
        void clearWindow();//Blanker ut terminalen WIN/LINUX
        void createBoard();//Oppretter arr[][]
        void reprintBoard();//Printer spillbrettet
//        void createSquareH();
//        void createSquareV();
        int randomPlayer(int,int);//Random hvilken spiller som starter
        int randomChoiceX();//Random tall for X-akse
        int randomChoiceY();//Random tall for Y-akse
    protected:
    private:
        int gameType;
        int choiceX,choiceY;
        char arr[999][999]; //rett måte?
};


#endif // GUI_H
