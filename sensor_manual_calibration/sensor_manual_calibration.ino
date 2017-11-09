int left = 8;
int centre = 9;
int right = 10;

int left_max = 0, centre_max = 0, right_max = 0;
int left_min = 2000, centre_min = 2000, right_min = 2000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

int read_channel(int ch) {
  unsigned long val = 0;
  for(int i = 0; i < 32; i++) {
    val += analogRead(ch);
  }
  return (val >> 5);
}

void loop() {
  // put your main code here, to run repeatedly:

  int rd = read_channel(left);
  if(rd > left_max) left_max = rd;
  if(rd < left_min) left_min = rd;
  
  rd = read_channel(centre);
  if(rd > centre_max) centre_max = rd;
  if(rd < centre_min) centre_min = rd;
  
  rd = read_channel(right);
  if(rd > right_max) right_max = rd;
  if(rd < right_min) right_min = rd;
  

  Serial.print("Left   MIN: ");
  Serial.print(left_min);
  Serial.print("  MAX: ");
  Serial.println(left_max);

  Serial.print("Centre MIN: ");
  Serial.print(centre_min);
  Serial.print("  MAX: ");
  Serial.println(centre_max);

  Serial.print("Right  MIN: ");
  Serial.print(right_min);
  Serial.print("  MAX: ");
  Serial.println(right_max);

  Serial.println();
  delay(1000);
}
