ROOTFS_POSTPROCESS_COMMAND += '${@bb.utils.contains("IMAGE_FEATURES", "foundationos-firsttime-boot", "set_systemd_firsttime_boot_target; ", "", d)}'

# Modify systemd default target
set_systemd_firsttime_boot_target () {
    if [ -d ${IMAGE_ROOTFS}${sysconfdir}/systemd/system -a -e ${IMAGE_ROOTFS}${systemd_unitdir}/system/firsttime-boot.target ]; then
        install -d ${IMAGE_ROOTFS}${sysconfdir}/systemd/system/local-fs-pre.target.wants
        ln -sf ${system_unitdir}/system/firsttime-boot.target ${IMAGE_ROOTFS}${sysconfdir}/systemd/system/local-fs-pre.target.wants
    fi
}
