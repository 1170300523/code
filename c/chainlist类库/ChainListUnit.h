#pragma once
template<typename T>
class ChainListUnit
{
public:
	template<typename T>
	friend class ChainList;
	ChainListUnit();
	~ChainListUnit();
	ChainListUnit<T> *next;
	ChainListUnit<T> *prev;
	int ID;
	T Date;
private:
	static int Count;
};

template<typename T>
ChainListUnit<T>::ChainListUnit()
{
	Count++;
}

template<typename T>
ChainListUnit<T>::~ChainListUnit()
{
	Count--;
}
template<typename T>
int ChainListUnit<T>::Count = 0;
