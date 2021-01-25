//
//  CCTalkingDataGA.mm
//  cocod2dx-talkingdata
//
//  Created by Wei Mike on 13-5-8.
//  Copyright (c) 2013年 Talkingdata. All rights reserved.
//

#import "TDCCProfile.h"
#import "TalkingDataGA.h"

TDCCProfile::TDCCProfile():mProfile(NULL) {
}

TDCCProfile::~TDCCProfile() {
}

TDCCProfile* TDCCProfile::setProfile(const char* profileId) {
    if (NULL == profileId || strlen(profileId) == 0) {
        return NULL;
    }
    NSString* id = [NSString stringWithUTF8String:profileId];
    
    static TDCCProfile profile;
    profile.mProfile = [TDGAProfile setProfile:id];
    return &profile;
}

void TDCCProfile::setProfileName(const char* profileName) {
    if (NULL == profileName || strlen(profileName) == 0) {
        return;
    }
    if (mProfile) {
        NSString* value = [NSString stringWithUTF8String:profileName];
        TDGAProfile* a = (TDGAProfile*)mProfile;
        [a setProfileName:value];
    }
}

void TDCCProfile::setProfileType(TDCCProfileType profileType){
    if (mProfile) {
        TDGAProfile* a = (TDGAProfile*)mProfile;
        [a setProfileType:(TDGAProfileType)profileType];
    }
}

void TDCCProfile::setLevel(int level) {
    if (mProfile) {
        TDGAProfile* a = (TDGAProfile*)mProfile;
        [a setLevel:level];
    }
}

void TDCCProfile::setGender(TDCCGender gender) {
    if (mProfile) {
        TDGAProfile* a = (TDGAProfile*)mProfile;
        [a setGender:(TDGAGender)gender];
    }
}

void TDCCProfile::setAge(int age){
    if (mProfile) {
        TDGAProfile* a = (TDGAProfile*)mProfile;
        [a setAge:age];
    }
}

void TDCCProfile::setGameServer(const char* gameServer){
    if (NULL == gameServer || strlen(gameServer) == 0) {
        return;
    }
    if (mProfile) {
        NSString* value = [NSString stringWithUTF8String:gameServer];
        TDGAProfile* a = (TDGAProfile*)mProfile;
        [a setGameServer:value];
    }
}