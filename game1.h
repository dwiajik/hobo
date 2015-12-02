#include<iostream>

using namespace std;

class Game1{
	public:
		void Print_Conversation(){
			char percakapan[4][68] = {"Bimbim  : Hobo, tadi aku memetik banyak sekali buah apel di hutan. ",
								      "Hobo    : Boleh aku minta satu ?                                   ",
								      "Bimbim  : Boleh sih, tapi tebak dulu aku punya berapa buah apel !  ",
								      "Hobo    : Oke.. Hmm kira-kira berapa ya ?!                         "};
			for(int y=0; y<4; y++){
				for(int x=0; x<68; x++){
					cout << percakapan[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void Print_Ending(){
			system("cls");
			char ending[7][68] = {"Bimbim  : Hobo, ini aku kasih apel ...                             ",
							      "          dan ini, pecahan kunci harta karun.                      ",
							      "Hobo    : Eh, terimakasih. Darimana kamu mendapatkannya, Bim ?     ",
							      "Bimbim  : Tadi waktu memetik apel, itu nyangkut di pohon .. Hahaha ",
								  "Hobo    : Bim, kamu tau nggak siapa lagi yang punya kuncinnya ?    ",
								  "Bimbim  : Setauku sih, Bapak-ku sama Pak Gelem punya satu ..       ",
								  "Hobo    : Okedeh, okesip Bim                                       " };
			for(int y=0; y<7; y++){
				for(int x=0; x<68; x++){
					cout << ending[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void Mulai_Tebak(){
			system("cls");
			int asli, tebakan;		
			
			asli=(rand()%100)+1;
			
			start1game3:
				cout << "Masukkan tebakan anda : " ;
				cin >> tebakan;
			
				if(tebakan < asli){
					cout << "Masih kurang bos." << endl << endl;
					goto start1game3;
				}else 
				if(tebakan > asli){
					cout << "Kelebihan bos." << endl << endl;
					goto start1game3;
				}else{
					cout << "Selamat, tebakan nya tepat." << endl;
				}
					system("pause");					
		}
		void main(){
			Print_Conversation();
			Mulai_Tebak();
			Print_Ending();			
		}
}Tebak;
