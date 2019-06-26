SUMMARY = "FoundationOS"
HOMEPAGE = ""
LICENSE = "MIT"

IMAGE_LINGUAS = "en-us"

inherit core-image

COMMON_FEATURES = " \
    splash \
    ssh-server-dropbear \
"

IMAGE_FEATURES += "${COMMON_FEATURES}"

FEATURE_PACKAGES_foundationos-coreos ?= "packagegroup-foundationos-coreos"

FEATURE_PACKAGES_foundationos ?= "packagegroup-foundationos"
FEATURE_PACKAGES_foundationos[optional]  ?=  "1"
FEATURE_PACKAGES_foundationos-tools ?= "packagegroup-foundationos-tools"
FEATURE_PACKAGES_foundationos-tools[optional]  ?=  "1"
FEATURE_PACKAGES_foundationos-firsttime-boot ?= "packagegroup-foundationos-firsttime-boot"
FEATURE_PACKAGES_foundationos-firsttime-boot[optional]  ?=  "1"

set_local_timezone() {
    ln -sf /usr/share/zoneinfo/EST5EDT ${IMAGE_ROOTFS}/etc/localtime
}

disable_bootlogd() {
    echo BOOTLOGD_ENABLE=no > ${IMAGE_ROOTFS}/etc/default/bootlogd
}

ROOTFS_POSTPROCESS_COMMAND += " \
    set_local_timezone ; \
    disable_bootlogd ; \
"
