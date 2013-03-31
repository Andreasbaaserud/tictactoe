#include "Gui.h"
#include <iostream>
#include "stdlib.h"
#include <sstream>

using namespace std;

//Sette valg for om man vil at computer skal spille, eller manuelt..
//TODO: Gjøre det enklere å plassere brikker(foreløpig koordinater)
//TODO: Kompilere på linux(Studssh)

string input = "";
string boardSize = "0";
string answer = "";
bool machine = false;
int antallRuter = 0;
int rounds = 0;

Gui::Gui()
{
    cout << "Welcome to Tic Tac Toe (NxN)" << endl;
    cout << "Rules are Simple:" << endl;
    cout << "1) Player 1 will be marked with an 'X'" << endl;
    cout << "2) Player 2 will be marked with an 'O'" << endl;
    cout << "3) You write the X and Y coordinates where you want to place your letter." << endl;
    cout << endl;
    cout << "Important note:" << endl;
    cout << "1) Avoid the player you play against to get 3 letters vertically, horisontally or diagonaly" << endl;
    cout << "2) coordinates starts at 0,0 and ends at n,n" << endl;
    cout << "3) it is random who will start" << endl;
    cout << endl;

    cout << "Lets get roling and play the game!" << endl;
    cout << endl;
    rdy();
}

void Gui::start(){
    createBoard();
    build();
}

int Gui::randomPlayer(int a, int b){
    srand(time(NULL));
    int r = rand()%2;
    if(r == 0)
        return a;
    else
        return b;
}

int Gui::randomChoice1(){
    return rand() % gameType;
}

int Gui::randomChoice2(){
    return rand() % gameType;
}

void Gui::build(){
    int holdPlayer;
    //setter inn verdien '#' i arrayet
    for(int i = 0; i < gameType; i++){
        for(int j = 0; j < gameType; j++){
            arr[i][j] = '#';
        }
    }

    int player = randomPlayer(1,2),p;
    cout << "Machine vs Machine?(y/n): ";
    cin >> answer;
    if(answer == "y")
        machine = true;
    else if(answer == "n")
        machine = false;

    do{
        if(machine){
            srand(time(NULL));
            choiceX = randomChoice1();
            choiceY = randomChoice2();
        }
        reprintBoard();
        cout << "Player " << player << endl;
        if(!machine){
            cout << "enter X coord: ";
            cin >> choiceX;
            cout << "enter Y coord: ";
            cin >> choiceY;
        }
        if(arr[choiceX][choiceY] == '#')
            arr[choiceX][choiceY] = (player == 1) ? 'X' : 'O';
        else if(player == 1){ //invalid move
            player++;
            rounds--;
        }
        else if(player == 2){//invalid move
            player --;
            rounds--;
        }

        holdPlayer = player;
        p=checkwinner();
        if(player == 1)
            player++;
        else if(player == 2)
            player--;
    }while(p == -1);

    if(p == 1){
        reprintBoard();
        cout << "\aPlayer " << holdPlayer << " win" << endl;
    }
    else{
        reprintBoard();
        cout << "\aGame draw" << endl;
    }
    //ctor
}

void Gui::reprintBoard(){
    //skriver ut arrayet
    clearWindow();
    for(int i = 0; i < gameType; i++){

        for(int j = 0; j < gameType; j++){
            cout << "[";
            cout << arr[i][j] << "] \t";
        }
        cout << endl << endl;
    }
}

int Gui::checkwinner(){
    bool win = false;

    //sjekker rader for 'X'
    for(int i = 0; i < gameType; i++){
            if(arr[choiceX][i] != 'X')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker rader for 'O'
    for(int i = 0; i < gameType; i++){
            if(arr[choiceX][i] != 'O')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker kolonner for 'X'
    for(int i = 0; i < gameType; i++){
            if(arr[i][choiceY] != 'X')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker kolonner for 'O'
    for(int i = 0; i < gameType; i++){
            if(arr[i][choiceY] != 'O')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker diagonalen for 'X'
    for(int i = 0; i < gameType; i++){
            if(arr[i][i] != 'X')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker diagonalen for 'O'
    for(int i = 0; i < gameType; i++){
            if(arr[i][i] != 'O')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker anti-diagonalen for 'X'
    for(int i = 0; i < gameType; i++){
            if(arr[i][(gameType-1)-i] != 'X')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker anti-diagonalen for 'O'
    for(int i = 0; i < gameType; i++){
            if(arr[i][(gameType-1)-i] != 'O')
                break;
            if(i == gameType-1)
                win = true;
    }

    rounds++;
    if(win)
        return 1; //X eller O har vunnet
    else if(rounds == (gameType*gameType))
        return 2; //Draw
    else
        return -1; //Foreløpig ingen vinnere
}

void Gui::rdy(){
            input == "";
            cout << "Ready to start?(y/n):" << ends;
            getline(cin, input);
            if(input == "y"){
                clearWindow();
                Gui::start();
            }
            else if(input == "n"){
                system("exit");
            }
}

void Gui::createBoard(){
    do{
    cout << "Oppgi brettstorrelse (mellom 3 og n): " << ends;
    getline(cin, boardSize);
    stringstream convert(boardSize);
    if( !(convert >> gameType))
            gameType = 0; //hvis resultat ikke får noen verdi blir resultat satt default til 0
    }while(gameType == NULL || gameType == 0 || gameType == 1 || gameType == 2 || gameType < 0);
}

//Implimenterer automatisk generering av brettet senere..
/*void Gui::createSquareH(){
    cout << "_______" << ends;
//    cout << "|     |" << endl;
//    cout << "|     |" << endl;
//    cout << "|_____|" << ends;
}

void Gui::createSquareV(){
    cout << "|         " << endl;
//    cout << "_______" << endl;
//    cout << "|     |" << endl;
//    cout << "|     |" << endl;
//    cout << "|_____|" << endl;
}*/

void Gui::clearWindow(){
    //Sjekker om systemet kjøres på windows eller linux
    //kall på metoden vil gjøre skjermen fri for tekst
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system("cls");  //Gjør skjermen fri for tekst i windows command prompt

    #else
        system("clear"); //Gjør skjermen fri for tekst i linux shell
    #endif
}

Gui::~Gui()
{
    //dtor
}
