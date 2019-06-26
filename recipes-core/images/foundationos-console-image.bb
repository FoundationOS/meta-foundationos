DESCRIPTION = "Console image for FoundationOS"
require foundationos-common.inc

FOUNDATIONOS_FEATURES += "\
    foundationos-coreos \
    foundationos-tools \
    foundationos-firsttime-boot \
"

IMAGE_FEATURES_append = "${FOUNDATIONOS_FEATURES}"
