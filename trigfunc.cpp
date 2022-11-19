//Team Fortress 3's trignometric functions
//Made by DavidB420, based on code from Doors NX calculator application, (2021-2022)

#include "trigfunc.h"

float sinFunction(float val)
{
    _asm {
        fninit //Initialize x87 FPU
        fld val //Load value onto FPU stack
        mov eax, 180 //Push 180 onto stack
        push eax
        fidiv[esp] //convert value to radians
        fldpi
        fmul
        fsin //Floating point sine function
        fwait //Wait until FPU is done its stuff
        fst val //Pop value from FPU stack back to variable
        pop eax //Pop value back from stack
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
        fninit //Initialize x87 FPU
        fld val //Load value onto FPU stack
        mov eax, 180 //Push 180 onto stack
        push eax
        fidiv[esp] //convert value to radians
        fldpi
        fmul
        fst st(1) //Copy contents of st0 register to st1
        fsin //Get sine value
        fxch st(1) //Swap values of st0 and st1 registers
        fcos //Get cosine value
        fdiv st(1), st(0) //Use trig identites to get tangent
        fxch st(1) //Swap st0 and st1
        fwait //Wait for FPU to finish its stuff
        fst val //Pop value back into variable
        pop eax //Pop value back from stack
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
        fninit //Initialize x87 FPU
        fld val //Load value onto FPU stack (Convert to arcsin to arctan, there is no arcsin instruction)
        fld st(0) //Duplicate st0
        fmul st(0),st(0) //Multiplies st1 by itself
        fld1 //Load 1 onto stack
        fsubr //Reverse subtract
        fsqrt //Square root
        fpatan //Get arctan
        fst val
    }
    clearfpuregisters(); //Clear FPU stack
    _asm {
        fninit //Convert from radians to degrees
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
        fxch st(1) //Trig relation is reciprocal of arcsin -> arctan 
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
