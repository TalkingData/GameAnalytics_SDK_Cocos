//
//  TalkingDataGA-Lua.cpp
//  LuaDemo
//
//  Created by liweiqiang on 13-10-24.
//
//

#include "TalkingDataGA-Lua.h"
#include "tolua++.h"
#include "TalkingData.h"

#define kTalkingDataGA       "TalkingDataGA"
#define kTDGAProfile         "TDGAProfile"
#define kTDGAMission         "TDGAMission"
#define kTDGAVirtualCurrency "TDGAVirtualCurrency"
#define kTDGAItem            "TDGAItem"

static TDCCProfile* profile = NULL;

void tolua_reg_tdga_types (lua_State* tolua_S)
{
    tolua_usertype(tolua_S, kTalkingDataGA);
    tolua_usertype(tolua_S, kTDGAProfile);
    tolua_usertype(tolua_S, kTDGAMission);
    tolua_usertype(tolua_S, kTDGAVirtualCurrency);
    tolua_usertype(tolua_S, kTDGAItem);
}

EventParamMap tolua_tomap(lua_State* L, int narg)
{
    EventParamMap map;
    if (lua_istable(L, narg)) {
        lua_pushnil(L);
        while (lua_next(L, narg))
        {
            lua_pushvalue(L, -2);
            const char* key = lua_tostring(L, -1);
            const char* value = lua_tostring(L, -2);
            map.insert(EventParamPair(key, value));
            lua_pop(L, 2);
        }
    }
    
    return map;
}

static int tolua_TalkingDataGA_onStart(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTalkingDataGA, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !(tolua_isnoobj(tolua_S, 3, &tolua_err) ||
        tolua_isstring(tolua_S, 3, 0, &tolua_err)))
        goto tolua_lerror;
    else
#endif
    {
        const char* appId = (const char*) tolua_tostring(tolua_S, 2, 0);
        const char* channelId = (const char*) tolua_tostring(tolua_S, 3, 0);
        TDCCTalkingDataGA::onStart(appId, channelId);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onStart'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TalkingDataGA_onEvent(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTalkingDataGA, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !(tolua_isnoobj(tolua_S, 3, &tolua_err) ||
        tolua_istable(tolua_S, 3, 0, &tolua_err)))
        goto tolua_lerror;
    else
