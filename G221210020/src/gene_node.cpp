/**
* @file gene_node.cpp
* @description Chromosome sınıfı için genlerin saklandığı ve birbirlerine bağlandığı GeneNode sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include "gene_node.hpp"

GeneNode::GeneNode(char value, GeneNode *previous, GeneNode *next)
	: value(value), previous(previous), next(next) {}

GeneNode::~GeneNode() {}
