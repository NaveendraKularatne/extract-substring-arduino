String text = "*B,47#-0.00*F,59#0.04*S,105#6.85*B,47#-56.00*L,142#3.85*S,150#2.36*";

int arrayLength = 0;

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
  String ex_Command[15];
  String ex_count[15];
  String ex_angle[15];
  String dummy[15];

  int x = 0;
  int beginFrom = 0;
  int asteriskPos = 0;
  String temp;

  while (asteriskPos != -1) {
    //Extracting Substring from String
    asteriskPos = record.indexOf('*', beginFrom + 1); //asteriskPos = 11
    dummy[x] = record.substring(beginFrom + 1, asteriskPos);

    Serial.println(x);
    Serial.print("Substring : ");
    Serial.println(dummy[x]);

    //Extracting Command
    temp = dummy[x];
    ex_Command[x] = temp.substring(0, 1);
    Serial.print("Command : ");
    Serial.println(ex_Command[x]);

    //Extracting Counter
    int hashPos = 0;
    hashPos = temp.indexOf('#');
    ex_count[x] = temp.substring(2, hashPos);
    Serial.print("Counter: ");
    Serial.println(ex_count[x]);

    //Extracting Angle
    ex_angle[x] = temp.substring(hashPos + 1, asteriskPos - 1);
    Serial.print("Angle: ");
    Serial.println(ex_angle[x]);
    Serial.println("");

    beginFrom = asteriskPos;
    arrayLength++;
    x++;
    if (asteriskPos == -1) {
      Serial.println(arrayLength);
      for (int k = arrayLength - 2; k >= 0; k--) {
        Serial.println(k);
        Serial.print("Substring : ");
        Serial.println(dummy[k]);
        /*---------------------------*/
        Serial.print("Command : ");
        Serial.println(ex_Command[k]);
        /*---------------------------*/
        Serial.print("Counter: ");
        Serial.println(ex_count[k]);
        /*---------------------------*/
        Serial.print("Angle: ");
        Serial.println(ex_angle[k]);
        Serial.println("");
      }
    }
  }
  record = "";
}
