# MES - Exercise 3

completed: 17-09-22

**What build environment are you using?**

Code Composer Studio (TI), TI 20.2.5.LTS toolchain, CMSIS/TivaWare Libs.


**Can you step through the code to see what each line does?**

Yes, Launchpad board has an on-board debugger so I can step through.


**What are the hardware registers that cause the LED to turn on and off?**

The GPIO DATA Register for PORTF (at position 1,2,3) - memory mapped to 0x40025000 (base addr)

A value of 1 will enable the LED, 0 will disable it, this can be set using the Tivaware API or directly. 

Three main bitwise operations are used:

**SET** value |= (1U << N)

**CLEAR** value &= ~(1U << N)

**TOGGLE** value ^= (1U << N)


**What are the registers that you read in order to find out the state of the button?**

The GPIO DATA Register for PORTF (at position 0) is read - memory mapped to 0x40025000 (base addr).

A value of 1 indicates an open switch (it is pulled up), 0 indicates a closed (pressed) switch, this can be read using the Tivaware API or directly. 


**Can you read the register directly and see the button change in a debugger or by printing out thes value of the memory at the register’s address?**

Yes, the registers are listed in the debug view
