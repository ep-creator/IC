int botao = 0;
int estado_atual = 0;
int estado_anterior = 0;

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(2, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{
    estado_atual = digitalRead(2);
    if (estado_atual != estado_anterior)
    {
        if (estado_atual == LOW)
        {
            botao++;
        }
    }
    estado_anterior = estado_atual;
    if (botao >= 16)
    {
        botao = 0;
    }
    int botaobox = botao;

    if (botaobox >= 8)
    {
        digitalWrite(13, HIGH);
        botaobox -= 8;
    }
    else
    {
        digitalWrite(13, LOW);
    }

    if (botaobox >= 4)
    {
        digitalWrite(12, HIGH);
        botaobox -= 4;
    }
    else
    {
        digitalWrite(12, LOW);
    }

    if (botaobox >= 2)
    {
        digitalWrite(11, HIGH);
        botaobox -= 2;
    }
    else
    {
        digitalWrite(11, LOW);
    }

    if (botaobox >= 1)
    {
        digitalWrite(10, HIGH);
        botaobox -= 1;
    }
    else
    {
        digitalWrite(10, LOW);
    }

    Serial.println(botao);
}