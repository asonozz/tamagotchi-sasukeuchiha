# 🐍 Sasuke Uchiha — Virtual Pet

> *“Meu objetivo não é ser um Hokage. Tenho uma ambição que não posso abandonar.”*

Um pequeno **Tamagotchi inspirado no Sasuke Uchiha**, desenvolvido com Arduino e um display OLED.

O projeto transforma um Arduino em um bichinho virtual que possui diferentes estados, reage aos botões e emite sons de acordo com seu humor.

## 🖥️ Sobre o projeto

O Sasuke possui quatro estados:

* `FELIZ` — está tranquilo.
* `COM_FOME` — está esperando ser alimentado.
* `DORMINDO` — entrou em modo de descanso.
* `TRISTE` — precisa de atenção e quer brincar.

Cada estado possui uma expressão diferente no display OLED e um som específico emitido pelo buzzer.

## ⚡ Como funciona

O Sasuke fica inicialmente **feliz**.

Com o passar do tempo, suas necessidades começam a mudar:

`FELIZ` → `COM_FOME` → `TRISTE`

Mas ele também pode receber atenção do jogador:

🍜 **Alimentar** → recupera a felicidade quando está com fome
🎮 **Brincar** → recupera a felicidade quando está triste
🌙 **Dormir** → coloca o Sasuke para descansar
☀️ **Alimentar / Brincar** → acorda o Sasuke

Enquanto isso, o display OLED mostra o rosto correspondente ao estado atual.

## 🔧 Componentes

* Arduino
* Display OLED 128×64
* 3 botões
* Buzzer ativo
* Protoboard
* Jumpers

## 🎮 Controles

| Botão     | Ação                        |
| --------- | --------------------------- |
| Alimentar | Alimenta o Sasuke           |
| Brincar   | Brinca com o Sasuke         |
| Dormir    | Coloca o Sasuke para dormir |

## 📺 Display

O projeto utiliza um display **OLED 128×64** através da comunicação I2C.

Os rostos do Sasuke são armazenados como bitmaps e carregados no display de acordo com seu estado.

## 📁 Estrutura

```text
virtual-pet-arduino/
│
├── virtual_pet.ino
├── bitmaps.h
└── README.md
```

`Ssuke-Uchiha.ino` → código principal do Tamagotchi
`bitmaps.h` → desenhos dos diferentes estados do Sasuke
`README.md` → documentação do projeto

## 🧠 Tecnologias

* Arduino
* C++
* I2C
* OLED SSD1306
* Adafruit GFX
* Adafruit SSD1306

## 🌱 Objetivo

Este projeto foi desenvolvido como uma forma prática de aprender e experimentar conceitos de **Arduino, eletrônica e programação**, utilizando estados, entradas de botões, controle de tempo, display gráfico e buzzer.

Pequeno projeto, grande responsabilidade:

> **não deixe o Sasuke ficar triste.**

---

### 🐍 Sasuke Uchiha

Made with Arduino, a little bit of code and questionable amounts of Uchiha energy.

**Status:** `alive`
**Clan:** `Uchiha`
**Mood:** `depends on you`

⭐ If you liked the project, consider leaving a star.
