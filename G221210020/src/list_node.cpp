/**
* @file list_node.cpp
* @description ChromosomeList sınıfı için kromozomların saklandığı ve birbirlerine bağlandığı ListNode sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include "list_node.hpp"

ListNode::ListNode(Chromosome *value, ListNode *previous, ListNode *next)
	: value(value), previous(previous), next(next) {}

ListNode::~ListNode() {
	delete this->value;
}
