#include <iostream>
#include <windows.h>
#include <ctime>
#include "game1.h"
#include "game2.h"
#include "game3.h"
#include "game4.h"
#include "game5.h"
#include "game6.h"

using namespace std;

void ClearScreen();
void Print_Menu();
void Credit();
void How_Play();
void Print_Map();
void Move_Hobo();
void Ke_Game(char depan);
void Finalize();
void End_Game();
				   
char Map[18][41]={"#######################################",
				  "##              @               ^######",
				  "## ##################### ## #### ######",
				  "##    %              ### ##  ##      ##",
   				  "## ########### ##### ### ## #### ### ##",
				  "#       ###### ######### ## #### ### ##",
				  "####### ###### ######### ## ####   # ##",
				  "####### ######          $##    ##### ##",
				  "####### ################ ##### ##### ##",
				  "#######          ####### ##### ##### ##",
				  "####### ### #### ####### ##### ##### ##",
				  "####### #   #### ####### ##### ##### ##",
				  "####### #####                 &      ##",
 				  "####### ##### ## ####### ##### ##### ##",
				  "####### #     ## ####### ##### ##### ##",
				  "####### ######## ####### ##### ##### ##",
				  "#######o########    !                ##",
				  "#######################################" };	

char Menu[12][41]={"#######################################",
				   "#                                     #",
				   "#        The Adventure of Hobo        #",
				   "#                                     #",
				   "# ----------------------------------- #",
				   "#             > Start                 #",
				   "#               How to Play           #",
				   "#               Credit                #",
				   "#               Exit                  #",
				   "# ----------------------------------- #",
				   "#        Press Enter to choose        #",
				   "#######################################" };

int key = 0;
int main_game = 0;
int finish = 0;

main(){
	srand((unsigned)time(0));
	Print_Menu();
	while(true){
		if(finish == 0){
			Print_Map();
			Move_Hobo();
		}else{
			break;
		}
	}
}

void Print_Map(){
	ClearScreen();
	for(int y=0; y<18; y++){
		for(int x=0; x<41; x++){
			if(Map[y][x]=='#'){
				Map[y][x]=219;
			}
		}
		cout << Map[y] << endl;       
	}
}

void Move_Hobo(){
	for(int y=0; y<18; y++){
		for(int x=0; x<41; x++){
			if(Map[y][x] == 'o'){
				if(GetAsyncKeyState(VK_UP) != 0 ){
					switch (Map[y-1][x]){
						case ' ':{
							Map[y-1][x] = 'o';
							Map[y][x] = ' ';
							break;
						}
						case (char) 219:{
							break;
						}
						default:{
							Ke_Game(Map[y-1][x]);
							if(main_game == 1){
								if(Map[y-1][x] == '^'){
									Map[y][x] = ' ';
									Map[y-1][x] = (char) 219;
									Map[y-1][x-1] = 'o';
								}else{
									Map[y][x] = ' ';
									Map[y-1][x] = (char) 219;
									Map[y-2][x] = 'o';
								}
							}							
						}
					}
					goto end;					
				}else
				if(GetAsyncKeyState(VK_DOWN) != 0 ){
					switch (Map[y+1][x]){
						case ' ':{
							Map[y+1][x] = 'o';
							Map[y][x] = ' ';
							break;
						}
						case (char) 219:{
							break;
						}
						default:{
							Ke_Game(Map[y+1][x]);
							if(main_game == 1){
								if(Map[y+1][x] == '$'){
									Map[y][x] = ' ';
									Map[y+1][x] = (char) 219;
									Map[y+1][x-1] = 'o';
								}else{
									Map[y][x] = ' ';
									Map[y+1][x] = (char) 219;
									Map[y+2][x] = 'o';
								}
							}
						}
					}
					goto end;
				}else
				if(GetAsyncKeyState(VK_LEFT) != 0 ){
					switch (Map[y][x-1]){
						case ' ':{
							Map[y][x-1] = 'o';
							Map[y][x] = ' ';
							break;
						}
						case (char) 219:{
							break;
						}
						default:{
							Ke_Game(Map[y][x-1]);
							if(main_game == 1){
								Map[y][x] = ' ';
								Map[y][x-1] = (char) 219;
								Map[y][x-2] = 'o';
							}
						}
					}
					goto end;
				}else
				if(GetAsyncKeyState(VK_RIGHT) != 0 ){
					switch (Map[y][x+1]){
						case ' ':{
							Map[y][x+1] = 'o';
							Map[y][x] = ' ';
							break;
						}
						case (char) 219:{
							break;
						}
						default:{
							Ke_Game(Map[y][x+1]);
							if(main_game == 1){
								Map[y][x] = ' ';
								Map[y][x+1] = (char) 219;
								Map[y][x+2] = 'o';
							}
						}
					}
					goto end;
				}			
			}
		}
	}
	end:
	main_game = 0;
	Sleep(100);
	GetAsyncKeyState(VK_RIGHT) &0x8000;
	GetAsyncKeyState(VK_LEFT) &0x8000;
	GetAsyncKeyState(VK_UP) &0x8000;
	GetAsyncKeyState(VK_DOWN) &0x8000;
}

