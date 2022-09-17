
#include <stdint.h>
#include <stdbool.h>
#include "ledDriver.h"
#include "buttonDriver.h"
#include "clockDriver.h"
#include "Utility.h"


/*...*/
void initialisation(void){
    configureClock();
    configureLED();
    configureBtn();
}

/*...*/
int main(void)
{
    /*button and LED init*/
    initialisation();

    /*Background loop*/
    while(1){
        DelayMs(1000);
    }

    /*should not return*/
	return 0;
}
