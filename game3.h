#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

class Game3{
	public:
		static int c_win, count;
		static bool lose;
		
		void clearscreen(){
			HANDLE hOut;
			COORD Position;
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			Position.X = 0;
			Position.Y = 0;
			SetConsoleCursorPosition(hOut, Position);
		}
		
		void Print_Conversation(){
			char percakapan[4][76] = {"Hobo      : Pak Gelem, bener kan bapak punya pecahan kunci harta karun ?   ",
								      "Pak Gelem : Mau minta ?  Beli doong .. gak modal banget sih hohoho         ",
								      "            Atau, rasakan dulu 'jurus 20 rintangan suci' ku ini ! ciaaat   ",
								      "Hobo      : Waduh ! galak bener !                                          "};
			for(int y=0; y<4; y++){
				for(int x=0; x<75; x++){
					cout << percakapan[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void menang () {
			system("cls");
			char ending[4][62] = {"Pak Gelem : Hobo, ini bapak pinjemin kunci punya bapak !     ",
							      "            Ingat ! cuma 'dipinjamkan' ! harus ada biayanya !",
							      "            Jika ketemu, bapak minta 10% .. Hohoho           ",
							      "Hobo      : Mbiiii, ogah wekk ! KABUUUUR ! ! !               "};
			for(int y=0; y<4; y++){
				for(int x=0; x<62; x++){
					cout << ending[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void kalah () {
			for (int main_lagi=3; main_lagi>0; main_lagi--){
				system("cls");
				cout << "      HOBO! bisa gak sih!" << endl;
				cout << "Mulai lagi ya! Dalam hitungan " << main_lagi << " detik";
				Sleep(1000);
			}
			c_win=0;
		}
		
		void gerak_hobo(char map[10][10]){
			for (int x=1; x<7; x++)
			{
				if (map [9][x]=='o')
				{
					if(GetAsyncKeyState(VK_LEFT) != 0)
					{
						if (map[9][x-1] != '|')
						{
							map [9][x]=' ';
							map [9][x-1]='o';
							goto end;
						}
					}
					if(GetAsyncKeyState(VK_RIGHT) != 0)
					{
						if (map[9][x+1] != '|')
						{
							map [9][x]=' ';
							map [9][x+1]='o';
							goto end;
						}
					}
				}
			}
			end:
			Sleep(60);
		}
		
		void acak(char map[10][10]){
			int acak = rand()%6;
			if (acak == 0)
			{
				map [0][1] = '_';
				map [0][2] = '_';
			}
			if (acak == 1)
			{
				map [0][3] = '_';
				map [0][4] = '_';
			}
			if (acak == 2)
			{
				map [0][5] = '_';
				map [0][6] = '_';
			}
			if (acak == 3) //0 1
			{
				map [0][1] = '_';
				map [0][2] = '_';
				map [0][3] = '_';
				map [0][4] = '_';
			}
			if (acak == 4) // 1 2
			{
				map [0][3] = '_';
				map [0][4] = '_';
				map [0][5] = '_';
				map [0][6] = '_';
			}
			if (acak == 5) // 2 0
			{
				map [0][6] = '_';
				map [0][5] = '_';
				map [0][1] = '_';
				map [0][2] = '_';
			}
		}
		
		void turunkan(char map[10][10]){
			for (int x=1;x<7;x++)
			{
				for (int y=9;y>(-1);y--)
				{
					if (map [y] [x] != 'o')
					{
						if(y == 0)
						{
							map [y] [x] = ' ';
						}else
						{
							map [y] [x]= map [y-1][x];
						}
					}else
					if (map [y-1][x] == '_')
					{
						kalah();
						lose = true;
					}			
				}
			}
			
			if(count==3){
				c_win++;
			}
		}
		
		void print_map(char map[10][10]){
			clearscreen();
			for (int y=0;y<10;y++)
			{
				cout << map[y] << endl;
			}
			
			if(c_win==-1){
				cout << "Rintangan: 0" << endl;
			}else{
				cout << "Rintangan: " << c_win << endl;
			}
		}
		
		int main(){
			Print_Conversation();
			
			mulai_lagi:
			system("cls");	
			char map[10][10]={"|      |",
					          "|      |",
					  		  "|      |",
				      	      "|      |",
					          "|      |",
					          "|      |",
							  "|      |",
			     		  	  "|      |",
			       		      "|      |",
				  	      	  "|  o   |"};
			lose = false;
			c_win=-1;
			GetAsyncKeyState(VK_RIGHT) &0x8000;
			GetAsyncKeyState(VK_LEFT) &0x8000;
			
			//deklarasi variabel
			int x, y;
						      
			//engine acakan
			srand((unsigned)time(NULL));
			
			//print map
			print_map(map);
			
			acak:
			//acak baris pertama
			acak(map);
			
			//print map
			print_map(map);
				
			
			count=0;
			
			turunkan:
			//turunkan baris 1-10
			turunkan(map);
			if(lose == true){				
				goto mulai_lagi;
			}
			
			//menggerakkan karakter 'o'
			gerak_hobo(map);
			
			//print map
			print_map(map);
			
			Sleep(60);
					
			count++;
			
			if(c_win == 20)	{
				menang();
			}else			
			if (count == 5)	{
				goto acak;
			}else{	
				goto turunkan;
			}
		}
}Balap;
bool Game3::lose = false;
int Game3::c_win=-1, Game3::count = 0;
