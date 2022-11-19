//Team Fortress 3's trignometric functions
//Made by DavidB420, based on code from Doors NX calculator application, 2022

#include "trigfunc.h"

float sinFunction(float val)
{
    _asm {
        fninit
        fld val
        mov eax, 180
        push eax
        fidiv[esp]
        fldpi
        fmul
        fsin
        fwait
        fst val
        pop eax
    }
    return val;
}

float cosFunction(float val)
{
    _asm {
        fninit
        fld val
        mov eax, 180
        push eax
        fidiv[esp]
        fldpi
        fmul
        fcos
        fwait
        fst val
        pop eax
    }
    return val;
}

float tanFunction(float val)
{
    _asm {
        fninit
        fld val
        mov eax, 180
        push eax
        fidiv[esp]
        fldpi
        fmul
        fst st(1)
        fsin
        fxch st(1)
        fcos
        fdiv st(1), st(0)
        fxch st(1)
        fwait
        fst val
        pop eax
    }
    return val;
}

float cscFunction(float val)
{
    return 1 / sinFunction(val);
}

float secFunction(float val)
{
    return 1 / cosFunction(val);
}

float cotFunction(float val)
{
    return 1 / tanFunction(val);
}

float asinFunction(float val)
{
    const float radtodeg = 180.0f / 3.14159f;
    _asm {
        fninit
        fld val
        fld st(0)
        fmul st(0),st(0)
        fld1
        fsubr
        fsqrt
        fpatan
        fst val
    }
    clearfpuregisters();
    _asm {
        fninit
        fld val
        fld radtodeg
        fmul st(0), st(1)
        fst val
    }
    return val;
}

float acosFunction(float val)
{
    const float radtodeg = 180.0f / 3.14159f;
    _asm {
        fninit
        fld val
        fld st(0)
        fmul st(0), st(0)
        fld1
        fsubr
        fsqrt
        fxch st(1)
        fpatan
        fst val
    }
    clearfpuregisters();
    _asm {
        fninit
        fld val
        fld radtodeg
        fmul st(0), st(1)
        fst val
    }
    return val;
}

float atanFunction(float val)
{
    const float radtodeg = 180.0f / 3.14159f;
    _asm {
        fninit
        fld val
        fld1
        fpatan
        fst val
    }
    clearfpuregisters();
    _asm {
        fninit
        fld val
        fld radtodeg
        fmul st(0), st(1)
        fst val
    }
    return val;
}

float acscFunction(float val)
{
    return asinFunction(1/val);
}

float asecFunction(float val)
{
    return acosFunction(1 / val);
}

float acotFunction(float val)
{
    return atanFunction(1 / val);
}

void clearfpuregisters()
{
    _asm {
        mov ecx,8
        clearfpuloop:
        fldz
        loop clearfpuloop
        mov ecx, 100000
        clearfpuloop2:
        fdecstp
        loop clearfpuloop2
    }
}
