#include<iostream>
#include<Windows.h>
#include<new>
#include<fstream>
#include"ChainListUnit.h"
using namespace std;
/*
c++复合类型单向链表类库v1.2	——by kreig

链表类结构：

参数：
-Length:int			链表的长度
-head				链表的头指针
-----------------------------------------------------------------------------------------------------------------------------
构造函数
+Chainlist<T>()													构造函数，初始化私有变量，声明链表时自动调用
+~Chainlist<T>()												析构函数，删除链表，释放所有空间，链表作用域消失时自动调用
*******															拷贝构造函数，实现链表对象之间的赋值操作（实现中）
*******															+运算符重载函数，实现使用+运算符进行链接两个链表、新建头尾节点的操作（实现中）
*******															-运算符重载函数，实现使用-运算符进行删除指定节点的操作（实现中）
*******															~运算符重载函数，实现使用~运算符使链表反向的操作（实现中）
------------------------------------------------------------------------------------------------------------------------------
链表基本操作
+CreatNewList(Date：T)											创建新链表和第一个节点，并传入第一个数据<Date>
+BuildNextUnit(Date：T)											在表尾建立下一节点，并传入数据<Date>
+DelThisUnit(ID：int)											删除指定序号<ID>所对应的一个节点
+InsertAfterThis（Date：T，ID：int）							在指定序号<ID>的节点后插入节点，并传入该节点的数据<Date>	
+InsertFrontThis(Date:T, ID:int)								在指定序号<ID>的节点前插入节点，并传入该节点的数据<Date>
+DelAllUnit()													删除整个链表
------------------------------------------------------------------------------------------------------------------------------
数据处理操作
+ShowTheDate（ID：int) ：T										传出指定序号<ID>的节点的数据
+PrintAllDate()													按照链表顺序打印所有节点的序号<ID>和数据<Date>
+RewriteTheDate（Date：T,ID：int）								修改指定序号<ID>的节点的数据<Date>
+TransToArray(): T*												将链表转为对应数据类型的数组，传出数组指针（注：请立即使用ShowTheLength（）标记数组宽度）
********														将一个数组转换为对应类型的链表（实现中）
********														指定数据<Date>,查找链表中所有有相同数据<Date>的节点的ID（实现中）
-------------------------------------------------------------------------------------------------------------------------------
文件读写操作
+WriteIntoFile(Address：string)									将整个链表写入一个指定地址<Address>（注：如“a.txt"、“C:\\Users\\asus\\Desktop\\a.txt”)
																的文件，如果文件不存在将会自动建立
+WIFRange(Address:string, ID_begin:int , ID_end:int)			将两个指定ID<ID_begin><ID_end>所对应的节点之间的所有节点（包括这两个节点）的数据写入一个
																指定地址<Address>的文件
+ReadFromFilm(Address：string,initialize：T)					从一个指定地址<Address>的文件读入数据并写入链表之后的节点（注：如果没有新建链表将会自动建立，
																如果已建立则会覆盖已建立的链表）
-------------------------------------------------------------------------------------------------------------------------------
链表特殊操作
+ShowTheLength（）：int											返回链表长度
+GiveMeHead()：ChainListUnit<T>*								返回链表头指针（注：非调试请勿使用）


说明：

1.使用该链表库请将<ChainList.h>、<ChainListUnit.h>放到<main.c>同一目录下，并在<main.c>中声明
	include "ChainList.h"
	include "ChainListUnit.h"
2.该库为模板类库，声明对象形式如下
	ChainList<需要的数据类型> 对象名
  例如：
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
  库中的数据<Date>的类型T会自动替换为声明的数据类型。
3.ID为节点的序号，从0开始，每一个新节点自动增加，库中的函数调用节点的ID来唯一的识别一个节点。
4.如果使用结构体、共用体、类等复合数据类型作为链表的数据类型，调用函数PrintAllDate、WriteIntoFile、WIFRange前请手动重载该数据类型的"<<"运算符，
  调用函数ReadFromFilm前请手动重载该数据类型的">>"运算符并尽可能保持与"<<"运算符相同结构。
  例如：
	struct Currency 
	{
		int Dollar;
		int Cents;
		friend ostream &operator<<(ostream &out,Currency value);	声明流输入类ostream为友元
		friend istream &operator>>(istream &in,Currency value);	声明流输出类istream为友元
     }
	 ostream& operator<<(ostream &out,Currency value)	重载<<运算符
	 {
		out<<"The dollar = "<<value.Dollar<<" and The Cents = "<<value.Cents<<endl;
		return out;
	 }
	 istream& operator<<(istream &in,Currency value)	重载>>运算符
	 {
		in<<"The dollar = "<<value.Dollar<<" and The Cents = "<<value.Cents<<endl;
		return in;
	 }
5.函数会检验传入的参数并在发生错误后弹出窗口提示并跳出，报错格式 <函数名简写 ERROR：错误原因>，可以根据错误提示查找bug。
6.对该库的任何使用问题、bug提交、细节交流都可以与作者交流，qq1533583676。


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