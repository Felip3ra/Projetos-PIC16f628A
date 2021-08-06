#include<htc.h>
#define _XTAL_FREQ 4000000
__CONFIG(0X2118);

char recebe;
short termino=0;
void converte(short valor)
{
	if(valor&0B00000001==1){ RB0=1; }
	else { RB0=0; }
	valor=valor>>1;
	if(valor&0B00000001==1){ RA1=1; }
	else { RA1=0; }
	valor=valor>>1;
	if(valor&0B00000001==1){ RA2=1; }
	else { RA2=0; }
	valor=valor>>1;
	if(valor&0B00000001==1){ RB3=1; }
	else { RB3=0; }
	valor=valor>>1;
	if(valor&0B00000001==1){ RB4=1; }
	else { RB4=0; }
	valor=valor>>1;
	if(valor&0B00000001==1){ RB5=1; }
	else { RB5=0; }
	valor=valor>>1;
	if(valor&0B00000001==1){ RB6=1; }
	else { RB6=0; }
	valor=valor>>1;
	if(valor&0B00000001==1){ RB7=1; }
	else { RB7=0; }
}

void envia(short num,short tipo)
{
	RA6=tipo;
	converte(num);
	RA7=1; __delay_ms(2);
	RA7=0; __delay_ms(2);
}
void inicializa(){
	
	__delay_ms(20);
	envia(0B00111000,0);
	envia(0B00001111,0);
	envia(0B00000001,0);
	envia(0B00000110,0);
}
void texto(char *frase){

	while(*frase != 0){
		envia(*frase,1);
		frase++;
	}
}
void posicao(short pos){

	pos = pos | 0B10000000;
	envia(pos,0); 
}

int main(){
	TRISB=0B00000010;
	TRISA=0;
	PORTB=0;
	inicializa();
	texto("PWM:");
	posicao(64);
	texto("ROT:AH");
	posicao(4);

	//TXSTA
	TXEN = 1;
	SYNC = 0;
	BRGH = 1;
	SPBRG = 25;

	//RCSTA
	SPEN = 1;
	CREN = 1;
	
	while(1){
		//FLAG DA CMC SERIAL
		if(RCIF == 1){
			recebe = RCREG;
			if(termino == 3){
		        posicao(4);
		        termino=0;
		      }
		
		      if(recebe == 'a'){
		            posicao(68);
		            texto("A");
		            posicao(69);
		            texto("H");
		            posicao(4);
		            TXREG = recebe;
		      }
		      else if(recebe == 'h'){
		            posicao(68);
		            texto("H");
		            posicao(69);
		            texto(" ");
		            posicao(4);
		            TXREG = recebe;
		      }
		      else if(recebe == 'p'){
		            posicao(68);
		            texto("Parado");
		            posicao(4);
		            TXREG = recebe;
		      }
		      else{
		            envia(recebe,1);
		            TXREG = recebe;
		            termino++;
		      }
		}	
	}

}