//
//  CCTDGAProfile.h
//  cocod2dx-talkingdata
//
//  Created by Wei Mike on 13-5-8.
//  Copyright (c) 2013年 Talkingdata. All rights reserved.
//

#ifndef cocod2dx_talkingdata_CCTDGAProfile_h
#define cocod2dx_talkingdata_CCTDGAProfile_h

class TDCCProfile {
private:
	friend class TDCCTalkingDataGA;

	void* mProfile;
    
    TDCCProfile();

	~TDCCProfile();

public:
	enum TDCCProfileType {
		kProfileAnonymous = 0,
		kProfileRegistered = 1,
		kProfileSianWeibo = 2,
		kProfileQQ = 3,
		kProfileTencentWeibo = 4,
		kProfileND91 = 5,
		kProfileTypeWeiXin = 6,
		kProfileType1 = 11,
		kProfileType2 = 12,
		kProfileType3 = 13,
		kProfileType4 = 14,
		kProfileType5 = 15,
		kProfileType6 = 16,
		kProfileType7 = 17,
		kProfileType8 = 18,
		kProfileType9 = 19,
		kProfileType10 = 20
	};

	enum TDCCGender {
		kGenderUnknown = 0,
		kGenderMale = 1,
		kGenderFemale = 2
	};
    
    
    
    static TDCCProfile* setProfile(const char* profileId);

	void setProfileName(const char* profileName);

	void setProfileType(TDCCProfileType profileType);

	void setLevel(int level);

	void setGender(TDCCGender gender);

	void setAge(int age);

	void setGameServer(const char* gameServer);

};

#endif
