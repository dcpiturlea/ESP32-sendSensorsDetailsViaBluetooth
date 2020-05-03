# ESP32-sendSensorsDetailsViaBluetooth

Proiectul a fost conceput pentru a usura primirea anumitor date trimise de microcontrollerul ESP32.
Hardware:

1. Microcontroller ESP32
2. Senzor de umiditate si temperatura DHT22
3. Senzor calitatea aerului MQ-32

Workflow:
Microcontrollerul are conectati cei doi senzori amintiti mai sus care capteaza din aer mai multe informatii pe care apoi le trimite catre controller.
Microcontrollerul dispune de bluetooth LE, drept urmare prin folosirea unei biblioteci specifice se poate conecta cu un device compatibil.
Dupa conectare acesta trimite prin metode specifice mai multe informatii catre device-ul imperecheat.

Exemplu:
Dupa legarea senzorilor conform schitei si programarea microcontrollerului, vom descarca o aplicatie bluetoohTerminal pe telefonul android.
Ex Aplicatie: Serial Bluetooth Terminal(https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=ro)
Dupa conectarea telefonului la aparat(microcontroller), se deschide aplicatia SBT, se acceseaza meniul device, se alege device-ul.
Imediat dupa conectare in terminal vor aparea scrise toate detaliile trimise de aparat.

Pentru exemplificare se pot vedea fotografia si videoclipul atasate proiectului.
