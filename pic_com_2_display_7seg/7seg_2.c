#include<htc.h>
#define _XTAL_FREQ 4000000
__CONFIG(0X2118);

short valor=0;

void display(short numero){

	switch(numero){

	   case 0:
			RB0 = 1;
			RB1 = 1;
			RB2 = 1;
			RB3 = 1;
			RB4 = 1;
			RB5 = 1;
			RB6 = 0;
			break;

		case 1:
			RB0 = 0;
			RB1 = 1;
			RB2 = 1;
			RB3 = 0;
			RB4 = 0;
			RB5 = 0;
			RB6 = 0;
			break;

		case 2:
			RB0 = 1;
			RB1 = 1;
			RB2 = 0;
			RB3 = 1;
			RB4 = 1;
			RB5 = 0;
			RB6 = 1;
			break;

		case 3:
			RB0 = 1;
			RB1 = 1;
			RB2 = 1;
			RB3 = 1;
			RB4 = 0;
			RB5 = 0;
			RB6 = 1;
			break;

		case 4:
			RB0 = 0;
			RB1 = 1;
			RB2 = 1;
			RB3 = 0;
			RB4 = 0;
			RB5 = 1;
			RB6 = 1;
			break;

		case 5:
			RB0 = 1;
			RB1 = 0;
			RB2 = 1;
			RB3 = 1;
			RB4 = 0;
			RB5 = 1;
			RB6 = 1;
			break;

		case 6:
			RB0 = 1;
			RB1 = 0;
			RB2 = 1;
			RB3 = 1;
			RB4 = 1;
			RB5 = 1;
			RB6 = 1;
			break;

		case 7:
			RB0 = 1;
			RB1 = 1;
			RB2 = 1;
			RB3 = 0;
			RB4 = 0;
			RB5 = 0;
			RB6 = 0;
			break;

		case 8:
			RB0 = 1;
			RB1 = 1;
			RB2 = 1;
			RB3 = 1;
			RB4 = 1;
			RB5 = 1;
			RB6 = 1;
			break;

		case 9:
			RB0 = 1;
			RB1 = 1;
			RB2 = 1;
			RB3 = 0;
			RB4 = 0;
			RB5 = 1;
			RB6 = 1;
			break;
	}
}

void mostra(short n){

	short dezena,unidade;
	dezena = n/10;
	unidade = n%10;
	display(dezena);RA0=1;
	__delay_ms(200);RA0=0;
	display(unidade);RA1=1;
	__delay_ms(200);RA1=0;
}

int main(){

TRISB=0;
TRISA7=1;
TRISA6=1;
TRISA0=0;
TRISA1=0;
	while(1){

		if(RA7 == 1){

			while(RA7==1);
			if(valor < 99){
				valor++;
			}
			else{
				valor=0;
			}
			
		}
		if(RA6 == 1){

			while(RA6==1);
			if(valor > 0){
				valor--;
			}
			else{
				valor=99;
			}
			
		}
		mostra(valor);
	}


}