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

# `02.09.2026` - Atualizando o Tamagotchi do Sasuke

Depois de mexer um pouco no código, o Tamagotchi do Sasuke recebeu algumas mudanças bem legais.

Na versão antiga, ele tinha só 4 estados: **Feliz, Com Fome, Triste e Dormindo**. A ideia era que, com o passar do tempo, ele fosse ficando cada vez pior caso o jogador não interagisse com ele.

Agora coloquei mais um estado: **Com Raiva** 😡

A sequência ficou:

**Feliz → Com Fome → Triste → Com Raiva**

Cada estado demora 10 segundos para passar para o próximo. Então, se ninguém cuidar dele, eventualmente o Sasuke fica com raiva KKKKK.

### 😡 Novo estado de raiva

A principal mudança foi justamente adicionar o `COM_RAIVA`.

Além do novo bitmap, também fiz um som diferente para ele. Agora, quando entra nesse estado, o buzzer faz **5 bips rápidos**, enquanto os outros estados continuam tendo seus próprios sons.

E para acalmar o Sasuke, é só apertar **alimentar ou brincar**, que ele volta a ficar feliz.

### 🖥️ Dei uma organizada no código

Também aproveitei a atualização para organizar um pouco melhor o código.

Antes, a parte que desenhava os bitmaps ficava diretamente dentro do `loop()`. Agora criei uma função chamada `atualizarTela()`, que fica responsável por mostrar o desenho certo de acordo com o estado atual.

Também troquei os nomes dos bitmaps para ficar mais fácil de entender que são os desenhos do Sasuke:

`bitmapSasukeFeliz`
`bitmapSasukeComFome`
`bitmapSasukeTriste`
`bitmapSasukeDormindo`
`bitmapSasukeRaiva`

🔋 Agora ele também funciona com bateria

Outra mudança que fizemos foi colocar uma bateria no projeto.

Antes, o Tamagotchi precisava ficar conectado ao PC para funcionar. Agora ele consegue ser alimentado pela bateria, então não ficamos mais presos ao cabo USB.

Isso também abre caminho para uma próxima atualização que queremos fazer: Bluetooth 👀

A ideia é que, no futuro, o Tamagotchi consiga se comunicar sem precisar estar conectado diretamente ao computador. Então essa mudança da bateria acaba sendo um dos primeiros passos para deixar o projeto realmente mais independente.

Ainda não chegamos no Bluetooth, mas já estamos preparando o terreno. 🚀

### 🔊 Sons

Cada estado tem um som diferente:

* 😄 Feliz → 1 bip
* 🍜 Com fome → 2 bips
* 😢 Triste → 3 bips
* 😡 Com raiva → 5 bips rápidos
* 😴 Dormindo → 1 bip longo

Assim dá até pra saber que o estado mudou sem precisar ficar olhando o display.

### ⚙️ Outra mudança importante

Também mudei o botão de brincar do **pino 7 para o pino 3**.

E coloquei uma verificação na inicialização do OLED. Se o display não iniciar corretamente, ele avisa no Serial Monitor em vez de simplesmente ficar sem funcionar e eu ficar tentando descobrir o que aconteceu KKKKK.

Outra coisa que mudou foi a atualização da tela. Antes ela era redesenhada toda hora dentro do `loop()`. Agora só atualizo o display quando o estado realmente muda.

No geral, a ideia continua a mesma, mas agora o Sasuke tem mais personalidade e o código ficou um pouco mais organizado.

E obviamente a maior preocupação agora é:

**não deixar o Sasuke ficar com raiva. 😭**


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
