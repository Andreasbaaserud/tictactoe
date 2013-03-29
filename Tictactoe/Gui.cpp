#include "Gui.h"
#include <iostream>
#include "stdlib.h"
using namespace std;

string input = "";
string boardSize = "";
char antallRuter = '0';
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
    for(int i = 0; i < sizeof(square); i++){
        square[i] = antallRuter++;
    }
    rdy();
}

void Gui::start(){
    createBoard();
}

void Gui::build(){
    //ctor

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

}

int Gui::checkwinner()
{
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
    int result;
   /* stringstream convert(boardSize);

    if( !(convert >> result))
        result = 0;*/
//    if(boardSize == "3"){
//        build();
//    }
    for(int i = 0; i < result; i++){
    }
}

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
