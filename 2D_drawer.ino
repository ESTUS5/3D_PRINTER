// ZMIENNE ZDEFINIOWANE DLA 2 PAR PINÓW
int Y_dir = 2; //Direction pin
int Y_step = 3; //Stepper pin
int X_dir = 4; //Direction pin
int X_step = 5; //Stepper pin

// SETUP, 2 PARY PINÓW DO STEROWNIKÓW EASY DRIVER
void setup(){
  pinMode(X_step, OUTPUT);
  pinMode(X_dir, OUTPUT);
  pinMode(Y_step, OUTPUT);
  pinMode(Y_dir, OUTPUT);
  Serial.begin(9600);
}
//METODY UŻYTE DO PRZEMIESZCZANIA SIĘ OSI X I Y
void move_left()
{
  digitalWrite(Y_dir, HIGH); // USTAWIA KIERUNEK OBRACANIA SIĘ SILNIKA BIPOLARNEGO
  digitalWrite(Y_step, HIGH); // WYSYŁA NAPIĘCIE 3.3V DO SILNIKA PRZEZ STEROWNIK
  delayMicroseconds(100); // CZAS DZIAŁANIA SILNIKA POD NAPIĘCIEM
  digitalWrite(Y_step,LOW); // WYSYŁA SYGNAŁ O NAPIĘCIU 0V DO SILNIKA
  delayMicroseconds(440); // CZAS OCZEKIWANIA 
}

void move_right()
{
  digitalWrite(Y_dir, LOW);
  digitalWrite(Y_step, HIGH);
  delayMicroseconds(100);
  digitalWrite(Y_step, LOW);
  delayMicroseconds(440);
}

void move_forward()
{
  digitalWrite(X_dir, LOW);
  digitalWrite(X_step, HIGH);
  delayMicroseconds(510);
  digitalWrite(X_step, LOW);
  delayMicroseconds(100);
}

void move_backward()
{
  digitalWrite(X_dir, HIGH);
  digitalWrite(X_step, HIGH);
  delayMicroseconds(510);
  digitalWrite(X_step, LOW);
  delayMicroseconds(100);
}

// LOOP = PROCES RYSOWANIA METODAMI
void loop(){
  delay(2500); // OPÓZNIENIE BY PRZYGOTOWAĆ DRUKARKĘ DO PRACY
  for(int i = 0; i!= 250;i++)
  {
    move_left();
  }
  for(int i = 0; i!= 125;i++)
  {
    move_forward();
    move_left();
  }
  for(int i = 0; i!= 125;i++)
  {
    move_backward();
    move_left();
  }
  for(int i = 0; i!= 250;i++)
  {
    move_left();
  }
  for(int i = 0; i!= 175;i++)
  {
    move_backward();
    move_right();
  }
  for(int i = 0; i!= 175;i++)
  {
    move_backward();
    move_left();
  }
  for(int i = 0; i!= 250;i++)
  {
    move_right();
  }
  for(int i = 0; i!= 125;i++)
  {
    move_backward();
    move_right();
  }
  for(int i = 0; i!= 125;i++)
  {
    move_forward();
    move_right();
  }
  for(int i = 0; i!= 250;i++)
  {
    move_right();
  }
  for(int i = 0; i!= 175;i++)
  {
    move_forward();
    move_left();
  }
  for(int i = 0; i!= 175;i++)
  {
    move_forward();
    move_right();
  }
}