void Ke_Game(char depan){
	switch(depan){
		case '!':{
			Tebak.main();
			key++;
			main_game = 1;
			break;
		}
		case '@':{
			if(key == 1){
				Pingsut.main();
				key++;
				main_game = 1;
			}else{
				char percakapan[5][54]={"Paman Ukad: Hobo, apakah kamu melihat Bimbim?        ",
										"Hobo      : Tidak paman, dia belum pulang?           ",
										"Paman Ukad: Iya, sejak tadi pagi Bimbim belum pulang.",
										"            maukah kamu mencari Bimbim?              ",
										"Hobo      : Oke paman.                               "};
				for(int y=0; y<5 ;y++){
					for(int x=0; x<54; x++){
						cout << percakapan[y][x];
						Sleep(50);
					}
					cout << endl;
				}
			}
			break;
		}
		case '$':{
			if(key == 2){
				Balap.main();
				key++;
				main_game = 1;
			}else{
				char percakapan[3][46]={"Pak Gelem: *&^^#@%$@@%#@&^*&@^^@%&*(!        ",
										"Hobo     : Sepertinya Pak Gelem sedang marah,",
										"           aku pergi saja aaah...            "};
				for(int y=0; y<3 ;y++){
					for(int x=0; x<46; x++){
						cout << percakapan[y][x];
						Sleep(50);
					}
					cout << endl;
				}
				
			}
			break;
		}
		case '%':{
			if(key == 3){
				Pac.main();
				key++;
				main_game = 1;
			}else{
				char percakapan[5][55]={"Hobo     : Maaf mister, boleh mengganggu sebentar     ",
										"Mr. Richy: Eh, apaan You orang kere datang ke rumah I?",
										"           Pergi sono, entar rumah I kotor...         ",
										"Hobo     : T.. tap ... tapi Mister.....               ",
										"Mr. Richy: Hush.... hush....                          "};
				for(int y=0; y<5 ;y++){
					for(int x=0; x<55; x++){
						cout << percakapan[y][x];
						Sleep(50);
					}
					cout << endl;
				}
			}
			break;
		}
		case '^':{
			if(key == 4){
				TicTac.main();
				key++;
				main_game = 1;
			}else{
				char percakapan[2][54]={"Hobo     : Baang.... Bang Onot.....                  ",
										"           Wah sepertinya Bang Onot lagi gak di rumah"};
				for(int y=0; y<2 ;y++){
					for(int x=0; x<54; x++){
						cout << percakapan[y][x];
						Sleep(50);
					}
					cout << endl;
				}
			}
			break;
		}
		case '&':{
			if(key == 5){
				Puzzle.main();
				key++;
				main_game = 1;
				Finalize();
			}else{
				char percakapan[3][45]={"Hobo    : Maaf, bapak orang baru ya di sini?",
										"Mr. Iyus: ........ ........ .........       ",
										"Hobo    : Kok gak jawab sih, orang yang aneh"};
				for(int y=0; y<3 ;y++){
					for(int x=0; x<45; x++){
						cout << percakapan[y][x];
						Sleep(50);
					}
					cout << endl;
				}
			}
			break;
		}
		case 'X':{
			End_Game();
			Credit();
			finish = 1;
			break;
		}
	}
	system("cls");
}

