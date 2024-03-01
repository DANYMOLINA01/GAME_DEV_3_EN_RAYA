#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

int PuntosX=0;
int PuntosY=0;
using namespace std;

char tablero[11][11];
void Titulo();
void Color(int color);
void EsconderCursor();
void MostrarCursor();
void gotoxy(int x, int y);
void marco_tablero();
void mostrar_tablero();
void insertarX(char pos);
void insertarO(char pos);
bool ganaX();
bool ganaO();
bool tablerolleno();
void llenar_con_espacios();
bool celdaVacia (char tecla);
void Juego();
void Juego1();
void Menuprincipal();
void Informacion();
void Instrucciones();
int main() {
	int op;
	char cont,menu;
	bool reg=false;
	char soundfile[]="C:\sonido1.wav";
		
	do{
    cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC)<<endl;
	Menuprincipal();
	do{
	if(reg){
		Color(11);
		gotoxy(35,28);
		cout<<"Vuleva a ingresar una de las opciones presentes : ";
		gotoxy(90,28);
		reg=false;
	}	
	cin>>op;
	switch(op){
		case 1:
		PuntosX=0;
		PuntosY=0;
		system("cls"); 
		Instrucciones();
		do{
		char soundfile2[]="C:\j1.wav";
		cout<<PlaySound((LPCSTR)soundfile2,NULL,SND_FILENAME | SND_ASYNC)<<endl;
		Juego1();
		gotoxy(10,28);
		Color(7);
		cout<<"Desea Volver a Jugar ? (s/n) : ";
		Color(9);
		cin>>cont;
		if(cont=='s'|| cont=='S'){
			system("cls");
		}
	}while(cont =='s' || cont =='S' );
		break;
		case 2:
		PuntosX=0;
		PuntosY=0;
		system("cls"); 
		Instrucciones();
		do{
		char soundfile3[]="C:\j2.wav";
		cout<<PlaySound((LPCSTR)soundfile3,NULL,SND_FILENAME | SND_ASYNC)<<endl;	
		Juego();
		gotoxy(10,28);
		Color(7);
		cout<<"Desea Volver a Jugar ? (s/n) : ";
		Color(9);
		cin>>cont;
		if(cont=='s'|| cont=='S'){
			system("cls");
		}
	}while(cont =='s' || cont =='S' );
		break;
		case 3:
			system("cls");
			
			Informacion();			
	    break;
	    case 4:
	   
			system("cls");
	    	
			for(int i=0;i<15;i++){
	    	Color(i);
			gotoxy(25,10);
			cout<<"Gracias por jugar nuestro Juego :D";
			Sleep(200);
			}
			cout<<"\n\n\n\n";
			exit(0);
			break;
	    	
	default:
		    Color(12);
			gotoxy(35,26);
	        cout<<"Opcion no valida ";
	        reg=true;
		break;
	}
}while(reg==true);
gotoxy(10,30);
		Color(13);
		cout<<"Desea Volver al Menu Principal ? (s/n) [No es para salir del programa]: ";
		cin>>menu;
}while(menu=='s' || menu=='S');
	system("cls");
	    	for(int i=0;i<15;i++){
	    	Color(i);
			gotoxy(25,10);
			cout<<"Gracias por jugar nuestro Juego :D";
			Sleep(200);
			}
			cout<<"\n\n\n\n";
			exit(0);
	

}
void Juego(){
	char tecla;
	bool empate=false;

    llenar_con_espacios();
	EsconderCursor();
	marco_tablero();
	Titulo();

	system("Color 2");
	
	while(true){
	mostrar_tablero();
	Color(12);
	gotoxy(80,10);
	cout<<"Partidas Ganadas Jugador 'X' "<<PuntosX;
	Color(9);
	gotoxy(80,12);
	cout<<"Partidas Ganadas Jugador 'Y' "<<PuntosY;

	do{
	gotoxy(1,10);
	cout<<"Turno de ";
	gotoxy(10,10);
	Color(12);
	cout<<" 'X' ";
	tecla=getch();
    }while(celdaVacia(tecla)==false);
	insertarX(tecla);
	mostrar_tablero();
	if(ganaX()|| tablerolleno()){
		if(ganaX()==false && tablerolleno()==true){
			empate=true;
		}else{
			char soundfile[]="C:\win.wav";
	        cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC)<<endl;
			PuntosX++;
		}
		break;
		
	}
	
	do{
	gotoxy(1,10);
	cout<<"Turno de ";
	gotoxy(10,10);
	Color(9);
	cout<<" 'O' ";
	tecla=getch();
    }while(celdaVacia(tecla)==false);

	insertarO(tecla);
	mostrar_tablero();
	if(ganaO() || tablerolleno()){
		if(ganaO()==false && tablerolleno()==true){
			empate=true;
		}else{
			char soundfile[]="C:\win.wav";
	        cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC)<<endl;
			PuntosY++;
		}
		break;
	}
} 
if(empate){
	Color(13);
	gotoxy(45,25);
	cout<<"Empate!";
}

}
void Juego1(){
	
	char tecla;
bool empate = false;

llenar_con_espacios();
EsconderCursor();
marco_tablero();
Titulo();

system("Color 2");

while (true) {
    mostrar_tablero();
    Color(12);
	gotoxy(80,10);
	cout<<"Partidas Ganadas Jugador 'X' "<<PuntosX;
	Color(9);
	gotoxy(80,12);
	cout<<"Partidas Ganadas Jugador 'Y' "<<PuntosY;

    do {
        gotoxy(1, 10);
        cout << "Turno de ";
        gotoxy(10, 10);
        Color(12);
        cout << " 'X' ";
        tecla = getch();
    } while (celdaVacia(tecla) == false);

    insertarX(tecla);
    mostrar_tablero();

    if (ganaX() || tablerolleno()) {
        if (ganaX() == false && tablerolleno() == true) {
            empate = true;
        }else{
        	char soundfile[]="C:\win.wav";
	cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC)<<endl;
	
        	PuntosX++;
		}
        break;
    }
    gotoxy(1, 10);
    cout << "Turno de ";
    gotoxy(10, 10);
    Color(9);
    cout << " 'O' ";
    Sleep(30);
    char posicion;
    do {
        posicion = '1' + rand() % 9;  
    } while (celdaVacia(posicion) == false);

    insertarO(posicion);
    mostrar_tablero();

    if (ganaO() || tablerolleno()) {
        if (ganaO() == false && tablerolleno() == true) {
            empate = true;
        }else{
        	char soundfile[]="C:\lose.wav";
	cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC)<<endl;
	
			PuntosY++;
		}
        break;
    }
}

