#include<iostream>
#include<fstream>
using namespace std;
int n, a[50];

void citire(int a[], int &n)
{
	int i;
	ifstream f("in.txt");
	f >> n;
	for(i = 1; i <= n; i++)
		f >> a[i];
}

void back(int st[], int k)
{
	int ev;
	if(k>=1)
	{
		if(k>1)
		{
			cout << "{";
			for(int i = 1; i < k; i++)
				cout << a[st[i]] << ',';
			cout << "\b} " << endl;
		}
		for(int i = 1; i <= n; i++)
		{
			st[k] = i;
			ev=1;
			if(k>1 && st[k]<=st[k-1])
				ev=0;
			if(k>n)
				ev=0;
			if(ev)
				back(st, k+1);
		}
	}
}

int main()
{
	int st[50];
	citire(a,n);
	back(st, 1);
	return 0;
}
