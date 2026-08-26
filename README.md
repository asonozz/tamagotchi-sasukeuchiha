# 🐍 Sasuke Uchiha — Virtual Pet

<div align="center">

> *“Meu objetivo não é ser um Hokage. Tenho uma ambição que não posso abandonar.”*

**Um pequeno Tamagotchi inspirado no Sasuke Uchiha, feito com Arduino.**

</div>

---

## 📸 O projeto

<div align="center">

<img src="images/sasuke.jpg" width="70%">

<br><br>

<img src="images/circuito.jpg" width="45%">
<img src="images/oled.jpg" width="45%">

</div>

---

## 🖥️ Sobre

O **Sasuke Uchiha Virtual Pet** é um pequeno bichinho virtual desenvolvido com Arduino.

Ele possui diferentes estados, reage aos botões, mostra expressões no display OLED e emite sons diferentes de acordo com o seu estado.

A ideia foi transformar componentes simples em um pequeno Tamagotchi inspirado em um dos personagens mais conhecidos de Naruto.

## 🧠 Estados

O Sasuke possui quatro estados diferentes:

| Estado        | O que acontece                |
| ------------- | ----------------------------- |
| 😌 `FELIZ`    | Sasuke está tranquilo         |
| 🍜 `COM_FOME` | Sasuke precisa ser alimentado |
| 🌙 `DORMINDO` | Sasuke está descansando       |
| 😔 `TRISTE`   | Sasuke quer brincar           |

Cada estado possui um bitmap próprio no display OLED e um som correspondente no buzzer.

---

## 🎮 Controles

| Botão        | Função                      |
| ------------ | --------------------------- |
| 🍜 Alimentar | Alimenta o Sasuke           |
| 🎮 Brincar   | Brinca com o Sasuke         |
| 🌙 Dormir    | Coloca o Sasuke para dormir |

Quando está dormindo, o Sasuke pode ser acordado pressionando **Alimentar** ou **Brincar**.

---

## ⚡ Funcionamento

O Sasuke começa no estado:

`FELIZ`

Depois de algum tempo sem interação:

`FELIZ` → `COM_FOME`

Se continuar sem receber atenção:

`COM_FOME` → `TRISTE`

O jogador pode interagir com ele para recuperar seu estado feliz.

Enquanto isso, o botão de dormir pode colocar o Sasuke para descansar a qualquer momento.

---

## 🔊 Sons

O buzzer possui um som diferente para cada estado:

* `FELIZ` → 1 bip curto
* `COM_FOME` → 2 bips curtos
* `TRISTE` → 3 bips curtos
* `DORMINDO` → 1 bip longo

---

## 🔧 Componentes

* Arduino
* Display OLED 128×64
* 3 botões
* Buzzer ativo
* Protoboard
* Jumpers

---

## 📁 Estrutura

```text
virtual-pet-arduino/
│
├── images/
│   ├── sasuke.jpg
│   ├── circuito.jpg
│   └── oled.jpg
│
├── Sasuke-Uchiha.ino
├── bitmaps.h
└── README.md
```

### Arquivos

`Sasuke-Uchiha.ino`
Código principal responsável pelo funcionamento do Tamagotchi.

`bitmaps.h`
Contém os desenhos dos diferentes estados do Sasuke.

`images/`
Fotos do projeto e do circuito.

---

## 🛠️ Tecnologias

* **Arduino**
* **C++**
* **I2C**
* **OLED SSD1306**
* **Adafruit GFX**
* **Adafruit SSD1306**

---

## 🌱 O que pratiquei

Com esse projeto, pude praticar:

* Controle de entradas digitais
* Uso de `INPUT_PULLUP`
* Controle de estados
* Uso de `millis()`
* Comunicação I2C
* Display OLED
* Bitmaps
* Buzzer
* Organização de um projeto Arduino

---

## 🐍 Sasuke Status

<div align="center">

**Name:** Sasuke Uchiha
**Clan:** Uchiha
**Status:** `ONLINE`
**Mood:** `depends on you`

<br>

*Don't let the Uchiha get sad.*

</div>

---

<div align="center">

### Made with Arduino, code and a little bit of Uchiha energy.

⭐ If you liked the project, consider leaving a star.

</div>
