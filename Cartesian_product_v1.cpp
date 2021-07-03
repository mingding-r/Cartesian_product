// dikaer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"stdlib.h"
#include<vector>
#include<sstream>
using namespace std;
vector<string> res;
string temp;
void dfs(vector<vector<string>> matrix, string temp, int i) {
	int r = matrix.size();
	int c = matrix[i].size();
	if (i == r) {
		res.push_back(temp);
		cout << temp << endl;
	}
	else {
		for (int j = 0; j < c; j++) {
			string t = temp;
			temp += matrix[i][j];
			dfs(matrix, temp, i + 1);
			temp = t;
		}
	}
}
int main()
{
	int n, m;
	cout << "请输入因子数量n:" << endl;
	cin >> n;
	cout << "请输入每个因子的形式数量m:" << endl;
	cin >> m;
	vector<vector<string>> matrix(n,vector<string>(m));
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个因子,形式之间用ENTER分隔" << endl;
		if(i==0)cin.ignore();
		for (int j = 0; j < m; j++) {
			getline(cin, matrix[i][j]);
		}
	}
	dfs(matrix,"",0);
	int num = res.size();
	for (int i = 0; i < num; i++) {
		cout << res[i] << endl;
	}
	
		system("pause");
}
