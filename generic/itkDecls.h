/*
 * itkDecls.h --
 *
 *	Declarations of functions in the platform independent public Tcl API.
 *
 * Copyright (c) 1998-1999 by XXXX
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS:
 */

#ifndef _ITKDECLS
#define _ITKDECLS

#ifdef BUILD_itk
#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLEXPORT
#endif

/*
 * WARNING: This file is automatically generated by the tools/genStubs.tcl
 * script.  Any modifications to the function declarations below should be made
 * in the generic/tk.decls script.
 */

/* !BEGIN!: Do not edit below this line. */

/*
 * Exported function declarations:
 */

/* 0 */
EXTERN int		Itk_Init _ANSI_ARGS_((Tcl_Interp * interp));
/* Slot 1 is reserved */
/* 2 */
EXTERN int		Itk_ConfigBodyCmd _ANSI_ARGS_((ClientData cdata, 
				Tcl_Interp * interp, int objc, 
				Tcl_Obj *CONST objv[]));
/* 3 */
EXTERN int		Itk_UsualCmd _ANSI_ARGS_((ClientData cdata, 
				Tcl_Interp * interp, int objc, 
				Tcl_Obj *CONST objv[]));
/* 4 */
EXTERN int		Itk_ClassOptionDefineCmd _ANSI_ARGS_((
				ClientData cdata, Tcl_Interp * interp, 
				int objc, Tcl_Obj *CONST objv[]));
/* 5 */
EXTERN int		Itk_ClassOptionIllegalCmd _ANSI_ARGS_((
				ClientData cdata, Tcl_Interp * interp, 
				int objc, Tcl_Obj *CONST objv[]));
/* 6 */
EXTERN int		Itk_ConfigClassOption _ANSI_ARGS_((
				Tcl_Interp * interp, ItclObject * contextObj, 
				ClientData cdata, char* newVal));
/* 7 */
EXTERN ItkClassOptTable* Itk_CreateClassOptTable _ANSI_ARGS_((
				Tcl_Interp * interp, ItclClass * cdefn));
/* 8 */
EXTERN ItkClassOptTable* Itk_FindClassOptTable _ANSI_ARGS_((
				ItclClass * cdefn));
/* Slot 9 is reserved */
/* 10 */
EXTERN int		Itk_CreateClassOption _ANSI_ARGS_((
				Tcl_Interp * interp, ItclClass * cdefn, 
				char * switchName, char * resName, 
				char * resClass, char * defVal, 
				char * config, ItkClassOption ** optPtr));
/* 11 */
EXTERN ItkClassOption*	Itk_FindClassOption _ANSI_ARGS_((ItclClass * cdefn, 
				char * switchName));
/* 12 */
EXTERN void		Itk_DelClassOption _ANSI_ARGS_((ItkClassOption * opt));
/* 13 */
EXTERN int		Itk_ArchetypeInit _ANSI_ARGS_((Tcl_Interp* interp));
/* 14 */
EXTERN void		Itk_OptListInit _ANSI_ARGS_((ItkOptList* olist, 
				Tcl_HashTable * options));
/* 15 */
EXTERN void		Itk_OptListFree _ANSI_ARGS_((ItkOptList* olist));
/* 16 */
EXTERN void		Itk_OptListAdd _ANSI_ARGS_((ItkOptList* olist, 
				Tcl_HashEntry * entry));
/* 17 */
EXTERN void		Itk_OptListRemove _ANSI_ARGS_((ItkOptList* olist, 
				Tcl_HashEntry * entry));

