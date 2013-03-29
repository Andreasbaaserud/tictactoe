#include "Gui.h"
#include <iostream>
#include "stdlib.h"
#include <sstream>

using namespace std;

string input = "";
string boardSize = "0";
int antallRuter = 0;
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
    int ant = 0;
//    int arr[result][result];
    for(int i = 0; i < result; i++){
        for(int j = 0; j < result; j++){
            arr[i][j] = square[ant++];
        }
    }
    int player = 1,p,choice1,choice2;
//    int mark;
    do{
        reprintBoard();
        player=(player%2)?1:2;
        cout << "Player " << player << endl;
        cout << "enter X coord: ";
        cin >> choice1;
        cout << "enter Y coord: ";
        cin >> choice2;

        arr[choice1][choice2] = (player == 1) ? 999 : 111;
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
        cout << "\aPlayer " << player << " win " << endl;
    }
    else{
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
    for(int i = 0; i < result; i++){
        for(int j = 0; j < result; j++){
            cout << "[";
            cout << arr[i][j] << "] \t";
        }
        cout << endl;
    }
}

int Gui::checkwinner(){
    if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
        return 1;
    else
    return -1;
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

    if( !(convert >> result))
            result = 0; //hvis resultat ikke får noen verdi blir resultat satt default til 0


    for(int i = 0; i < result*result; i++){
        square[i] = antallRuter++;
    }
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
