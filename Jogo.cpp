#include "Jogo.h"

Jogo::Jogo()
{

}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1920, 1080, true);

	//Interface
	//-------------------------------------------

	if (!gRecursos.carregouSpriteSheet("fundoMenu"))
		gRecursos.carregarSpriteSheet("fundoMenu", "assets/sprites/telas/tela_menu.jpg");
	fundoMenu.setSpriteSheet("fundoMenu");

	if (!gRecursos.carregouSpriteSheet("bJogar"))
		gRecursos.carregarSpriteSheet("bJogar",	"assets/sprites/botoes/bNewGame.jpg", 1);	
	botoes[bJogar].setSpriteSheet("bJogar");
	botoes[bJogar].getSprite()->setEscala(1.8, 1.8);
	botoes[bJogar].setPos(gJanela.getLargura() / 2 - 30, 530);	

	if (!gRecursos.carregouSpriteSheet("bInstrucoes"))
		gRecursos.carregarSpriteSheet("bInstrucoes", "assets/sprites/botoes/bTutorial.jpg", 1);

	botoes[bInstrucoes].setSpriteSheet("bInstrucoes");
	botoes[bInstrucoes].getSprite()->setEscala(1.8, 1.8);
	botoes[bInstrucoes].setPos(gJanela.getLargura() / 2 - 30, 630);

	if (!gRecursos.carregouSpriteSheet("bCreditos"))
		gRecursos.carregarSpriteSheet("bCreditos", "assets/sprites/botoes/bCredits.jpg", 1);

	botoes[bCreditos].setSpriteSheet("bCreditos");
	botoes[bCreditos].getSprite()->setEscala(1.8, 1.8);
	botoes[bCreditos].setPos(gJanela.getLargura() / 2 - 30, 730);

	if (!gRecursos.carregouSpriteSheet("bSair"))
		gRecursos.carregarSpriteSheet("bSair", "assets/sprites/botoes/bExit.jpg", 1);

	botoes[bSair].setSpriteSheet("bSair");
	botoes[bSair].getSprite()->setEscala(1.8, 1.8);
	botoes[bSair].setPos(gJanela.getLargura() / 2 - 30, 830);

	if (!gRecursos.carregouSpriteSheet("bOk"))
		gRecursos.carregarSpriteSheet("bOk", "assets/sprites/botoes/bBack.jpg", 1);

	botoes[bOk].setSpriteSheet("bOk");
	botoes[bOk].getSprite()->setEscala(1.8, 1.8);
	botoes[bOk].setPos(gJanela.getLargura() / 2 + 40, 800);

	if (!gRecursos.carregouSpriteSheet("bContinuar"))
		gRecursos.carregarSpriteSheet("bContinuar", "assets/sprites/botoes/bContinuar.png", 3);

	botoes[bContinuar].setSpriteSheet("bContinuar");
	botoes[bContinuar].setPos(gJanela.getLargura() / 2 - 200, 300);

	if (!gRecursos.carregouSpriteSheet("b1Jogador"))
		gRecursos.carregarSpriteSheet("b1Jogador", "assets/sprites/botoes/b1Jogador.png", 3);

	botoes[b1Jogador].setSpriteSheet("b1Jogador");
	botoes[b1Jogador].setPos(gJanela.getLargura() / 2 - 150, 300);

	if (!gRecursos.carregouSpriteSheet("b2Jogadores"))
		gRecursos.carregarSpriteSheet("b2Jogadores", "assets/sprites/botoes/b2Jogadores.png", 3);

	botoes[b2Jogadores].setSpriteSheet("b2Jogadores");
	botoes[b2Jogadores].setPos(gJanela.getLargura() / 2 + 150, 300);

	telaAtual = tMenu;
	
	if (!gRecursos.carregouMusica("musicaMenu"))
		gRecursos.carregarMusica("musicaMenu", "assets/sons/MenuMusic.mp3");	

	//Game
	//-------------------------------------------		

	if (!gRecursos.carregouMusica("musicaJogo"))
		gRecursos.carregarMusica("musicaJogo", "assets/sons/musicaFundo.mp3");

	if (!gRecursos.carregouSpriteSheet("fundo"))
		gRecursos.carregarSpriteSheet("fundo", "assets/sprites/telas/jogo.png");
	fundo.setSpriteSheet("fundo");

	if (!gRecursos.carregouSpriteSheet("fundo2"))
		gRecursos.carregarSpriteSheet("fundo2", "assets/sprites/telas/jogo.png");
	fundo2.setSpriteSheet("fundo2");


	if (!gRecursos.carregouSpriteSheet("fundoCreditos"))
		gRecursos.carregarSpriteSheet("fundoCreditos", "assets/sprites/telas/CreditsMenu.png");
		fundoCreditos.setSpriteSheet("fundoCreditos");


	if (!gRecursos.carregouSpriteSheet("fundoinstrucoes"))
		gRecursos.carregarSpriteSheet("fundoinstrucoes", "assets/sprites/telas/tutorial.jpg");
		fundoInstrucoes.setSpriteSheet("fundoinstrucoes");

	if (!gRecursos.carregouSpriteSheet("fundoPausa"))
		gRecursos.carregarSpriteSheet("fundoPausa", "assets/sprites/telas/pause.png");
	fundoPausa.setSpriteSheet("fundoPausa");

	if (!gRecursos.carregouSpriteSheet("fundoGameOver"))
		gRecursos.carregarSpriteSheet("fundoGameOver", "assets/sprites/telas/gameOver.png");
	fundoGameOver.setSpriteSheet("fundoGameOver");

	if (!gRecursos.carregouSpriteSheet("dialog"))
		gRecursos.carregarSpriteSheet("dialog","assets/sprites/telas/pixel-speech-bubble.png");
	dialog.setSpriteSheet("dialog");
	//
	pfundo1.x = 0;
	pfundo1.y = gJanela.getAltura() / 2;

	pfundo2.x = gJanela.getLargura();
	pfundo2.y = gJanela.getAltura() / 2;	
	
	
	lataDeLixo.inicializar(tLataDeLixo);

	for (int n = 0; n < 4; n++)
	{
		gripezinha[n].inicializar(tGripezinha);
	}

	for (int c = 0; c < 8; c++)
	{
		lixos1[c].inicializar(tLixos1);
	}

	for (int c = 0; c < 2; c++)
	{
		bolsoMinions[c].inicializar(tBolsoMinion);
	}

	if (!gRecursos.carregouFonte("minhaFonte"))
		gRecursos.carregarFonte("minhaFonte", "assets/fontes/pixelart.ttf", 22);

	tPontuacao.setFonte("minhaFonte");
	tPontuacao.setCor(0, 0, 0);
	tPontuacao.setAncora(0, 0.5);
	tPontuacao.setEscala(2.0, 2.0);

	dialogText.setFonte("minhaFonte");
	dialogText.setCor(0, 0, 0);
	dialogText.setAncora(0, 0.5);
	dialogText.setEscala(1.0, 1.0);

	tVida.setFonte("minhaFonte");
	tVida.setEscala(1,1);
	tVida.setCor(0, 0, 0);
	tVida.setAncora(0, 0.5);

	resetText.setFonte("minhaFonte");
	resetText.setCor(255, 255, 100);
	resetText.setAncora(0, 0.5);
	resetText.setEscala(1.0, 1.0);


	personagem.inicializar(200, 900);	


	velocidadeCenario = 2;
	timer = 0;
	timer2 = 0;
	pausa = false;
	posText = 0;
	tmp;		   
}

