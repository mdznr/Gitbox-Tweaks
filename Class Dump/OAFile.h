//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

__attribute__((visibility("hidden")))
@interface OAFile : NSObject
{
}

+ (id)mutablePropertyListFromData:(id)arg1;
+ (id)immutablePropertyListFromData:(id)arg1;
+ (id)propertyListFromData:(id)arg1 mutabilityOption:(unsigned long long)arg2;
+ (id)dataFromPropertyList:(id)arg1;
+ (id)removeFileAtPath:(id)arg1;
+ (id)setUtf8String:(id)arg1 forPath:(id)arg2;
+ (id)setString:(id)arg1 withEncoding:(unsigned long long)arg2 forPath:(id)arg3;
+ (id)setPropertyList:(id)arg1 forPath:(id)arg2;
+ (id)setData:(id)arg1 forPath:(id)arg2;
+ (id)createFolderForFilePath:(id)arg1;
+ (id)createFolderForPath:(id)arg1;
+ (BOOL)isReadable:(id)arg1;
+ (id)utf8StringForPath:(id)arg1;
+ (id)stringForPath:(id)arg1 encoding:(unsigned long long)arg2;
+ (id)mutablePropertyListForPath:(id)arg1;
+ (id)immutablePropertyListForPath:(id)arg1;
+ (id)propertyListForPath:(id)arg1 mutabilityOption:(unsigned long long)arg2;
+ (id)dataForPath:(id)arg1;

@end
