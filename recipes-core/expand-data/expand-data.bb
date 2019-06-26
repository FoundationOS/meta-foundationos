LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "\
        file://expand_data.service \
"

FILES_${PN} += "\
        ${systemd_unitdir}/system/*.service \
"

do_install_append() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/*.service ${D}${systemd_unitdir}/system

    sed -i -e 's,@FOUNDATIONOS_DATA_PART_NUMBER@,${FOUNDATIONOS_DATA_PART_NUMBER},g' ${D}${systemd_unitdir}/system/*.service
    sed -i -e 's,@FOUNDATIONOS_STORAGE_DEVICE_PATH@,${FOUNDATIONOS_STORAGE_DEVICE_PATH},g' ${D}${systemd_unitdir}/system/*.service
}

inherit foundationos-firsttime-boot-service
FIRSTTIME_BOOT_SYSTEMD_SERVICE_${PN} = "expand_data.service"