typedef struct ItkStubs {
    int magic;
    struct ItkStubHooks *hooks;

    int (*itk_Init) _ANSI_ARGS_((Tcl_Interp * interp)); /* 0 */
    void *reserved1;
    int (*itk_ConfigBodyCmd) _ANSI_ARGS_((ClientData cdata, Tcl_Interp * interp, int objc, Tcl_Obj *CONST objv[])); /* 2 */
    int (*itk_UsualCmd) _ANSI_ARGS_((ClientData cdata, Tcl_Interp * interp, int objc, Tcl_Obj *CONST objv[])); /* 3 */
    int (*itk_ClassOptionDefineCmd) _ANSI_ARGS_((ClientData cdata, Tcl_Interp * interp, int objc, Tcl_Obj *CONST objv[])); /* 4 */
    int (*itk_ClassOptionIllegalCmd) _ANSI_ARGS_((ClientData cdata, Tcl_Interp * interp, int objc, Tcl_Obj *CONST objv[])); /* 5 */
    int (*itk_ConfigClassOption) _ANSI_ARGS_((Tcl_Interp * interp, ItclObject * contextObj, ClientData cdata, char* newVal)); /* 6 */
    ItkClassOptTable* (*itk_CreateClassOptTable) _ANSI_ARGS_((Tcl_Interp * interp, ItclClass * cdefn)); /* 7 */
    ItkClassOptTable* (*itk_FindClassOptTable) _ANSI_ARGS_((ItclClass * cdefn)); /* 8 */
    void *reserved9;
    int (*itk_CreateClassOption) _ANSI_ARGS_((Tcl_Interp * interp, ItclClass * cdefn, char * switchName, char * resName, char * resClass, char * defVal, char * config, ItkClassOption ** optPtr)); /* 10 */
    ItkClassOption* (*itk_FindClassOption) _ANSI_ARGS_((ItclClass * cdefn, char * switchName)); /* 11 */
    void (*itk_DelClassOption) _ANSI_ARGS_((ItkClassOption * opt)); /* 12 */
    int (*itk_ArchetypeInit) _ANSI_ARGS_((Tcl_Interp* interp)); /* 13 */
    void (*itk_OptListInit) _ANSI_ARGS_((ItkOptList* olist, Tcl_HashTable * options)); /* 14 */
    void (*itk_OptListFree) _ANSI_ARGS_((ItkOptList* olist)); /* 15 */
    void (*itk_OptListAdd) _ANSI_ARGS_((ItkOptList* olist, Tcl_HashEntry * entry)); /* 16 */
    void (*itk_OptListRemove) _ANSI_ARGS_((ItkOptList* olist, Tcl_HashEntry * entry)); /* 17 */
} ItkStubs;

#ifdef __cplusplus
extern "C" {
#endif
extern ItkStubs *itkStubsPtr;
#ifdef __cplusplus
}
#endif

#if defined(USE_ITK_STUBS) && !defined(USE_ITK_STUB_PROCS)

/*
 * Inline function declarations:
 */

#ifndef Itk_Init
#define Itk_Init \
	(itkStubsPtr->itk_Init) /* 0 */
#endif
/* Slot 1 is reserved */
#ifndef Itk_ConfigBodyCmd
#define Itk_ConfigBodyCmd \
	(itkStubsPtr->itk_ConfigBodyCmd) /* 2 */
#endif
#ifndef Itk_UsualCmd
#define Itk_UsualCmd \
	(itkStubsPtr->itk_UsualCmd) /* 3 */
#endif
#ifndef Itk_ClassOptionDefineCmd
#define Itk_ClassOptionDefineCmd \
	(itkStubsPtr->itk_ClassOptionDefineCmd) /* 4 */
#endif
#ifndef Itk_ClassOptionIllegalCmd
#define Itk_ClassOptionIllegalCmd \
	(itkStubsPtr->itk_ClassOptionIllegalCmd) /* 5 */
#endif
#ifndef Itk_ConfigClassOption
#define Itk_ConfigClassOption \
	(itkStubsPtr->itk_ConfigClassOption) /* 6 */
#endif
#ifndef Itk_CreateClassOptTable
#define Itk_CreateClassOptTable \
	(itkStubsPtr->itk_CreateClassOptTable) /* 7 */
#endif
#ifndef Itk_FindClassOptTable
#define Itk_FindClassOptTable \
	(itkStubsPtr->itk_FindClassOptTable) /* 8 */
#endif
/* Slot 9 is reserved */
#ifndef Itk_CreateClassOption
#define Itk_CreateClassOption \
	(itkStubsPtr->itk_CreateClassOption) /* 10 */
#endif
#ifndef Itk_FindClassOption
#define Itk_FindClassOption \
	(itkStubsPtr->itk_FindClassOption) /* 11 */
#endif
#ifndef Itk_DelClassOption
#define Itk_DelClassOption \
	(itkStubsPtr->itk_DelClassOption) /* 12 */
#endif
#ifndef Itk_ArchetypeInit
#define Itk_ArchetypeInit \
	(itkStubsPtr->itk_ArchetypeInit) /* 13 */
#endif
#ifndef Itk_OptListInit
#define Itk_OptListInit \
	(itkStubsPtr->itk_OptListInit) /* 14 */
#endif
#ifndef Itk_OptListFree
#define Itk_OptListFree \
	(itkStubsPtr->itk_OptListFree) /* 15 */
#endif
#ifndef Itk_OptListAdd
#define Itk_OptListAdd \
	(itkStubsPtr->itk_OptListAdd) /* 16 */
#endif
#ifndef Itk_OptListRemove
#define Itk_OptListRemove \
	(itkStubsPtr->itk_OptListRemove) /* 17 */
#endif

#endif /* defined(USE_ITK_STUBS) && !defined(USE_ITK_STUB_PROCS) */

/* !END!: Do not edit above this line. */

#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLIMPORT

#endif /* _ITKDECLS */

