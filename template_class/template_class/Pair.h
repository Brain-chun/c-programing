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
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return first;
}

template <class T>
void Pair<T>::SetFirst(T firstval)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	first = firstval;

}

template <class T>
T Pair<T>::GetSecond() const
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return second;
}

template <class T>
void Pair<T>::SetSecond(T secondval)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	second = secondval;
}
