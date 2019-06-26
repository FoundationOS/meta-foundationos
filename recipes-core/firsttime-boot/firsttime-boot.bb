LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "\
        file://firsttime-boot.target\
"
do_install_append() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/*.target ${D}${systemd_unitdir}/system
}

FILES_${PN} += "\
    ${systemd_unitdir} \
    ${sysconfdir} \
"
