#pragma once
#include <string>

using namespace std;

class ProduceItem
{
private:
	string m_Name;
	int m_Count;
public:
	ProduceItem(string t_item);
	void AddOneToCount();
	string GetName();
	int GetCount();
};