void Jogo::finalizar()
{
	
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair
		  && telaAtual != tSair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
			case tMenu: telaMenu();
				break;
			case tJogo: telaJogo();				
				break;
			case tConfig: telaConfig();
				break;
			case tCreditos: telaCreditos();
				break;
			case tInstrucoes: telaInstrucoes();
				break;
			case tGameOver: telaGameOver();
				break;
		}				

		uniTerminarFrame();
	}
}

void Jogo::telaMenu()
{
	
	
	if (gMusica.getNomeMusica() == "musicaJogo") {
		gMusica.parar();
	}

	if (!gMusica.estaTocando()) {
		gMusica.tocar("musicaMenu", true);		
	}

	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2); 

	botoes[bJogar].atualizar();
	botoes[bJogar].desenhar();
	

	if (botoes[bJogar].estaClicado())
		telaAtual = tConfig;

	botoes[bInstrucoes].atualizar();
	botoes[bInstrucoes].desenhar();

	if (botoes[bInstrucoes].estaClicado())
		telaAtual = tInstrucoes;

	botoes[bCreditos].atualizar();
	botoes[bCreditos].desenhar();

	if (botoes[bCreditos].estaClicado())
		telaAtual = tCreditos;

	botoes[bSair].atualizar();
	botoes[bSair].desenhar();

	if (botoes[bSair].estaClicado())
		telaAtual = tSair;
	
}

