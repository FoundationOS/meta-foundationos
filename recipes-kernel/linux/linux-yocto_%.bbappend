FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append = "\
    file://enable_efi.cfg \
    file://usb_gadget.cfg \
"
