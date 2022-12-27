#include "note.h"
constexpr float BPM = 30;


struct note{
	int number, div_num, count;
	void play() {
		constexpr double A = 123218.0959, E = 0.058022999;
		double f = 440 * (powf(powf(2, 1/12.0), number-69));
		int v = A*exp(-1*E*(number));
		Serial.println(v);
		for(int i = 0; i < (240/BPM * ((float)count / div_num)) * 1000000 / v; i++){
			digitalWrite(3,HIGH);
			delayMicroseconds(v/2);
			digitalWrite(3,LOW);
			delayMicroseconds(v/2);
		}
	}
};

void setup() {
	// put your setup code here, to run once:
	pinMode(3,OUTPUT);
	Serial.begin(9600);
}



note notes[] = {
	{C_5,4,1},
	{D_5,4,1},
	{E_5,4,1},
	{F_5,4,1},
	{G_5,4,1},
	{A_5,4,1},
	{H_5,4,1},
	{C_6,4,1}
};

void loop(){
	for(int i = 0; i < sizeof(notes) / sizeof(note); i++){
		notes[i].play();
	}
	delay(60000);
}
