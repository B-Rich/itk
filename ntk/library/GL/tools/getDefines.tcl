#!/usr/bin/env tclsh

set map_names [list \
    [ list Boolean_values [list]] \
    [ list Data_types [list]] \
    [ list Primitives Primitives] \
    [ list Vertex_Arrays Vertex_Arrays] \
    [ list Matrix_Mode Matrix_Mode] \
    [ list Points Points] \
    [ list Lines Lines] \
    [ list Polygons Polygons] \
    [ list Display_Lists Display_Lists] \
    [ list Depth_buffer Depth_buffer] \
    [ list Lighting Lighting] \
    [ list User_clipping_planes User_clipping_planes] \
    [ list Accumulation_buffer Accumulation_buffer] \
    [ list Alpha_testing Alpha_testing] \
    [ list Blending Blending] \
    [ list Render_Mode Render_Mode] \
    [ list Feedback Feedback] \
    [ list Selection Selection] \
    [ list Fog Fog] \
    [ list Logic_Ops Logic_Ops] \
    [ list Stencil Stencil] \
    [ list Buffers__Pixel_Drawing_Reading Buffers__Pixel_Drawing_Reading] \
    [ list Implementation_limits Implementation_limits] \
    [ list Gets Gets] \
    [ list Evaluators Evaluators] \
    [ list Hints Hints] \
    [ list Scissor_box Scissor_box] \
    [ list Pixel_Mode___Transfer Pixel_Mode___Transfer] \
    [ list Texture_mapping Texture_mapping] \
    [ list Utility Utility] \
    [ list Errors Errors] \
    [ list glPush_PopAttrib_bits glPush_PopAttrib_bits] \
    [ list OpenGL_1_1 OpenGL_1_1] \
    [ list multitexture multitexture] \
    [ list texture_cube_map texture_cube_map] \
    [ list texture_compression texture_compression] \
    [ list multisample multisample] \
    [ list transpose_matrix transpose_matrix] \
    [ list texture_env_combine texture_env_combine] \
    [ list texture_env_dot3 texture_env_dot3] \
    [ list texture_border_clamp texture_border_clamp] \
]

set glTypes [list \
    GLenum \
    GLboolean \
    GLbitfield \
    GLvoid \
    GLbyte \
    GLshort \
    GLint \
    GLubyte \
    GLushort \
    GLuint \
    GLsizei \
    GLfloat \
    GLclampf \
    GLdouble \
    GLclampd \
]

