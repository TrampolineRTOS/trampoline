# Mixed Criticality branch

This branch is used to develop a testing framework for so-called mixed criticiality scheduling policies. 

The first scheduling policy is linked to AMC (Adaptive Mixed Criticality).
Modification to vanilla Trampoline are linked to the concept of execution
level:

* each task has a maximal execution level
* each task may have two execution budgets: one corresponding to its execution
  in the normal mode, denoted as CNORM and one corresponding to its execution
  in the graceful degradation mode, denoted as CSELF
* there is a system execution level (SEL), managed dynamically according to the
  following rules:
  * when a job is released, if it has been spawned by a task that has an
    execution level lower than the SEL, the job is dropped
  * at startup, the SEL is 0, corresponding to the normal mode
  * the timing protection service enforces that no job can overrun its CSELF budget
    (otherwise it is dropped)
  * when a job overruns its CNORM budget, the SEL becomes
    equal to the execution level of the task that spawned the job until the next idle time
  * when the SEL is equal to X, jobs spawned by tasks of execution level X use CSELF as their execution budget; jobs spawned by tasks of execution level higher than X use CNORM as their execution budget.
  * when an idle time is reached, the SEL is set back to 0
