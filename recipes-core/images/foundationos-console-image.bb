DESCRIPTION = "Console image for FoundationOS"
require foundationos-common.inc

FOUNDATIONOS_FEATURES += "\
    foundationos-coreos \
    foundationos-tools"

IMAGE_FEATURES_append = "${FOUNDATIONOS_FEATURES}"
