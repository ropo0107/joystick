int channel_one = 2;
int channel_two = 3;
int channel_three = 4;
int channel_four = 5;
unsigned long duration_one;
unsigned long duration_two;
unsigned long duration_three;
unsigned long duration_four;
unsigned long start = 0;
int board_data_received;
void setup() {
  // put your setup code here, to run once:
   pinMode(channel_one, INPUT);
   pinMode(channel_two, INPUT);
   pinMode(channel_three, INPUT);
   pinMode(channel_four, INPUT);
   Serial.begin(115200);
   start = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
// Serial.print((millis() - start));
//  start = millis();
  if (Serial.available() > 0){
    board_data_received = (int) Serial.read();
    if (board_data_received == 115){ // 's'
      duration_one = pulseIn(channel_one, HIGH);
//      Serial.print(" C1:");
      Serial.print("C1:");
      Serial.println(duration_one);
    }else{
      Serial.print("I received: ");
      Serial.println(board_data_received);
    }
  }
//  Serial.print(" Time(ms):");
//  Serial.println((millis() - start));
//  delay(20);
}