python do_systemd_firsttime_boot_service_install() {
    import shutil

    pn = d.getVar('PN')
    service_name = d.getVar('FIRSTTIME_BOOT_SYSTEMD_SERVICE_' + pn)
    if not service_name:
        return

    outdir = oe.path.join(d.getVar("sysconfdir"), "systemd", "system", "firsttime-boot.target.wants")
    outdir = oe.path.join(d.getVar('D'), outdir)
    shutil.rmtree(outdir, ignore_errors=True)
    print("Outdir:"+outdir)

    service_file = oe.path.join(d.getVar("systemd_system_unitdir"), service_name)
    print("Service file:"+service_file)

    bb.utils.mkdirhier(outdir)
    os.symlink(service_file, os.path.join(outdir, service_name))
}

FILES_${PN} += "\
    ${sysconfdir} \
"

RDEPENDS_${PN} += "firsttime-boot"

addtask systemd_firsttime_boot_service_install after do_install before do_package
