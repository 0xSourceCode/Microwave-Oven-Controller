# Microwave Oven Controller Project

```C 
LCD_sendString("CSE 211 | Introduction to Embedded Systems");
LCD_moveCursor(1, 0);
LCD_sendString("Final Project");
```

# Overview

In this project, we used **Tiva™ C Series TM4C123G LaunchPad** in order to develop Microwave Oven Controller<sup id="a1">[1](#f1)</sup> 


# Components

### Tiva™ C Series TM4C123GXL (ARM Cortex M4F Based) LaunchPad
### 16×2 LCD
### Keypad
### LEDs, potentiometer, etc.


# Steps

## 1. The LCD

in the first step, our goal was only to display a sequence of **ASCII** characters on the LCD, with the full control of it's position.

In [LCD_Functions.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/main/LCD.c) we started by initializing the used pins from *PORT B* and *PORT F*

we have known that the **LCD functions** will be used a lot in the project, so we needed to make the code reuseable and readable. so we followed the functional programming paradigm, so our code became nothing more than a set of functions that call each other<sup id="a2">[2](#f2)</sup>, we can summarize as following


### 1. The control functions

- [LCD_vInit](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L13) calls the initializing functions, clears the LCD and sets the cursor

- [LCD_cmd](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L37) initializes the Command ports

- [sendPulse](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L30) sends a pulse to the enable pin(***E***) in the LCD to enable it

- [tostring](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L78) converts integer to string


### 2. The basic instruction functions

- [LCD_sendChar](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L44) print character to the LCD

- [LCD_sendString](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L51) print string to the LCD

- [LCD_clearScreen](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L58) Clears the LCD

- [LCD_moveCursor](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LCD.c#L63) sets the cursor in the selected position on the LCD



## 2. Helper function
we made some helper files and function to make the code reuseable and readable. so our code became nothing more than a set of functions that call each other<sup id="a2">[2](#f2)</sup>. We can summarize as following:

### 1. [Timer.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/Timer.c)
Instead of using meaningless delay such as looping in an empty loop, we have used the systick timer, giving us the choice from choosing between 2 modes in counting [wait_secs](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/Timer.c#L29) for seconds, and [wait_ms](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/Timer.c#L40) for milliseconds, and of course the number of counts in the selected mode.

### 2. [DIO.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/DIO.c)
Instead of using repeated and long port names and port regesters, we made this file to deal with ports more easly. Like for example when we need to initalize a port we use [port_vInit](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/DIO.c#L7). And when we need to write or read from a specific pin we use [DIO_u8ReadPin](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/DIO.c#L262) or [DIO_vWritePort](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/DIO.c#L191), etc.


### 3. [BITCTRL.h](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/BITCTRL.h)
we made this header file to deal with the problem of choosing which bit to work on, for example to set a BIT in specific register we use [SET_BIT](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/BITCTRL.h#L1) and for toggling a bit we use [TOG_BIT](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/BITCTRL.h#L3), etc.

### 4.[LED.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LED.c)
In this file we made a function for in case we wanted to use a led in specific pin and port, so to initialize the pin connected to the led we use [LED_vInit](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LED.c#L5), and to light up the led we use [LED_vON](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LED.c#L10) and the same for closing it [LED_vOFF](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/LED.c#L14).
### 4.[Switch.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/Switch.c)
same as [LED.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/c9202a44d7f34e4c8ddd7e9a4b4688bd3d33c8c0/README.md?plain=1#L70) but for switches. We use [switch_vint](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/Switch.c#L3) function to initialize a switch connected to a specific pin, and the same for [switch_vint_pullup](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/Switch.c#L14) but include the enabling the  pullup for the switch, and [switch_vRead](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/Switch.c#L9) to check if the swich is pressed or not.

## 3. Keypad
in [keypad.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/keypad.c), we started by initializing the used pins from *PORT A* and *PORT E*

we have known that the **Keypad functions** will be used a lot in the project, so we needed to make the code reuseable and readable. so we followed the functional programming paradigm, so our code became nothing more than a set of functions that call each other<sup id="a2">[2](#f2)</sup>, we can summarize as following

- [Initializing the Keypad](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/keypad.c#L10)

- [Returning  the user input (pressed key)](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/keypad.c#L30)

## 4. Parsing the Data
The main Parsing process was implemented in [cookingModes.c](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/cookingModes.c) which take the user input search for the right mode after checking its availability. We also created [LEDxBuzzer](https://github.com/At0m77/Microwave-Oven-Controller/blob/e86ce6fc958a09a00950c7df400fb972cf7ba180/cookingModes.c#L261) which enables the buzzer and the led during mode functions


# Footnotes
<sup><b id="f1">1</b> The functionality of Microwave Oven Controller is limited for the time being duo to problems with intrrupts, but we will fix it as soon as possible[↩](#a1)</sup>

<sup><b id="f2">2</b> The implementation of many functions is nothing more than just calling another functions. [↩](#a2)</sup>