void Print_Menu(){
	bool ulang = true;
	while(ulang == true){		
		ClearScreen();
		for(int y=0; y<12; y++){
			for(int x=0; x<41; x++){
				if(Menu[y][x]=='#'){
					Menu[y][x]=219;
				}
			}
			cout << Menu[y] << endl;       
		}
		int x = 14;
		for(int y = 5; y<9; y++){
			if(Menu[y][x] == '>'){
				if(GetAsyncKeyState(VK_UP) != 0 && Menu[y-1][x] != '-'){
					Menu[y][x] = ' ';
					Menu[y-1][x] = '>';
				}
				if(GetAsyncKeyState(VK_DOWN) != 0 && Menu[y+1][x] != '-'){
					Menu[y][x] = ' ';
					Menu[y+1][x] = '>';
					goto end;
				}
				if(GetAsyncKeyState(VK_RETURN) != 0){
					if(y == 5){
						ulang = false;
					}
					if(y == 6){
						How_Play();
					}
					if(y == 7){
						Credit();
					}
					if(y == 8){
						exit(0);
					}
				}
			}
		}
		end: 
		Sleep(100);
	}	
}

void Credit(){
	system("cls");
	while(true){
		ClearScreen();
		char Credit[12][41]={"#######################################",
					         "#                                     #",
					      	 "#        Credits :                    #",
					     	 "#                                     #",
					   		 "#        Dwi Aji Kurniawan            #",
					   		 "#        Handoko Kustanto             #",
					   		 "#        Nurrahmat Pradeska           #",
					   		 "#        Thoriq Satriya               #",
					   		 "#        Burhan Pirzada               #",
					   		 "# ----------------------------------- #",
					   		 "#        Press Esc to back            #",
					   		 "#######################################" };
		
		for(int y=0; y<12; y++){
			for(int x=0; x<41; x++){
				if(Credit[y][x] == '#'){
					Credit[y][x] = 219;
				}
			}			
			cout << Credit[y] << endl;
		}
		
		if(GetAsyncKeyState(VK_ESCAPE) != 0){
			break;
		}
		Sleep(100);
	}			
}

void Finalize(){
	for(int y=11; y<16; y++){
		for(int x=1; x<6; x++){			
				Map[y][x] = ' ';
		}
	}
	
	Map[10][3] = ' ';
	Map[9][3] = ' ';
	Map[9][4] = ' ';
	Map[9][5] = ' ';
	Map[9][6] = ' ';
	Map[14][3] = 'X';
}

void End_Game(){
	system("cls");
	char percakapan[7][60]={"    Akhirnya, Hobo menemukan harta karun yang selama ini   ",
							"dicarinya. Kehidupan Hobo pun berubah drastis. Hobo yang   ",
							"dulu dicap sebagai gelandangan, kini menjadi orang terkaya ",
							"di negeri ini.",
							"    Hobo pun mengakhiri masa lajangnya dengan seorang putri",
							"cantik dari negeri seberang. Mereka pun hidup bahagia      ",
							"selamanya."};
	for(int y=0; y<7 ;y++){
		for(int x=0; x<60; x++){
			cout << percakapan[y][x];
			Sleep(50);
		}
		cout << endl;
	}
}

void How_Play(){
	while(true){
		ClearScreen();
		char Credit[12][41]={"#######################################",
					         "# How to Play:                        #",
					         "#                                     #",
					      	 "# Gerakkan Hobo ( o ) menggunakan     #",
					      	 "# tombol arah                         #",
					     	 "# Dekati karakter lain ( ! , @ , $ ,  #",
							 "# % , ^ , & )                         #",
							 "#                                     #",
					   		 "# Feel free to explore the map!       #",
					   		 "# ----------------------------------- #",
					   		 "#        Press Esc to back            #",
					   		 "#######################################" };
		
		for(int y=0; y<12; y++){
			for(int x=0; x<41; x++){
				if(Credit[y][x] == '#'){
					Credit[y][x] = 219;
				}
			}			
			cout << Credit[y] << endl;
		}
		
		if(GetAsyncKeyState(VK_ESCAPE) != 0){
			break;
		}
		
		Sleep(100);
	}			
}

void ClearScreen(){
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
