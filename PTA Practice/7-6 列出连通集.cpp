﻿/*
7-6 列出连通集（25 point(s)）
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
按照"{ v​1​​  v​2​​  ... v​k​​  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
using namespace std;
int Graph[10][10];

void DFS(int Root, int length, bool isVisited[])
{
	isVisited[Root] = true;
	cout << Root << " ";
	for (int j = 0; j < length; j++)
	{
		if (Graph[Root][j] && isVisited[j] == false)
			DFS(j, length, isVisited);
	}
	return;
}

void BFS(int Root, int length, bool isVisited[])
{
	queue<int> Q;
	Q.push(Root);
	isVisited[Root] = true;
	while (!Q.empty())
	{
		cout << Q.front() << " ";
		for (int j = 0; j < length; j++)
		{
			if (Graph[Q.front()][j] && isVisited[j] == false)
			{
				Q.push(j);
				isVisited[j] = true;
			}
		}
		Q.pop();
	}
	return;
}

int main(int argc, char const *argv[])
{
	int N = 10, E;
	bool isVisited[10];
	fill(&isVisited[0], &isVisited[10], false);
	fill(&Graph[0][0], &Graph[10][10], 0);
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		Graph[a][b] = Graph[b][a] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (!isVisited[i])
		{
			cout << "{ ";
			DFS(i, N, isVisited);
			cout << "}\n";
		}
	}
	fill(&isVisited[0], &isVisited[10], false);
	for (int i = 0; i < N; i++)
	{
		if (!isVisited[i])
		{
			cout << "{ ";
			BFS(i, N, isVisited);
			cout << "}\n";
		}
	}
	return 0;
}