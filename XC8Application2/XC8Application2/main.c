

//#include <xc.h>
#define F_CPU 16000000ul
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void command_to_LCD(unsigned char cmd){
	PORTC = 0x02; // THE RS PIN IS LOW AND THE ENABLE PIN IS HIGH
	PORTD = cmd;
	PORTC = 0x00; // THE RS PIN IS LOW AND THE ENABLE PIN IS LOW
	_delay_ms(10); // TO ENSURE LCD HAS ENOUGH TIME TO PROCESS THE COMMAND
}

void data_to_LCD(unsigned char data){
	PORTC = 0x03; // THE RS PIN IS HIGH AND THE ENABLE PIN IS HIGH
	PORTD = data;
	PORTC = 0x01; // THE RS PIN IS LOW AND THE ENABLE PIN IS LOW
	_delay_ms(10);// TO ENSURE LCD HAS ENOUGH TIME TO PROCESS THE COMMAND
	
}

void row1(){
	
	
	PORTB = 0x01; // SET THE FIRST PIN OF PORT B HIGH
	
	if(PINA == 0x01){
		 data_to_LCD('D');
		 command_to_LCD(0x06);		
	} else if (PINA == 0x02){
		 data_to_LCD('A');
		 command_to_LCD(0x06);	
		
	} else if (PINA == 0x04){
		 data_to_LCD('N');
		 command_to_LCD(0x06);	
		
	} else if (PINA == 0x08){
	     data_to_LCD('I');
	     command_to_LCD(0x06);	
	
    }
}

void row2(){
	
   PORTB = 0x02; // SET THE SECOND PIN OF PORT B HIGH
   
   if(PINA == 0x01){
	    data_to_LCD('E');
	    command_to_LCD(0x06);	
	   } else if (PINA == 0x02){
	       data_to_LCD('L');
	       command_to_LCD(0x06);	
	   
	   } else if (PINA == 0x04){
	       data_to_LCD('1');
	       command_to_LCD(0x06);	
	   
	   } else if (PINA == 0x08){
	       data_to_LCD('2');
	       command_to_LCD(0x06);	
	   
   }	
}

void row3(){
	
	PORTB = 0x04; // SET THE THIRD PIN OF PORT B HIGH
	
	if(PINA == 0x01){
		 data_to_LCD('3');
	     command_to_LCD(0x06);	
		} else if (PINA == 0x02){
		 data_to_LCD(' ');
	     command_to_LCD(0x06);	// SHIFT CURSOR TO RIGHT
		
		} else if (PINA == 0x04){
		command_to_LCD(0x01); // CLEAR THE DISPLAY
		
		} else if (PINA == 0x08){
		command_to_LCD(0x80); // CURSOR TO BEGIN IN FIRST LINE
		
	}
}

void row4(){
	PORTB = 0x08; // SET THE FOURTH PIN OF PORT B HIGH
	
	if(PINA == 0x01){
		command_to_LCD(0xc0); // CURSOR TO BEGIN IN THE SECOND LINE
		
		} else if (PINA == 0x02){
			
		data_to_LCD('*');
		command_to_LCD(0x06);
		
		} else if (PINA == 0x04){
		data_to_LCD('.');
		command_to_LCD(0x06);
		
		} else if (PINA == 0x08){
		data_to_LCD('#');
		command_to_LCD(0x06);
		
	}
}



int main(void){
	DDRA = 0x00; // PORT A SET AS INPUT
	DDRB = 0xff; // PORT B SET AS OUTPUT
	DDRC = 0xff; // PORT C SET AS OUTPUT
	DDRD = 0xff; // PORT D SET AS OUTPUT
	command_to_LCD(0x38); // ACTIVATE THE TWO LINES(ROWS)
	command_to_LCD(0x0f); // DISPLAY ON CURSOR BLINKING
	command_to_LCD(0x01); // CLEAR SCREEN
	command_to_LCD(0x80); // CURSOR TO THE FIRST LINE
    while(1)
    {
        //TODO:: Please write your application code 
		row1(); 
		_delay_ms(5);
		row2();
		_delay_ms(5);
		row3();
		_delay_ms(5);
		row4();
		_delay_ms(5);
    }
}