if (empate) {
	Color(13);
	gotoxy(45,25);
    cout << "Empate!" << endl;
} 

}
void Titulo(){
	cout<<"\t==================================================================================="<<endl;
	cout << "\t||  ________              ________                 ________                      ||" << endl;
    cout << "\t|| |__   __| __    ___   |__   __|  _____   ___   |__   __| _____  _____         ||" << endl;
    cout << "\t||    | |    | |  / __|     | |    |  _  | / __|     | |   |  _  |/  () \\\        ||" << endl;
    cout << "\t||    | |    | | | |        | |    | |_| || |        | |   | | | ||  ___|        ||" << endl;
    cout << "\t||    | |    | | | |__      | |    |  _  || |__      | |   | |_| || |___         ||" << endl;
    cout << "\t||    |_|    |_|  |___|     |_|    |_| |_| |___|     |_|   |_____||_____|        ||" << endl;
    cout<<"\t==================================================================================="<<endl;

}
void marco_tablero(){
for(int i=0;i<11;i++){
tablero[i][3]=186;
tablero[i][7]=186;
tablero[3][i]=205;
tablero[7][i]=205;
}
tablero[3][3]=206;
tablero[3][7]=206;
tablero[7][3]=206;
tablero[7][7]=206;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mostrar_tablero(){
for(int i=0;i<11;i++){
	for(int j=0;j<11;j++){
		gotoxy(j+50,i+12);
		if(tablero[i][j]=='X'){
			Color(12);
		}else if(tablero[i][j]=='O'){
			Color(9);
		}else{
			Color(15);
		}
		cout<<tablero[i][j];
	}
}	
}

void insertarX(char pos){
	if(pos=='1'){
		tablero[1][1]='X';
	}else if(pos=='2'){
		tablero [1][5]='X';
	}else if(pos=='3'){
		tablero [1][9]='X';
	}else if(pos=='4'){
		tablero [5][1]='X';
	}else if(pos=='5'){
		tablero [5][5]='X';
	}else if(pos=='6'){
		tablero [5][9]='X';
	}else if(pos=='7'){
		tablero [9][1]='X';
	}else if(pos=='8'){
		tablero [9][5]='X';
	}else if(pos=='9'){
		tablero [9][9]='X';
	}
}

void insertarO(char pos){
	if(pos=='1'){
		tablero[1][1]='O';
	}else if(pos=='2'){
		tablero [1][5]='O';
	}else if(pos=='3'){
		tablero [1][9]='O';
	}else if(pos=='4'){
		tablero [5][1]='O';
	}else if(pos=='5'){
		tablero [5][5]='O';
	}else if(pos=='6'){
		tablero [5][9]='O';
	}else if(pos=='7'){
		tablero [9][1]='O';
	}else if(pos=='8'){
		tablero [9][5]='O';
	}else if(pos=='9'){
		tablero [9][9]='O';
	}
}

bool ganaX(){
	if(tablero[1][1]=='X' && tablero[1][5]=='X' && tablero[1][9]=='X' || 
	tablero[5][1]=='X' && tablero[5][5]=='X' && tablero[5][9]=='X' || 
	tablero[9][1]=='X' && tablero[9][5]=='X' && tablero[9][9]=='X'||
	
	tablero[1][1]=='X' && tablero[5][1]=='X' && tablero[9][1]=='X' ||
	tablero[1][5]=='X' && tablero[5][5]=='X' && tablero[9][5]=='X' ||
	tablero[1][9]=='X' && tablero[5][9]=='X' && tablero[9][9]=='X' ||
	
	tablero[1][1]=='X' && tablero[5][5]=='X' && tablero[9][9]=='X' ||
	tablero[1][9]=='X' && tablero[5][5]=='X' && tablero[9][1]=='X'   ){
		Color(12);
		gotoxy(45,25);
		cout<<"Gano la X !";
		Color(12);
		
		return true;
		
	}else{
		return false;
	}
	
}

bool ganaO(){
	if(tablero[1][1]=='O' && tablero[1][5]=='O' && tablero[1][9]=='O' || 
	tablero[5][1]=='O' && tablero[5][5]=='O' && tablero[5][9]=='O' || 
	tablero[9][1]=='O' && tablero[9][5]=='O' && tablero[9][9]=='O'||
	
	tablero[1][1]=='O' && tablero[5][1]=='O' && tablero[9][1]=='O' ||
	tablero[1][5]=='O' && tablero[5][5]=='O' && tablero[9][5]=='O' ||
	tablero[1][9]=='O' && tablero[5][9]=='O' && tablero[9][9]=='O' ||
	
	tablero[1][1]=='O' && tablero[5][5]=='O' && tablero[9][9]=='O' ||
	tablero[1][9]=='O' && tablero[5][5]=='O' && tablero[9][1]=='O'   ){
		Color(9);
		gotoxy(45,25);
		cout<<"Gano la O!";
		return true;
		
	}else{
		return false;
	}
	
}

bool tablerolleno(){
	if(tablero[1][1]!=32 && tablero [1][5]!=32 && tablero [1][9]!=32 &&  
	tablero [5][1]!=32 &&  tablero [5][5]!=32 && tablero [5][9]!=32 && 
	tablero [9][1]!=32 && tablero [9][5]!=32 && tablero [9][9]!=32 ){
		
		return true;
	}else{
		return false;
	}
}
void llenar_con_espacios(){
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			tablero[i][j]=32;
		}
	}
}

