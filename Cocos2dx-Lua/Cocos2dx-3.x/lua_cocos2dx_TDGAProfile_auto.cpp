#include "lua_cocos2dx_TDGAProfile_auto.hpp"
#include "TDCCProfile.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



static TDCCProfile* tdgaProfile;
int lua_cocos2dx_TDGAProfile_setGender(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAProfile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        TDCCProfile::TDCCGender arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaProfile)
            tdgaProfile->setGender(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAProfile_setGender'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAProfile_setProfileName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAProfile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        if (tdgaProfile)
            tdgaProfile->setProfileName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setProfileName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAProfile_setProfileName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAProfile_setAge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAProfile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaProfile)
            tdgaProfile->setAge(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setAge",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAProfile_setAge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAProfile_setProfileType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAProfile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        TDCCProfile::TDCCProfileType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaProfile)
            tdgaProfile->setProfileType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setProfileType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAProfile_setProfileType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAProfile_setGameServer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAProfile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        if (tdgaProfile)
            tdgaProfile->setGameServer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setGameServer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAProfile_setGameServer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAProfile_setProfile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAProfile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        tdgaProfile = TDCCProfile::setProfile(arg0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setProfile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAProfile_setProfile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAProfile_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAProfile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaProfile)
            tdgaProfile->setLevel(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setLevel",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAProfile_setLevel'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_TDGAProfile_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TDGAProfile)");
    return 0;
}

int lua_register_cocos2dx_TDGAProfile(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TDGAProfile");
    tolua_cclass(tolua_S,"TDGAProfile","TDGAProfile","",nullptr);
    
    tolua_beginmodule(tolua_S,"TDGAProfile");
        tolua_constant(tolua_S,"kProfileAnonymous", TDCCProfile::kProfileAnonymous);
        tolua_constant(tolua_S,"kProfileRegistered", TDCCProfile::kProfileRegistered);
        tolua_constant(tolua_S,"kProfileSinaWeibo", TDCCProfile::kProfileSianWeibo);
        tolua_constant(tolua_S,"kProfileQQ", TDCCProfile::kProfileQQ);
        tolua_constant(tolua_S,"kProfileTencentWeibo", TDCCProfile::kProfileTencentWeibo);
        tolua_constant(tolua_S,"kProfileND91", TDCCProfile::kProfileND91);
        tolua_constant(tolua_S,"kProfileTypeWeiXin", TDCCProfile::kProfileTypeWeiXin);
        tolua_constant(tolua_S,"kProfileType1", TDCCProfile::kProfileType1);
        tolua_constant(tolua_S,"kProfileType2", TDCCProfile::kProfileType2);
        tolua_constant(tolua_S,"kProfileType3", TDCCProfile::kProfileType3);
        tolua_constant(tolua_S,"kProfileType4", TDCCProfile::kProfileType4);
        tolua_constant(tolua_S,"kProfileType5", TDCCProfile::kProfileType5);
        tolua_constant(tolua_S,"kProfileType6", TDCCProfile::kProfileType6);
        tolua_constant(tolua_S,"kProfileType7", TDCCProfile::kProfileType7);
        tolua_constant(tolua_S,"kProfileType8", TDCCProfile::kProfileType8);
        tolua_constant(tolua_S,"kProfileType9", TDCCProfile::kProfileType9);
        tolua_constant(tolua_S,"kProfileType10", TDCCProfile::kProfileType10);
    
        tolua_constant(tolua_S,"kGenderUnknown", TDCCProfile::kGenderUnknown);
        tolua_constant(tolua_S,"kGenderMale", TDCCProfile::kGenderMale);
        tolua_constant(tolua_S,"kGenderFemale", TDCCProfile::kGenderFemale);
    
        tolua_function(tolua_S,"setGender", lua_cocos2dx_TDGAProfile_setGender);
        tolua_function(tolua_S,"setProfileName", lua_cocos2dx_TDGAProfile_setProfileName);
        tolua_function(tolua_S,"setAge", lua_cocos2dx_TDGAProfile_setAge);
        tolua_function(tolua_S,"setProfileType", lua_cocos2dx_TDGAProfile_setProfileType);
        tolua_function(tolua_S,"setGameServer", lua_cocos2dx_TDGAProfile_setGameServer);
        tolua_function(tolua_S,"setProfile", lua_cocos2dx_TDGAProfile_setProfile);
        tolua_function(tolua_S,"setLevel", lua_cocos2dx_TDGAProfile_setLevel);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TDCCProfile).name();
    g_luaType[typeName] = "TDGAProfile";
    g_typeCast["TDGAProfile"] = "TDGAProfile";
    return 1;
}
TOLUA_API int register_all_cocos2dx_TDGAProfile(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_TDGAProfile(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

