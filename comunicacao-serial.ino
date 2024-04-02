const int LED_BLUE = 9;
const int LED_GREEN = 10;
const int LED_RED = 11;

void setup () {
  Serial.begin(9600); //configura comunicacao serial com 9600 bps
  pinMode(LED_BLUE, OUTPUT); //configura pino do led como saída
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop () {                      
  if (Serial.available()) {         //se byte pronto para leitura
    switch(Serial.read()) {           //verifica qual caracter recebido
      case 'A':                 //Caso 'A'
        digitalWrite(LED_BLUE,HIGH); //inverte estado do LED
        break;
      case 'a':
        digitalWrite(LED_BLUE,LOW);
        break;
      case 'R':
        digitalWrite(LED_RED,HIGH);
        break;
      case 'r':
        digitalWrite(LED_RED,LOW);
        break;
      case 'G':
        digitalWrite(LED_GREEN,!digitalRead(LED_GREEN));
        break;
    }
  }
}