EXTRA_IMAGEDEPENDS_append = "${@bb.utils.contains('DISTRO_FEATURES', 'foundationos-uboot', ' u-boot', '', d)}"

FOUNDATIONOS_UBOOT_ENV_STORAGE_DEVICE_OFFSET ??= "${@eval('${FOUNDATIONOS_PARTITION_ALIGNMENT_KB} * 1024')}"

# u-boot environment file
IMAGE_UENV_TXT_FILE ?= ""

IMAGE_BOOT_FILES_append_foundationos-uboot = " ${IMAGE_UENV_TXT_FILE}"

# make sure to provide a weak default
UBOOT_SUFFIX ??= "bin"
