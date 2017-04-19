#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
	Serial.begin(115200);
	irrecv.enableIRIn(); // Start the receiver
}

void loop() {
	if (irrecv.decode(&results)) {
		Serial.println(results.value);
		irrecv.resume(); // Receive the next value
	}
}


16716015 <<
16734885 >>
