#include<iostream>
using namespace std;

char baris, kolom;
int angka_kotak;
char player = 'X';
char angka[3][3] = {{'1','2','3'}, {'4','5','6'},{'7','8','9'}};
string player1, player2;
bool seimbang = true;

void papan_game(){
	
	cout << " _______________" << endl;
	cout << "|    |    |     |" << endl;
	cout << "| " << angka[0][0] << "  |  " << angka[0][1] << " | " << angka[0][2] << "   |" << endl;
	cout << "|____|____|_____|" << endl;
	cout << "|    |    |     |" << endl;
	cout << "| " << angka[1][0] << "  |  " << angka[1][1] << " | " << angka[1][2] << "   | " << endl;
	cout << "|____|____|_____|" << endl;
	cout << "|    |    |     |" << endl;
	cout << "| " << angka[2][0] << "  | " << angka[2][1] << "  | " << angka[2][2] << "   | " << endl;
	cout << "|____|____|_____|" << endl;
}

void nomor_baris_kolom(){
	
	if(player == 'X'){
		cout << player1 << "silahkan pilih nomor kotak! : ";
		cin >> angka_kotak;
	}
	
	if(player == 'O'){
		cout << player2 << "silahkan pilih nomor kotak! : ";
		cin >> angka_kotak;
	}
	
	if(angka_kotak == 1){
		baris = 0;
		kolom = 0;
	}else if(angka_kotak == 2){
		baris = 0;
		kolom = 1;
	}else if(angka_kotak == 3){
		baris = 0;
		kolom = 2;
	}else if(angka_kotak == 4){
		baris = 1;
		kolom = 0;
	}else if(angka_kotak == 5){
		baris = 1;
		kolom = 1;
	}else if(angka_kotak== 6){
		baris = 1;
		kolom = 2;
	}else if(angka_kotak == 7){
		baris = 2;
		kolom = 0;
	}else if(angka_kotak == 8){
		baris = 2;
		kolom = 1;
	}else if(angka_kotak == 9){
		baris = 2;
		kolom = 2;
	}else{
		cout << "Masukan angka yang diminta!!" << endl;
		nomor_baris_kolom();		
	}
	
	if(player == 'X' && angka[baris][kolom] != 'X' && angka[baris][kolom] != 'O'){
    angka[baris][kolom]	= 'X';
    player = 'O';
	}else if(player == 'O' && angka[baris][kolom] !='X' && angka[baris][kolom] != 'O'){
		angka[baris][kolom] = 'O';
		player = 'X';
	}else{
		cout << "Masukkan angka yang diminta!!!" << endl;
		nomor_baris_kolom();
	}
}

bool cek_kemenangan(){
		//kondisi apabila salah satu pemain mendapat satu baris yang sama
	if(angka[0][0] == angka[0][1] && angka[0][1] == angka[0][2] || angka[1][0] == angka[1][1] && angka[1][1] == angka[1][2] || angka[2][0] == angka[2][1] && angka[2][1] == angka[2][2]){
		seimbang = true;
		return true;
	//kondisi apabila salah satu pemain mendapat satu kolom yang sama
	}else if(angka[0][0] == angka[1][0] && angka[1][0] == angka[2][0] || angka[0][1] == angka[1][1] && angka[1][1] == angka[2][1] || angka[0][2] == angka[1][2] && angka[1][2] == angka[2][2]){
		seimbang = true;
		return true;
	//cek kondisi apabila salah satu pemain mendapat satu 
	}else if(angka[0][0] == angka[1][1] && angka[1][1] == angka[2][2] || angka[0][2] == angka[1][1] && angka[1][1] == angka[2][2]){
	seimbang = true;
		return true;
	}else{
		//cek kondisi apabila masih terdapat kotak yang masih kosong untuk lanjut bermain
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(angka[i][j] != 'X' && angka[i][j] != 'O'){
				return false;				
			}
			}
		}
		seimbang = false;
		return true;
	}
}
void winner(){
if(player == 'X' && seimbang == true){
    cout << "selamat" << player2 << "menang" << endl;
}else if(player == '0' && seimbang == true) { 
    cout << "selamat" << player1 << "menang" << endl;
}else{
cout << "PERMAINAN SELESAI" << endl;

}
	
}
int main(){

cout << "Masukkan nama player 1: ";
getline(cin, player1);
cout << "Masukkan nama player 2: ";
getline(cin, player2);

cout << player1 << "bermain sebagai 'X' dan" << player2 << "bermain sebagai '0'\n" << endl;

while(!cek_kemenangan()){
papan_game();
nomor_baris_kolom();
cek_kemenangan();
system("cls");
}
winner();
}



	

