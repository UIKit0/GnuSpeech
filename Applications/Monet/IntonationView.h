#import <AppKit/NSView.h>
#import <AppKit/NSNibDeclarations.h> // For IBAction, IBOutlet

@class EventList, IntonationPoint;

/*===========================================================================

	Author: Craig-Richard Taube-Schock
		Copyright (c) 1994, Trillium Sound Research Incorporated.
		All Rights Reserved.

=============================================================================
*/

@protocol IntonationViewNotification
- (void)intonationViewSelectionDidChange:(NSNotification *)aNotification;
@end

extern NSString *IntonationViewSelectionDidChangeNotification;

@interface IntonationView : NSView
{
    NSTextFieldCell *postureTextFieldCell;
    NSTextFieldCell *ruleIndexTextFieldCell;
    NSTextFieldCell *ruleDurationTextFieldCell;

    NSFont *timesFont;
    NSFont *timesFontSmall;

    EventList *eventList;

    float timeScale;

    NSMutableArray *selectedPoints;
    NSPoint selectionPoint1;
    NSPoint selectionPoint2;

    struct {
        unsigned int shouldDrawSelection:1;
        unsigned int shouldDrawSmoothPoints:1;
        unsigned int mouseBeingDragged:1;
    } flags;

    id nonretained_delegate;
}

- (id)initWithFrame:(NSRect)frameRect;
- (void)dealloc;

- (BOOL)acceptsFirstResponder;

- (void)setEventList:(EventList *)newEventList;

- (BOOL)shouldDrawSelection;
- (void)setShouldDrawSelection:(BOOL)newFlag;

- (BOOL)shouldDrawSmoothPoints;
- (void)setShouldDrawSmoothPoints:(BOOL)newFlag;

- (id)delegate;
- (void)setDelegate:(id)newDelegate;

- (void)drawRect:(NSRect)rect;

- (void)drawGrid;
- (void)drawPostureLabels;
- (void)drawRules;
- (void)drawIntonationPoints;
- (void)drawSmoothPoints;

// Event handling
- (void)mouseEntered:(NSEvent *)theEvent;
- (void)keyDown:(NSEvent *)theEvent;
- (void)mouseDown:(NSEvent *)theEvent;
- (void)mouseDragged:(NSEvent *)mouseEvent;
- (void)mouseUp:(NSEvent *)mouseEvent;
- (void)selectGraphPointsBetweenPoint:(NSPoint)point1 andPoint:(NSPoint)point2;

- (void)updateScale:(float)column;

- (void)deselectAllPoints;
- (void)deletePoints;

- (IntonationPoint *)selectedIntonationPoint;
- (void)selectIntonationPoint:(IntonationPoint *)anIntonationPoint;
- (void)_selectionDidChange;

// View geometry
- (int)sectionHeight;
- (NSPoint)graphOrigin;

- (void)updateEvents;


- (float)scaleXPosition:(float)xPosition;
- (float)scaleWidth:(float)width;
- (NSRect)rectFormedByPoint:(NSPoint)point1 andPoint:(NSPoint)point2;

- (void)intonationPointDidChange:(NSNotification *)aNotification;

@end
