#include "ProduceItem.h"

ProduceItem::ProduceItem(string t_item) {
	m_name = t_item;
	m_count = 1;
}

void ProduceItem::AddOneToCount() {
	m_count++;
}

string ProduceItem::GetName() {
	return m_name;
}

int ProduceItem::GetCount() {
	return m_count;
}