//-*-c++-*-
/***************************************************************************/
/*                                                                         */
/*              (C) Copyright 1995 The Board of Trustees of the            */
/*                          University of Illinois                         */
/*                           All Rights Reserved                           */
/*									   */
/***************************************************************************/
/* DESCRIPTION:                                                            */
/*                                                                         */
/***************************************************************************/
#ifndef LJTABLE_H
#define LJTABLE_H

#include "common.h"
#include "ProcessorPrivate.h"

class LJTable
{
public:
  struct TableEntry
  {
    BigReal exclcut2;
    BigReal A;
    BigReal B;
  };

  static LJTable *Instance(void);
  inline static LJTable *Object(void) {return CpvAccess(LJTable_instance);}
  ~LJTable(void);

  inline TableEntry *table_entry(const int index) const;
  inline int table_index(const int i,const int j, const int scaled14) const;
  inline void get_LJ_params(const int index, BigReal *A, BigReal *B) const;
  inline TableEntry *table_val(const int gi, const int gj, 
			       const int scaled14) const;
  inline TableEntry *table_val(const int gi, const int gj) const;

protected:
  LJTable(void);

private:

  void compute_vdw_params(int i, int j, 
			  TableEntry *cur, TableEntry *cur_scaled);

  TableEntry *table;
  int half_table_sz;
  int table_dim;

};

//======================================================================
inline LJTable::TableEntry *LJTable::table_entry(const int index) const
{
  return &(table[index]);
}

//----------------------------------------------------------------------
inline int 
LJTable::table_index(const int i, const int j, const int scaled14) const
{
#ifdef NAMD_DEBUG
  if ((i<0) || (i>=table_dim) || (j<0) || (j>table_dim))
  {
    NAMD_die("Unexpected LJ table value requested in LJTable::table_index()");
  }
#endif

  return i * table_dim + j + (scaled14 ? half_table_sz : 0);
}

//----------------------------------------------------------------------
inline LJTable::TableEntry *
LJTable::table_val(const int i, const int j, const int scaled14) const
{
#if NAMD_DEBUG
  if ((i<0) || (i>=table_dim) || (j<0) || (j>table_dim))
  {
    NAMD_die("Unexpected LJ table value requested in LJTable::table_val()");
  }
#endif
  return table + i * table_dim + j + (scaled14 ? half_table_sz : 0);
}

//----------------------------------------------------------------------
inline LJTable::TableEntry *
LJTable::table_val(const int i, const int j) const
{
#if NAMD_DEBUG
  if ((i<0) || (i>=table_dim) || (j<0) || (j>table_dim))
  {
    NAMD_die("Unexpected LJ table value requested in LJTable::table_val()");
  }
#endif
  return table + i * table_dim + j;
}

//----------------------------------------------------------------------
inline void 
LJTable::get_LJ_params(const int index, BigReal *A, BigReal *B) const
{
  TableEntry *cur = table + index;

  *A = cur->A;
  *B = cur->B;
  
return;
}

#endif

/***************************************************************************
 * RCS INFORMATION:
 *
 *	$RCSfile: LJTable.h,v $
 *	$Author: milind $	$Locker:  $		$State: Exp $
 *	$Revision: 1.1002 $	$Date: 1997/11/07 20:17:39 $
 *
 ***************************************************************************
 * REVISION HISTORY:
 *
 * $Log: LJTable.h,v $
 * Revision 1.1002  1997/11/07 20:17:39  milind
 * Made NAMD to run on shared memory machines.
 *
 * Revision 1.1001  1997/04/04 23:34:19  milind
 * Got NAMD2 to run on Origin2000.
 * Included definitions of class static variables in C files.
 * Fixed alignment bugs by using memcpy instead of assignment in
 * pack and unpack.
 *
 * Revision 1.1000  1997/02/06 15:58:36  ari
 * Resetting CVS to merge branches back into the main trunk.
 * We will stick to main trunk development as suggested by CVS manual.
 * We will set up tags to track fixed points of development/release
 * as suggested by CVS manual - all praise the CVS manual.
 *
 * Revision 1.778  1997/01/28 00:30:44  ari
 * internal release uplevel to 1.778
 *
 * Revision 1.777.2.1  1997/01/27 22:45:20  ari
 * Basic Atom Migration Code added.
 * Added correct magic first line to .h files for xemacs to go to C++ mode.
 * Compiles and runs without migration turned on.
 *
 * Revision 1.777  1997/01/17 19:36:18  ari
 * Internal CVS leveling release.  Start development code work
 * at 1.777.1.1.
 *
 * Revision 1.6  1996/11/20 23:17:23  jim
 * added missing #ifndef LJTABLE_H idiom
 *
 * Revision 1.5  1996/11/05 04:59:56  jim
 * Added exclcut2 to table.
 *
 * Revision 1.4  1996/10/31 22:19:51  jim
 * first incarnation in NAMD 2.0, added singleton pattern
 *
 * Revision 1.3  1996/10/12 21:42:18  brunner
 * Fixed NAMD_DEBUG test, and added table_val
 *
 * Revision 1.2  1996/10/12 00:11:27  brunner
 * Optimized table_index a bit, and took out bounds checking
 *
 * Revision 1.1  1996/10/08 04:49:01  brunner
 * Initial revision
 *
 ***************************************************************************/
