#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/list.h>

struct my_list
{
    int value;
    struct list_head list;
};

static int __init my_init(void)
{
    LIST_HEAD(head);

    struct my_list m1 = {
        .value = 0,
        .list = LIST_HEAD_INIT(m1.list),
    };

    struct my_list m2 = {
        .value = 5,
        .list = LIST_HEAD_INIT(m2.list),
    };

    struct my_list m3 = {
        .value = 3,
        .list = LIST_HEAD_INIT(m3.list),
    };

    list_add(&m1.list, &head);
    list_add(&m2.list, &m1.list);
    list_add(&m3.list, &m2.list);

    // now the list should look like 0 -> 5 -> 3
    struct list_head *l;
    struct my_list *m;
    list_for_each(l, &head)
    {
        m = list_entry(l, struct my_list, list);
        pr_info("lab_list: entry %d", m->value);
    }

    pr_info("lab_list: remove the second entry");
    list_del(&m2.list);
    list_for_each(l, &head)
    {
        m = list_entry(l, struct my_list, list);
        pr_info("lab_list: entry %d", m->value);
    }

    pr_info("module lab_list is loaded");
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
