#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
#define RANGE 255

using namespace std;

// RANDOM DATA--------------------------------------
void GenerateRandomData(unsigned long long int a[], unsigned long long int n);
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(unsigned long long int a[], long int n);
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(unsigned long long int a[], unsigned long long int n);
// HÀM HOÁN VỊ
void HoanVi(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int x = a;
	a = b;
	b = x;
}

// RANDOM DATA--------------------------------------
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(unsigned long long int a[], unsigned long long int n)
{
	fstream data;
	data.open("D:\\HK1(2021)_Nam3\\TTCS\\DATA\\200000.txt", ios::out);
	
	srand((unsigned long long int)time(0));

	for (unsigned long long int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
		data << a[i] <<" ";
	}
	data.close();
}
void GenerateRandomDataHeap(int a[],int n)
{
//	fstream data;
//	data.open("D:\\HK1(2021)_Nam3\\TTCS\\DATA\\500000.txt", ios::out);
	
//	srand((unsigned long long int)time(0));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(unsigned long long int a[],unsigned long long int n)
{
	for (unsigned long long int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
void GenerateSortedDataHeap(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(unsigned long long int a[],unsigned long long int n)
{
	for (unsigned long long int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void GenerateReverseDataHeap(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void GenerateRanDomRange(unsigned long long int a[],unsigned long long int n,unsigned long long int b, unsigned long long int c)//b<=c
{
	srand((unsigned long long int)time(0));
	for (unsigned long long int i=0;i<n;i++){
			a[i]=b+rand()%(c-b+1);
	}
	
}
void GenerateRanDomRangeHeap(int a[],int n,int b, int c)//b<=c
{
	srand((int)time(0));
	for (int i=0;i<n;i++){
			a[i]=b+rand()%(c-b+1);
	}
	
}
// ----------------------IN DS-----------------------
void InDs(unsigned long long int a[],unsigned long long int n){
	for(unsigned long long int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void InDsHeap(int a[],int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void NhapDS(unsigned long long int a[], unsigned long long int n){
	for(unsigned long long int i = 0; i < n; i++){
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];		
	}
}
void NhapDSHeap(int a[],int n){
	for(int i = 0; i < n; i++){
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];		
	}
}
// ---------------------SHELL SORT------------------

void ShellSort(unsigned long long int a[], unsigned long long int n)
{
	// Bắt đầu với khoảng cách lớn, sau đó giảm khoảng cách
	for (unsigned long long int gap = n/2; gap > 0; gap /= 2)
    {
    	// Thực hiện sắp xếp chèn cho khoảng cách này.
		// Các phần tử khoảng cách đầu tiên a[0..gap-1] đã có thứ tự
		// tiếp tục thêm một phần tử nữa cho đến khi toàn bộ mảng là
		// đã được sắp xếp
        for (unsigned long long int i = gap; i < n; i += 1)
        {
        	// thêm a[i] vào các phần tử đã được sắp xếp trong khoảng cách(gap)
			// lưu a[i] tạm thời
            unsigned long long int temp = a[i];
            // chuyển các phần tử được sắp xếp theo khoảng cách trước đó lên cho đến khi đúng
			// vị trí a[i] được tìm thấy
            unsigned long long int j;           
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            // đặt giá trị a[j] tạm thời vào đúng vị trí của nó
            a[j] = temp;
        }
    }
}

// ---------------------COCKTAIL SORT---------------
void CocktailSort(unsigned long long int a[],unsigned long long int n)
{
    bool swapped = true;
    unsigned long long int start = 0;
    unsigned long long int end = n - 1;
    while (swapped)
    {
        // đặt lại cờ đã hoán đổi khi nhập
		// vòng lặp, vì nó có thể đúng từ một lần lặp trước đó.
        swapped = false;
 
        // vòng lặp từ trái sang phải giống như Bubble Sort
        for (unsigned long long int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1]) {
                HoanVi(a[i], a[i + 1]);
                swapped = true;
            }
        }
 
		// nếu không có gì được di chuyển, thì mảng được sắp xếp. 
        if (!swapped)
            break;
 
        // nếu không, hãy đặt lại cờ đã hoán đổi để nó
		// có thể được sử dụng trong giai đoạn tiếp theo
        swapped = false;
 
        // giảm end đi 1 đơn vị bởi pt cuối cùng đã đúng vị trí
        --end;
 
        // từ phải sang trái, thực hiện so sánh tương tự như trong giai đoạn trước
        for (unsigned long long int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1]) {
                HoanVi(a[i], a[i + 1]);
                swapped = true;
            }
        }
 		// Tăng điểm bắt đầu
        ++start;
    }
}

void CocktailSort_v2(unsigned long long int a[],unsigned long long int n)
{
	unsigned long long int Left = 0;
	unsigned long long int Right = n - 1;
	unsigned long long int k = 0;
	while (Left < Right)
	{
		for (unsigned long long int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (unsigned long long int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
// ---------------------COUNTING SORT - NUMBER------
void CountingSort(unsigned long long int input[],unsigned long long int n)
{
 
    unsigned long long int output[n]; // // Đầu ra sẽ có mảng đầu vào đã được sắp xếp
    unsigned long long int max = input[0];
    unsigned long long int min = input[0];
 
    for(unsigned long long int i = 1; i < n; i++)
    {
        if(input[i] > max)
            max = input[i]; // Giá trị lớn nhất trong mảng
        else if(input[i] < min)
            min = input[i]; // Giá trị nhỏ nhất trong mảng
    }
 
    unsigned long long int k = max - min + 1; // Kích thước của mảng đếm
 
    unsigned long long int count_array[k]; // Tạo một count_array để lưu trữ số lượng của từng giá trị đầu vào riêng lẻ
    fill_n(count_array, k, 0); // Khởi tạo các phần tử count_array bằng 0
 
    for(unsigned long long int i = 0; i < n; i++)
        count_array[input[i] - min]++; // Lưu trữ số lượng của từng giá trị đầu vào riêng lẻ
 
   /*Thay đổi count_array để count_array hiện chứa thực tế
      vị trí của các giá trị đầu vào trong mảng đầu ra*/
    for(unsigned long long int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];
 
 
    // Điền mảng đầu ra bằng cách sử dụng mảng đếm và mảng đầu vào
    for(unsigned long long int i = 0; i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }
 
 
    for(unsigned long long int i = 0; i < n; i++)
        input[i] = output[i]; 
	//Sao chép mảng đầu ra vào đầu vào, để đầu vào bây giờ chứa các giá trị đã được sắp xếp
 
}

//----------------------HEAP SORT-------------------
void heapify(int arr[],int n,int i)
{
	int largest = i; // khoi tao largest nhu la root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// Neu nut con trai lon hon so voi root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Neu nut con phai lon hon so voi root
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Neu root khong phai la lon nhat
	if (largest != i) //Xấu nhất/ Tốt SWAP = 1 //XẤU NHẤT n
	{
		swap(arr[i], arr[largest]);

		// De quy lai ham heapify
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void HeapSort(int arr[],int n)
{
	// Tao mot dong (Sap xep lai mang)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);//1

	// for cùng cấp = (n/2 i => (0;n/2) + 2n = 5n/2 = n => Tốt nhất
	// Xấu nhất n*n/2 + n  +  n^2 => n^2 => n^2 => Xấu nhất
	// Trích xuất từng một phần tử một từ heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Di chuyen root ve cuoi cung
		swap(arr[0], arr[i]);// Tốt nhất: n

		// goi ham heapify
		heapify(arr, i, 0);// n = 2n
	}
}
void Menu(){
	cout << "==============CAC THUAT TOAN SAP XEP=============\n";
	cout << "|         1. SHELL SORT				|\n";
	cout << "|         2. COCKTAIL SORT			|\n";
	cout << "|         3. COUNTING SORT			|\n";
	cout << "|         4. HEAP SORT				|\n";
	cout << "=================================================\n";
	cout << "\nVui long lua chon thuat toan muon sap xep: ";
}
//--------------------------MAIN-------------------

char str[100];
int main(){
	unsigned long long int n;
	int lc,pt,pt2, pt3, start, end;	
	Menu();
	cin >> lc;
	cout << "==============CAC PHUONG THUOC DAU VAO===========\n";
	cout << "|         1. TU BAN PHIM			|\n";
	cout << "|         2. RANDOM				|\n";
	cout << "|         3. TU FILE				|\n";
	cout << "=================================================\n";
	cout << "\nVui long lua chon phuong thuc nhap muon sap xep: ";
	cin >> pt;
	if(pt == 2){
		cout << "==============CAC PHUOC THUOC DAU VAO============\n";
		cout << "|         1. RANDOM MANG NGAU NHIEN		|\n";
		cout << "|         2. RANDOM MANG TRONG TH TOT NHAT	|\n";
		cout << "|         3. RANDOM MANG TRONG TH XAU NHAT	|\n";
		cout << "|         4. RANDOM MANG TRONG KHOANG GT	|\n";
		cout << "=================================================\n";
		cout << "\nVui long lua chon phuong thuc RANDOM: ";
		cin >> pt2;
		cout << "Phuong thuc RANDOM: " << pt2 << endl;
	}
	if(pt==3){
		cout << "==============Chon bo du lieu: =================\n";
		cout << "|	1. 50000 			   	|\n";
		cout << "|	2. 90000			   	|\n";
		cout << "|	3. 100000			   	|\n";
		cout << "|	4. 200000 so tang dan		   	|\n";
		cout << "|	5. 200000 so giam dan		   	|\n";
		cout << "================================================\n";
		cout << "\nVui long lua chon file dau vao: ";
		cin >> pt3;
		cout << "File dau vao la: " << pt3 << endl;
	}
	switch(lc){
		// SHELL SORT-------------------------------------------------
		case 1:{
			cout << "\nBan da chon Shell Sort";
			if(pt == 1){
				cout << "\nPhuong thuc nhap tu ban phim!!";
				cout << "\nNhap n: ";
				cin >> n;
				unsigned long long int a[n];
				NhapDS(a,n);
				cout << "Mang sau khi nhap: ";
				InDs(a, n);
				ShellSort(a, n);
				cout << "Mang sau khi sap xep: ";
				InDs(a, n);
			}
			if(pt == 2){
				cout << "\nPhuong thuc RANDOM!!";
				if(pt2 == 1){
					cout << "\nRANDOM MANG NGAU NHIEN!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateRandomData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					ShellSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 2){
					cout << "\nRANDOM MANG TRONG TH TOT NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateSortedData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					ShellSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 3){
					cout << "\nRANDOM MANG TRONG TH XAU NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateReverseData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					ShellSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 4){
					cout << "\nRANDOM MANG TRONG KHOANG GT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					cout << "\nNhap gt bat dau: ";
					cin >> start;
					cout << "\nNhap gt ket thuc: ";
					cin >> end;
					GenerateRanDomRange(a,n,start,end);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					ShellSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
			}
			if(pt == 3){
				switch(pt3){
					case 1:{
						ifstream ifs("DATA/50000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							ShellSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 2:{
						ifstream ifs("DATA/90000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							ShellSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 3:{
						ifstream ifs("DATA/100000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							ShellSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 4:{
						ifstream ifs("DATA/200000_TD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							ShellSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 5:{
						ifstream ifs("DATA/200000_GD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							ShellSort(a, n);
							InDs(a,n);
						}
						break;
					}
				}

			}
			break;
		}
		// COCKTAIL SORT ---------------------------------------------------
		case 2:{
			cout << "\nBan da chon Cocktail Sort\n";
			if(pt == 1){
				cout << "\nPhuong thuc nhap tu ban phim!!";
				cout << "\nNhap n: ";
				cin >> n;
				unsigned long long int a[n];
				NhapDS(a,n);
				cout << "Mang sau khi nhap: ";
				InDs(a, n);
				CocktailSort_v2(a, n);
				cout << "Mang sau khi sap xep: ";
				InDs(a, n);
			}
			if(pt == 2){
				cout << "\nPhuong thuc RANDOM!!";
				if(pt2 == 1){
					cout << "\nRANDOM MANG NGAU NHIEN!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateRandomData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CocktailSort_v2(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 2){
					cout << "\nRANDOM MANG TRONG TH TOT NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateSortedData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CocktailSort_v2(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 3){
					cout << "\nRANDOM MANG TRONG TH XAU NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateReverseData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CocktailSort_v2(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 4){
					cout << "\nRANDOM MANG TRONG KHOANG GT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					cout << "\nNhap gt bat dau: ";
					cin >> start;
					cout << "\nNhap gt ket thuc: ";
					cin >> end;
					GenerateRanDomRange(a,n,start,end);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CocktailSort_v2(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
			}
			if(pt == 3){
				switch(pt3){
					case 1:{
						ifstream ifs("DATA/50000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CocktailSort_v2(a, n);
							InDs(a,n);
						}
						break;
					}
					case 2:{
						ifstream ifs("DATA/90000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CocktailSort_v2(a, n);
							InDs(a,n);
						}
						break;
					}
					case 3:{
						ifstream ifs("DATA/100000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CocktailSort_v2(a, n);
							InDs(a,n);
						}
						break;
					}
					case 4:{
						ifstream ifs("DATA/200000_TD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CocktailSort_v2(a, n);
							InDs(a,n);
						}
						break;
					}
					case 5:{
						ifstream ifs("DATA/200000_GD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CocktailSort_v2(a, n);
							InDs(a,n);
						}
						break;
					}
				}
			}
			break;
		}
		//COUTING SORT
		case 3:{
			cout << "\nBan da chon Counting Sort";
			if(pt == 1){
				cout << "\nPhuong thuc nhap tu ban phim!!";
				cout << "\nNhap n: ";
				cin >> n;
				unsigned long long int a[n];
				NhapDS(a,n);
				cout << "Mang sau khi nhap: ";
				InDs(a, n);
				CountingSort(a, n);
				cout << "Mang sau khi sap xep: ";
				InDs(a, n);
			}
			if(pt == 2){
				cout << "\nPhuong thuc RANDOM!!";
				if(pt2 == 1){
					cout << "\nRANDOM MANG NGAU NHIEN!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateRandomData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CountingSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 2){
					cout << "\nRANDOM MANG TRONG TH TOT NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateSortedData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CountingSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 3){
					cout << "\nRANDOM MANG TRONG TH XAU NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					GenerateReverseData(a,n);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CountingSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
				if(pt2 == 4){
					cout << "\nRANDOM MANG TRONG KHOANG GT!!";
					cout << "\nNhap n: ";
					cin >> n;
					unsigned long long int a[n];
					cout << "\nNhap gt bat dau: ";
					cin >> start;
					cout << "\nNhap gt ket thuc: ";
					cin >> end;
					GenerateRanDomRange(a,n,start,end);
					cout << "Mang sau khi nhap: ";
					InDs(a, n);
					CountingSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDs(a, n);
				}
			}
			if(pt == 3){
				switch(pt3){
					case 1:{
						ifstream ifs("DATA/50000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CountingSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 2:{
						ifstream ifs("DATA/90000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CountingSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 3:{
						ifstream ifs("DATA/100000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CountingSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 4:{
						ifstream ifs("DATA/200000_TD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CountingSort(a, n);
							InDs(a,n);
						}
						break;
					}
					case 5:{
						ifstream ifs("DATA/200000_GD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	unsigned long long int a[n];
					    	cout << "SL pt " << n;
							for(unsigned long long int i = 0; i < n; i++){
								ifs >> a[i];
							}
							unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDs(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							CountingSort(a, n);
							InDs(a,n);
						}
						break;
					}
				}
			}
			break;
		}
		// HEAP SORT ------------------------------------------------------
		case 4:{
			cout << "\nBan da chon Heap Sort";
			if(pt == 1){
				cout << "\nPhuong thuc nhap tu ban phim!!";
				cout << "\nNhap n: ";
				cin >> n;
				int a[n];
				NhapDSHeap(a,n);
				cout << "Mang sau khi nhap: ";
				InDsHeap(a, n);
				HeapSort(a, n);
				cout << "Mang sau khi sap xep: ";
				InDsHeap(a, n);
			}
			if(pt == 2){
				cout << "\nPhuong thuc RANDOM!!";
				if(pt2 == 1){
					cout << "\nRANDOM MANG NGAU NHIEN!!";
					cout << "\nNhap n: ";
					cin >> n;
					int a[n];
					GenerateRandomDataHeap(a,n);
					cout << "Mang sau khi nhap: ";
					InDsHeap(a, n);
					HeapSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDsHeap(a, n);
				}
				if(pt2 == 2){
					cout << "\nRANDOM MANG TRONG TH TOT NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					int a[n];
					GenerateSortedDataHeap(a,n);
					cout << "Mang sau khi nhap: ";
					InDsHeap(a, n);
					HeapSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDsHeap(a, n);
				}
				if(pt2 == 3){
					cout << "\nRANDOM MANG TRONG TH XAU NHAT!!";
					cout << "\nNhap n: ";
					cin >> n;
					int a[n];
					GenerateReverseDataHeap(a,n);
					cout << "Mang sau khi nhap: ";
					InDsHeap(a, n);
					HeapSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDsHeap(a, n);
				}
				if(pt2 == 4){
					cout << "\nRANDOM MANG TRONG KHOANG GT!!";
					cout << "\nNhap n: ";
					cin >> n;
					int a[n];
					cout << "\nNhap gt bat dau: ";
					cin >> start;
					cout << "\nNhap gt ket thuc: ";
					cin >> end;
					GenerateRanDomRangeHeap(a,n,start,end);
					cout << "Mang sau khi nhap: ";
					InDsHeap(a, n);
					HeapSort(a, n);
					cout << "Mang sau khi sap xep: ";
					InDsHeap(a, n);
				}
			}
			if(pt == 3){
				switch(pt3){
					case 1:{
						ifstream ifs("DATA/50000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	static int a[50000];
					    	cout << "SL pt " << n;
							for(int i = 0; i < n; i++){
								ifs >> a[i];
							}
							int length = sizeof(a)/sizeof(int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDsHeap(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							HeapSort(a, n);
							InDsHeap(a,n);
						}
						break;
					}
					case 2:{
						ifstream ifs("DATA/90000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	static int a[90000];
					    	cout << "SL pt " << n;
							for(int i = 0; i < n; i++){
								ifs >> a[i];
							}
							int length = sizeof(a)/sizeof(int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDsHeap(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							HeapSort(a, n);
							InDsHeap(a,n);
						}
						break;
					}
					case 3:{
						ifstream ifs("DATA/100000.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	static int a[100000];
					    	cout << "SL pt " << n;
							for(int i = 0; i < n; i++){
								ifs >> a[i];
							}
							int length = sizeof(a)/sizeof(int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDsHeap(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							HeapSort(a, n);
							InDsHeap(a,n);
						}
						break;
					}
					case 4:{
						ifstream ifs("DATA/200000_TD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	static int a[200000];
					    	cout << "SL pt " << n;
							for(int i = 0; i < n; i++){
								ifs >> a[i];
							}
							int length = sizeof(a)/sizeof(int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDsHeap(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							HeapSort(a, n);
							InDsHeap(a,n);
						}
						break;
					}
					case 5:{
						ifstream ifs("DATA/200000_GD.txt");
					    if(!ifs){
					        cerr << "Error: file not opened." << endl;
					    }
					    else{
							ifs >> n;
					    	static int a[200000];
					    	cout << "SL pt " << n;
							for(int i = 0; i < n; i++){
								ifs >> a[i];
							}
							int length = sizeof(a)/sizeof(int);
							cout << "\nSl mang la: " << length << endl;
							cout << "\nMang la:\n";
							InDsHeap(a,n);
							cout << "\n\nMang sau khi sap xep la:" << endl;
							HeapSort(a, n);
							InDsHeap(a,n);
						}
						break;
					}
				}
			}
			break;
		}
		default:{
			cout << "\nLua chon khong ton tai";
			break;
		}
	}
	return 0;
}