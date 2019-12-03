#include <linux/module.h>
#include <linux/init.h>
#include <linux/utsname.h>

static int __init my_init(void)
{
    struct new_utsname *name = init_utsname();
    pr_info("sysname %s, nodename %s, release %s, version %s, machine %s, domainname %s,", name->sysname, name->nodename, name->release, name->version, name->machine, name->domainname);
    return 0;
}

static void __exit my_exit(void)
{
    pr_info("exit");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("haibzhou");
MODULE_LICENSE("GPL v2");
