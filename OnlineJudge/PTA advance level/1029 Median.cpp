﻿/*
1029 Median（25 point(s)）
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10
​5
​​ ) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output Specification:
For each test case you should output the median of the two given sequences in a line.

Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int N = 200005;
const int INF = 0x7fffffff;
int input[N] = { 0 };
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n;
	fill(&input[0], &input[0 + N], INF);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &input[i]);
	}
	cin >> m;

	int count = 0, C_i = 1, mid = (n + m + 1) / 2;

	for (int i = 1; i <= m; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		while (input[C_i] < tmp)
		{
			count++;
			if (count == mid)cout << input[C_i];
			C_i++;
		}
		count++;
		if (count == mid)cout << tmp;
	}

	while (C_i <= n)
	{
		count++;
		if (count == mid)cout << input[C_i];
		C_i++;
	}

	return 0;
}