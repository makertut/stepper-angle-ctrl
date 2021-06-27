// defines pins numbers

const int stepPin = 5;

const int dirPin  = 2;

const int enPin  = 8;

// Button

const int b1 = A0;

const int b2 = A1;

const int b3 = A2;

const int b4 = A3;



int currentAngle = 0;

int angle = 0;

float stepPerAngle = 1.8; // full step = 1.8

int   numstep;
boolean dirStatus=HIGH;


void setup() {

  Serial.begin(9600);

  // Sets the two pins as Outputs

  pinMode(stepPin,OUTPUT);

  pinMode(dirPin,OUTPUT);



  pinMode(enPin,OUTPUT);

  digitalWrite(enPin,LOW);

  digitalWrite(dirPin,dirStatus);



  pinMode(b1, INPUT);

  pinMode(b2, INPUT);

  pinMode(b3, INPUT);

  pinMode(b4, INPUT);



}

void loop() {



    int n;

    if( digitalRead(b1) == HIGH){
        angle = 0;
    }

    else if( digitalRead(b2) == HIGH){
        angle = 45;
    }

    else if( digitalRead(b3) == HIGH){
        angle = 225;
    }

    else if( digitalRead(b4) == HIGH){
        angle = 270;
    }



    if( currentAngle != angle ){
        if( currentAngle < angle){
           // digitalWrite(dirPin,HIGH);
             n = angle - currentAngle;
            numstep = n / stepPerAngle;
        }
        else if( currentAngle > angle){
            //digitalWrite(dirPin,LOW);
            n = 360-(currentAngle - angle);
            if( angle == 0){
               n =currentAngle;
            }
            numstep = n / stepPerAngle;
        }
        for(int x = 0; x < numstep; x++) {

           digitalWrite(stepPin,HIGH);

           delayMicroseconds(1000);

           digitalWrite(stepPin,LOW);

           delayMicroseconds(1000);

        }
        currentAngle = angle;
    }



   delay(500);

 

}
