#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<string.h>
using namespace std;




int main()
{
	string s;
	cin >> s;
	string b = "";
	vector <double> vv;
	int j;
	for ( j = 0; j < s.length(); j++)
	{
		if (s[j] != ',')
		{
			b += s[j];
		}
		else
		{

			double a = 0;
			/*for (int h = 0; h <b.length(); h++)
			{
				a *= 10;
				a += (b[h] - 48);
				
			}*/
			vv.push_back(stod(b,NULL));
			b = "";
		}
	}
	/*double a = 0;
	for (int h = 0; h <b.length(); h++)
	{
		a *= 10;
		a += (b[h] - 48);

	}*/
	vv.push_back(stod(b,NULL));
	sort(vv.begin(),vv.end());

	double min;
	double max;
	double Q1;
	double Q2;
	double Q3;

	cout << "for this data:" << endl;
	cout << "MIN:" << vv[0] << endl;
	if (vv.size() % 2 == 0)
	{
		Q2 = (vv[(vv.size() / 2)-1] + vv[(vv.size() / 2)]) / 2;
		double n = vv.size() / 2;
		if ((vv.size() / 2) % 2 == 0)
		{
			Q1 = (vv[(n / 2)-1] + vv[n / 2])/2;
			Q3 = (vv[n + (n / 2) - 1] + vv[n + (n / 2)])/2;
		}
		else
		{
			Q1 = vv[n / 2];
			Q3 = vv[n + n / 2];
		}
	}
	else if (vv.size() % 2 == 1)
	{
		Q2 = vv[vv.size()/2];
		double m = vv.size() / 2;
		if ((vv.size() / 2) % 2 == 0)
		{
			Q1 = (vv[(m / 2) - 1] + vv[(m / 2)]) / 2;
			Q3 = (vv[m + (m / 2) - 1] + (vv[m + (m / 2)]) / 2);
		}
		else
		{
			Q1 = vv[m / 2];
			Q3 = vv[m +1+ (m / 2)];
		}

	}
	max = vv[vv.size() - 1];
	cout.setf(ios::fixed);
	cout << "Q1:" << setprecision(2) << Q1 << "--" << "Q2:" << setprecision(2) << Q2 << "--" << "Q3:" << setprecision(2) << Q3 << endl;
	cout << "MAX:" << max<<endl;

	double iqr = Q3 - Q1;
	double nn = 1.5*iqr;
	double o = nn + Q3;  //x>o
	double oo = Q1 - nn; //x<oo
	vector<double> vvv;
	for (int f = 0; f < vv.size(); f++)
	{
		if (vv[f]>o)
			vvv.push_back(vv[f]);
		if (vv[f] < oo)
			vvv.push_back(vv[f]);
	}
	if (vvv.empty())
		cout << "OUTLIERS:" << " There is no outlier";
	else
		for (int c = 0; c < vvv.size(); c++)
			cout << "OUTLIERS:" << vvv[c];
	_getch();
	return 0;
}

