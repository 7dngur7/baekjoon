#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;
vector<pair<double,double> >arr;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (-y1 * x2 - y2 * x3 - y3 * x1);
	return res / 2;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    double n;
    cin>>n;

    double ans=0;

    for(double i=0; i<n; i++){
        double a, b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }

	double res = 0;
	for (int i = 1; i < n; i++)
		res += ccw(arr[0].first, arr[i - 1].first, arr[i].first, arr[0].second, arr[i - 1].second, arr[i].second);

	printf("%.1lf", abs(res));

    // auto num1 = v[0];


    // for(double i=1; i<n-1; i++){
    //     //삼각형 넓이 계산(신발끈)
    //     auto num2 = v[i];
    //     auto num3 = v[i+1];
    //     double cur = abs(num1.first*num2.second+num2.first*num3.second+num3.first*num1.second - num1.second*num2.first - num2.second*num3.first- num3.second*num1.first);
    //     ans += cur/2.0;
    // }

    // printf("%.1f\n", ans);
    //printf("%.1f\n", floor(ans*10)/10);
}