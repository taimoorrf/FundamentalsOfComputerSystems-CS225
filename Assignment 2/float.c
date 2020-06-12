/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features andhttps://scontent.flhe2-1.fna.fbcdn.net/v/t1.0-9/44298338_1945667078805712_3395333267107348480_n.jpg?_nc_cat=111&oh=d539121f758dcc3102e69ea8b19220b3&oe=5C4F4222
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

/*Note: I discussed some of the logics of this assignment with Muhammad Nouman Abbasi (21100177)*/
int float_f2i(unsigned uf) {
  	
	int exp,frac,E;
	frac=uf&0x7fffff; 	//Fraction part is extracted by taking & of the original float with a string of 0s and 23 1s. Shifting not 					needed since fraction part is at the end of the float
	
	exp=(uf>>23)&0xff;	//Exp part is extracted by first shifting it 23 bit to the right, hence removing the fraction part. Then we 					take an & with a string of 0s and 8 1s to remove the 's' value.

	E=exp-127;
				//Checking if exp part is a string of 1s. We don't need to check the fraction part since both the condtions 					for NaN and Infinity for fraction are opposite to each other
	if (exp==0xff)
	return 0x80000000;
	


	if (E>30)		//Check if number if out of range
	return 0x80000000;
	
	if (E<0)		
	return 0;
	
	if (exp==0)
	return 0;
	
	frac=frac|0x1<<23;	//Adding a "1" at the start of frac
	

	if (E>=23)		//Preserving the bits
	frac =frac<<(E-23); 
  	else
	frac = frac>>(23-E);	
	
	if (uf>>31)		//Checking if positive or negative, and returning the appropriate bit pattern
	return -frac;
	else
	return frac;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {

  
    	int E = 158;
	int Tmin=0x80000000;			//E=Exp+bias
    	int signbit=x&Tmin;			//& with 1 followed by 31 0s gives us the sign of the origianl floating point number
    	int frac;
    	int exp;
	int result;  
	/*Special cases*/	
	if (x==0)				//Check for 0
        return 0;  
	
	if (x==Tmin)
	return Tmin|(0x4f000000);		//Change 
	
	if (x<0)				//Check for negative 
	x=-x;					//Convert to positive

	while(!(x&Tmin))
	{
	  x=x<<1;				//Shifting left till the leading bit in x is at the start
	  E=E-1;				
	} 
	exp=E<<23;
	frac=(x&(~Tmin))>>8;			//Extracting the fraction from x
	
	if ( ((x&0x7f)>0 || frac&1) && (x&0x80) ) // Rounding the value off
	frac=frac+1;
	
	result=signbit+exp+frac;
return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {

	int exp,frac;
	int mask=0x80000000;
	frac=uf&0x7fffff; 	//Fraction part is extracted by taking & of the original float with a string of 0s and 23 1s. Shifting not 					needed since fraction part is at the end of the float
	
	exp=(uf>>23)&0xff;	//Exp part is extracted by first shifting it 23 bit to the right, hence removing the fraction part. Then we 					take an & with a string of 0s and 8 1s to remove the 's' value.
	if (exp==0xff)		//Checking if exp part is a string of 1s.
	{	if (frac!=0)	//Checking if the fraction part is not a string of 0s.
		return uf;
	}
	
 return uf^mask;		//Exclusive or with 1 followed by a string of 31 0s gives us the negative of the original
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	//To multiply a float with two, we can take a left shift by 1

	//But then, the left most bit which signifies the sign of the float gets replaced as well. So we need to preserve that sign 		so that we can later use it to restore the sign of the floating point number.
	unsigned sign=uf&0x80000000; 	//Preserving the sign for the original floating point number.
	unsigned exp=(uf>>23)&0xff;	// Separating the Exp from the floating point. (To be used for checks)
	unsigned frac=uf&0x7fffff;	// Separating the fraction part.
	unsigned fracandexp=(exp|frac);	// Joining the fraction and exp part.
	unsigned fracandexpleft=(fracandexp<<1);	//Shifting them both collectively to the left (Multiplies by 2)
	unsigned final=(sign|fracandexpleft);		//Taking an "or" with the sign to restore the sign of the original floating point.
	
	if(exp==0x00)			//Check for a denormalized value
 	return final;
	if (exp==0xff)			//Check for NaN	and Inf
	return uf;
	if(uf==0 || uf==0x80000000)	//Check for a 0 number
	return uf;
	


return uf+(1<<23); //Simply adding a 1 to the exp value (Which multiplies it with 2)
}
