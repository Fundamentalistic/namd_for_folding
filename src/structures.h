/***************************************************************************/
/*                                                                         */
/*              (C) Copyright 1995 The Board of Trustees of the            */
/*                          University of Illinois                         */
/*                           All Rights Reserved                           */
/*								   	   */
/***************************************************************************/

/***************************************************************************
 * RCS INFORMATION:
 *
 *	$RCSfile: structures.h,v $
 *	$Author: nealk $	$Locker:  $		$State: Exp $
 *	$Revision: 1.2 $	$Date: 1996/12/03 17:48:43 $
 *
 ***************************************************************************
 * DESCRIPTION:
 *     structures.h contains useful structures
 *
 ***************************************************************************
 * REVISION HISTORY:
 *
 * $Log: structures.h,v $
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

#ifndef STRUCTURES_H
#define STRUCTURES_H

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

typedef struct nonbondedexcl
{
	int atom1;
	int atom2;
	Index nonbondedexcl_type;
} NonbondedExcl;

typedef struct exclusion
{
	int atom1;
	int atom2;
} Exclusion;

#endif
