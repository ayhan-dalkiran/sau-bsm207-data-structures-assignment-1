/**
* @file gene_node.hpp
* @description Chromosome sınıfı için genlerin saklandığı ve birbirlerine bağlandığı GeneNode sınıfının tanımı
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once

#include <ostream>

//Circular Doubly Linked List Node
class GeneNode {
public:
    char value;

	GeneNode *previous = nullptr;
    GeneNode *next = nullptr;

    GeneNode(char gene, GeneNode *previous, GeneNode *next);
	~GeneNode();
};