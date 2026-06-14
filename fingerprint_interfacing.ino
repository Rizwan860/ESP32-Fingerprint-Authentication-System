#include <Adafruit_Fingerprint.h>

HardwareSerial mySerial(2);   // UART2

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define GREEN_LED 13
#define RED_LED   12

void setup()
{
  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // RX = GPIO16, TX = GPIO17
  mySerial.begin(57600, SERIAL_8N1, 16, 17);

  finger.begin(57600);

  if (finger.verifyPassword())
  {
    Serial.println("Fingerprint Sensor Found!");
  }
  else
  {
    Serial.println("Fingerprint Sensor Not Found!");
    while (1);
  }
}

void loop()
{
  int id = getFingerprintID();

  if (id > 0)
  {
    Serial.print("Match Found! ID = ");
    Serial.println(id);

    digitalWrite(GREEN_LED, HIGH);
    delay(2000);
    digitalWrite(GREEN_LED, LOW);
  }

  delay(100);
}

int getFingerprintID()
{
  uint8_t p = finger.getImage();

  if (p != FINGERPRINT_OK)
    return -1;

  p = finger.image2Tz();

  if (p != FINGERPRINT_OK)
    return -1;

  p = finger.fingerFastSearch();

  if (p == FINGERPRINT_OK)
  {
    return finger.fingerID;
  }
  else
  {
    Serial.println("No Match Found");

    digitalWrite(RED_LED, HIGH);
    delay(2000);
    digitalWrite(RED_LED, LOW);

    return -1;
  }
}