bool celdaVacia (char tecla){
	if(tecla=='1'){
	if(tablero[1][1]!=32)
	return false;
	else 
	return true;
	} else if(tecla=='2'){
	if(tablero[1][5]!=32)
	return false;
	else 
	return true;
	}else if(tecla=='3'){
	if(tablero[1][9]!=32)
	return false;
	else 
	return true;
	} else if(tecla=='4'){
	if(tablero[5][1]!=32)
	return false;
	else 
	return true;
	}else if(tecla=='5'){
	if(tablero[5][5]!=32)
	return false;
	else 
	return true;
	} else if(tecla=='6'){
	if(tablero[5][9]!=32)
	return false;
	else 
	return true;
	} else if(tecla=='7'){
	if(tablero[9][1]!=32)
	return false;
	else 
	return true;
	}else if(tecla=='8'){
	if(tablero[9][5]!=32)
	return false;
	else 
	return true;
	}else if(tecla=='9'){
	if(tablero[9][9]!=32)
	return false;
	else 
	return true;
	}
}
void Menuprincipal(){
    
    for(int i=0;i<=13;i++){
    	gotoxy(10,1);
	system("cls");
	Color(i);
	gotoxy(10,1);
	cout<<"\t==================================================================================="<<endl;
	gotoxy(10,2);
	cout << "\t||  ________              ________                 ________                      ||" << endl;
    gotoxy(10,3);
	cout << "\t|| |__   __|  __   ___   |__   __|  _____   ___   |__   __| _____  _____         ||" << endl;
    gotoxy(10,4);
	cout << "\t||    | |    | |  / __|     | |    |  _  | / __|     | |   |  _  |/  () \\\        ||" << endl;
    gotoxy(10,5);
	cout << "\t||    | |    | | | |        | |    | |_| || |        | |   | | | ||  ___|        ||" << endl;
    gotoxy(10,6);
	cout << "\t||    | |    | | | |__      | |    |  _  || |__      | |   | |_| || |___         ||" << endl;
    gotoxy(10,7);
	cout << "\t||    |_|    |_|  |___|     |_|    |_| |_| |___|     |_|   |_____||_____|        ||" << endl;
    gotoxy(10,8);
	cout<<"\t=================================================================================="<<endl;
	Sleep(200);
	}
	Color(12);
    gotoxy(40,12);
	cout<<"========== MENU ==========";
	Color(9);
	gotoxy(42,14);
	cout<<"1.- Modo Un Jugador [Sera el Jugador de la X]";
	Color(6);
	gotoxy(42,16);
	cout<<"2.- Modo Multijugador";
	Color (2);
	gotoxy(42,18);
	cout<<"3.- Acerca del Juego ";
    Color (10);
	gotoxy(42,20);
	cout<<"4.- Salir ";
	Color(12);
	gotoxy(40,22);
	cout<<"=========================";
	Color (8);
	gotoxy(35,24);
	cout<<"Seleccione una opcion :  ";

}
void Informacion() {
    
    Color(12);
	cout << "\tObjetivo del juego:" << endl;
    Color(9);
	cout << "\nEl juego se juega en un tablero de 3x3." << endl;
    cout << "Dos jugadores, usualmente X y O, toman turnos para marcar un espacio vacío en el tablero." << endl;
    Color(12);
    cout << "\n\tGanar el juego:" << endl;
    Color(9);
	cout << "Un jugador gana si coloca tres de sus marcas (X o O) consecutivamente en una fila horizontal, vertical o diagonal." << endl;
    cout << "El juego termina en empate si no hay más espacios vacíos en el tablero y nadie ha ganado." << endl;
    Color(12);
    cout << "\n\tComo jugar:" << endl;
    Color(9);
    cout << "Cada jugador coloca su marca en un espacio vacío del tablero durante su turno." << endl;
    cout << "El juego alterna entre los jugadores hasta que se alcanza un resultado (ganar o empate)." << endl;
    Color(12);
    cout << "\n\tEstrategias comunes:" << endl;
    Color(9);
    cout << "Al ser un juego sencillo, los jugadores a menudo intentan bloquear al oponente y formar sus propias lineas." << endl;
    cout << "El primer movimiento suele ser en el centro o en las esquinas, ya que proporcionan mas oportunidades para formar lineas ganadoras." << endl;
    Color(12);
    cout << "\n\tVariantes:" << endl;
    Color(9);
    cout << "Además del juego estándar de 3x3, hay variantes en tableros más grandes y reglas adicionales para aumentar la complejidad." << endl;
    Color(12);
    cout << "\n\tEnfoques educativos:" << endl;
    Color(9);
    cout << "Tic Tac Toe se utiliza a menudo como un juego introductorio para enseñar conceptos de estrategia y pensamiento lógico en inteligencia artificial." << endl;
    Color (7);
	cout<<"\n\n\tCreditos : Dany Molina - Alexander Romero "<<endl;
    
}
void Instrucciones(){
	gotoxy(17,1);
	Color(12);
	cout<<".: INTRUCCIONES :.";
	gotoxy(1,3);
	Color(9);
	cout<<"Debe de presionar un numero para posicionarse en una celda.";
	gotoxy(17,4);
	Color(13);
	cout<<"Los valores de la celda son: ";
	for(int i=7;i<=17;i++){
		gotoxy(25,i);
		printf("%c",186);
		gotoxy(29,i);
		printf("%c",186);
		gotoxy(i+15,10);
		printf("%c",205);
		gotoxy(i+15,14);
		printf("%c",205);
	}
	gotoxy(25,10);
	printf("%c",206);
	gotoxy(29,10);
	printf("%c",206);
	gotoxy(25,14);
	printf("%c",206);
	gotoxy(29,14);
	printf("%c",206);
	Color(1);
	gotoxy(23,8);
	cout<<"1";
	Color(2);
	gotoxy(27,8);
	cout<<"2";
	Color(3);
	gotoxy(31,8);
	cout<<"3";
	Color(4);
    gotoxy(23,12);
	cout<<"4";
	Color(5);
	gotoxy(27,12);
	cout<<"5";
	Color(6);
	gotoxy(31,12);
	cout<<"6";	
	Color(7);
	gotoxy(23,16);
	cout<<"7";
	Color(8);
	gotoxy(27,16);
	cout<<"8";
	Color(10);
	gotoxy(31,16);
	cout<<"9";
	gotoxy(1,19);
	system("pause");
	system("cls");
}

void EsconderCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void MostrarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 10;
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void Color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

