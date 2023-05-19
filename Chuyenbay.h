#include<iostream>
#include "Date.h"
#include <utility>
#include <string>

using namespace std;
class ChuyenBay
{
private:
	string maChuyenBay;
	string ngayGioBay;
	string ngayGioDen;
	string maDatVe;
	double giaGoc;
public:
	ChuyenBay(){}
	ChuyenBay(string maChuyenBay, string ngayGioBay, string ngayGioDen,string maDatve, double giaGoc)
	{
		this->maChuyenBay = maChuyenBay;
		this->ngayGioBay = ngayGioBay;
		this->ngayGioDen = ngayGioDen;
		this->maDatVe = maDatVe;
		this->giaGoc = giaGoc;
	}
	string getMaChuyenBay()
	{
		return this->maChuyenBay;
	}

	void setMaChuyenBay(string maChuyenBay)
	{
		this->maChuyenBay = maChuyenBay;
	}

	string getNgayGioBay()
	{
		return this->ngayGioBay;
	}

	void setNgayGioBay(const string ngayGioBay)
	{
		this->ngayGioBay = ngayGioBay;
	}

	string getNgayGioDen()
	{
		return this->ngayGioDen;
	}

	void setNgayGioDen(const string& ngayGioDen)
	{
		this->ngayGioDen = ngayGioDen;
	}

	string getMaDatVe() {
		return this->maDatVe;
	}
	void setMaDatVe(string) {
		this->maDatVe = maDatVe;
	}

	double getGiaGoc()
	{
		return this->giaGoc;
	}

	void setGiaGoc(double giaGoc)
	{
		this->giaGoc = giaGoc;
	}

	virtual void input()
	{
		cin.ignore();
		cout << "\nMa chuyen bay: ";
		getline(cin, maChuyenBay);
		cout << "Nhap ngay bay: \n";
		getline(cin, ngayGioBay);
		cout << "Nhap ngay den: \n";
		getline(cin, ngayGioDen);
		cout << "Nhap gia ve: \n";
		cin >> giaGoc;
	}

	virtual void output()
	{
		cout << "\nMa chuyen bay: " << getMaChuyenBay() << endl;
		cout << "Ngay bay: " << getNgayGioBay() << endl;
		cout << "Ngay Ha Canh: " << getNgayGioDen() << endl;
		cout << "Gia ve: " << getGiaGoc() << endl;
	}
};
#pragma once
