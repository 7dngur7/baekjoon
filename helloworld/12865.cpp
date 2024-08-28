#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int> > pro(101);

int banang[101][100001] = { 0 };




int main() {
	int n;
	int max_w; 
	int answer=0;


	cin >> n>> max_w;

	int num = 0;
	for (int i = 1; i < n+1; i++) {
		cin >> pro[i].first >> pro[i].second;
	}

	
	for (int j = 1; j < max_w + 1; j++) {
		for (int i = 1; i < n + 1; i++) {
			if (j >= pro[i].first) {
				banang[i][j] = max(banang[i - 1][j - pro[i].first] + pro[i].second, banang[i - 1][j]); // 최댓값 최신화
			}
			else {
				banang[i][j] = banang[i - 1][j];
			}
		}
	}
	
	
	

	cout<< banang[n][max_w] << endl;
}
