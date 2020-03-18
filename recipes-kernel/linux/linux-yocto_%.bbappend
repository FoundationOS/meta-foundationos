FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append = "\
    file://enable_efi.cfg \
    file://usb_gadget.cfg \
    file://enable_lzo.cfg \
"

KERNEL_FEATURES_append = "  cfg/efi-ext.scc \
                            cfg/fs/ext2.scc \
                            cfg/fs/ext4.scc \
                            features/cgroups/cgroups.scc \
"