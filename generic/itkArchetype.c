/*
 * ------------------------------------------------------------------------
 *      PACKAGE:  [incr Tk]
 *  DESCRIPTION:  Building mega-widgets with [incr Tcl]
 *
 *  [incr Tk] provides a framework for building composite "mega-widgets"
 *  using [incr Tcl] classes.  It defines a set of base classes that are
 *  specialized to create all other widgets.
 *
 *  This part adds C implementations for some of the methods in the
 *  base class itk::Archetype.
 *
 *    Itk_ArchComponentCmd   <=> itk_component
 *    Itk_ArchOptionCmd      <=> itk_option
 *    Itk_ArchInitCmd        <=> itk_initialize
 *    Itk_ArchCompAccessCmd  <=> component
 *    Itk_ArchConfigureCmd   <=> configure
 *    Itk_ArchCgetCmd        <=> cget
 *
 *    Itk_ArchInitOptsCmd    <=> _initOptionInfo (used to set things up)
 *    Itk_ArchDeleteOptsCmd  <=> _deleteOptionInfo (used to clean things up)
 *
 * ========================================================================
 *  AUTHOR:  Michael J. McLennan
 *           Bell Labs Innovations for Lucent Technologies
 *           mmclennan@lucent.com
 *           http://www.tcltk.com/itcl
 *
 *     RCS:  $Id: itkArchetype.c,v 1.1.2.1 2007/09/08 12:03:22 wiede Exp $
 * ========================================================================
 *           Copyright (c) 1993-1998  Lucent Technologies, Inc.
 * ------------------------------------------------------------------------
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */
#include <assert.h>
#include "itkInt.h"

void
ItclShowArgs(
    const char *str,
    int objc,
    Tcl_Obj * const* objv)
{
    int i;
    fprintf(stderr, "%s", str);
    for (i = 0; i < objc; i++) {
        fprintf(stderr, "!%s", objv[i] == NULL ? "??" :
                Tcl_GetString(objv[i]));
    }
    fprintf(stderr, "!\n");
}

struct NameProcMap { const char *name; Tcl_ObjCmdProc *proc; };

/*
 * List of commands that are used to implement the [info object] subcommands.
 */

static const struct NameProcMap archetypeCmds[] = {
    { "::itcl::builtin::Archetype::cget", Itk_ArchCgetCmd },
    { "::itcl::builtin::Archetype::component", Itk_ArchCompAccessCmd },
    { "::itcl::builtin::Archetype::configure", Itk_ArchConfigureCmd },
    { "::itcl::builtin::Archetype::delete", Itk_ArchDeleteOptsCmd },
    { "::itcl::builtin::Archetype::init", Itk_ArchInitOptsCmd },
    { "::itcl::builtin::Archetype::itk_component", Itk_ArchComponentCmd },
    { "::itcl::builtin::Archetype::itk_initialize", Itk_ArchInitCmd },
    { "::itcl::builtin::Archetype::itk_option", Itk_ArchOptionCmd },
    { NULL, NULL }
};


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchetypeInit()
 *
 *  Invoked by Itk_Init() whenever a new interpreter is created to
 *  declare the procedures used in the itk::Archetype base class.
 * ------------------------------------------------------------------------
 */
