// JRSwizzle.h semver:1.0
//   Copyright (c) 2007-2011 Jonathan 'Wolf' Rentzsch: http://rentzsch.com
//   Some rights reserved: http://opensource.org/licenses/MIT
//   https://github.com/rentzsch/jrswizzle

#import <Foundation/Foundation.h>

#define SWIZZLE(class_name, src, dest) \
[NSClassFromString(class_name) jr_swizzleMethod:@selector(src) \
withMethod:@selector(dest) \
error:NULL]

#define SWIZZLE_CLASS(class_name, src, dest) \
[NSClassFromString(class_name) jr_swizzleClassMethod:@selector(src) \
withClassMethod:@selector(dest) \
error:NULL]

@interface NSObject (JRSwizzle)

+ (BOOL)jr_swizzleMethod:(SEL)origSel_ withMethod:(SEL)altSel_ error:(NSError**)error_;
+ (BOOL)jr_swizzleClassMethod:(SEL)origSel_ withClassMethod:(SEL)altSel_ error:(NSError**)error_;

@end
