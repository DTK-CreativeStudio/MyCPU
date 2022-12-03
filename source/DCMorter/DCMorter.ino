void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}
constexpr float BPM = 140;

void note(int i, int div_num, int count) {
  int v = 123218.095902248*exp(-0.058022998718112 * (i + 24));
  Serial.println(v);
  for(int i = 0; i < (240/BPM * ((float)count / div_num)) * 1000000 / v; i++){
    digitalWrite(3,HIGH);
    delayMicroseconds(v/2);
    digitalWrite(3,LOW);
    delayMicroseconds(v/2);
  }
}

int n[] = {
  41,68,41,68,41,68,41,68,41,68,41,68,41,68,41,68,65,61,63,65,63,65,67,68,67,68,70,68,67,65,67,80,79,77,79,77,
  65,67,68,60,68,67,65,67,60,67,65,64,67,60,70,68,67,65,67,68,70,72
};
int d[] = {
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16,16,16,16,16,16,16,16,16,16,16,16,16,16,8, 8, 8, 8, 4, 
  8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 4 ,8, 8 ,8, 8, 8, 8, 4
};
int c[] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1
};

void loop(){
  for(int i = 0; i < sizeof(n) / sizeof(int); i++){
    note(n[i], d[i],c[i]);
  }
  delay(60000);
}
