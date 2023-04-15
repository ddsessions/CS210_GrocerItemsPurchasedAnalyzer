#include "ProduceItem.h"

ProduceItem::ProduceItem(string t_item) {
	m_Name = t_item;
	m_Count = 1;
}

void ProduceItem::AddOneToCount() {
	m_Count++;
}

string ProduceItem::GetName() {
	return m_Name;
}

int ProduceItem::GetCount() {
	return m_Count;
}