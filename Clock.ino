// Wiring notes:
// Pin 8: Decimal control
// Pins 10-13: D1-4

int A = 1;
int B = 2;
int C = 3;
int D = 4;

int seconds = 0;
int minutes = 0;
int hours = 0;

void setup() {
  Serial.begin(9600);
  // Segment decoders
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  // Segment Cathodes
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  //delay(500);
  //delay(500);
  seconds++;

  if (seconds == 60) {
    if (minutes == 59) {
      hours++;
      minutes = 0;
      seconds = 0;
    }
    else {
      minutes++;
      seconds = 0;
    }
  }
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.print(seconds);
  Serial.print("\n");
  display(11,hours);
  display(12,minutes);
}

// Prototype 7 segment display function
// Requires 7 segment decoder control pins mapped to A-D
void display(int segment, int value) {
  digitalWrite(segment,LOW);
  if (value == 0)
  {
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  else if (value == 1)
  {
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  else if (value == 2)
  {
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  else if (value == 3)
  {
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  else if (value == 4)
  {
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
  }
  else if (value == 5)
  {
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
  }
  else if (value == 6)
  {
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
  }
  else if (value == 7)
  {
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
  }
  else if (value == 8)
  {
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
  }
  else if (value == 9)
  {
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
  }
  digitalWrite(segment,HIGH);
}

