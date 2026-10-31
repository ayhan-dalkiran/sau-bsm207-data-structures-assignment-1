/**
* @file chromosome_list.hpp
* @description Kromozomların saklandığı ChromosomeList sınıfının tanımı
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once

#include <ostream>

#include "chromosome.hpp"
#include "list_node.hpp"

//Circular Doubly Linked List
class ChromosomeList {
protected:
    ListNode *head = nullptr;
	int count = 0;

public:
    ListNode *first() const;
    ListNode *last() const;
	int length() const;
	bool empty() const;

	ListNode *at(int i) const;

    void add(Chromosome *ch);
	void cross(int ci0, int ci1);
	void mutate(int ci, int gi);
	void printSmallerGenes();

    ChromosomeList();
	~ChromosomeList();

    friend std::ostream &operator<<(std::ostream &os, const ChromosomeList &cl);
};