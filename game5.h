#include<iostream>
#include <windows.h>
#include <ctime>

using namespace std;

class Game5{
	public:
		void Print_Conversation(){
			char percakapan[4][76] = {"Hobo      : Hello Bang Onot, lagi ngapain bang ?                           ",
								      "Bang Onot : Lagi maen TicTacToe ni lho. Tapi gak ada lawan maen.           ",
								      "Hobo      : Sini bang, maen sama Hobo ! Kalah jangan nyesel tapi, wkwk     ",
								      "Bang Onot : Sombong amat ! Kalo bisa menang, Abang kasih 'sesuatu' dah !   "};
			for(int y=0; y<4; y++){
				for(int x=0; x<75; x++){
					cout << percakapan[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void Menang(){
			system("cls");
			char ending[4][66] = {"Hobo      : Tuh kan, menang kan bang ! Hobo gitu loh             ",
							      "Bang Onot : Beruntung aja bangga lu. Nih Abang kasih hadiahnya ..",
							      "            Abang nemu di selokan tadi pagi tuh , wkwk           ",
							      "Hobo      : Bang, ini kan pecahan kunci harta karun ! Wkwk       "};
			for(int y=0; y<4; y++){
				for(int x=0; x<66; x++){
					cout << ending[y][x];
					Sleep(50);
				}
				cout << endl;
			}
			system("pause");
		}
		
		void Main_Game(){
			start:
			
			//engine acakan
			srand((unsigned)time(0));
			
			/* Deklarasi variabel */
			char data [10] = {'#','1','2','3','4','5','6','7','8','9'}, playagain;
			char menu[2][13] = {">   1 Player",
								"    2 Player"};
			int count=0, input=0, jumlah_player=0;
			bool ulang=true;
			string pemain1, pemain2;
			
			int x, y;
			
			pemain1 = "Hobo";
			pemain2 = "Bang Onot";
			
			home:
			
			/* Bersihkan layar lagi */
			system("cls");
			
		//	/* Header 2: saat game berjalan */
//			cout << "###############################" << endl;
//			cout << "##         TicTacToe         ##" << endl;
//			cout << "###############################" << endl << endl;
			
			/* Papan permainan */
			cout << "___________________" << endl;
			cout << "|     |     |     |" << endl;
			cout << "|  " << data[1] << "  |  " << data[2] << "  |  " << data[3] << "  |" << endl;
			cout << "|_____|_____|_____|" << endl;
			cout << "|     |     |     |" << endl;
			cout << "|  " << data[4] << "  |  " << data[5] << "  |  " << data[6] << "  |" << endl;
			cout << "|_____|_____|_____|" << endl;
			cout << "|     |     |     |" << endl;
			cout << "|  " << data[7] << "  |  " << data[8] << "  |  " << data[9] << "  |" << endl;
			cout << "|_____|_____|_____|" << endl << endl;
			
			
			/* Keterangan simbol untuk setiap pemain */
			cout << pemain1 << ": X" << endl;
			cout << pemain2 << ": O" << endl << endl;
			
			/* Mengecek permainan sudah selesai atau belum.
				 Lalu menampilkan pemenang: pemain1, pemain2, atau gak ada yg menang.
				 Jika permainan belum selesai meminta input lagi ke pemain yg mendapat giliran */
			if ((data[1]=='X' && data[2]=='X' && data[3]=='X') ||
				(data[4]=='X' && data[5]=='X' && data[6]=='X') ||
				(data[7]=='X' && data[8]=='X' && data[9]=='X') ||
				(data[1]=='X' && data[4]=='X' && data[7]=='X') ||
				(data[2]=='X' && data[5]=='X' && data[8]=='X') ||
				(data[3]=='X' && data[6]=='X' && data[9]=='X') ||
				(data[1]=='X' && data[5]=='X' && data[9]=='X') ||
				(data[3]=='X' && data[5]=='X' && data[7]=='X')){
				cout << pemain1 << " menang!" << endl << endl;
				Sleep(1000);
				goto end;
			}else
			if ((data[1]=='O' && data[2]=='O' && data[3]=='O') ||
				(data[4]=='O' && data[5]=='O' && data[6]=='O') ||
				(data[7]=='O' && data[8]=='O' && data[9]=='O') ||
				(data[1]=='O' && data[4]=='O' && data[7]=='O') ||
				(data[2]=='O' && data[5]=='O' && data[8]=='O') ||
				(data[3]=='O' && data[6]=='O' && data[9]=='O') ||
				(data[1]=='O' && data[5]=='O' && data[9]=='O') ||
				(data[3]=='O' && data[5]=='O' && data[7]=='O')){
				cout << pemain2 << " menang!" << endl << endl;
				system("pause");
				goto start;
			}else
			if ((data[1]=='X' || data[1]=='O') &&
				(data[2]=='X' || data[2]=='O') &&
				(data[3]=='X' || data[3]=='O') &&
				(data[4]=='X' || data[4]=='O') &&
				(data[5]=='X' || data[5]=='O') &&
				(data[6]=='X' || data[6]=='O') &&
				(data[7]=='X' || data[7]=='O') &&
				(data[8]=='X' || data[8]=='O') &&
				(data[9]=='X' || data[9]=='O')){
				cout << "Tidak ada yang menang!" << endl << endl;
				system("pause");
				goto start;
			}else
			if(count+1==1){
				while(ulang){
					cout << pemain1 << " masukkan angka: ";
					cin >> input; cout << endl;
					if (data[input] != 'X' && data[input] != 'O' && input>0 && input<10){
						data [input] = 'X';
						break;
					}else{
						cout << "Input tidak valid! Silakan coba lagi!" << endl;
					}
				}
			}else
			if(count+1==2){	
				if (jumlah_player == 2){
					while(ulang){
						cout << pemain2 << " masukkan angka: ";
						cin >> input; cout << endl;
						if (data[input] != 'X' && data[input] != 'O'  && input>0 && input<10){
							data [input] = 'O';
							break;
						}else{
							cout << "Input tidak valid! Silakan coba lagi!" << endl;
						}
					}
				}else{
					cout << pemain2 << " masukkan angka: ";
					while(ulang){
						input = rand()%9+1; cout << endl;
						if (data[input] != 'X' && data[input] != 'O'  && input>0 && input<10){
							data [input] = 'O';
							break;
						}
					}
					Sleep(1000);
				}
			}
			
			/* Untuk menandai giliran pemain */
			count++;
			count=count % 2;
			
			/* Balik ke home: */
			goto home;
			
			end:
				Menang();
		}
		
		int main(){
			Print_Conversation();
			Main_Game();	
		}
}TicTac;
