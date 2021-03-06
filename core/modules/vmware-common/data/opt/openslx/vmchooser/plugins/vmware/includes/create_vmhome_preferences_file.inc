#!/bin/bash
###########################################
# Include: Create VMware preferences file #
###########################################
## Functions ##
create_vmhome_preferences_file() {
	local nobar=1
	[ "$DISPLAY_COUNT" -gt 1 ] && nobar=0
	cat > "${VM_HOME}/preferences" <<-HEREEND
		.encoding = "UTF-8"
		# This configuration file was generated on $(date)
		# by $0 for VMWare version $vmware_version

		# updates
		webUpdate.enabled = "FALSE"
		webUpdate.lastCheck.status = "done_updates"
		webUpdate.checkPeriod = "never"
		pref.downloadPermission = "DENY"
		pref.vmplayer.downloadPermission = "DENY"
		pref.vmplayer.webUpdateOnStartup = "FALSE"
		pref.lastUpdateCheckSec = "$(date +%s)"
		# hints
		pref.tip.startup = "FALSE"
		hints.hideAll = "TRUE"
		hint.vmui.showAllUSBDevs = "FALSE"
		hint.usb.disconnectHostdriver = "FALSE"
		hint.vmui.reset = "FALSE"
		hint.vmui.poweroff = "FALSE"
		hint.upgrade.legacyVM = "FALSE"
		hint.tools.toolsReminder = "FALSE"
		hint.nfsmounted.persistent = "FALSE"
		hint.loader.debug.beta = "FALSE"
		hint.leaveFullScreen = "FALSE"
		hint.guestos.xp = "FALSE"
		hint.buslogic.needDriver = "FALSE"
		
		# configs
		prefvmx.defaultVMPath = "${VM_HOME}"
		prefvmx.mru.config = "$VM_RUN_FILE:"
		
		# hot keys
		pref.hotkey.control = "true"
		pref.hotkey.alt = "true"
		pref.hotkey.shift = "true"
		pref.hotkey.gui = "true"
		
		# fullscreen/mouse/keyboard
		pref.fullscreen.toolbarPixels = "0"
		pref.vmplayer.fullscreen.autohide = "TRUE"
		pref.vmplayer.fullscreen.nobar = $nobar
		pref.grabOnMouseClick = "TRUE"
		pref.grabOnKeyPress = "TRUE"
		pref.motionGrab = "TRUE"
		pref.motionUngrab = "TRUE"
		pref.hideCursorOnUngrab = "TRUE"
		pref.autoFit = "TRUE"
		pref.autoFitFullScreen = "fitGuestToHost"
		pref.autoFitGuestToWindow = "TRUE"
		pref.vmplayer.exit.vmAction = "poweroff"
		pref.vmplayer.confirmOnExit = "TRUE"
		pref.backgroundOnClose = "FALSE"
		pref.trayicon.enabled = "FALSE"
		pref.keyboardAndMouse.vmHotKey.enabled = "FALSE"
		pref.keyboardAndMouse.vmHotKey.count = "0"
		
		# shared folders
		pref.enableAllSharedFolders = "TRUE"
		
		# eula
		pref.vmplayer.firstRunDismissedVersion = "$vmware_version"
		pref.eula.count = "2"
		pref.eula0.product = "VMware Player"
		pref.eula0.build = "$vmware_build"
		pref.eula1.product = "VMware Workstation"
		pref.eula1.build = "$vmware_build"
	HEREEND
	if [ -n "$SLX_EXAM" ]; then
		echo 'pref.hotkey.rightControl = "true"' >> "${VM_HOME}/preferences"
	fi
	writelog "Vmware preferences file created in $VM_HOME."
}

call_post_source create_vmhome_preferences_file
