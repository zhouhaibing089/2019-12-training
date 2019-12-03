#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

static int __init my_init(void)
{
    struct task_struct *p;
    struct task_struct *t;
    for_each_process_thread(p, t)
    {
        pr_info("threadgroupid %d; pid %d, state %ld, command: %s", t->tgid, t->pid, t->state, t->comm);
    }
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