int
Itk_ArchetypeInit(
    Tcl_Interp *interp)  /* interpreter to be updated */
{
    ArchMergeInfo *mergeInfo;
    Tcl_Namespace *parserNs;
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     *  Declare all of the C routines that are integrated into
     *  the Archetype base class.
     */
    if (Itcl_RegisterObjC(interp,
            "Archetype-init", Itk_ArchInitOptsCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK ||

        Itcl_RegisterObjC(interp,
            "Archetype-delete", Itk_ArchDeleteOptsCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK ||

        Itcl_RegisterObjC(interp,
            "Archetype-itk_component", Itk_ArchComponentCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK ||

        Itcl_RegisterObjC(interp,
            "Archetype-itk_option", Itk_ArchOptionCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK ||

        Itcl_RegisterObjC(interp,
            "Archetype-itk_initialize", Itk_ArchInitCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK ||

        Itcl_RegisterObjC(interp,
            "Archetype-component", Itk_ArchCompAccessCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK ||

        Itcl_RegisterObjC(interp,
            "Archetype-configure",Itk_ArchConfigureCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK ||

        Itcl_RegisterObjC(interp,
            "Archetype-cget",Itk_ArchCgetCmd,
            (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL) != TCL_OK) {

        return TCL_ERROR;
    }

    /*
     * Build the ensemble used to implement [_archetype].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::itcl::builtin::Archetype",
        NULL, NULL);
if (nsPtr == NULL) {
fprintf(stderr, "error in creating namespace: ::itcl::builtin::Archetype \n");
}
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
       TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; archetypeCmds[i].name!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, archetypeCmds[i].name,
                archetypeCmds[i].proc, NULL, NULL);
    }

    /*
     *  Create the namespace containing the option parser commands.
     */
    mergeInfo = (ArchMergeInfo*)ckalloc(sizeof(ArchMergeInfo));
    Tcl_InitHashTable(&mergeInfo->usualCode, TCL_STRING_KEYS);
    mergeInfo->archInfo    = NULL;
    mergeInfo->archComp    = NULL;
    mergeInfo->optionTable = NULL;

    parserNs = Tcl_CreateNamespace(interp, "::itk::option-parser",
        (ClientData)mergeInfo, Itcl_ReleaseData);

    if (!parserNs) {
        Itk_DelMergeInfo((char*)mergeInfo);
        Tcl_AddErrorInfo(interp, "\n    (while initializing itk)");
        return TCL_ERROR;
    }
    Itcl_PreserveData((ClientData)mergeInfo);
    Itcl_EventuallyFree((ClientData)mergeInfo, Itk_DelMergeInfo);

    Tcl_CreateObjCommand(interp, "::itk::option-parser::keep",
        Itk_ArchOptKeepCmd,
        (ClientData)mergeInfo, (Tcl_CmdDeleteProc*)NULL);

    Tcl_CreateObjCommand(interp, "::itk::option-parser::ignore",
        Itk_ArchOptIgnoreCmd,
        (ClientData)mergeInfo, (Tcl_CmdDeleteProc*)NULL);

    Tcl_CreateObjCommand(interp, "::itk::option-parser::rename",
        Itk_ArchOptRenameCmd,
        (ClientData)mergeInfo, (Tcl_CmdDeleteProc*)NULL);

    Tcl_CreateObjCommand(interp, "::itk::option-parser::usual",
        Itk_ArchOptUsualCmd,
        (ClientData)mergeInfo, (Tcl_CmdDeleteProc*)NULL);

    /*
     *  Add the "itk::usual" command to register option handling code.
     */
    Tcl_CreateObjCommand(interp, "::itk::usual", Itk_UsualCmd,
        (ClientData)mergeInfo, Itcl_ReleaseData);
    Itcl_PreserveData((ClientData)mergeInfo);

    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchetypeCmd()
 *
 *  Invoked whenever the user issues the "_archetype" method.
 *  Handles the following syntax:
 *
 *    _archetype cget
 *    _archetype component
 *    _archetype configure
 *    _archetype delete
 *    _archetype init
 *    _archetype itk_component
 *    _archetype itk_initialize
 *    _archetype itk_option
 *
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchetypeCmd(
    ClientData clientData,   /* class definition */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
//ItclShowArgs("Itk_ArchetypeCmd", objc, objv);
    if (objc == 1) {
        /* produce usage message */
        Tcl_Obj *objPtr = Tcl_NewStringObj(
                "wrong # args: should be one of...\n", -1);
//        ItclGetInfoUsage(interp, objPtr);
        Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
        return TCL_ERROR;
    }
    return ItclEnsembleSubCmd(clientData, interp, "::itcl::builtin::Archetype",
            objc, objv, "Itk_ArchetypeCmd");
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchInitOptsCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::_initOptionInfo
 *  method.  This method should be called out in the constructor for
 *  each object, to initialize the object so that it can be used with
 *  the other access methods in this file.  Allocates some extra
 *  data associated with the object at the C-language level.
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchInitOptsCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int newEntry;
    int result;
    ArchInfo *info;
    ItclClass *contextClass;
    ItclObject *contextObj;
    Tcl_HashTable *objsWithArchInfo;
    Tcl_HashEntry *entry;

//ItclShowArgs("Itk_ArchInitOptsCmd", objc, objv);
    if (objc != 1) {
        Tcl_WrongNumArgs(interp, 1, objv, "");
        return TCL_ERROR;
    }

    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        char *token = Tcl_GetString(objv[0]);
        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "cannot use \"", token, "\" without an object context",
            (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  Create some archetype info for the current object and
     *  register it on the list of all known objects.
     */
    objsWithArchInfo = ItkGetObjsWithArchInfo(interp);

    info = (ArchInfo*)ckalloc(sizeof(ArchInfo));
    info->itclObj = contextObj;
    info->tkwin = NULL;  /* not known yet */
    Tcl_InitHashTable(&info->components, TCL_STRING_KEYS);
    Tcl_InitHashTable(&info->options, TCL_STRING_KEYS);
    Itk_OptListInit(&info->order, &info->options);

    entry = Tcl_CreateHashEntry(objsWithArchInfo, (char*)contextObj, &newEntry);
    if (!newEntry) {
        Itk_DelArchInfo( Tcl_GetHashValue(entry) );
    }
    Tcl_SetHashValue(entry, (ClientData)info);

    /*
     *  Make sure that the access command for this object
     *  resides in the global namespace.  If need be, move
     *  the command.
     */
    result = TCL_OK;

    Tcl_CmdInfo cmdInfo;
    Tcl_GetCommandInfoFromToken(contextObj->accessCmd, &cmdInfo);
    if (cmdInfo.namespacePtr != Tcl_GetGlobalNamespace(interp)) {
        Tcl_Obj *oldNamePtr, *newNamePtr;

        oldNamePtr = Tcl_NewStringObj((char*)NULL, 0);
        Tcl_GetCommandFullName(interp, contextObj->accessCmd, oldNamePtr);
        Tcl_IncrRefCount(oldNamePtr);

        newNamePtr = Tcl_NewStringObj("::", -1);
        Tcl_AppendToObj(newNamePtr,
            Tcl_GetCommandName(interp, contextObj->accessCmd), -1);
        Tcl_IncrRefCount(newNamePtr);

//fprintf(stderr, "REN initopts!%s!%s!\n", Tcl_GetString(oldNamePtr), Tcl_GetString(newNamePtr));
        result = TclRenameCommand(interp, Tcl_GetString(oldNamePtr),
                Tcl_GetString(newNamePtr));

        Tcl_DecrRefCount(oldNamePtr);
        Tcl_DecrRefCount(newNamePtr);
    }

    return result;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchDeleteOptsCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::_deleteOptionInfo
 *  method.  This method should be called out in the destructor for each
 *  object, to clean up data allocated by Itk_ArchInitOptsCmd().
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchDeleteOptsCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    ItclClass *contextClass;
    ItclObject *contextObj;
    Tcl_HashTable *objsWithArchInfo;
    Tcl_HashEntry *entry;

    if (objc != 1) {
        Tcl_WrongNumArgs(interp, 1, objv, "");
        return TCL_ERROR;
    }
//fprintf(stderr, "Itk_ArchDeleteOptsCmd\n");
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        char *token = Tcl_GetStringFromObj(objv[0], (int*)NULL);
        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "cannot use \"", token, "\" without an object context",
            (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  Find the info associated with this object.
     *  Destroy the data and remove it from the global list.
     */
    objsWithArchInfo = ItkGetObjsWithArchInfo(interp);
    entry = Tcl_FindHashEntry(objsWithArchInfo, (char*)contextObj);

    if (entry) {
        Itk_DelArchInfo( Tcl_GetHashValue(entry) );
        Tcl_DeleteHashEntry(entry);
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchComponentCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::itk_component
 *  method.  Handles the following options:
 *
 *      itk_component add ?-protected? ?-private? ?--? <name> \
 *          <createCmds> ?<optionCmds>?
 *
 *      itk_component delete <name> ?<name>...?
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchComponentCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    char *cmd;
    char *token;
    char c;
    int length;

//ItclShowArgs("Itk_ArchComponentCmd", objc, objv);
//fprintf(stderr, "CURRNS!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName);
    /*
     *  Check arguments and handle the various options...
     */
//fprintf(stderr, "Itk_ArchComponentCmd\n");
    Tcl_DString buffer;
    char *head;
    char *tail;
    cmd = Tcl_GetString(objv[0]);
    Itcl_ParseNamespPath(cmd, &buffer, &head, &tail);
    Tcl_DStringFree(&buffer);
    if (objc < 2) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "wrong # args: should be one of...\n",
            "  ", tail, " add ?-protected? ?-private? ?--? name createCmds ?optionCmds?\n",
            "  ", tail, " delete name ?name name...?",
            (char*)NULL);
        return TCL_ERROR;
    }

    token = Tcl_GetString(objv[1]);
    c = *token;
    length = strlen(token);

    /*
     *  Handle:  itk_component add...
     */
    if (c == 'a' && strncmp(token, "add", length) == 0) {
        if (objc < 4) {
            Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                "wrong # args: should be \"",
                tail,
		" add ?-protected? ?-private? ?--?",
		" name createCmds ?optionCmds?\"",
                (char*)NULL);
            return TCL_ERROR;
        }
        return Itk_ArchCompAddCmd(dummy, interp, objc-1, objv+1);
    } else {

        /*
         *  Handle:  itk_component delete...
         */
        if (c == 'd' && strncmp(token, "delete", length) == 0) {
            if (objc < 3) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "wrong # args: should be \"",
                    tail,
		    " delete name ?name name...?\"",
                    (char*)NULL);
                return TCL_ERROR;
            }
            return Itk_ArchCompDeleteCmd(dummy, interp, objc-1, objv+1);
        }
    }

    /*
     *  Flag any errors.
     */
    cmd = Tcl_GetStringFromObj(objv[0], (int*)NULL);
    Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
        "bad option \"", token,
        "\": should be one of...\n",
        "  ", cmd, " add name createCmds ?optionCmds?\n",
        "  ", cmd, " delete name ?name name...?",
        (char*)NULL);
    return TCL_ERROR;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchInitCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::itk_initialize
 *  method.  This method should be called out in the constructor for
 *  each mega-widget class, to build the composite option list at
 *  each class level.  Handles the following syntax:
 *
 *      itk_initialize ?-option val -option val...?
 *
 *  Integrates any class-based options into the composite option list,
 *  handles option settings from the command line, and then configures
 *  all options to have the proper initial value.
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchInitCmd(dummy, interp, objc, objv)
    ClientData dummy;        /* unused */
    Tcl_Interp *interp;      /* current interpreter */
    int objc;                /* number of arguments */
    Tcl_Obj *CONST objv[];   /* argument objects */
{
    ItclClass *contextClass;
    ItclClass *iclsPtr;
    ItclObject *contextObj;
    ArchInfo *info;

    int i;
    int result;
    CONST char *val;
    char *token;
    ItkClassOption *opt;
    ItkClassOptTable *optTable;
    Itcl_ListElem *part;
    ArchOption *archOpt;
    ArchOptionPart *optPart;
    ItclHierIter hier;
    ItclVariable *ivPtr;
    Tcl_HashSearch place;
    Tcl_HashEntry *entry;

//ItclShowArgs("Itk_ArchInitCmd", objc, objv);
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        token = Tcl_GetString(objv[0]);
        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "improper usage: should be \"object ",
            token, " ?-option value -option value...?\"",
            (char*)NULL);
        return TCL_ERROR;
    }

    ItclObjectInfo *infoPtr;
    infoPtr = (ItclObjectInfo *)Tcl_GetAssocData(interp,
            ITCL_INTERP_DATA, NULL);
//fprintf(stderr, "CCNS!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName);
//fprintf(stderr, "Itk_GetArchInfo 3\n");
    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     *  See what class is being initialized by getting the namespace
     *  for the calling context.
     */
//fprintf(stderr, "cfInfo!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName);
    infoPtr = Tcl_GetAssocData(interp, ITCL_INTERP_DATA, NULL);
    ItclCallContext *callContextPtr;
    callContextPtr = Itcl_GetStackValue(&infoPtr->contextStack,
            Itcl_GetStackSize(&infoPtr->contextStack)-2);
    if (callContextPtr->iclsPtr != NULL) {
        contextClass = callContextPtr->iclsPtr;
    } else {
        contextClass = callContextPtr->ioPtr->iclsPtr;
    }


//fprintf(stderr, "contextClass!%s!\n", contextClass->namesp->fullName);

    /*
     *  Integrate all public variables for the current class
     *  context into the composite option list.
     */
//fprintf(stderr, "look for variables\n");
    Itcl_InitHierIter(&hier, contextClass);
    while ((iclsPtr=Itcl_AdvanceHierIter(&hier)) != NULL) {
        entry = Tcl_FirstHashEntry(&iclsPtr->variables, &place);
        while (entry) {
            ivPtr = (ItclVariable*)Tcl_GetHashValue(entry);

            if (ivPtr->protection == ITCL_PUBLIC) {
                optPart = Itk_FindArchOptionPart(info,
                    Tcl_GetString(ivPtr->namePtr), (ClientData)ivPtr);

//fprintf(stderr, "Itk_FindArchOptionPart!%s!%p!\n", Tcl_GetString(ivPtr->namePtr), optPart);
                if (!optPart) {
                    optPart = Itk_CreateOptionPart(interp, (ClientData)ivPtr,
                        Itk_PropagatePublicVar, (Tcl_CmdDeleteProc*)NULL,
                        (ClientData)ivPtr);

                    val = Itcl_GetInstanceVar(interp,
		            Tcl_GetString(ivPtr->fullNamePtr),
                            contextObj, contextObj->iclsPtr);

                    result = Itk_AddOptionPart(interp, info,
                            Tcl_GetString(ivPtr->namePtr),
			    (char*)NULL, (char*)NULL,
                            val, (char*)NULL, optPart, &archOpt);

                    if (result != TCL_OK) {
                        Itk_DelOptionPart(optPart);
                        return TCL_ERROR;
                    }
                }
            }
            entry = Tcl_NextHashEntry(&place);
        }
    }
    Itcl_DeleteHierIter(&hier);
//fprintf(stderr, "after look for variables\n");

    /*
     *  Integrate all class-based options for the current class
     *  context into the composite option list.
     */
    optTable = Itk_FindClassOptTable(contextClass);
    if (optTable) {
//fprintf(stderr, "optTable!%s!%p!%d!\n", contextClass->namesp->fullName, optTable, optTable->order.len);
        for (i=0; i < optTable->order.len; i++) {
            opt = (ItkClassOption*)Tcl_GetHashValue(optTable->order.list[i]);

            optPart = Itk_FindArchOptionPart(info, Tcl_GetString(opt->namePtr),
                (ClientData)contextClass);
//fprintf(stderr, "opt!%d!%s!%p\n", i, Tcl_GetString(opt->namePtr), optPart);

            if (!optPart) {
                optPart = Itk_CreateOptionPart(interp, (ClientData)opt,
                    Itk_ConfigClassOption, (Tcl_CmdDeleteProc*)NULL,
                    (ClientData)contextClass);

                result = Itk_AddOptionPart(interp, info,
                    Tcl_GetString(opt->namePtr), opt->resName, opt->resClass,
                    opt->init, (char*)NULL, optPart, &archOpt);

                if (result != TCL_OK) {
                    Itk_DelOptionPart(optPart);
                    return TCL_ERROR;
                }
            }
        }
    }

//fprintf(stderr, "after optTable!%p!\n", optTable);
    /*
     *  If any option values were specified on the command line,
     *  override the current option settings.
     */
    if (objc > 1) {
        for (objc--,objv++; objc > 0; objc-=2, objv+=2) {
	    char *value;
            token = Tcl_GetString(objv[0]);
            if (objc < 2) {
	        /* Bug 227814
		 * Ensure that the interp result is unshared.
		 */

	        Tcl_ResetResult(interp);
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "value for \"", token, "\" missing",
                    (char*)NULL);
                return TCL_ERROR;
            }

            value = Tcl_GetString(objv[1]);
            if (Itk_ArchConfigOption(interp, info, token, value) != TCL_OK) {
                return TCL_ERROR;
            }
        }
    }

//fprintf(stderr, "after cmdlin options\n");
    /*
     *  If this is most-specific class, then finish constructing
     *  the mega-widget:
     *
     *  Scan through all options in the composite list and
     *  look for any that have been set but not initialized.
     *  Invoke the parts of uninitialized options to propagate
     *  changes and update the widget.
     */
    if (contextObj->iclsPtr == contextClass) {
        for (i=0; i < info->order.len; i++) {
            archOpt = (ArchOption*)Tcl_GetHashValue(info->order.list[i]);

//fprintf(stderr, "composite !%s!\n", archOpt->switchName);
            if ((archOpt->flags & ITK_ARCHOPT_INIT) == 0) {
                val = Tcl_GetVar2(interp, "itk_option", archOpt->switchName, 0);

                if (!val) {
//fprintf(stderr, "Itk_ArchOptAccessError 1\n");
                    Itk_ArchOptAccessError(interp, info, archOpt);
                    return TCL_ERROR;
                }

                part = Itcl_FirstListElem(&archOpt->parts);
                while (part) {
                    optPart = (ArchOptionPart*)Itcl_GetListValue(part);
                    result  = (*optPart->configProc)(interp, contextObj,
                        optPart->clientData, val);

                    if (result != TCL_OK) {
                        Itk_ArchOptConfigError(interp, info, archOpt);
                        return result;
                    }
                    part = Itcl_NextListElem(part);
                }
                archOpt->flags |= ITK_ARCHOPT_INIT;
            }
        }
    }
//fprintf(stderr, "after composite list\n");

    Tcl_ResetResult(interp);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchOptionCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::itk_option
 *  method.  Handles the following options:
 *
 *      itk_option define <switch> <resName> <resClass> <init> ?<config>?
 *      itk_option add <name> ?<name>...?
 *      itk_option remove <name> ?<name>...?
 *
 *  These commands customize the options list of a specific widget.
 *  They are similar to the "itk_option" ensemble in the class definition
 *  parser, but manipulate a single instance instead of an entire class.
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchOptionCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    char *cmd;
    char *token;
    char c;
    int length;

//ItclShowArgs("Itk_ArchOptionCmd", objc, objv);
    /*
     *  Check arguments and handle the various options...
     */
    if (objc < 2) {
        cmd = Tcl_GetString(objv[0]);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "wrong # args: should be one of...\n",
            "  ", cmd, " add name ?name name...?\n",
            "  ", cmd, " define -switch resourceName resourceClass init ?config?\n",
            "  ", cmd, " remove name ?name name...?",
            (char*)NULL);
        return TCL_ERROR;
    }

    token = Tcl_GetString(objv[1]);
    c = *token;
    length = strlen(token);

    /*
     *  Handle:  itk_option add...
     */
    if (c == 'a' && strncmp(token, "add", length) == 0) {
        if (objc < 3) {
            Tcl_WrongNumArgs(interp, 1, objv, "add name ?name name...?");
            return TCL_ERROR;
        }
        return Itk_ArchOptionAddCmd(dummy, interp, objc-1, objv+1);
    } else {

        /*
         *  Handle:  itk_option remove...
         */
        if (c == 'r' && strncmp(token, "remove", length) == 0) {
            if (objc < 3) {
                Tcl_WrongNumArgs(interp, 1, objv, "remove name ?name name...?");
                return TCL_ERROR;
            }
            return Itk_ArchOptionRemoveCmd(dummy, interp, objc-1, objv+1);
        } else {

            /*
             *  Handle:  itk_option define...
             */
            if (c == 'd' && strncmp(token, "define", length) == 0) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                        "can only ", token, " options at the class level\n",
                        "(move this command into the class definition)",
                        (char*)NULL);
              return TCL_ERROR;
            }
        }
    }

    /*
     *  Flag any errors.
     */
    cmd = Tcl_GetString(objv[0]);
    Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
        "bad option \"", token,
        "\": should be one of...\n",
        "  ", cmd, " add name ?name name...?\n",
        "  ", cmd, " define -switch resourceName resourceClass init ?config?\n",
        "  ", cmd, " remove name ?name name...?",
        (char*)NULL);
    return TCL_ERROR;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchCompAccessCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::component method.
 *  Finds the requested component and invokes the <command> as a method
 *  on that component.
 *
 *  Handles the following syntax:
 *
 *      component
 *      component <name>
 *      component <name> <command> ?<arg> <arg>...?
 *
 *  With no arguments, this command returns the names of components
 *  that can be accessed from the current context.  Note that components
 *  respect public/protected/private declarations, so private and
 *  protected components may not be accessible from all namespaces.
 *
 *  If a component name is specified, then this command returns the
 *  window name for that component.
 *
 *  If a series of arguments follow the component name, they are treated
 *  as a method invocation, and dispatched to the component.
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchCompAccessCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int i;
    int result;
    char *token;
    CONST char *name;
    CONST char *val;
    Tcl_Namespace *callingNs;
    ItclClass *contextClass;
    ItclObject *contextObj;
    Tcl_HashEntry *entry;
    Tcl_HashSearch place;
    ArchInfo *info;
    ArchComponent *archComp;
    int cmdlinec;
    Tcl_Obj *objPtr;
    Tcl_Obj *cmdlinePtr;
    Tcl_Obj **cmdlinev;

//ItclShowArgs("Itk_ArchCompAccessCmd", objc, objv);
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        token = Tcl_GetString(objv[0]);
        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "improper usage: should be \"object ",
            token, " ?name option arg arg...?\"",
            (char*)NULL);
        return TCL_ERROR;
    }

    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    ItclObjectInfo *infoPtr;
    infoPtr = (ItclObjectInfo *)Tcl_GetAssocData(interp,
            ITCL_INTERP_DATA, NULL);
    if (Itcl_GetStackSize(&infoPtr->contextStack) == 1) {
        callingNs = Tcl_GetGlobalNamespace(interp);
    } else {
	ItclCallContext *callContextPtr;
	callContextPtr = Itcl_GetStackValue(&infoPtr->contextStack,
	        Itcl_GetStackSize(&infoPtr->contextStack)-2);
#ifdef NOTDEF
        callingNs = (Tcl_Namespace *)Itcl_GetStackValue(
	        &infoPtr->namespaceStack,
		Itcl_GetStackSize(&infoPtr->namespaceStack)-2);
#endif
        callingNs = callContextPtr->nsPtr;
    }
