/**
* @file chromosome.cpp
* @description Genlerin saklandığı Chromosome sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include "chromosome.hpp"

GeneNode *Chromosome::first() const {
	return this->head;
}

GeneNode *Chromosome::last() const {
	return !this->empty() ? this->head->previous : nullptr;
}

int Chromosome::length() const {
	return this->count;
}

bool Chromosome::empty() const {
	return this->length() == 0;
}

GeneNode *Chromosome::at(int i) const {
	if (this->empty()) {
		throw std::string("list is empty");
	}

	if (i < 0 || i >= this->length()) {
		throw std::string("value must be within range [0, ") + std::to_string(this->length() - 1) + "]";
	}

	auto it = this->first();
	int pos = 0;
	do {
		if (pos == i) {
			return it;
		}

		pos++;
		it = it->next;
	}
	while(it != this->first());

	throw std::string("unexpected error");
}

void Chromosome::add(char gene) {
	if (this->empty()) {
		auto node = new GeneNode(gene, nullptr, nullptr);
		node->previous = node;
		node->next = node;
		this->head = node;
	}
	else {
		auto node = new GeneNode(gene, this->last(), this->first());
		this->last()->next = node;
		this->first()->previous = node;
	}

	count += 1;
	return;
}

Chromosome::Chromosome() {}

Chromosome::~Chromosome() {
	if (this->empty()) {
		return;
	}

	auto it = this->first();
	do {
		delete it;
	}
	while (it != this->first());

	this->count = 0;
	this->head = nullptr;
}

std::ostream &operator<<(std::ostream &os, const Chromosome &ch) {
	if (ch.empty()) {
		os << '_';
		return os;
	}

	auto it = ch.first();
	do {
		os << it->value << ' ';
		it = it->next;
	}
	while (it != ch.first());

	return os;
}
