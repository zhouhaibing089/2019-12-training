#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void)
{
    pr_info("module lab_module1 is loaded");
    return 0;
}

static void __exit my_exit(void)
{
    pr_info("exit");
}

static int haibzhou_cool_func(void)
{
    return 5;
}

module_init(my_init);
module_exit(my_exit);

EXPORT_SYMBOL(haibzhou_cool_func);

MODULE_AUTHOR("haibzhou");
MODULE_LICENSE("GPL v2");
