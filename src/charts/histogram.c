#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"
#include "../image-loaders/ppm.h"
#include "../core/utils.h"

// --------------------------------------------------- PUBLIC FUNCTIONS

void hist_buildHistogram(ImacImg* imgToAnalyse, unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE]) {
    // Get values for histogram
    unsigned int pixelAvgBrightness[4] = {0};
    for (unsigned int x = 0; x < imgToAnalyse->width; x++) {
        for (unsigned int y = 0; y < imgToAnalyse->height; y++) {
            for (int c = red; c <= blue; c++) {
                pixelAvgBrightness[c] += img_getPixelChannel(imgToAnalyse, x, y, (enum img_Channel) c);
                imgBrightnessSpectrum[c][(unsigned char) pixelAvgBrightness[c]] += 1;
            }

            pixelAvgBrightness[rvb] = (pixelAvgBrightness[red] + pixelAvgBrightness[green] + pixelAvgBrightness[blue])/ 3;
	        imgBrightnessSpectrum[rvb][(unsigned char) pixelAvgBrightness[rvb]] += 1;
            for (int c = red; c <= blue; c++) {
                pixelAvgBrightness[c] = 0;
            }
        }
    }
}

void hist_getMaxBrightness(unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE], unsigned int maxPixelsForBrightness[rvb+1]) {
    for (int i = 0; i < HIST_SIZE; i++) {
	    for (int c = red; c <= rvb; c++) {
		    if (imgBrightnessSpectrum[c][i] > maxPixelsForBrightness[c]) {
			    maxPixelsForBrightness[c] = imgBrightnessSpectrum[c][i];
		    }
	    }	
    }
}


int hist_findMaxIndex(int *histogram, int histSize) {
	int maxValueIndex = 0;
	for (int i = 0; i < histSize; i++) {
		if (histogram[i] > histogram[maxValueIndex]) maxValueIndex = i;
	}
	return maxValueIndex;
}

int* hist_initScaledHistogram(int *outputHistogram, int scale) {
	outputHistogram = (int*) malloc(sizeof(outputHistogram) * scale);	
	if (!outputHistogram) {
		printf("error hist_initScaledHistogram: malloc failed");
		DEBUG_BREAK;
	}
	return outputHistogram;
}

void hist_printHistValues(int *histogram, int nbOfValues) {
	printf("\n");
	printf("H: ");
	for (int i = 0; i < nbOfValues; i++){
		printf("%2d ", histogram[i]);
	}
	printf("\n");
	printf("\n");
}

void hist_fillScaledHistogram(int *inputHist, int *outputHist, int scale) {
	float palier = (float) HIST_SIZE / scale;
	float quantitee = 0.;
	int inputHistIndex = 0;
	float rest = 0.;
	float partDecQuantitee = 0.;
	int partEntQuantitee = 0;
	int value = 0;
	float valueRound = 0.;
	for (int outputIndex = 0; outputIndex < scale; outputIndex++) {
		value = 0;
		if (rest) {
			valueRound = inputHist[inputHistIndex] * rest;
			value += (int) (valueRound < 0 ? valueRound-.5 : valueRound+.5); 
			quantitee = palier - rest;
			inputHistIndex++;
		} else quantitee = palier;
		//printf("value = %d\n", value);
		partEntQuantitee = (int) quantitee;
		partDecQuantitee = (float) quantitee - partEntQuantitee;

		for (int j = 0; j < partEntQuantitee; j++) {
			valueRound = inputHist[inputHistIndex];
			value += (int) (valueRound < 0 ? valueRound-.5 : valueRound+.5); 
			inputHistIndex++;
			// printf("value = %d\n", value);
		}
		if (inputHistIndex > 255) inputHistIndex = 255;
		valueRound = (float) inputHist[inputHistIndex] * partDecQuantitee;
		value += (int) (valueRound < 0 ? valueRound-.5 : valueRound+.5); 
		//printf("///value = %d, inputHistIndex = %d, inputHist[inputHistIndex] = %d, partDecQuantitee = %f\n", value, inputHistIndex, inputHist[inputHistIndex], partDecQuantitee);
		rest = 1. - partDecQuantitee;	
		outputHist[outputIndex] = value;
	}
}

