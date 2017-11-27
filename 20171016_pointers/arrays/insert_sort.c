/* insert_sort.c : implementing insert sort */
 
# include <stdlib.h>
# include <string.h>
 
# include "helper.h"
 
/*
 * insert sort *
 */
 
int* array_bin_search(int *begin, int *end, int x)
{
	int *mid = begin + (end-begin)/2;
	while(begin<end){
	  if(*mid == x)
	    return mid;
	  else if(*mid>x)
	    end = mid;
	  else
	    begin = mid+1;
	  mid = begin + (end-begin)/2;
	}
	return mid;
}
 
// insert using the naive algo
void array_insert(int *begin, int *end, int x){
  int *i = end-begin;
  while(i > begin && x < *(i-1)){
    *i = *(i-1);
    i--;
  }
  *i = x;
}
 
// insert using binary search
void array_insert_bin(int *begin, int *end, int x){
  int *i = array_bin_search(begin, end, x);
  while(end>i){
    *end = *(end-1);
    end--;
  }
  *i = x;
}
 
void array_insert_sort(int *begin, int *end){
  for(int *i = begin; i < end; i++){
    array_insert(begin, i, *i);
  }
}
 
void array_insert_sort_bin(int *begin, int *end){
  //int *i = array_bin_search()
}
