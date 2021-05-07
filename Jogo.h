#pragma once
#include "Personagem.h"
#include "Objeto.h"


enum Telas {tMenu, tJogo, tConfig, tCreditos, tInstrucoes, 
	        tGameOver, tSair};

enum Botoes {bJogar, bInstrucoes, bCreditos, bSair, 
	         bOk, bContinuar, b1Jogador, b2Jogadores};

class Jogo
{
public:
	Jogo();
	~Jogo();
	void inicializar();
	void finalizar();
	void executar();

	

protected:
	Telas telaAtual;
	BotaoSprite botoes[8];

	Sprite fundo,fundo2, chao, fundoPausa,fundoMenu, fundoCreditos, fundoInstrucoes, fundoCreditos2, fundoInstrucoes2, fundoGameOver, dialog;
	
	Vetor2D pfundo1, pfundo2;
	Personagem personagem;	
	float velocidadeCenario;
	Objeto gripezinha[4], lixos1[8], bolsoMinions[2],lataDeLixo;
	
	Texto tPontuacao,tVida,dialogText, resetText;		
	string tmp;
	int timer,timer2,posText;
	bool pausa;
	void telaMenu();
	void telaJogo();
	void telaCreditos();
	void telaInstrucoes();
	void telaConfig();
	void telaGameOver();
	void reiniciarGame();	
};

