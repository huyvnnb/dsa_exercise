#include <iostream>
#include <string>
using namespace std;
struct thongtinsinhvien {
	int mssv = 0;
	string hoten = "No Name";
	float dtoan = 0.0;
	float dly = 0.0;
} sinhvien[100];

// Hàm nhập thông tin sinh viên từ bàn phím
void nhapThongTinSV(thongtinsinhvien, int);

// Hàm xuất thông tin sinh viên theo yêu cầu
void xuatThongTinSV(thongtinsinhvien, int);
// Hàm sắp xếp sinh viên theo MSSV

void sapxepMSSV(thongtinsinhvien, int);
void sapxepMSSV(thongtinsinhvien, int , int);

// Hàm tìm sinh viên đạt điểm toán cao nhất - bằng điểm thì in ra hết
void timSVtoan(thongtinsinhvien, int);

// Hàm tìm sinh viên có điểm trung bình thấp nhất
void xuatdtb_min(thongtinsinhvien, int);
// Hàm tìm sinh viên theo MSSV

void timSinhVien(thongtinsinhvien, int);
void upperCase(thongtinsinhvien, int ); // in hoa tất cả ký tự trong tên sinh viên

// Hàm tìm sinh viên theo điểm
void timSVtheodiem(thongtinsinhvien, int);
//===========================================================================================================

