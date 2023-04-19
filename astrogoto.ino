int izquierda = 3;
int derecha = 2;
int estizq = 0;
int estder = 0;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 20;

int giroizquierda [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

int giroderecha [8][4] =
{
  {1, 0, 0, 0},
  {1, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 1, 1},
  {0, 0, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0}
};

void setup() {
  pinMode(izquierda, INPUT);
  pinMode(derecha, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);  
  estizq = digitalRead(izquierda);
  estder = digitalRead(derecha);
}
 
void loop(){
  estizq = digitalRead(izquierda);
  estder = digitalRead(derecha);  
  if (estizq==HIGH)
  {
      for (int i = 0; i < 512; i++)
    {
      for (int i = 0; i < 8; i++)
      {      
        digitalWrite(IN1, giroizquierda[i][0]);
        digitalWrite(IN2, giroizquierda[i][1]);
        digitalWrite(IN3, giroizquierda[i][2]);
        digitalWrite(IN4, giroizquierda[i][3]);
       delay(demora);
      }
    }
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);    

  }
  else
  {
      for (int i = 0; i < 512; i++)
    {
      for (int i = 0; i < 8; i++)
        digitalWrite(IN1, giroderecha[i][0]);
        digitalWrite(IN2, giroderecha[i][1]);
        digitalWrite(IN3, giroderecha[i][2]);
        digitalWrite(IN4, giroderecha[i][3]);
       delay(demora);
      }
    }

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }  
}