//fprintf(stderr, "callingNs!%s!%s!\n", callingNs->fullName, contextClass->namesp->fullName);
    /*
     *  With no arguments, return a list of components that can be
     *  accessed from the calling scope.
     */
    if (objc == 2) {
	/* if the name of the component is the empty string ignore that arg */
        if (strlen(Tcl_GetString(objv[1])) == 0) {
	    objc--;
	}
    }
    if (objc == 1) {
        entry = Tcl_FirstHashEntry(&info->components, &place);
        while (entry) {
            archComp = (ArchComponent*)Tcl_GetHashValue(entry);
if (archComp == NULL) {
fprintf(stderr, "ERR 2 archComp == NULL\n");
} else {
//fprintf(stderr, "Itcl_CanAccess2!%s!%d!%s!%s!\n", archComp->iclsPtr->namesp->fullName, archComp->protection, callingNs->fullName, Tcl_GetString(archComp->namePtr));
            if (Itcl_CanAccess2(archComp->iclsPtr, archComp->protection,
	            callingNs)) {
                name = Tcl_GetHashKey(&info->components, entry);
                Tcl_AppendElement(interp, (CONST84 char *)name);
            }
}
            entry = Tcl_NextHashEntry(&place);
        }
        return TCL_OK;
    }

    /*
     *  Make sure the requested component exists.
     */
    token = Tcl_GetString(objv[1]);
    entry = Tcl_FindHashEntry(&info->components, token);
