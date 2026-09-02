# 🐍 Sasuke Uchiha — Devlog

> *A small virtual pet, built one step at a time.*

Este é o diário de desenvolvimento do **Sasuke Uchiha**, um Tamagotchi feito com Arduino.

Aqui ficam registradas as atualizações, testes, descobertas, ideias e mudanças que acontecem durante o desenvolvimento.

O README apresenta o projeto.
Este aqui conta a história de como ele está sendo construído.

---

## 📖 Development Log

### `02.09.2026` — Atualizando o Tamagotchi do Sasuke

Depois de mexer um pouco no código, o Tamagotchi do Sasuke recebeu algumas mudanças bem legais.

Na versão antiga, ele tinha quatro estados: **Feliz, Com Fome, Triste e Dormindo**.

Agora entrou mais um:

**Com Raiva. 😡**

A sequência ficou:

**Feliz → Com Fome → Triste → Com Raiva**

Cada mudança acontece depois de 10 segundos caso o jogador não interaja com ele. Então, se ninguém cuidar do Sasuke, ele vai ficando cada vez mais irritado KKKKK.

### 😡 Novo estado: COM_RAIVA

A principal novidade foi adicionar o `COM_RAIVA`.

Além do novo bitmap, ele também ganhou um som próprio. Quando o Sasuke fica com raiva, o buzzer faz **5 bips rápidos**.

Para acalmar o Sasuke, basta interagir com ele através dos botões.

### 🖥️ Código mais organizado

Também aproveitei a atualização para dar uma organizada no código.

Antes, a parte responsável por atualizar o display ficava diretamente dentro do `loop()`.

Agora existe uma função própria:

```cpp
atualizarTela()
```

Ela fica responsável por mostrar o bitmap correspondente ao estado atual.

Também atualizei os nomes dos bitmaps para deixar mais claro que eles pertencem ao Sasuke:

```text
bitmapSasukeFeliz
bitmapSasukeComFome
bitmapSasukeTriste
bitmapSasukeDormindo
bitmapSasukeRaiva
```

Outra melhoria foi fazer com que o display só seja atualizado quando o estado realmente muda, em vez de redesenhar a mesma imagem o tempo todo.

### 🔊 Sons

Cada estado possui uma resposta diferente do buzzer:

* 😄 Feliz → 1 bip
* 🍜 Com fome → 2 bips
* 😢 Triste → 3 bips
* 😡 Com raiva → 5 bips rápidos
* 😴 Dormindo → 1 bip longo

Assim, além de ver o que está acontecendo no OLED, também dá para perceber as mudanças pelos sons.

### 🔧 Pequenas melhorias

Também mudei o botão de brincar do **pino 7 para o pino 3**.

Outra mudança foi adicionar uma verificação na inicialização do OLED. Se o display não conseguir iniciar, o Arduino avisa pelo Serial Monitor.

Pequenas coisas, mas que deixam o projeto um pouco mais organizado e fácil de testar.

---

## 🔋 Funcionando com bateria

O Sasuke também ganhou uma mudança importante no hardware: **agora ele pode ser alimentado por bateria**.

Antes, o Tamagotchi dependia da conexão com o PC para funcionar. Agora ele pode funcionar de forma independente, sem precisar ficar preso ao cabo USB.

Isso é importante principalmente pensando nos próximos passos do projeto.

E por falar nisso...

### 👀 Bluetooth entrou para a conversa

Com o projeto funcionando de forma mais independente, começou a surgir uma ideia:

**e se o Sasuke pudesse conversar com outros dispositivos?**

A próxima grande etapa é explorar a comunicação via **Bluetooth**, permitindo que o Tamagotchi possa futuramente se comunicar com um celular ou computador.

A ideia é, aos poucos, levar o projeto para algo mais próximo de um pequeno sistema IoT.

Ainda não chegamos lá, mas o terreno já está sendo preparado.

---

### `28.08.2026` — A ideia do Bluetooth

Antes mesmo de começar a implementação, o Bluetooth já tinha entrado nos planos do projeto.

A ideia inicial é fazer com que o Sasuke consiga se comunicar com o mundo externo, podendo futuramente enviar informações para uma aplicação web ou mobile.

Algo nessa direção:

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

Ainda estamos descobrindo qual será a melhor forma de fazer essa comunicação e o que realmente vale a pena adicionar.

Por enquanto:

**fazer o Sasuke falar com algo além do próprio OLED.**

---

## 🧪 Experiments

Nem tudo que aparece aqui necessariamente vai parar na versão final.

Esta seção serve para guardar ideias, testes e coisas que queremos experimentar:

* Bluetooth
* Comunicação com celular
* Dashboard para acompanhar o Sasuke
* Notificações
* Interação remota
* Novos sensores
* Novas animações
* Novos estados

Algumas ideias vão funcionar.

Outras provavelmente vão dar errado.

As duas coisas fazem parte do processo. KKKKK.

---

## 🧠 Things We Learned

Até agora, o projeto ajudou a colocar em prática coisas como:

* trabalhar com displays OLED;
* utilizar comunicação I2C;
* criar e utilizar bitmaps;
* trabalhar com botões e entradas digitais;
* utilizar estados no Arduino;
* controlar eventos através de tempo;
* organizar o projeto em diferentes arquivos;
* integrar hardware e software;
* transformar uma ideia em um protótipo físico.

E a próxima lição provavelmente vai ser:

**fazer dois dispositivos conversarem. 👀**

---

## 🗺️ Roadmap

### `✓` Base do Tamagotchi

### `✓` Display OLED

### `✓` Sistema de estados

### `✓` Interações

### `✓` Bitmaps

### `✓` Alimentação por bateria

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

Começou como uma ideia, virou código, depois virou circuito e, aos poucos, começou a parecer com um pequeno personagem de verdade.

Este diário existe para guardar justamente essa evolução.

Não só o resultado final.

**Mas tudo que aconteceu até chegar nele.**

<p align="center">

`made with Arduino, curiosity and a lot of debugging`

</p>
