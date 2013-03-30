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
//    int ant = 0;
//    int arr[gameType][gameType];
    for(int i = 0; i < gameType; i++){
        for(int j = 0; j < gameType; j++){
            arr[i][j] = '#';
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
//    if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
//        return 1;
    int countWin = 0;
//    int row0Win = 0;
//    int row1Win = 0;
//    int row2Win = 0;
//    int col0Win = 0;
//    int col1Win = 0;
//    int col2Win = 0;
//    int countX = 0;
//    int countO = 0;
//    bool win = false;
//    int row0 = 0;
//    int row1 = 1;
//    int row2 = 2;
//    int col0 = 0;
//    int col1 = 1;
//    int col2 = 2;

    for(int i = 0; i < gameType; i++){
        for(int j = 0; j < gameType; j++){
            if(arr[i][j] == 'X')
                countWin++;
            if(arr[i][j] == 'O')
                countWin--;
        }
//        //sjekker rad 0
//        if(arr[row0][i] != '#'){
//            if(arr[row0][i] == 'X'){
//                row0Win++;
//            }
//            if(arr[row0][i] == 'O'){
//                row0Win--;
//            }
//        }
//        //sjekker rad 1
//        if(arr[row1][i] != '#'){
//            if(arr[row1][i] == 'X'){
//                row1Win++;
//            }
//            if(arr[row1][i] == 'O'){
//                row1Win--;
//            }
//        }
//        //sjekker rad 2
//        if(arr[row2][i] != '#'){
//            if(arr[row2][i] == 'X'){
//                row2Win++;
//            }
//            if(arr[row2][i] == 'O'){
//                row2Win--;
//            }
//        }
//        //sjekker kolonne 0
//        if(arr[i][col0] != '#'){
//            if(arr[i][col0] == 'X'){
//                col0Win++;
//            }
//            if(arr[i][col0] == 'O'){
//                col0Win--;
//            }
//        }
//        //sjekker kolonne 1
//        if(arr[i][col1] != '#'){
//            if(arr[i][col1] == 'X'){
//                col1Win++;
//            }
//            if(arr[i][col1] == 'O'){
//                col1Win--;
//            }
//        }
//        //sjekker kolonne 2
//        if(arr[i][col2] != '#'){
//            if(arr[i][col2] == 'X'){
//                col2Win++;
//            }
//            if(arr[i][col2] == 'O'){
//                col2Win--;
//            }
//        }
//
//        //rad0
//        if(row0Win == gameType || row0Win == -gameType)
//            win = true;
//
//        //rad1
//        if(row1Win == gameType || row1Win == -gameType)
//            win = true;
//
//        //rad2
//        if(row2Win == gameType || row2Win == -gameType)
//            win = true;
//
//        //kolonne0
//        if(col0Win == gameType || col0Win == -gameType)
//            win = true;
//
//        //kolonne1
//        if(col1Win == gameType || col1Win == -gameType)
//            win = true;
//
//        //kolonne2
//        if(col2Win == gameType || col2Win == -gameType)
//            win = true;
    }

   /* for(int i = 0; i < gameType; i++){
        countWin = 0;
        //sjekker rad 1
        if(arr[row1][i] != '#'){
            if(arr[row1][i] == 'X'){
                countWin++;
            }
            if(arr[row1][i] == 'O'){
                countWin--;
            }
        }
        if(countWin == gameType)
            win = true;
    }*/
    cout << countWin;
    //countWin = 3 == WIN
    //countWin = 2 == DRAW
    //countWin = 1 == DRAW
    //countWin = -3 == WIN
    if(countWin == gameType)
        return 1; //X eller O har vunnet
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