set funcHeader {

/*
 * ------------------------------------------------------------------------
 *  TclGL_%sCmd()
 *
 *  Handles the OpenGL %s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
}

set paramHeader {
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
}

set argsCheck {
    if (objc != %d) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk %s %s\"",
                NULL);
        return TCL_ERROR;
    }
}

set varDecls {
{    Tcl_HashEntry *hPtr;}
{    TclGLInfo *infoPtr;}
{    int result;}
{    int glResult;}
}

set enumPart {    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[%s]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"", \
	        Tcl_GetString(objv[%s]),"\"", NULL);
	return TCL_ERROR;
    }
    %s = (int)Tcl_GetHashValue(hPtr); }

set openCurly "{"
set closeCurly "}"

set lineNo 0
set comments [list]
set lastDefineLineNo -1
set procNameLst [list]
set methodNameLst [list]
set cmdNameLst [list]
set funcLst [list]
while {[gets stdin line] >= 0} {
    incr lineNo
#puts stderr "LINE!$line![regexp {^/[*] } $line]!"
    if {[regexp {^/[*] } $line]} {
        # comment save for later use as hash table */
	regexp {^/[*] (.*) [*]/$} $line -> comment
	set comment [string trim $comment]
	regsub -all { } $comment {_} comment
	regsub -all {/} $comment {_} comment
	regsub -all {[.]} $comment {_} comment
	regsub -all {[-]} $comment {_} comment
	regsub -all {,} $comment {_} comment
        set commentLineNo $lineNo
#puts stderr "comment!$commentLineNo!$comment!"
    } else {
        if {[regexp {^#define GL_(.*)$} $line -> defineStr]} {
	    if {$commentLineNo == [expr {$lineNo - 1}]} {
                lappend comments $comment
	        set lastDefineLineNo $commentLineNo
	        set defines($comment) [list]
	    }
	    regsub -all "\t" $defineStr { } defineStr
	    while {[regsub {  } $defineStr { } defineStr]} {
	    }
	    set defineStr GL_$defineStr
	    set defineStrLst [split $defineStr]
            set defineStrLineNo $lineNo
#puts stderr "defineStr!$defineStrLineNo!$defineStr!"
	    if {$lastDefineLineNo == [expr {$lineNo - 1}]} {
	        lappend defines($comment) $defineStrLst
	    }
	    set lastDefineLineNo $lineNo
	} else {
            if {[regexp {^GLAPI ([^ ]*) GLAPIENTRY ([^ ]*)[(]([^)]*)[)]} $line -> type name params]} {
#puts stderr "FUNC!$type!$name!$params!"
                if {($type ne "void") && ([lsearch $glTypes $type] < 0)} {
                    puts stderr "unknown return type: $type inf function $name"
		}
		switch -glob -- $name {
		*MESA {
		    continue
		  }
		}
	        set params [string trim $params]
		set paramLst [split $params ","]
#puts stderr "PARAMS![join $paramLst !]!"
		set param_info ""
                set funcVarDecls $varDecls
		set paramNum 0
		set getParamInfos [list]
		set paramCallInfos ""
		set callSep ""
		set notYet 0
                set varInits [list]
	        foreach entry $paramLst {
		    incr paramNum
		    set star ""
		    switch [llength $entry] {
		    1 {
		        set ptype1 ""
			foreach {ptype2} $entry break
			if {$ptype2 ne "void"} {
		            puts stderr "bad param part!$entry!"
			}
			set pname ""
		      }
		    2 {
			set ptype1 ""
		        foreach {ptype2 pname} $entry break
		        if {[regexp {^([*]*)(.*)} $pname -> star pname2]} {
			    set pname $pname2
			}
		        if {[regexp {[\[]} $pname]} {
		            set notYet 1
			}
		      }
		    3 {
		        foreach {ptype1 ptype2 pname} $entry break
		        if {[regexp {^([*]*)(.*)} $pname -> star pname2]} {
			    set pname $pname2
			}
		        if {[regexp {[\[]} $pname]} {
		            set notYet 1
			}
		      }
		    4 {
		        foreach {ptype1 ptype2 star pname} $entry break
		        if {$star ne "*"} {
		            puts stderr "bad param part!$entry!"
			}
puts stderr "444!$entry!"
		        set notYet 1
			continue
		      }
		    default {
		        puts stderr "bad param part!$entry!"
			set notYet 1
		        continue
		      }
		    }
		    set ptype1 [string trim $ptype1]
		    set ptype2 [string trim $ptype2]
		    set pname [string trim $pname]
		    if {($ptype1 != "") && ($ptype1 != "const")} {
			puts stderr "FUNNY ptype1!$ptype1!"
			set notYet 1
		        continue
		    }
		    if {($ptype2 != "void") && ([lsearch $glTypes $ptype2] < 0)} {
		        puts stderr "NO SUCH TYPE!$ptype2!"
			set notYet 1
		        continue
		    }
		    if {$ptype2 ne "void"} {
			set startStr ""
                        if {$ptype1 != ""} {
			    set startStr "$ptype1 "
                        }
		        append param_info "<($ptype2) $pname> "
			switch $ptype2 {
			GLenum {
                            set myType "int"
puts stderr "NOYenum!$name!$entry!"
                            set getParam [format $enumPart $paramNum \
			            $paramNum $pname]
			    append paramCallInfos "${callSep}(GLenum)$pname"
			    set callSep ", "
			  }
                        GLboolean {
                            set myType "int"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetBooleanFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
			        set getParam "    $pname = (${startStr}int*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(unsigned char $star)$pname"
			    set callSep ", "
                          }
                        GLbitfield {
                            set myType ""
			    set notYet 1
#puts stderr "NOYbitfield!$name!$entry!"
                          }
                        GLvoid {
                            set myType "void"
			    if {$star eq ""} {
			        set notYet 1
puts stderr "NOYvoid!$name!$entry!"
			    } else {
			        set getParam "    $pname = (${startStr}void$star)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    append paramCallInfos "${callSep}(void $star)$pname"
			    set callSep ", "
			    }
                          }
                        GLbyte {
                            set myType "int"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetIntFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
			        set getParam "    $pname = (${startStr}int*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(signed char $star)$pname"
			    set callSep ", "
                          }
                        GLshort {
                            set myType "int"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetIntFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
			        set getParam "    $pname = (${startStr}int*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(short $star)$pname"
			    set callSep ", "
                          }
                        GLint {
                            set myType "int"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetIntFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
			        set getParam "    $pname = (${startStr}int*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(int $star)$pname"
			    set callSep ", "
                          }
                        GLubyte {
                            set myType "int"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetIntFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
			        set getParam "    $pname = (${startStr}int*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(unsigned char $star)$pname"
			    set callSep ", "
                          }
                        GLushort {
                            set myType "int"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetIntFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
			        set getParam "    $pname = (${startStr}int*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(unsigned short $star)$pname"
			    set callSep ", "
                          }
                        GLuint {
                            set myType "int"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetIntFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
			        set getParam "    $pname = (${startStr}int*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(unsigned int $star)$pname"
			    set callSep ", "
                          }
                        GLsizei {
                            set myType "int"
			    set getParam "    Tcl_GetIntFromObj(interp, objv\[$paramNum\], &$pname);"
			    append paramCallInfos "${callSep}(int $star)$pname"
			    set callSep ", "
                          }
                        GLfloat {
                            set myType "double"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetDoubleFromObj(interp, objv\[$paramNum], &$pname);"
			    } else {
				set myType "void"
			        set getParam "    $pname = (${startStr}float*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(float $star)$pname"
			    set callSep ", "
                          }
                        GLclampf {
                            set myType "double"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetDoubleFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
				set myType "void"
			        set getParam "    $pname = (${startStr}float*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(float $star)$pname"
			    set callSep ", "
                          }
                        GLdouble {
                            set myType "double"
			    if {$star eq ""} {
			        set getParam "    Tcl_GetDoubleFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
				set myType "void"
			        set getParam "    $pname = (${startStr}double*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(GLdouble $star)$pname"
			    set callSep ", "
                          }
                        GLclampd {
                            set myType "double"
			    if {$star eq ""} {
			         set getParam "    Tcl_GetDoubleFromObj(interp, objv\[$paramNum\], &$pname);"
			    } else {
				set myType "void"
			        set getParam "    $pname = (${startStr}double*)Tcl_GetByteArrayFromObj(objv\[$paramNum\], NULL);"
			    }
			    append paramCallInfos "${callSep}(GLclampd $star)$pname"
			    set callSep ", "
                          }
                        default {
                            puts stderr "FUNNY GL type!$ptype2"
			    set notYet 1
                            continue
                           }
                        }
                        if {$myType != ""} {
			    set init " = 0"
			    switch $myType {
			    double {
			        set init " = 0.0"
			      }
			    }
		            lappend funcVarDecls "    $startStr$myType ${star}$pname;"
			    if {$ptype1 eq ""} {
#			        lappend varInits "    $pname $init;"
			    }
		            lappend getParamInfos $getParam
		        }
		    }
	        }
                set param_info [string trimright $param_info]
#puts stderr "param_info!$param_info!"
                
		set notYetStr ""
		if {$notYet} {
		    set funcVarDecls $varDecls
		    set varInits ""
		    set notYetStr " !not yet!"
		}
		lappend procNameLst "Tcl_ObjCmdProc TclGL_${name}Cmd;"

		lappend methodNameLst "    { \"$name\", \"$param_info$notYetStr\", TclGL_${name}Cmd } ,"
	        lappend cmdNameLst "    { \"::ntk::gl::GL::$name\", TclGL_${name}Cmd },"
	        lappend funcLst [format $funcHeader $name $name]
	        lappend funcLst "int\nTclGL_${name}Cmd("
                lappend funcLst $paramHeader
                lappend funcLst $openCurly
                lappend funcLst [join $funcVarDecls \n]
		lappend funcLst "\n    glResult = 0;"
		lappend funcLst "    hPtr = NULL;"
		lappend funcLst [join $varInits \n]
		lappend funcLst "    infoPtr = (TclGLInfo *)clientData;"
                lappend funcLst "    TclGLShowArgs(0, \"TclGL_${name}Cmd\", objc, objv);"
                lappend funcLst [format $argsCheck [expr {$paramNum + 1}] $name $param_info]
		if {$notYet} {
#puts stderr "NOT YET !$name!"
		    lappend funcLst "fprintf(stderr, \"$name not yet implemented\");"
		    lappend funcLst "    result = TCL_OK;"
		} else {
		    lappend funcLst [join $getParamInfos \n]
		    lappend funcLst "    ${name}(${paramCallInfos});"
		    lappend funcLst "    result = GetGLError(interp);"
		}
                lappend funcLst "    return result;"
                lappend funcLst $closeCurly
	    }
        }
    }
}
set hashTables [list]
set initLst [list]
set hashName glDefines
lappend hashTables "    Tcl_HashTable $hashName;"
lappend initLst "    Tcl_InitObjHashTable(&infoPtr->$hashName);"
set hashDefineNames glDefineStrings
lappend hashTables "    Tcl_HashTable $hashDefineNames;"
lappend initLst "    Tcl_InitHashTable(&infoPtr->$hashDefineNames, TCL_ONE_WORD_KEYS);"
foreach name [array names defines] {
    set map_name_idx [lsearch -glob $map_names ${name}*]
    set map_name [lindex [lindex $map_names $map_name_idx] 1]
    if {[llength $map_name] == 0} {
puts "NO MAP!$name!"
        continue
    }
#puts stderr "MAP!$name!$map_name_idx!$map_name!"
    foreach entry $defines($name) {
	foreach {entryName entryValue} $entry break
        lappend initLst "    objPtr = Tcl_NewStringObj(\"$entryName\", -1);"
        lappend initLst "    Tcl_IncrRefCount(objPtr);"
        lappend initLst "    hPtr = Tcl_CreateHashEntry(&infoPtr->$hashName, (char *)objPtr, &isNew);"
        lappend initLst "    Tcl_SetHashValue(hPtr, $entryValue);"
        lappend initLst "    hPtr = Tcl_CreateHashEntry(&infoPtr->$hashDefineNames, (char *)$entryValue, &isNew);"
        lappend initLst "    Tcl_SetHashValue(hPtr, objPtr);"
        lappend initLst "    Tcl_IncrRefCount(objPtr);"
    }
    lappend initLst ""
}
set fd [open ../generic/tclGLHashTables.h w]
puts $fd [join $hashTables \n]
close $fd
set fd [open ../generic/tclGLInitHashTables.c w]
puts $fd [join $initLst \n]
close $fd
set fd [open ../generic/tclGLProcNames.c w]
puts $fd [join $procNameLst \n]
close $fd
set fd [open ../generic/tclGLMethodNames.c w]
puts $fd [join $methodNameLst \n]
close $fd
set fd [open ../generic/tclGLCmdNames.c w]
puts $fd [join $cmdNameLst \n]
close $fd
set fd [open ../generic/tclGLFuncs.c w]
puts $fd [join $funcLst \n]
close $fd
