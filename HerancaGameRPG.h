#include <iostream>
#include <string>

class Personagem {

public:
	double Vida = 100;
	double Mana = 100;
	double Agilidade = 20;
	double forca = 10;
	int Nivel = 0;
	double XP = 0; 
	std::string Nome;

	Personagem(std::string N) {
		this->Nome = N;
	}
	

	virtual void atacar(double dmg, Personagem& ref) {
		std::cout << "Ataque basico" << std::endl;
		ref.ReceberDano(dmg);
	};

	bool IsLive() {
		if (this->Vida <= 0) {
			std::cout <<"Vida: " << this->Vida << std::endl;
			return false;
		} 
		return true;
	};
	void ReceberDano(double dmg) {
		if (IsLive()) {
			Vida -= dmg;
			std::cout << Nome << " Recebeu Dano: " << dmg << std::endl;
			std::cout << Nome << " Vida: " << Vida << std::endl;
		}
	}
	virtual ~Personagem() {};

};

class Heroi : public Personagem {
	
public:
	Heroi(std::string N) : Personagem(N) {};
};

class Inimigo : public Personagem {

public:
	int agressividade = 0;

	Inimigo(std::string N) : Personagem(N) {};
};

class Cavaleiro : public Heroi {
public:
	double PoderDivino = 0;
	Cavaleiro(std::string N) : Heroi(N) {};
	
	
	void atacar(double dmg, Personagem& ref)override {
		std::cout << this->Nome << " atacou " << ref.Nome << std::endl;
		std::cout << "Dano Ataque: " << dmg << std::endl;
		ref.ReceberDano(dmg);
	}
};

class Goblin : public Inimigo {
public:

	Goblin(std::string N) : Inimigo(N) {};

	virtual void atacar(double dmg, Personagem& ref) override {
		std::cout << "Goblin atacou!!" << std::endl;
		ref.ReceberDano(dmg);
	}


	
};
