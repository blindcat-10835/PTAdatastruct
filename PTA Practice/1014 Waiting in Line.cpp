﻿/*
1014 Waiting in Line（30 point(s)）
Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
Customer
​i
​​  will take T
​i
​​  minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer
​1
​​  is served at window
​1
​​  while customer
​2
​​  is served at window
​2
​​ . Customer
​3
​​  will wait in front of window
​1
​​  and customer
​4
​​ will wait in front of window
​2
​​ . Customer
​5
​​  will wait behind the yellow line.

At 08:01, customer
​1
​​  is done and customer
​5
​​  enters the line in front of window
​1
​​  since that line seems shorter now. Customer
​2
​​  will leave at 08:02, customer
​4
​​  at 08:06, customer
​3
​​  at 08:07, and finally customer
​5
​​  at 08:10.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (≤20, number of windows), M (≤10, the maximum capacity of each line inside the yellow line), K (≤1000, number of customers), and Q (≤1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

Output Specification:
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.

Sample Input:
2 2 7 7
1 2 6 4 3 534 2
1 2 3 4 5 6 7
Sample Output:
08:07
08:06
08:10
17:00
Sorry
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int N = 10002;
const int INF = 999999;
struct Window
{
	int list[N] = { 0 };
	int head = 1;
	int end = 0;
};
Window win[25];
int cost[N] = { 0 };
int EndTime[N] = { 0 };
int inQ(int win_i, int cust_i)
{
	win[win_i].end++;
	int curEnd = win[win_i].end;
	if (win[win_i].list[curEnd - 1] >= 540)//sorry的情况
	{
		win[win_i].list[curEnd] = INF;
		EndTime[cust_i] = INF;
	}
	else//可以
	{
		win[win_i].list[curEnd] = cost[cust_i] + win[win_i].list[curEnd - 1];
		EndTime[cust_i] = win[win_i].list[curEnd];
		return 0;
	}
}
int main(int argc, char const *argv[])
{
	int  Windows, Capacity, Customers, Queries;
	cin >> Windows >> Capacity >> Customers >> Queries;
	for (int Customer_i = 1; Customer_i <= Customers; Customer_i++)
	{
		scanf("%d", &cost[Customer_i]);
		if (Customer_i <= Windows * Capacity)
		{
			//只入队
			int curWin = (Customer_i - 1) % Windows + 1;
			inQ(curWin, Customer_i);
		}
		else
		{
			//既有入队又有出队
			int curWin = -1;
			int tmpPopTime = INF + 1;//这里为了使curWin不会等于-1
			for (int i = 1; i <= Windows; i++)
			{
				if (win[i].list[win[i].head] < tmpPopTime)
				{
					tmpPopTime = win[i].list[win[i].head];
					curWin = i;
				}
			}
			win[curWin].head++;
			inQ(curWin, Customer_i);
		}
	}
	for (int i = 1; i <= Queries; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (EndTime[tmp] < INF)
		{
			int hour = EndTime[tmp] / 60 + 8, minute = EndTime[tmp] % 60;
			printf("%02d:%02d\n", hour, minute);
		}
		else
		{
			printf("Sorry\n");
		}
	}
	return 0;
}