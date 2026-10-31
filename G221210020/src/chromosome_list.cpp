/**
* @file chromosome_list.cpp
* @description Kromozomların saklandığı ChromosomeList sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include <iostream>

#include "chromosome_list.hpp"

ListNode *ChromosomeList::first() const {
	return this->head;
}

ListNode *ChromosomeList::last() const {
	return !this->empty() ? this->head->previous : nullptr;
}

int ChromosomeList::length() const {
	return this->count;
}

bool ChromosomeList::empty() const {
	return this->length() == 0;
}

ListNode *ChromosomeList::at(int i) const {
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

void ChromosomeList::add(Chromosome *ch) {
	if (this->empty()) {
		auto node = new ListNode(ch, nullptr, nullptr);
		node->previous = node;
		node->next = node;
		this->head = node;
	}
	else {
		auto node = new ListNode(ch, this->last(), this->first());
		this->last()->next = node;
		this->first()->previous = node;
	}

	count += 1;
	return;
}

void ChromosomeList::cross(int ci0, int ci1) {
	Chromosome *ch0;
	try {
		ch0 = this->at(ci0)->value;
	}
	catch (std::string msg) {
		throw std::string("left chromosome indexing error: ") + msg;
	}

	if (ch0->length() <= 1) {
		throw std::string("left chromosome is too small (expected at least 2 genes, got ") + std::to_string(ch0->length()) + ')';
	}

	Chromosome *ch1;
	try {
		ch1 = this->at(ci1)->value;
	}
	catch (std::string msg) {
		throw std::string("right chromosome indexing error: ") + msg;
	}

	if (ch1->length() <= 1) {
		throw std::string("right chromosome is too small (expected at least 2 genes, got ") + std::to_string(ch1->length()) + ')';
	}

	auto outer = new Chromosome();
	auto inner = new Chromosome();

	int s0 = ch0->length() / 2;
	auto f00 = ch0->first();
	auto l00 = ch0->at(s0 - 1);
	auto f01 = ch0->at(ch0->length() - s0);
	auto l01 = ch0->last();

	int s1 = ch1->length() / 2;
	auto f10 = ch1->first();
	auto l10 = ch1->at(s1 - 1);
	auto f11 = ch1->at(ch1->length() - s1);
	auto l11 = ch1->last();

	GeneNode *it;
	//Outer
	it = f00;
	do {
		outer->add(it->value);
		it = it->next;
	}
	while (it != l00);
	outer->add(l00->value);

	it = f11;
	do {
		outer->add(it->value);
		it = it->next;
	}
	while (it != l11);
	outer->add(l11->value);

	//Inner
	it = f01;
	do {
		inner->add(it->value);
		it = it->next;
	}
	while (it != l01);
	inner->add(l01->value);

	it = f10;
	do {
		inner->add(it->value);
		it = it->next;
	}
	while (it != l10);
	inner->add(l10->value);

	this->add(outer);
	this->add(inner);
}

void ChromosomeList::mutate(int ci, int gi) {
	Chromosome *ch;
	try {
		ch = this->at(ci)->value;
	}
	catch (std::string msg) {
		throw std::string("chromosome indexing error: ") + msg;
	}

	try {
		ch->at(gi)->value = 'X';
	}
	catch (std::string msg) {
		throw std::string("gene indexing error: ") + msg;
	}
}

void ChromosomeList::printSmallerGenes() {
	if (this->empty()) {
		return;
	}

	auto itch = this->first();
	do {
		auto ch = itch->value;
		if (ch->empty()) {
			std::cout << '_' << ' ';
			continue;
		}

		char pivot = ch->first()->value;

		for (auto itg = ch->last(); itg != ch->first(); itg = itg->previous) {
			if (itg->value < pivot) {
				pivot = itg->value;
				break;
			}
		}

		std::cout << pivot << ' ';
		itch = itch->next;
	}
	while (itch != this->first());

	std::cout << std::endl;
}

ChromosomeList::ChromosomeList() {}
ChromosomeList::~ChromosomeList() {
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

std::ostream &operator<<(std::ostream &os, const ChromosomeList &cl) {
	if (cl.empty()) {
		return os;
	}

	auto it = cl.first();
	do {
		os << *it->value << std::endl;
		it = it->next;
	}
	while (it != cl.first());

	return os;
}