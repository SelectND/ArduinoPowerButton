# Arduino Power Button
## Attention: Only do this if you know what you're doing! I won't be responsible for any damage caused by this piece of software! Randomly plugging cables into your PC can cause serious damage! Refer to your motherboard manual for more information.
Replace your PC's power button with a pin-protected one.

## Installation

Load the .ino file on your Arduino board

### Prerequisites
<ul>
 <li> Hardware:</li>
 <ol>
 <li> Arduino (tested on Arduino Uno Rev3)</li>
 <li> I2C LCD display </li>
 <li> 4x4 keypad </li>
 <li> Relay</li>
 <li> Jumper cables of different types </li>
 </ol>
 <li>Software</li>
 <ol>
 <li> Arduino IDE </li>
 <li>libraries "Keypad" and "LiquidCrystal_I2C"</li>
 </ol>
</ul>

## Usage
0. You can set your PIN in the "PowerButton.ino" file. Look out for the comments for where you can set the PIN.

1. Connect the jumper cables to your PC's power button headers and make sure that the one end is connected to the "COM" port on the relay and the other end is connected to the "NO" (normally open) port on the relay.

2. Connect all devices to the Arduino board as shown.

## Connect devices to the Arduino board
Generally, "GND" or "Ground" belongs to the "Ground" port on the Arduino. All devices with a "VCC" connector used in this project take a 5V input.

Relay: "IN" -> Digital 10<br/><br/>
I2C Display: "SDA" -> SDA; "SCL" -> SCL (if your board doesn't have those headers, check what    they are called on your model)
<br/><br/>
Keypad: 
Check <a href="https://funduino.de/wp-content/uploads/2022/04/fritzing-skizze-schaltplan-tastenfeld-am-arduino.webp" target="_blank">this</a> image
