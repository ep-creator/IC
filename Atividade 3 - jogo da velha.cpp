// C++ code
//

int led1r = 2;
bool trava1r = false;
int led2r = 3;
bool trava2r = false;
int led3r = 4;
bool trava3r = false;
int led4y = 5;
bool trava4y = false;
int led5y = 6;
bool trava5y = false;
int led6y = 7;
bool trava6y = false;
int led7g = 8;
bool trava7g = false;
int led8g = 9;
bool trava8g = false;
int led9g = 10;
bool trava9g = false;
int btn = 11;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(led1r, OUTPUT);
    pinMode(led2r, OUTPUT);
    pinMode(led3r, OUTPUT);
    pinMode(led4y, OUTPUT);
    pinMode(led5y, OUTPUT);
    pinMode(led6y, OUTPUT);
    pinMode(led7g, OUTPUT);
    pinMode(led8g, OUTPUT);
    pinMode(led9g, OUTPUT);
    pinMode(btn, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{
    // checa se o botao ta pressionado
    bool press = (digitalRead(btn) == LOW);

    // recebe o valor do potenciometro
    int potenciometro = analogRead(A0);

    // resenha dos leds
    resenhaLed(trava1r, led1r, press, potenciometro, 0, 113);
    resenhaLed(trava2r, led2r, press, potenciometro, 113, 226);
    resenhaLed(trava3r, led3r, press, potenciometro, 226, 339);
    resenhaLed(trava4y, led4y, press, potenciometro, 339, 452);
    resenhaLed(trava5y, led5y, press, potenciometro, 452, 562);
    resenhaLed(trava6y, led6y, press, potenciometro, 562, 678);
    resenhaLed(trava7g, led7g, press, potenciometro, 678, 791);
    resenhaLed(trava8g, led8g, press, potenciometro, 791, 904);
    resenhaLed(trava9g, led9g, press, potenciometro, 904, 1024);

    linha(trava1r, trava2r, trava3r);
    linha(trava4y, trava5y, trava6y);
    linha(trava7g, trava8g, trava9g);
    linha(trava1r, trava4y, trava7g);
    linha(trava2r, trava5y, trava8g);
    linha(trava3r, trava6y, trava9g);
    linha(trava1r, trava5y, trava9g);
    linha(trava3r, trava5y, trava7g);
}

// Pisca o led selecionado pelo potênciometro
void piscarLed(int pino, int duracao)
{
    digitalWrite(pino, HIGH);
    delay(duracao);
    digitalWrite(pino, LOW);
    delay(duracao);
}

void resenhaLed(bool &trava, int led, bool press, int pot, int min, int max)
{
    if ((pot >= min) and (pot < max) and (trava == false))
    {
        piscarLed(led, 250);
    }
    if (trava == true)
    {
        digitalWrite(led, HIGH);
    }
    else
    {
        digitalWrite(led, LOW);
    }
    if ((pot >= min) and (pot < max) and (press == true))
    {
        trava = true;
    }
}

void linha(bool a, bool b, bool c)
{
    if (((a and b) and c) == true)
    {
        trava1r = false;
        trava2r = false;
        trava3r = false;
        trava4y = false;
        trava5y = false;
        trava6y = false;
        trava7g = false;
        trava8g = false;
        trava9g = false;
    }
}