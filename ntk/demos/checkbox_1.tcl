#---------------------------------------------------------------------------
# ntkWidget checkbox_1.tcl demo --
#
# This file contains a small demo for a button using the ntkWidget package
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: checkbox_1.tcl,v 1.1.2.1 2007/11/29 18:16:13 wiede Exp $
#--------------------------------------------------------------------------

# optional command line parameter: rotate 
# the value determines how much the label is rotated counter clock wise
# negative values rotate clockwise
# the value is in the range of 0 .. 360 (degrees)

package require ntkWidget

# the next proc is mostly for debugging a simulated command line interface

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

::ntk::glmwfw::Glmwfw setWindowTitle $::ntk::_win "NtkWidget Checkbox Demo 1"

proc flipName {win} {
    set name [$win cget -text]
    switch $name {
    Arnulf {
        $win configure -text Wiedemann
      }
    Wiedemann {
        $win configure -text Arnulf
      }
   }
}

set rotate 0
if {[llength $argv] > 0} {
    set rotate [lindex $argv 0]
}
set wPath [ntk checkbox .w -width 50 -height 20 -xoffset 50 -yoffset 50 \
-bd 2 -bg [list 255 255 255 255] -check 1]
$wPath configure -rotate $rotate

# pack the widget using ntkWidget grid manager
ntk grid $wPath

fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