//fprintf(stderr, "FARCHCOMP!%s!%p!\n", token, entry);
    if (entry) {
        archComp = (ArchComponent*)Tcl_GetHashValue(entry);
    } else {
        archComp = NULL;
    }

    if (archComp == NULL) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "name \"", token, "\" is not a component",
            (char*)NULL);
        return TCL_ERROR;
    }

    if (!Itcl_CanAccess2(archComp->iclsPtr, archComp->protection, callingNs)) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "can't access component \"", token, "\" from context \"",
            callingNs->fullName, "\"",
            (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  If only the component name is specified, then return the
     *  window name for this component.
     */
    if (objc == 2) {
//fprintf(stderr, "CNS!%s!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName, callingNs->fullName);
//fprintf(stderr, "��archComp!%s!%s!\n", archComp->pathName, Tcl_GetCommandName(interp, archComp->iclsPtr->accessCmd));
	Tcl_Obj *objPtr;
	objPtr = Tcl_NewObj();
	Tcl_GetCommandFullName(interp, archComp->accessCmd, objPtr);
	Tcl_IncrRefCount(objPtr);
	Tcl_DString buffer;
	Tcl_DStringInit(&buffer);
	Tcl_DStringAppend(&buffer, ITCL_VARIABLES_NAMESPACE, -1);
	Tcl_DStringAppend(&buffer, Tcl_GetString(objPtr), -1);
	Tcl_DecrRefCount(objPtr);
	Tcl_DStringAppend(&buffer, archComp->iclsPtr->namesp->fullName, -1);
//fprintf(stderr, "FND!%s!%p!\n", Tcl_DStringValue(&buffer), Tcl_FindNamespaceVar(interp, Tcl_DStringValue(&buffer), NULL, 0));
	Tcl_Namespace *nsPtr;
	Tcl_CallFrame frame;
	nsPtr = Tcl_FindNamespace(interp, Tcl_DStringValue(&buffer), NULL, 0);
//fprintf(stderr, "nsPtr!%p!\n", nsPtr);
	Tcl_PushCallFrame(interp, &frame, nsPtr, /*isProcCallFrame*/0);
        val = Tcl_GetVar2(interp, "itk_component", token, 0);
	Tcl_DStringFree(&buffer);
	Tcl_PopCallFrame(interp);
        if (!val) {
            Tcl_ResetResult(interp);
            Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                "internal error: cannot access itk_component(", token, ")",
                (char*)NULL);

            if (contextObj->accessCmd) {
                Tcl_Obj *resultPtr = Tcl_GetObjResult(interp);
                Tcl_AppendToObj(resultPtr, " in widget \"", -1);
                Tcl_GetCommandFullName(contextObj->iclsPtr->interp,
                    contextObj->accessCmd, resultPtr);
                Tcl_AppendToObj(resultPtr, "\"", -1);
            }
            return TCL_ERROR;
        }
	/*
	 * Casting away CONST is safe because TCL_VOLATILE guarantees
	 * CONST treatment.
	 */
        Tcl_SetResult(interp, (char *) val, TCL_VOLATILE);
        return TCL_OK;
    }

    /*
     *  Otherwise, treat the rest of the command line as a method
     *  invocation on the requested component.  Invoke the remaining
     *  command-line arguments as a method for that component.
     */
    cmdlinePtr = Tcl_NewListObj(0, (Tcl_Obj**)NULL);
    Tcl_IncrRefCount(cmdlinePtr);

    objPtr = Tcl_NewStringObj((char*)NULL, 0);
    Tcl_GetCommandFullName(interp, archComp->accessCmd, objPtr);
    Tcl_ListObjAppendElement((Tcl_Interp*)NULL, cmdlinePtr, objPtr);

    for (i=2; i < objc; i++) {
        Tcl_ListObjAppendElement((Tcl_Interp*)NULL, cmdlinePtr, objv[i]);
    }

    (void) Tcl_ListObjGetElements((Tcl_Interp*)NULL, cmdlinePtr,
        &cmdlinec, &cmdlinev);

