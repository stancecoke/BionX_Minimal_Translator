#ifndef CANregisters_h
#define CANregisters_h

#define CON_ALIVE 495		// wird regelmäßig gesendet, beim Abschalten ändert sich Byte 0 von 128 auf 0, Rest bleibt immer gleich
#define DIS_ALIVE 296		// wird nur zum Ende der Einschaltsequenz gesendet
#define DIS_ASSIST 552		// Byte0 ist die Unterstützungsstufe, wird erst nach der Einschaltprozedur gesendet
#define DIS_SPEED 1007L 		//? Speed x 10, Byte3 LSB, Byte4 MSB, Byte0 Assist Level, Byte2 Error ?!
#define CON_SPEED 751L 		//? Speed x 10, Byte3 LSB, Byte4 MSB, Byte2 Error ?!
#define CON_ODO	1263L 		//Byte0 ODO LSB, Byte1 ODO MSB, Byte3 Trip LSB, Byte4 Trip MSB, Byte 6 ?! Zählt runter
#define CON_UNKOWN_1 1519L 	//??? 230 ... Byte6 springt in Einschaltprozedur von 160 auf 64 Rest bleibt immer gleich
#define CON_STARTUP 1775L	//wird nur beim Start gesendet, Inhalt bleibt immer gleich
#define CON_WHEEL_CIRCUMFERENCE 2031L //Byte 3 LSB, Byte 4 MSB, ?!
#define DIS_STARTUP 62703L	//Wird nur beim Ein- und Ausschalten gesendet. Beim Starten ist Byte0 1, beim Abschalten ist Byte0 2


#endif
