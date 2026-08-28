# 🐍 Sasuke Uchiha — Devlog

> *A small virtual pet, built one step at a time.*

Este é o diário de desenvolvimento do **Sasuke Uchiha**, um Tamagotchi feito com Arduino.

Aqui ficam registradas as atualizações, testes, descobertas, ideias e mudanças que acontecem durante a construção do projeto.

O README principal apresenta o projeto.
Este aqui conta a história de como ele está sendo construído.

---

## 📖 Development Log

### `28.08.2026` — Bluetooth entrou para a conversa

O Sasuke começou como um pequeno Tamagotchi rodando diretamente no Arduino, mas a ideia nunca foi deixar ele parado por aí.

A próxima etapa do projeto é fazer com que ele consiga **se comunicar com o mundo externo**.

A proposta é adicionar comunicação via **Bluetooth**, permitindo que um celular ou computador consiga receber informações sobre o estado do Sasuke e, futuramente, também interagir com ele.

A ideia é transformar o projeto em algo mais próximo de um pequeno sistema IoT:

```text
        ┌──────────────┐
        │    SASUKE    │
        │   Arduino    │
        └──────┬───────┘
               │
           Bluetooth
               │
               ▼
        ┌──────────────┐
        │   Aplicação  │
        │  Web / Mobile│
        └──────────────┘
```

Ainda estamos descobrindo qual será a melhor forma de fazer essa comunicação e quais informações realmente fazem sentido enviar.

Por enquanto, a missão é simples:

**fazer o Sasuke falar com algo além do próprio OLED.**

---

### `Coming soon` — Primeiros testes

> Em breve...

Aqui serão registrados os primeiros testes de comunicação, problemas encontrados, soluções e tudo aquilo que inevitavelmente dá errado antes de funcionar.

Porque, aparentemente, nenhum projeto Arduino começa funcionando de primeira.

---

## 🧪 Experiments

Nem tudo que aparece aqui necessariamente vai parar na versão final.

Esta seção existe para guardar ideias, testes e experiências:

* Bluetooth
* Comunicação com celular
* Dashboard para acompanhar o Sasuke
* Notificações sobre o estado do pet
* Interação remota
* Novos sensores
* Novas animações
* Novos estados
* Melhorias no sistema de necessidades

Algumas ideias vão funcionar.

Outras provavelmente vão explodir.

As duas coisas fazem parte do processo.

---

## 📸 Project Diary

### The beginning

O projeto começou com uma ideia relativamente simples:

> **"E se a gente fizesse um Tamagotchi usando Arduino?"**

Daí vieram o OLED, os botões, o buzzer, os bitmaps e, eventualmente, um Sasuke inteiro vivendo dentro de uma pequena placa.

[📷 adicionar foto aqui]

---

### The first prototype

[📷 adicionar foto do primeiro protótipo]

O primeiro protótipo ainda era bem diferente da versão atual.

Foi aqui que começamos a descobrir como transformar a ideia em algo que realmente pudesse funcionar fisicamente.

---

### Current build

[📷 adicionar foto da versão atual]

O Sasuke atualmente consegue:

* comer
* brincar
* dormir
* mudar de estado
* demonstrar diferentes emoções
* interagir através dos botões
* exibir suas expressões no OLED

E isso é só o começo.

---

## 🧠 Things We Learned

Cada atualização também deixa alguma coisa para trás.

Até agora:

* trabalhar com displays OLED
* utilizar comunicação I2C
* criar e utilizar bitmaps
* controlar entradas através de botões
* trabalhar com estados dentro do Arduino
* organizar um projeto em diferentes arquivos
* transformar uma ideia em um protótipo físico

A próxima lição:

**fazer dois dispositivos conversarem.**

---

## 🗺️ Roadmap

### `✓` Base do Tamagotchi

### `✓` Display OLED

### `✓` Sistema de estados

### `✓` Interações

### `✓` Bitmaps

### `○` Comunicação Bluetooth

### `○` Monitoramento pelo celular

### `○` Notificações

### `○` Interações remotas

### `○` Interface web/app

### `○` Versão final

> *The project is still being built.*

---

## 🐍 About Sasuke

O Sasuke não começou perfeito.

Ele começou como uma ideia, virou código, depois virou circuito e, aos poucos, começou a parecer com um pequeno personagem de verdade.

Este diário existe para guardar justamente essa evolução.

Não só o resultado final.

**Mas tudo que aconteceu até chegar nele.**

---

<p align="center">

`made with Arduino, curiosity and a lot of debugging`

</p>
