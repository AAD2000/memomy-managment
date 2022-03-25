#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <drm/drm.h>
#include <drm/drm_gem.h>
#include <drm/drm_drv.h>
#include <linux/syscalls.h>

struct drm_device * dev;
struct drm_gem_object * gemdev;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Lakshmanan");
MODULE_DESCRIPTION("A Simple Hello World module");

static int __init hello_init(void) 
{
    int fd = sys_open("/dev/dri/card0", O_RDWR);
        
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);