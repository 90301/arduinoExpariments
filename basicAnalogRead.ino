void setup() {
  //initialize serial to comunicate 9600 bits/sec
  Serial.begin(9600);
}
  int myValues[1000];
  int myTimes[1000];
  int i = 0;
  int time = 1;
  int tolerance = 5;
  
//basic function already implemented
//runs over and over again forever
void loop() {
  time++;
  //read from analog port A0
  int sensorValue=analogRead(A0);
  Serial.println(sensorValue);
  //myValues[i] = sensorValue;
  //i=i+1;
  if (checkValues(sensorValue)) {
    myValuesAdd(sensorValue,time);
  }
  outputData();
  delay(2000);
  
}
void myValuesAdd(int value,int time) {
  myValues[i]=value;
  myTimes[i]=time;
  i++;
}
boolean checkValues(int value) {
 if (value>myValues[i-1]+tolerance || value<myValues[i-1]-tolerance) {
  return true; 
 } else {
  return false; 
 }
}
void outputData() {
  Serial.println("START OF DATA:--------------");
   for (int e=0;e<i;e++) {
    Serial.print(myValues[e]);
    Serial.print(" Time: ");
    Serial.print(myTimes[e]);
    Serial.println(" ");
  } 
}