//ItclShowArgs("COMPONENT", cmdlinec, cmdlinev);
    result = Itcl_EvalArgs(interp, cmdlinec, cmdlinev);

    Tcl_DecrRefCount(cmdlinePtr);

    return result;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchConfigureCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::configure method.
 *  Mimics the usual Tk "configure" method for Archetype mega-widgets.
 *
 *      configure
 *      configure -name
 *      configure -name value ?-name value ...?
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchConfigureCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int i;
    CONST char *val;
    char *token;
    ItclClass *contextClass;
    ItclObject *contextObj;
    ArchInfo *info;
    Tcl_HashEntry *entry;
    ArchOption *archOpt;
    Tcl_DString buffer;

    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        token = Tcl_GetString(objv[0]);
        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "improper usage: should be \"object ",
            token, " ?-option? ?value -option value...?\"",
            (char*)NULL);
        return TCL_ERROR;
    }

//fprintf(stderr, "Itk_GetArchInfo 7 %s\n", Tcl_GetCurrentNamespace(interp)->fullName);
    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     *  If there are no extra arguments, then return a list of all
     *  known configuration options.  Each option has the form:
     *    {name resName resClass init value}
     */

//fprintf(stderr, "GO!%d!%s!%s!\n", objc, Tcl_GetCurrentNamespace(interp)->fullName, contextClass->namesp->fullName);
    if (objc == 2) {
        /* skip an empty option */
	if (strlen(Tcl_GetString(objv[1])) == 0) {
	    objc--;
	}
    }