#endif
    {
        const char* eventId = tolua_tostring(tolua_S, 2, 0);
        EventParamMap eventData = tolua_tomap(tolua_S, 3);
        TDCCTalkingDataGA::onEvent(eventId, &eventData);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onEvent'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TalkingDataGA_setLocation(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTalkingDataGA, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 3, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 4, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        double latitude = (double) tolua_tonumber(tolua_S, 2, 0);
        double longitude = (double) tolua_tonumber(tolua_S, 3, 0);
        TDCCTalkingDataGA::setLatitude(latitude, longitude);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setLocation'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TalkingDataGA_getDeviceId(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTalkingDataGA, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 2, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* deviceId = TDCCTalkingDataGA::getDeviceId();
        tolua_pushstring(tolua_S, deviceId);
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'getDeviceId'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TalkingDataGA_getOAID(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTalkingDataGA, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 2, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* oaid = TDCCTalkingDataGA::getOAID();
        tolua_pushstring(tolua_S, oaid);
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'getOAID'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TalkingDataGA_onKill(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTalkingDataGA, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 2, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        TDCCTalkingDataGA::onKill();
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onKill'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TalkingDataGA_setVerboseLogDisabled(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTalkingDataGA, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 2, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        TDCCTalkingDataGA::setVerboseLogDisabled();
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setVerboseLogDisabled'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAProfile_setProfile(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAProfile, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* profileId = tolua_tostring(tolua_S, 2, 0);
        profile = TDCCProfile::setProfile(profileId);
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setProfile'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAProfile_setProfileName(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAProfile, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        if (profile)
        {
            const char* profileName = tolua_tostring(tolua_S, 2, 0);
            profile->setProfileName(profileName);
        }
#ifndef TOLUA_RELEASE
        else
        {
            tolua_error(tolua_S, "invalid 'profile' in function 'setProfileName'.", &tolua_err);
        }
#endif
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setProfileName'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAProfile_setProfileType(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAProfile, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        if (profile)
        {
            TDCCProfile::TDCCProfileType profileType = (TDCCProfile::TDCCProfileType)tolua_tonumber(tolua_S, 2, 0);
            profile->setProfileType(profileType);
        }
#ifndef TOLUA_RELEASE
        else
        {
            tolua_error(tolua_S, "invalid 'profile' in function 'setProfileType'.", &tolua_err);
        }
#endif
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setProfileType", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAProfile_setLevel(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAProfile, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        if (profile)
        {
            int level = (int) tolua_tonumber(tolua_S, 2, 0);
            profile->setLevel(level);
        }
#ifndef TOLUA_RELEASE
        else
        {
            tolua_error(tolua_S, "invalid 'profile' in function 'setLevel'.", &tolua_err);
        }
#endif
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setLevel'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAProfile_setGender(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAProfile, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        if (profile)
        {
            TDCCProfile::TDCCGender gender = (TDCCProfile::TDCCGender)tolua_tonumber(tolua_S, 2, 0);
            profile->setGender(gender);
        }
#ifndef TOLUA_RELEASE
        else
        {
            tolua_error(tolua_S, "invalid 'profile' in function 'setGender'.", &tolua_err);
        }
#endif
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setLevel'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAProfile_setAge(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAProfile, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        if (profile)
        {
            int age = (int) tolua_tonumber(tolua_S, 2, 0);
            profile->setAge(age);
        }
#ifndef TOLUA_RELEASE
        else
        {
            tolua_error(tolua_S, "invalid 'profile' in function 'setAge'.", &tolua_err);
        }
#endif
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setAge'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAProfile_setGameServer(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAProfile, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        if (profile)
        {
            const char* gameServer = tolua_tostring(tolua_S, 2, 0);
            profile->setGameServer(gameServer);
        }
#ifndef TOLUA_RELEASE
        else
        {
            tolua_error(tolua_S, "invalid 'profile' in function 'setGameServer'.", &tolua_err);
        }
#endif
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'setGameServer'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAMission_onBegin(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAMission, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* missionId = tolua_tostring(tolua_S, 2, 0);
        TDCCMission::onBegin(missionId);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onBegin'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAMission_onCompleted(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAMission, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* missionId = tolua_tostring(tolua_S, 2, 0);
        TDCCMission::onCompleted(missionId);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onCompleted'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAMission_onFailed(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAMission, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !(tolua_isnoobj(tolua_S, 3, &tolua_err) ||
        tolua_isstring(tolua_S, 3, 0, &tolua_err)))
        goto tolua_lerror;
    else
#endif
    {
        const char* missionId = tolua_tostring(tolua_S, 2, 0);
        const char* failedCause = tolua_tostring(tolua_S, 3, 0);
        TDCCMission::onFailed(missionId, failedCause);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onFailed'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAVirtualCurrency_onChargeRequest(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAVirtualCurrency, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 3, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 4, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 5, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 6, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 7, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 8, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* orderId = tolua_tostring(tolua_S, 2, 0);
        const char* iapId = tolua_tostring(tolua_S, 3, 0);
        double currencyAmount = (double) tolua_tonumber(tolua_S, 4, 0);
        const char* currencyType = tolua_tostring(tolua_S, 5, 0);
        double virtualCurrencyAmount = (double) tolua_tonumber(tolua_S, 6, 0);
        const char* paymentType = tolua_tostring(tolua_S, 7, 0);
        TDCCVirtualCurrency::onChargeRequest(orderId, iapId, currencyAmount, currencyType, virtualCurrencyAmount, paymentType);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onChargeRequest'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAVirtualCurrency_onChargeSuccess(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAVirtualCurrency, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 3, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* orderId = tolua_tostring(tolua_S, 2, 0);
        TDCCVirtualCurrency::onChargeSuccess(orderId);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onChargeSuccess'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAVirtualCurrency_onReward(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAVirtualCurrency, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 3, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 4, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        double currencyAmount = (double) tolua_tonumber(tolua_S, 2, 0);
        const char* reason = tolua_tostring(tolua_S, 3, 0);
        TDCCVirtualCurrency::onReward(currencyAmount, reason);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onReward'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAItem_onPurchase(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAItem, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 3, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 4, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 5, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* item = tolua_tostring(tolua_S, 2, 0);
        int number = (int) tolua_tonumber(tolua_S, 3, 0);
        double price = (double) tolua_tonumber(tolua_S, 4, 0);
        TDCCItem::onPurchase(item, number, price);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onPurchase'.", &tolua_err);
    return 0;
#endif
}

static int tolua_TDGAItem_onUse(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, kTDGAItem, 0, &tolua_err) ||
        !tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 3, 0, &tolua_err) ||
        !tolua_isnoobj(tolua_S, 4, &tolua_err))
        goto tolua_lerror;
    else
#endif
    {
        const char* item = tolua_tostring(tolua_S, 2, 0);
        int number = tolua_tonumber(tolua_S, 3, 0);
        TDCCItem::onUse(item, number);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S, "ferror in function 'onUse'.", &tolua_err);
    return 0;
#endif
}

