// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#include "json_spirit_writer.h"
#include "json_spirit_writer_template.h"

void json_spirit::write( const Value& value, std::ostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const Value& value, std::ostream& os )
{
    write_stream( value, os, true );
}

std::string json_spirit::write( const Value& value )
{
    return write_string( value, false );
}

std::string json_spirit::write_formatted( const Value& value )
{
    return write_string( value, true );
}

#ifndef BOOST_NO_STD_WSTRING

void json_spirit::write( const wValue& value, std::wostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const wValue& value, std::wostream& os )
{
    write_stream( value, os, true );
}

std::wstring json_spirit::write( const wValue&  value )
{
    return write_string( value, false );
}

std::wstring json_spirit::write_formatted( const wValue&  value )
{
    return write_string( value, true );
}

#endif

void json_spirit::write( const mValue& value, std::ostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const mValue& value, std::ostream& os )
{
    write_stream( value, os, true );
}

std::string json_spirit::write( const mValue& value )
{
    return write_string( value, false );
}

std::string json_spirit::write_formatted( const mValue& value )
{
    return write_string( value, true );
}

#ifndef BOOST_NO_STD_WSTRING

void json_spirit::write( const wmValue& value, std::wostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const wmValue& value, std::wostream& os )
{
    write_stream( value, os, true );
}

std::wstring json_spirit::write( const wmValue&  value )
{
    return write_string( value, false );
}

std::wstring json_spirit::write_formatted( const wmValue&  value )
{
    return write_string( value, true );
}

#endif
