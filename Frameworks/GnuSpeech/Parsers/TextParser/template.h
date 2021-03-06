/*******************************************************************************
 *
 *  Copyright (c) 1991-2012 David R. Hill, Leonard Manzara, Craig Schock
 *  
 *  Contributors: 
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *******************************************************************************
 *
 *  template.h
 *  GnuSpeech
 *
 *  Version: 0.9.1
 *
 ******************************************************************************/

#import <stdio.h>

/*  DEFINITIONS  */
#define SYMBOL_LENGTH_MAX       12
#define SAMPLE_SIZE_DEF         2

/*  DATA STRUCTURES  */
struct _phoneStruct {
	char symbol[SYMBOL_LENGTH_MAX+1];
	struct _phoneStruct *next;
};
typedef struct _phoneStruct phoneStruct;
typedef phoneStruct *phoneStructPtr;

struct _parameterStruct {
	char symbol[SYMBOL_LENGTH_MAX+1];
	float minimum;
	float maximum;
	float Default;
	struct _parameterStruct *next;
};
typedef struct _parameterStruct parameterStruct;
typedef parameterStruct *parameterStructPtr;

void initTemplate(void);
int sampleValue(void);
char *parameterSymbol(int number);
float parameterSymMinimum(char *parameter);
float parameterSymMaximum(char *parameter);
void readFromFileTemplate(FILE *fp1);
int legalPhone(char *phone);
int legalParameter(char *parameter);
#if DEBUG
void printTemplate(void);
#endif
