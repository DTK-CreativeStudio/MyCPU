constexpr long MICRO = 1000;
constexpr auto _0 = 1.45;
constexpr auto _M90 = 0.5;
constexpr auto _P90 = 2.4;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
}

void loop() {
  //0 deg
  digitalWrite(7, HIGH);
  delayMicroseconds(_0 * MICRO);
  digitalWrite(7, LOW);
  delayMicroseconds((20 - _0) * MICRO);
  delay(105);
  //90 deg
  digitalWrite(7, HIGH);
  delayMicroseconds(_P90 * MICRO);
  digitalWrite(7, LOW);
  delayMicroseconds((20 - _P90) * MICRO);
  delay(105);

  delay(250);
}
