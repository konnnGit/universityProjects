/*
 * Konstantinos Spalas
 *
 * This program checks whether a number 
 * is prime
 * 
 * /*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

*/

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

void Twins(int array[] , int array[]);
bool IsPrime(int n);

main()
{
	int input, array[3],i,low,high,k=0;
	printf("Please enter the low border of the field to search for prime nums: ");
	//input = GetInteger();
	scanf ("%d",&low);
	printf("Please enter the high border of the field : ");
	scanf ("%d",&high);
	for(i=low;i<high;i++){

	  if(IsPrime(i) == TRUE){
		  printf("The %d is a PRIME!\n",i); array[k]=i} k++;
		  Twins(array[k],array[k-1]);
	  //else
		 // printf("The integer you entered is NOT a prime\n");
	}
}
void Twins(int , int)
{
	if (array[i]-array[i-1]==2)
	printf ("%d,%d", array[i-1],array[i] twins);
}
	
bool IsPrime(int n)
{
	int i;
	double limit;

	if (n <= 1) return (FALSE);
	if (n == 2) return (TRUE);
	if (n % 2 == 0) return (FALSE);
	limit = sqrt(n) + 1;
	for(i = 3; i <= limit; i+=2) {
		if (n % i == 0) return (FALSE);
	}

	return (TRUE);
}
