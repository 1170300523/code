#include<iostream>
#include<Windows.h>
#include<new>
#include<fstream>
#include"ChainListUnit.h"
using namespace std;
/*
c++�������͵����������v1.2	����by kreig

������ṹ��

������
-Length:int			����ĳ���
-head				�����ͷָ��
-----------------------------------------------------------------------------------------------------------------------------
���캯��
+Chainlist<T>()													���캯������ʼ��˽�б�������������ʱ�Զ�����
+~Chainlist<T>()												����������ɾ�������ͷ����пռ䣬������������ʧʱ�Զ�����
*******															�������캯����ʵ���������֮��ĸ�ֵ������ʵ���У�
*******															+��������غ�����ʵ��ʹ��+����������������������½�ͷβ�ڵ�Ĳ�����ʵ���У�
*******															-��������غ�����ʵ��ʹ��-���������ɾ��ָ���ڵ�Ĳ�����ʵ���У�
*******															~��������غ�����ʵ��ʹ��~�����ʹ������Ĳ�����ʵ���У�
------------------------------------------------------------------------------------------------------------------------------
�����������
+CreatNewList(Date��T)											����������͵�һ���ڵ㣬�������һ������<Date>
+BuildNextUnit(Date��T)											�ڱ�β������һ�ڵ㣬����������<Date>
+DelThisUnit(ID��int)											ɾ��ָ�����<ID>����Ӧ��һ���ڵ�
+InsertAfterThis��Date��T��ID��int��							��ָ�����<ID>�Ľڵ�����ڵ㣬������ýڵ������<Date>	
+InsertFrontThis(Date:T, ID:int)								��ָ�����<ID>�Ľڵ�ǰ����ڵ㣬������ýڵ������<Date>
+DelAllUnit()													ɾ����������
------------------------------------------------------------------------------------------------------------------------------
���ݴ������
+ShowTheDate��ID��int) ��T										����ָ�����<ID>�Ľڵ������
+PrintAllDate()													��������˳���ӡ���нڵ�����<ID>������<Date>
+RewriteTheDate��Date��T,ID��int��								�޸�ָ�����<ID>�Ľڵ������<Date>
+TransToArray(): T*												������תΪ��Ӧ�������͵����飬��������ָ�루ע��������ʹ��ShowTheLength������������ȣ�
********														��һ������ת��Ϊ��Ӧ���͵�����ʵ���У�
********														ָ������<Date>,������������������ͬ����<Date>�Ľڵ��ID��ʵ���У�
-------------------------------------------------------------------------------------------------------------------------------
�ļ���д����
+WriteIntoFile(Address��string)									����������д��һ��ָ����ַ<Address>��ע���硰a.txt"����C:\\Users\\asus\\Desktop\\a.txt��)
																���ļ�������ļ������ڽ����Զ�����
+WIFRange(Address:string, ID_begin:int , ID_end:int)			������ָ��ID<ID_begin><ID_end>����Ӧ�Ľڵ�֮������нڵ㣨�����������ڵ㣩������д��һ��
																ָ����ַ<Address>���ļ�
+ReadFromFilm(Address��string,initialize��T)					��һ��ָ����ַ<Address>���ļ��������ݲ�д������֮��Ľڵ㣨ע�����û���½��������Զ�������
																����ѽ�����Ḳ���ѽ���������
-------------------------------------------------------------------------------------------------------------------------------
�����������
+ShowTheLength������int											����������
+GiveMeHead()��ChainListUnit<T>*								��������ͷָ�루ע���ǵ�������ʹ�ã�


˵����

1.ʹ�ø�������뽫<ChainList.h>��<ChainListUnit.h>�ŵ�<main.c>ͬһĿ¼�£�����<main.c>������
	include "ChainList.h"
	include "ChainListUnit.h"
2.�ÿ�Ϊģ����⣬����������ʽ����
	ChainList<��Ҫ����������> ������
  ���磺
	ChainList<int> a; ChainList<double> b; ChainList<char[4]> c
	****************
	#include <string>
	ChainList<string> d
	****************
	struct link
	{
		int a;
		double b;
	}
	ChainList<struct link> e
  ���е�����<Date>������T���Զ��滻Ϊ�������������͡�
3.IDΪ�ڵ����ţ���0��ʼ��ÿһ���½ڵ��Զ����ӣ����еĺ������ýڵ��ID��Ψһ��ʶ��һ���ڵ㡣
4.���ʹ�ýṹ�塢�����塢��ȸ�������������Ϊ������������ͣ����ú���PrintAllDate��WriteIntoFile��WIFRangeǰ���ֶ����ظ��������͵�"<<"�������
  ���ú���ReadFromFilmǰ���ֶ����ظ��������͵�">>"������������ܱ�����"<<"�������ͬ�ṹ��
  ���磺
	struct Currency 
	{
		int Dollar;
		int Cents;
		friend ostream &operator<<(ostream &out,Currency value);	������������ostreamΪ��Ԫ
		friend istream &operator>>(istream &in,Currency value);	�����������istreamΪ��Ԫ
     }
	 ostream& operator<<(ostream &out,Currency value)	����<<�����
	 {
		out<<"The dollar = "<<value.Dollar<<" and The Cents = "<<value.Cents<<endl;
		return out;
	 }
	 istream& operator<<(istream &in,Currency value)	����>>�����
	 {
		in<<"The dollar = "<<value.Dollar<<" and The Cents = "<<value.Cents<<endl;
		return in;
	 }
5.��������鴫��Ĳ������ڷ�������󵯳�������ʾ�������������ʽ <��������д ERROR������ԭ��>�����Ը��ݴ�����ʾ����bug��
6.�Ըÿ���κ�ʹ�����⡢bug�ύ��ϸ�ڽ��������������߽�����qq1533583676��


*/		
template<typename T>
class ChainList
{
public:
	ChainList();
	~ChainList();
	void CreatNewList(T Date);
	void BuildNextUnit(T Date);
	void DelThisUnit(int ID);
	void DelAllUnit();
	T ShowTheDate(int ID);
	void RewriteTheDate(T Date,int ID);
	void PrintAllDate();
	T* SerchThisDate(T Date);
	T* TransToArray();
	void InsertAfterThis(T Date, int ID);
	void InsertFrontThis(T Date, int ID);
	void WriteIntoFile(string Address);
	void WIFRange(string Address, int ID_begin , int ID_end);
	void ReadFromFilm(string Address,T initialize);
	int ShowTheLength();
	ChainListUnit<T>* GiveMeHead();
private:
	int Length;
	ChainListUnit<T> *head;
};



