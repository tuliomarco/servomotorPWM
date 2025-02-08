# Tarefa Aula 06/02: Controle de Servomotor com PWM

## Descrição do Projeto
Este projeto utiliza o microcontrolador **RP2040** para controlar a posição de um **servomotor** utilizando PWM. A posição do braço do servomotor é ajustada de acordo com valores de **ciclo ativo (duty cycle)** para representar diferentes ângulos, além de permitir movimentos suaves e periódicos entre a posição inicial (0º) e a posição final (180º).

### Componentes Utilizados
- **Raspberry Pi Pico (RP2040)**
- **Servomotor** - Controlado pela GPIO 22 (PWM)
- **LED RGB** - GPIO 13 (Utilizado para o experimento no BitDogLab, portanto, opcional)

## Funcionalidades do Projeto
### 1. Configuração da Frequência de PWM
- A **frequência de PWM** é configurada para **50 Hz**, o que gera um **período de 20 ms**.

### 2. Controle do Ciclo Ativo para Angulação
- O **ciclo ativo (duty cycle)** do PWM é ajustado para **12%** (aproximadamente 180º), **7,35%** (aproximadamente 90º), e **2,5%** (aproximadamente 0º).
- Após cada ajuste de ciclo ativo, o servomotor aguarda **5 segundos** na posição definida.

### 3. Movimentação Suave e Periódica
- O **braço do servomotor** realiza movimentos suaves entre os ângulos de **0º** e **180º**, com um incremento de **0.025%** no ciclo ativo a cada **10 ms**.

### 4. Experimento com LED RGB
- Utilizando o **BitDogLab**, é realizado um experimento com o **LED RGB** na GPIO 13, observando o comportamento da iluminação durante a execução do código PWM ao atualizar o valor do PWM_SRV_MTR. Também possível observar na simulação com o Wokwi.

## Como Executar o Projeto
1. Compile o código no Raspberry Pi Pico utilizando o **CMakeLists.txt**.
2. Monte o circuito com os componentes necessários no **Wokwi** e veja a simulação com a extensão integrada ao **VS Code**.
3. O servomotor será ajustado para as posições de **0º**, **90º** e **180º**, aguardando 5 segundos em cada posição.
4. A movimentação suave do braço entre 0º e 180º será observada após os ajustes.
5. No experimento do **BitDogLab**, o comportamento do **LED RGB** será monitorado.
