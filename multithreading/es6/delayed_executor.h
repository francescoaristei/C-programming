/*

//Add header files here
class DelayedExecutor {
    public:
        DelayedExecutor();
        void push(function<void ()> task);
        ~DelayedExecutor();
    private:
        //Insert your code here
};

which should spawn a background thread to execute the tasks that are passed. When a single
task is passed, it shall be executed with approximately a 10 seconds delay since the call to
push(). If one or more other tasks are passed during this 10 seconds period, or during the time
it takes to execute the task function, the subsequent tasks shall be queued and executed with
a 10 seconds gap since the previous task.
To perform a delay of x seconds, you can use this_thread::sleep_for(std::chrono::seconds(x));

*/

// REACTOR design pattern

# ifndef DELAYEDEXECUTOR
# define DELAYEDEXECUTOR

# include <mutex>
# include <condition_variable>
# include <list>
# include <atomic>
# include <functional>
# include <thread>

using namespace std;

class DelayedExecutor {
    public:
        DelayedExecutor();
        void push(function<void ()> task);
        ~DelayedExecutor();
    

    private:
        void run ();
        mutex m;
        condition_variable cv;
        list<function<void ()>> queue;
        atomic<bool> done;
        // worker
        thread t;
};

# endif