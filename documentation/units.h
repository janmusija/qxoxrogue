//
// units.h
// 2026-01-17
// qxoxrogue
//

#ifndef units_h
#define units_h

#include <ncurses.h>
#include <locale.h>
#include <gmpxx.h>

/*
temperature
*/
mpz_class K_to_mK(mpz_class K){
    return K*1000;
}

mpz_class C_to_mK(mpz_class C){
    return C*1000 + 273150;
}

mpz_class F_to_mK(mpz_class F){
    return (F*5000 + 2298350 + 5)/9; // (F*5000 + 2298350)/9 is the actual conversion; +5 for rounding reasons.
}

mpz_class mK_to_K(mpz_class mK){
    return (mK + 500)/1000; // +500 for rounding reasons
}

mpz_class mK_to_C(mpz_class mK){
    return (mK - 273150 + 500)/1000; // +500 for rounding reasons
}

mpz_class mK_to_F(mpz_class mK){
    return (mK*9 - 2298350 + 2500)/5000; // +2500 for rounding reasons
}

/*
mass
*/
mpz_class kg_to_g(mpz_class kg){
    return kg*1000;
}

mpz_class g_to_kg(mpz_class g){
    return (g+500)/1000; // +500 for rounding reasons
}

/*
density
*/

mpz_class g_cm3_to_g_m3(mpz_class g_cm3){
    return g_cm3*1000000;
}

mpz_class kg_m3_to_g_m3(mpz_class kg_m3){
    return kg_m3*1000;
}

mpz_class g_m3_to_g_cm3(mpz_class g_m3){
    return (g_m3+500000)/1000000; // +500000 for rounding reasons
}

mpz_class g_m3_to_kg_m3(mpz_class g_m3){
    return (g_m3+500)/1000; // +500 for rounding reasons
}

#endif // units.h