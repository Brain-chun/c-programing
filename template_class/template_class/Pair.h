#pragma once
//typedef  char T;
template <class T>
class Pair
{
private:
	T first;
	T second;
public:
	Pair();
	Pair(T firstval, T secondval);
	T GetFirst()const;
	void SetFirst(T firstval);
	T GetSecond()const;
	void SetSecond(T secondval);
};

template <class T>
Pair<T>::Pair()
{

}

template <class T>
Pair<T>::Pair(T firstval, T secondval)
{
	first = firstval;
	second = secondval;
}

template <class T>
T Pair<T>::GetFirst() const
{
	// TODO: 여기에 구현 코드 추가.
	return first;
}

template <class T>
void Pair<T>::SetFirst(T firstval)
{
	// TODO: 여기에 구현 코드 추가.
	first = firstval;

}

template <class T>
T Pair<T>::GetSecond() const
{
	// TODO: 여기에 구현 코드 추가.
	return second;
}

template <class T>
void Pair<T>::SetSecond(T secondval)
{
	// TODO: 여기에 구현 코드 추가.
	second = secondval;
}
