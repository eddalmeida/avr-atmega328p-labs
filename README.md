# AVR ATmega328P Labs

Repositório de estudos práticos com **AVR (ATmega328P)** focado em **programação bare-metal**, **manipulação direta de registradores** e construção de uma base sólida em **sistemas embarcados**.

> Este repositório reúne pequenos projetos e experimentos em C usando **avr-gcc**, **avr-libc**, **Makefile** e **avrdude**, sem dependência de IDE proprietária.

---

## Objetivo

O foco deste repositório é estudar, praticar e consolidar fundamentos importantes de microcontroladores AVR, incluindo:

* Configuração e uso de **GPIO**
* Controle de **LEDs** e **botões**
* Leitura de entradas digitais
* **Debounce**
* Controle de **display de 7 segmentos**
* **Multiplexação**
* Temporização com `_delay_ms()` / `_delay_us()`
* Organização de projetos com **Makefile**
* Fluxo de desenvolvimento com **VS Code + terminal**
* Programação próxima do hardware (**bare-metal / registradores**)

---

## Filosofia do projeto

Este repositório prioriza:

* **Aprendizado de baixo nível**
* **Código simples e legível**
* **Manipulação direta de registradores**
* **Independência de IDE**
* **Estrutura reutilizável para futuros projetos AVR**

A ideia é entender **como o microcontrolador realmente funciona**, em vez de depender de abstrações prontas.

---

## Toolchain utilizada

Ambiente atual de desenvolvimento:

* **Editor:** VS Code
* **Compilador:** `avr-gcc`
* **Bibliotecas:** `avr-libc`
* **Programador / Upload:** `avrdude`
* **Build system:** `Makefile`
* **Plataforma alvo:** **ATmega328P**
* **Sistema operacional:** Linux

---

## Estrutura do repositório

```text
.
├── blink-atmega328p/
├── muxDisplay7seg/
├── .gitattributes
├── .gitignore
└── README.md
```

Cada pasta representa um **projeto/experimento independente**, com seu próprio código-fonte e `Makefile`.

---

## Projetos atuais

### 1. `blink-atmega328p`

Projeto básico para estudo de:

* Configuração de pino como saída
* Escrita em registradores (`DDRx`, `PORTx`)
* Uso de delays
* Estrutura mínima de firmware AVR

### 2. `muxDisplay7seg`

Projeto para estudo de:

* Controle de **display de 7 segmentos com delay(não recomendado)**
* **Multiplexação**
* Leitura de entrada digital
* Organização de código em projeto maior
* Estruturação com `Makefile` próprio

---

## Como compilar

Entre na pasta do projeto desejado e execute:

```bash
cd blink-atmega328p
make
```

Ou:

```bash
cd muxDisplay7seg
make
```

---

## Como gravar no microcontrolador

Se o `Makefile` do projeto já estiver configurado com o programador correto, use:

```bash
make flash
```

---

## Exemplo de fluxo completo

```bash
cd blink-atmega328p
make
make flash
```

---

## Requisitos

Certifique-se de ter instalado no Linux:

* `avr-gcc`
* `avr-libc`
* `avrdude`
* `make`

Exemplo (Debian/Ubuntu):

```bash
sudo apt update
sudo apt install gcc-avr avr-libc avrdude make
```

---

## Boas práticas adotadas

Este repositório busca manter:

* Arquivos de build fora do Git (`.elf`, `.hex`, `.o`, etc.)
* Separação entre projetos
* Configuração compatível com **VS Code**
* Estrutura fácil de expandir
* Versionamento limpo e legível

---

## Próximos estudos / roadmap

Alguns tópicos planejados para evolução do repositório:

* Timers (Timer0 / Timer1 / Timer2)
* Interrupções externas
* PWM
* ADC
* UART
* Máquinas de estado
* Organização modular com `src/` e `include/`
* Drivers reutilizáveis para periféricos simples
* Pequenas bibliotecas bare-metal para AVR

---

## Público-alvo

Este repositório é útil para:

* Estudantes de **Engenharia Elétrica / Eletrônica**
* Quem está começando com **microcontroladores AVR**
* Quem quer aprender **programação bare-metal**
* Quem deseja sair de ambientes fortemente dependentes de IDE
* Quem quer construir base para **sistemas embarcados**

---

## Observações

* O repositório começou a partir de estudos iniciais com ferramentas ligadas ao ecossistema da Microchip, mas atualmente está sendo organizado para um fluxo mais limpo com **VS Code + Makefile + avr-gcc + avrdude**.
* O objetivo é manter os projetos cada vez mais independentes, reproduzíveis e próximos de um fluxo real de desenvolvimento embarcado.

---

## 📚 Base de estudo

Parte dos estudos e exercícios deste repositório é inspirada nos exercicios do livro:

- [**AVR e Arduino: Técnicas de Projeto** — Charles Borges de Lima e Marco V. M. Villaça](https://clubedeautores.com.br/livro/avr-e-arduino-tecnicas-de-projeto)
  
---

## Licença

Este repositório é voltado para fins de estudo e aprendizado.

Se desejar, você pode futuramente adicionar uma licença como:

* MIT
* BSD-3-Clause

---

## Autor

**Edson Almeida**

Estudos em microcontroladores, eletrônica e sistemas embarcados.
