#include <linux/module.h>
#include <linux/init.h>

int haibzhou_cool_func(void);

static int __init my_init(void)
{
    pr_info("module lab_module2 is loaded, calling haibzhou_cool_func(): %d", haibzhou_cool_func());
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
