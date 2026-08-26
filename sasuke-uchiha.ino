// Bibliotecas para comunicação I2C e display OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Biblioteca com os bitmaps do bichinho (rostos)
// Você deve ter seu arquivo bitmaps.h com os desenhos
#include "bitmaps.h"

// Define as dimensões do display OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Cria objeto display com as dimensões e endereço padrão (0x3C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define os pinos dos botões
#define BOTAO_ALIMENTAR 2
#define BOTAO_BRINCAR 7
#define BOTAO_DORMIR 4

// Define o pino do buzzer ativo
#define BUZZER_PIN 6

// Enum para representar os estados possíveis do bichinho
enum EstadoBichinho {
  FELIZ,
  COM_FOME,
  DORMINDO,
  TRISTE
};

// Variáveis para guardar o estado atual e anterior
EstadoBichinho estadoAtual = FELIZ;
EstadoBichinho estadoAnterior = FELIZ;

// Variáveis de tempo para controlar mudança de estado
unsigned long ultimoTempoEstado = 0;
const unsigned long intervaloFome = 10000;    // 10s para mudar para COM_FOME
const unsigned long intervaloTriste = 10000;  // 10s para mudar para TRISTE

// Função para tocar som diferente para cada estado
// Como usa buzzer ativo, diferencia pelo número de bips e duração
void tocarSom(EstadoBichinho estado) {
  switch(estado) {
    case FELIZ:
      // 1 bip curto
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case COM_FOME:
      // 2 bips curtos
      for(int i=0; i<2; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(150);
        digitalWrite(BUZZER_PIN, LOW);
        delay(100);
      }
      break;

    case TRISTE:
      // 3 bips curtos
      for(int i=0; i<3; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(150);
        digitalWrite(BUZZER_PIN, LOW);
        delay(100);
      }
      break;

    case DORMINDO:
      // 1 bip longo
      digitalWrite(BUZZER_PIN, HIGH);
      delay(600);
      digitalWrite(BUZZER_PIN, LOW);
      break;
  }
}

void setup() {
  // Inicializa comunicação serial para debug
  Serial.begin(9600);

  // Inicializa comunicação I2C
  Wire.begin();

  // Inicializa display OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Configura pinos dos botões como entrada com pull-up interno
  pinMode(BOTAO_ALIMENTAR, INPUT_PULLUP);
  pinMode(BOTAO_BRINCAR, INPUT_PULLUP);
  pinMode(BOTAO_DORMIR, INPUT_PULLUP);

  // Configura pino do buzzer como saída e inicia desligado
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Inicializa estados
  estadoAtual = FELIZ;
  estadoAnterior = FELIZ;
  ultimoTempoEstado = millis();

  Serial.println("Estado inicial: FELIZ");

  // Toca som inicial
  tocarSom(estadoAtual);
}

void loop() {
  unsigned long tempoAtual = millis();

  // Leitura dos botões (invertida pois usa INPUT_PULLUP)
  bool botaoAlimentar = (digitalRead(BOTAO_ALIMENTAR) == LOW);
  bool botaoBrincar = (digitalRead(BOTAO_BRINCAR) == LOW);
  bool botaoDormir = (digitalRead(BOTAO_DORMIR) == LOW);

  // Se apertar botão dormir, entra em DORMINDO
  if(botaoDormir) {
    if(estadoAtual != DORMINDO) {
      estadoAtual = DORMINDO;
      Serial.println("Entrou no estado: DORMINDO");
      ultimoTempoEstado = tempoAtual;
    }
  }
  // Se está dormindo e apertar ALIMENTAR ou BRINCAR, acorda e volta para FELIZ
  else if(estadoAtual == DORMINDO) {
    if(botaoAlimentar || botaoBrincar) {
      estadoAtual = FELIZ;
      ultimoTempoEstado = tempoAtual;
      Serial.println("Acordou! Estado: FELIZ");
    }
  }
  // Caso contrário, executa lógica normal dos estados
  else {
    static bool jaFoiComFome = false; // controla alternância entre COM_FOME e TRISTE

    switch(estadoAtual) {
      case FELIZ:
        // Se apertar alimentar ou brincar, reinicia o tempo em FELIZ
        if(botaoAlimentar) {
          ultimoTempoEstado = tempoAtual;
          Serial.println("Botão ALIMENTAR pressionado em FELIZ - tempo reiniciado");
        } else if(botaoBrincar) {
          ultimoTempoEstado = tempoAtual;
          Serial.println("Botão BRINCAR pressionado em FELIZ - tempo reiniciado");
        } else {
          // Verifica se é hora de mudar para COM_FOME ou TRISTE
          unsigned long tempoPassado = tempoAtual - ultimoTempoEstado;

          if(!jaFoiComFome && tempoPassado >= intervaloFome) {
            estadoAtual = COM_FOME;
            ultimoTempoEstado = tempoAtual;
            jaFoiComFome = true;
            Serial.println("Mudou para COM_FOME");
          } else if(jaFoiComFome && tempoPassado >= intervaloTriste) {
            estadoAtual = TRISTE;
            ultimoTempoEstado = tempoAtual;
            jaFoiComFome = false;
            Serial.println("Mudou para TRISTE");
          }
        }
        break;

      case COM_FOME:
        // Se apertar ALIMENTAR, volta para FELIZ
        if(botaoAlimentar) {
          estadoAtual = FELIZ;
          ultimoTempoEstado = tempoAtual;
          Serial.println("Alimentado! Voltou para FELIZ");
        }
        break;

      case TRISTE:
        // Se apertar BRINCAR, volta para FELIZ
        if(botaoBrincar) {
          estadoAtual = FELIZ;
          ultimoTempoEstado = tempoAtual;
          Serial.println("Brincado! Voltou para FELIZ");
        }
        break;
    }
  }

  // Se mudou de estado, toca o som correspondente
  if(estadoAtual != estadoAnterior) {
    tocarSom(estadoAtual);
    estadoAnterior = estadoAtual;
  }

  // Atualiza display OLED com bitmap correspondente ao estado
  display.clearDisplay();

  switch(estadoAtual) {
    case FELIZ:
      display.drawBitmap(32, 0, bitmapFeliz, 64, 64, SSD1306_WHITE);
      break;
    case COM_FOME:
      display.drawBitmap(32, 0, bitmapComFome, 64, 64, SSD1306_WHITE);
      break;
    case DORMINDO:
      display.drawBitmap(32, 0, bitmapDormindo, 64, 64, SSD1306_WHITE);
      break;
    case TRISTE:
      display.drawBitmap(32, 0, bitmapTriste, 64, 64, SSD1306_WHITE);
      break;
  }

  display.display();

  delay(200); // pequeno atraso para estabilidade
}