int main() {
	int solgsinhvien;
	int choice;

	cout << "Nhap so luong sinh vien can nhap: ";
	cin >> solgsinhvien;

	cout << "Chon phuong thuc xuat du lieu: \n";
	cout << " 1) Xuat danh sach sinh vien \n";
	cout << " 2) Xuat danh sach tang dan theo MSSV \n";
	cout << " 3) Xuat sinh vien diem Toan cao nhat \n";
	cout << " 4) Diem trung binh thap nhat \n";
	// 2 Chức năng này chưa dùng đến, dùng khi làm việc với file
	cout << " 5) Tim kiem thong tin sinh vien thong qua MSSV - Tinh nang chua hoan thien! \n";
	cout << " 6) Tim kiem sinh vien theo diem toan / diem ly - Tinh nang chua hoan thien!\n";
	cin >> choice;
	cout << "===============================\n";

	nhapThongTinSV(sinhvien[100], solgsinhvien); // Nhập thông tin sinh viên
	upperCase(sinhvien[100], solgsinhvien); // In hoa các chữ cái trong tên

	switch (choice) {
		case 1:
			xuatThongTinSV(sinhvien[100], solgsinhvien);
			break;
		case 2:
			sapxepMSSV(sinhvien[100], solgsinhvien);
			xuatThongTinSV(sinhvien[100], solgsinhvien);
			break;
		case 3:
			timSVtoan(sinhvien[100], solgsinhvien);
			break;
		case 4:
			xuatdtb_min(sinhvien[100], solgsinhvien);
			break;
		case 5:
			timSinhVien(sinhvien[100], solgsinhvien);
			break;
		case 6:
			timSVtheodiem(sinhvien[100], solgsinhvien);
			break;
		default: cout << "Ohh! There're some errors, please exit and restart this program";
	}
	return 0;
}
//===========================================================================================================
void nhapThongTinSV(thongtinsinhvien, int solgsinhvien) {
	for (int i = 0; i < solgsinhvien; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
		cout << "MSSV: "; cin >> sinhvien[i].mssv;
		cin.ignore();
		cout << "Ho va ten: "; getline(cin, sinhvien[i].hoten);
		cout << "Diem toan: "; cin >> sinhvien[i].dtoan;
		cout << "Diem Ly: "; cin >> sinhvien[i].dly;
	}
}
void xuatThongTinSV(thongtinsinhvien, int solgsinhvien) {
	system("cls");
	for (int i = 0; i < solgsinhvien; i++) {
		cout << sinhvien[i].mssv << '\t';
		cout << sinhvien[i].hoten << '\t';
		cout << sinhvien[i].dtoan << '\t';
		cout << sinhvien[i].dly;
		cout << endl;
	}
}
void sapxepMSSV(thongtinsinhvien, int i, int j){
	if (sinhvien[i].mssv < sinhvien[j].mssv) {
		int mssv = sinhvien[i].mssv;
		sinhvien[i].mssv = sinhvien[j].mssv;
		sinhvien[j].mssv = mssv;
		string name = sinhvien[i].hoten;
		sinhvien[i].hoten = sinhvien[j].hoten;
		sinhvien[j].hoten = name;
		float diemtoan = sinhvien[i].dtoan;
		sinhvien[i].dtoan = sinhvien[j].dtoan;
		sinhvien[j].dtoan = diemtoan;
		float diemly = sinhvien[i].dly;
		sinhvien[i].dly = sinhvien[j].dly;
		sinhvien[j].dly = diemly;
	}
}
void sapxepMSSV(thongtinsinhvien, int solgsinhvien) {
	for (int i = 0; i < solgsinhvien; i++) {
		for (int j = 0; j < i; j++) {
			sapxepMSSV (sinhvien[100], i, j);
		}
	}
}
void timSVtoan(thongtinsinhvien, int solgsinhvien){
	system("cls");
	int Max = sinhvien[0].dtoan;
	cout << "Sinh vien co diem toan cao nhat: \n";
	for (int i = 0; i < solgsinhvien; i++) {
		if (sinhvien[i].dtoan > Max) {
		Max = sinhvien[i].dtoan;
		}
	}
	for (int i = 0; i < solgsinhvien; i++) {
		if (sinhvien[i].dtoan == Max) {
			cout << "\n------------------------------------------\n";
			cout << sinhvien[i].mssv;
			cout << '\t' << sinhvien[i].hoten;
			cout << '\t' << sinhvien[i].dtoan;
			cout << '\t' << sinhvien[i].dly;
			cout << endl;
		}
	}
}
void xuatdtb_min(thongtinsinhvien, int solgsinhvien) {
	system("cls");
	float minest = (sinhvien[0].dtoan + sinhvien[0].dly) / 2.0;
	for (int i = 0; i < solgsinhvien; i++) {
		float miner = (sinhvien[i].dtoan + sinhvien[i].dly) / 2.0;
		if (miner <= minest) {
			minest = miner;
		}
	}
	for (int i = 0; i < solgsinhvien; i++) {
		if ((sinhvien[i].dtoan + sinhvien[i].dly)/2 == minest) {
			cout << "\n------------------------------------------\n";
			cout << sinhvien[i].mssv;
			cout << '\t' << sinhvien[i].hoten;
			cout << '\t' << sinhvien[i].dtoan;
			cout << '\t' << sinhvien[i].dly;
			cout << "\nDiem trung binh: " << (sinhvien[i].dtoan + sinhvien[i].dly) / 2;
			cout << endl;
		}
	}
}
void timSinhVien(thongtinsinhvien, int solgsinhvien) {
	system("cls");
	int timMSSV;
	cout << "Nhap MSSV de tim kiem thong tin sinh vien: ";
	cin >> timMSSV;
	for (int i = 0; i < solgsinhvien; i++) {
		if (sinhvien[i].mssv == timMSSV) {
			cout << sinhvien[i].mssv << '\t';
			cout << sinhvien[i].hoten << '\t';
			cout << sinhvien[i].dtoan << '\t';
			cout << sinhvien[i].dly;
			break;
		}
	}
}
void upperCase(thongtinsinhvien, int solgsinhvien) {
	for (int i = 0; i < solgsinhvien; i++) {
		for (int j = 0; j < sinhvien[i].hoten.length();j++) {
			if (sinhvien[i].hoten[j] > 96) {
				sinhvien[i].hoten[j] -= 32 ;
			}
		}
		cout << sinhvien[i].hoten << endl;
	}
}
void timSVtheodiem(thongtinsinhvien, int solgsinhvien) {
	system("cls");
	int select;
	float toan, ly;
	cout << "Ban muon tim kiem theo diem ly hay diem toan?\n";
	cout << "\t 1) Tim theo diem toan\n";
	cout << "\t 2) Tim theo diem ly\n";
	cin >> select;
	switch (select) {
		case 1:
			cout << "Nhap diem toan ban can tim kiem: ";
			cin >> toan;
			for (int i = 0; i < solgsinhvien; i++) {
				if (sinhvien[i].dtoan == toan) {
					cout << sinhvien[i].mssv;
					cout << '\t' << sinhvien[i].hoten;
					cout << '\t' << sinhvien[i].dtoan;
					cout << '\t' << sinhvien[i].dly;
					cout << "\n---------------------------------------------------------\n";
				}
			}
			break;
		case 2:
			cout << "Nhap diem ly ban can tim kiem: ";
			cin >> ly;
			for (int i = 0; i < solgsinhvien; i++) {
				if (sinhvien[i].dtoan == ly) {
					cout << sinhvien[i].mssv;
					cout << '\t' << sinhvien[i].hoten;
					cout << '\t' << sinhvien[i].dtoan;
					cout << '\t' << sinhvien[i].dly;
					cout << "\n---------------------------------------------------------\n";
				}
			}
			break;

		default:
		cout << "Out of Option!";
		}
}