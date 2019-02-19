#BluetoothServo
For a project I needed to make a servo move once every time bluetooth input was sent to it.
I used the ServoTimer2 for this, since it runs on a different timer than the regular servo lib.

Here's the schematic:
![original image](http://proficient.ninja/js/btservo.png)

The important thing to highlight is the use of `attachInterrupt(digitalPinToInterrupt(2), punchIt, CHANGE);` for the bluetooth module instead of using `SerialSoftware` 

Using SerialSoftware in the same loop as the servo library creates some issues in this case, so instead of reading out the data, I listen for voltage changes on pin 2, since we don't actually need the data.
