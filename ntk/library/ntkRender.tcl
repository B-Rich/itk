::itcl::eclass ::ntk::classes::render {

    private common backgroundColor [list 16 33 65 255]
    private variable rendering 0

    public method render {args} {
        if {[llength $args] == 0} {
	    return -code error "expected a window to render"
	}
	foreach w $args {
	    $w update 1
	}
	if {$rendering} {
	    return
	}
	set rendering 1
	after idle [::itcl::code $this renderNow]
    }
    protected method renderNow {} {
	set myObj [. obj]
        $myObj setall [. cget -bg]
        renderTree $myObj .
#puts stderr "NOW!.f objsetimage $myObj!"
#	resizeImage [. id] [. cget -width] [. cget -height]
#	putImage [. id] $myObj
	set rendering 0
	.f objsetimage $myObj
    }

    protected method changeInTree {win} {
#puts stderr "changeInTree!$win![$win update]![$win children]!"
        if {[$win update]} {
            return 1
        }
        foreach child [$win children] {
            if {[changeInTree $child]} {
                return 1
            }
        } 
        return 0
    }

    protected method renderRecurse {baseobj win x y} {
#puts stderr "renderRecurse!$baseobj!$win!$x!$y![$win children]!"
        foreach child [$win children] {
            set cx [expr {$x + [$child cget -x]}]
            set cy [expr {$y + [$child cget -y]}]
            set r [$child cget -rotate]
            if {$r} {
		set childObj [$child obj]
		set myRenderTreeData
                if {$myRenderTreeData] eq ""} {
                    $child renderTreeData [megaimage-blank 1 1]
                }
                $myRenderTreeData setdata [$childObj getdata]
                renderRecurse $myRenderTreeData] $child 0 0
                $myRenderTreeData rotate $r
#puts stderr "BASE2a!$baseobj!$cx!$cy!$myRenderTreeData!"
                $baseobj blendobj $cx $cy $myRenderTreeData
            } else {
#puts stderr "BASE2b!$baseobj!$cx!$cy!$childObj!"
                $baseobj blendobj $cx $cy $childObj
                renderRecurse $baseobj $child $cx $cy
            }
            $child update 0
        } 
    }

    public method renderTree {baseobj win} {
#puts stderr "renderTree!WIN!$win![$win children]!"
        foreach child [$win children] {
#puts stderr CHILD:$child
            if {[$child renderTreeData] eq ""} {
                $child renderTreeData [megaimage-blank 1 1]
            } 
            set back [$child renderTreeData]
            if {[changeInTree $child]} {
#puts stderr changeInChild:CHILD:$child
                $back setdata [[$child obj] getdata]
                renderRecurse $back $child 0 0
                if {[set r [$child cget -rotate]]} {
                    $back rotate $r
                }
                $child update 0
           }
#puts stderr "BASE3!$baseobj!$back!"
           $baseobj blendobj [$child cget -x] [$child cget -y] $back
        }
    }
}