//ItclShowArgs("Itk_ArchConfigureCmd", objc, objv);
    if (objc == 1) {
        Tcl_DStringInit(&buffer);

        for (i=0; i < info->order.len; i++) {
            archOpt = (ArchOption*)Tcl_GetHashValue(info->order.list[i]);
            val = Tcl_GetVar2(interp, "itk_option", archOpt->switchName, 0);
//fprintf(stderr, "GO3!%s!%s!\n", archOpt->switchName, val == NULL ? "(nil)" : val);
            if (!val) {
//fprintf(stderr, "Itk_ArchOptAccessError 2\n");
                Itk_ArchOptAccessError(interp, info, archOpt);
                Tcl_DStringFree(&buffer);
                return TCL_ERROR;
            }

            Tcl_DStringStartSublist(&buffer);
            Tcl_DStringAppendElement(&buffer, archOpt->switchName);
            Tcl_DStringAppendElement(&buffer,
                (archOpt->resName) ? archOpt->resName : "");
            Tcl_DStringAppendElement(&buffer,
                (archOpt->resClass) ? archOpt->resClass : "");
            Tcl_DStringAppendElement(&buffer,
                (archOpt->init) ? archOpt->init : "");
            Tcl_DStringAppendElement(&buffer, val);
            Tcl_DStringEndSublist(&buffer);
        }
        Tcl_DStringResult(interp, &buffer);
        Tcl_DStringFree(&buffer);
        return TCL_OK;
    } else {

        /*
         *  If there is just one argument, then query the information
         *  for that one argument and return:
         *    {name resName resClass init value}
         */
        if (objc == 2) {
            token = Tcl_GetString(objv[1]);
            entry = Tcl_FindHashEntry(&info->options, token);
//fprintf(stderr, "GO 2!%s!%p!\n", token, entry);
            if (!entry) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "unknown option \"", token, "\"",
                    (char*)NULL);
                return TCL_ERROR;
            }

            archOpt = (ArchOption*)Tcl_GetHashValue(entry);
            val = Tcl_GetVar2(interp, "itk_option", archOpt->switchName, 0);
            if (!val) {
//fprintf(stderr, "Itk_ArchOptAccessError 3\n");
                Itk_ArchOptAccessError(interp, info, archOpt);
                return TCL_ERROR;
            }

            Tcl_AppendElement(interp, archOpt->switchName);
            Tcl_AppendElement(interp,
                (archOpt->resName) ? archOpt->resName : "");
            Tcl_AppendElement(interp,
                (archOpt->resClass) ? archOpt->resClass : "");
            Tcl_AppendElement(interp,
                (archOpt->init) ? archOpt->init : "");
            Tcl_AppendElement(interp, (CONST84 char *)val);
            return TCL_OK;
        } 
    }

    /*
     *  Otherwise, it must be a series of "-option value" assignments.
     *  Look up each option and assign the new value.
     */
    for (objc--,objv++; objc > 0; objc-=2, objv+=2) {
	char *value;
        token = Tcl_GetString(objv[0]);
//fprintf(stderr, "TOK!%s!%d!\n", token, objc);
        if (objc < 2) {
            Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                "value for \"", token, "\" missing",
                (char*)NULL);
            return TCL_ERROR;
        }
        value = Tcl_GetString(objv[1]);

