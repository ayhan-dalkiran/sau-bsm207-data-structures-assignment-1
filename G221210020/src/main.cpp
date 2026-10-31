/**
* @file main.cpp
* @description Programın başlangıç noktasını ve kullanıcı konsol arayüz kodunu içeren dosya
* @course 2. Öğretim B Grubu
* @assignment 1. Ödev
* @date 17/11/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include <fstream>
#include <iostream>
#include <sstream>

#include "chromosome.hpp"
#include "chromosome_list.hpp"

ChromosomeList chromosome_list = {};

void readFile() {
	auto file = std::ifstream("./Dna.txt");
	file >> std::skipws;

	auto buffer = std::istringstream();
	buffer >> std::skipws;

	std::string line;
	while (std::getline(file, line)) {
		if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
			continue;
		}

		buffer.clear();
		buffer.str(line);

		auto ch = new Chromosome();
		char gene;
		while (buffer >> gene) {
			ch->add(gene);
		}
		chromosome_list.add(ch);
	}
}

void resetStream(std::istream &s) {
	s.clear();
	s.ignore(LLONG_MAX, '\n');
}

int main() {
	//This line just doesn't work for some reason???
	//setlocale(LC_ALL, "turkish");
	readFile();

	while (true) {
		std::cout << "[1] Cross" << std::endl;
		std::cout << "[2] Mutate" << std::endl;
		std::cout << "[3] Automatic Operations" << std::endl;
		std::cout << "[4] Print to Screen" << std::endl;
		std::cout << "[5] Exit" << std::endl;
		std::cout << "[6] Print All Chromosomes" << std::endl;

		while (true) {
			std::cout << "Select Command: ";
			std::string command;
			if (!(std::cin >> command)) {
				std::cout << "input error: failed to read command" << std::endl;
				resetStream(std::cin);
				continue;
			}

			if (command == "1") {
				std::cout << "Left chromosome index: ";
				int ci0;
				if (!(std::cin >> ci0)) {
					std::cout << "input error: failed to read integer" << std::endl;
					resetStream(std::cin);
					continue;
				}

				std::cout << "Right chromosome index: ";
				int ci1;
				if (!(std::cin >> ci1)) {
					std::cout << "input error: failed to read integer" << std::endl;
					resetStream(std::cin);
					continue;
				}

				try {
					chromosome_list.cross(ci0, ci1);
				}
				catch (std::string msg) {
					std::cout << "cross operation error: " << msg << std::endl;
					continue;
				}
			}
			else if (command == "2") {
				std::cout << "Chromosome index: ";
				int ci;
				if (!(std::cin >> ci)) {
					std::cout << "input error: failed to read integer" << std::endl;
					resetStream(std::cin);
					continue;
				}

				std::cout << "Gene index: ";
				int gi;
				if (!(std::cin >> gi)) {
					std::cout << "input error: failed to read integer" << std::endl;
					resetStream(std::cin);
					continue;
				}

				try {
					chromosome_list.mutate(ci, gi);
				}
				catch (std::string msg) {
					std::cout << "mutate operation error: " << msg << std::endl;
					continue;
				}
			}
			else if (command == "3") {
				auto file = std::ifstream("./Islemler.txt");
				file >> std::skipws;

				auto buffer = std::istringstream();
				buffer >> std::skipws;

				std::string line;
				while (std::getline(file, line)) {
					if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
						continue;
					}
					//Comment this line out if Islemler.txt file is too large
					//Otherwise cmd/ps will take forever to go through it
					std::cout << line << std::endl;

					buffer.clear();
					buffer.str(line);

					std::string command;
					if (!(buffer >> command)) {
						std::cout << "automatic operations error: failed to read command" << std::endl;
						break;
					}

					if (command == "C") {
						int ci0;
						if (!(buffer >> ci0)) {
							std::cout << "automatic operations error: failed to read integer" << std::endl;
							break;
						}

						int ci1;
						if (!(buffer >> ci1)) {
							std::cout << "automatic operations error: failed to read integer" << std::endl;
							break;
						}

						try {
							chromosome_list.cross(ci0, ci1);
						}
						catch (std::string msg) {
							std::cout << "automatic operations error: cross operation error: " << msg << std::endl;
							break;
						}
					}
					else if (command == "M") {
						int ci;
						if (!(buffer >> ci)) {
							std::cout << "automatic operations error: failed to read integer" << std::endl;
							break;
						}

						int gi;
						if (!(buffer >> gi)) {
							std::cout << "automatic operations error: failed to read integer" << std::endl;
							break;
						}

						try {
							chromosome_list.mutate(ci, gi);
						}
						catch (std::string msg) {
							std::cout << "automatic operations error: mutate operation error: " << msg << std::endl;
							break;
						}
					}
					else {
						std::cout << "automatic operations error: invalid command" << std::endl;
						break;
					}
				}
			}
			else if (command == "4") {
				chromosome_list.printSmallerGenes();
			}
			else if (command == "5") {
				return 0;
			}
			else if (command == "6") {
				std::cout << chromosome_list << std::endl;
				std::cout << "Chromosone count: " << chromosome_list.length() << std::endl;
			}
			else {
				std::cout << "input error: invalid command" << std::endl;
			}
		}
	}

	return 0;
}