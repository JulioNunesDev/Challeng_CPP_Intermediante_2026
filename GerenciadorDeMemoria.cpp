#include <iostream>
#include "Gerenciadordememoria.h"
#include "HerancaGameClasses.h"
#include <memory>



int main() {

	std::unique_ptr<Personagem> CavaleiroPlayer = std::make_unique<Cavaleiro>("Julio Cavaleiro");
	std::unique_ptr<Personagem> GoblinInimigo = std::make_unique<Goblin>("Goblin");

	
		GerenciadorDeEntidades  GerenciadorPersonagens;



		GerenciadorPersonagens.AdicionarPlayer(std::move(CavaleiroPlayer));
		GerenciadorPersonagens.AdicionarPlayer(std::move(GoblinInimigo));
		GerenciadorPersonagens.ListarPersonagens();
		GerenciadorPersonagens.ExecutarCombate("Julio Cavaleiro", "Goblin");
		GerenciadorPersonagens.ListarPersonagens();
		GerenciadorPersonagens.RemoverPlayer("Goblin");
		GerenciadorPersonagens.ListarPersonagens();



		

	return 0;
}