void tolua_tdga_open (lua_State* tolua_S)
{
    tolua_cclass(tolua_S, kTalkingDataGA, kTalkingDataGA, "", NULL);
    tolua_beginmodule(tolua_S, kTalkingDataGA);
    tolua_function(tolua_S, "onStart", tolua_TalkingDataGA_onStart);
    tolua_function(tolua_S, "onEvent", tolua_TalkingDataGA_onEvent);
    tolua_function(tolua_S, "setLocation", tolua_TalkingDataGA_setLocation);
    tolua_function(tolua_S, "getDeviceId", tolua_TalkingDataGA_getDeviceId);
    tolua_function(tolua_S, "getOAID",tolua_TalkingDataGA_getOAID);
    tolua_function(tolua_S, "onKill", tolua_TalkingDataGA_onKill);
    tolua_function(tolua_S, "setVerboseLogDisabled", tolua_TalkingDataGA_setVerboseLogDisabled);
    tolua_endmodule(tolua_S);
    
    tolua_cclass(tolua_S, kTDGAProfile, kTDGAProfile, "", NULL);
    tolua_beginmodule(tolua_S, kTDGAProfile);
    tolua_constant(tolua_S, "kProfileAnonymous", TDCCProfile::kProfileAnonymous);
    tolua_constant(tolua_S, "kProfileRegistered", TDCCProfile::kProfileRegistered);
    tolua_constant(tolua_S, "kProfileSinaWeibo", TDCCProfile::kProfileSianWeibo);
    tolua_constant(tolua_S, "kProfileQQ", TDCCProfile::kProfileQQ);
    tolua_constant(tolua_S, "kProfileTencentWeibo", TDCCProfile::kProfileTencentWeibo);
    tolua_constant(tolua_S, "kProfileND91", TDCCProfile::kProfileND91);
    tolua_constant(tolua_S, "kProfileTypeWeiXin", TDCCProfile::kProfileTypeWeiXin);
    tolua_constant(tolua_S, "kProfileType1", TDCCProfile::kProfileType1);
    tolua_constant(tolua_S, "kProfileType2", TDCCProfile::kProfileType2);
    tolua_constant(tolua_S, "kProfileType3", TDCCProfile::kProfileType3);
    tolua_constant(tolua_S, "kProfileType4", TDCCProfile::kProfileType4);
    tolua_constant(tolua_S, "kProfileType5", TDCCProfile::kProfileType5);
    tolua_constant(tolua_S, "kProfileType6", TDCCProfile::kProfileType6);
    tolua_constant(tolua_S, "kProfileType7", TDCCProfile::kProfileType7);
    tolua_constant(tolua_S, "kProfileType8", TDCCProfile::kProfileType8);
    tolua_constant(tolua_S, "kProfileType9", TDCCProfile::kProfileType9);
    tolua_constant(tolua_S, "kProfileType10", TDCCProfile::kProfileType10);
    
    tolua_constant(tolua_S, "kGenderUnknown", TDCCProfile::kGenderUnknown);
    tolua_constant(tolua_S, "kGenderMale", TDCCProfile::kGenderMale);
    tolua_constant(tolua_S, "kGenderFemale", TDCCProfile::kGenderFemale);
    
    tolua_function(tolua_S, "setProfile", tolua_TDGAProfile_setProfile);
    tolua_function(tolua_S, "setProfileName", tolua_TDGAProfile_setProfileName);
    tolua_function(tolua_S, "setProfileType", tolua_TDGAProfile_setProfileType);
    tolua_function(tolua_S, "setLevel", tolua_TDGAProfile_setLevel);
    tolua_function(tolua_S, "setGender", tolua_TDGAProfile_setGender);
    tolua_function(tolua_S, "setAge", tolua_TDGAProfile_setAge);
    tolua_function(tolua_S, "setGameServer", tolua_TDGAProfile_setGameServer);
    tolua_endmodule(tolua_S);
    
    tolua_cclass(tolua_S, kTDGAMission, kTDGAMission, "", NULL);
    tolua_beginmodule(tolua_S, kTDGAMission);
    tolua_function(tolua_S, "onBegin", tolua_TDGAMission_onBegin);
    tolua_function(tolua_S, "onCompleted", tolua_TDGAMission_onCompleted);
    tolua_function(tolua_S, "onFailed", tolua_TDGAMission_onFailed);
    tolua_endmodule(tolua_S);
    
    tolua_cclass(tolua_S, kTDGAVirtualCurrency, kTDGAVirtualCurrency, "", NULL);
    tolua_beginmodule(tolua_S, kTDGAVirtualCurrency);
    tolua_function(tolua_S, "onChargeRequest", tolua_TDGAVirtualCurrency_onChargeRequest);
    tolua_function(tolua_S, "onChargeSuccess", tolua_TDGAVirtualCurrency_onChargeSuccess);
    tolua_function(tolua_S, "onReward", tolua_TDGAVirtualCurrency_onReward);
    tolua_endmodule(tolua_S);
    
    tolua_cclass(tolua_S, kTDGAItem, kTDGAItem, "", NULL);
    tolua_beginmodule(tolua_S, kTDGAItem);
    tolua_function(tolua_S, "onPurchase", tolua_TDGAItem_onPurchase);
    tolua_function(tolua_S, "onUse", tolua_TDGAItem_onUse);
    tolua_endmodule(tolua_S);
}
