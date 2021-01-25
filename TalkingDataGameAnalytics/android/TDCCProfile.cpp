#include "TDCCProfile.h"
#include "TDGAJniHelper.h"
#include "TDGALog.h"

extern jclass gClass_Profile;
extern jclass gClass_ProfileType;
extern jclass gClass_Gender;

static const char * TDCCProfileTypeString[] = {
			"ANONYMOUS",
			"REGISTERED",
			"SINA_WEIBO",
			"QQ",
			"QQ_WEIBO",
			"ND91",
			"WEIXIN",
			"", "", "", "",
			"TYPE1",
			"TYPE2",
			"TYPE3",
			"TYPE4",
			"TYPE5",
			"TYPE6",
			"TYPE7",
			"TYPE8",
			"TYPE9",
			"TYPE10"
};

static const char * TDCCGenderString[] = {
			"UNKNOW",
			"MALE",
			"FEMALE"
};

TDCCProfile::TDCCProfile():mProfile(NULL) {
	LOGD("TDCCProfile()");
}

TDCCProfile::~TDCCProfile() {
	LOGD("~TDCCProfile()");
	JNIEnv *env = 0;
	if (mProfile && TDGAJniHelper::getJNIEnv(&env)) {
		env->DeleteGlobalRef((jobject)mProfile);
		mProfile = NULL;
	}
}

TDCCProfile* TDCCProfile::setProfile(const char* profileId) {
    if (NULL == profileId || strlen(profileId) == 0) {
        return NULL;
    }
    static TDCCProfile profile;
    TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, gClass_Profile
		, "setProfile"
		, "(Ljava/lang/String;)Lcom/tendcloud/tenddata/TDGAProfile;")) {
		if (profile.mProfile) {
			t.env->DeleteGlobalRef((jobject)profile.mProfile);
			profile.mProfile = NULL;
		}

		jstring jprofileId = t.env->NewStringUTF(profileId);
		jobject jobj = t.env->CallStaticObjectMethod(gClass_Profile, t.methodID, jprofileId);
		profile.mProfile = (void*)t.env->NewGlobalRef(jobj);
		t.env->DeleteLocalRef(jprofileId);
		t.env->DeleteLocalRef(jobj);
	}

    return &profile;
}

void TDCCProfile::setProfileName(const char* profileName) {
	TDGAJniMethodInfo t;
	if (mProfile && TDGAJniHelper::getMethodInfo(t
		, gClass_Profile
		, "setProfileName"
		, "(Ljava/lang/String;)V")) {
		jstring jprofileName = t.env->NewStringUTF(profileName);
		t.env->CallVoidMethod((jobject)mProfile, t.methodID, jprofileName);
		t.env->DeleteLocalRef(jprofileName);
	}
}

void TDCCProfile::setGameServer(const char* gameServer) {
	TDGAJniMethodInfo t;
	if (mProfile && TDGAJniHelper::getMethodInfo(t
		, gClass_Profile
		, "setGameServer"
		, "(Ljava/lang/String;)V")) {
		jstring jgameServer = t.env->NewStringUTF(gameServer);
		t.env->CallVoidMethod((jobject)mProfile, t.methodID, jgameServer);
		t.env->DeleteLocalRef(jgameServer);
	}
}

void TDCCProfile::setLevel(int level) {
	TDGAJniMethodInfo t;
	if (mProfile && TDGAJniHelper::getMethodInfo(t
		, gClass_Profile
		, "setLevel"
		, "(I)V")) {
		t.env->CallVoidMethod((jobject)mProfile, t.methodID, level);
	}
}

void TDCCProfile::setAge(int age) {
	TDGAJniMethodInfo t;
	if (mProfile && TDGAJniHelper::getMethodInfo(t
		, gClass_Profile
		, "setAge"
		, "(I)V")) {
		t.env->CallVoidMethod((jobject)mProfile, t.methodID, age);
	}
}

void TDCCProfile::setProfileType(TDCCProfileType profileType) {
	TDGAJniMethodInfo t;
	TDGAJniMethodInfo type;
	if (mProfile && TDGAJniHelper::getMethodInfo(t
		, gClass_Profile
		, "setProfileType"
		, "(Lcom/tendcloud/tenddata/TDGAProfile$ProfileType;)V") &&
		TDGAJniHelper::getStaticMethodInfo(type
		, gClass_ProfileType
		, "valueOf"
		, "(Ljava/lang/String;)Lcom/tendcloud/tenddata/TDGAProfile$ProfileType;")) {
		jstring jprofileType = t.env->NewStringUTF(TDCCProfileTypeString[profileType]);
		jobject jtype = type.env->CallStaticObjectMethod(gClass_ProfileType, type.methodID, jprofileType);
		t.env->CallVoidMethod((jobject)mProfile, t.methodID, jtype);
		t.env->DeleteLocalRef(jtype);
		t.env->DeleteLocalRef(jprofileType);
	}
}

void TDCCProfile::setGender(TDCCGender gender) {
	TDGAJniMethodInfo t;
	TDGAJniMethodInfo type;
	if (mProfile
		&& TDGAJniHelper::getMethodInfo(t
		, gClass_Profile
		, "setGender"
		, "(Lcom/tendcloud/tenddata/TDGAProfile$Gender;)V")
		&& TDGAJniHelper::getStaticMethodInfo(type
		, gClass_Gender
		, "valueOf"
		, "(Ljava/lang/String;)Lcom/tendcloud/tenddata/TDGAProfile$Gender;")) {

		jstring jgender = type.env->NewStringUTF(TDCCGenderString[gender]);
		jobject jtype = type.env->CallStaticObjectMethod(gClass_Gender, type.methodID, jgender);
		type.env->DeleteLocalRef(jgender);
		t.env->CallVoidMethod((jobject)mProfile, t.methodID, jtype);
		t.env->DeleteLocalRef(jtype);
	}
}
