#pragma once
#include <string>

using namespace std;

class ProduceItem
{
private:
	string m_name;
	int m_count;
public:
	//Constructor
	ProduceItem(string t_item);
	//Add one to m_count
	void AddOneToCount();
	//Get m_name
	string GetName();
	//Get m_count
	int GetCount();
};