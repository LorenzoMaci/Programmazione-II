#include <iostream>
using namespace std;

int ricerca_binaria(int a[], int chiave, int sin, int des)
{
	if(sin == des)
	{
		if(chiave == a[sin])
			return true;
		else
			return -1;
	}

	int centro = (sin + des) / 2;

	if(chiave <= a[centro])
		return ricerca_binaria(a, chiave, sin, centro);
	else
		return ricerca_binaria(a, chiave, centro+1, des);
}

int main()
{
	int vett[10] = {1,2,3,4,5,6,7,8,9,10};
	cout << ricerca_binaria(vett, 9, 0, 9) << endl;
	return 0;
}