void Jogo::telaJogo()
{	
	timer++;
	timer2++;

	fundo.desenhar(pfundo1.x, pfundo1.y); //fundo 1
	fundo2.desenhar(pfundo2.x, pfundo2.y); //fundo 2	
	
	if (timer2 > 60 && personagem.getVida() > 0)
	{
		for (int b = 0; b < 4; b++) {
			gripezinha[b].desenhar();
		}

		for (int c = 0; c < 8; c++)
			lixos1[c].desenhar();

		for (int p = 0; p < 2; p++)
			bolsoMinions[p].desenhar();	

		lataDeLixo.desenhar();
	}


	personagem.desenhar();


	if (pausa)
		fundoPausa.desenhar(980, 490);

	if (gTeclado.pressionou[TECLA_P])
	{
		pausa = !pausa;
		if (gMusica.estaTocando())
			gMusica.pausar();
		else
			gMusica.continuar();
	}


	if (!pausa)
	{

		personagem.setPontuacao();		

		if (timer > 1000 && velocidadeCenario < 4)
		{
			velocidadeCenario+= 0.5;			
			timer = 0;
		}	

		
		tPontuacao.setString("Score: " +
			to_string(personagem.getPontuacao()));
		tPontuacao.desenhar(20, 30);

		if (gMusica.getNomeMusica() == "musicaMenu") {
			gMusica.parar();
		}

		if (!gMusica.estaTocando()) {
			gMusica.tocar("musicaJogo", true);
		}		

		pfundo1.x -= velocidadeCenario;
		if (pfundo1.x <= -gJanela.getLargura() / 2)
			pfundo1.x = gJanela.getLargura() * 1.5;

		pfundo2.x -= velocidadeCenario;
		if (pfundo2.x <= -gJanela.getLargura() / 2)
			pfundo2.x = gJanela.getLargura() * 1.5;


		if (timer2 > 60 && personagem.getVida() > 0) 
		{
			for (int n = 0; n < 4; n++)
			{
				gripezinha[n].atualizar(velocidadeCenario);
				if (uniTestarColisaoCirculoComCirculo(
					personagem.getX() - 60,
					personagem.getY() + 90,
					30,
					gripezinha[n].getX(),
					gripezinha[n].getY(),
					25))
				{
					personagem.levarDano(100);
				}
			}

			for (int c = 0; c < 8; c++) {
				lixos1[c].atualizar(velocidadeCenario);
				
				if (uniTestarColisaoCirculoComCirculo(
					personagem.getX() - 60,
					personagem.getY() + 90,
					30,
					lixos1[c].getX(),
					lixos1[c].getY(),
					25))
				{
					personagem.pegar(10, tLixos1);
					lixos1[c].setposicaox(-100);
					lixos1[c].tocarsom(tLixos1);
				}						
			}

			for (int p = 0; p < 2; p++) {

				bolsoMinions[p].atualizar(velocidadeCenario);

				if (uniTestarColisaoCirculoComCirculo(
					personagem.getX() - 60,
					personagem.getY() + 90,
					30,
					bolsoMinions[p].getX() + 40,
					bolsoMinions[p].getY() + 60,
					30))
				{
					personagem.levarDano(100);
				}				
			}

			lataDeLixo.atualizar(velocidadeCenario);
			if (uniTestarColisaoCirculoComCirculo(
				personagem.getX() - 60,
				personagem.getY() + 90,
				30,				
				lataDeLixo.getX(),
				lataDeLixo.getY(),
				20))
			{
				personagem.pegar(10, tLataDeLixo);
				lataDeLixo.setposicaox(-100);
				lataDeLixo.tocarsom(tLataDeLixo);
			}
		}

		if (!pausa)
			personagem.atualizar();

		if (personagem.getVida() <= 0) {
			telaAtual = tGameOver;
		}		
	}
}

void Jogo::telaCreditos()
{
	fundoCreditos.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2); 

	botoes[bOk].atualizar();
	botoes[bOk].desenhar();

	if (botoes[bOk].estaClicado())
		telaAtual = tMenu;
}

void Jogo::telaInstrucoes()
{
	fundoInstrucoes.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);	
	botoes[bOk].atualizar();
	botoes[bOk].desenhar();

	if (botoes[bOk].estaClicado())
		telaAtual = tMenu;
}

