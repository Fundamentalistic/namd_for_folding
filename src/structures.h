//-*-c++-*-
/***************************************************************************/
/*                                                                         */
/*              (C) Copyright 1995 The Board of Trustees of the            */
/*                          University of Illinois                         */
/*                           All Rights Reserved                           */
/*								   	   */
/***************************************************************************/

/***************************************************************************
 * DESCRIPTION:
 *     structures.h contains useful structures
 *
 ***************************************************************************/

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "common.h"

// forward references
class IntList;


// status elements, used for Atom status 
#define UnknownAtom      0x00
#define HydrogenAtom     0x01
#define OxygenAtom       0x02
#define HBDonorAtom      0x04
#define HBAcceptorAtom   0x08
#define HBAntecedentAtom 0x10
#define HBHydrogenAtom   0x20


typedef unsigned short Index;		//  Used for index into arrays
					//  or parameters

typedef struct atom_name_info
{
	char *resname;
	char *atomname;
	char *atomtype;
} AtomNameInfo;

typedef struct atom_constants
{
	Real mass;
	Real charge;
	Index vdw_type;
	int status;	         // flags telling about this atom
	int partner;             // connecting atom, for hydrogens
	IntList *donorList;      // donor-hydrogen pairs this is part of
	IntList *acceptorList;   // acceptor-anteced pairs this is part of
} Atom;

typedef struct bond
{
	int atom1;
	int atom2;
	Index bond_type;
} Bond;

typedef struct angle
{
	int atom1;
	int atom2;
	int atom3;
	Index angle_type;
} Angle;

typedef struct dihedral
{
	int atom1;
	int atom2;
	int atom3;
	int atom4;
	Index dihedral_type;
} Dihedral;

typedef struct improper
{
	int atom1;
	int atom2;
	int atom3;
	int atom4;
	Index improper_type;
} Improper;

class Exclusion
{
public:
	Exclusion(void) : modified(0) {;}
	Exclusion(int a1, int a2, int mod = 0) :
		atom1(a1), atom2(a2), modified(mod) {;}
	int atom1;
	int atom2;
	Index modified;
	int hash(void) const
	{
		return atom1 + atom2;
	}
	int operator==(const Exclusion &o) const
	{
		return atom1 == o.atom1 && atom2 == o.atom2;
	}
	int operator<(const Exclusion &o) const
	{
		return
		(
		  ( atom1 < o.atom1 ) ||
		  ( atom1 == o.atom1 && atom2 < o.atom2 ) ||
		  ( atom1 == o.atom1 && atom2 == o.atom2 )
		);
	}
};

#endif
/***************************************************************************
 * RCS INFORMATION:
 *
 *	$RCSfile: structures.h,v $
 *	$Author: jim $	$Locker:  $		$State: Exp $
 *	$Revision: 1.1002 $	$Date: 1997/03/11 04:07:56 $
 *
 * REVISION HISTORY:
 *
 * $Log: structures.h,v $
 * Revision 1.1002  1997/03/11 04:07:56  jim
 * Eliminated use of LintList for by-atom lists.
 * Now uses little arrays managed by ObjectArena<int>.
 *
 * Revision 1.1001  1997/02/10 08:14:35  jim
 * Fixed problem with exclusions where both modified and unmodified
 * versions of the same exclusion could be placed in the list, causing
 * one to be selected more or less randomly.  Also caused different
 * results on different numbers of processors.
 *
 * Revision 1.1000  1997/02/06 15:59:39  ari
 * Resetting CVS to merge branches back into the main trunk.
 * We will stick to main trunk development as suggested by CVS manual.
 * We will set up tags to track fixed points of development/release
 * as suggested by CVS manual - all praise the CVS manual.
 *
 * Revision 1.778  1997/01/28 00:31:41  ari
 * internal release uplevel to 1.778
 *
 * Revision 1.777.2.1  1997/01/27 22:45:47  ari
 * Basic Atom Migration Code added.
 * Added correct magic first line to .h files for xemacs to go to C++ mode.
 * Compiles and runs without migration turned on.
 *
 * Revision 1.777  1997/01/17 19:37:17  ari
 * Internal CVS leveling release.  Start development code work
 * at 1.777.1.1.
 *
 * Revision 1.3  1996/12/06 06:51:02  jim
 * made Exclusion a class, combined with old nonbondedexcl
 *
 * Revision 1.2  1996/12/03 17:48:43  nealk
 * Added nonbondedexcl.
 *
 * Revision 1.1  1996/08/06 20:38:38  ari
 * Initial revision
 *
 * Revision 1.6  1996/04/23 22:44:48  billh
 * Modified Atom structure to store a list of the hydrogen bond pairs
 * each atom participates in.
 *
 * Revision 1.5  1996/04/18 18:45:52  billh
 * Modified Atom structure to store status and partner items.
 *
 * Revision 1.4  1995/03/08 14:46:32  nelson
 * Added copyright
 *
 * Revision 1.3  94/10/28  12:49:04  12:49:04  nelson (Mark T. Nelson)
 * Added AtomName structure to split out naming information
 * 
 * Revision 1.2  94/07/08  13:00:39  13:00:39  nelson (Mark T. Nelson)
 * changed for index based parameters and add RCS header
 * 
 ***************************************************************************/
