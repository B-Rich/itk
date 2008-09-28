#---------------------------------------------------------------------------
# ntkWidget defaultFocusringElement.tcl --
#
# This file contains a ntkWidget defaultFocusringElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultFocusringElement.tcl,v 1.1.2.2 2007/12/30 22:58:19 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::defaultFocusringElement {
    inherit ::ntk::classes::baseElement

    protected option -focuscolor -default [list 0 0 0 0] \
            -configurecommand focusringElementConfigure
    protected option -focusthickness -default 1 \
            -configurecommand focusringElementConfigure

    public method focusringElementConfigure {option value} {
    }

    public method InitializeOptionValues {styleName widget state} {
	InitializeOptionValuesBase $styleName $widget $state
puts stderr "FOCUSRING!$this!focusthickness!$itcl_options(-focusthickness)!"
	return
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        upvar $paddingVar padding

        set borderWidth $itcl_options(-focusthickness)
	set padding [list $borderWidth $borderWidth $borderWidth $borderWidth]
puts stderr "FOCUSRING SIZE!$this!$paddingVar!$itcl_options(-focusthickness)!"
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}
