#include "Objeto.h"

Objeto::Objeto()
{
}

Objeto::~Objeto()
{
	exit(0);
}

void Objeto::inicializar(TipoObjeto t)
{
	timer2 = 0;
	velocidadePass = 0.0;
	tipo = t;
	if (!gRecursos.carregouSpriteSheet("bolsoMinion"))
		gRecursos.carregarSpriteSheet("bolsoMinion", "./assets/sprites/objetos/BolsoMinion.png", 1, 4);
	
	if (!gRecursos.carregouSpriteSheet("gripezinha"))
		gRecursos.carregarSpriteSheet("gripezinha", "./assets/sprites/objetos/umaGripezinha.png");
		sprite.setSpriteSheet("gripezinha");
		

	if (!gRecursos.carregouSpriteSheet("lixos1"))
		gRecursos.carregarSpriteSheet("lixos1", "./assets/sprites/objetos/lixos1.png");
		sprite.setSpriteSheet("lixos1");
		

	if (!gRecursos.carregouSpriteSheet("lataDeLixo"))
		gRecursos.carregarSpriteSheet("lataDeLixo", "./assets/sprites/objetos/lataDeLixo.png");
		sprite.setSpriteSheet("lataDeLixo");
		sprite.setEscala(0.5, 0.5);

	if (!gRecursos.carregouAudio("somlixos1"))
		gRecursos.carregarAudio("somlixos1", "assets/sons/confirmation.mp3");	

	if (!gRecursos.carregouAudio("somPowerUp"))
		gRecursos.carregarAudio("somPowerUp", "assets/sons/powerup.mp3");
			

	int sorteio;

	switch (tipo)
	{
		case tGripezinha: 	
					sprite.setSpriteSheet("gripezinha");					
					sprite.setEscala(0.3, 0.3);
					x = gJanela.getLargura() + sprite.getLargura() + rand() % 1000 + 2500;
					y = rand() % 300 + 800;
					velocidade = 2;
					break;
		case tBolsoMinion: 
					sprite.setSpriteSheet("bolsoMinion");
					sprite.setVelocidadeAnimacao(2);
					sprite.setEscala(4, 4);
					x = gJanela.getLargura() + sprite.getLargura() + rand() % 1000 + 1500;
					y = rand() % 100 + 800;
					velocidade = 2;
					break;
		case tLixos1:					
					sprite.setSpriteSheet("lixos1");			
					sprite.setEscala(0.3, 0.3);
					x = gJanela.getLargura() + sprite.getLargura() + rand() % 1000 + 500;
					y = rand() % 250 + 800;
					velocidade = 2;
					break;
		case tLataDeLixo:					
					sprite.setSpriteSheet("lataDeLixo");	
					sprite.setEscala(0.3, 0.3);
					sprite.setVelocidadeAnimacao(1);
					x = gJanela.getLargura() + sprite.getLargura() + rand() % 3000 + 200;
					y = rand() % 120 + 800;
					velocidade = 2;
					break;
	}
}

void Objeto::atualizar(float vCenario)
{		
	timer++;
	timer2++;
	x -= velocidade + vCenario;

	if (x < -sprite.getLargura())
	{
		int sorteio;

		switch (tipo)
		{
		case tGripezinha:					
			sprite.setSpriteSheet("gripezinha");
			sorteio = rand() % 3;
			if (sorteio == 0) {
				y = rand() % 10 + 820;
			}
			else if (sorteio == 1) {
				y = rand() % 100 + 750;
			}
			else {
				y = rand() % 60 + 890;
			}
			sprite.setVelocidadeAnimacao(2);
			x = gJanela.getLargura() + sprite.getLargura() + rand() % 1000 + 1000;
			velocidade = vCenario / 2;
			break;
		case tBolsoMinion:			
			sprite.setSpriteSheet("bolsoMinion");
			sorteio = rand() % 3;
			if (sorteio == 0) {
				y = rand() % 100 + 850;
			}
			else if (sorteio == 1) {
				y = rand() % 140 + 830;
			}
			else {
				y = rand() % 80 + 860;
			}
			x = gJanela.getLargura() + sprite.getLargura() + rand() % 1000 + 500;
			velocidade = vCenario / 2;
			timer = 0;
			break;			
		case tLixos1:
			sprite.setSpriteSheet("lixos1");
			sorteio = rand() % 3;
			if (sorteio == 0) {
				y = rand() % 50 + 900;
			}
			else if (sorteio == 1) {
				y = rand() % 100 + 870;
			}
			else {
				y = rand() % 100 + 800;
			}
			x = gJanela.getLargura() + sprite.getLargura() + rand() % 1000 + 800;
			velocidade = vCenario / 2;
			break;
		case tLataDeLixo:
			sprite.setSpriteSheet("lataDeLixo");
			sprite.setVelocidadeAnimacao(1.5);			
			x = gJanela.getLargura() + sprite.getLargura() + 3000;
			y = rand() % 100 + 850;
			velocidade = vCenario / 2;
			break;	
		}	
	}
	sprite.setVelocidadeAnimacao(3);
	sprite.avancarAnimacao();	
}

void Objeto::desenhar()
{
	sprite.desenhar(x, y);	
}

void Objeto::setposicaox(int posicao)
{
	x = posicao;
}

void Objeto::tocarsom(TipoObjeto t)
{
	
	switch (t)
	{
	case tLixos1:
		som.setAudio("somlixos1");		
		som.tocar();
		break;
	case tLataDeLixo:
		som.setAudio("somPowerUp");
		som.tocar();		
		break;
	default:
		break;
	}	
}

void Objeto::zeraVelocidade()
{
	velocidadePass = 0.0;
}