void hist_printTerminal(int *histogram1, int *histogram2, int scaleX){
	int* scaledHist1 = NULL;
	int* scaledHist2 = NULL;
	float palier = (float) HIST_SIZE / scaleX;
	scaledHist1 = hist_initScaledHistogram(scaledHist1, scaleX);
	scaledHist2 = hist_initScaledHistogram(scaledHist2, scaleX);

	hist_fillScaledHistogram(histogram1, scaledHist1, scaleX);
	hist_fillScaledHistogram(histogram2, scaledHist2, scaleX);

	hist_printHistValues(histogram1, HIST_SIZE);
	hist_printHistValues(scaledHist1, scaleX);
	hist_printHistValues(histogram2, HIST_SIZE);
	hist_printHistValues(scaledHist2, scaleX);

	int hheight;
	int hPos1, hPos2;
	int lineNum;
	char histogramTitle1[] = "Histogram1";
	char histogramTitle2[] = "Histogram2";
	int maxValueIndex1 = hist_findMaxIndex(scaledHist1, scaleX);
	int maxValueIndex2 = hist_findMaxIndex(scaledHist2, scaleX);
	float upscaleFactor1 = (float) HIST_HEIGHT / scaledHist1[maxValueIndex1];
	float upscaleFactor2 = (float) HIST_HEIGHT / scaledHist2[maxValueIndex2];
	char gap[] = "   >   ";

	for(int h = 1; h <= HIST_HEIGHT; h++){
		hheight = HIST_HEIGHT - h + 1;
		lineNum = hheight;
		printf("%2d | ..", lineNum);
		hPos1 = hheight;
		hPos2 = hheight;
		hPos1 /= upscaleFactor1;
		hPos2 /= upscaleFactor2;

		for (int w=0; w<scaleX; w++) {
			if (hPos1 <= scaledHist1[w]) {
				printf("# ..");
			}	
			else{ printf("....");}
		} 

		printf("%s", gap);
		printf("%2d | ..", lineNum);

		for (int w = 0; w < scaleX; w++) {
			if (hPos2 <= scaledHist2[w]) {
				printf("# ..");
			}	
			else{ printf("....");}
		}
		printf("\n");
	}

	printf("       ");
	for(float w = 0; w < HIST_SIZE; w += palier) {
		printf("%-3d ", (int)w);
	}
	printf("%s", gap);
	printf("       ");

	for(float w = 0; w < HIST_SIZE; w += palier) {
		printf("%-3d ", (int)w);
	}
	printf("\n");

	int paddingL1 = ((8 + scaleX * 4) - strlen(histogramTitle1)) / 2;
	int paddingL2 = ((8 + scaleX * 4) - strlen(histogramTitle2)) / 2;
	printf("%-*s%s%*s", paddingL1-1, "---", histogramTitle1, paddingL1, "---");
	printf("%s", gap);
	printf("%-*s%s%*s\n", paddingL2, "---", histogramTitle2, paddingL2+1, "---");
	//printf("HIST_VALUES/scaleX = %f\n", HIST_VALUES/scaleX);

	free(scaledHist1);
	free(scaledHist2);
}

void hist_printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor, enum img_Channel c) {
    if (histogram->width != 256) {
        printf("hist_printHistogram error: histogram not 256 width");
		DEBUG_BREAK;
        exit(EXIT_FAILURE);
    }

    for (unsigned int x = 0; x < histogram->width; x++) {
        unsigned int columnHeight = linearMapping(histogramData[x], 0, maxData, 0, histogram->height);
        unsigned int columnEnd = histogram->height - columnHeight;

        for (unsigned int y = histogram->height - 1; y > columnEnd; y--) {
            if (c == rvb) img_setPixelChannels(histogram, x, y, printColor);
            else {
                for (int ch = red; ch <= blue; ch++) {
                    if (ch == c) img_setPixelChannel(histogram, x, y, printColor, c);
                    else img_setPixelChannel(histogram, x, y, 0, (enum img_Channel) ch);
                }
            }
        }
    }
}

int hist_rgb(ImacImg* imgToAnalyse, ImacImg* histogram) {
    img_setToWhite(histogram);
    unsigned int imgBrightnessSpectrum[4][256] = {{0},{0},{0},{0}};
    hist_buildHistogram(imgToAnalyse, imgBrightnessSpectrum);
    unsigned int maxPixelsForBrightness[4] = {0};
    hist_getMaxBrightness(imgBrightnessSpectrum, maxPixelsForBrightness);
    unsigned char colorLevel = 0;

    // Print histogram to file
    for (int c = red; c <= rvb; c++) {
	    colorLevel = (c==rvb)?150:255;
	    hist_printHistogram(histogram, imgBrightnessSpectrum[c], maxPixelsForBrightness[c], colorLevel, (enum img_Channel) c);
    }
    return EXIT_SUCCESS;
}

int hist_channel(ImacImg* imgToAnalyse, ImacImg* histogram, enum img_Channel c) {
    img_setToWhite(histogram);
    unsigned int imgBrightnessSpectrum[255] = { 0 };

    // Get values for histogram
    unsigned int pixelBrightness = 0;
    unsigned int maxPixelsForBrightness = 0;
    for (unsigned int x = 0; x < imgToAnalyse->width; x++) {
        for (unsigned int y = 0; y < imgToAnalyse->height; y++) {
            pixelBrightness = img_getPixelChannel(imgToAnalyse, x, y, c);
            imgBrightnessSpectrum[(unsigned char) pixelBrightness] += 1;
            if (imgBrightnessSpectrum[(unsigned char) pixelBrightness] > maxPixelsForBrightness) {
                maxPixelsForBrightness = imgBrightnessSpectrum[(unsigned char) pixelBrightness];
            }
            pixelBrightness = 0;
        }
    }

    hist_printHistogram(histogram, imgBrightnessSpectrum, maxPixelsForBrightness, 255, c);
    return EXIT_SUCCESS;
}
