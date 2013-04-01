Navn: Andreas Baaserud
Studnr: s169982
År: 2013

Oppgave: 1

Spillet består av totalt 2 cpp filer og 1 header file

cpp filer: Gui.cpp og main.cpp
header filer: Gui.h

i Gui.cpp ligger all funksjonalitet og grafisk grensesnitt
i main.cpp ligger kun et objekt av Gui.

Metoder:
    public:
        Gui(); //Konstruktør som inneholder en velkomstmelding
        void start(); //Kaller på settings() og build()
        void rdy(); //Metode som spør om du vil starte eller ikke
        void build();//Metode for å legge inn 'X' eller 'O' i rutenettet(arrayet)
        virtual ~Gui();
        int checkwinner();//Metode som består av en algoritme for sjekk av vinner eller om det er uavgjort mellom spillerene.
        void clearWindow();//Blanker ut terminalen i WIN eller LINUX
        void settings();//Inneholder spørsmål til brukeren. I denne metoden kan man velge størrelsen på brettet, om det skal være maskin vs maskin eller spiller vs spiller og om spillet skal kjøres i sakte fart ved maskin vs maskin.
        void reprintBoard();//Printer spillbrettet
        int randomPlayer(int,int);//En metode som velger tilfeldig hvilken spiller som starter(spiller 1 eller 2)
        int randomChoiceX();//Random tall for X-akse, ved bruk av maskin vs maskin
        int randomChoiceY();//Random tall for Y-akse, ved bruk av maskin vs maskin
        void qPlayAgain(); //En metode som spør om brukeren ønsker å spille en runde til.
    private:
        int gameType; //Holder på brettstørrelse
        int choiceX,choiceY; //Holder på koordinatene.
        char arr[999][999]; //Holderpå arrayet, usikker på om dette er rett måte?
