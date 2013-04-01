//Navn: Andreas Baaserud
//Studnr: s169982
//År: 2013

#include "Gui.h"
#include <iostream>
#include "stdlib.h"
#include <sstream>
#include <time.h>
#include <unistd.h>

using namespace std;

string input = "";
string playAgain = "";
string boardSize = "0";
string answer = "";
bool slow = false;
bool machine = false;
int antallRuter = 0;
int rounds = 0;

Gui::Gui()
{
    cout << "Welcome to Tic Tac Toe (NxN)" << endl;
    cout << "*******************************" << endl;
    cout << "**          Created by       **" << endl;
    cout << "**       Andreas Baaserud    **" << endl;
    cout << "**             2013          **" << endl;
    cout << "*******************************" << endl;
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
    settings();
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

int Gui::randomChoiceX(){
    return rand() % gameType;
}

int Gui::randomChoiceY(){
    return rand() % gameType;
}

void Gui::build(){
    srand(time(0));
    int holdPlayer; //Sparer på player
    //setter inn verdien '#' i arrayet
    for(int i = 0; i < gameType; i++){
        for(int j = 0; j < gameType; j++){
            arr[i][j] = '#';
        }
    }

    int player = randomPlayer(1,2);
    int p;
    do{
        if(machine){
            choiceX = randomChoiceX();
            choiceY = randomChoiceY();
        }

        if(!machine){
            cout << "enter X coord: ";
            cin >> choiceX;
            cout << "enter Y coord: ";
            cin >> choiceY;
        }

        if(arr[choiceX][choiceY] == '#' ){
            arr[choiceX][choiceY] = (player == 1) ? 'X' : 'O';
            reprintBoard();
            cout << "Player " << player << " coords: " << choiceX << "," << choiceY << endl;
        }
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
        cout << "******************" << endl;
        cout << "** Player " << holdPlayer << " won **" << endl;
        cout << "******************" << endl;
        cout << endl;
        qPlayAgain();
    }
    else{
        reprintBoard();
        cout << "***************" << endl;
        cout << "** Game draw **" << endl;
        cout << "***************" << endl;
        cout << endl;
        qPlayAgain();
    }
    //ctor
}

void Gui::qPlayAgain(){
    playAgain = "";
    cout << "Play again(y/n)? " << ends;
    cin >> playAgain;
    cout << endl;
    if(playAgain == "y"){
        rounds = 0;
        start();
    }
    else if(playAgain == "n")
        system("exit");

    }

void Gui::reprintBoard(){
    //skriver ut arrayet på nytt
    if(slow){
        sleep(1);
    }
    clearWindow();
    for(int i = 0; i < gameType; i++){
        for(int j = 0; j < gameType; j++){
            cout << "[";
            if(arr[i][j] == '#'){
                cout << i << "," <<j;
            }
            else{
                cout << arr[i][j];
            }
            cout << "] \t";
        }
        cout << endl << endl;
    }
}

int Gui::checkwinner(){
    bool win = false;

    //Legge til sjekk om draw før alle ruter er utfylt

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

void Gui::settings(){
    cout << "***GAME SETTINGS***" << endl;
    cout << "Choose boardsize (between 3 and n): " << ends;
    do{
    getline(cin, boardSize);
    stringstream convert(boardSize);

    if( !(convert >> gameType))
            gameType = 0; //hvis resultat ikke får noen verdi blir resultat satt default til 0
    }while(gameType == 1 || gameType == 2 || gameType <= 0);

    cout << "Machine vs Machine?(y/n): ";
    cin >> answer;
    if(answer == "y"){
        answer = "";
        machine = true;
        cout << "Wish to view in slow motion?(y/n): ";
        cin >> answer;
        if(answer == "y")
            slow = true;
        if(answer == "n")
            slow = false;
    }
    else if(answer == "n"){
        machine = false;
    }
}

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
