# MES - Exercise 3

completed: 17-09-22

**What build environment are you using?**

Code Composer Studio (TI), TI 20.2.5.LTS toolchain, CMSIS/TivaWare Libs.


**Can you step through the code to see what each line does?**

Yes, Launchpad board has an on-board debugger so I can step through.


**What are the hardware registers that cause the LED to turn on and off?**

The GPIO DATA Register for PORTF (at position 1,2,3) - memory mapped to 0x40025000 (base addr)


**What are the registers that you read in order to find out the state of the button?**

The GPIO DATA Register for PORTF (at position 0) - memory mapped to 0x40025000 (base addr)


**Can you read the register directly and see the button change in a debugger or by printing out thes value of the memory at the register’s address?**

Yes, the registers are listed in the debug view
