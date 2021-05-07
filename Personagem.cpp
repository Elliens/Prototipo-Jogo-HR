#include "Personagem.h"


Personagem::Personagem()
{	
}

Personagem::~Personagem()
{
}

void Personagem::inicializar(int x, int y)
{
	if (!gRecursos.carregouSpriteSheet("personagem")) 
	{
		gRecursos.carregarSpriteSheet("personagem", "./assets/sprites/player/Girl_walk.png", 1, 6);
		sprite.setSpriteSheet("personagem");		
	}

	this->x = x;
	this->y = y;
	direcao = baixo;
	velocidade = 3;
	pontuacao = 0;
	vida = 100;
	imortal = false;
	sprite.setCorAlpha(250);
	sprite.setEscala(5, 5);
}

void Personagem::atualizar()
{
	
	direcao = parado;
	
	
	if (gTeclado.segurando[TECLA_D] || gJoysticks.player1.segurando[TECLA_DIR])
	{
		if (x < 1250)
		{			
			x += velocidade;
		}
	}
	if (gTeclado.segurando[TECLA_A] || gJoysticks.player1.segurando[TECLA_ESQ])
	{
		if (x >= 30)
		{			
			x -= velocidade;
		}
	}

	if (gTeclado.segurando[TECLA_W] || gJoysticks.player1.segurando[TECLA_CIMA])
	{
		if (y > 700)
		{
			y -= 4;
		}		
	}	
	
	if (gTeclado.segurando[TECLA_S] || gJoysticks.player1.segurando[TECLA_BAIXO])
	{
		if (y < 950)
		{
			y += 4;
		}
	}
		
	sprite.setVelocidadeAnimacao(8);		
	sprite.avancarAnimacao();		

	if (imortal) 
	{
		timer++;
	}
	else
	{
		timer = 0;
	}
				
	if (timer > 600)
	{
		sprite.setCorAlpha(250);
		imortal = false;
	}		
}

void Personagem::desenhar()
{	
	sprite.desenhar(x, y);	
}

void Personagem::pegar(int valor,TipoObjeto item)
{
	if  (item == tLixos1)
	{
		pontuacao += valor;
	}
	else if (item == tLataDeLixo)
	{
		sprite.setCorAlpha(100);
		imortal = true;
	}
	
}

void Personagem::levarDano(int valor)
{
	if (imortal == false) 
	{
		vida -= valor;
	}
	
}

void Personagem::setposicaox(int x)
{
	this->x += x;
	
}

void Personagem::setPontuacao()
{
	pontuacao+= 0.16;
}





