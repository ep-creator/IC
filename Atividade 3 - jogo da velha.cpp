// C++ code
//

int led1r = 2;
bool trava1r = false;
int led2r = 3;
int led3r = 4;
int led4y = 5;
int led5y = 6;
int led6y = 7;
int led7g = 8;
int led8g = 9;
int led9g = 10;
int btn = 11;

void piscarLed(int pino, int vezes, int duracao);
void resenhaLed(int min, int max);

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
    pinMode(btn, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // checa se o botao ta pressionado
    bool press = (digitalRead(btn) == HIGH);

    // recebe o valor do potenciometro
    int potenciometro = analogRead(A0);

    resenhaLed(press, potenciometro, -1, 113);
    // faz cada led piscar de acordo com o potenciometro
    // if ((potenciometro < 113) and (trava1r == false)) {
    // piscarLed(led1r, 250);
    // Serial.println("pisca");
    //}
    // if ((potenciometro < 113) and (trava1r == true)) {
    // digitalWrite(led1r, HIGH);
    //}
    // if ((potenciometro < 113) and (press == true)) {
    // trava1r = true;
    //}

    if (potenciometro > 113 and potenciometro < 226)
    {
        piscarLed(led2r, 250);
    }
    if (potenciometro > 226 and potenciometro < 339)
    {
        piscarLed(led3r, 250);
    }
    if (potenciometro > 339 and potenciometro < 452)
    {
        piscarLed(led4y, 250);
    }
    if (potenciometro > 452 and potenciometro < 562)
    {
        piscarLed(led5y, 250);
    }
    if (potenciometro > 562 and potenciometro < 678)
    {
        piscarLed(led6y, 250);
    }
    if (potenciometro > 678 and potenciometro < 791)
    {
        piscarLed(led7g, 250);
    }
    if (potenciometro > 791 and potenciometro < 904)
    {
        piscarLed(led8g, 250);
    }
    if (potenciometro > 904)
    {
        piscarLed(led9g, 250);
    }
}

// Pisca o led selecionado pelo potênciometro
void piscarLed(int pino, int duracao)
{
    digitalWrite(pino, HIGH);
    delay(duracao);
    digitalWrite(pino, LOW);
    delay(duracao);
}

void resenhaLed(bool press, int pot, int min, int max)
{
    if ((pot > min) and (pot < max) and (trava1r == false))
    {
        piscarLed(led1r, 250);
    }
    if ((pot > min) and (pot < max) and (trava1r == true))
    {
        digitalWrite(led1r, HIGH);
    }
    if ((pot > min) and (pot < max) and (press == true))
    {
        trava1r = true;
    }
}
