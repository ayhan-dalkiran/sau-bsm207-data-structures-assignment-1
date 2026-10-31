/**
* @file list_node.hpp
* @description ChromosomeList sınıfı için kromozomların saklandığı ve birbirlerine bağlandığı ListNode sınıfının tanımı
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once

#include <ostream>

#include "chromosome.hpp"

//Circular Doubly Linked List Node
class ListNode {
public:
    Chromosome *value;

	ListNode *previous = nullptr;
    ListNode *next = nullptr;

    ListNode(Chromosome *value, ListNode *previous, ListNode *next);
	~ListNode();
};