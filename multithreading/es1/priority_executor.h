# ifndef PRIORITYEXECUTOR
# define PRIORITYEXECUTOR

# include <thread>
# include <atomic>
# include <functional>
# include "active_object.h"
# include "synchronized_queue.h"

using namespace std;

// REACTOR architecture
class PriorityExecutor: public ActiveObject {
    public:
        // same as pushTask() of Reactor but with priority boolean
        void execute(function<void ()> task, bool highPriority);
        ~PriorityExecutor();
    private:
        virtual void run ();
        SynchronizedQueue<function<void ()>> highPriorityTasks;
        SynchronizedQueue<function<void ()>> lowPriorityTasks;
};
# endif