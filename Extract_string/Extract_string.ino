String text = "*B,47,-0.00*F,59,0.04*S,105,6.85*";

void setup() {
  Serial.begin(9600);
  extract(text);
}

void loop() {
}

void extract(String record) {
  int i = 0;
  int number = 0;
  Serial.println(record);
  int ex_Command[10], ex_count[10], ex_angle[10];
  String dummy[100];
  int dummy_count = 0;
  int x = 1;

  while (x != 2) {
    int start = record.indexOf('*', 1);
    Serial.println(start);
    int stopp = record.indexOf('*', start+1);
    Serial.println(stopp);
    int temp = record.indexOf('*',stopp+1);
    Serial.println(temp);
    dummy[x] = record.substring(x, start);
    dummy[x + 1] = record.substring(start + 1, stopp);
    dummy[x + 2] = record.substring(stopp + 1, temp);
    Serial.println(dummy[1]);
    Serial.println(dummy[2]);
    Serial.println(dummy[3]);

    x++;
  }
  int pos = dummy_count;
  record = "";
}
