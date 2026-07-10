#pragma once
#include <iostream>
#include <memory>
#include "HerancaGameClasses.h"
#include <vector>



class GerenciadorDeEntidades {

public:
	std::vector < std::unique_ptr<Personagem>> Personagens;


	void AdicionarPlayer(std::unique_ptr<Personagem > Player) {
		std::string Nome = Player->Nome;
		Personagens.push_back(std::move(Player));

		std::cout << Nome << " adicionado." << std::endl;
	};

	void RemoverPlayer(std::string idPlayerRef) {

		if (this->Personagens.empty()) {
			std::cout << "Lista de Personagens Vazia!" << std::endl;
			return;
		}
		

		std::erase_if(Personagens, [idPlayerRef](const std::unique_ptr<Personagem>& a) {
			return a->Nome == idPlayerRef;
			});
		
		std::cout  << idPlayerRef << " Removido com sucesso!" << std::endl;
	}

	void ListarPersonagens() {
		if (this->Personagens.empty()) {
			std::cout << "Lista vazia de Personagens" << std::endl;
			return;
		}

		for (const auto &p  : this->Personagens) {
			std::cout << "Nome: " << p->Nome << " | Vida: " << p->Vida << std::endl;
		}
	}


	void ExecutarCombate(std::string NomeAtacante, std::string NomeAlvo) {
		if (NomeAtacante == NomeAlvo) {
			std::cout << "Voce esta atacando voce mesmo." << std::endl;
			return;
		}

		auto itAtacante = std::find_if(this->Personagens.begin(), this->Personagens.end(), [NomeAtacante](const std::unique_ptr<Personagem>& a) {
			return a->Nome == NomeAtacante;
			});

		auto itAlvo = std::find_if(this->Personagens.begin(), this->Personagens.end(), [NomeAlvo](const std::unique_ptr<Personagem>& a) {
			return a->Nome == NomeAlvo;
			});

		if (itAtacante == this->Personagens.end()) {
			std::cout << NomeAtacante << " Personagem nao encontrado!" << std::endl;
			return;
		}
		else if (itAlvo == this->Personagens.end()) {
			std::cout << NomeAlvo << " Personagem nao encontrado!" << std::endl;
			return;
		}
		
		(*itAtacante)->atacar(50, **itAlvo);
			
		
	}
};
