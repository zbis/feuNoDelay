/*
 * Une des solutions pour faire un feu trivolore voiture / pieton sans utiliser de delay()
 * 
 * Créé par Tatiana Grange, pour zBis, sous licence CC-BY-SA 4.0
 */
 

/********** Constantes **********/
// Les constantes sont comme des bouts de papier sur lesquels on écrit un mot ou un chiffre au feutre pour le retenir
// Le feutre ne peut-être effacé, la constante ne peut être modifiée.
const int car_redLed      = 13;
const int car_orangeLed   = 12;
const int car_greenLed    = 11;
const int p_redLed        = 10;
const int p_greenLed      = 9;
const int redForCar       = 1;
const int orangeForCar    = 2;
const int greenForCar     = 3;


/********** Variables **********/
// Les variables sont comme des bouts de papier sur lesquels on écrit au crayon à papier. 
// On peut remplacer le contenu de la variable en gommant et en écrivant la nouvelle valeur au crayon à papier
int state;
long myTime;


/********** Fonctions **********/

// La fonction setup est la toute première exécutée par la carte Arduino.
void setup() {

  //Déclaration du mode des pins
  pinMode(car_redLed,OUTPUT);
  pinMode(car_orangeLed,OUTPUT);
  pinMode(car_greenLed,OUTPUT);
  pinMode(p_redLed,OUTPUT);
  pinMode(p_greenLed,OUTPUT);

  //Définition du tout premier état
  state = greenForCar;

  //Définition du temps
  myTime = millis();

  //Définition du port série pour débugger
  Serial.begin(9600);


  //Configuration de base
  digitalWrite(car_greenLed,HIGH);
  digitalWrite(car_redLed,LOW);
  digitalWrite(p_redLed,HIGH);
  digitalWrite(p_greenLed,LOW);
}

// La fonction loop est appelée en boucle par la carte Arduino
void loop() {

  //Récupération de la différence de temps entre l'étape précédente et le temps courrant
  long diff = millis() - myTime;

  //Debug du temps
  Serial.println(myTime);

  //Gestion des différents cas
  switch(state){
    //Il est rouge pour les voitures
    case redForCar:
      if(diff > 5000){
        digitalWrite(car_greenLed,HIGH);
        digitalWrite(car_redLed,LOW);

        digitalWrite(p_redLed,HIGH);
        digitalWrite(p_greenLed,LOW);

        myTime = millis();
        state = greenForCar;
      }
      break;
    //Il est orange pour les voitures
    case orangeForCar:
      if(diff > 3000){
          digitalWrite(car_redLed,HIGH);
          digitalWrite(car_orangeLed,LOW);
  
          digitalWrite(p_greenLed,HIGH);
          digitalWrite(p_redLed,LOW);
  
          myTime = millis();
          state = redForCar;
        }
      break;
    //Il est vert pour les voiture
    case greenForCar:
      if(diff > 7000){
            digitalWrite(car_orangeLed,HIGH);
            digitalWrite(car_greenLed,LOW);
    
            myTime = millis();
            state = orangeForCar;
          }
      break;
    default:
      myTime = millis();
      state = greenForCar;
      break;
  }
}
