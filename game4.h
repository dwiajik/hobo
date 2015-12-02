#include<iostream>
#include<windows.h>
#include<ctime>

using namespace std;

class Game4{
	public:
		static int lebary, lebarx, poin_total;
		static bool stopgame, ulang;
		int y, x, print;
		int arah, poin, atas, bawah, kanan, kiri, arah_balik;
		int arah_hobo, poin_hobo;
		char mainlagi;
		int lose;
		
		void Print_Conversation(){
			char percakapan[4][76] = {"Mr. Richy : Hobo, I dengar You sedang mencari harta karun legendaris itu.  ",
								      "            I punya satu pecahan kunci, I akan berikan ke You, tapi....    ",
								      "            Ada pencuri di rumah I. Ambilin semua uang I di dalem rumah ye!",
								      "Hobo      : Wets.. Hobo coba deh Mister .                                  "};
			for(int y=0; y<4; y++){
				for(int x=0; x<75; x++){
					cout << percakapan[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void menang(){
			system("cls");
			char percakapan[4][64] = {"Hobo      : Sudah beres Mister !                               ",
								      "Mr. Richy : Woyoooo thank you Hobo, thank you very full !      ",
								      "            ini, sesuai my promise, pecahan kunci harta karun .",
								      "Hobo      : Aseeeek, saya yang matur thank you Mister.         "};
			for(int y=0; y<4; y++){
				for(int x=0; x<64; x++){
					cout << percakapan[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void kalah(){
				for (int main_lagi=3; main_lagi>0; main_lagi--){
					system("cls");
					cout << "Waduh, gagal Mister !" << endl;
					cout << "Saya coba lagi " << main_lagi << " detik lagi Mister !";
				Sleep(1000);
				}
			lose = 1;
			//system("pause");
		}
		
		void print_map(char map[11][38]){
			system("cls");
			for(int y=0; y<lebary; y++){
				cout << map[y] << endl;
			}
		}
		
		void gerak_musuh(char map[11][38]){
			if(map[y-1][x] == (char)219){
				atas = 1;
			}else
			if(map[y-1][x] == '$' || map[y-1][x] == ' '){
				atas = 0;
			}
			if(map[y+1][x] == (char)219){
				bawah = 1;
			}else
			if(map[y+1][x] == '$' || map[y+1][x] == ' '){
				bawah = 0;
			}
			if(map[y][x+1] == (char)219){
				kanan = 1;
			}else
			if(map[y][x+1] == '$' || map[y][x+1] == ' '){
				kanan = 0;
			}
			if(map[y][x-1] == (char)219){
				kiri = 1;
			}else
			if(map[y][x-1] == '$' || map[y][x-1] == ' '){
				kiri = 0;
			}
			
			if(y == 1 && x == 34){
				arah = 3;
			}else
			if(atas == 0 && bawah == 1 && kanan == 1 && kiri == 1){
				arah = 0;
			}else
			if(atas == 1 && bawah == 0 && kanan == 1 && kiri == 1){
				arah = 1;
			}else
			if(atas == 1 && bawah == 1 && kanan == 0 && kiri == 1){
				arah = 2;
			}else
			if(atas == 1 && bawah == 1 && kanan == 1 && kiri == 0){
				arah = 3;
			}else
			if(atas == 1 && bawah == 1 && kanan == 0 && kiri == 0){
				//arah sama dengan arah sebelumnya
			}else
			if(atas == 0 && bawah == 0 && kanan == 1 && kiri == 1){
				//arah sama dengan arah sebelumnya
			}else
			if(atas == 0 && bawah == 1 && kanan == 0 && kiri == 1){
				arah = rand()%4;
				while(arah == 1 || arah == 3){
					arah = rand()%4;
				}
			}else
			if(atas == 1 && bawah == 0 && kanan == 0 && kiri == 1){
				arah = rand()%4;
				while(arah == 0 || arah == 3){
					arah = rand()%4;
				}
			}else
			if(atas == 1 && bawah == 0 && kanan == 1 && kiri == 0){
				arah = rand()%4;
				while(arah == 0 || arah == 2){
					arah = rand()%4;
				}
			}else
			if(atas == 0 && bawah == 1 && kanan == 1 && kiri == 0){
				arah = rand()%4;
				while(arah == 1 || arah == 2){
					arah = rand()%4;
				}
			}else
			if(atas == 0 && bawah == 1 && kanan == 0 && kiri == 0){
				if(arah == 2){arah_balik = 3;}else
				if(arah == 3){arah_balik = 2;}
				arah = rand()%4;
				while(arah == 1 || arah == arah_balik){
					arah = rand()%4;
				}
			}else
			if(atas == 1 && bawah == 0 && kanan == 0 && kiri == 0){
				if(arah == 2){arah_balik = 3;}else
				if(arah == 3){arah_balik = 2;}
				arah = rand()%4;
				while(arah == 0 || arah == arah_balik){
					arah = rand()%4;
				}
			}else
			if(atas == 0 && bawah == 0 && kanan == 0 && kiri == 1){
				if(arah == 0){arah_balik = 1;}else
				if(arah == 1){arah_balik = 0;}
				arah = rand()%4;
				while(arah == 3 || arah == arah_balik){
					arah = rand()%4;
				}
			}else
			if(atas == 0 && bawah == 0 && kanan == 1 && kiri == 0){
				if(arah == 0){arah_balik = 1;}else
				if(arah == 1){arah_balik = 0;}
				arah = rand()%4;
				while(arah == 2 || arah == arah_balik){
					arah = rand()%4;
				}
			}else
			if(atas == 0 && bawah == 0 && kanan == 0 && kiri == 0){
				arah = rand()%4;
			}
			
			if(poin == 0){
				map[y][x] = ' ';
			}else{
				map[y][x] = '$';
			}
			
			if(arah == 0){
				if(map[y-1][x] == 'o'){
					kalah();
				}else
				if(map[y-1][x] == '$'){
					poin = 1;
				}else{
					poin = 0;
				}
				map[y-1][x] = '@';
			}else
			if(arah == 1){
				if(map[y+1][x] == 'o'){
					kalah();
				}else
				if(map[y+1][x] == '$'){
					poin = 1;
				}else{
					poin = 0;
				}
				map[y+1][x] = '@';
			}else
			if(arah == 2){
				if(map[y][x+1] == 'o'){
					kalah();
				}else
				if(map[y][x+1] == '$'){
					poin = 1;
				}else{
					poin = 0;
				}
				map[y][x+1] = '@';
			}else
			if(arah == 3){
				if(map[y][x-1] == 'o'){
					kalah();
				}else
				if(map[y][x-1] == '$'){
					poin = 1;
				}else{
					poin = 0;
				}
				map[y][x-1] = '@';
			}
		}
		
		void gerak_hobo(char map[11][38]){
			if(GetAsyncKeyState(VK_UP) != 0 && map[y-1][x] != (char)219){
				arah_hobo = 0;
			}else
			if(GetAsyncKeyState(VK_DOWN) != 0 && map[y+1][x] != (char)219){
				arah_hobo = 1;
			}else
			if(GetAsyncKeyState(VK_RIGHT) != 0 && map[y][x+1] != (char)219){
				arah_hobo = 2;
			}else
			if(GetAsyncKeyState(VK_LEFT) != 0 && map[y][x-1] != (char)219){
				arah_hobo = 3;
			}
			
			if(arah_hobo == 0 && map[y-1][x] != (char)219){
				if(map[y-1][x] == '$'){
					poin_hobo++;
				}else
				if(map[y-1][x] == '@'){
					kalah();
				}
				map[y-1][x] = 'o';
				map[y][x] = ' ';
			}else
			if(arah_hobo == 1 && map[y+1][x] != (char)219){
				if(map[y+1][x] == '$'){
					poin_hobo++;
				}else
				if(map[y+1][x] == '@'){
					kalah();
				}
				map[y+1][x] = 'o';
				map[y][x] = ' ';
			}else
			if(arah_hobo == 2 && map[y][x+1] != (char)219){
				if(map[y][x+1] == '$'){
					poin_hobo++;
				}else
				if(map[y][x+1] == '@'){
					kalah();
				}
				map[y][x+1] = 'o';
				map[y][x] = ' ';
			}else
			if(arah_hobo == 3 && map[y][x-1] != (char)219){
				if(map[y][x-1] == '$'){
					poin_hobo++;
				}else
				if(map[y][x-1] == '@'){
					kalah();
				}
				map[y][x-1] = 'o';
				map[y][x] = ' ';
			}
		}
		
		int main(){
			Print_Conversation();
			awal:
			srand((unsigned)time(NULL));
			arah_hobo = 4;
			lose = 0;
			
			GetAsyncKeyState(VK_RIGHT) &0x8000;
			GetAsyncKeyState(VK_DOWN) &0x8000;
			
			char map[11][38] = {"#####################################",
								"##o $$$$$$$$$$$$$$$$$$$$$$$$$$$$$ @##",
								"## ########$##$########$######$######",
								"## ########$##$########$######$######",
								"## ########$##$########$######$######",
								"##$$$$$$$$$$##$########$######$######",
								"##$########$  $########$######$######",
								"##$########$##$########$######$######",
								"##$########$##$########$######$######",
								"##$$$$$$$$$$##$$$$$$$$$$$$$$$$$$$$$##",
								"#####################################"};
			
			//buat tembok
			for(y=0; y<lebary; y++){
				for(x=0; x<lebarx-1; x++){
					if(map[y][x] == '#'){
						map[y][x] = (char)219;
					}
				}
			}
			print_map(map);
			
			//Menggerakkan Musuh
			//arah			poin
			//0 -> atas		0 -> tdk ada $ ketika dilewati
			//1 -> bawah	1 -> ada $ ketika dilewati
			//2 -> kanan
			//3 -> kiri
			//atas	map[y-1][x] == (char)219
			//bawah map[y+1][x] == (char)219
			//kanan map[y][x+1] == (char)219
			//kiri  map[y][x-1] == (char)219
			poin = 0;
			poin_hobo = 0;
			while(stopgame == false){
				for(y=0; y<lebary; y++){
					for(x=0; x<lebarx-1; x++){
						if(map[y][x] == '@'){
							gerak_musuh(map);
							print_map(map);
							goto gerakhobo;
						}
					}
				}
				
				gerakhobo:
				for(y=0; y<lebary; y++){
					for(x=0; x<lebarx-1; x++){
						if(map[y][x] == 'o'){
							gerak_hobo(map);
							goto print;
						}
					}
				}
				
				print:		
				print_map(map);
				cout << endl << "Uang yang didapat: " << poin_hobo << endl;
				if(poin_hobo == poin_total){
					menang();
					break;
				}
				Sleep(250);
				
				if(lose == 1){
					Sleep(200);
					goto awal;
				}
			}
		}
}Pac;
		int Game4::lebary = 11;
		int Game4::lebarx = 38;
		int Game4::poin_total = 100;
		bool Game4::stopgame = false;
		bool Game4::ulang = true;
