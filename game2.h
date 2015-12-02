#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

class Game2{
	public:
						
		char input_1, input_2;
		static string pemain_1;
		static string pemain_2;
		static bool menang;
		
		void Print_Conversation(){
			char percakapan[4][76] = {"Hobo      : Apakah paman mempunyai pecahan kunci kotak harta karun?        ",
								      "Paman Ukad: Aku menyimpannya selama puluhan tahun,                         ",
								      "            jika kamu menginginkannya, kamu harus menang pingsut melawanku!",
								      "Hobo      : Baiklah paman, mari kita pingsut!                              "};
			for(int y=0; y<4; y++){
				for(int x=0; x<76; x++){
					cout << percakapan[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void Choose_Pingsut(){
			char pilihan[3][10] = {"> Batu",
								   "  Kertas",
								   "  Gunting"};
			bool ulang = true;
			while(ulang == true){
				int x = 0;
				for(int y=0; y<3; y++){
					if(pilihan[y][x] == '>'){
						if(GetAsyncKeyState(VK_UP) != 0 && y != 0){
							pilihan[y][x] = ' ';
							pilihan[y-1][x] = '>';
							goto print;
						}else
						if(GetAsyncKeyState(VK_DOWN) != 0 && y != 2){
							pilihan[y][x] = ' ';
							pilihan[y+1][x] = '>';
							goto print;
						}else
						if(GetAsyncKeyState(VK_RETURN) != 0){
							if(pilihan[0][0] == '>'){
								input_1 = '1';
							}else
							if(pilihan[1][0] == '>'){
								input_1 = '2';
							}else
							if(pilihan[2][0] == '>'){
								input_1 = '3';
							}
							ulang = false;
							goto print;
						}
					}
				}
				print:
				system("cls");
				cout << "Hobo pilih:" << endl;
				for(int i=0; i<3; i++){
					cout << pilihan[i] << endl;
				}
				Sleep(100);
			}
		}

		void Print_Illustration(){			
			class Gambar{
				public:
					void Batu(){
						cout << "  ____   " << endl;
						cout << " /    \\ " << endl;
						cout << "|      | " << endl;
						cout << " \\____/ " << endl;
						cout << "  Batu   " << endl << endl;
					}
					void Kertas(){
						cout << " ______  " << endl;
						cout << "/     /  " << endl;
						cout << "\\     \\" << endl;
						cout << "/_____/  " << endl;
						cout << " Kertas  " << endl << endl;
					}
					void Gunting(){
						cout << "        __    " << endl;
						cout << " ______/ /_   " << endl;
						cout << "/_____  ___|  " << endl;
						cout << "     / /      " << endl;
						cout << "    /_/       " << endl;
						cout << "   Gunting    " << endl << endl;
					}
			}Print;
			
			switch(input_1){
				case '1':
					Print.Batu();
					break;
				case '2':
					Print.Kertas();
					break;
				case '3':
					Print.Gunting();
					break;
			}
			
			cout << " VS " << endl;
			
			switch(input_2){
				case '1':
					Print.Batu();
					break;
				case '2':
					Print.Kertas();
					break;
				case '3':
					Print.Gunting();
					break;
			}
		}
		
		void Check_Win(){
			if (input_1 == input_2) {
				cout << "Draw" << endl << endl;
			}else
			if (((input_1=='1') && (input_2=='3')) ||
				((input_1=='2') && (input_2=='1')) ||
				((input_1=='3') && (input_2=='2'))) {
				cout << pemain_1 << " Win" << endl << endl;
				menang = true;
			}else
			if (((input_1=='1') && (input_2=='2')) ||
				((input_1=='2') && (input_2=='3')) ||
				((input_1=='3') && (input_2=='1'))){
				cout << pemain_2 << " Win" << endl << endl;
			}
			system("pause");
		}
		
		void Print_Ending(){
			system("cls");
			char ending[4][76] = {"Paman Ukad: Hobo, kuserahkan pecahan kunci ini padamu.                     ",
							      "            Cari harta karun itu Hobo, aku sudah terlalu tua untuk mencari.",
							      "            Jika ketemu, bagi hasilnya denganku ya.. Hahaha                ",
							      "Hobo      : Baiklah paman, All iz Well . wkwk                              "};
			for(int y=0; y<4; y++){
				for(int x=0; x<75; x++){
					cout << ending[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}

		void main(){
			GetAsyncKeyState(VK_RETURN) &0x8000;
			char data[3]={'1','2','3'};
			
			srand((unsigned)time(0));
			
			Print_Conversation();
			
			home:
			Choose_Pingsut();
			
			input_2=data[(rand()%3)];	
			
			Print_Illustration();
			Check_Win();
			
			if(menang == false){
				goto home;
			}
			
			Print_Ending();
		}
}Pingsut;

string Game2::pemain_1 = "Hobo";
string Game2::pemain_2 = "Paman Ukad";
bool Game2::menang = false;
