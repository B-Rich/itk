#---------------------------------------------------------------------------
# ntkWidget ntk.tcl --
#
# This file contains a namespace ensemble for the subcommands of ntkWidget
# ntkWidget is derived from the NexTk implementation written by
# George Peter Staplin
#
# ntkWidget is a reimplementation of Tk based on megapkg, ntk and freetypeext
# written by George Peter Staplin
#
# Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntk.tcl,v 1.1.2.7 2007/10/13 21:38:36 wiede Exp $
#--------------------------------------------------------------------------

namespace eval ::ntk {
    namespace ensemble create -map [list \
        button ::ntk::button \
        clock ::ntk::clock \
        entry ::ntk::entry \
        focus ::ntk::focus \
        frame ::ntk::frame \
        grid ::ntk::grid \
        input ::ntk::input \
        label ::ntk::label \
        listbox ::ntk::listbox \
        render ::ntk::render \
        scrollbar ::ntk::scrollbar \
        text ::ntk::text \
        theme ::ntk::theme \
        toplevel ::ntk::toplevel \
        window ::ntk::window \
        keyPress ::ntk::inputKeyPress \
        keyRelease ::ntk::inputKeyRelease \
        mousePress ::ntk::inputMousePress \
        mouseRelease ::ntk::inputMouseRelease \
        motion ::ntk::inputMotion \
    ]
}

set myDir [file dirname [::info script]]
source [file join $myDir ntkHelpers.tcl]
source [file join $myDir ntkRender.tcl]
source [file join $myDir ntkInput.tcl]
source [file join $myDir ntkGridBase.tcl]
source [file join $myDir ntkWindow.tcl]
source [file join $myDir ntkTheme.tcl]
source [file join $myDir ntkScrollbar.tcl]
source [file join $myDir ntkButton.tcl]
source [file join $myDir ntkEntry.tcl]
source [file join $myDir ntkFrame.tcl]
source [file join $myDir ntkLabel.tcl]
source [file join $myDir ntkListbox.tcl]
source [file join $myDir ntkToplevel.tcl]
#source [file join $myDir ntkGrid.tcl]
#source [file join $myDir ntkClock.tcl]
#source [file join $myDir ntkText.tcl]

proc ::ntk::button {args} {
    puts stderr "::ntk::button called !$args!"
    return [uplevel 1 ::ntk::classes::button {*}$args]
}
    
proc ::ntk::clock {args} {
    puts stderr "::ntk::clock called !$args!"
}
    
proc ::ntk::entry {args} {
    puts stderr "::ntk::entry called !$args!"
    return [uplevel 1 ::ntk::classes::entry {*}$args]
}
    
proc ::ntk::focus {args} {
    puts stderr "::ntk::focus called !$args!"
    return [uplevel 1 ::ntk::classes::focus {*}$args]
}
    
proc ::ntk::frame {args} {
    return [uplevel 1 ::ntk::classes::frame {*}$args]
}
    
proc ::ntk::grid {args} {
    return [uplevel 1 ::ntk::classes::grid {*}$args]
}
    
proc ::ntk::input {args} {
    puts stderr "::ntk::input called !$args!"
}
    
proc ::ntk::label {args} {
    puts stderr "::ntk::label called !$args!"
    return [uplevel 1 ::ntk::classes::label {*}$args]
}
    
proc ::ntk::listbox {args} {
    puts stderr "::ntk::listbox called !$args!"
}
    
proc ::ntk::render {args} {
    puts stderr "::ntk::render called !$args!"
}
    
proc ::ntk::scrollbar {args} {
    puts stderr "::ntk::scrollbar called !$args!"
}
    
proc ::ntk::text {args} {
    puts stderr "::ntk::text called !$args!"
}
    
proc ::ntk::theme {args} {
    puts stderr "::ntk::theme called !$args!"
}
    
proc ::ntk::toplevel {args} {
    return [uplevel 1 ::ntk::classes::toplevel {*}$args]
}
    
proc ::ntk::window {args} {
    return [uplevel 1 ::ntk::classes::window {*}$args]
}

proc ::ntk::inputKeyPress {args} {
    ::ntk::classes::input::inputKeyPress {*}$args
}

proc ::ntk::inputKeyRelease {args} {
    ::ntk::classes::input::inputKeyRelease {*}$args
}

proc ::ntk::inputMousePress {args} {
    ::ntk::classes::input::inputMousePress {*}$args
}

proc ::ntk::inputMouseRelease {args} {
    ::ntk::classes::input::inputMouseRelease {*}$args
}

proc ::ntk::inputMotion {args} {
    ::ntk::classes::input::inputMotion {*}$args
}

    
package provide ntkWidget 0.1

