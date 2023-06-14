int motor1Pin1 = 22;     // Pin 1 del motor Az                      
int motor1Pin2 = 23;     // Pin 2 del motor Az
int motor1Pin3 = 24;     // Pin 3 del motor Az
int motor1Pin4 = 25;     // Pin 4 del motor Az
int motor2Pin1 = 26;     // Pin 1 del motor Dec
int motor2Pin2 = 27;     // Pin 2 del motor Dec
int motor2Pin3 = 28;     // Pin 3 del motor Dec
int motor2Pin4 = 29;     // Pin 4 del motor Dec
int delayTime = 15;      // delay de pasos del motor Az/Dec
int buttonizq = 2;       // pin entrada hacia izquierda
int buttonder = 3;       // pin entrada hacia derecha
int buttonarb = 4;       // pin entrada hacia arriba
int buttonabj = 5;       // pin entrada hacia abajo
int izquierda  = 0;      // estado de la entrada de giro a izquierda
int derecha = 0;         // estado de la entrada de giro a derecha
int arriba = 0;          // estado de la entrada de giro a arriba
int abajo = 0;           // estado de la entrada de giro a abajo
int buttonbuscar = 6;
int buscar = 0;
float paso = 0.087890625;
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
  pinMode(motor1Pin1, OUTPUT);                   
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2Pin3, OUTPUT);
  pinMode(motor2Pin4, OUTPUT);  
  pinMode(buttonizq, INPUT); 
  pinMode(buttonder, INPUT);
  pinMode(buttonarb, INPUT);
  pinMode(buttonabj, INPUT);
  pinMode(buttonbuscar, INPUT);
  Serial.begin(9600);
  Serial.println("Posición");
}
void loop() {
  izquierda = digitalRead(buttonizq);
  derecha =  digitalRead(buttonder);
  arriba = digitalRead(buttonarb);
  abajo = digitalRead(buttonabj);
  
  if(izquierda==HIGH)
  { 
    for (int i = 0; i < 1; i++)
    {
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(motor1Pin1, giroizquierda[i][0]);
        digitalWrite(motor1Pin2, giroizquierda[i][1]);
        digitalWrite(motor1Pin3, giroizquierda[i][2]);
        digitalWrite(motor1Pin4, giroizquierda[i][3]); 
        delay(delayTime);
      }      
    }   
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);  
  digitalWrite(motor1Pin4, LOW);
  }
  else if (derecha==HIGH)
  {
    for (int i = 0; i < 1; i++)
    {
      for (int i = 0; i < 8; i++)
      {
       digitalWrite(motor1Pin1, giroderecha[i][0]);
       digitalWrite(motor1Pin2, giroderecha[i][1]);
       digitalWrite(motor1Pin3, giroderecha[i][2]);
       digitalWrite(motor1Pin4, giroderecha[i][3]);
       delay(delayTime);
      }          
    }
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
  }

if(arriba==HIGH)
  { 
    for (int i = 0; i < 1; i++)
    {
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(motor2Pin1, giroizquierda[i][0]);
        digitalWrite(motor2Pin2, giroizquierda[i][1]);
        digitalWrite(motor2Pin3, giroizquierda[i][2]);
        digitalWrite(motor2Pin4, giroizquierda[i][3]); 
        delay(delayTime);
      }      
    }   
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor2Pin3, LOW);  
  digitalWrite(motor2Pin4, LOW);
  }
  else if (abajo==HIGH)
  {
    for (int i = 0; i < 1; i++)
    {
      for (int i = 0; i < 8; i++)
      {
       digitalWrite(motor2Pin1, giroderecha[i][0]);
       digitalWrite(motor2Pin2, giroderecha[i][1]);
       digitalWrite(motor2Pin3, giroderecha[i][2]);
       digitalWrite(motor2Pin4, giroderecha[i][3]);
       delay(delayTime);
      }          
    }
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
  }
  if (buscar==HIGH)  //Error en esta parte, estoy mirando como arreglarlo
  {
    while (Serial.available()==0)
    {      
    
  
      int posicion = Serial.parseFloat();
      int desplazamiento(int paso, int posicion);
      {
        int pasos;
        pasos=posicion/paso;
      }
      int pasosv;
      float pasos;
      pasosv = (int) pasos;  
      for (int i = 0; i < pasosv; i++)
      {
      for (int i = 0; i < 8; i++)
        {
          digitalWrite(motor1Pin1, giroizquierda[i][0]);
          digitalWrite(motor1Pin2, giroizquierda[i][1]);
          digitalWrite(motor1Pin3, giroizquierda[i][2]);
          digitalWrite(motor1Pin4, giroizquierda[i][3]); 
          delay(delayTime);
        }      
      }   
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor1Pin3, LOW);  
      digitalWrite(motor1Pin4, LOW); 
