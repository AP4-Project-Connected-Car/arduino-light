void setup()
{
  Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    pinMode(11, INPUT);
    pinMode(12, INPUT);
}

void writeBinaryWithThreeOutput(int ouput_1, int ouput_2, int ouput_3, int value)
{
  // Whrite on digital ouputs the number value in binary
  digitalWrite(ouput_1, (value & 0x04) >> 2);
  digitalWrite(ouput_2, (value & 0x02) >> 1);
  digitalWrite(ouput_3, value & 0x01);
  Serial.print((value & 0x04) >> 2);
  Serial.print((value & 0x02) >> 1);
  Serial.println(value & 0x01);
}

int tmp = 400;

void loop()
{
  int front_right = 0;
  int front_right_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, front_right);
  front_right_work = digitalRead(5);
  delay(tmp);

  int front_left = 1;
  int front_left_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, front_left);
  front_left_work = digitalRead(6);
  delay(tmp);

  int blinker_front_right = 2;
  int blinker_front_right_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, blinker_front_right);
  blinker_front_right_work = digitalRead(7);
  delay(tmp);

  int blinker_front_left = 3;
  int blinker_front_left_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, blinker_front_left);
  blinker_front_left_work = digitalRead(8);
  delay(tmp);

  int blinker_rear_right = 4;
  int blinker_rear_right_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, blinker_rear_right);
  blinker_rear_right_work = digitalRead(9);
  // delay(tmp);

  int blinker_rear_left = 5;
  int blinker_rear_left_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, blinker_rear_left);
  blinker_rear_left_work = digitalRead(10);
  // delay(tmp);

  int rear_right = 6;
  int rear_right_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, rear_right);
  rear_right_work = digitalRead(11);
  // delay(tmp);

  int rear_left = 7;
  int rear_left_work = 0;
  writeBinaryWithThreeOutput(2, 3, 4, rear_left);
  rear_left_work = digitalRead(12);
  // delay(tmp);

  Serial.print(front_right_work);
  Serial.print(front_left_work);
  Serial.print(blinker_front_right_work);
  Serial.print(blinker_front_left_work);
  Serial.print(blinker_rear_right_work);
  Serial.print(blinker_rear_left_work);
  Serial.print(rear_right_work);
  Serial.println(rear_left_work);
  delay(tmp);
}
