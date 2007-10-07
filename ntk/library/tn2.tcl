package require Itcl 4.0
package require megaimage
package require ntk
lappend auto_path .
package require ntkWidget

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

set width 800
set height 600
set configure_pending 0

proc configure {winid x y width height} {
    global configure configure_pending

    if {$width == [. cget -width] && $height == [. cget -height]} {
        return
    }
    set configure [list $width $height]
    if {$configure_pending} {
        return
    }
    set configure_pending 1
    after idle [list configureNow $winid]
}

proc configureNow {winid} {
    global configure configure_pending

    lassign $configure width height
    set obj [. obj]
    $obj setsize $width $height
    . configure -width $width -height $height
    set rat [expr {$width / 7.0}]
    ntk_request-size .left [expr {int($rat)}] $height
    ntk_request-size .right [expr {round($rat * 6)}] $height
    set configure_pending 0
}

proc ntk_input-key-release {args} {
    puts stderr "ntk_input-key-release called!$args!"
}

proc ntk_input-key-press {args} {
    puts stderr "ntk_input-key-press called!$args!"
}

proc ntk_input-mouse-release {args} {
    puts stderr "ntk_input-mouse-release called!$args!"
}

proc ntk_input-mouse-press {args} {
    puts stderr "ntk_input-mouse-press called!$args!"
}

proc ntk_input-motion {args} {
    puts stderr "ntk_input-motion called!$args!"
}

set id [ntk-create-sys-window $width $height]
ntk-set-title $id "NTk Itcl Demo"

puts stderr "TOP"
set top [ntk toplevel .  -width $width -height $height]
. id $id

ntk-create-event-handler $id [list ntk_input-key-press .] \
       [list ntk_input-key-release .] [list ntk_input-motion .] \
       [list ntk_input-mouse-press .] [list ntk_input-mouse-release .] \
       [list configure .]
ntk-move-sys-window $id 200 200
ntk-map-sys-window $id


set topObj [$top obj]

set w2Path [ntk frame .w2 -width 100 -height 100]
puts stderr "w2Path!$w2Path!"
after 2000 "[list $w2Path configure -bg [list 155 0 0 255]]"

set w3Path [ntk frame .w3 -width 200 -height 200]
puts stderr "w3Path!$w3Path!"
.w3 configure -bg [list 255 150 150 255] -x 180 -y 150

after 6000 "[list $w2Path configure -bg [list 255 0 0 255]]"
puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"