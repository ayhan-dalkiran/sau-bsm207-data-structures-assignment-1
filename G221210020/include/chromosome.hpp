/**
* @file chromosome.hpp
* @description Genlerin saklandığı Chromosome sınıfının tanımı
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once

#include <ostream>

#include "gene_node.hpp"

//Circular Doubly Linked List
class Chromosome {
protected:
    GeneNode *head = nullptr;
	int count = 0;

public:
    GeneNode *first() const;
    GeneNode *last() const;
	int length() const;
	bool empty() const;

	GeneNode *at(int i) const;

    void add(char gene);

	Chromosome();
	~Chromosome();

    friend std::ostream &operator<<(std::ostream &os, const Chromosome &ch);
};