#include "Field.h"
#include <iostream>
#include <vector>

/**
 * Constructor creates a 10x10 grid with no mines
**/
 Field::Field()
 {
 	_map.resize(FIELD_DIMENSION);
 	for(unsigned int i=0; i < _map.size(); i++)
 	{
 		_map[i].resize(FIELD_DIMENSION);
 		for(unsigned int j=0; j < _map[i].size(); j++)
 		{
 			_map[i][j] = EMPTY_HIDDEN;
 		}
 	}
 }

 /**
  * Places a mine at the x,y coordinate in the field
 **/
 void Field::placeMine(int x, int y)
 {
 	if(x < 0 || x >= FIELD_DIMENSION || y < 0 || y >= FIELD_DIMENSION)
 	{
 		throw -1;
 	}
 	else
 		_map[x][y] = MINE_HIDDEN;
 }

/**
 * Retrieves the state of the field at location (x,y)
**/
FieldType Field::get(int x, int y)
{
	if(x < 0 || x >= FIELD_DIMENSION || y < 0 || y >= FIELD_DIMENSION)
 	{
 		throw -1;
 	}
 	else
 		return _map[x][y];
}

/**
 * Returns whether or not _map at (x,y) has a mine and throws an
 * exception if the location is illegal
**/
 bool Field::isSafe(int x, int y)
 {
 	//TODO: Complete this function, isSafe(int,int)
        FieldType fy=get(x,y);
	   if(fy==MINE_HIDDEN)
           {
		fy=MINE_SHOWN;
               revealAdjacent(x,y);
	   }
	   else if(fy==EMPTY_HIDDEN)
	   {
		fy=EMPTY_SHOWN;
               revealAdjacent(x,y);
           }
           else
	    {
	        return false;
            }	
 	return true;
 }

/**
 * Changes the location from EMPTY_HIDDEN to EMPTY_SHOWN for the 
 * location and any valid locations adjacent (immediately above,
 * below, left, or right as printed) to the provided (x,y) location
**/
void Field::revealAdjacent(int x, int y)
{
	//TODO: Complete this function, revealAdjacent(int,int)
      FieldType fy=get(x,y);
      if(fy==MINE_SHOWN)
      {
        FieldType fy1=get(x+1,y);
        if(fy1==EMPTY_HIDDEN)
	{
		_map[x+1][y] = EMPTY_SHOWN;	}
        FieldType fy2=get(x-1,y);
        if(fy2==EMPTY_HIDDEN)
	 {
		_map[x-1][y] = EMPTY_SHOWN;
	 }
        FieldType fy3=get(x,y+1);
        if(fy3==EMPTY_HIDDEN)
	 {
		_map[x][y+1] = EMPTY_SHOWN;
	 }
	 FieldType fy4=get(x,y-1);
        if(fy4==EMPTY_HIDDEN)
	 {
		_map[x][y-1] = EMPTY_SHOWN;
	 }
      }
      else if(fy==EMPTY_SHOWN)
      {
        FieldType fy1=get(x+1,y);
        if(fy1==EMPTY_HIDDEN)
	{
		_map[x+1][y] = EMPTY_SHOWN;
	}
        FieldType fy2=get(x-1,y);
        if(fy2==EMPTY_HIDDEN)
	 {
		_map[x-1][y] = EMPTY_SHOWN;
	 }
        FieldType fy3=get(x,y+1);
        if(fy3==EMPTY_HIDDEN)
	 {
		_map[x][y+1] = EMPTY_SHOWN;
	 }
	 FieldType fy4=get(x,y-1);
        if(fy4==EMPTY_HIDDEN)
	 {
		_map[x][y-1] = EMPTY_SHOWN;
	 }
      }
     else
	{
	}
       
}