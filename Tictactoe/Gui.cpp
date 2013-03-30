#include "Gui.h"
#include <iostream>
#include "stdlib.h"
#include <sstream>

using namespace std;


//TODO: Random hvem som starter, X eller O
//TODO: Gjøre det enklere å plassere brikker(foreløpig koordinater)
//TODO: Kompilere på linux(Studssh)

string input = "";
string boardSize = "0";
int antallRuter = 0;
int rounds = 0;
int choice1,choice2;
Gui::Gui()
{
    cout << "Welcome to Tic Tac Toe" << endl;
    cout << "Rules are Simple: \n" << endl;
    cout << "1) Player 1 will be marked with an 'X'" << endl;
    cout << "2) Player 2 will be marked with an 'O'" << endl;
    cout << "3) You write the number where you want to place your letter." << endl;
    cout << endl;
    cout << "#Important note: Avoid the player you play against to get 3 letters vertically, horisontally or diagonaly" << endl;
    cout << endl;
    cout << "This is how it will look like! amazing right?" << endl;
    //ctor
    cout << "Player 1 (X)  -   Player 2 (O)" << endl << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "     |     |     " << endl << endl;
    cout << "Lets get roling and play the game!" << endl;
    cout << endl;
//    for(int i = 0; i < sizeof(square); i++){
//        square[i] = antallRuter++;
//    }
    rdy();
}

void Gui::start(){
    createBoard();
    build();
}

void Gui::build(){
    //setter inn verdier i arrayet
//    int ant = 0;
//    int arr[gameType][gameType];
    for(int i = 0; i < gameType; i++){
        for(int j = 0; j < gameType; j++){
            arr[i][j] = '#';
        }
    }
    int player = 1,p;
//    int mark;
    do{
        reprintBoard();
        player=(player%2)?1:2;
        cout << "Player " << player << endl;
        cout << "enter X coord: ";
        cin >> choice1;
        cout << "enter Y coord: ";
        cin >> choice2;

        if(arr[choice1][choice2] == '#'){
            arr[choice1][choice2] = (player == 1) ? 'X' : 'O';
        }
        else{
            player--; //gjør så man ikke mister et trekk
        }
        /*mark = (player == 1) ? 11 : 22; //999 = X, 000 = O
        if(choice == 1 && arr[0][1] == 1)
            arr[0][0] == mark;
        else {
            cout << "invalid move ";
            player--;
        }*/
        p=checkwinner();
        player++;
    }while(p == -1);

    if(p == 1){
        reprintBoard();
        cout << "\aPlayer " << --player << " win" << endl;
    }
    else{
        reprintBoard();
        cout << "\aGame draw" << endl;
    }
    //ctor
/*
    clearWindow();//system("cls");  //Gjør skjermen fri for tekst
    cout << "Player 1 (X)  -   Player 2 (O)" << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2]<< "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
*/
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
            if(arr[choice1][i] != 'X')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker rader for 'O'
    for(int i = 0; i < gameType; i++){
            if(arr[choice1][i] != 'O')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker kolonner for 'X'
    for(int i = 0; i < gameType; i++){
            if(arr[i][choice2] != 'X')
                break;
            if(i == gameType-1)
                win = true;
    }
    //sjekker kolonner for 'O'
    for(int i = 0; i < gameType; i++){
            if(arr[i][choice2] != 'O')
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
                clearWindow();//system("cls");  //Gjør skjermen fri for tekst
                Gui::start();
            }
            else if(input == "n"){
                system("exit");
            }
}

void Gui::createBoard(){
    cout << "Oppgi brettstorrelse (mellom 3 og n): " << ends;
    getline(cin, boardSize);
    stringstream convert(boardSize);

    if( !(convert >> gameType))
            gameType = 0; //hvis resultat ikke får noen verdi blir resultat satt default til 0


//    for(int i = 0; i < result*result; i++){
//        square[i] = antallRuter++;
//    }
    //    for(int i = 0; i <= 1; i++){
//        cout << "[" << endl;
//        for(int j = 0; j <= 2; j++){
//            cout << " " + arr[i][j] << endl;
//        }
//        cout << " ]" << endl;
//    }
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
