#pragma once

#include "cast.h"

namespace yzg
{
    extern const char * rts_null;
    
    __forceinline const char * to_rts ( __m128 a ) {
        const char * s = cast<const char *>::to(a);
        return s ? s : rts_null;
    }
    
    __forceinline __m128 from_rts ( const char * a ) {
        return cast<const char *>::from(a==rts_null ? nullptr : a);
    }
    
    struct SimPolicy_String {
        // basic
        static __forceinline __m128 Set     ( __m128 a, __m128 b )
            { *cast<char **>::to(a) =  cast<char *>::to(b); return a; }
        static __forceinline __m128 Equ     ( __m128 a, __m128 b )
            { return cast<bool>::from(strcmp(to_rts(a), to_rts(b))==0); }
        static __forceinline __m128 NotEqu  ( __m128 a, __m128 b )
            { return cast<bool>::from(strcmp(to_rts(a), to_rts(b))!=0); }
        // ordered
        static __forceinline __m128 LessEqu ( __m128 a, __m128 b )
            { return cast<bool>::from(strcmp(to_rts(a), to_rts(b))<=0); }
        static __forceinline __m128 GtEqu   ( __m128 a, __m128 b )
            { return cast<bool>::from(strcmp(to_rts(a), to_rts(b))>=0); }
        static __forceinline __m128 Less    ( __m128 a, __m128 b )
            { return cast<bool>::from(strcmp(to_rts(a), to_rts(b))<0); }
        static __forceinline __m128 Gt      ( __m128 a, __m128 b )
            { return cast<bool>::from(strcmp(to_rts(a), to_rts(b))>0); }
    };
    
    string unescapeString ( const string & input );
    string escapeString ( const string & input );
    
    string::const_iterator positionToRowCol ( const string & st, long AT, int & col, int & row );
}
