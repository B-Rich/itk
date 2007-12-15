#---------------------------------------------------------------------------
# ntkWidget ntkGrid.tcl --
#
# This file contains a ntkWidget grid command implementation
#
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
# RCS: @(#) $Id: ntkGrid.tcl,v 1.1.2.13 2007/12/15 21:55:16 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::grid {
    private common gridLock
    private common slotInfos
    private common numCalls 0
    private common layoutId 0
    private common currentLayout
    set currentLayout(.) 0
#    private common xsizes
#    private common ysizes
#    private common ratios
#    private common sticky

    public proc dump {grid} {
        puts stderr "BEGIN DUMP"
	set i 0
	foreach row $grid {
	    puts stderr "  row: $i -> $row"
	    incr i
	}
	puts stderr "END DUMP"
    }

    public proc dumpSizes {grid} {
        foreach row $grid {
	    foreach cells $row {
	        foreach w $cells {
		    puts -nonewline stderr "$w is +[$w cget -xoffset]+[$w cget -yoffset] [$w cget -width]x[$w cget -height] \[[$w cget -slot]\]\t"
		}
	    }
	    puts stderr ""
	}
    }

    protected proc free {managerobj} {
        uplevel 0 [free] $managerobj
    }

    protected proc getVisible {columnsVar rowsVar} {
        # 
	# find the number of visible columns
	#
	set r 0
	foreach row [grid] {
	    set c 0
	    foreach path $row {
	        if {$path eq ""} {
		    incr c
		    continue
		}
		for {set i 0} {$i < [$path cget -columnspan]} {incr i} {
		    lappend columns [expr {$c + $i}]
		}
		for {set i 0} {$i < [$path cget -rowspan]} {incr i} {
		    lappend rows [expr {$r + $i}]
		}
                incr c
	    }
	    incr r
	}
    }

    protected proc insertWidget {gridVar path column row} {
	upvar $gridVar grid

	set numRows [llength $grid]
#puts stderr "INS!$column!$row!$numRows!"
        if {$numRows <= ($row + 1)} {
            #
            # The grid row doesn't exist, so insert it.
            #
            for {set i [expr {$numRows - 1}]} {$i < $row} {incr i} {
                lappend grid [list]
            }
       } 
#puts stderr "INS2!$grid!$row!"
       set myRow [lindex $grid $row]
#puts stderr "INS2a!$myRow!$grid!$row!"
       set numColumns [llength $myRow]
       if {$numColumns <= ($column + 1)} {
           #
           # The grid column doesn't exist in the row, so insert it.
           #
           for {set i [expr {$numColumns - 1}]} {$i < $column} {incr i} {
               lappend myRow [list]
           }
       }
#puts stderr "INS3!$myRow!"
       set cells [lindex $myRow $column]
       if {[llength $cells] == 0} {
           set cells [list $path]
       } else {
           lappend cells $path
       }
       lset myRow $column $cells
       lset grid $row $myRow
    }

    protected proc integerCallback {w arg} {
        if {![string is integer -strict $arg]} {
            return -code error "invalid argument (not an integer): $arg"
        }
        return 1
    }

    public proc layout {parent} {
#puts stderr "LAYOUT!$parent!"
	incr layoutId
        set currentLayout($parent) $layoutId
	after idle [list ::ntk::classes::grid::layoutNow $parent $layoutId]
    }

    public proc layoutNow {parent id} {
#puts stderr "LAYOUT!$parent!$id![info exists currentLayout($parent)]!"
        if {[info exists currentLayout($parent)]} {
	    if {$currentLayout($parent) > $id} {
                return
	    }
	}
	if {[info exists gridLock($parent)]} {
#puts stderr "gridLock $parent exists"
	    return
	}
#puts stderr "layout2!$parent!"
	set gridLock($parent) $parent
        set m [$parent manager]
        set myGrid [$m grid]
        set pwidth [$parent cget -width]
        set pheight [$parent cget -height]
# puts stderr "  LAYOUT!P!$parent!$pwidth!$pheight!$myGrid!"
        if {$pwidth <= 0 || $pheight <= 0} {
	    unset gridLock($parent)
	    return
        }
        set cwork [list]
	set myPeakcolumn [$m peakcolumn]
	set myPeakrow [$m peakrow]
        for {set c 0} {$c < $myPeakcolumn} {incr c} {
            set col [list]
            for {set r 0} {$r < $myPeakrow} {incr r} {
                set cells [lindex $myGrid $r $c]
                if {[llength $cells] == 0} {
	            continue
	        }
                lappend col {*}$cells
            }
            if {[llength $col]} {
                lappend cwork $col
            }
        }

#puts stderr "    CWORK!$cwork!"
        set tim1 [time {
	if {![layoutDirection $cwork columnspan reqwidth width $pwidth 0 xsizes]} {
	    return
	}
	}]
#puts stderr "tim1!$tim1!$currentLayout($parent)!$id!"
        if {$currentLayout($parent) > $id} {
            return
        }
#puts stderr "    xsizes!"
#parray xsizes
        set rwork [list]
        foreach row $myGrid {
             set rbuf [list]
             foreach cells $row {
                 if {[llength $cells] == 0} {
	             continue
	         }
                 lappend rbuf {*}$cells
             }
             if {[llength $rbuf]} {
                 lappend rwork $rbuf
             }
        }
#puts stderr "    RWORK!$rwork!"
        set tim2 [time {
        if {![layoutDirection $rwork rowspan reqheight height $pheight 1 ysizes]} {
	    return
	}
	}]
#puts stderr "tim2!$tim2!"
#puts stderr "    ysizes!"
#parray ysizes
        set tim3 [time {
        layoutXy $myGrid xsizes ysizes
	}]
#puts stderr "tim3!$tim3!"
	unset gridLock($parent)
        gridRedraw $myGrid
    }

    protected proc layoutDirection {worklist spankey reqdim wdir psize slotoffset sizesvar} {
        upvar $sizesvar sizes
	upvar parent parent
	upvar id id
        array set ratios {}
        array set sticky {}
        set units 5000

set tim11 [time {
        # Set ratios for the windows that span 1 column/row.
        foreach dim $worklist {
            foreach path $dim {
		if {$currentLayout($parent) != $id} {
		    return 0
		}
		if {![info exists winRatio($path)]} {
                    if {[$path cget -$spankey] > 1} {
	                continue
                    }
                    set s [lindex [$path cget -slot] $slotoffset]
		    set myReqDim [$path cget -$reqdim]
#puts stderr "      set set myReqDim [$path cget -$reqdim]!$reqdim!$psize!$s!"
                    set winRatio($path) [expr {$myReqDim * $units / $psize}]
		}
		set ratio $winRatio($path)
                if {[lsearch -exact [$path cget -sticky] $wdir] >= 0} {
                    set sticky($s) 1
#puts stderr "      set sticky($s) 1"
                }
                if {![::info exists ratios($s)] || $ratio > $ratios($s)} {
                    set ratios($s) $ratio 
#puts stderr "      set ratios($s) $ratio"
                }
            }
        }
}]
#puts stderr "tim11!$tim11"

        # Now handle the multiple span windows.
set tim12 [time {
        foreach dim $worklist {
            foreach path $dim {
		if {$currentLayout($parent) != $id} {
		    return 0
		}
		if {![info exists winRatio($path)]} {
                    if {[$path cget -$spankey] == 1} {
		        continue
	            }
                    set s [lindex [set [set slots($path)]] $slotoffset]
                    set es [expr {$s + [set _${spankey}($path)]}]
                    set st [expr {[lsearch -exact [set stickys($path)] $wdir] >= 0}]
                    for {set i $s} {$i < $es} {incr i} {
                        if {![info exists ratios($i)]} {
                            set wratio [expr {[set [set _${reqdim}($path)]] * $units / $psize}]
                            for {set subi $s} {$subi < $es} {incr subi} {
                                if {[info exists ratios($subi)]} {
                                    set wratio [expr {$wratio - $ratios($subi)}]
                                }
                            }
                            set wratio [expr {($wratio > 0) ? $wratio : 0}]
                            set ratios($i) $wratio
                        } 
                        if {$st} {
                            set sticky($i) 1
                        }
                    }
	        }
            }
        }
}]
#puts stderr "tim12!$tim12"
        set totalcells [llength [array names ratios]]
        if {$totalcells <= 0} {
	    return 1
        }
	if {$currentLayout($parent) != $id} {
	    return 0
	}
set tim121 [time {
        set totalratio [sumRatios ratios]

#puts stderr "      totalratio!$totalratio!"
        if {$totalratio > $units} {
            # The widgets will all have to be bumped down in ratio.
            # Try to shrink sticky widgets more than others.
	    set stickyratio 0
	    set totalstickycells [llength [array names sticky]]
            foreach key [array names sticky] {
	        incr stickyratio $ratios($key)
	    }
	    if {$stickyratio > 0} {
	        #Shrink the sticky cells.
                set bump [expr {($totalratio - $units) / $totalstickycells}]
                foreach key [array names sticky] {
                    set ratios($key) [expr {$ratios($key) - $bump}]
#puts stderr "      2 set ratios($key) [expr {$ratios($key) - $bump}]"
                }
	    } else {
	        set bump [expr {($totalratio - $units) / $totalcells}]
		foreach key [array names ratios] {
		    set ratios($key) [expr {$ratios($key) - $bump}]
#puts stderr "      3 set ratios($key) [expr {$ratios($key) - $bump}]"
		}
	    }
        } else {
	    # We can expand some of the widgets.
	    set nonstickyratio 0
	    set stickyratio 0
	    foreach {i value} [array get ratios] {
	        if {![info exists sticky($i)]} {
	            incr nonstickyratio $value
	        } else {
		    incr stickyratio $value
	        }
	    }
            set fillcells [llength [array names sticky]]
            if {$fillcells > 0} {
                set ratiodelta [expr {$units - $nonstickyratio - $stickyratio}]
                set bump [expr {$ratiodelta / $fillcells}]
                foreach i [array names sticky] {
                    set ratios($i) [expr {$ratios($i) + $bump}]
#puts stderr "      4 set ratios($i) [expr {$ratios($i) + $bump}]"
                }
            }  
        }
}]
#puts stderr "tim121!$tim121!"
	if {$currentLayout($parent) != $id} {
	    return 0
	}
        # Now calculate the size for each cell.
        foreach i [array names ratios] {
             set sizes($i) [expr {$ratios($i) * $psize / $units}]
        }
        #Set the size for this dimension of the widget.
#puts stderr "SLOT!$spankey!$slotoffset!$worklist!"
set tim13 [time {
        foreach dim $worklist {
#puts stderr "dim![llength $dim]!"
            foreach path $dim {
	        if {$currentLayout($parent) != $id} {
	            return 0
	        }
                set s [lindex [$path cget -slot] $slotoffset]
                set es [expr {$s + [$path cget -$spankey]}]
                set totalsize 0
                for {set i $s} {$i < $es} {incr i} {
                    incr totalsize $sizes($i)
                }
                if {$totalsize <= 0} {
                    set totalsize 1
                }
                set gridLock($path) $path
                $path $wdir $totalsize
#                $path configure -$wdir $totalsize
#puts stderr "      $path configure -$wdir $totalsize"
                unset gridLock($path)
            }
        }
}]
#puts stderr "tim13!$tim13"
#puts stderr C
#parray sizes
#puts stderr D
        return 1
    }

    private proc layoutXy {grid xsizesvar ysizesvar} {
        upvar $xsizesvar xsizes
	upvar $ysizesvar ysizes

        foreach row $grid {
            foreach cells $row {
                foreach path $cells {
                    if {$path eq ""} {
		        continue
                    }
                    lassign [$path cget -slot] xslot yslot
                    set x 0
		    set y 0
                    for {set xi 0} {$xi < $xslot} {incr xi} {
                        if {[::info exists xsizes($xi)]} {
			    incr x $xsizes($xi)
			}
                    }
                    for {set yi 0} {$yi < $yslot} {incr yi} {
                        if {[::info exists ysizes($yi)]} {
			    incr y $ysizes($yi)
			}
                    }
                    set gridLock($path) $path
                    $path configure -xoffset $x -yoffset $y
                    unset gridLock($path)
                }
            }   
        }
    }

    protected proc listSet {list_var i value} {
        upvar $list_var list

        if {[llength $list] >= $i} {
            lappend list $value
        } else {
            lset list $i $value
        }
    }

    public proc gridRedraw {grid} {
        foreach row $grid {
            foreach cells $row {
                foreach path $cells {
                    #Resize the backing ntkWidget windowImage.
                    ::ntk::widgetImage::Image setsize [$path windowImage] [$path cget -width] [$path cget -height]
                    #Trigger a redraw of the widget.
                    $path dispatchRedraw
                }
            }
        }
    }

    public proc relayoutTrace {path} {
        layout [$path parent]
    }

    public method remanageChildren {path ignore depth} {
        #puts "$path $ignore $depth"
puts stderr "REMANAGE_CHILDREN!$path!"
        foreach c [$path children] {
            remanageChildren $c $ignore [expr {$depth + 1}]
	    if {$depth > $ignore} {
puts stderr REMANAGE:$c
	        remanageWindow $c
	    }
	}
    }
    protected proc remove {w} {
        set m [[$w parent] manager]
        set grid [$m grid]
        removeWidget grid $w
        layout [$w parent]
    }

    protected proc removeWidget {gridvar path} {
        upvar $gridvar grid

	if {[llength $grid] == 0} {
	    # grid call in progress
	    return
	}
        lassign [$path cget -slot] c r
#puts stderr "removeWidget!$grid!$path!$c!$r!"
        set row [lindex $grid $r]
        set cells [lindex $row $c]
#puts stderr "ROW!$row!$cells!"
	if {[llength $cells] == 0} {
	    # grid call in progress
	    return
	}
        set i [lsearch -exact $cells $path]
        if {$i >= 0} {
            set cells [lreplace $cells $i $i]
        }
        lset row $c $cells
        lset grid $r $row 
    }

    protected proc rmList {list slot span} {
        for {set i 0} {$i < $span} {incr i} {
            set e [lsearch -exact $list [expr {$slot + $i}]]
            if {$e < 0} {
                continue
            }
            set list [lreplace $list $e $e]
        }
        return $list
    }

    # peakrow and peakcolumn are the maximum row number/column number used

    protected proc setPeak {m peaktype peak} {
        if {$peak > [$m $peaktype]} {
            $m $peaktype $peak
        }
    }

    protected proc slotCallback {path arg} {
        if {[llength $arg] != 2} {
            return -code error "invalid list length (should be 2): $arg"
        }
        lassign $arg c r
        if {![string is integer -strict $c]} {
            return -code error "invalid column for slot (not an integer): $c"
        }
        if {![string is integer -strict $r]} {
            return -code error "invalid row for slot (not an integer): $r"
        }
        set p [$path parent]
        set grid [[$p manager] grid]

        removeWidget grid $path
        insertWidget grid $path $c $r
 
        [$p manager] grid $grid
 
        #
        # There is a -slot trace, so when this completes successfully,
        # relayoutTrace will be evaluated.
        #
        return 1
    }

    protected proc spanCallback {w arg} {
        if {![string is integer -strict $arg]} {
            return -code error "invalid argument (not an integer): $arg"
        }
        if {$arg <= 0} {
            return -code error "invalid span: $arg"
        }
        return 1
    }

    protected proc stickyCallback {w arg} {
        foreach i $arg {
            if {"width" ne $i && "height" ne $i} {
                return -code error \
		    "invalid -sticky list item (should be width or height): $i"
            }
        }
        return 1
    }

    protected proc isSticky {w arg} {
        return [expr {[lsearch -exact [$w cget -sticky] $arg] >= 0}]
    }

    protected proc sumRatios {arname} {
        upvar $arname ar

        set s 0
        foreach {key value} [array get ar] {
            incr s $value
        }
        return $s
    }

    public proc grid {path args} {
        # See if the parent has a manager object already.
        # Create a new grid manager object if there isn't one already.
        set myParent [$path parent]
set tim0 [time {
#puts stderr "GRID!$path!$args!$myParent![$myParent manager]!"
        if {[$myParent manager] eq ""} {
	    set m [uplevel #0 ::ntk::classes::gridManager ${myParent}.__manager $myParent]
	    $m remanage layout
	    $m free gridFree
            $myParent manager $m 
	    $myParent appendRedrawHandler [list $myParent layout $myParent]
        }
        # initialize the grid data for the window.
	set m2 [::ntk::classes::gridData ${path}.__data $path]
        if {[llength $args] > 0} {
	    $path configure {*}$args
	}
	$m2 wpath $path
#::ntk::widget::Widget gridregister $path [$path getScope itcl_options] [$m2 getScope itcl_options]
        $path removeFromManager gridRemove

        # Get the manager and set the peaks.
        set m [$myParent manager]
        lassign [$path cget -slot] c r
        setPeak $m peakrow [expr {$r + [$path cget -rowspan]}]
        setPeak $m peakcolumn [expr {$c + [$path cget -columnspan]}]
        # Get the grid prior to insertion from the parent.
        set myGrid [$m grid]
#puts stderr "myGrid1!$myGrid!"
        insertWidget myGrid $path $c $r
#puts stderr "myGrid2!$myGrid!"
        # Set the new grid list.
        $m grid $myGrid
#puts stderr "LAYOUT![$path parent]!"
        layout [$path parent]
#dump $myGrid
#dumpSizes $myGrid
}]
#puts stderr "tim0!$tim0!"
        return $path
    }
}
