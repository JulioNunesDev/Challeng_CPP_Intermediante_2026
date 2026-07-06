#include <iostream>
#include "./HerancaGameClasses.h"


int main() {

	Personagem* CavaleiroPlayer = new Cavaleiro("Julio Cavaleiro");
	Personagem* GoblinInimigo =   new Goblin("Goblin");

	CavaleiroPlayer->atacar(20, *GoblinInimigo);
	if (GoblinInimigo->IsLive()) {
	GoblinInimigo->atacar(30, *CavaleiroPlayer);

	}

	delete CavaleiroPlayer;
	delete GoblinInimigo;

	return 0;
}
