// Abschluss Projekt Praxisteil Abstandsmessung Ultraschall mit Display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initialisierung des Displays
LiquidCrystal_I2C lcd(0x27, 16, 2);         //Display mit 16 Zeichen in 2 Zeilen, Busadresse 0x27
// Einführung der Variablen
int trigger=7;                              //Pin "trigger" ist angeschlossen an Pin 7
int echo=6;                                 //Pin "echo" ist angeschlossen an Pin 6
long laufzeit=0;                            //Laufzeit des Schalls, Datentyp long statt int, es können größere Zahlen gespeichert werden
long entfernung=0;                          //Für berechnung der Entfernung, int bereich -2147483648 bis 2147483647 

void setup()
{
  lcd.begin();
   pinMode(trigger, OUTPUT);                //„trigger“(Pin7) ist ein Ausgang.
   pinMode(echo, INPUT);                    //„echo“(Pin6) ist ein Eingang.
}

void loop()
{
  digitalWrite(trigger, LOW);               //Kurz Ausschalten zur Rauschreduzierung
    delay(5);                               //Dauer: 5 Millisekunden
  digitalWrite(trigger, HIGH);              //Ultraschallwelle wird gestartet
    delay(10);                              //Dauer des Aussendens der Welle
  digitalWrite(trigger, LOW);               //Ultraschallwelle wird beendet
 // Berechnung der Laufzeit
  laufzeit = pulseIn(echo, HIGH);           //pulseIn zählt Zeit bis zur detektierung der Reflektion der Schallwelle
  entfernung = (laufzeit/2) / 29.1;         // Berechnung in cm. Schall in Luft hat eine Geschwindigkeit von 29,1 cm pro ms 
                                            // Teilung durch 2 da nur eine Wegstrecke gemessen werden soll
if (entfernung >= 500 || entfernung <= 0)   //Messwertgrenze
  {
    lcd.setCursor(0,1);                     //Setzt Cursor auf die zweite Zeile für das Ergebnis
    lcd.clear();                            //Löscht alle Zeichen vom LCD für klare Anzeige
    lcd.print("Kein Messwert");             //Keine Messung möglich
  }
else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Entfernung");                //Zeigt den Einführungstext in der ersten Zeile an
    lcd.setCursor(0,1);                     //Setzt Cursor auf die zweite Zeile für das Ergebnis
    lcd.print(entfernung);                  //Ausgabe des Messwertes
    lcd.print(" cm");                       //Ausgabe der Einheit hinter dem Messwert
   }
// Hier beginnt die Piepser-Steuerung
if (entfernung < 15 && entfernung >= 10)   //Entfernungswert zwischen 15 und 10 cm
  {
    for (int i = 0; i <= 1; i++)           // Schleife für 2x Piepsen
    {
      pinMode(2,OUTPUT);                  // Pin2 als Output festlegen
      digitalWrite(2,HIGH);               // Piepton einschalten
      delay(100);                         // Piepton 100 ms anhalten
      digitalWrite(2,LOW);                // Piepton ausschalten
      delay(100);                         // Pause 100 ms
    }
  }
if (entfernung < 10 && entfernung >= 5)   //Entfernungswert zwischen 10 und 5 cm
  {
    for (int i = 0; i <= 2; i++)           // Schleife für 3x Piepsen
    {
      pinMode(2,OUTPUT);                  // Pin2 als Output festlegen
      digitalWrite(2,HIGH);               // Piepton einschalten
      delay(100);                         // Piepton 100 ms anhalten
      digitalWrite(2,LOW);                // Piepton ausschalten
      delay(100);                         // Pause 100 ms
    }
  }
 if (entfernung < 5 && entfernung >= 0)   //Entfernungswert zwischen 5 und 0 cm
  {
    for (int i = 1; i <= 5; i++)           // Schleife für 5x Piepsen
    {
      pinMode(2,OUTPUT);                  // Pin2 als Output festlegen
      digitalWrite(2,HIGH);               // Piepton einschalten
      delay(100);                         // Piepton 100 ms anhalten
      digitalWrite(2,LOW);                // Piepton ausschalten
      delay(100);                         // Pause 100 ms
    }
  }
delay(1000);                               //Pause für 1 Sekunde zur Stabilität
}