void Jogo::telaConfig()
{
	char string1[] = "HELLO, PLAYER /" 
	"WE HAVE BEEN IN A PANDEMIC FOR OVER A YEAR /" 
	"OUR PROTAGONIST LOST HER JOB AND THAT CHANGED HER LIFE COMPLETELY /"
	"NOW SHE IS DOING EVERYTHING THAT SHE CAN TO SURVIVE /"
	"EVEN SCAVENGING FROM THEWASTE STREAM /" 
	"IT HAS NOT BEEN EASY /" 
	"PEOPLE ARE IGNORING THE SERIOUSNESS OF THE SITUATION IN WHICH /"
	"WE FIND  OURSELVES /" 
	"I HOPE YOU CAN HELP US  /"	
	"WELCOME TO ANOTHER CHAOTIC DAY .";	

	timer++;
	timer2++;
	telaAtual = tConfig;

	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);	
	dialog.setEscala(1.2, 0.5);
	dialog.desenhar(900, 400);
	
	if (posText >= 1000)
		timer2 = 0;	

	if (timer2 > 18) {	

		if (string1[posText] == '/') {
			tmp = "";				
		}		
		else if (string1[posText] == '.') {
			tmp += string1[posText];
			posText = 1000;
		}
		else 
		{			
			tmp += string1[posText];			
		}	
		
		posText++;
		timer2 = 0;		
	}		

	
	dialogText.desenhar(400, 380);	
	dialogText.setString(tmp);
	
	
	tPontuacao.setString("Press Enter to start!");
	tPontuacao.setCor(255, 255, 255);
	tPontuacao.setEscala(2, 2);
	tPontuacao.desenhar(600, 800);

	resetText.setString("Press R to restart the dialog!");
	resetText.setCor(255, 0, 0);
	resetText.setEscala(1, 1);
	resetText.desenhar(350, 480);

	if (gTeclado.pressionou[TECLA_R]) {
		tmp = "";
		dialogText.desenhar(400, 380);
		dialogText.setString(tmp);
		posText = 0;
	}
		

	if (gTeclado.pressionou[TECLA_ENTER])		
		telaAtual = tJogo;	
}

void Jogo::telaGameOver()
{
	
	fundo.desenhar(pfundo1.x, pfundo1.y); //fundo 1
	fundo2.desenhar(pfundo2.x, pfundo2.y); //fundo 2	
	
	for (int b = 0; b < 4; b++) {
		gripezinha[b].desenhar();
	}

	for (int c = 0; c < 8; c++)
		lixos1[c].desenhar();

	for (int p = 0; p < 2; p++)
		bolsoMinions[p].desenhar();

	personagem.desenhar();

	lataDeLixo.desenhar();
	
	fundoGameOver.desenhar(980, 490);	

	tPontuacao.setString("Score: " +
		to_string(personagem.getPontuacao()));
	tPontuacao.setCor(255, 255, 0);
	tPontuacao.setEscala(3,3);
	tPontuacao.desenhar(750, 800);
	
	gMusica.pausar();	

	if (gTeclado.pressionou[TECLA_ENTER])
	{
		reiniciarGame();
		telaAtual = tJogo;
	}
	else if (gTeclado.pressionou[TECLA_ESPACO]) 
	{
		reiniciarGame();
		telaAtual = tMenu;		
	}
}

void Jogo::reiniciarGame()
{

	pfundo1.x = 0;
	pfundo1.y = gJanela.getAltura() / 2;

	pfundo2.x = gJanela.getLargura();
	pfundo2.y = gJanela.getAltura() / 2;

	personagem.inicializar(200, 800);		
	
	lataDeLixo.inicializar(tLataDeLixo);

	lataDeLixo.setposicaox(-100);
	lataDeLixo.zeraVelocidade();
	for (int b = 0; b < 4; b++)
	{
		gripezinha[b].setposicaox(-120);
		gripezinha[b].zeraVelocidade();
	}

	for (int c = 0; c < 8; c++)
	{
		lixos1[c].setposicaox(-120);
		lixos1[c].zeraVelocidade();
	}

	for (int p = 0; p < 2; p++)
	{
		bolsoMinions[p].setposicaox(-150);
		bolsoMinions[p].zeraVelocidade();
	}	

	tPontuacao.setFonte("minhaFonte");
	tPontuacao.setCor(0, 0, 0);
	tPontuacao.setAncora(0, 0.5);
	tPontuacao.setEscala(2.0, 2.0);

	timer2 = 0;
	velocidadeCenario = 2;
	pausa = false;	
	tmp = "";
	posText = 0;
}

