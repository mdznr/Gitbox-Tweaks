//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSTableView.h>

__attribute__((visibility("hidden")))
@interface GBChangesTableView : NSTableView
{
    BOOL preparesImageForDragging;
}

@property(nonatomic) BOOL preparesImageForDragging; // @synthesize preparesImageForDragging;
- (void)keyDown:(id)arg1;
- (id)dragImageForRowsWithIndexes:(id)arg1 tableColumns:(id)arg2 event:(id)arg3 offset:(struct CGPoint *)arg4;

@end

