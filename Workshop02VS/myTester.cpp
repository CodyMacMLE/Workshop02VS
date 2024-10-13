#include <iostream>
#include <iomanip>
#include "weapons.h"
#include "weapons.h"        // intentional
#include "abilities.h"
#include "abilities.h"      // intentional
#include "health.h"
#include "health.h"         // health
#include "character.h"
#include "character.h"      // intentional
#include "team.h"
#include "team.h"           // intentional
#include "guild.h"
#include "guild.h"          // intentional
#include "barbarian.h"
#include "barbarian.h"      // intentional
#include "rogue.h"
#include "rogue.h"          // intentional
#include "archer.h"
#include "archer.h"         // intentional

int main(int argc, char** argv) {

	std::cout << "Command Line:\n";
	std::cout << "------------------------------------------------------\n";
	for (int i = 0; i < argc; ++i)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "------------------------------------------------------\n\n";

	seneca::Rogue<seneca::SuperHealth, seneca::Heal, seneca::Fireball> ch_1("Quick Silver", 950, 33, 77);

	return 0;
}