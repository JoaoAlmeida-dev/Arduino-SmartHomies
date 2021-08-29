#define POL_NUM 24 // number of poles of the characteristic

int port0 = 0;
float resistor = 1000;

int sensTable[POL_NUM][2] = {{-55,490},{-50,515},{-40,567},{-30,624},{-20,684},{-10,747},{0,815},{10,886},{20,961},{25,1000},{30,1040},{40,1122},{50,1209},{60,1299},{70,1392},{80,1490},{90,1591},{100,1696},{110,1805},{120,1915},{125,1970},{130,2023},{140,2124},{150,2211}};

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  float sensorValue = analogRead(port0);
  float resistance = sensorValue / (1023-sensorValue) * resistor;
  float temperature;
  for(int i=1; i<POL_NUM; i++){
    
      if(resistance<sensTable[i][1] && resistance>sensTable[i-1][1]){
    
          int x0 =sensTable[i-1][1];
          int y0 =sensTable[i-1][0];
          
          int x1 =sensTable[i][1];
          int y1 =sensTable[i][0];

          int x = resistance;
          
          temperature = (y0*(x1-x) + y1*(x-x0)) / ( x1-x0);
          Serial.println(temperature);
        }
        
    }

  
  delay(500);

}
