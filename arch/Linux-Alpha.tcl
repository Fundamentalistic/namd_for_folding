
TCLDIR=/Projects/namd2/tcl/alphalinux
TCLINCL=-I$(TCLDIR)/include
TCLLIB=-L$(TCLDIR)/lib -ltcl8.3
TCLFLAGS=-DNAMD_TCL
TCL=$(TCLINCL) $(TCLFLAGS)

