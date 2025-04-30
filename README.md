# Processamento Digital de Sinais

Este repositório contém alguns dos projetos desenvolvidos durante a disciplina de **Processamento Digital de Sinais (PDS)**, bem como estudos e pesquisas pessoais relacionados ao tema.

---

## 🎯 Projeto Final

Para o projeto final, foi pensado em empregar um dos conceitos trabalhados ao longo da disciplina em **hardware**. Sendo assim, este projeto implementa um **filtro passa-baixa de Resposta Infinita ao Impulso (IIR)** para filtrar a **primeira componente harmônica** de uma **onda quadrada**.

O hardware escolhido foi um **ESP32**, dado que ele possui conversores **Analógico-Digital (AD)** e **Digital-Analógico (DA)** integrados. Um **Arduino UNO** foi utilizado para gerar uma **onda quadrada de 60 Hz**, como apresentado na imagem abaixo:

<div align="center">
  <img src="img/Square_wave.jpg" alt="Onda Quadrada" width="400"/>
</div>

O ESP32 realiza a **amostragem do sinal** gerado pelo Arduino por meio de seu conversor AD. Em seguida, o sinal é **processado digitalmente** no próprio microcontrolador utilizando um **filtro IIR**. Por fim, o **conversor DA** é utilizado para obter a **primeira componente harmônica** do sinal de entrada, ou seja, uma **onda senoidal de 60 Hz**:

<div align="center">
  <img src="img/1Harmonica.jpg" alt="Primeira Harmônica" width="400"/>
</div>

## 📺 Assista ao vídeo do sistema em funcionamento:

<div align="center">
  <a href="https://youtu.be/E689NTvVX8Q">
    <img src="https://img.youtube.com/vi/E689NTvVX8Q/0.jpg" alt="Vídeo do projeto" width="400"/>
  </a>
  <br/>
  <a href="https://youtu.be/E689NTvVX8Q">https://youtu.be/E689NTvVX8Q</a>
</div>
