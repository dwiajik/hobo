#include<iostream>
#include<windows.h>
#include<ctime>

using namespace std;

class Game6{
	public:
		string temp;
		void Print_Conversation(){
			char percakapan[5][76] = {"Mr. Iyus  : Hobo, tampaknya kau sudah memiliki 5 pecahan kunci harta karun.",
								      "            Dengan pecahan kunci yang kumiliki, semuanya akan lengkap.     ",
								      "            Tapi, kau harus aku tes terlebih dahulu !                      ",
								      "Hobo      : Tes apa ? Bapak ini siapa ? kok tahu namu saya ?               ",
								      "Mr. Iyus  : Diamlah ! Ini untuk menguji apakah kau pantas mendapatkannya ! "};
			for(int y=0; y<5; y++){
				for(int x=0; x<76; x++){
					cout << percakapan[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void cetak_header_arr(string arr[6][6]){
			system("cls");
			//cout << "#############################" << endl;
//			cout << "#         15 puzzle         #" << endl;
//			cout << "#############################" << endl;
		
			cout << "_____________________" << endl;
			cout << "|    |    |    |    |" << endl;
			cout << "| " << arr[1][1] << " | " << arr[1][2] << " | " << arr[1][3] << " | " << arr[1][4] << " |"  << endl;;
			cout << "|____|____|____|____|" << endl;
			cout << "|    |    |    |    |" << endl;
			cout << "| " << arr[2][1] << " | " << arr[2][2] << " | " << arr[2][3] << " | " << arr[2][4] << " |"  << endl;;
			cout << "|____|____|____|____|" << endl;
			cout << "|    |    |    |    |" << endl;
			cout << "| " << arr[3][1] << " | " << arr[3][2] << " | " << arr[3][3] << " | " << arr[3][4] << " |"  << endl;;
			cout << "|____|____|____|____|" << endl;
			cout << "|    |    |    |    |" << endl;
			cout << "| " << arr[4][1] << " | " << arr[4][2] << " | " << arr[4][3] << " | " << arr[4][4] << " |"  << endl;;
			cout << "|____|____|____|____|" << endl << endl;
		}
		
		void acak(string arr[6][6]){
			int x, y, acakanx, acakany;
			for (int a=0; a<5000; a++){
				acakanx = rand()%3-1;
				acakany = rand()%3-1;
				for(x=1; x<=4; x++){
					for(y=1; y<=4; y++){
						if(arr[y][x] == "  " && x+acakanx >= 1 && x+acakanx <= 4){
							temp = arr[y][x];
							arr[y][x] = arr[y][x+acakanx];
							arr[y][x+acakanx] = temp;
						}else if(arr[y][x] == "  " && y+acakany >= 1 && y+acakany <= 4){
							temp = arr[y][x];
							arr[y][x] = arr[y+acakany][x];
							arr[y+acakany][x] = temp;
						}
					}
				}
			}
		}
		
		void gerak(string arr[6][6]){
			int y, x;
			while(true){
				if(arr[1][1] == " 1" &&
				   arr[1][2] == " 2" &&
				   arr[1][3] == " 3" &&
				   arr[1][4] == " 4" &&
				   arr[2][1] == " 5" &&
				   arr[2][2] == " 6" &&
				   arr[2][3] == " 7" &&
				   arr[2][4] == " 8" &&
				   arr[3][1] == " 9" &&
				   arr[3][2] == "10" &&
				   arr[3][3] == "11" &&
				   arr[3][4] == "12" &&
				   arr[4][1] == "13" &&
				   arr[4][2] == "14" &&
				   arr[4][3] == "15"){
					break;
				}else{
					for(y=0; y<=4; y++){
						for(x=0; x<=4; x++){
							if(arr[y][x] == "  "){
								if(GetAsyncKeyState(VK_UP) != 0 && arr[y+1][x] != "##"){
									temp = arr[y][x];
									arr[y][x] = arr[y+1][x];
									arr[y+1][x] = temp;
									goto end;
								}else if(GetAsyncKeyState(VK_DOWN) != 0 && arr[y-1][x] != "##"){
									temp = arr[y][x];
									arr[y][x] = arr[y-1][x];
									arr[y-1][x] = temp;
									goto end;
								}else if(GetAsyncKeyState(VK_RIGHT) != 0 && arr[x-1][x] != "##"){
									temp = arr[y][x];
									arr[y][x] = arr[y][x-1];
									arr[y][x-1] = temp;
									goto end;
								}else if(GetAsyncKeyState(VK_LEFT) != 0 && arr[x+1][x] != "##"){
									temp = arr[y][x];
									arr[y][x] = arr[y][x+1];
									arr[y][x+1] = temp;
									goto end;
								}
							}
						}
					}
					end:
					cetak_header_arr(arr);
					Sleep(200);
				}
				
			}
		}
		
		void Menang(){
			system("cls");
			char ending[6][76] = {"Mr. Iyus : Hobo, kau memang pantas mendapatkan harta karun itu.            ",
							      "           Aku adalah penjaga harta karun tersebut, sudah sangat banyak    ",
							      "           pendekar yang gagal karena mereka kurang pintar. Mereka tidak   ",
							      "           bisa menyelesaikan ujian ini. Hanya manusia terpilih yang bisa. ",
								  "           Sekarang, Goa Rahasia tempat harta karun itu telah terbuka !    ",
								  "           Ambil harta karun itu dan hiduplah  dengan baik, Hobo ! ! !     "};
			for(int y=0; y<6; y++){
				for(int x=0; x<76; x++){
					cout << ending[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		int main(){
			
			Print_Conversation();
			int x, y;
			bool ulang = true, menang = false;
			char main;
			string arr[6][6] = {"##", "##", "##", "##", "##", "##",
								"##", " 1", " 2", " 3", " 4", "##",
								"##", " 5", " 6", " 7", " 8", "##",
								"##", " 9", "10", "11", "12", "##",
								"##", "13", "14", "15", "  ", "##",
								"##", "##", "##", "##", "##", "##"};
			srand((unsigned)time(0));
			
			//cetak array dan header
			//cetak_header_arr(arr);
			
		//	while(ulang){
//				cout << "Acak puzzle dan mulai bermain? (Y/N) ";
//				cin >> main;
//				switch (main){
//					case 'Y': case 'y':
//						goto acak;
//					case 'N': case 'n':
//						return 0;
//					default:
//						cout << "Input tidak valid, silakan coba lagi." << endl;
//				}
//			}
			
			acak:
			//mengacak array
			acak(arr);
		
			//cetak header dan array yang sudah diacak
			cetak_header_arr(arr);
			
			gerak(arr);
			
			Menang();
			
		}
}Puzzle;
