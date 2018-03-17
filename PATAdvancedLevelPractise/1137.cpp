#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
// AC
int P, M, N;
struct StudentNode
{
	string id;
	int gp, gmid = -1, gfinal = -1, g = -1;
}stuList[30001];

bool cmp(StudentNode a, StudentNode b)
{
	if(a.g != b.g)
		return a.g > b.g;
	else
	
		return a.id < b.id;
}

int main(int argc, char const *argv[])
{
	int count = 0;
	map<string, int>m;
	scanf("%d %d %d", &P, &M, &N);
	int i, score;
	string name;
	for(i = 0; i < P; i++)
	{
		cin >> name >> score;
		if(score >= 200)
		{
			stuList[count].id = name;
			stuList[count].gp = score;
			stuList[count].gmid = stuList[count].gfinal = -1;
			m[name] = count;
			count++;
		}
	}
	for(i = 0; i < M; i++)
	{
		cin >> name >> score;
		if(m.find(name) != m.end())
			stuList[m[name]].gmid = score;
	}

	for(i = 0; i < N; i++)
	{
		cin >> name >> score;
		if(m.find(name) != m.end())
			stuList[m[name]].gfinal = score;
	}

	for(i = 0; i < count; i++)
	{
		if(stuList[i].gmid <= stuList[i].gfinal)
			stuList[i].g = stuList[i].gfinal;
		else
			stuList[i].g = (int)((double)stuList[i].gmid * 0.4 + (double)stuList[i].gfinal * 0.6 + 0.5);
	}
	sort(stuList, stuList + count, cmp);
	for(i = 0; i < count; i++)
		if(stuList[i].g >= 60)
			printf("%s %d %d %d %d\n", stuList[i].id.c_str(), stuList[i].gp, stuList[i].gmid, stuList[i].gfinal, stuList[i].g);
	return 0;
}
