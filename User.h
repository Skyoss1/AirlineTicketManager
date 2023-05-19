#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include"Date.h"
#include"Chuyenbay.h"
using namespace std;
class User
{
private:
	string hoTen;
	string CMND;
	bool gioiTinh;
	string SDT;
	string Email;
	string NgaySinh;

public:
	User(){}
	User(string hoTen, string CMND, bool gioiTinh, string SDT, string Email, string NgaySinh)
	{
		this->hoTen = hoTen;
		this->CMND = CMND;
		this->gioiTinh = gioiTinh;
		this->SDT = SDT;
		this->Email = Email;
		this->NgaySinh = NgaySinh;
	}

	~User() {}

	void standardName(string& name)// định dang lại tên dữ liệu
	{
		while (name[0] == ' ')
			name.erase(0, 1);
		while (name[name.length() - 1] == ' ')
			name.pop_back();

		int i = 0;
		while (i < name.length() - 1)
		{
			if (name[i] == ' ' && name[i + 1] == ' ')
			{
				name.erase(i, 1);
				i--;
			}
			i++;
		}

		int l = name.length();
		char* strlwr((char*)name.c_str());
	}

	string getHoTen() const
	{
		return hoTen;
	}
	void setHoTen(string hoTen)
	{
		this->hoTen = hoTen;
	}

	string getCMND() const
	{
		return this->CMND;
	}
	void setCMND(string CMND)
	{
		this->CMND = CMND;
	}

	bool getGioiTinh() const
	{
		return gioiTinh;
	}

	void setGioiTinh(bool gioiTinh)
	{
		if (gioiTinh == true)
			cout << "Nam";
		else
			cout << "Nu";
	}
	

	string getSDT() const
	{
		return this->SDT;
	}
	void setSDT(string SDT)
	{
		this->SDT = SDT;
	}

	string getEmail() const
	{
		return this->Email;
	}

	void setEmail(string Email)
	{
		this->Email = Email;
	}

	string getNgaySinh() const {
		return this->NgaySinh;
	}

	void setNgaySinh(string NgaySinh) {
		this->NgaySinh = NgaySinh;
	}

	virtual void input()
	{
		cin.ignore();
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
		standardName(hoTen);
		cout << "Gioi tinh: (1 - Nam, 0 - Nu): "; cin >> gioiTinh;
		cout << "SDT: "; cin >> SDT;
		cout << "Emaiil: "; cin >> Email;
		cout << "Ngay sinh: "; cin >>NgaySinh;
	}
	virtual void output()
	{
		cout << "Ho ten: " << getHoTen() << endl;
		cout << "Gioi tinh: " << getGioiTinh() << endl;
		cout << "SDT: " << getSDT() << endl;
		cout << "Email: " << getEmail() << endl;
		cout << "Ngay sinh: " << getNgaySinh() << endl;
	}
};

class HanhKhach :public User
{
private:
	string maHanhKhach;
	ChuyenBay* ve;
	int Sove;

public:
	HanhKhach(){}
	HanhKhach(string MaHK,ChuyenBay* ve, string hoTen, string CMND, bool gioiTinh, string SDT, string Email, string NgaySinh, int Sove) : User(hoTen, CMND, gioiTinh, SDT,  Email,  NgaySinh)
	{
		this->maHanhKhach = MaHK;
		this->ve = ve;
		this->Sove = Sove;
	}

	~HanhKhach() {}

	string getMaHanhKhach() const
	{
		return this->maHanhKhach;
	}

	void setMaHanhKhach(string maHanhKhach)
	{
		this->maHanhKhach = maHanhKhach;
	}
	int tongtien() {
		int total = 0;
		for (int i = 0; i < Sove; i++) {
			total += ve[i].getGiaGoc();
		}
		return total;
	}

	/*void addTicketClass(DatVe* _datVe) {
		this->datVe.push_back(_datVe);
	}*/

	void input()
	{
		User::input();

		cin.ignore();
		cout << "Nhap ma hanh khach: ";
		getline(cin, maHanhKhach);

		do {
			cout << "Nhap so luong ve: ";
			cin >> Sove;

			if (Sove <= 0) {
				cout << "So luong ve khong hop le. Vui long nhap lai.\n";
			}
		} while (Sove <= 0);

		ve = new ChuyenBay[Sove];
		for (int i = 0; i < Sove; i++) {
			cout << "\nNhap thong tin ve thu " << i + 1 << ": ";
			ve[i].input();
		}
		delete[] ve;
	}

	void output()
	{
		User::output();
		cout << "Ma Khach Hang: " << getMaHanhKhach() << endl;
		for (int i = 0; i < Sove; i++) {
			cout << "\nThong tin ve thu " << i + 1 << ":";
			ve[i].output();
		}
		cout << "\nTong tien phai tra: " << tongtien() << endl;
		cout << "============================" << endl;
	}
};
