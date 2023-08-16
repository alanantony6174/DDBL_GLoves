#include <ThingSpeak.h>
#include <WiFi.h>

WiFiClient x;
String val;

#include <WiFi.h>


const char *ssid = "alans";
const char *password = "34567890";
String url1;

const char* host = "api.thingspeak.com";
const char* streamId   = "662Y3U7TZZBLZBIA";
WiFiClient client;

#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);







//Analog Input
#define APIN_0 36
#define APIN_1 39
#define APIN_2 34
#define APIN_3 35
#define APIN_4 32

int av0 = 0;
int av1 = 0;
int av2 = 0;
int av3 = 0;
int av4 = 0;


void setup() {


  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
 
      lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
    ThingSpeak.begin(x);
}

void loop()
{

 for(int i = 0; i<10 ; i= i+1)
 {
  av0 = av0 + analogRead(APIN_0);
  av1 = av1 + analogRead(APIN_1);
  av2 = av2 + analogRead(APIN_2);
  av3 = av3 + analogRead(APIN_3);
  av4 = av4 + analogRead(APIN_4);
  delay(500);
 }
 av0 = av0/10;
  av1 = av1/10;
   av2 = av2/10;
    av3 = av3/10;
     av4 = av4/10;




//
  Serial.print("A0 = "); Serial.print(av0);
  Serial.print(" | A1 = "); Serial.print(av1);
  Serial.print(" | A2 = "); Serial.print(av2);
  Serial.print(" | A3 = "); Serial.print(av3);
  Serial.print(" | A4 = "); Serial.println(av4);

  lcd.clear();

  if (av0 < 1300 && av1 < 1300 && av2 < 1200 && av3 < 1000 && av4 < 1100)
  {

      url1 = "A";
  //    req(url1);
      Serial.println("A");
      lcd.setCursor(0, 0);
      lcd.print("OCR"); // You can make spaces using well... spaces
    delay(500);
      sendvaluetoserver();
   
    }
    else if (av0 > 1400 && av1 < 1250 && av2 < 1100 && av3 < 950 && av4 < 1100)
    {
      url1 = "B";
   //   req(url1);
   Serial.println("B");
      lcd.setCursor(0, 0);
      lcd.print("Face Rec"); // You can make spaces using well... spaces
    delay(500);
      sendvaluetoserver();
     
    }
    else if (av0 > 1400 && av1 > 1500 && av2 < 1150 && av3 < 950 && av4 < 1150)
    {
      url1 = "C";
      Serial.println("C");
      lcd.setCursor(0, 0);
      lcd.print("S2T"); // You can make spaces using well... spaces
    delay(500);
      sendvaluetoserver();
   
    }
    else if (av0 > 1200 && av1 > 1100 && av2 > 1100 && av3 < 950 && av4 < 1150)
    {
      url1 = "D";
   //   req(url1);
      Serial.println("D");
      lcd.setCursor(0, 0);
      lcd.print("My Name Is Alan"); // You can make spaces using well... spaces
      delay(500);
      sendvaluetoserver();
   
    }
    else if (av0 > 1300 && av1 > 1150 && av2 > 1150 && av3 > 1050 && av4 < 1050)
    {
      url1 = "E";
  //    req(url1);
      Serial.println("E");
          lcd.setCursor(0, 0);
     // lcd.print("direction"); // You can make spaces using well... spaces
    delay(1000);
     // sendvaluetoserver();
 val = ThingSpeak.readStringField(2052308,1,"0WU9G766HF1XP24Q");
 int k= val.length();
 Serial.println(val);
  delay(1000);
  lcd.print(val);
  delay(2000);
    for (int positionCounter = 0; positionCounter < k; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(100);
  }
     
    }
    else if (av0 > 1200 && av1 > 1100 && av2 > 1100 && av3 > 950 && av4 > 950)
    {
      url1 = "S";
   //   req(url1);
      Serial.println("S");
      lcd.setCursor(0, 0);
      lcd.print("stop"); // You can make spaces using well... spaces
      delay(500);
      sendvaluetoserver();
     
    }
    else if (av0 < 1200 && av1 > 1350 && av2 < 1200 && av3 < 1000 && av4 < 1200)
    {
      url1 = "/move?dir=H";
   //   req(url1);
      Serial.println("H");
      lcd.setCursor(0, 0);
      lcd.print("Hello"); // You can make spaces using well... spaces
      delay(500);
      sendvaluetoserver();
      
    }
     else if (av0 < 1100 && av1 > 1400 && av2 > 1300 && av3 < 1000 && av4 < 1300)
    {
      url1 = "/move?dir=G";
   //   req(url1);
      Serial.println("G");
      lcd.setCursor(0, 0);
      lcd.print("Good Morning"); // You can make spaces using well... spaces
      delay(500);
      sendvaluetoserver();
      
    }
    else if (av0 > 1200 && av1 > 1400 && av2 < 1100 && av3 < 1050 && av4 > 1100)
    {
      url1 = "/move?dir=L";
   //   req(url1);
      Serial.println("L");
      lcd.setCursor(0, 0);
      lcd.print("I Love You"); // You can make spaces using well... spaces
      delay(500);
      sendvaluetoserver();
      
    }

  delay(50);
}

void sendvaluetoserver()
{
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }


  // We now create a URI for the request
  String url = "/update?api_key=";
  url += streamId;
  url += "&field1=";
  url += url1;


  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  delay(2000);
}
