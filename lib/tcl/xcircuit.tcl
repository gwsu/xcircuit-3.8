# Wishrc startup for ToolScript (xcircuit)
#
# Loads the shared object (xcircuit.so) file into Tcl, runs the
# wrapper script to generate the GUI, then runs the initialization
# routine for the XCircuit package.

global XCOps

set envlibdir [array get env "XCIRCUIT_LIB_DIR"]
if {$envlibdir == {}} {
   set XCIRCUIT_LIB_DIR /usr/local/lib/xcircuit-3.8
}
unset envlibdir

set envsrcdir [array get env "XCIRCUIT_SRC_DIR"]
if {$envsrcdir != {}} {
   set path [lindex $envsrcdir 1]
} else {
   set path /usr/local/lib/xcircuit-3.8
   set XCIRCUIT_SRC_DIR $path
}
unset envsrcdir

if {[string compare $tcl_platform(platform) "windows"] == 0} {
   set libext .dll
} else {
   set libext .so
}

set tcllibdir $path
if {![file exists ${tcllibdir}/xcircuit$libext]} {
   set tcllibdir ${path}/tcl
}
if {![file exists ${tcllibdir}/xcircuit$libext]} {
   puts stderr "Error:  Cannot find file xcircuit$libext"
}
load ${tcllibdir}/xcircuit$libext

package require Xcircuit

# It is important to make sure no magic commands overlap with Tcl built-in
# commands, because otherwise the namespace import will fail.

proc pushnamespace { name } {

   set y [namespace eval ${name} info commands ::${name}::*]
   set z [info commands]

   foreach v $y {
      regsub -all {\*} $v {\\*} i
      set x [namespace tail $i]
      if {[lsearch $z $x] < 0} { 
	 namespace import $i                       
      } else {
	 puts "Warning: ${name} command '$x' use fully-qualified name '$v'"
      }
   }
}

proc popnamespace { name } {
   set z [info commands]
   set l [expr [string length ${name}] + 5]

   while {[set v [lsearch $z ${name}_tcl_*]] >= 0} {
      set y [lindex $z $v]
      set w [string range $y $l end]
      interp alias {} ::$w {}
      rename ::$y ::$w
      puts "Info: replacing ::$w with ::$y"
   }
   namespace forget ::${name}::*
}

set auto_noexec 1	;# don't EVER call UNIX commands w/o "shell" in front

# Have we called xcircuit from tkcon?

if {[lsearch [interp aliases] tkcon] != -1} {
   set XcConsole tkcon
   wm withdraw .

   # Rename conflicting TkCon commands before pushing xcircuit's namespace

   if {[lsearch [info commands] orig_edit] < 0} { rename edit orig_edit }
} else {

   # Extend the "unknown" command-line handler to be compatible with the
   # way we have renamed certain core Tcl/Tk functions.

   rename unknown tcl_unknown
   proc unknown { args } {
      # CAD tools special:
      # Check for commands which were renamed to tcl_(command)

      set cmd [lindex $args 0]
      if {[lsearch [info commands] tcl_$cmd] >= 0} {
         set arglist [concat tcl_$cmd [lrange $args 1 end]]
         set ret [catch {eval $arglist} result]
         if {$ret == 0} {
            return $result
         } else {
            return -code $ret -errorcode $errorCode $result
         }
      }
      return [eval [concat tcl_unknown $args]]
   }
}

# Rename conflicting Tcl/Tk commands before pushing xcircuit's namespace

if {[lsearch [info commands] tcl_label] < 0} { rename label tcl_label }

# Allow commands in the xcircuit namespace to be called from the toplevel namespace

pushnamespace xcircuit

#----------------------------------------------------------------------
# Cross-Application section
#----------------------------------------------------------------------

# Check namespaces for existence of other applications
set UsingMagic 0
set UsingIRSIM 0
set UsingNetgen 0
set nlist [namespace children]
foreach i $nlist {
   switch $i {
      ::magic { set UsingMagic 1 }
      ::irsim { set UsingIRSIM 1 }
      ::netgen { set UsingNetgen 1 }
   }
}

# Setup IRSIM assuming that the Tcl version is installed.
# We do not need to rename procedure irsim to NULL because it is
# redefined in a script, which simply overwrites the original.

