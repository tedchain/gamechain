// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#include "gamechain/gamechain.h"

#include <iosfwd>
#include <string>
#include <map>

using namespace std;


void mc_MapStringIndex::Init()
{
    Destroy();
    mapObject=new std::map<string, int>;
}

void mc_MapStringIndex::Destroy()
{
    if(mapObject)
    {
        delete (std::map<string, int>*)mapObject;
    }
}

void mc_MapStringIndex::Clear()
{
    Init();
}

void mc_MapStringIndex::Add(const char* key, int value)
{
    ((std::map<string, int>*)mapObject)->insert(std::pair<string, int>(string(key), value));
}

void mc_MapStringIndex::Add(const unsigned char* key, int size, int value)
{
    ((std::map<string, int>*)mapObject)->insert(std::pair<string, int>(string(key,key+size), value));
}

void mc_MapStringIndex::Remove(const char* key,int size)
{
    ((std::map<string, int>*)mapObject)->erase(string(key,key+size));
}

int mc_MapStringIndex::Get(const char* key)
{
    std::map<string, int>::iterator it;
    int value=-1;
    it=((std::map<string, int>*)mapObject)->find(string(key));
    if (it != ((std::map<string, int>*)mapObject)->end())
    {
        value=it->second;
    }    
    return value;
}

int mc_MapStringIndex::Get(const unsigned char* key,int size)
{
    std::map<string, int>::iterator it;
    int value=-1;
    it=((std::map<string, int>*)mapObject)->find(string(key,key+size));
    if (it != ((std::map<string, int>*)mapObject)->end())
    {
        value=it->second;
    }    
    return value;
}

void mc_MapStringString::Init()
{
    mapObject=new std::map<string, string>;
}

void mc_MapStringString::Destroy()
{
    if(mapObject)
    {
        delete (std::map<string, string>*)mapObject;
    }
}

void mc_MapStringString::Add(const char* key, const char*  value)
{
    ((std::map<string, string>*)mapObject)->insert(std::pair<string, string>(string(key), value));
}

const char* mc_MapStringString::Get(const char* key)
{
    std::map<string, string>::iterator it;
    it=((std::map<string, string>*)mapObject)->find(string(key));
    if (it != ((std::map<string, string>*)mapObject)->end())
    {
         return it->second.c_str();
    }    
    return NULL;
}

int mc_MapStringString::GetCount()
{
    return ((std::map<string, string>*)mapObject)->size();
}