
#include<iostream>
#include<fstream>
using namespace std;
//Khai bao kieu du lieu Thuoc
struct Thuoc
{
	string MaThuoc;
	string TenThuoc;
	float GiaBan;
	int LuotBan;
};
//Định nghĩa nút trong hàng đợi
struct Node
{
	Thuoc Data;
	Node *Next;
};
//Định nghĩa hàng đợi có tên Queue
struct Queue
{
	Node *Front,*Rear;//2 đầu thêm vào và lấy ra của hàng đợi
	int SoPhanTu;//Số phần tử hiện tại của hàng đợi
};
//Khai báo hàm

void KhoiTao(Queue &Q);
bool KiemTraRong(Queue Q);
int DoDai(Queue Q);
void HienThi(Queue Q);
Node *TaoNut(Thuoc t);
void Push(Queue &Q, Thuoc t);
void Pop(Queue &Q, Thuoc &t);
void Peek(Queue Q, Thuoc &t);
void TimThuocTheoMa(Queue Q, string MaThuoc);
void TimThuocTheoTen(Queue Q, string TenThuoc);
void ThuocGiaCaoNhat(Queue Q);
void ThuocGiaThapNhat(Queue Q);
void ThuocBanChayNhat(Queue Q);
void TongDoanhThu(Queue Q);
void GhiVaoTep(Queue Q);
void DocTuTep(Queue &Q);
void Menu();
int main()
{
	Menu();
	return 0;
}
//Định nghĩa hàm
void KhoiTao(Queue &Q)
{
	Q.Front = Q.Rear = NULL;
	Q.SoPhanTu = 0;
}
bool KiemTraRong(Queue Q)
{
	return (Q.Front == NULL);
}
int DoDai(Queue Q)
{
	return Q.SoPhanTu;
}

void HienThi(Queue Q)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong!\n";
	}
	else
	{
		Node *p = Q.Front;

		cout<<"Ma Thuoc\tTen Thuoc\tGia Ban\tLuot Ban\n";

		while(p != NULL)
		{
			cout<<p->Data.MaThuoc<<"\t"
				<<p->Data.TenThuoc<<"\t"
				<<p->Data.GiaBan<<"\t"
				<<p->Data.LuotBan<<endl;

			p = p->Next;
		}
	}
}
void Push(Queue &Q, Thuoc t)
{
	Node *p = new Node;
	p->Data = t;
	p->Next = NULL;
	if(KiemTraRong(Q))
	{
		Q.Front = Q.Rear = p;
	}
	else
	{
		Q.Rear->Next = p;
		Q.Rear = p;
	}
	Q.SoPhanTu++;
}
void NhapThuoc(Thuoc &t)
{
	cout<<"Nhap ma thuoc: ";
	cin>>t.MaThuoc;
	cin.ignore();
	cout<<"Nhap ten thuoc: ";
	getline(cin,t.TenThuoc);
	cout<<"Nhap gia ban: ";
	cin>>t.GiaBan;
	cout<<"Nhap luot ban: ";
	cin>>t.LuotBan;
}
void Pop(Queue &Q, Thuoc &t)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		Node *p = Q.Front;
		t = p->Data;
		Q.Front = Q.Front->Next;
		delete p;
		Q.SoPhanTu--;
		if(Q.Front == NULL)
		{
			Q.Rear = NULL;
		}
	}
}
void Peek(Queue Q, Thuoc &t)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		t = Q.Front->Data;
	}
}
void TimThuocTheoMa(Queue Q, string MaThuoc)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		Node *p = Q.Front;
		bool found = false;
		while(p != NULL)
		{
			if(p->Data.MaThuoc == MaThuoc)
			{
				cout<<"Ma Thuoc: "<<p->Data.MaThuoc<<"\tTen Thuoc: "<<p->Data.TenThuoc<<"\tGia Ban: "<<p->Data.GiaBan<<endl;
				found = true;
				break;
			}
			p = p->Next;
		}
		if(!found)
		{
			cout<<"Khong tim thay thuoc co ma: "<<MaThuoc<<endl;
		}
	}
}
void TimThuocTheoTen(Queue Q, string TenThuoc)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		Node *p = Q.Front;
		bool found = false;
		while(p != NULL)
		{
			if(p->Data.TenThuoc == TenThuoc)
			{
				cout<<"Ma Thuoc: "<<p->Data.MaThuoc<<"\tTen Thuoc: "<<p->Data.TenThuoc<<"\tGia Ban: "<<p->Data.GiaBan<<endl;
				found = true;
				break;
			}
			p = p->Next;
		}
		if(!found)
		{
			cout<<"Khong tim thay thuoc co ten: "<<TenThuoc<<endl;
		}
	}
}

