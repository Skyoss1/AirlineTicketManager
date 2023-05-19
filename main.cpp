#include <iostream>
#include "User.h"
#include "Date.h"
#include"ChuyenBay.h"
using namespace std;

void SortbyTongTien(HanhKhach* ds[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i]->tongtien() > ds[j]->tongtien()) {
                HanhKhach* temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void menu() {
    string option;
    HanhKhach* listHanhKhach[100];
    int n = 0;
    string group, id;
    while (1) {
        system("cls");
        cout << "\n---------------------MENU---------------------\n";
        cout << "1. Nhap thong tin hanh khach.\n";
        cout << "2. Xuat danh sach hanh khach.\n";
        cout << "3. Sap xep danh sach hanh khach theo tong tien.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "------------------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> option;
        if (option == "1") {
            cout << "\nNhap thong tin hanh khach thu " << n + 1 << endl;
            HanhKhach* hk = new HanhKhach("", NULL, "", "", 1, "", "", "", 0);
            hk->input();
            listHanhKhach[n] = hk;
            n++;
        }
        else if (option == "2") {
            for (int i = 0; i < n; i++) {
                cout << "\nThong tin hanh khach thu " << i + 1 << ":" << endl;
                listHanhKhach[i]->output();
            }
        }

        else if (option == "3") {
            SortbyTongTien(listHanhKhach, n);
            cout << "\nDanh sach hanh khach da duoc sap xep theo tong tien:\n";
            for (int i = 0; i < n; i++) {
                cout << "\nThong tin hanh khach thu " << i + 1 << ":" << endl;
                listHanhKhach[i]->output();
            }
        }
        else if (option == "0") {
            break;
        }
        else
            continue;
        system("pause");
    }
}

int main()
{
    menu();
    return 0;
}