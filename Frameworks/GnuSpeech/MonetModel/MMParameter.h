//  This file is part of Gnuspeech, an extensible, text-to-speech package, based on real-time, articulatory, speech-synthesis-by-rules. 
//  Copyright 1991-2012 David R. Hill, Leonard Manzara, Craig Schock

#import "MMNamedObject.h"

@interface MMParameter : MMNamedObject

@property (assign) double minimumValue;
@property (assign) double maximumValue;
@property (nonatomic, assign) double defaultValue;

- (void)appendXMLToString:(NSMutableString *)resultString level:(NSUInteger)level;

@end