proc irsim { args } {
   global CAD_ROOT
   set irsimscript [glob -nocomplain ${CAD_ROOT}/irsim/tcl/irsim.tcl]
   if { ${irsimscript} == {} } {
      puts stderr "\"irsim\" requires Tcl-based IRSIM version 9.6 or newer."
      puts stderr "Could not find script \"irsim.tcl\".  If IRSIM is installed in a"
      puts stderr "place other than CAD_ROOT (=${CAD_ROOT}), use the command"
      puts stderr "\"source <path>/irsim.tcl\" before doing \"irsim\"."
   } else {
      source $irsimscript
      eval {irsim} $args
   }
}

# Setup Magic assuming that the Tcl version is installed.

proc magic { args } {
   global CAD_ROOT
   set magicscript [glob -nocomplain ${CAD_ROOT}/magic/tcl/magic.tcl]
   if { ${magicscript} == {} } {
      puts stderr "\"magic\" requires Tcl-based Magic version 7.2 or newer."
      puts stderr "Could not find script \"magic.tcl\".  If Magic is installed in a"
      puts stderr "place other than CAD_ROOT (=${CAD_ROOT}), use the command"
      puts stderr "\"source <path>/magic.tcl\"."
   } else {
      set argv $args
      set argc [llength $args]
      uplevel #0 source $magicscript
   }
}

# Setup Netgen assuming that the Tcl version is installed.

proc netgen { args } {  
   global CAD_ROOT
   set netgenscript [glob -nocomplain ${CAD_ROOT}/netgen/tcl/netgen.tcl]
   if { ${netgenscript} == {} } {
      puts stderr "\"netgen\" requires Tcl-based Netgen version 1.2 or newer."
      puts stderr "Could not find script \"netgen.tcl\".  If Netgen is installed in a"
      puts stderr "place other than CAD_ROOT (=${CAD_ROOT}), use the command"
      puts stderr "\"source <path>/netgen.tcl\"."
   } else {
      set argv $args
      set argc [llength $args]
      source $netgenscript
   }
}

# Source the default resources file

source ${tcllibdir}/resource.tcl

# Sourcing of individual resource overrides

set envhomedir [array get env "HOME"]
if {$envhomedir != {}} {
   set homepath [lindex $envhomedir 1]
   set homedefaults ${homepath}/.Xdefaults
   if {[file exists $homedefaults]} {
      if {[catch {option readfile $homedefaults userDefault}]} {
	 puts stderr "Warning:  Error parsing file $homedefaults"
      }
   }
   unset homedefaults
   unset homepath
}
unset envhomedir

# Run the xcircuit start function

if {[string length $argv] == 0} {
   # Source the GUI-generating script
   source ${tcllibdir}/wrapper.tcl
   xcircuit::start .xcircuit
} else {
   set do_wrapper true
   set argafter {xcircuit::start}
   for {set i 0} {$i < $argc} {incr i 1} {
      set x [lindex $argv $i]
      switch -regexp -- $x {
	 ^-now {
	   set do_wrapper false
	 }
	 ^-r {
	   set XCOps(library) "all"
	 }
	 ^-noc {
	   # this option already handled---absorb it and do nothing.
	 }
	 default {
	   lappend argafter $x
	 }
      }
   }
   
   # Set up for interactive or filter (batch) mode processing
   if {$do_wrapper} {
      # Source the GUI-generating script
      source ${tcllibdir}/wrapper.tcl
      set argafter [linsert $argafter 1 .xcircuit]
   } else {
      simple .xcdummy -exitproc "quitnocheck"
      set XCOps(window) .xcdummy
   }
   unset x i do_wrapper
   eval $argafter		;# xcircuit::start .xcircuit ${argv}
}
unset tcllibdir

# The GUI wrapper iconfies the window while generating it
catch {wm deiconify $XCOps(toplevel)}

# Invoke the "wire" button by default
catch {$XCOps(focus).mainframe.toolbar.bw invoke}

# Xcircuit start function drops back to interpreter after initialization & setup

if {[string range [wm title .] 0 3] == "wish"} {
   wm withdraw .
}

if {[string range [wm title .] 0 8] == "xcircexec"} {
   wm withdraw .
}
