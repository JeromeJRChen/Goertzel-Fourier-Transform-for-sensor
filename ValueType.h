// int(2byte), long(4byte), long long(8byte), float(4byte), double(8byte)
//VALTYP1 can be float or doubfloat_verle, more accu
//VALTYP2 can be any type by different fun (fixed point or float point)
//VALTYP3 can be int(2byte) or higher, but is eff by int
#ifndef VALUE_TYPE_H__
#define VALUE_TYPE_H__
// only can select FIXED_VER or FLOAT_VER, depending on VALTYP2
#define FIXED_VER

#ifdef FLOAT_VER
#define VALTYP1 double
#define VALTYP2 float
#define VALTYP3 int
#endif

#ifdef FIXED_VER
#define VALTYP1 float
#define VALTYP2 long long
#define VALTYP3 int
#endif

#endif
