# Test Plan and Output

### Simulation SetUp

![Simulation_setup](https://user-images.githubusercontent.com/47130828/157218410-4c49a526-f8de-4add-a669-a8613e0bf3fe.PNG)

### Simulation Output (When distance is greater than threshold water level)

![Simulation_Output1](https://user-images.githubusercontent.com/47130828/157218953-7fbeda38-9a0a-47b5-abf5-d95fa585d27e.PNG)

- The Threshold distance from water level is set to 10cm and here we can see that the out put is 75cm.
- And hence the gate is closed, led is off and the buzzer is off. 

### Simulation Output (When distance is less than threshold water level)

![Simulation_Output2](https://user-images.githubusercontent.com/47130828/157219884-93b645b9-d8ad-45aa-9422-5043b84f4bfb.PNG)

- Now distance of water level is less than 10cm.
- And hence the gate is open, led is on and the buzzer is also on.

### Low level requirments:

|    ID       |             Description                            | Expected o/p | Actual o/p |
|:-----------:|:--------------------------------------------------:|:------------:|:----------:|
| LR01_HR01   | Sensor has to transmit signal and detect it back   |   pass       |  pass      |
| LR02_HR01   | Calculate the distance from water level            | Distance     |  Distance  |
| LR03_HR02   | Make decision weather to close or open the gate    | open/close   | open/close |
| LR04_HR03   | Buzzer and Blink LED when the gate is opened       |   On/Off     |   On/Off   |