void ThuocGiaCaoNhat(Queue Q)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		Node *p = Q.Front;
		Thuoc maxThuoc = p->Data;
		while(p != NULL)
		{
			if(p->Data.GiaBan > maxThuoc.GiaBan)
			{
				maxThuoc = p->Data;
			}
			p = p->Next;
		}
		cout<<"Thuoc co gia cao nhat: \n";
		cout<<"Ma Thuoc: "<<maxThuoc.MaThuoc<<"\tTen Thuoc: "<<maxThuoc.TenThuoc<<"\tGia Ban: "<<maxThuoc.GiaBan<<endl;
	}
}
void ThuocGiaThapNhat(Queue Q)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		Node *p = Q.Front;
		Thuoc minThuoc = p->Data;
		while(p != NULL)
		{
			if(p->Data.GiaBan < minThuoc.GiaBan)
			{
				minThuoc = p->Data;
			}
			p = p->Next;
		}
		cout<<"Thuoc co gia thap nhat: \n";
		cout<<"Ma Thuoc: "<<minThuoc.MaThuoc<<"\tTen Thuoc: "<<minThuoc.TenThuoc<<"\tGia Ban: "<<minThuoc.GiaBan<<endl;
	}
}
void ThuocBanChayNhat(Queue Q)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		Node *p = Q.Front;
		Thuoc maxLuotBan = p->Data;
		while(p != NULL)
		{
			if(p->Data.LuotBan > maxLuotBan.LuotBan)
			{
				maxLuotBan = p->Data;
			}
			p = p->Next;
		}
		cout<<"Thuoc ban chay nhat: \n";
		cout<<"Ma Thuoc: "<<maxLuotBan.MaThuoc<<"\tTen Thuoc: "<<maxLuotBan.TenThuoc<<"\tGia Ban: "<<maxLuotBan.GiaBan<<"\tLuot Ban: "<<maxLuotBan.LuotBan<<endl;
	}
}
void TongDoanhThu(Queue Q)
{
	if(KiemTraRong(Q))
	{
		cout<<"Hang doi rong! \n";
	}
	else
	{
		Node *p = Q.Front;
		float tongDoanhThu = 0;
		while(p != NULL)
		{
			tongDoanhThu += p->Data.GiaBan * p->Data.LuotBan;
			p = p->Next;
		}
		cout<<"Tong doanh thu: "<<tongDoanhThu<<endl;
	}
}
void GhiVaoTep(Queue Q)
{
	ofstream outFile("Thuoc.txt");
	if(!outFile)
	{
		cout<<"Khong the mo tep!\n";
		return;
	}
	Node *p = Q.Front;
	while(p != NULL)
	{
		outFile<<p->Data.MaThuoc<<endl;
		outFile<<p->Data.TenThuoc<<endl;
		outFile<<p->Data.GiaBan<<endl;
		outFile<<p->Data.LuotBan<<endl;
		p = p->Next;
	}

	outFile.close();
}
void DocTuTep(Queue &Q)
{
	ifstream inFile("Thuoc.txt");
	if(!inFile)
	{
		cout<<"Khong the mo tep!\n";
		return;
	}
	KhoiTao(Q);
	Thuoc t;
	while(inFile>>t.MaThuoc)
	{
		inFile.ignore();
		getline(inFile,t.TenThuoc);
		inFile>>t.GiaBan;
		inFile>>t.LuotBan;
		Push(Q,t);
	}
	inFile.close();
}
void Menu()
{
	int LuaChon;
	Queue Q;
	Thuoc t;

	do
	{
	cout<<"-------------------------------------------\n";
cout<<"CHUC NANG QUAN LY THUOC - QUEUE - 2026\n";
cout<<"-------------------------------------------\n";
cout<<"1. Khoi tao hang doi\n";
cout<<"2. Kiem tra hang doi rong\n";
cout<<"3. Do dai hang doi\n";
cout<<"4. Hien thi danh sach thuoc\n";
cout<<"5. Them thuoc vao hang doi \n";
cout<<"6. Xem thuoc dau hang doi \n";
cout<<"7. Lay va xoa thuoc dau hang doi\n";
cout<<"8. Tim thuoc theo ma\n";
cout<<"9. Tim thuoc theo ten\n";
cout<<"10. Thuoc gia cao nhat\n";
cout<<"11. Thuoc gia thap nhat\n";
cout<<"12. Thuoc ban chay nhat\n";
cout<<"13. Tong doanh thu\n";
cout<<"14. Ghi danh sach vao tep\n";
cout<<"15. Doc danh sach tu tep\n";
cout<<"0. Thoat\n";
cout<<"-------------------------------------------\n";
cout<<"Lua chon chuc nang? ";
cin>>LuaChon;
		switch (LuaChon)
		{
			case 1://Khởi tạo
			{
				KhoiTao(Q);
				cout<<"Da khoi tao! \n";
				break;
			}
			case 2: //Kiểm tra rỗng
			{
				if(KiemTraRong(Q))
				{
					cout<<"Hang doi rong! \n";
				}
				else
				{
					cout<<"Hang doi khong rong! \n";
				}
				break;
			}
			case 3://Độ dài hàng đợi
			{
				cout<<"Do dai hang doi la: "<<DoDai(Q)<<endl;
				break;
			}
			case 4://Hiển thị
			{
				HienThi(Q);
				break;
			}
		case 5://Thêm thuốc vào hàng đợi
			{
				NhapThuoc(t);
				Push(Q,t);
				cout<<"Da them thuoc vao hang doi! \n";
				break;
			}
			case 6://Xem thuốc đầu hàng đợi
			{
				Peek(Q,t);
				cout<<"Thuoc dau hang doi: \n";
				cout<<"Ma Thuoc: "<<t.MaThuoc<<"\tTen Thuoc: "<<t.TenThuoc<<"\tGia Ban: "<<t.GiaBan<<endl;
				break;
			}
			case 7://Lấy và xóa thuốc đầu hàng đợi
			{
				Pop(Q,t);
				cout<<"Da lay va xoa thuoc dau hang doi! \n";
				break;
			}
			case 8://Tìm thuốc theo mã
			{
				string MaThuoc;
				cout<<"Nhap ma thuoc can tim: ";
				cin>>MaThuoc;
				TimThuocTheoMa(Q,MaThuoc);
				break;
			}
			case 9://Tìm thuốc theo tên
			{
				string TenThuoc;
				cout<<"Nhap ten thuoc can tim: ";
				cin.ignore();
				getline(cin,TenThuoc);
				TimThuocTheoTen(Q,TenThuoc);
				break;
			}
	case 10://Thuốc giá cao nhất
			{
				ThuocGiaCaoNhat(Q);
				break;
			}
			case 11://Thuốc giá thấp nhất
			{
				ThuocGiaThapNhat(Q);
				break;
			}
			case 12://Thuốc bán chạy nhất
			{
				ThuocBanChayNhat(Q);
				break;
			}
			case 13://Tổng doanh thu
			{
				TongDoanhThu(Q);
				break;
			}
			case 14://Ghi danh sách vào tệp
			{
				GhiVaoTep(Q);
				cout<<"Da ghi danh sach vao tep! \n";
				break;
			}
			case 15://Đọc danh sách từ tệp
			{
				DocTuTep(Q);
				cout<<"Da doc danh sach tu tep! \n";
				break;
			}
			case 0: //Thoat
			{
				cout<<"Tam biet! \n";
				break;
			}
		}
	}while(LuaChon!=0);
}