template<typename T>
ChainList<T>::ChainList()
{
	int Length = 0;
	ChainListUnit<T> *head = nullptr;
}
template<typename T>
ChainList<T>::~ChainList()
{
	this->DelAllUnit();
}
template<typename T>
void ChainList<T>::CreatNewList(T Date)
{
	if (head != nullptr)
	{
		MessageBox(NULL, TEXT("CNL ERROR:LIST HAS BEEN BUILD"), TEXT("ERROR"), MB_OK);
		return;
	}	
	Length++;
	try
	{
		head = new ChainListUnit<T>;
	}
	catch (std::bad_alloc)
	{
		MessageBox(NULL, TEXT("ERROR:NO ENOUGH SPACE"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	head = new ChainListUnit<T>;
	head->Date = Date;
	head->ID = 0;
	head->next = nullptr;
	return;
}
template<typename T>
void ChainList<T>::BuildNextUnit(T Date)
{
	ChainListUnit<T> *tmp = nullptr;
	try
	{
		ChainListUnit<T> *next = new ChainListUnit<T>;
	}
	catch (std::bad_alloc)
	{
		MessageBox(NULL, TEXT("ERROR:NO ENOUGH SPACE"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	ChainListUnit<T> *next = new ChainListUnit<T>;
	for (tmp = head;tmp->next != nullptr;)
		{
			tmp = tmp->next;
		}
	tmp->next = next;
	next->Date = Date;
	next->ID = tmp->ID + 1;
	Length++;
	return;
}
template<typename T>
void ChainList<T>::DelThisUnit(int ID)
{
	if (ID >= Length||ID<0)
	{
		MessageBox(NULL, TEXT("DTU ERROR:ID OVER RANGE"), TEXT("ERROR"), MB_OK);
		return;
	}
	else
	{
		ChainListUnit<T> *tmpB = nullptr;
		ChainListUnit<T> *tmpE = nullptr;
		ChainListUnit<T> *tmp = nullptr;
		ChainListUnit<T> *tmp_t = nullptr;
		if (ID == 0)
		{
			tmp = head;
			tmp_t = head;
		}
		else
		{
			for (tmpB = head;tmpB->ID != ID - 1;)
				{
					tmpB = tmpB->next;
				}
			tmp = tmpB->next;
			tmp_t = tmpB->next;
		}
		tmpE = tmp->next;
		for (tmp_t = tmpE; tmp_t != nullptr;)
		{
			tmp_t->ID--;
			tmp_t = tmp_t->next;
		}
		if (ID != 0)
			tmpB->next = tmpE;
		else
			head = tmp->next;
		delete(tmp);
		Length--;
		return;
	}
}
template<typename T>
void ChainList<T>::DelAllUnit()
{
	for (int n = Length - 1; n >= 0; n--)
	{
		this->DelThisUnit(n);
	}
	head = nullptr;
	Length = 0;
	return;
}
template<typename T>
T ChainList<T>::ShowTheDate(int ID)
{
	if (ID >= Length || ID<0)
	{
		MessageBox(NULL, TEXT("STD ERROR:ID OVER RANGE"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	ChainListUnit<T> *tmp = nullptr;
	for (tmp = head;tmp->ID != ID;)
		{
			tmp = tmp->next;
		}
	return tmp->Date;
}
template<typename T>
void ChainList<T>::PrintAllDate()
{
	cout << endl;
	if (Length == 0)
	{
		cout << "NO DATE";
		return;
	}
		
	ChainListUnit<T> *tmp = nullptr;
	for (tmp = head;tmp!=nullptr;)
	{
		cout << tmp->ID << "\t" << tmp->Date << endl;
		tmp = tmp->next;
	}
	return;
}
template<typename T>
int ChainList<T>::ShowTheLength()
{
	return Length;
}
template<typename T>
ChainListUnit<T>* ChainList<T>::GiveMeHead()
{
	return head;
}
template<typename T>
void ChainList<T>::InsertAfterThis(T Date, int ID)
{
	if (ID >= Length || ID<0)
	{
		MessageBox(NULL, TEXT("IAT ERROR:ID OVER RANGE"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	ChainListUnit<T> *tmp = nullptr;
	for (tmp = head; tmp->ID != ID;)
	{
		tmp = tmp->next;
	}
	ChainListUnit<T> *next = new ChainListUnit<T>;
	next->Date = Date;
	next->ID = tmp->ID + 1;
	next->next = tmp->next;
	tmp->next = next;
	for (tmp=tmp->next->next;tmp != nullptr;)
	{
		tmp->ID++;
		tmp = tmp->next;
	}

}
template<typename T>
void  ChainList<T>::InsertFrontThis(T Date, int ID)
{
	if (ID >= Length || ID<0)
	{
		MessageBox(NULL, TEXT("IFT ERROR:ID OVER RANGE"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	ChainListUnit<T> *tmp = nullptr;
	ChainListUnit<T> *front = new ChainListUnit<T>;
	if (ID == 0)
	{
		front->next = head;
		head = front;
		front->Date = Date;
		front->ID = 0;
		for (tmp = front->next; tmp != nullptr;)
		{
			tmp->ID++;
			tmp = tmp->next;
		}
	}
	else
	{
		for (tmp = head; tmp->ID != ID-1;)
		{
			tmp = tmp->next;
		}
		front->Date = Date;
		front->ID = tmp->ID + 1;
		front->next = tmp->next;
		tmp->next = front;
		for (tmp = tmp->next->next; tmp != nullptr;)
		{
			tmp->ID++;
			tmp = tmp->next;
		}
	}
}
template<typename T>
void ChainList<T>::RewriteTheDate(T Date,int ID)
{
	if (ID >= Length || ID<0)
	{
		MessageBox(NULL, TEXT("RTD ERROR:ID OVER RANGE"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	ChainListUnit<T> *tmp = nullptr;
	for (tmp = head; tmp->ID != ID;)
	{
		tmp = tmp->next;
	}
	tmp->Date = Date;
}
template<typename T>
void ChainList<T>::WriteIntoFile(string Address)
{
	fstream output;
	output.open(Address.c_str(), ofstream::out);
	if (output.is_open()==0)
	{
		MessageBox(NULL, TEXT("ERROR:FILE OPEN FAILED"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	ChainListUnit<T> *tmp = nullptr;
	for (tmp = head; tmp != nullptr;)
	{
		output << tmp->ID << " " << tmp->Date << endl;
		tmp = tmp->next;
	}
	output.close();
}
template<typename T>
void ChainList<T>::WIFRange(string Address, int ID_begin, int ID_end )
{
	if (ID_begin >= Length || ID_begin<0|| ID_end >= Length || ID_end<0)
	{
		MessageBox(NULL, TEXT("ERROR:ID OVER RANGE"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	fstream output;
	output.open(Address.c_str(), ofstream::out);
	if (output.is_open() == 0)
	{
		MessageBox(NULL, TEXT("ERROR:FILE OPEN FAILED"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	ChainListUnit<T> *tmp = nullptr;
	for (tmp = head; tmp->ID != ID_begin;)
	{
		tmp = tmp->next;
	}
	for (; tmp->ID != ID_end+1;)
	{
		output << tmp->ID << " " << tmp->Date << endl;
		tmp = tmp->next;
	}
	output.close();

}
template<typename T>
void  ChainList<T>::ReadFromFilm(string Address,T initialize)
{
	this->DelAllUnit();
	fstream input;
	input.open(Address.c_str(), ofstream::in);
	if (input.is_open() == 0)
	{
		MessageBox(NULL, TEXT("ERROR:FILE OPEN FAILED"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	int ID;
	T Date= initialize;
	this->CreatNewList(initialize);
	while (input.peek() != EOF)
	{
		input >> ID >> Date;
		if (Length - 1 < ID)
		{
			do {
				this->BuildNextUnit(initialize);
			} while (Length - 1 != ID);
			this->RewriteTheDate(Date, ID);
		}
		else
			this->RewriteTheDate(Date, ID);	
	}
	input.close();
}
template<typename T>
T* ChainList<T>::TransToArray()
{
	T* Arr = new T[this->ShowTheLength()];
	ChainListUnit<T> *tmp=nullptr;
	for (tmp = head; tmp != nullptr;)
	{
		Arr[tmp->ID] = tmp->Date;
		tmp = tmp->next;
	}
	return Arr;
}