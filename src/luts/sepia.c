#include "sepia.h"
#include <stdio.h>

void sepia_addToLut(ImacLut* lut3d) {
    int brightnessR = 0, brightnessG = 0, brightnessB = 0;
    /*
    for (unsigned int red = 0; red < lut3d->size; red++) {
	    for (unsigned int green = 0; green < lut3d->size; green++) {
		    for (unsigned int blue = 0; blue < lut3d->size; blue++) {
			    brightnessR = (red*.33) + (green * .33) + (blue * .33);
			    //brightnessR = (red*.393) + (green * .769) + (blue * .189);
			    //brightnessG = (red*.349) + (green * .686) + (blue * .168);
			    //brightnessB = (red*.272) + (green * .534) + (blue * .131);
			    lut3d->dataR[red] = (unsigned char) brightnessR;
			    lut3d->dataG[red] = (unsigned char) brightnessR;
			    lut3d->dataB[red] = (unsigned char) brightnessR;
		    }    
	    }
    }
    */
    for (unsigned int i = 0; i < lut3d->size; i++) {
	    brightnessR = (i*.393) + (i * .469) + (i * .189);
	    brightnessG = (i*.349) + (i * .486) + (i * .168);
	    brightnessB = (i*.272) + (i * .534) + (i * .131);
	    lut3d->dataR[i] = (unsigned char) brightnessR;
	    lut3d->dataG[i] = (unsigned char) brightnessG;
	    lut3d->dataB[i] = (unsigned char) brightnessB;
    }    

}
