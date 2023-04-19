
 int motorPin1 = 8;        // Pin 1 del motor Az                      
 int motorPin2 = 9;        // Pin 2 del motor Az
 int motorPin3 = 10;       // Pin 3 del motor Az
 int motorPin4 = 11;       // Pin 4 del motor Az
 int delayTime = 15;       // delay de pasos del motor Az               
 int buttonizq = 2;       // pin entrada hacia izquierda
 int buttonder = 3;       // pin entrada hacia derecha
 int izquierda  = 0;       // estado de la entrada de giro izquierda
 int derecha = 0;          // estado de la entrada de giro a derecha
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
int giroarriba [8][4] =
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
int giroabajo [8][4] =
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
  pinMode(motorPin1, OUTPUT);                   
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(buttonizq, INPUT); 
  pinMode(buttonder, INPUT);
}
void loop() {
  izquierda= digitalRead(buttonizq);
  derecha=  digitalRead(buttonder);

  if(izquierda==HIGH)
  { 
    for (int i = 0; i < 51; i++){
      for (int i = 0; i < 8; i++)
      digitalWrite(motorPin1, giroizquierda[i][0]);
      digitalWrite(motorPin2, giroizquierda[i][1]);
      digitalWrite(motorPin3, giroizquierda[i][2]);
      digitalWrite(motorPin4, giroizquierda[i][3]);          
    }    
  }
  else if (derecha==HIGH)
  {
    for (int i = 0; i < 51; i++){
      for (int i = 0; i < 8; i++)
      digitalWrite(motorPin1, giroderecha[i][0]);
      digitalWrite(motorPin2, giroderecha[i][1]);
      digitalWrite(motorPin3, giroderecha[i][2]);
      digitalWrite(motorPin4, giroderecha[i][3]);          
    }
  }
}
