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
	for ( j = 0; j < s.length(); j++)                 //جداسازی اعداد ورودی و تبدیل از حالت رشته به عدد
	{
		if (s[j] != ',')
		{
			b += s[j];
		}
		else
		{
			vv.push_back(stod(b,NULL));
			b = "";
		}
	}
	vv.push_back(stod(b,NULL));                       // برای آخرین عدد-> تبدیل از حالت رشته به عدد
	sort(vv.begin(),vv.end());                        //مرتب سازی لیست اعداد
	double min;
	double max;
	double Q1;
	double Q2;
	double Q3;
	cout << "for this data:" << endl;
	cout << "MIN:" << vv[0] << endl;        //چاپ مقدار مینیمم

	if (vv.size() % 2 == 0)                 //محاسبه ی مقادیر Q1,Q2,Q3
	{
		Q2 = (vv[(vv.size() / 2)-1] + vv[(vv.size() / 2)]) / 2;
		double n = vv.size() / 2;
		if ((vv.size() / 2) % 2 == 0)
		{
			Q1 = ((vv[(n / 2)-1]) + (vv[n / 2]))/2;
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
			Q1 = ((vv[(m / 2) - 1]) + (vv[(m / 2)]) )/ 2;
			Q3 =( (vv[m + (m / 2)]) + (vv[m+1 + (m / 2)]))/2;
		}
		else
		{
			Q1 = vv[m / 2];
			Q3 = vv[m +1+ (m / 2)];
		}
	}
	max = vv[vv.size() - 1];                            //چاپ مقدار ماکسیمم
	cout.setf(ios::fixed);                             // جلوگیری از نمایش عدد با نماد علمی
	cout << "Q1:" << setprecision(2) << Q1 << "--" << "Q2:" << setprecision(2) << Q2 << "--" << "Q3:" << setprecision(2) << Q3 << endl;
	cout << "MAX:" << max<<endl;

	double iqr = Q3 - Q1;
	double nn = 1.5*iqr;
	double o = nn + Q3;  //x>o
	double oo = Q1 - nn; //x<oo
	vector<double> vvv;
	for (int f = 0; f < vv.size(); f++)                   //بررسی وجود و عدم وجود outlier
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

