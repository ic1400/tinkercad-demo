#define LED_PIN 13
#define TRIGGER_PIN 4

const int seconds = 1000;

int  msPassed = 0;
bool blinkingMode = true;
bool ledOn = true;

void setup() {
  pinMode( TRIGGER_PIN, INPUT_PULLUP );
  pinMode( LED_PIN, OUTPUT );
  digitalWrite( LED_PIN, LOW );

  Serial.begin( 9600 );
}

void loop() {
  int isPressed = digitalRead( TRIGGER_PIN );

  if ( isPressed == LOW ) {
    digitalWrite( LED_PIN, HIGH );

    return;
  }

  if ( blinkingMode ) {
    Serial.println( "Blinking Mode..." );

    if ( msPassed < ( 6 * seconds ) ) {
      ledOn = !ledOn;
    } else {
      msPassed = 0;
      blinkingMode = false;
    }
  } else {
    Serial.println( "Blinking Mode Turned Off..." );
    ledOn = false;

    if ( msPassed >= ( 3 * seconds ) ) {
      msPassed = 0;
      blinkingMode = true;
    }
  }

  digitalWrite( LED_PIN, ledOn ? HIGH : LOW );

  delay( 500 );
  msPassed += 500;
}