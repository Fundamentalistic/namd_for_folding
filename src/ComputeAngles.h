/***************************************************************************/
/*                                                                         */
/*              (C) Copyright 1996 The Board of Trustees of the            */
/*                          University of Illinois                         */
/*                           All Rights Reserved                           */
/*									   */
/***************************************************************************/

/***************************************************************************
 * DESCRIPTION:
 *
 ***************************************************************************/

#ifndef COMPUTEANGLE_H
#define COMPUTEANGLE_H

#include "ComputeHomeTuples.h"
class Molecule;

class AngleElem {
public:
    // ComputeHomeTuples interface
    enum { size = 3 };
    AtomID atomID[size];
    int    localIndex[size];
    TuplePatchElem *p[size];
    BigReal computeForce(void);
    // The following is evil, but the compiler chokes otherwise. (JCP)
    static void addTuplesForAtom(void*, AtomID, Molecule*);

    // Internal data
    Index angleType;


  AngleElem() {
    atomID[0] = -1;
    atomID[1] = -1;
    atomID[2] = -1;
    p[0] = NULL;
    p[1] = NULL;
    p[2] = NULL;
  }
  AngleElem(const Angle *a) {
    atomID[0] = a->atom1;
    atomID[1] = a->atom2;
    atomID[2] = a->atom3;
    angleType = a->angle_type;
  }

  AngleElem(AtomID atom0, AtomID atom1, AtomID atom2) {
    if (atom0 > atom2) {  // Swap end atoms so lowest is first!
      AtomID tmp = atom2; atom2 = atom0; atom0 = tmp; 
    }
    atomID[0] = atom0;
    atomID[1] = atom1;
    atomID[2] = atom2;
  }
  ~AngleElem() {};

  int operator==(const AngleElem &a) const {
    return (a.atomID[0] == atomID[0] && a.atomID[1] == atomID[1] &&
        a.atomID[2] == atomID[2]);
  }

  int operator<(const AngleElem &a) const {
    return (atomID[0] < a.atomID[0] ||
            (atomID[0] == a.atomID[0] &&
            (atomID[1] < a.atomID[1] ||
            (atomID[1] == a.atomID[1] &&
             atomID[2] < a.atomID[2]) )));
  }
};

class ComputeAngles : public ComputeHomeTuples<AngleElem>
{
public:

  ComputeAngles(ComputeID c) : ComputeHomeTuples<AngleElem>(c) { ; }

};

#endif
/***************************************************************************
 * RCS INFORMATION:
 *
 *	$RCSfile: ComputeAngles.h,v $
 *	$Author: jim $	$Locker:  $		$State: Exp $
 *	$Revision: 1.7 $	$Date: 1996/11/22 01:45:28 $
 *
 ***************************************************************************
 * REVISION HISTORY:
 *
 * $Log: ComputeAngles.h,v $
 * Revision 1.7  1996/11/22 01:45:28  jim
 * restructured, fixed bugs, now seems to work
 *
 * Revision 1.6  1996/11/19 06:58:37  jim
 * first compiling templated version, needed ugly void* hack
 *
 * Revision 1.5  1996/11/18 21:28:48  ari
 * *** empty log message ***
 *
 * Revision 1.4  1996/11/04 20:06:17  nealk
 * Now it compiles :-)
 *
 * Revision 1.3  1996/11/04 19:29:02  nealk
 * Added angleForce() to system, but it is untested.
 *
 * Revision 1.2  1996/11/04 16:55:46  ari
 * *** empty log message ***
 *
 * Revision 1.1  1996/11/01 21:20:45  ari
 * Initial revision
 *
 * Revision 1.3  1996/10/16 08:22:39  ari
 * *** empty log message ***
 *
 * Revision 1.1  1996/08/19 22:07:49  ari
 * Initial revision
 *
 * Revision 1.4  1996/07/16 01:54:12  ari
 * *** empty log message ***
 *
 * Revision 1.3  96/07/16  01:10:26  01:10:26  ari (Aritomo Shinozaki)
 * Fixed comments, added methods
 * 
 * Revision 1.2  1996/06/25 21:10:48  gursoy
 * *** empty log message ***
 *
 * Revision 1.1  1996/06/24 14:12:26  gursoy
 * Initial revision
 *
 ***************************************************************************/

