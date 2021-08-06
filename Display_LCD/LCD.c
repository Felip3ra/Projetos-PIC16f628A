#include<htc.h>
#define _XTAL_FREQ 4000000
__CONFIG(0X2118);


short pos=0;
void envia(short num,short tipo)
{
	RA6=tipo;
	PORTB=num;
	RA7=1; __delay_ms(5);
	RA7=0; __delay_ms(5);
}
void inicializa()
{
	__delay_ms(40);
	envia(0B00111000,0);
	envia(0B00001111,0);
	envia(1,0);
	envia(0B00000110,0);
}
void texto(const char *frase)
{
	while(*frase!=0) { envia(*frase,1); frase++; }
}
void posicao(short pos)
{
pos=pos | 0B10000000; //compatibiliza posicao do display
envia(pos,0);
}


int main(){
	TRISB=0;
	TRISA7=0;
	TRISA6=0;
	PORTB=0;
	
	inicializa();
	texto("funciona");
	posicao(64);
	texto("linha2");
	__delay_ms(5000);
	posicao(6);
	texto("troca");
	posicao(14);
	while(1){

	

	}

}