//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBRepositoryController.h"

@class GBSubmodule;

__attribute__((visibility("hidden")))
@interface GBSubmoduleController : GBRepositoryController
{
    GBSubmodule *_submodule;
    GBRepositoryController *_parentRepositoryController;
}

+ (id)controllerWithSubmodule:(id)arg1;
@property(nonatomic) GBRepositoryController *parentRepositoryController; // @synthesize parentRepositoryController=_parentRepositoryController;
@property(retain, nonatomic) GBSubmodule *submodule; // @synthesize submodule=_submodule;
- (void)start;
- (BOOL)isSubmoduleClean;
- (void)resetSubmodule:(id)arg1;
- (id)sidebarItemMenu;
- (id)initWithSubmodule:(id)arg1;
- (void)dealloc;

@end

