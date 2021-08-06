#include<htc.h>
#define _XTAL_FREQ 4000000
__CONFIG(0X2118);

char recebe;
int valor=0,controle=1;

void pwm(char rec){

	switch(rec){
    case '0':
        if(controle == 1){
          valor = 0 * 100;
        }
        else if(controle == 2){
          valor += 0 * 10;
        }
        else if(controle == 3){
          valor += 0;
        }
        controle++;
        break;

     case '1':
        if(controle == 1){
          valor = 1 * 100;
        }
        else if(controle == 2){
          valor += 1 * 10;
        }
        else if(controle == 3){
          valor += 1;
        }
        controle++;
        
        break;

      case '2':
        if(controle == 1){
          valor = 2 * 100;
        }
        else if(controle == 2){
          valor += 2 * 10;
        }
        else if(controle == 3){
          valor += 2;
        }
        controle++;
        
        break;

      case '3':
        if(controle == 1){
          valor = 3 * 100;
        }
        else if(controle == 2){
          valor += 3 * 10;
        }
        else if(controle == 3){
          valor += 3;
        }
        controle++;
        break;

      case '4':
        if(controle == 1){
          valor = 4 * 100;
        }
        else if(controle == 2){
          valor += 4 * 10;
        }
        else if(controle == 3){
          valor += 4;
        }
        controle++;
        break;

       case '5':
        if(controle == 1){
          valor = 5 * 100;
        }
        else if(controle == 2){
          valor += 5 * 10;
        }
        else if(controle == 3){
          valor += 5;
        }
        controle++;
        break;

     case '6':
        if(controle == 1){
          valor = 6 * 100;
        }
        else if(controle == 2){
          valor += 6 * 10;
        }
        else if(controle == 3){
          valor += 6;
        }
        controle++;
        break;

      case '7':
        if(controle == 1){
          valor = 7 * 100;
        }
        else if(controle == 2){
          valor += 7 * 10;
        }
        else if(controle == 3){
          valor += 7;
        }
        controle++;
        break;

      case '8':
        if(controle == 1){
          valor = 8 * 100;
        }
        else if(controle == 2){
          valor += 8 * 10;
        }
        else if(controle == 3){
          valor += 8;
        }
        controle++;
        break;

      case '9':
        if(controle == 1){
          valor = 9 * 100;
        }
        else if(controle == 2){
          valor += 9 * 10;
        }
        else if(controle == 3){
          valor += 9;
        }
        controle++;
        break;

    }
	if(controle == 4){
        controle=1;
        
      }

}

int main(){

TRISB = 0B00000010;
PORTB=0;
//TXSTA
TXEN = 1;
SYNC = 0;
BRGH = 1;

//RCSTA
SPEN = 1;
CREN = 1;
SPBRG = 25;

//PWM
PR2 = 255; // FLAG DE ESTOURO DO TIMER2
CCPR1L = 0; //PWM
T2CON = 0B00000110;
CCP1CON = 0B00001100;

//ROT INICIAL AH
RB4=1;
RB7=1;

	while(1){
		if(RCIF == 1){

			recebe = RCREG;

			if(recebe == 'p'){
				
				RB4 = 0;
				RB5 = 0;
				RB6 = 0;
				RB7 = 0;
			}
			else if(recebe == 'a'){
				RB5 = 0;
				RB6 = 0;
				__delay_ms(500);
				RB4 = 1;
				RB7 = 1;
			}
			else if(recebe == 'h'){
				RB4 = 0;
				RB7 = 0;
				__delay_ms(500);
				RB5 = 1;
				RB6 = 1;
			}
			else{
				pwm(recebe);
			}
		}

		CCPR1L = valor;
	}

}