//fprintf(stderr, "CONFIG 3!%s!%s!\n", token, value);
        if (Itk_ArchConfigOption(interp, info, token, value) != TCL_OK) {
            return TCL_ERROR;
        }
    }

    Tcl_ResetResult(interp);
//fprintf(stderr, "ArchConfigureCmd END\n");
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_ArchCgetCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::cget method.
 *  Mimics the usual Tk "cget" method for Archetype mega-widgets.
 *
 *      cget -name
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchCgetCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    CONST char *token;
    CONST char *val;
    ItclClass *contextClass;
    ItclObject *contextObj;
    ArchInfo *info;
    Tcl_HashEntry *entry;
    ArchOption *archOpt;

//ItclShowArgs("Itk_ArchCgetCmd", objc, objv);
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        token = Tcl_GetString(objv[0]);
        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "improper usage: should be \"object ", token, " -option\"",
            (char*)NULL);
        return TCL_ERROR;
    }

//fprintf(stderr, "Itk_GetArchInfo 8\n");
    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    if (objc != 2) {
        Tcl_WrongNumArgs(interp, 1, objv, "option");
        return TCL_ERROR;
    }

    /*
     *  Look up the specified option and get its current value.
     */
    token = Tcl_GetString(objv[1]);
    entry = Tcl_FindHashEntry(&info->options, token);
    if (!entry) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "unknown option \"", token, "\"",
            (char*)NULL);
        return TCL_ERROR;
    }

    archOpt = (ArchOption*)Tcl_GetHashValue(entry);
    val = Tcl_GetVar2(interp, "itk_option", archOpt->switchName, 0);
    if (!val) {
//fprintf(stderr, "Itk_ArchOptAccessError 4\n");
        Itk_ArchOptAccessError(interp, info, archOpt);
        return TCL_ERROR;
    }

    /*
     * Casting away CONST is safe because TCL_VOLATILE guarantees
     * CONST treatment.
     */
    Tcl_SetResult(interp, (char *) val, TCL_VOLATILE);
    return TCL_OK;
}